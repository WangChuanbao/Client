#include "formpoly.h"
#include "ui_formpoly.h"
#include <QTextStream>
#include "formgraph.h"

FormPoly::FormPoly(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPoly)
{
    ui->setupUi(this);

    _period = 900;

    //视图－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
    _selectData = new FormSelectData();
    _selectData->styleForGraph();
    ui->verticalLayout->addWidget(_selectData);

    _glayout = new QGridLayout();
    ui->verticalLayout->addLayout(_glayout);

    connect(_selectData, SIGNAL(selected(QString, QString)),
            this, SLOT(timeSelected(QString,QString)), Qt::QueuedConnection);
    connect(_selectData, SIGNAL(selectedDateTime(long,long)),
            this, SLOT(selectDateTime(long,long)), Qt::QueuedConnection);


    //网络－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
    _netWorker = new NetWorker();
    connect(_netWorker, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(netWorkerResponse(QNetworkReply*)), Qt::QueuedConnection);

    QString parameter = "action=screens_group";
    QNetworkReply *reply = _netWorker->requestUrl("",parameter);
    _replyMap.insert(reply, 100);

    _timer = new QTimer(this);
    connect(_timer,SIGNAL(timeout()),this,SLOT(timeUpDate()));
    _timer->start(10000);
}

void FormPoly::timeUpDate()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    if (!_graphidList.isEmpty() && _graphidList.length()>0)
    {
        QString period = QString::number(_period);
        for (int i=0; i<_graphidList.length(); i++)
        {
            QString paramerter = QString("action=chart&graphid=%1&period=%2").arg(_graphidList.value(i),period);
            QNetworkReply *reply = _netWorker->requestUrl("",paramerter);
            _replyMap.insert(reply,i);
        }
    }
}

void FormPoly::netWorkerResponse(QNetworkReply *reply)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    if (reply->error() != QNetworkReply::NoError)
    {
        cout << "netWork error:" << reply->errorString() << endl;
        return;
    }

    int request = _replyMap.value(reply);
    QVariantMap data = FormGraph::analyzeJson(reply);

    if (request == 100)
    {
        ui->comboBox->clear();
        foreach (QVariant varint, data.value("data").toList()) {
           QVariantMap map = varint.toMap();
           QString name = map.value("name").toString();
           ui->comboBox->addItem(name,map);
        }
    }
    else if (request == 101)
    {
        _graphidList.clear();
        _replyMap.clear();
        foreach (QCustomPlot *graph, _graphMap.values()) {
           _glayout->removeWidget(graph);
           delete graph;
        }
        _graphMap.clear();
        int i = 0;
        foreach (QVariant variant, data.value("data").toList()) {
            QVariantMap map = variant.toMap();
            QString graphid = map.value("graphid").toString();
            _graphidList.append(graphid);
            QString time = QString::number(_period);
            QString paramerter = QString("action=chart&graphid=%1&period=%2").arg(graphid,time);
            QNetworkReply *reply = _netWorker->requestUrl("",paramerter);
            _replyMap.insert(reply,i);
            i++;
        }
    }
    else {
        if (_graphMap.isEmpty() || !_graphMap.contains(request))
        {
            QCustomPlot *graph = new QCustomPlot(this);
            graph->plotLayout()->insertRow(0);
            graph->plotLayout()->addElement(0, 0, new QCPTextElement(graph));

            if (_graphidList.length()>2)
            {
                int row = request/2;
                int column = request%2;
                _glayout->addWidget(graph,row,column);
            }
            else {
                _glayout->addWidget(graph,request,0);
            }
            _graphMap.insert(request, graph);
        }

        _graphMap.value(request)->clearGraphs();
        QVariantMap dataMap = data.value("data").toMap();
        int graphTyle = dataMap.value("graphtype").toInt();
        if (graphTyle == 0 || graphTyle == 1)   //线性图
        {
            //linegraph(_graphMap.value(request), dataMap);
            FormGraph::linegraph(_graphMap.value(request), dataMap);
        }
        else {  //饼状图
            //FormGraph::piechart(_graphMap.value(request), dataMap);
        }
    }
}

//时间
void FormPoly::timeSelected(QString name, QString title)
{
    Q_UNUSED(name);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    long time = title.left(title.length()-1).toLong();

    if (title.endsWith("m"))
    {
        time = time * 60;
    }
    if (title.endsWith("h"))
    {
        time = time * 60 * 60;
    }
    if (title.endsWith("d"))
    {
        time = time * 24 * 60 * 60;
    }
    if (title.endsWith("M"))
    {
        time = time * 30 * 24 * 60 * 60;
    }
    if (title.endsWith("y"))
    {
        time = time * 365 * 24 * 60 * 60;
    }

    _period = time;
    QString period = QString::number(time);
    for (int i=0; i<_graphidList.length(); i++)
    {
        QString paramerter = QString("action=chart&graphid=%1&period=%2").arg(_graphidList.value(i),period);
        QNetworkReply *reply = _netWorker->requestUrl("",paramerter);
        _replyMap.insert(reply,i);
    }
}

void FormPoly::selectDateTime(long startTime, long endTime)
{
    QString stime = QString::number(startTime);
    QString etime = QString::number(endTime);
    for(int i=0; i<_graphidList.length(); i++)
    {
        QString paramerter = QString("action=chart&graphid=%1&start_time=%2&end_time=%3").arg(_graphidList.value(i),stime,etime);
        QNetworkReply *reply = _netWorker->requestUrl("",paramerter);
        _replyMap.insert(reply,i);
    }
}

void FormPoly::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
}

FormPoly::~FormPoly()
{
    delete _glayout;
    delete ui;
}

void FormPoly::on_comboBox_currentIndexChanged(int index)
{
    QVariantMap map = ui->comboBox->itemData(index).toMap();
    QString screenid = map.value("screenid").toString();
    QString parameter = QString("action=screens&screens_id=%1").arg(screenid);
    QNetworkReply *reply = _netWorker->requestUrl("",parameter);
    _replyMap.insert(reply, 101);
}

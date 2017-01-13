#include "formgraph.h"
#include "ui_formgraph.h"
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QtAlgorithms>
#include <QDebug>
#include "utils.h"
#include "mybutton.h"

FormGraph::FormGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGraph)
{
    ui->setupUi(this);

    QFont font;
    font.setPixelSize(14);
    ui->graphTitle->setFont(font);
    ui->warningTitle->setFont(font);
    ui->allButton->setFont(font);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);

    font.setPixelSize(12);
    ui->hostGroupBox->setFont(font);
    ui->hostBox->setFont(font);
    ui->graphBox->setFont(font);

    _isNew = false;
    _lastWarningTime = 0;
    _netWorker = new NetWorker();
    _maxWidth = 0;
    _isHistory = 0;

    _selectData = new FormSelectData();
    ui->verticalLayout_3->insertWidget(1,_selectData);

    connect(_selectData, SIGNAL(selected(QString, QString)),
            this, SLOT(timeSelected(QString,QString)), Qt::QueuedConnection);

    connect(_selectData, SIGNAL(selectedDateTime(long,long)),
            this, SLOT(selectDateTime(long,long)), Qt::QueuedConnection);

    connect(_netWorker, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(netWorkerResponse(QNetworkReply*)), Qt::QueuedConnection);

    getHostGroups();

    //告警列表设置
    model = new QStandardItemModel();
    font.setPixelSize(14);
    QStandardItem *item0 = new QStandardItem(QString::fromLocal8Bit("告警类别"));
    item0->setFont(font);
    QStandardItem *item1 = new QStandardItem(QString::fromLocal8Bit("主机"));
    item1->setFont(font);
    QStandardItem *item2 = new QStandardItem(QString::fromLocal8Bit("告警信息"));
    item2->setFont(font);
    QStandardItem *item3 = new QStandardItem(QString::fromLocal8Bit("告警时间"));
    item3->setFont(font);
    QStandardItem *item4 = new QStandardItem(QString::fromLocal8Bit("持续时间"));
    item4->setFont(font);
    QStandardItem *item5 = new QStandardItem(QString::fromLocal8Bit("处理"));
    item5->setFont(font);
    QStandardItem *item6 = new QStandardItem(QString::fromLocal8Bit("查看"));
    item6->setFont(font);

    model->setHorizontalHeaderItem(0, item0);
    model->setHorizontalHeaderItem(1, item1);
    model->setHorizontalHeaderItem(2, item2);
    model->setHorizontalHeaderItem(3, item3);
    model->setHorizontalHeaderItem(4, item4);
    model->setHorizontalHeaderItem(5, item5);
    model->setHorizontalHeaderItem(6, item6);
    //利用setModel()方法将数据模型与QTableView绑定
    ui->warningTableView->setModel(model);

    ui->warningTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->warningTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->warningTableView->setSelectionMode(QAbstractItemView::NoSelection);

    ui->graph->plotLayout()->insertRow(0);
    ui->graph->plotLayout()->addElement(0, 0, new QCPTextElement(ui->graph));

}

void FormGraph::getHostGroups()
{
    QNetworkReply *reply = _netWorker->requestUrl("","action=groups");
    _replyMap.insert(reply, requestHostGroup);
}

void FormGraph::getHosts(QString &group_id)
{
    QString parameter = "action=hosts&group_id=";
    parameter.append(group_id);
    QNetworkReply *reply = _netWorker->requestUrl("",parameter);
    _replyMap.insert(reply, requestHost);
}

void FormGraph::getItems(QString &host_id)
{
    QString parameter = "action=graphs&&host_id=";
    parameter.append(host_id);
    QNetworkReply *reply = _netWorker->requestUrl("",parameter);
    _replyMap.insert(reply, requestItem);
}

void FormGraph::getWarning(QString &parameter)
{
    QNetworkReply *reply = _netWorker->requestUrl("",parameter);
    _replyMap.insert(reply, requestWarning);
}

void FormGraph::getGraph(QString &parameter, const int isHistory)
{
    QNetworkReply *reply = _netWorker->requestUrl("",parameter,isHistory);
    if (isHistory == 1)
    {
        _replyMap.insert(reply, requestChart_history);
    }
    else {
        _replyMap.insert(reply, requestChart);
    }
}

void FormGraph::mergeData(QVariantMap map1, QVariantMap map2)
{
    //qDebug() << map1 << "\n" << "---------------------" << map2 << endl;

    QList<QVariant> list1 = map1.value("chart_items").toList();
    QList<QVariant> list2 = map2.value("chart_items").toList();
    for (int i=0; i<list1.count(); i++)
    {
        QVariantMap itemMap1 = list1.value(i).toMap();
        QVariantMap itemMap2 = list2.value(i).toMap();

//        QJsonDocument doc1 = QJsonDocument::fromVariant(itemMap2);
//        QByteArray bac1 = doc1.toJson();
//        QString str21 = QString(bac1);
//        qDebug() << "\n\n" << "---------------------------" << "\n\n" << str21 << endl;


        QList<QVariant> chartList1 = itemMap1.value("chart").toList();
        QList<QVariant> chartList2 = itemMap2.value("chart").toList();

        QVariantMap chartMap2 = chartList2.last().toMap();
        double clock2 = chartMap2.value("clock").toDouble();
        for (int j=0; j<chartList1.count(); j++)
        {
            QVariantMap chartMap1 = chartList1.value(j).toMap();
            double clock1 = chartMap1.value("clock").toDouble();

            if (clock1 > clock2)
            {
                chartList2.append(chartList1.value(j));
            }
        }

        itemMap2.insert("chart",chartList2);

//        QJsonDocument doc = QJsonDocument::fromVariant(itemMap2);
//        QByteArray bac = doc.toJson();
//        QString str2 = QString(bac);
//        qDebug() << "\n\n" << "---------------------------" << "\n\n" << str2 << endl;
        list2.removeAt(i);
        list2.insert(i,itemMap2);
    }
    map2.insert("chart_items",list2);

    int graphTyle = map2.value("graphtype").toInt();
    if (graphTyle == 0 || graphTyle == 1)   //线性图
    {
        linegraph(ui->graph,map2);
    }
    else {  //饼状图
        //piechart(ui->graph, dataMap);
    }
}

QVariantMap FormGraph::analyzeJson(QNetworkReply *reply)
{
    //QTextStream cout(stdout, QIODevice::WriteOnly);
    QVariantMap data;
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll(), &error);
    if (error.error == QJsonParseError::NoError)
    {
        if (!(jsonDocument.isNull()||jsonDocument.isEmpty()) && jsonDocument.isObject())
        {
            data = jsonDocument.toVariant().toMap();
        }
    }
    return data;
}

void FormGraph::onPreUpdateData(const QDateTime& time)
{
    Q_UNUSED(time);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    _isNew = true;
    model->removeRows(0,model->rowCount());
}

void FormGraph::onEndUpdateData(const QDateTime& time)
{
    Q_UNUSED(time);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    _isNew = false;
}

void FormGraph::onAddWaring(const QString &strTime, const QString &strName, const QString &strDescription,
                             const QString &strSeverity, const QColor &color)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    Utils::log("formGraph addwarning");
    Utils::log(strName);
    /****************************检查是否忽略**********************************************/
    if (Utils::fileExist(IGNOREDATA_FILE))
    {
        //Utils::clearIgnoreData();
        QStringList list = Utils::readIgnoreData();
        for (int i=0; i<list.length(); i++)
        {
            QString string = list.value(i);
            QStringList list1 = string.split("|");
            QString name = list1.first();
            QString decription = list1.last();
            if (strName == name && decription == strDescription)
            {
                return;
            }
        }
    }
    /****************************检查是否忽略**********************************************/

    /****************************检查是否是最新告警**********************************************/
    QDateTime time = QDateTime::fromString(strTime, "yyyy-MM-dd hh:mm:ss");
    long longTime = time.toTime_t();
    if (longTime > _lastWarningTime)
    {
        _lastWarningTime = time.toTime_t();
        emit newWarning_all();
    }
    /****************************检查是否是最新告警**********************************************/

    if (QString::compare(_currentHostName,strName) == 0 || ui->hostBox->currentIndex()==0)
    {
        Utils::log(strName);
        int i = 0;
        QDateTime now = QDateTime::currentDateTime();

        long res = time.secsTo(now);
        long d,h,m,s;
        QString strd,strh,strm,strs;

        d = res/86400;
        h = (res-d*86400)/3600;
        m = (res-d*86400-h*3600)/60;
        s = res%60;
        if (d>0)
            strd = QString::number(d)+QString::fromLocal8Bit("天");
        if (h>0)
            strh = QString::number(h)+QString::fromLocal8Bit("小时");
        if (m>0)
            strm = QString::number(m)+QString::fromLocal8Bit("分");
        strs = QString::number(s)+QString::fromLocal8Bit("秒");

        QString deration = strd+strh+strm+strs;

        QList<QStandardItem *> list;
        QFont font;
        font.setPixelSize(12);
        //font.setPointSize(12);
        QStandardItem *item0 = new QStandardItem(strSeverity);
        item0->setFont(font);
        item0->setToolTip(strSeverity);
        QStandardItem *item1 = new QStandardItem(strName);
        item1->setFont(font);
        item1->setToolTip(strName);
        QStandardItem *item2 = new QStandardItem(strDescription);
        item2->setFont(font);
        item2->setToolTip(strDescription);
        QStandardItem *item3 = new QStandardItem(strTime);
        item3->setFont(font);
        item3->setToolTip(strTime);
        QStandardItem *item4 = new QStandardItem(deration);
        item4->setFont(font);
        item4->setToolTip(deration);
        QStandardItem *item5 = new QStandardItem();
        item5->setFont(font);
        QStandardItem *item6 = new QStandardItem();
        item6->setFont(font);
        MyButton *btn = new MyButton();       
        btn->setFont(font);
        btn->setText(QString::fromLocal8Bit("处理"));
        btn->setItem(item5);
        MyButton *btn1 = new MyButton();
        btn1->setFont(font);
        btn1->setText(QString::fromLocal8Bit("忽略"));
        btn1->setItem(item6);

        connect(btn, SIGNAL(clicked(int)), this, SLOT(solve_button_click(int)),Qt::QueuedConnection);
        connect(btn1, SIGNAL(clicked(int)), this, SLOT(ignore_button_click(int)),Qt::QueuedConnection);

        list.append(item0);
        list.append(item1);
        list.append(item2);
        list.append(item3);
        list.append(item4);
        list.append(item5);
        list.append(item6);
        model->insertRow(i,list);

        int strWidth = btn->fontMetrics().width(strDescription);
        int cellWidth = (this->width()-20)*13/36;
        int cellHeight = (strWidth/cellWidth + 1) * (btn->fontMetrics().lineSpacing()+20);
        ui->warningTableView->setRowHeight(i,cellHeight);

        QModelIndex index = model->indexFromItem(item5);
        ui->warningTableView->setIndexWidget(index,btn);
        index = model->indexFromItem(item6);
        ui->warningTableView->setIndexWidget(index,btn1);

        model->item(i,0)->setBackground(QBrush(color));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->item(i,1)->setTextAlignment(Qt::AlignCenter);
        model->item(i,2)->setTextAlignment(Qt::AlignCenter);
        model->item(i,3)->setTextAlignment(Qt::AlignCenter);
        model->item(i,4)->setTextAlignment(Qt::AlignCenter);
    }
    else {
        if (longTime > _lastWarningTime)
        {
            _lastWarningTime = time.toTime_t();
            emit newWarning();
        }
    }
}

void FormGraph::solve_button_click(const int row)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QString hostName = model->data(model->index(row,1)).toString();
    QString description = model->data(model->index(row,2)).toString();

    QStringList list = Utils::readData();
    Utils::clearData();
    for(int i=0; i<list.length(); i++)
    {
        QString string = list.value(i);
        if (string.contains(hostName,Qt::CaseSensitive) && string.contains(description,Qt::CaseSensitive))
        {
            continue;
        }
        Utils::recordData(string);
    }

    model->removeRow(row);
}

void FormGraph::ignore_button_click(const int row)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);

    QString hostName = model->data(model->index(row,1)).toString();
    QString description = model->data(model->index(row,2)).toString();
    cout << "row:" << row << "name:" <<hostName<<"desc:"<<description<<endl;
    Utils::ignoreData(hostName+"|"+description);

    model->removeRow(row);
}

void FormGraph::netWorkerResponse(QNetworkReply *reply)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);

    if (reply->error() != QNetworkReply::NoError)
    {
        cout << "netWork error:" << reply->errorString() << endl;
        return;
    }

    RemoteRequest request = _replyMap.value(reply);
    QVariantMap data = analyzeJson(reply);

    switch (request) {
    case requestHostGroup:
    {
        ui->hostGroupBox->clear();
        int maxWidth = 0;
        QVariantMap m;
        m.insert("groupid", QVariant("0"));
        ui->hostGroupBox->addItem(QString::fromLocal8Bit("所有"), m);
        foreach (QVariant varint, data.value("data").toList()) {
           QVariantMap map = varint.toMap();
           QString name = map.value("name").toString();
           int strWidth = ui->hostGroupBox->fontMetrics().width(name);
           if (maxWidth < strWidth)
           {
               maxWidth = strWidth;
           }
           ui->hostGroupBox->addItem(name,map);
        }
        ui->hostGroupBox->view()->setFixedWidth(maxWidth+60);
        break;
    }
    case requestHost:
    {
        ui->hostBox->clear();
        int maxWidth = 0;
        QVariantMap m;
        m.insert("hostid", QVariant("0"));
        m.insert("name",QString::fromLocal8Bit("所有"));
        ui->hostBox->addItem(QString::fromLocal8Bit("所有"), m);
        foreach (QVariant varint, data.value("data").toList()) {
           QVariantMap map = varint.toMap();
           QString name = map.value("name").toString();
           int strWidth = ui->hostBox->fontMetrics().width(name);

           if (maxWidth < strWidth)
               maxWidth = strWidth;
           ui->hostBox->addItem(name,map);
        }
        ui->hostBox->view()->setFixedWidth(maxWidth+60);
        break;
    }
    case requestItem:
    { 
        ui->graphBox->clear();
        int maxWidth = 0;
        QVariantMap m;
        m.insert("graphid", QVariant("0"));
        ui->graphBox->addItem(QString::fromLocal8Bit("非所选的"), m);
        foreach (QVariant varint, data.value("data").toList()) {
           QVariantMap map = varint.toMap();
           QString name = map.value("name").toString();
           int strWidth = ui->graphBox->fontMetrics().width(name);
           if (maxWidth < strWidth)
               maxWidth = strWidth;
           ui->graphBox->addItem(name,map);
        }
        ui->graphBox->view()->setFixedWidth(maxWidth+60);
        break;
    }
    case requestWarning:
    {
        /*
        int i = 0;
        foreach (QVariant varint, data.value("data").toList()) {
           QVariantMap map = varint.toMap();
          // model->setItem(i,0,new QStandardItem(map.value("severity_name").toString()));
           QString colorStr = map.value("severity_color").toString();
           QByteArray array;
           array.append(colorStr);
           bool ok;
           rgb color = colorSwichRGB(array.toInt(&ok,16));

           model->setItem(i,1,new QStandardItem(map.value("host_name").toString()));
           model->item(i,1)->setTextAlignment(Qt::AlignCenter);
           model->setItem(i,2,new QStandardItem(map.value("description").toString()));
           model->item(i,2)->setTextAlignment(Qt::AlignCenter);
           double time = map.value("datetime").toDouble();
           QDateTime date = QDateTime::fromTime_t(time);
           QString dateStr = date.toString("yyyy-MM-dd hh:mm:ss");
           model->setItem(i,3,new QStandardItem(dateStr));
           model->item(i,3)->setTextAlignment(Qt::AlignCenter);
           model->setItem(i,4,new QStandardItem(map.value("time_diff").toString()));
           model->item(i,4)->setTextAlignment(Qt::AlignCenter);

        }
        */

        break;
    }
    case requestChart:
    {
        ui->graph->clearGraphs();
        QVariantMap dataMap = data.value("data").toMap();

        if (_isHistory == 1)
        {
            qDebug() << "需要查询历史库" << endl;
            QVariantMap map = _graphData.value(requestChart_history);
            if (map.isEmpty())
            {
                qDebug() << "数据库查询完成，历史库未完成" << endl;
                _graphData.insert(requestChart, dataMap);
            }
            else {
                qDebug() << "数据库完成。历史库完成" << endl;
                mergeData(dataMap, map);
                _graphData.clear();
            }
        }
        else
        {
            qDebug() << "不需要查询历史库" << endl;
            int graphTyle = dataMap.value("graphtype").toInt();
            if (graphTyle == 0 || graphTyle == 1)   //线性图
            {
                linegraph(ui->graph,dataMap);
            }
            else {  //饼状图
                //piechart(ui->graph, dataMap);
            }
        }

        break;
    }
    case requestChart_history:
    {
        qDebug() << "历史库查询" << endl;
        QVariantMap dataMap = data.value("data").toMap();
        QVariantMap map = _graphData.value(requestChart);
        if (map.isEmpty())
        {
            qDebug() << "历史库完成，数据库未完成" << endl;
            _graphData.insert(requestChart_history, dataMap);
        }
        else {
            qDebug() << "历史库完成，数据库完成" << endl;
            mergeData(map, dataMap);
            _graphData.clear();
        }
    }
        break;
    default:
        break;
    }

    reply->deleteLater();
}

/********************************界面*********************************************/

void FormGraph::linegraph(QCustomPlot *customPlot, QVariantMap dataMap)
{
    //QCustomPlot *customPlot = ui->graph;
    QCPLayoutElement *ele = customPlot->plotLayout()->element(0, 0);

    if (ele->inherits("QCPTextElement"))
    {
        qobject_cast<QCPTextElement *>(ele)->setText(dataMap.value("name").toString());
        QFont font;
        //font.setPointSize(7);
        font.setPixelSize(14);
        qobject_cast<QCPTextElement *>(ele)->setFont(font);
    }

    QVector<double> xaxis(0);
    QVector<double> yaxis(0);
    foreach (QVariant variant, dataMap.value("chart_items").toList()) {
       QVariantMap itemMap = variant.toMap();
       QVector<QCPGraphData> timeData(0);
       QString unit = itemMap.value("units").toString();

       foreach (QVariant chartvar, itemMap.value("chart").toList()) {
            QVariantMap chartMap = chartvar.toMap();
            double clock = chartMap.value("clock").toDouble();
            QCPGraphData graphData;
            graphData.key = clock;
            graphData.value = chartMap.value("avg").toDouble();
            timeData.append(graphData);

            xaxis.append(clock);
            yaxis.append(graphData.value);
       }

       customPlot->addGraph();
       customPlot->graph()->setLineStyle(QCPGraph::lsLine);
       customPlot->graph()->setName(itemMap.value("item_name").toString());
       QString colorStr = itemMap.value("color").toString();
       QString color = "#"+colorStr;
       customPlot->graph()->setPen(QPen(QColor(color)));
       //customPlot->graph()->setBrush(QBrush(color));
       customPlot->graph()->data()->set(timeData);
       //customPlot->yAxis->setLabel("单位：");
       QString u = QString::fromLocal8Bit("单位：") + unit;
       customPlot->yAxis->setLabel(u);
       QFont font;
       //font.setPointSize(6);
       font.setPixelSize(12);
       font.setBold(true);
       customPlot->yAxis->setLabelFont(font);
    }

    if (!yaxis.isEmpty() && !xaxis.isEmpty())
    {
        qSort(yaxis);
        qSort(xaxis);

        QFont font;
        //font.setPointSize(6);
        font.setPointSize(12);
        customPlot->legend->setVisible(true);
        customPlot->legend->setFont(font);
        customPlot->legend->setBrush(QColor(255, 255, 255, 150));
        //customPlot->legend->addItem()

        customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);
        // 设置底部x轴刻度名称显示为日期
        QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
        //dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
        dateTicker->setDateTimeFormat("MM/dd\nhh:mm");
        customPlot->xAxis->setTicker(dateTicker);
        //customPlot->xAxis->setPadding(10);  //坐标轴距边界距离
        customPlot->xAxis->setRange(xaxis.first(), xaxis.last());
        customPlot->yAxis->setRange(yaxis.first(), yaxis.last());
        customPlot->xAxis->setTickLabelRotation(-90);

        //font.setPointSize(5);
        font.setPixelSize(10);
        customPlot->xAxis->setTickLabelFont(font);
        customPlot->yAxis->setTickLabelFont(font);
        //customPlot->rescaleAxes(false);
        customPlot->replot();
    }
}

void FormGraph::resizeEvent(QResizeEvent *e)
{
    for(int i = 0; i < 7; i++)
    {
        double width = 0;
        if (i == 0)
        {
            width = (this->width()-20)/12;
        }
        else if (i == 1)
        {
            width = (this->width()-20)/6;
        }
        else if (i == 3 || i == 4)
        {
            width = (this->width()-20)*5/36;
        }
        else if (i > 4)
        {
            width = (this->width()-20)/18;
            //ui->warningTableView->setColumnWidth(i,40);
        }
        else
        {
            width = (this->width()-20)*13/36;
        }
        ui->warningTableView->setColumnWidth(i, width);
    }
    QWidget::resizeEvent(e);
}

void FormGraph::styleForHome()
{
    _selectData->styleForHome();

    connect(RecvMsgObject::instance(), SIGNAL(sigAddWarning(QString,QString,QString,QString,QColor)),
            this, SLOT(onAddWaring(QString,QString,QString,QString, QColor)), Qt::QueuedConnection);
    connect(RecvMsgObject::instance(), SIGNAL(sigPreUpdateData(QDateTime)), this,
            SLOT(onPreUpdateData(QDateTime)), Qt::QueuedConnection);
    connect(RecvMsgObject::instance(), SIGNAL(sigEndUpdateData(QDateTime)), this,
            SLOT(onEndUpdateData(QDateTime)),Qt::QueuedConnection);

    _period = 15 * 60;

    _timer = new QTimer(this);
    connect(_timer,SIGNAL(timeout()),this,SLOT(timeUpDate()));
    _timer->start(30000);
}

void FormGraph::styleForChart()
{
    _selectData->styleForGraph();
    hiddenWarning(true);
    hiddenGraphTitle(true);

    _period = 15 * 60;

    _timer = new QTimer(this);
    connect(_timer,SIGNAL(timeout()),this,SLOT(timeUpDate()));
    _timer->start(30000);
}

void FormGraph::styleForWarning()
{
    connect(RecvMsgObject::instance(), SIGNAL(sigAddWarning(QString,QString,QString,QString,QColor)),
            this, SLOT(onAddWaring(QString,QString,QString,QString, QColor)), Qt::QueuedConnection);
    connect(RecvMsgObject::instance(), SIGNAL(sigPreUpdateData(QDateTime)), this,
            SLOT(onPreUpdateData(QDateTime)), Qt::QueuedConnection);
    connect(RecvMsgObject::instance(), SIGNAL(sigEndUpdateData(QDateTime)), this,
            SLOT(onEndUpdateData(QDateTime)),Qt::QueuedConnection);

    ui->graphBox->setVisible(false);
    ui->label_3->setVisible(false);
    hiddenGraph(true);
    hiddenWarningTitle(true);
}

void FormGraph::hiddenWarning(bool hidden)
{
    ui->warningWidge->setVisible(!hidden);
}

void FormGraph::hiddenGraph(bool hidden)
{
    ui->graphWidge->setVisible(!hidden);
}

void FormGraph::hiddenWarningTitle(bool hidden)
{
    ui->warningTitle->setVisible(!hidden);
}

void FormGraph::hiddenGraphTitle(bool hidden)
{
    ui->graphTitle->setVisible(!hidden);
}

void FormGraph::initializeSelect()
{
    if (ui->hostGroupBox->currentIndex() == 0)
    {
        if (ui->hostBox->currentIndex() == 0)
        {
            if (ui->graphBox->currentIndex() != 0)
            {
                ui->graphBox->setCurrentIndex(0);
            }
        }
        else {
            ui->hostBox->setCurrentIndex(0);
        }
    }
    else {
       ui->hostGroupBox->setCurrentIndex(0);
    }
}

void FormGraph::setCurrenHost(QString str)
{
    ui->hostGroupBox->setCurrentIndex(0);
    int  c = ui->hostBox->count();

    for(int i=0; i<c; i++)
    {
        QVariantMap map = ui->hostGroupBox->itemData(i).toMap();
        QString hostIP = map.value("ip").toString();
        if (hostIP.contains(str, Qt::CaseSensitive))
        {
            ui->hostBox->setCurrentIndex(i);
            return;
        }
    }

}

FormGraph::~FormGraph()
{
    delete _netWorker;
    delete _selectData;
    delete ui;
}

FormGraph::rgb FormGraph::colorSwichRGB(const int color)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    rgb colorRgb;
    colorRgb.r=( 0xff <<16 & color ) >> 16;
    colorRgb.g=( 0xff <<8 & color ) >> 8;
    colorRgb.b=0xff & color;
    //cout << colorRgb.r << colorRgb.g << colorRgb.b <<endl;
    return colorRgb;
}

/********************************点击事件******************************************/

void FormGraph::timeUpDate()
{
    if (!(_currentGraphID.isEmpty() || _currentGraphID.isNull()) && _currentGraphID != 0)
    {
        QString period = QString::number(_period);
        QString paramerter = QString("action=chart&graphid=%1&period=%2").arg(_currentGraphID,period);
        getGraph(paramerter);

        if (_period > INSTANT_CYCLE)
        {
            _isHistory = 1;
            getGraph(paramerter,_isHistory);
        }
        else {
            _isHistory = 0;
        }

    }
}

//全部按钮
void FormGraph::on_allButton_clicked()
{
    initializeSelect();
}

//时间
void FormGraph::timeSelected(QString name, QString title)
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
    QString paramerter = QString("action=chart&graphid=%1&period=%2").arg(_currentGraphID,period);
    getGraph(paramerter);

    if (_period > INSTANT_CYCLE)
    {
        _isHistory = 1;
        getGraph(paramerter,_isHistory);
    }
    else {
        _isHistory = 0;
    }

}

void FormGraph::selectDateTime(long startTime, long endTime)
{
    QString stime = QString::number(startTime);
    QString etime = QString::number(endTime);
    QString paramerter = QString("action=chart&graphid=%1&start_time=%2&end_time=%3").arg(_currentGraphID,stime,etime);
    qDebug() << "select date----" << endTime-startTime << endl;
    getGraph(paramerter);

    if (endTime - startTime > INSTANT_CYCLE)
    {
        _isHistory = 1;
        getGraph(paramerter,_isHistory);
    }
    else {
        _isHistory = 0;
    }

}

//主机组
void FormGraph::on_hostGroupBox_currentIndexChanged(const int index)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //根据所选机组id获取主机
    QVariantMap map = ui->hostGroupBox->itemData(index).toMap();
    //cout << "selected groupid" << map.value("groupid").toString() << endl;
    QString groupid = map.value("groupid").toString();
    getHosts(groupid);
}

//主机
void FormGraph::on_hostBox_currentIndexChanged(const int index)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //根据所选主机，获取监控项
    QVariantMap map = ui->hostBox->itemData(index).toMap();
    _currentHostName = map.value("name").toString();

    QString hostid = map.value("hostid").toString();

    if (!(hostid.isEmpty() || hostid.isNull()))
    {
        getItems(hostid);
        emit selectedHost(_currentHostName);
        RecvMsgObject::instance()->loadLocalData();
    }
}

//监控项
void FormGraph::on_graphBox_currentIndexChanged(const int index)
{
    //QTextStream cout(stdout, QIODevice::WriteOnly);

    QString time = QString::number(_period);
    QVariantMap map = ui->graphBox->itemData(index).toMap();
    QString graphid = map.value("graphid").toString();
    if (index != 0)
    {
        _currentGraphID = graphid;
        QString paramerter = QString("action=chart&graphid=%1&period=%2").arg(graphid,time);
        getGraph(paramerter);
        if (_period > INSTANT_CYCLE)
        {
            _isHistory = 1;
            getGraph(paramerter,_isHistory);
        }
        else {
            _isHistory = 0;
        }

        _selectData->initializeButtonColor();
    }

    emit selectItem(index);
}

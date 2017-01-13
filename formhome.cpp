#include "formhome.h"
#include "ui_formhome.h"
#include <QTextStream>
#include <QDebug>
#include "config.h"
#include "utils.h"

FormHome::FormHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHome)
{
    ui->setupUi(this);

    QFont font;  
    font.setPixelSize(16);
    ui->label->setFont(font);


    ui->viewGraph->styleForHome();
    ui->viewGraph->hiddenGraph(true);

    connect(ui->viewGraph, SIGNAL(selectItem(int)), this, SLOT(selectItem(int)), Qt::QueuedConnection);
    connect(ui->viewGraph, SIGNAL(newWarning_all()), this, SLOT(receiveNewWarning_all()),Qt::QueuedConnection);
    connect(ui->viewGraph, SIGNAL(newWarning()), this, SLOT(receiveNewWarning()),Qt::QueuedConnection);
    connect(ui->viewGraph, SIGNAL(selectedHost(QString)), this, SLOT(selectedHost(QString)),Qt::QueuedConnection);
    connect(ui->viewLeft, SIGNAL(topologyClick(int)), this, SLOT(topologyClicked(int)), Qt::QueuedConnection);

    _rightBtnClicked = false;
    _leftBtnClicked = false;


/*
    ui->widget_2->setAutoFillBackground(true);
    QPalette palette;
    //palette.setBrush(QPalette::Window, QBrush(QPixmap("1.png")));
    palette.setColor(QPalette::Background, QColor(Qt::yellow));
    ui->widget_2->setPalette(palette);
*/
}

FormHome::~FormHome()
{
    delete ui;
}

void FormHome::selectItem(const int index)
{
    if (index == 0){
        ui->viewGraph->hiddenGraph(true);
    }
    else {
        ui->viewGraph->hiddenGraph(false);
    }
}

void FormHome::receiveNewWarning_all()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //cout << "+++++++++++++"  << endl;
    emit newWarning_all();
}

void FormHome::receiveNewWarning()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //cout << "+++++++++++++"  << endl;
    emit newWarning();
}

void FormHome::selectedHost(QString hostName)
{
    ui->label->setText(hostName);
}

void FormHome::topologyClicked(const int index)
{
    bool b = Utils::fileExist(TOPOLOGY_FILE);
    QString str = Config::getTopology(index);
    qDebug() << b << "++++" << str << "++++" << index << endl;

    ui->viewGraph->setCurrenHost(str);
}

void FormHome::on_leftButton_clicked()
{
    if (_leftBtnClicked)
    {
        resumeView();
    }
    else
    {
        if (_rightBtnClicked)
        {
            setRightBtnClicked(false);
        }
        zoomView(ui->viewLeft);

    }

    setLeftBtnClicked(!_leftBtnClicked);
}

void FormHome::on_rightButton_clicked()
{
    if (_rightBtnClicked)
    {
        resumeView();
    }
    else
    {
        setLeftBtnClicked(false);
        zoomView(ui->viewRight);
    }

    setRightBtnClicked(!_rightBtnClicked);
}

void FormHome::setIcon(QPushButton *btn, QString &path)
{
    btn->setIcon(QIcon(path));
}

void FormHome::resumeView()
{
    ui->viewRight->setGeometry(_oldReightViewRT);
    ui->viewLeft->setGeometry(_oldLeftViewRt);
}

void FormHome::zoomView(QWidget *w)
{
    QRect viewLeftRect = ui->viewLeft->geometry();
    QRect viewRightRt = ui->viewRight->geometry();

    if (w == ui->viewLeft)
    {
        QRect rightButtonRect = ui->rightButton->geometry();

        /**
          左侧放大，右侧宽度缩小为右侧按钮宽度。左侧原来的宽度加上右侧减少的宽度。
          */
        viewLeftRect.setWidth(viewLeftRect.width()+viewRightRt.width()-rightButtonRect.width());
        viewRightRt.setX(this->width()-15-rightButtonRect.width());//重新设置右侧x坐标
        viewRightRt.setWidth(rightButtonRect.width());
    }

    if (w == ui->viewRight)
    {
        QRect leftButtonRect = ui->leftButton->geometry();

        viewRightRt.setX(20+leftButtonRect.width());
        viewLeftRect.setWidth(leftButtonRect.width());
    }

    ui->viewRight->setGeometry(viewRightRt);
    ui->viewLeft->setGeometry(viewLeftRect);
}

void FormHome::resizeEvent(QResizeEvent *e)
{
    QRect viewLeftRect = ui->viewLeft->geometry();
    QRect viewRightRt = ui->viewRight->geometry();

    _oldReightViewRT = viewRightRt;
    _oldLeftViewRt = viewLeftRect;

    QWidget::resizeEvent(e);
}
/*
void FormHome::mouseReleaseEvent(QMouseEvent *e)
{
    QRect rect = ui->viewLeft->geometry();
    QPoint lt(23.0/76*rect.width(),14.0/159*rect.height());
    QPoint rb(13.0/38*rect.width(),20.0/159*rect.height());
    QRect r(lt,rb);
    //if (r.contains(e->x(),e->y()))
    {
        qDebug() << e->x() << "----" << e->y() << endl;
        qDebug() << lt.x() << "," << lt.y() << "," << rb.x() << "," << rb.y()<<endl;
    }
}
*/

void FormHome::setRightBtnClicked(bool r)
{
    _rightBtnClicked = r;
    if (_rightBtnClicked)
    {
        QString string = ":/middle.jpg";
        setIcon(ui->rightButton, string);
    }
    else
    {
        QString string = ":/right.jpg";
        setIcon(ui->rightButton, string);
    }
}

void FormHome::setLeftBtnClicked(bool r)
{
    _leftBtnClicked = r;
    if (_leftBtnClicked)
    {
        QString string = ":/middle.jpg";
        setIcon(ui->leftButton, string);
    }
    else {
        QString string = ":/left.jpg";
        setIcon(ui->leftButton, string);
    }
}

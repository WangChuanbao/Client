#include "formselectdata.h"
#include "ui_formselectdata.h"
#include <QTextStream>

FormSelectData::FormSelectData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSelectData)
{
    ui->setupUi(this);
    QFont font;
    font.setPixelSize(12);
    ui->dateFrom->setFont(font);
    ui->dateFrom_2->setFont(font);
    ui->dateTo->setFont(font);
    ui->dateTo_2->setFont(font);

    font.setPixelSize(14);
    ui->label->setFont(font);
    ui->label_3->setFont(font);

    ui->dateFrom->setDateTime(QDateTime::currentDateTime());
    ui->dateTo->setDateTime(QDateTime::currentDateTime());
    ui->dateFrom_2->setDateTime(QDateTime::currentDateTime());
    ui->dateTo_2->setDateTime(QDateTime::currentDateTime()); 
}

bool FormSelectData::eventFilter( QObject *o, QEvent *e )
{
    QTextStream cout(stdout, QIODevice::WriteOnly);

    if (e->type() == QEvent::MouseButtonPress)
    {
        buttonClicked(o->objectName(),qobject_cast<QPushButton *>(o)->text());
    }
    return false;
}

void FormSelectData::styleForHome()
{
    ui->dateFrom->setMaximumDateTime(QDateTime::currentDateTime());
    ui->dateFrom->setDateTime(QDateTime::currentDateTime());
    ui->dateTo->setMaximumDateTime(QDateTime::currentDateTime());
    ui->dateTo->setDateTime(QDateTime::currentDateTime());

    ui->widget_4->setVisible(false);

    style = styleHome;

    installFilter(ui->widget);
}

void FormSelectData::styleForGraph()
{
    ui->dateFrom_2->setMaximumDateTime(QDateTime::currentDateTime());
    ui->dateFrom_2->setDateTime(QDateTime::currentDateTime());
    ui->dateTo_2->setMaximumDateTime(QDateTime::currentDateTime());
    ui->dateTo_2->setDateTime(QDateTime::currentDateTime());

    ui->widget_3->setVisible(false);

    style = stylechart;

    installFilter(ui->widget_4);
}

void FormSelectData::installFilter(QWidget *widget)
{
    QObjectList list = widget->children();
    //QFont font;
    //font.setPixelSize(12);
    foreach (QObject *obj, list) {
        if (obj->inherits("QPushButton"))
        {
            //qobject_cast<QPushButton *>(obj)->setFont(font);
            obj->installEventFilter(this);
        }
    }
}

void FormSelectData::changeButtonColor(QWidget *widget, QString &name)
{
    QObjectList list = widget->children();
    foreach (QObject *obj, list) {
        if (obj->inherits("QPushButton"))
        {
            qobject_cast<QPushButton *>(obj)->setStyleSheet("");
            if (obj->objectName() == name)
            {
                qobject_cast<QPushButton *>(obj)->setStyleSheet(QStringLiteral("color:rgb(0,0,255)"));
            }
        }
    }
}

void FormSelectData::initializeButtonColor()
{
    if (style == styleHome)
    {
        QString name = "t_15m";
        changeButtonColor(ui->widget, name);
    }
    else {
        QString name = "t_15m_2";
        changeButtonColor(ui->widget_4, name);
    }
}

void FormSelectData::resizeEvent(QResizeEvent *e)
{
    ui->widget_3->setGeometry(0,0,this->width(),this->height());
    ui->widget_4->setGeometry(0,0,this->width(),this->height());
    QWidget::resizeEvent(e);
}

FormSelectData::~FormSelectData()
{
    delete ui;
}

//时间按钮
void FormSelectData::buttonClicked(QString name, QString title)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //cout << name << title << endl;

    switch (style) {
    case styleHome:
    {
        changeButtonColor(ui->widget, name);
        break;
    }
    case stylechart:
    {
        changeButtonColor(ui->widget_4, name);
        break;
    }
    default:
        break;
    }

    emit selected(name, title);
}

/*********************日期选择器*************************/
void FormSelectData::on_dateFrom_dateTimeChanged(const QDateTime &dateTime)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    _startTime = dateTime.toTime_t();
    checkDateTime();
}

void FormSelectData::on_dateTo_dateTimeChanged(const QDateTime &dateTime)
{
    _endTime = dateTime.toTime_t();
    checkDateTime();
}

void FormSelectData::on_dateFrom_2_dateTimeChanged(const QDateTime &dateTime)
{
    _startTime = dateTime.toTime_t();
    checkDateTime();
}

void FormSelectData::on_dateTo_2_dateTimeChanged(const QDateTime &dateTime)
{
    _endTime = dateTime.toTime_t();
    checkDateTime();
}

void FormSelectData::checkDateTime()
{
    if (_startTime != 0 && _endTime != 0 && _startTime<_endTime)
        emit selectedDateTime(_startTime, _endTime);
}

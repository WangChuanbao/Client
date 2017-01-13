#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formhome.h"
#include "formgraph.h"
#include "formpoly.h"
#include "formchart.h"
#include <QTextStream>
#include "utils.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFont font;
    font.setPixelSize(18);
    ui->pushButton->setFont(font);
    ui->pushButton_2->setFont(font);
    ui->pushButton_3->setFont(font);
    ui->pushButton_4->setFont(font);
    font.setPixelSize(10);
    ui->pushButton_5->setFont(font);

    setWindowState(Qt::WindowMaximized);
    //修改视图背景色
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(Qt::gray));
    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(palette);

    _warningCount = 0;
    _warningCount_all = 0;
    ui->pushButton_5->setText("");

    _stack = new QStackedLayout();
    ui->verticalLayout_2->addLayout(_stack);

    FormHome *home = new FormHome(ui->centralWidget);
    _stack->addWidget(home);
    warning = new FormWarning(ui->centralWidget);
    _stack->addWidget(warning);
    FormChart *chart = new FormChart(ui->centralWidget);
    _stack->addWidget(chart);
    FormPoly *poly = new FormPoly(ui->centralWidget);
    _stack->addWidget(poly);

    ui->verticalLayout_2->setStretch(0,1);
    ui->verticalLayout_2->setStretch(0,2);

    connect(home, SIGNAL(newWarning()),this,SLOT(newWarning()),Qt::QueuedConnection);
    connect(home, SIGNAL(newWarning_all()),this,SLOT(newWarning_all()),Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete _stack;
    delete ui;
}

/*
void MainWindow::onAddWaring(const QString &strTime,
                 const QString &strName,
                 const QString &strDescription,
                 const QString &strSeverity,
                 const QColor &color)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << "this is mainwindow" << endl;
}
*/

void MainWindow::newWarning()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << "this is mainwindow" << endl;
    _warningCount++;
}

void MainWindow::newWarning_all()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //cout << "this is mainwindow" << endl;
    _warningCount_all++;
}

void MainWindow::changeWarningPrompt()
{
    if (_stack->currentIndex() == 0 || _stack->currentIndex() == 1)
    {
        QString string = QString::number(_warningCount) + "条新告警信息";
        ui->pushButton_5->setText(string);
    }
    else {
        QString string = QString::number(_warningCount_all) + "条新告警信息";
        ui->pushButton_5->setText(string);
    }
}

void MainWindow::changeButtonColor(int index)
{
    ui->pushButton->setStyleSheet("");
    ui->pushButton_2->setStyleSheet("");
    ui->pushButton_3->setStyleSheet("");
    ui->pushButton_4->setStyleSheet("");
    switch (index) {
    case 0:
        ui->pushButton->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        break;
    case 1:
        ui->pushButton_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        break;
    case 2:
        ui->pushButton_3->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        break;
    case 3:
        ui->pushButton_4->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    changeButtonColor(0);
    _stack->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    changeButtonColor(1);
    _stack->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    changeButtonColor(2);
    _stack->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    changeButtonColor(3);
    _stack->setCurrentIndex(3);
}

void MainWindow::on_pushButton_5_clicked()
{
    changeButtonColor(1);
    _stack->setCurrentIndex(1);
    warning->initializeSelect();
}

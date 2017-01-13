/********************************************************************************
** Form generated from reading UI file 'formselectdata.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSELECTDATA_H
#define UI_FORMSELECTDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSelectData
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *t_30m;
    QPushButton *t_1M;
    QPushButton *t_5m;
    QPushButton *t_6M;
    QPushButton *t_7d;
    QPushButton *t_3d;
    QPushButton *t_15m;
    QPushButton *t_1d;
    QPushButton *t_12h;
    QPushButton *t_all;
    QPushButton *t_14d;
    QPushButton *t_3h;
    QPushButton *t_1y;
    QPushButton *t_2h;
    QPushButton *t_3M;
    QPushButton *t_6h;
    QPushButton *t_1h;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *dateFrom;
    QLabel *label_2;
    QDateTimeEdit *dateTo;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *t_5m_2;
    QPushButton *t_15m_2;
    QPushButton *t_30m_2;
    QPushButton *t_1h_2;
    QPushButton *t_2h_2;
    QPushButton *t_3h_2;
    QPushButton *t_6h_2;
    QPushButton *t_12h_2;
    QPushButton *t_1d_2;
    QPushButton *t_3d_2;
    QPushButton *t_7d_2;
    QPushButton *t_14d_2;
    QPushButton *t_1M_2;
    QPushButton *t_3M_2;
    QPushButton *t_6M_2;
    QPushButton *t_1y_2;
    QPushButton *t_all_2;
    QSpacerItem *horizontalSpacer;
    QDateTimeEdit *dateFrom_2;
    QLabel *label_4;
    QDateTimeEdit *dateTo_2;

    void setupUi(QWidget *FormSelectData)
    {
        if (FormSelectData->objectName().isEmpty())
            FormSelectData->setObjectName(QStringLiteral("FormSelectData"));
        FormSelectData->resize(1130, 400);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormSelectData->sizePolicy().hasHeightForWidth());
        FormSelectData->setSizePolicy(sizePolicy);
        FormSelectData->setMinimumSize(QSize(0, 0));
        FormSelectData->setMaximumSize(QSize(16777215, 16777215));
        FormSelectData->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(FormSelectData);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 5, 0, 5);
        widget_3 = new QWidget(FormSelectData);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setMaximumSize(QSize(16777215, 80));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(227, 227, 227);"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(12);
        widget->setFont(font);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(227, 227, 227);"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        t_30m = new QPushButton(widget);
        t_30m->setObjectName(QStringLiteral("t_30m"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(t_30m->sizePolicy().hasHeightForWidth());
        t_30m->setSizePolicy(sizePolicy3);
        t_30m->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setPointSize(5);
        t_30m->setFont(font1);

        gridLayout->addWidget(t_30m, 0, 5, 1, 1);

        t_1M = new QPushButton(widget);
        t_1M->setObjectName(QStringLiteral("t_1M"));
        sizePolicy3.setHeightForWidth(t_1M->sizePolicy().hasHeightForWidth());
        t_1M->setSizePolicy(sizePolicy3);
        t_1M->setMaximumSize(QSize(30, 30));
        t_1M->setFont(font1);

        gridLayout->addWidget(t_1M, 1, 7, 1, 1);

        t_5m = new QPushButton(widget);
        t_5m->setObjectName(QStringLiteral("t_5m"));
        sizePolicy3.setHeightForWidth(t_5m->sizePolicy().hasHeightForWidth());
        t_5m->setSizePolicy(sizePolicy3);
        t_5m->setMaximumSize(QSize(30, 30));
        t_5m->setFont(font1);

        gridLayout->addWidget(t_5m, 0, 3, 1, 1);

        t_6M = new QPushButton(widget);
        t_6M->setObjectName(QStringLiteral("t_6M"));
        sizePolicy3.setHeightForWidth(t_6M->sizePolicy().hasHeightForWidth());
        t_6M->setSizePolicy(sizePolicy3);
        t_6M->setMaximumSize(QSize(30, 30));
        t_6M->setFont(font1);

        gridLayout->addWidget(t_6M, 1, 10, 1, 1);

        t_7d = new QPushButton(widget);
        t_7d->setObjectName(QStringLiteral("t_7d"));
        sizePolicy3.setHeightForWidth(t_7d->sizePolicy().hasHeightForWidth());
        t_7d->setSizePolicy(sizePolicy3);
        t_7d->setMaximumSize(QSize(30, 30));
        t_7d->setFont(font1);

        gridLayout->addWidget(t_7d, 1, 5, 1, 1);

        t_3d = new QPushButton(widget);
        t_3d->setObjectName(QStringLiteral("t_3d"));
        sizePolicy3.setHeightForWidth(t_3d->sizePolicy().hasHeightForWidth());
        t_3d->setSizePolicy(sizePolicy3);
        t_3d->setMaximumSize(QSize(30, 30));
        t_3d->setFont(font1);

        gridLayout->addWidget(t_3d, 1, 4, 1, 1);

        t_15m = new QPushButton(widget);
        t_15m->setObjectName(QStringLiteral("t_15m"));
        sizePolicy3.setHeightForWidth(t_15m->sizePolicy().hasHeightForWidth());
        t_15m->setSizePolicy(sizePolicy3);
        t_15m->setMaximumSize(QSize(30, 30));
        t_15m->setFont(font1);
        t_15m->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(t_15m, 0, 4, 1, 1);

        t_1d = new QPushButton(widget);
        t_1d->setObjectName(QStringLiteral("t_1d"));
        sizePolicy3.setHeightForWidth(t_1d->sizePolicy().hasHeightForWidth());
        t_1d->setSizePolicy(sizePolicy3);
        t_1d->setMaximumSize(QSize(30, 30));
        t_1d->setFont(font1);

        gridLayout->addWidget(t_1d, 1, 3, 1, 1);

        t_12h = new QPushButton(widget);
        t_12h->setObjectName(QStringLiteral("t_12h"));
        sizePolicy3.setHeightForWidth(t_12h->sizePolicy().hasHeightForWidth());
        t_12h->setSizePolicy(sizePolicy3);
        t_12h->setMaximumSize(QSize(30, 30));
        t_12h->setFont(font1);

        gridLayout->addWidget(t_12h, 0, 11, 1, 1);

        t_all = new QPushButton(widget);
        t_all->setObjectName(QStringLiteral("t_all"));
        sizePolicy3.setHeightForWidth(t_all->sizePolicy().hasHeightForWidth());
        t_all->setSizePolicy(sizePolicy3);
        t_all->setMaximumSize(QSize(30, 30));
        t_all->setFont(font1);

        gridLayout->addWidget(t_all, 1, 12, 1, 1);

        t_14d = new QPushButton(widget);
        t_14d->setObjectName(QStringLiteral("t_14d"));
        sizePolicy3.setHeightForWidth(t_14d->sizePolicy().hasHeightForWidth());
        t_14d->setSizePolicy(sizePolicy3);
        t_14d->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setPointSize(5);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        t_14d->setFont(font2);
        t_14d->setContextMenuPolicy(Qt::DefaultContextMenu);

        gridLayout->addWidget(t_14d, 1, 6, 1, 1);

        t_3h = new QPushButton(widget);
        t_3h->setObjectName(QStringLiteral("t_3h"));
        sizePolicy3.setHeightForWidth(t_3h->sizePolicy().hasHeightForWidth());
        t_3h->setSizePolicy(sizePolicy3);
        t_3h->setMaximumSize(QSize(30, 30));
        t_3h->setFont(font1);

        gridLayout->addWidget(t_3h, 0, 8, 1, 1);

        t_1y = new QPushButton(widget);
        t_1y->setObjectName(QStringLiteral("t_1y"));
        sizePolicy3.setHeightForWidth(t_1y->sizePolicy().hasHeightForWidth());
        t_1y->setSizePolicy(sizePolicy3);
        t_1y->setMaximumSize(QSize(30, 30));
        t_1y->setFont(font1);

        gridLayout->addWidget(t_1y, 1, 11, 1, 1);

        t_2h = new QPushButton(widget);
        t_2h->setObjectName(QStringLiteral("t_2h"));
        sizePolicy3.setHeightForWidth(t_2h->sizePolicy().hasHeightForWidth());
        t_2h->setSizePolicy(sizePolicy3);
        t_2h->setMaximumSize(QSize(30, 30));
        t_2h->setFont(font1);

        gridLayout->addWidget(t_2h, 0, 7, 1, 1);

        t_3M = new QPushButton(widget);
        t_3M->setObjectName(QStringLiteral("t_3M"));
        sizePolicy3.setHeightForWidth(t_3M->sizePolicy().hasHeightForWidth());
        t_3M->setSizePolicy(sizePolicy3);
        t_3M->setMaximumSize(QSize(30, 30));
        t_3M->setFont(font1);

        gridLayout->addWidget(t_3M, 1, 8, 1, 1);

        t_6h = new QPushButton(widget);
        t_6h->setObjectName(QStringLiteral("t_6h"));
        sizePolicy3.setHeightForWidth(t_6h->sizePolicy().hasHeightForWidth());
        t_6h->setSizePolicy(sizePolicy3);
        t_6h->setMaximumSize(QSize(30, 30));
        t_6h->setFont(font1);

        gridLayout->addWidget(t_6h, 0, 10, 1, 1);

        t_1h = new QPushButton(widget);
        t_1h->setObjectName(QStringLiteral("t_1h"));
        sizePolicy3.setHeightForWidth(t_1h->sizePolicy().hasHeightForWidth());
        t_1h->setSizePolicy(sizePolicy3);
        t_1h->setMaximumSize(QSize(30, 30));
        t_1h->setFont(font1);

        gridLayout->addWidget(t_1h, 0, 6, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(7);
        label->setFont(font3);

        gridLayout->addWidget(label, 0, 2, 1, 1);


        horizontalLayout_2->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy4);
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(227, 227, 227);"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dateFrom = new QDateTimeEdit(widget_2);
        dateFrom->setObjectName(QStringLiteral("dateFrom"));
        sizePolicy3.setHeightForWidth(dateFrom->sizePolicy().hasHeightForWidth());
        dateFrom->setSizePolicy(sizePolicy3);
        dateFrom->setMinimumSize(QSize(130, 0));
        dateFrom->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setPointSize(5);
        font4.setKerning(true);
        dateFrom->setFont(font4);
        dateFrom->setCalendarPopup(true);

        horizontalLayout->addWidget(dateFrom);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        dateTo = new QDateTimeEdit(widget_2);
        dateTo->setObjectName(QStringLiteral("dateTo"));
        sizePolicy3.setHeightForWidth(dateTo->sizePolicy().hasHeightForWidth());
        dateTo->setSizePolicy(sizePolicy3);
        dateTo->setMinimumSize(QSize(130, 0));
        dateTo->setMaximumSize(QSize(16777215, 16777215));
        dateTo->setFont(font1);
        dateTo->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        dateTo->setCalendarPopup(true);

        horizontalLayout->addWidget(dateTo);


        horizontalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(FormSelectData);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        widget_4->setStyleSheet(QStringLiteral("background-color: rgb(227, 227, 227);"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setFont(font3);

        horizontalLayout_3->addWidget(label_3);

        t_5m_2 = new QPushButton(widget_4);
        t_5m_2->setObjectName(QStringLiteral("t_5m_2"));
        sizePolicy3.setHeightForWidth(t_5m_2->sizePolicy().hasHeightForWidth());
        t_5m_2->setSizePolicy(sizePolicy3);
        t_5m_2->setMaximumSize(QSize(30, 30));
        t_5m_2->setFont(font1);

        horizontalLayout_3->addWidget(t_5m_2);

        t_15m_2 = new QPushButton(widget_4);
        t_15m_2->setObjectName(QStringLiteral("t_15m_2"));
        sizePolicy3.setHeightForWidth(t_15m_2->sizePolicy().hasHeightForWidth());
        t_15m_2->setSizePolicy(sizePolicy3);
        t_15m_2->setMaximumSize(QSize(30, 30));
        t_15m_2->setFont(font1);
        t_15m_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        horizontalLayout_3->addWidget(t_15m_2);

        t_30m_2 = new QPushButton(widget_4);
        t_30m_2->setObjectName(QStringLiteral("t_30m_2"));
        sizePolicy3.setHeightForWidth(t_30m_2->sizePolicy().hasHeightForWidth());
        t_30m_2->setSizePolicy(sizePolicy3);
        t_30m_2->setMaximumSize(QSize(30, 30));
        t_30m_2->setFont(font1);

        horizontalLayout_3->addWidget(t_30m_2);

        t_1h_2 = new QPushButton(widget_4);
        t_1h_2->setObjectName(QStringLiteral("t_1h_2"));
        sizePolicy3.setHeightForWidth(t_1h_2->sizePolicy().hasHeightForWidth());
        t_1h_2->setSizePolicy(sizePolicy3);
        t_1h_2->setMaximumSize(QSize(30, 30));
        t_1h_2->setFont(font1);

        horizontalLayout_3->addWidget(t_1h_2);

        t_2h_2 = new QPushButton(widget_4);
        t_2h_2->setObjectName(QStringLiteral("t_2h_2"));
        sizePolicy3.setHeightForWidth(t_2h_2->sizePolicy().hasHeightForWidth());
        t_2h_2->setSizePolicy(sizePolicy3);
        t_2h_2->setMaximumSize(QSize(30, 30));
        t_2h_2->setFont(font1);

        horizontalLayout_3->addWidget(t_2h_2);

        t_3h_2 = new QPushButton(widget_4);
        t_3h_2->setObjectName(QStringLiteral("t_3h_2"));
        sizePolicy3.setHeightForWidth(t_3h_2->sizePolicy().hasHeightForWidth());
        t_3h_2->setSizePolicy(sizePolicy3);
        t_3h_2->setMaximumSize(QSize(30, 30));
        t_3h_2->setFont(font1);

        horizontalLayout_3->addWidget(t_3h_2);

        t_6h_2 = new QPushButton(widget_4);
        t_6h_2->setObjectName(QStringLiteral("t_6h_2"));
        sizePolicy3.setHeightForWidth(t_6h_2->sizePolicy().hasHeightForWidth());
        t_6h_2->setSizePolicy(sizePolicy3);
        t_6h_2->setMaximumSize(QSize(30, 30));
        t_6h_2->setFont(font1);

        horizontalLayout_3->addWidget(t_6h_2);

        t_12h_2 = new QPushButton(widget_4);
        t_12h_2->setObjectName(QStringLiteral("t_12h_2"));
        sizePolicy3.setHeightForWidth(t_12h_2->sizePolicy().hasHeightForWidth());
        t_12h_2->setSizePolicy(sizePolicy3);
        t_12h_2->setMaximumSize(QSize(30, 30));
        QFont font5;
        font5.setFamily(QStringLiteral(".SF NS Text"));
        font5.setPointSize(5);
        t_12h_2->setFont(font5);

        horizontalLayout_3->addWidget(t_12h_2);

        t_1d_2 = new QPushButton(widget_4);
        t_1d_2->setObjectName(QStringLiteral("t_1d_2"));
        sizePolicy3.setHeightForWidth(t_1d_2->sizePolicy().hasHeightForWidth());
        t_1d_2->setSizePolicy(sizePolicy3);
        t_1d_2->setMaximumSize(QSize(30, 30));
        t_1d_2->setFont(font1);

        horizontalLayout_3->addWidget(t_1d_2);

        t_3d_2 = new QPushButton(widget_4);
        t_3d_2->setObjectName(QStringLiteral("t_3d_2"));
        sizePolicy3.setHeightForWidth(t_3d_2->sizePolicy().hasHeightForWidth());
        t_3d_2->setSizePolicy(sizePolicy3);
        t_3d_2->setMaximumSize(QSize(30, 30));
        t_3d_2->setFont(font1);

        horizontalLayout_3->addWidget(t_3d_2);

        t_7d_2 = new QPushButton(widget_4);
        t_7d_2->setObjectName(QStringLiteral("t_7d_2"));
        sizePolicy3.setHeightForWidth(t_7d_2->sizePolicy().hasHeightForWidth());
        t_7d_2->setSizePolicy(sizePolicy3);
        t_7d_2->setMaximumSize(QSize(30, 30));
        t_7d_2->setFont(font1);

        horizontalLayout_3->addWidget(t_7d_2);

        t_14d_2 = new QPushButton(widget_4);
        t_14d_2->setObjectName(QStringLiteral("t_14d_2"));
        sizePolicy3.setHeightForWidth(t_14d_2->sizePolicy().hasHeightForWidth());
        t_14d_2->setSizePolicy(sizePolicy3);
        t_14d_2->setMaximumSize(QSize(30, 30));
        t_14d_2->setFont(font1);

        horizontalLayout_3->addWidget(t_14d_2);

        t_1M_2 = new QPushButton(widget_4);
        t_1M_2->setObjectName(QStringLiteral("t_1M_2"));
        sizePolicy3.setHeightForWidth(t_1M_2->sizePolicy().hasHeightForWidth());
        t_1M_2->setSizePolicy(sizePolicy3);
        t_1M_2->setMaximumSize(QSize(30, 30));
        t_1M_2->setFont(font1);

        horizontalLayout_3->addWidget(t_1M_2);

        t_3M_2 = new QPushButton(widget_4);
        t_3M_2->setObjectName(QStringLiteral("t_3M_2"));
        sizePolicy3.setHeightForWidth(t_3M_2->sizePolicy().hasHeightForWidth());
        t_3M_2->setSizePolicy(sizePolicy3);
        t_3M_2->setMaximumSize(QSize(30, 30));
        t_3M_2->setFont(font1);

        horizontalLayout_3->addWidget(t_3M_2);

        t_6M_2 = new QPushButton(widget_4);
        t_6M_2->setObjectName(QStringLiteral("t_6M_2"));
        sizePolicy3.setHeightForWidth(t_6M_2->sizePolicy().hasHeightForWidth());
        t_6M_2->setSizePolicy(sizePolicy3);
        t_6M_2->setMaximumSize(QSize(30, 30));
        t_6M_2->setFont(font1);

        horizontalLayout_3->addWidget(t_6M_2);

        t_1y_2 = new QPushButton(widget_4);
        t_1y_2->setObjectName(QStringLiteral("t_1y_2"));
        sizePolicy3.setHeightForWidth(t_1y_2->sizePolicy().hasHeightForWidth());
        t_1y_2->setSizePolicy(sizePolicy3);
        t_1y_2->setMaximumSize(QSize(30, 30));
        t_1y_2->setFont(font1);

        horizontalLayout_3->addWidget(t_1y_2);

        t_all_2 = new QPushButton(widget_4);
        t_all_2->setObjectName(QStringLiteral("t_all_2"));
        sizePolicy3.setHeightForWidth(t_all_2->sizePolicy().hasHeightForWidth());
        t_all_2->setSizePolicy(sizePolicy3);
        t_all_2->setMaximumSize(QSize(30, 30));
        t_all_2->setFont(font1);

        horizontalLayout_3->addWidget(t_all_2);

        horizontalSpacer = new QSpacerItem(1, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        dateFrom_2 = new QDateTimeEdit(widget_4);
        dateFrom_2->setObjectName(QStringLiteral("dateFrom_2"));
        sizePolicy3.setHeightForWidth(dateFrom_2->sizePolicy().hasHeightForWidth());
        dateFrom_2->setSizePolicy(sizePolicy3);
        dateFrom_2->setMinimumSize(QSize(130, 0));
        dateFrom_2->setMaximumSize(QSize(16777215, 16777215));
        dateFrom_2->setFont(font1);
        dateFrom_2->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateFrom_2);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMaximumSize(QSize(30, 30));
        label_4->setFont(font3);

        horizontalLayout_3->addWidget(label_4);

        dateTo_2 = new QDateTimeEdit(widget_4);
        dateTo_2->setObjectName(QStringLiteral("dateTo_2"));
        sizePolicy3.setHeightForWidth(dateTo_2->sizePolicy().hasHeightForWidth());
        dateTo_2->setSizePolicy(sizePolicy3);
        dateTo_2->setMinimumSize(QSize(130, 0));
        dateTo_2->setMaximumSize(QSize(16777215, 16777215));
        dateTo_2->setFont(font1);
        dateTo_2->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateTo_2);


        verticalLayout->addWidget(widget_4);


        retranslateUi(FormSelectData);

        QMetaObject::connectSlotsByName(FormSelectData);
    } // setupUi

    void retranslateUi(QWidget *FormSelectData)
    {
        FormSelectData->setWindowTitle(QApplication::translate("FormSelectData", "Form", 0));
        t_30m->setText(QApplication::translate("FormSelectData", "30m", 0));
        t_1M->setText(QApplication::translate("FormSelectData", "1M", 0));
        t_5m->setText(QApplication::translate("FormSelectData", "5m", 0));
        t_6M->setText(QApplication::translate("FormSelectData", "6M", 0));
        t_7d->setText(QApplication::translate("FormSelectData", "7d", 0));
        t_3d->setText(QApplication::translate("FormSelectData", "3d", 0));
        t_15m->setText(QApplication::translate("FormSelectData", "15m", 0));
        t_1d->setText(QApplication::translate("FormSelectData", "1d", 0));
        t_12h->setText(QApplication::translate("FormSelectData", "12h", 0));
        t_all->setText(QApplication::translate("FormSelectData", "\346\211\200\346\234\211", 0));
        t_14d->setText(QApplication::translate("FormSelectData", "14d", 0));
        t_3h->setText(QApplication::translate("FormSelectData", "3h", 0));
        t_1y->setText(QApplication::translate("FormSelectData", "1y", 0));
        t_2h->setText(QApplication::translate("FormSelectData", "2h", 0));
        t_3M->setText(QApplication::translate("FormSelectData", "3M", 0));
        t_6h->setText(QApplication::translate("FormSelectData", "6h", 0));
        t_1h->setText(QApplication::translate("FormSelectData", "1h", 0));
        label->setText(QApplication::translate("FormSelectData", "\346\227\266\351\227\264\346\256\265", 0));
        dateFrom->setDisplayFormat(QApplication::translate("FormSelectData", "yyyy/M/d hh:mm", 0));
        label_2->setText(QApplication::translate("FormSelectData", "\357\274\215", 0));
        dateTo->setDisplayFormat(QApplication::translate("FormSelectData", "yyyy/M/d hh:mm", 0));
        label_3->setText(QApplication::translate("FormSelectData", "\346\227\266\351\227\264\346\256\265", 0));
        t_5m_2->setText(QApplication::translate("FormSelectData", "5m", 0));
        t_15m_2->setText(QApplication::translate("FormSelectData", "15m", 0));
        t_30m_2->setText(QApplication::translate("FormSelectData", "30m", 0));
        t_1h_2->setText(QApplication::translate("FormSelectData", "1h", 0));
        t_2h_2->setText(QApplication::translate("FormSelectData", "2h", 0));
        t_3h_2->setText(QApplication::translate("FormSelectData", "3h", 0));
        t_6h_2->setText(QApplication::translate("FormSelectData", "6h", 0));
        t_12h_2->setText(QApplication::translate("FormSelectData", "12h", 0));
        t_1d_2->setText(QApplication::translate("FormSelectData", "1d", 0));
        t_3d_2->setText(QApplication::translate("FormSelectData", "3d", 0));
        t_7d_2->setText(QApplication::translate("FormSelectData", "7d", 0));
        t_14d_2->setText(QApplication::translate("FormSelectData", "14d", 0));
        t_1M_2->setText(QApplication::translate("FormSelectData", "1M", 0));
        t_3M_2->setText(QApplication::translate("FormSelectData", "3M", 0));
        t_6M_2->setText(QApplication::translate("FormSelectData", "6M", 0));
        t_1y_2->setText(QApplication::translate("FormSelectData", "1y", 0));
        t_all_2->setText(QApplication::translate("FormSelectData", "\346\211\200\346\234\211", 0));
        dateFrom_2->setDisplayFormat(QApplication::translate("FormSelectData", "yyyy/M/d hh:mm", 0));
        label_4->setText(QApplication::translate("FormSelectData", "\357\274\215", 0));
        dateTo_2->setDisplayFormat(QApplication::translate("FormSelectData", "yyyy/M/d hh:mm", 0));
    } // retranslateUi

};

namespace Ui {
    class FormSelectData: public Ui_FormSelectData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSELECTDATA_H

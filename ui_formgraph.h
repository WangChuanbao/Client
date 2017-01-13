/********************************************************************************
** Form generated from reading UI file 'formgraph.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGRAPH_H
#define UI_FORMGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FormGraph
{
public:
    QVBoxLayout *verticalLayout_6;
    QWidget *searchWidge;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *allButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *hostGroupBox;
    QLabel *label_2;
    QComboBox *hostBox;
    QLabel *label_3;
    QComboBox *graphBox;
    QWidget *warningWidge;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *warningTitle;
    QTableView *warningTableView;
    QWidget *graphWidge;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *graphTitle;
    QCustomPlot *graph;

    void setupUi(QWidget *FormGraph)
    {
        if (FormGraph->objectName().isEmpty())
            FormGraph->setObjectName(QStringLiteral("FormGraph"));
        FormGraph->resize(1560, 450);
        FormGraph->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_6 = new QVBoxLayout(FormGraph);
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        searchWidge = new QWidget(FormGraph);
        searchWidge->setObjectName(QStringLiteral("searchWidge"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchWidge->sizePolicy().hasHeightForWidth());
        searchWidge->setSizePolicy(sizePolicy);
        searchWidge->setMinimumSize(QSize(0, 0));
        searchWidge->setMaximumSize(QSize(16777215, 16777215));
        searchWidge->setStyleSheet(QStringLiteral("background-color: rgb(205, 205, 205);"));
        verticalLayout = new QVBoxLayout(searchWidge);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        allButton = new QPushButton(searchWidge);
        allButton->setObjectName(QStringLiteral("allButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(allButton->sizePolicy().hasHeightForWidth());
        allButton->setSizePolicy(sizePolicy1);
        allButton->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(7);
        allButton->setFont(font);

        horizontalLayout->addWidget(allButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(searchWidge);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        hostGroupBox = new QComboBox(searchWidge);
        hostGroupBox->setObjectName(QStringLiteral("hostGroupBox"));
        QFont font1;
        font1.setPointSize(6);
        hostGroupBox->setFont(font1);
        hostGroupBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout->addWidget(hostGroupBox);

        label_2 = new QLabel(searchWidge);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        hostBox = new QComboBox(searchWidge);
        hostBox->setObjectName(QStringLiteral("hostBox"));
        hostBox->setFont(font1);
        hostBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout->addWidget(hostBox);

        label_3 = new QLabel(searchWidge);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        graphBox = new QComboBox(searchWidge);
        graphBox->setObjectName(QStringLiteral("graphBox"));
        graphBox->setFont(font1);
        graphBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout->addWidget(graphBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_6->addWidget(searchWidge);

        warningWidge = new QWidget(FormGraph);
        warningWidge->setObjectName(QStringLiteral("warningWidge"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(warningWidge->sizePolicy().hasHeightForWidth());
        warningWidge->setSizePolicy(sizePolicy3);
        warningWidge->setMaximumSize(QSize(16777215, 16777215));
        warningWidge->setStyleSheet(QStringLiteral("background-color: rgb(205, 205, 205);"));
        verticalLayout_4 = new QVBoxLayout(warningWidge);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, 0);
        warningTitle = new QLabel(warningWidge);
        warningTitle->setObjectName(QStringLiteral("warningTitle"));
        sizePolicy2.setHeightForWidth(warningTitle->sizePolicy().hasHeightForWidth());
        warningTitle->setSizePolicy(sizePolicy2);
        warningTitle->setFont(font);
        warningTitle->setScaledContents(true);

        verticalLayout_2->addWidget(warningTitle);

        warningTableView = new QTableView(warningWidge);
        warningTableView->setObjectName(QStringLiteral("warningTableView"));
        sizePolicy3.setHeightForWidth(warningTableView->sizePolicy().hasHeightForWidth());
        warningTableView->setSizePolicy(sizePolicy3);
        warningTableView->setFont(font1);
        warningTableView->setLayoutDirection(Qt::LeftToRight);
        warningTableView->setAutoFillBackground(false);
        warningTableView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        warningTableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        warningTableView->horizontalHeader()->setCascadingSectionResizes(false);
        warningTableView->horizontalHeader()->setDefaultSectionSize(15);
        warningTableView->horizontalHeader()->setStretchLastSection(false);
        warningTableView->verticalHeader()->setVisible(false);
        warningTableView->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(warningTableView);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_6->addWidget(warningWidge);

        graphWidge = new QWidget(FormGraph);
        graphWidge->setObjectName(QStringLiteral("graphWidge"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(graphWidge->sizePolicy().hasHeightForWidth());
        graphWidge->setSizePolicy(sizePolicy4);
        graphWidge->setStyleSheet(QStringLiteral("background-color: rgb(205, 205, 205);"));
        verticalLayout_5 = new QVBoxLayout(graphWidge);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, 0, 0);
        graphTitle = new QLabel(graphWidge);
        graphTitle->setObjectName(QStringLiteral("graphTitle"));
        sizePolicy2.setHeightForWidth(graphTitle->sizePolicy().hasHeightForWidth());
        graphTitle->setSizePolicy(sizePolicy2);
        graphTitle->setFont(font);
        graphTitle->setScaledContents(true);

        verticalLayout_3->addWidget(graphTitle);

        graph = new QCustomPlot(graphWidge);
        graph->setObjectName(QStringLiteral("graph"));
        sizePolicy4.setHeightForWidth(graph->sizePolicy().hasHeightForWidth());
        graph->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(graph);


        verticalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_6->addWidget(graphWidge);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 5);
        verticalLayout_6->setStretch(2, 8);

        retranslateUi(FormGraph);

        QMetaObject::connectSlotsByName(FormGraph);
    } // setupUi

    void retranslateUi(QWidget *FormGraph)
    {
        FormGraph->setWindowTitle(QApplication::translate("FormGraph", "Form", 0));
        allButton->setText(QApplication::translate("FormGraph", "\345\205\250\351\203\250", 0));
        label->setText(QApplication::translate("FormGraph", "\347\255\233\351\200\211\357\274\232\344\270\273\346\234\272\347\276\244\347\273\204", 0));
        label_2->setText(QApplication::translate("FormGraph", "\344\270\273\346\234\272", 0));
        label_3->setText(QApplication::translate("FormGraph", "\345\233\276\345\275\242", 0));
        warningTitle->setText(QApplication::translate("FormGraph", "\345\221\212\350\255\246\345\210\227\350\241\250", 0));
        graphTitle->setText(QApplication::translate("FormGraph", "\345\233\276\350\241\250", 0));
    } // retranslateUi

};

namespace Ui {
    class FormGraph: public Ui_FormGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGRAPH_H

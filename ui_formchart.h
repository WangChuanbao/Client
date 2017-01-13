/********************************************************************************
** Form generated from reading UI file 'formchart.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCHART_H
#define UI_FORMCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "formgraph.h"

QT_BEGIN_NAMESPACE

class Ui_FormChart
{
public:
    QVBoxLayout *verticalLayout;
    FormGraph *widget;

    void setupUi(QWidget *FormChart)
    {
        if (FormChart->objectName().isEmpty())
            FormChart->setObjectName(QStringLiteral("FormChart"));
        FormChart->resize(483, 347);
        verticalLayout = new QVBoxLayout(FormChart);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        widget = new FormGraph(FormChart);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);


        retranslateUi(FormChart);

        QMetaObject::connectSlotsByName(FormChart);
    } // setupUi

    void retranslateUi(QWidget *FormChart)
    {
        FormChart->setWindowTitle(QApplication::translate("FormChart", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class FormChart: public Ui_FormChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCHART_H

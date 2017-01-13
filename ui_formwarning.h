/********************************************************************************
** Form generated from reading UI file 'formwarning.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMWARNING_H
#define UI_FORMWARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "formgraph.h"

QT_BEGIN_NAMESPACE

class Ui_FormWarning
{
public:
    QVBoxLayout *verticalLayout;
    FormGraph *widget;

    void setupUi(QWidget *FormWarning)
    {
        if (FormWarning->objectName().isEmpty())
            FormWarning->setObjectName(QStringLiteral("FormWarning"));
        FormWarning->resize(800, 450);
        verticalLayout = new QVBoxLayout(FormWarning);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        widget = new FormGraph(FormWarning);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 255);"));

        verticalLayout->addWidget(widget);


        retranslateUi(FormWarning);

        QMetaObject::connectSlotsByName(FormWarning);
    } // setupUi

    void retranslateUi(QWidget *FormWarning)
    {
        FormWarning->setWindowTitle(QApplication::translate("FormWarning", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class FormWarning: public Ui_FormWarning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMWARNING_H

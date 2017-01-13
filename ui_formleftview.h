/********************************************************************************
** Form generated from reading UI file 'formleftview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMLEFTVIEW_H
#define UI_FORMLEFTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormLeftView
{
public:
    QWidget *widget;

    void setupUi(QWidget *FormLeftView)
    {
        if (FormLeftView->objectName().isEmpty())
            FormLeftView->setObjectName(QStringLiteral("FormLeftView"));
        FormLeftView->resize(837, 632);
        FormLeftView->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(FormLeftView);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 841, 631));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/topological.jpg);"));

        retranslateUi(FormLeftView);

        QMetaObject::connectSlotsByName(FormLeftView);
    } // setupUi

    void retranslateUi(QWidget *FormLeftView)
    {
        FormLeftView->setWindowTitle(QApplication::translate("FormLeftView", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class FormLeftView: public Ui_FormLeftView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMLEFTVIEW_H

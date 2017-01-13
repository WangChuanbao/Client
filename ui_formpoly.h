/********************************************************************************
** Form generated from reading UI file 'formpoly.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPOLY_H
#define UI_FORMPOLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPoly
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FormPoly)
    {
        if (FormPoly->objectName().isEmpty())
            FormPoly->setObjectName(QStringLiteral("FormPoly"));
        FormPoly->resize(641, 456);
        FormPoly->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(FormPoly);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(FormPoly);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(205, 205, 205);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 10, 5, 10);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);


        retranslateUi(FormPoly);

        QMetaObject::connectSlotsByName(FormPoly);
    } // setupUi

    void retranslateUi(QWidget *FormPoly)
    {
        FormPoly->setWindowTitle(QApplication::translate("FormPoly", "Form", 0));
        label->setText(QApplication::translate("FormPoly", "\347\255\233\351\200\211\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class FormPoly: public Ui_FormPoly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPOLY_H

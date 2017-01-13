/********************************************************************************
** Form generated from reading UI file 'formhome.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMHOME_H
#define UI_FORMHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "formgraph.h"
#include "formleftview.h"

QT_BEGIN_NAMESPACE

class Ui_FormHome
{
public:
    QHBoxLayout *horizontalLayout;
    FormLeftView *viewLeft;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *leftButton;
    QSpacerItem *verticalSpacer;
    QWidget *viewRight;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *rightButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    FormGraph *viewGraph;

    void setupUi(QWidget *FormHome)
    {
        if (FormHome->objectName().isEmpty())
            FormHome->setObjectName(QStringLiteral("FormHome"));
        FormHome->resize(1600, 900);
        horizontalLayout = new QHBoxLayout(FormHome);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        viewLeft = new FormLeftView(FormHome);
        viewLeft->setObjectName(QStringLiteral("viewLeft"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(viewLeft->sizePolicy().hasHeightForWidth());
        viewLeft->setSizePolicy(sizePolicy);
        viewLeft->setMinimumSize(QSize(0, 0));
        viewLeft->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(viewLeft);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        leftButton = new QPushButton(viewLeft);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftButton->sizePolicy().hasHeightForWidth());
        leftButton->setSizePolicy(sizePolicy1);
        leftButton->setMinimumSize(QSize(30, 30));
        leftButton->setMaximumSize(QSize(30, 30));
        leftButton->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/left.jpg"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QStringLiteral(":/middle.jpg"), QSize(), QIcon::Selected, QIcon::On);
        leftButton->setIcon(icon);
        leftButton->setIconSize(QSize(28, 28));

        horizontalLayout_3->addWidget(leftButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(viewLeft);

        viewRight = new QWidget(FormHome);
        viewRight->setObjectName(QStringLiteral("viewRight"));
        sizePolicy.setHeightForWidth(viewRight->sizePolicy().hasHeightForWidth());
        viewRight->setSizePolicy(sizePolicy);
        viewRight->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(viewRight);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        rightButton = new QPushButton(viewRight);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rightButton->sizePolicy().hasHeightForWidth());
        rightButton->setSizePolicy(sizePolicy2);
        rightButton->setMinimumSize(QSize(30, 30));
        rightButton->setMaximumSize(QSize(30, 30));
        rightButton->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/right.jpg"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QStringLiteral(":/middle.jpg"), QSize(), QIcon::Selected, QIcon::On);
        rightButton->setIcon(icon1);
        rightButton->setIconSize(QSize(28, 28));

        horizontalLayout_2->addWidget(rightButton);

        label = new QLabel(viewRight);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(7);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        viewGraph = new FormGraph(viewRight);
        viewGraph->setObjectName(QStringLiteral("viewGraph"));
        sizePolicy.setHeightForWidth(viewGraph->sizePolicy().hasHeightForWidth());
        viewGraph->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(viewGraph);


        horizontalLayout->addWidget(viewRight);


        retranslateUi(FormHome);

        QMetaObject::connectSlotsByName(FormHome);
    } // setupUi

    void retranslateUi(QWidget *FormHome)
    {
        FormHome->setWindowTitle(QApplication::translate("FormHome", "Form", 0));
        leftButton->setText(QString());
        rightButton->setText(QString());
        label->setText(QApplication::translate("FormHome", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class FormHome: public Ui_FormHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMHOME_H

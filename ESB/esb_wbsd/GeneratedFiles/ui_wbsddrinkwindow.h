/********************************************************************************
** Form generated from reading UI file 'wbsddrinkwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDDRINKWINDOW_H
#define UI_WBSDDRINKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDDrinkWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *button9;
    QPushButton *button10;
    QPushButton *button11;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *button3;
    QPushButton *button6;
    QPushButton *button2;
    QPushButton *button4;
    QPushButton *button1;
    QPushButton *button5;
    QPushButton *button7;
    QPushButton *button8;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WBSDDrinkWindow)
    {
        if (WBSDDrinkWindow->objectName().isEmpty())
            WBSDDrinkWindow->setObjectName(QStringLiteral("WBSDDrinkWindow"));
        WBSDDrinkWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDDrinkWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 651, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 20, 50, 40);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button9 = new QPushButton(verticalLayoutWidget);
        button9->setObjectName(QStringLiteral("button9"));
        button9->setEnabled(false);

        horizontalLayout->addWidget(button9);

        button10 = new QPushButton(verticalLayoutWidget);
        button10->setObjectName(QStringLiteral("button10"));
        button10->setEnabled(false);

        horizontalLayout->addWidget(button10);

        button11 = new QPushButton(verticalLayoutWidget);
        button11->setObjectName(QStringLiteral("button11"));
        button11->setEnabled(false);

        horizontalLayout->addWidget(button11);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setHorizontalSpacing(32);
        gridLayout_3->setVerticalSpacing(9);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        button3 = new QPushButton(verticalLayoutWidget);
        button3->setObjectName(QStringLiteral("button3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button3, 2, 2, 1, 1);

        button6 = new QPushButton(verticalLayoutWidget);
        button6->setObjectName(QStringLiteral("button6"));
        sizePolicy.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button6, 2, 3, 1, 1);

        button2 = new QPushButton(verticalLayoutWidget);
        button2->setObjectName(QStringLiteral("button2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button2, 1, 2, 1, 1);

        button4 = new QPushButton(verticalLayoutWidget);
        button4->setObjectName(QStringLiteral("button4"));
        sizePolicy.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button4, 0, 3, 1, 1);

        button1 = new QPushButton(verticalLayoutWidget);
        button1->setObjectName(QStringLiteral("button1"));
        sizePolicy1.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button1, 0, 2, 1, 1);

        button5 = new QPushButton(verticalLayoutWidget);
        button5->setObjectName(QStringLiteral("button5"));
        sizePolicy.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button5, 1, 3, 1, 1);

        button7 = new QPushButton(verticalLayoutWidget);
        button7->setObjectName(QStringLiteral("button7"));
        sizePolicy1.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button7, 0, 1, 1, 1);

        button8 = new QPushButton(verticalLayoutWidget);
        button8->setObjectName(QStringLiteral("button8"));
        sizePolicy1.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button8, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 4, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 4);
        WBSDDrinkWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WBSDDrinkWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDDrinkWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(WBSDDrinkWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDDrinkWindow->setMenuBar(menubar);
        QWidget::setTabOrder(button1, button2);
        QWidget::setTabOrder(button2, button3);
        QWidget::setTabOrder(button3, button4);
        QWidget::setTabOrder(button4, button5);
        QWidget::setTabOrder(button5, button6);
        QWidget::setTabOrder(button6, button7);
        QWidget::setTabOrder(button7, button8);
        QWidget::setTabOrder(button8, button9);
        QWidget::setTabOrder(button9, button10);
        QWidget::setTabOrder(button10, button11);

        retranslateUi(WBSDDrinkWindow);

        QMetaObject::connectSlotsByName(WBSDDrinkWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDDrinkWindow)
    {
        WBSDDrinkWindow->setWindowTitle(QApplication::translate("WBSDDrinkWindow", "Drink settings", 0));
        button9->setText(QString());
        button10->setText(QString());
        button11->setText(QString());
        button3->setText(QApplication::translate("WBSDDrinkWindow", "Button 3", 0));
        button6->setText(QApplication::translate("WBSDDrinkWindow", "Button 6", 0));
        button2->setText(QApplication::translate("WBSDDrinkWindow", "Button 2", 0));
        button4->setText(QApplication::translate("WBSDDrinkWindow", "Button 4", 0));
        button1->setText(QApplication::translate("WBSDDrinkWindow", "Button 1", 0));
        button5->setText(QApplication::translate("WBSDDrinkWindow", "Button 5", 0));
        button7->setText(QApplication::translate("WBSDDrinkWindow", "Button 7", 0));
        button8->setText(QApplication::translate("WBSDDrinkWindow", "Button 8", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDDrinkWindow: public Ui_WBSDDrinkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDDRINKWINDOW_H

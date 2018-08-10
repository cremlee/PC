/********************************************************************************
** Form generated from reading UI file 'wbsdboilerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDBOILERWINDOW_H
#define UI_WBSDBOILERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDBoilerWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menuBAck;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDBoilerWindow)
    {
        if (WBSDBoilerWindow->objectName().isEmpty())
            WBSDBoilerWindow->setObjectName(QStringLiteral("WBSDBoilerWindow"));
        WBSDBoilerWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDBoilerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 761, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(50, 0, 50, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 8, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 7, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 9, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 3, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 4, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 5, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 6, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 8, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 9, 1, 1, 1);

        WBSDBoilerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDBoilerWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuBAck = new QMenu(menubar);
        menuBAck->setObjectName(QStringLiteral("menuBAck"));
        WBSDBoilerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDBoilerWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDBoilerWindow->setStatusBar(statusbar);

        menubar->addAction(menuBAck->menuAction());

        retranslateUi(WBSDBoilerWindow);

        QMetaObject::connectSlotsByName(WBSDBoilerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDBoilerWindow)
    {
        WBSDBoilerWindow->setWindowTitle(QApplication::translate("WBSDBoilerWindow", "Boiler", 0));
        label_2->setText(QApplication::translate("WBSDBoilerWindow", "100 \302\260C", 0));
        label_10->setText(QApplication::translate("WBSDBoilerWindow", "Counter water throughput", 0));
        label->setText(QApplication::translate("WBSDBoilerWindow", "Boiler temperature", 0));
        label_7->setText(QApplication::translate("WBSDBoilerWindow", "Over-boiler sensor", 0));
        label_5->setText(QApplication::translate("WBSDBoilerWindow", "Normal boiler level", 0));
        label_6->setText(QApplication::translate("WBSDBoilerWindow", "Dry-boiler sensor", 0));
        label_3->setText(QApplication::translate("WBSDBoilerWindow", "Heating", 0));
        label_8->setText(QApplication::translate("WBSDBoilerWindow", "Connection loop", 0));
        label_4->setText(QApplication::translate("WBSDBoilerWindow", "Heating", 0));
        label_9->setText(QApplication::translate("WBSDBoilerWindow", "Inlet valve", 0));
        label_11->setText(QApplication::translate("WBSDBoilerWindow", "Counter water throughput reset", 0));
        label_12->setText(QApplication::translate("WBSDBoilerWindow", "Off", 0));
        pushButton->setText(QApplication::translate("WBSDBoilerWindow", "Activate", 0));
        label_13->setText(QApplication::translate("WBSDBoilerWindow", "No water", 0));
        label_14->setText(QApplication::translate("WBSDBoilerWindow", "OK", 0));
        label_15->setText(QApplication::translate("WBSDBoilerWindow", "OK", 0));
        label_16->setText(QApplication::translate("WBSDBoilerWindow", "In place", 0));
        label_17->setText(QApplication::translate("WBSDBoilerWindow", "6163 ml", 0));
        pushButton_2->setText(QApplication::translate("WBSDBoilerWindow", "Activate", 0));
        pushButton_3->setText(QApplication::translate("WBSDBoilerWindow", "Reset", 0));
        menuBAck->setTitle(QApplication::translate("WBSDBoilerWindow", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDBoilerWindow: public Ui_WBSDBoilerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDBOILERWINDOW_H

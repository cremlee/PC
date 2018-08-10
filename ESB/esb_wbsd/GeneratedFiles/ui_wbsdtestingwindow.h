/********************************************************************************
** Form generated from reading UI file 'wbsdtestingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDTESTINGWINDOW_H
#define UI_WBSDTESTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDTestingWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *outletButton;
    QPushButton *pumpButton;
    QPushButton *heaterButton;
    QPushButton *instantButton;
    QPushButton *doserButton;
    QPushButton *displayButton;
    QPushButton *paymentButton;
    QPushButton *versionsButton;
    QPushButton *btn_ext_tst;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDTestingWindow)
    {
        if (WBSDTestingWindow->objectName().isEmpty())
            WBSDTestingWindow->setObjectName(QStringLiteral("WBSDTestingWindow"));
        WBSDTestingWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDTestingWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 761, 275));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 0, 50, 0);
        outletButton = new QPushButton(verticalLayoutWidget);
        outletButton->setObjectName(QStringLiteral("outletButton"));

        verticalLayout->addWidget(outletButton);

        pumpButton = new QPushButton(verticalLayoutWidget);
        pumpButton->setObjectName(QStringLiteral("pumpButton"));

        verticalLayout->addWidget(pumpButton);

        heaterButton = new QPushButton(verticalLayoutWidget);
        heaterButton->setObjectName(QStringLiteral("heaterButton"));

        verticalLayout->addWidget(heaterButton);

        instantButton = new QPushButton(verticalLayoutWidget);
        instantButton->setObjectName(QStringLiteral("instantButton"));

        verticalLayout->addWidget(instantButton);

        doserButton = new QPushButton(verticalLayoutWidget);
        doserButton->setObjectName(QStringLiteral("doserButton"));

        verticalLayout->addWidget(doserButton);

        displayButton = new QPushButton(verticalLayoutWidget);
        displayButton->setObjectName(QStringLiteral("displayButton"));

        verticalLayout->addWidget(displayButton);

        paymentButton = new QPushButton(verticalLayoutWidget);
        paymentButton->setObjectName(QStringLiteral("paymentButton"));
        paymentButton->setEnabled(false);

        verticalLayout->addWidget(paymentButton);

        versionsButton = new QPushButton(verticalLayoutWidget);
        versionsButton->setObjectName(QStringLiteral("versionsButton"));

        verticalLayout->addWidget(versionsButton);

        btn_ext_tst = new QPushButton(verticalLayoutWidget);
        btn_ext_tst->setObjectName(QStringLiteral("btn_ext_tst"));

        verticalLayout->addWidget(btn_ext_tst);

        WBSDTestingWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDTestingWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDTestingWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDTestingWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDTestingWindow->setStatusBar(statusbar);

        retranslateUi(WBSDTestingWindow);

        QMetaObject::connectSlotsByName(WBSDTestingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDTestingWindow)
    {
        WBSDTestingWindow->setWindowTitle(QApplication::translate("WBSDTestingWindow", "Testing", 0));
        outletButton->setText(QApplication::translate("WBSDTestingWindow", "Valve tests", 0));
        pumpButton->setText(QApplication::translate("WBSDTestingWindow", "Pump tests", 0));
        heaterButton->setText(QApplication::translate("WBSDTestingWindow", "Heater and cooling tests", 0));
        instantButton->setText(QApplication::translate("WBSDTestingWindow", "Instant option tests", 0));
        doserButton->setText(QApplication::translate("WBSDTestingWindow", "B2 doser system", 0));
        displayButton->setText(QApplication::translate("WBSDTestingWindow", "Display options", 0));
        paymentButton->setText(QApplication::translate("WBSDTestingWindow", "Payment", 0));
        versionsButton->setText(QApplication::translate("WBSDTestingWindow", "Versions overview", 0));
        btn_ext_tst->setText(QApplication::translate("WBSDTestingWindow", "External module test", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDTestingWindow: public Ui_WBSDTestingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDTESTINGWINDOW_H

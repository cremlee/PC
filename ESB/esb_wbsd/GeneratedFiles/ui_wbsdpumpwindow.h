/********************************************************************************
** Form generated from reading UI file 'wbsdpumpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDPUMPWINDOW_H
#define UI_WBSDPUMPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDPumpWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *waterPump;
    QLabel *label_3;
    QPushButton *lbibPump;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *rbibLabel;
    QPushButton *rbibPump;
    QPushButton *btn_setpump;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDPumpWindow)
    {
        if (WBSDPumpWindow->objectName().isEmpty())
            WBSDPumpWindow->setObjectName(QStringLiteral("WBSDPumpWindow"));
        WBSDPumpWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDPumpWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 761, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 20, 50, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        waterPump = new QPushButton(verticalLayoutWidget);
        waterPump->setObjectName(QStringLiteral("waterPump"));

        gridLayout->addWidget(waterPump, 0, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lbibPump = new QPushButton(verticalLayoutWidget);
        lbibPump->setObjectName(QStringLiteral("lbibPump"));

        gridLayout->addWidget(lbibPump, 1, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        rbibLabel = new QLabel(verticalLayoutWidget);
        rbibLabel->setObjectName(QStringLiteral("rbibLabel"));
        rbibLabel->setEnabled(false);

        gridLayout_2->addWidget(rbibLabel, 0, 0, 1, 1);

        rbibPump = new QPushButton(verticalLayoutWidget);
        rbibPump->setObjectName(QStringLiteral("rbibPump"));
        rbibPump->setEnabled(false);

        gridLayout_2->addWidget(rbibPump, 0, 1, 1, 1);

        btn_setpump = new QPushButton(verticalLayoutWidget);
        btn_setpump->setObjectName(QStringLiteral("btn_setpump"));

        gridLayout_2->addWidget(btn_setpump, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        WBSDPumpWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDPumpWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDPumpWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDPumpWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDPumpWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(waterPump, lbibPump);

        retranslateUi(WBSDPumpWindow);

        QMetaObject::connectSlotsByName(WBSDPumpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDPumpWindow)
    {
        WBSDPumpWindow->setWindowTitle(QApplication::translate("WBSDPumpWindow", "Pump tests", 0));
        waterPump->setText(QApplication::translate("WBSDPumpWindow", "Activate", 0));
        label_3->setText(QApplication::translate("WBSDPumpWindow", "Air pump", 0));
        lbibPump->setText(QApplication::translate("WBSDPumpWindow", "Activate", 0));
        label->setText(QApplication::translate("WBSDPumpWindow", "Water pump", 0));
        rbibLabel->setText(QApplication::translate("WBSDPumpWindow", "RBIB air pump", 0));
        rbibPump->setText(QApplication::translate("WBSDPumpWindow", "Activate", 0));
        btn_setpump->setText(QApplication::translate("WBSDPumpWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDPumpWindow: public Ui_WBSDPumpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDPUMPWINDOW_H

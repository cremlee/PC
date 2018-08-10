/********************************************************************************
** Form generated from reading UI file 'wbsdheaterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDHEATERWINDOW_H
#define UI_WBSDHEATERWINDOW_H

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

class Ui_WBSDHeaterWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *heaterRelay;
    QLabel *label;
    QLabel *label_2;
    QPushButton *cooler;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *lb_rfsetpoint;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *lblBoilerTempMid;
    QLabel *label_7;
    QLabel *lblCoolboxTemp;
    QLabel *lblBoilerTempTop;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDHeaterWindow)
    {
        if (WBSDHeaterWindow->objectName().isEmpty())
            WBSDHeaterWindow->setObjectName(QStringLiteral("WBSDHeaterWindow"));
        WBSDHeaterWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDHeaterWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 40, 741, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 20, 50, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, -1, -1, -1);
        heaterRelay = new QPushButton(verticalLayoutWidget);
        heaterRelay->setObjectName(QStringLiteral("heaterRelay"));

        gridLayout->addWidget(heaterRelay, 0, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        cooler = new QPushButton(verticalLayoutWidget);
        cooler->setObjectName(QStringLiteral("cooler"));

        gridLayout->addWidget(cooler, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(20);
        gridLayout_2->setContentsMargins(10, -1, -1, -1);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        lb_rfsetpoint = new QLabel(verticalLayoutWidget);
        lb_rfsetpoint->setObjectName(QStringLiteral("lb_rfsetpoint"));

        gridLayout_2->addWidget(lb_rfsetpoint, 3, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lblBoilerTempMid = new QLabel(verticalLayoutWidget);
        lblBoilerTempMid->setObjectName(QStringLiteral("lblBoilerTempMid"));

        gridLayout_2->addWidget(lblBoilerTempMid, 1, 1, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        lblCoolboxTemp = new QLabel(verticalLayoutWidget);
        lblCoolboxTemp->setObjectName(QStringLiteral("lblCoolboxTemp"));

        gridLayout_2->addWidget(lblCoolboxTemp, 2, 1, 1, 1);

        lblBoilerTempTop = new QLabel(verticalLayoutWidget);
        lblBoilerTempTop->setObjectName(QStringLiteral("lblBoilerTempTop"));

        gridLayout_2->addWidget(lblBoilerTempTop, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        WBSDHeaterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDHeaterWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDHeaterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDHeaterWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDHeaterWindow->setStatusBar(statusbar);

        retranslateUi(WBSDHeaterWindow);

        QMetaObject::connectSlotsByName(WBSDHeaterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDHeaterWindow)
    {
        WBSDHeaterWindow->setWindowTitle(QApplication::translate("WBSDHeaterWindow", "Heater and cooling tests", 0));
        heaterRelay->setText(QApplication::translate("WBSDHeaterWindow", "Activate", 0));
        label->setText(QApplication::translate("WBSDHeaterWindow", "Heater relay", 0));
        label_2->setText(QApplication::translate("WBSDHeaterWindow", "Cooler   (measure with multi-meter)\n"
"Approximately 2 AMPERES of current driving", 0));
        cooler->setText(QApplication::translate("WBSDHeaterWindow", "Activate", 0));
        label_4->setText(QApplication::translate("WBSDHeaterWindow", "refrigerator set point ", 0));
        lb_rfsetpoint->setText(QApplication::translate("WBSDHeaterWindow", "-", 0));
        label_3->setText(QApplication::translate("WBSDHeaterWindow", "Boiler temperature (TOP)", 0));
        label_5->setText(QApplication::translate("WBSDHeaterWindow", "Boiler temperature (MID)", 0));
        lblBoilerTempMid->setText(QApplication::translate("WBSDHeaterWindow", "-", 0));
        label_7->setText(QApplication::translate("WBSDHeaterWindow", "Coolbox temperature", 0));
        lblCoolboxTemp->setText(QApplication::translate("WBSDHeaterWindow", "-", 0));
        lblBoilerTempTop->setText(QApplication::translate("WBSDHeaterWindow", "-", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDHeaterWindow: public Ui_WBSDHeaterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDHEATERWINDOW_H

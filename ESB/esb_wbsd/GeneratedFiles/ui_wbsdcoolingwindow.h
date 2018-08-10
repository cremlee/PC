/********************************************************************************
** Form generated from reading UI file 'wbsdcoolingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDCOOLINGWINDOW_H
#define UI_WBSDCOOLINGWINDOW_H

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDCoolingWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *coolingTemp;
    QLabel *label_5;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WBSDCoolingWindow)
    {
        if (WBSDCoolingWindow->objectName().isEmpty())
            WBSDCoolingWindow->setObjectName(QStringLiteral("WBSDCoolingWindow"));
        WBSDCoolingWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDCoolingWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(19, 10, 761, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(50, 0, 50, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        coolingTemp = new QLabel(gridLayoutWidget);
        coolingTemp->setObjectName(QStringLiteral("coolingTemp"));

        gridLayout->addWidget(coolingTemp, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoFillBackground(false);

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        WBSDCoolingWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WBSDCoolingWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDCoolingWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(WBSDCoolingWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDCoolingWindow->setMenuBar(menubar);

        retranslateUi(WBSDCoolingWindow);

        QMetaObject::connectSlotsByName(WBSDCoolingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDCoolingWindow)
    {
        WBSDCoolingWindow->setWindowTitle(QApplication::translate("WBSDCoolingWindow", "Cooling", 0));
        label->setText(QApplication::translate("WBSDCoolingWindow", "Cooling temperature", 0));
        label_2->setText(QApplication::translate("WBSDCoolingWindow", "Compressor", 0));
        label_3->setText(QApplication::translate("WBSDCoolingWindow", "Compressor", 0));
        coolingTemp->setText(QApplication::translate("WBSDCoolingWindow", "-", 0));
        label_5->setText(QApplication::translate("WBSDCoolingWindow", "On", 0));
        pushButton->setText(QApplication::translate("WBSDCoolingWindow", "Deactivate", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDCoolingWindow: public Ui_WBSDCoolingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDCOOLINGWINDOW_H

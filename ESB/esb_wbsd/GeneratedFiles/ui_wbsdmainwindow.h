/********************************************************************************
** Form generated from reading UI file 'wbsdmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDMAINWINDOW_H
#define UI_WBSDMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDMainWindow
{
public:
    QWidget *centralwidget;
    QFrame *connStatusInd;
    QFrame *connStatus;
    QLabel *connStatusInfo;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WBSDMainWindow)
    {
        if (WBSDMainWindow->objectName().isEmpty())
            WBSDMainWindow->setObjectName(QStringLiteral("WBSDMainWindow"));
        WBSDMainWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        connStatusInd = new QFrame(centralwidget);
        connStatusInd->setObjectName(QStringLiteral("connStatusInd"));
        connStatusInd->setEnabled(true);
        connStatusInd->setGeometry(QRect(50, 110, 703, 310));
        connStatusInd->setFrameShape(QFrame::StyledPanel);
        connStatusInd->setFrameShadow(QFrame::Sunken);
        connStatus = new QFrame(centralwidget);
        connStatus->setObjectName(QStringLiteral("connStatus"));
        connStatus->setGeometry(QRect(50, 470, 16, 20));
        connStatus->setStyleSheet(QLatin1String("background:rgb(170, 0, 0)\n"
""));
        connStatus->setFrameShape(QFrame::StyledPanel);
        connStatus->setFrameShadow(QFrame::Raised);
        connStatusInfo = new QLabel(centralwidget);
        connStatusInfo->setObjectName(QStringLiteral("connStatusInfo"));
        connStatusInfo->setGeometry(QRect(70, 470, 101, 21));
        WBSDMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WBSDMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDMainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(WBSDMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDMainWindow->setMenuBar(menubar);

        retranslateUi(WBSDMainWindow);

        QMetaObject::connectSlotsByName(WBSDMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDMainWindow)
    {
        WBSDMainWindow->setWindowTitle(QApplication::translate("WBSDMainWindow", "Compact WBSD v0.91", 0));
        connStatusInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WBSDMainWindow: public Ui_WBSDMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDMAINWINDOW_H

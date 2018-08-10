/********************************************************************************
** Form generated from reading UI file 'wbsdversionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDVERSIONWINDOW_H
#define UI_WBSDVERSIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDVersionWindow
{
public:
    QWidget *centralwidget;
    QListWidget *metaWindow;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDVersionWindow)
    {
        if (WBSDVersionWindow->objectName().isEmpty())
            WBSDVersionWindow->setObjectName(QStringLiteral("WBSDVersionWindow"));
        WBSDVersionWindow->resize(495, 585);
        centralwidget = new QWidget(WBSDVersionWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        metaWindow = new QListWidget(centralwidget);
        metaWindow->setObjectName(QStringLiteral("metaWindow"));
        metaWindow->setGeometry(QRect(20, 10, 461, 531));
        WBSDVersionWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDVersionWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 495, 21));
        WBSDVersionWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDVersionWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDVersionWindow->setStatusBar(statusbar);

        retranslateUi(WBSDVersionWindow);

        QMetaObject::connectSlotsByName(WBSDVersionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDVersionWindow)
    {
        WBSDVersionWindow->setWindowTitle(QApplication::translate("WBSDVersionWindow", "Versions overview", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDVersionWindow: public Ui_WBSDVersionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDVERSIONWINDOW_H

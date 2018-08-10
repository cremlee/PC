/********************************************************************************
** Form generated from reading UI file 'wbsderrorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDERRORWINDOW_H
#define UI_WBSDERRORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDErrorWindow
{
public:
    QAction *actionSave_Complete_Error_Log;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelActiveErr;
    QListWidget *listActiveErr;
    QHBoxLayout *horizontalLayout;
    QLabel *labelHistoryErr;
    QPushButton *loadErrorButton;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBar;
    QPushButton *btnSaveErrors;
    QListWidget *listHistoryErr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDErrorWindow)
    {
        if (WBSDErrorWindow->objectName().isEmpty())
            WBSDErrorWindow->setObjectName(QStringLiteral("WBSDErrorWindow"));
        WBSDErrorWindow->resize(800, 600);
        actionSave_Complete_Error_Log = new QAction(WBSDErrorWindow);
        actionSave_Complete_Error_Log->setObjectName(QStringLiteral("actionSave_Complete_Error_Log"));
        centralwidget = new QWidget(WBSDErrorWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 801, 531));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 0, 50, 0);
        labelActiveErr = new QLabel(verticalLayoutWidget);
        labelActiveErr->setObjectName(QStringLiteral("labelActiveErr"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        labelActiveErr->setFont(font);
        labelActiveErr->setMargin(2);
        labelActiveErr->setIndent(4);

        verticalLayout->addWidget(labelActiveErr);

        listActiveErr = new QListWidget(verticalLayoutWidget);
        listActiveErr->setObjectName(QStringLiteral("listActiveErr"));

        verticalLayout->addWidget(listActiveErr);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelHistoryErr = new QLabel(verticalLayoutWidget);
        labelHistoryErr->setObjectName(QStringLiteral("labelHistoryErr"));
        labelHistoryErr->setFont(font);
        labelHistoryErr->setMargin(2);
        labelHistoryErr->setIndent(4);

        horizontalLayout->addWidget(labelHistoryErr);

        loadErrorButton = new QPushButton(verticalLayoutWidget);
        loadErrorButton->setObjectName(QStringLiteral("loadErrorButton"));

        horizontalLayout->addWidget(loadErrorButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        btnSaveErrors = new QPushButton(verticalLayoutWidget);
        btnSaveErrors->setObjectName(QStringLiteral("btnSaveErrors"));

        horizontalLayout->addWidget(btnSaveErrors);


        verticalLayout->addLayout(horizontalLayout);

        listHistoryErr = new QListWidget(verticalLayoutWidget);
        listHistoryErr->setObjectName(QStringLiteral("listHistoryErr"));

        verticalLayout->addWidget(listHistoryErr);

        WBSDErrorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDErrorWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDErrorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDErrorWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDErrorWindow->setStatusBar(statusbar);

        retranslateUi(WBSDErrorWindow);

        QMetaObject::connectSlotsByName(WBSDErrorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDErrorWindow)
    {
        WBSDErrorWindow->setWindowTitle(QApplication::translate("WBSDErrorWindow", "Errors", 0));
        actionSave_Complete_Error_Log->setText(QApplication::translate("WBSDErrorWindow", "Save Complete Error Log", 0));
        labelActiveErr->setText(QApplication::translate("WBSDErrorWindow", "Active Errors", 0));
        labelHistoryErr->setText(QApplication::translate("WBSDErrorWindow", "Error History", 0));
        loadErrorButton->setText(QApplication::translate("WBSDErrorWindow", "Load All Error History", 0));
        btnSaveErrors->setText(QApplication::translate("WBSDErrorWindow", "Save to file", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDErrorWindow: public Ui_WBSDErrorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDERRORWINDOW_H

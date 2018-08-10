/********************************************************************************
** Form generated from reading UI file 'wbsd_paytest.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSD_PAYTEST_H
#define UI_WBSD_PAYTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDpaytest
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_test;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDpaytest)
    {
        if (WBSDpaytest->objectName().isEmpty())
            WBSDpaytest->setObjectName(QStringLiteral("WBSDpaytest"));
        WBSDpaytest->resize(800, 600);
        centralwidget = new QWidget(WBSDpaytest);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 30, 561, 223));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, 50, 50, 50);
        plainTextEdit = new QPlainTextEdit(horizontalLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btn_test = new QPushButton(horizontalLayoutWidget);
        btn_test->setObjectName(QStringLiteral("btn_test"));

        verticalLayout_2->addWidget(btn_test);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        WBSDpaytest->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDpaytest);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDpaytest->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDpaytest);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDpaytest->setStatusBar(statusbar);

        retranslateUi(WBSDpaytest);

        QMetaObject::connectSlotsByName(WBSDpaytest);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDpaytest)
    {
        WBSDpaytest->setWindowTitle(QApplication::translate("WBSDpaytest", "MainWindow", 0));
        btn_test->setText(QApplication::translate("WBSDpaytest", "Test", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDpaytest: public Ui_WBSDpaytest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSD_PAYTEST_H

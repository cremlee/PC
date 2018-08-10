/********************************************************************************
** Form generated from reading UI file 'wbsd_update.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSD_UPDATE_H
#define UI_WBSD_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wbsd_update
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QProgressBar *pb_update;
    QHBoxLayout *horizontalLayout;
    QComboBox *cb_type;
    QTextEdit *textEdit;
    QPushButton *btn_select;
    QPushButton *btn_update;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wbsd_update)
    {
        if (wbsd_update->objectName().isEmpty())
            wbsd_update->setObjectName(QStringLiteral("wbsd_update"));
        wbsd_update->resize(521, 402);
        centralwidget = new QWidget(wbsd_update);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 19, 451, 300));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        pb_update = new QProgressBar(verticalLayoutWidget);
        pb_update->setObjectName(QStringLiteral("pb_update"));
        pb_update->setValue(0);

        verticalLayout->addWidget(pb_update);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cb_type = new QComboBox(verticalLayoutWidget);
        cb_type->setObjectName(QStringLiteral("cb_type"));

        horizontalLayout->addWidget(cb_type);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(textEdit);

        btn_select = new QPushButton(verticalLayoutWidget);
        btn_select->setObjectName(QStringLiteral("btn_select"));

        horizontalLayout->addWidget(btn_select);


        verticalLayout->addLayout(horizontalLayout);

        btn_update = new QPushButton(verticalLayoutWidget);
        btn_update->setObjectName(QStringLiteral("btn_update"));
        btn_update->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_update->sizePolicy().hasHeightForWidth());
        btn_update->setSizePolicy(sizePolicy1);
        btn_update->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(btn_update);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(2, 1);
        wbsd_update->setCentralWidget(centralwidget);
        verticalLayoutWidget->raise();
        plainTextEdit->raise();
        menubar = new QMenuBar(wbsd_update);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 521, 21));
        wbsd_update->setMenuBar(menubar);
        statusbar = new QStatusBar(wbsd_update);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        wbsd_update->setStatusBar(statusbar);

        retranslateUi(wbsd_update);

        QMetaObject::connectSlotsByName(wbsd_update);
    } // setupUi

    void retranslateUi(QMainWindow *wbsd_update)
    {
        wbsd_update->setWindowTitle(QApplication::translate("wbsd_update", "MainWindow", 0));
        cb_type->clear();
        cb_type->insertItems(0, QStringList()
         << QApplication::translate("wbsd_update", "UIB ", 0)
         << QApplication::translate("wbsd_update", "MCB", 0)
        );
        btn_select->setText(QApplication::translate("wbsd_update", "Select image file", 0));
        btn_update->setText(QApplication::translate("wbsd_update", "Update", 0));
    } // retranslateUi

};

namespace Ui {
    class wbsd_update: public Ui_wbsd_update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSD_UPDATE_H

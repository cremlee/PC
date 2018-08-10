/********************************************************************************
** Form generated from reading UI file 'wbsd_extern_tool.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSD_EXTERN_TOOL_H
#define UI_WBSD_EXTERN_TOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSD_EXTERN_TOOL
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_fmu_tst;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSD_EXTERN_TOOL)
    {
        if (WBSD_EXTERN_TOOL->objectName().isEmpty())
            WBSD_EXTERN_TOOL->setObjectName(QStringLiteral("WBSD_EXTERN_TOOL"));
        WBSD_EXTERN_TOOL->resize(800, 600);
        centralwidget = new QWidget(WBSD_EXTERN_TOOL);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(29, 19, 751, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 20, 50, 0);
        btn_fmu_tst = new QPushButton(verticalLayoutWidget);
        btn_fmu_tst->setObjectName(QStringLiteral("btn_fmu_tst"));
        QFont font;
        font.setPointSize(12);
        btn_fmu_tst->setFont(font);

        verticalLayout->addWidget(btn_fmu_tst);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        WBSD_EXTERN_TOOL->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSD_EXTERN_TOOL);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSD_EXTERN_TOOL->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSD_EXTERN_TOOL);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSD_EXTERN_TOOL->setStatusBar(statusbar);

        retranslateUi(WBSD_EXTERN_TOOL);

        QMetaObject::connectSlotsByName(WBSD_EXTERN_TOOL);
    } // setupUi

    void retranslateUi(QMainWindow *WBSD_EXTERN_TOOL)
    {
        WBSD_EXTERN_TOOL->setWindowTitle(QApplication::translate("WBSD_EXTERN_TOOL", "MainWindow", 0));
        btn_fmu_tst->setText(QApplication::translate("WBSD_EXTERN_TOOL", "MMP Test", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSD_EXTERN_TOOL: public Ui_WBSD_EXTERN_TOOL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSD_EXTERN_TOOL_H

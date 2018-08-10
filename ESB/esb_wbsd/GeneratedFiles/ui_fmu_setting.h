/********************************************************************************
** Form generated from reading UI file 'fmu_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMU_SETTING_H
#define UI_FMU_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
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

class Ui_FMU_SETTING
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn_param;
    QPushButton *btn_test;
    QPushButton *btn_cal;
    QPushButton *btn_error;
    QPushButton *btn_up;
    QPushButton *btn_clone;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cb_element_switch;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lbl_descale;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *cb_hardness;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QPushButton *pbtn_rest;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FMU_SETTING)
    {
        if (FMU_SETTING->objectName().isEmpty())
            FMU_SETTING->setObjectName(QStringLiteral("FMU_SETTING"));
        FMU_SETTING->resize(800, 600);
        centralwidget = new QWidget(FMU_SETTING);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(29, 19, 741, 511));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(30, 0, 30, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(50, -1, 50, -1);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        btn_param = new QPushButton(verticalLayoutWidget);
        btn_param->setObjectName(QStringLiteral("btn_param"));

        verticalLayout_2->addWidget(btn_param);

        btn_test = new QPushButton(verticalLayoutWidget);
        btn_test->setObjectName(QStringLiteral("btn_test"));

        verticalLayout_2->addWidget(btn_test);

        btn_cal = new QPushButton(verticalLayoutWidget);
        btn_cal->setObjectName(QStringLiteral("btn_cal"));

        verticalLayout_2->addWidget(btn_cal);

        btn_error = new QPushButton(verticalLayoutWidget);
        btn_error->setObjectName(QStringLiteral("btn_error"));

        verticalLayout_2->addWidget(btn_error);

        btn_up = new QPushButton(verticalLayoutWidget);
        btn_up->setObjectName(QStringLiteral("btn_up"));

        verticalLayout_2->addWidget(btn_up);

        btn_clone = new QPushButton(verticalLayoutWidget);
        btn_clone->setObjectName(QStringLiteral("btn_clone"));

        verticalLayout_2->addWidget(btn_clone);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        cb_element_switch = new QComboBox(verticalLayoutWidget);
        cb_element_switch->setObjectName(QStringLiteral("cb_element_switch"));

        horizontalLayout->addWidget(cb_element_switch);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lbl_descale = new QLabel(verticalLayoutWidget);
        lbl_descale->setObjectName(QStringLiteral("lbl_descale"));

        horizontalLayout_2->addWidget(lbl_descale);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        cb_hardness = new QComboBox(verticalLayoutWidget);
        cb_hardness->setObjectName(QStringLiteral("cb_hardness"));

        horizontalLayout_3->addWidget(cb_hardness);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        pbtn_rest = new QPushButton(verticalLayoutWidget);
        pbtn_rest->setObjectName(QStringLiteral("pbtn_rest"));

        horizontalLayout_4->addWidget(pbtn_rest);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addLayout(verticalLayout_2);

        FMU_SETTING->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FMU_SETTING);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        FMU_SETTING->setMenuBar(menubar);
        statusbar = new QStatusBar(FMU_SETTING);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FMU_SETTING->setStatusBar(statusbar);

        retranslateUi(FMU_SETTING);

        QMetaObject::connectSlotsByName(FMU_SETTING);
    } // setupUi

    void retranslateUi(QMainWindow *FMU_SETTING)
    {
        FMU_SETTING->setWindowTitle(QApplication::translate("FMU_SETTING", "MainWindow", 0));
        btn_param->setText(QApplication::translate("FMU_SETTING", "Parameter Setting", 0));
        btn_test->setText(QApplication::translate("FMU_SETTING", "Test Function", 0));
        btn_cal->setText(QApplication::translate("FMU_SETTING", "Calibration", 0));
        btn_error->setText(QApplication::translate("FMU_SETTING", "Error", 0));
        btn_up->setText(QApplication::translate("FMU_SETTING", "Update", 0));
        btn_clone->setText(QApplication::translate("FMU_SETTING", "Clone", 0));
        label->setText(QApplication::translate("FMU_SETTING", "Dispenser heating element when MMP dispensing", 0));
        label_2->setText(QApplication::translate("FMU_SETTING", "Descaling function", 0));
        lbl_descale->setText(QApplication::translate("FMU_SETTING", "-", 0));
        label_4->setText(QApplication::translate("FMU_SETTING", "Water hardness", 0));
        label_5->setText(QApplication::translate("FMU_SETTING", "Reset MMP descale counters", 0));
        pbtn_rest->setText(QApplication::translate("FMU_SETTING", "reset", 0));
    } // retranslateUi

};

namespace Ui {
    class FMU_SETTING: public Ui_FMU_SETTING {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMU_SETTING_H

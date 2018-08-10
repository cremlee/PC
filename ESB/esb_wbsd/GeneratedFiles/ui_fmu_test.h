/********************************************************************************
** Form generated from reading UI file 'fmu_test.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMU_TEST_H
#define UI_FMU_TEST_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fmu_test
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btn_inlet;
    QPushButton *btn_milk;
    QPushButton *btn_clean;
    QPushButton *btn_air;
    QPushButton *btn_flush;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_5;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLabel *label_4;
    QLabel *lbl_ntc_mix;
    QLabel *lbl_sor_conductive;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_9;
    QLabel *lbl_sor_milk;
    QLabel *lbl_fth_efast;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_8;
    QPushButton *btn_pump;
    QPushButton *btn_flowmeter;
    QSpacerItem *verticalSpacer_9;
    QWidget *tab_4;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QPushButton *btn_fan_box;
    QPushButton *btn_fan_condensor;
    QSpacerItem *verticalSpacer_4;
    QLabel *lbl_tst_info;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *fmu_test)
    {
        if (fmu_test->objectName().isEmpty())
            fmu_test->setObjectName(QStringLiteral("fmu_test"));
        fmu_test->resize(800, 600);
        centralwidget = new QWidget(fmu_test);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 29, 771, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(16);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayoutWidget_2 = new QWidget(tab);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(9, 9, 751, 471));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(50, 0, 50, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        btn_inlet = new QPushButton(verticalLayoutWidget_2);
        btn_inlet->setObjectName(QStringLiteral("btn_inlet"));

        verticalLayout_2->addWidget(btn_inlet);

        btn_milk = new QPushButton(verticalLayoutWidget_2);
        btn_milk->setObjectName(QStringLiteral("btn_milk"));

        verticalLayout_2->addWidget(btn_milk);

        btn_clean = new QPushButton(verticalLayoutWidget_2);
        btn_clean->setObjectName(QStringLiteral("btn_clean"));

        verticalLayout_2->addWidget(btn_clean);

        btn_air = new QPushButton(verticalLayoutWidget_2);
        btn_air->setObjectName(QStringLiteral("btn_air"));

        verticalLayout_2->addWidget(btn_air);

        btn_flush = new QPushButton(verticalLayoutWidget_2);
        btn_flush->setObjectName(QStringLiteral("btn_flush"));

        verticalLayout_2->addWidget(btn_flush);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayoutWidget = new QWidget(tab_5);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 751, 471));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        lbl_ntc_mix = new QLabel(gridLayoutWidget);
        lbl_ntc_mix->setObjectName(QStringLiteral("lbl_ntc_mix"));

        gridLayout->addWidget(lbl_ntc_mix, 1, 2, 1, 1);

        lbl_sor_conductive = new QLabel(gridLayoutWidget);
        lbl_sor_conductive->setObjectName(QStringLiteral("lbl_sor_conductive"));

        gridLayout->addWidget(lbl_sor_conductive, 2, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 1, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_10, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 4, 1, 1, 1);

        lbl_sor_milk = new QLabel(gridLayoutWidget);
        lbl_sor_milk->setObjectName(QStringLiteral("lbl_sor_milk"));

        gridLayout->addWidget(lbl_sor_milk, 3, 2, 1, 1);

        lbl_fth_efast = new QLabel(gridLayoutWidget);
        lbl_fth_efast->setObjectName(QStringLiteral("lbl_fth_efast"));

        gridLayout->addWidget(lbl_fth_efast, 4, 2, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayoutWidget_3 = new QWidget(tab_2);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(9, 9, 751, 461));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(50, 0, 50, 0);
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_8);

        btn_pump = new QPushButton(verticalLayoutWidget_3);
        btn_pump->setObjectName(QStringLiteral("btn_pump"));

        verticalLayout_3->addWidget(btn_pump);

        btn_flowmeter = new QPushButton(verticalLayoutWidget_3);
        btn_flowmeter->setObjectName(QStringLiteral("btn_flowmeter"));

        verticalLayout_3->addWidget(btn_flowmeter);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_9);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayoutWidget_4 = new QWidget(tab_4);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(19, 19, 731, 451));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(50, 0, 50, 0);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        btn_fan_box = new QPushButton(verticalLayoutWidget_4);
        btn_fan_box->setObjectName(QStringLiteral("btn_fan_box"));

        verticalLayout_4->addWidget(btn_fan_box);

        btn_fan_condensor = new QPushButton(verticalLayoutWidget_4);
        btn_fan_condensor->setObjectName(QStringLiteral("btn_fan_condensor"));

        verticalLayout_4->addWidget(btn_fan_condensor);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        lbl_tst_info = new QLabel(verticalLayoutWidget);
        lbl_tst_info->setObjectName(QStringLiteral("lbl_tst_info"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_tst_info->setFont(font1);
        lbl_tst_info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_tst_info);

        fmu_test->setCentralWidget(centralwidget);
        menubar = new QMenuBar(fmu_test);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        fmu_test->setMenuBar(menubar);
        statusbar = new QStatusBar(fmu_test);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        fmu_test->setStatusBar(statusbar);

        retranslateUi(fmu_test);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(fmu_test);
    } // setupUi

    void retranslateUi(QMainWindow *fmu_test)
    {
        fmu_test->setWindowTitle(QApplication::translate("fmu_test", "MainWindow", 0));
        btn_inlet->setText(QApplication::translate("fmu_test", "Inlet valve", 0));
        btn_milk->setText(QApplication::translate("fmu_test", "Milk valve", 0));
        btn_clean->setText(QApplication::translate("fmu_test", "Clean valve", 0));
        btn_air->setText(QApplication::translate("fmu_test", "Air valve", 0));
        btn_flush->setText(QApplication::translate("fmu_test", "Flush valve", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("fmu_test", "Valve test", 0));
        label->setText(QApplication::translate("fmu_test", "NTC mixing block", 0));
        label_4->setText(QApplication::translate("fmu_test", "Conductivity sensor", 0));
        lbl_ntc_mix->setText(QApplication::translate("fmu_test", "-", 0));
        lbl_sor_conductive->setText(QApplication::translate("fmu_test", "-", 0));
        label_7->setText(QApplication::translate("fmu_test", "Milk container empty detection", 0));
        label_9->setText(QApplication::translate("fmu_test", "FTH: E-fast", 0));
        lbl_sor_milk->setText(QApplication::translate("fmu_test", "-", 0));
        lbl_fth_efast->setText(QApplication::translate("fmu_test", "-", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("fmu_test", "Sensor status", 0));
        btn_pump->setText(QApplication::translate("fmu_test", "Pump", 0));
        btn_flowmeter->setText(QApplication::translate("fmu_test", "Flowmeter", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("fmu_test", "Pump test", 0));
        btn_fan_box->setText(QApplication::translate("fmu_test", "Fan box", 0));
        btn_fan_condensor->setText(QApplication::translate("fmu_test", "Condensor", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("fmu_test", "Fan test", 0));
        lbl_tst_info->setText(QApplication::translate("fmu_test", "-", 0));
    } // retranslateUi

};

namespace Ui {
    class fmu_test: public Ui_fmu_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMU_TEST_H

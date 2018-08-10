/********************************************************************************
** Form generated from reading UI file 'fmu_calibration.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMU_CALIBRATION_H
#define UI_FMU_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FMU_Calibration
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_pump;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_6;
    QGridLayout *gridLayout;
    QProgressBar *pb_3;
    QPushButton *btn_cal_50;
    QLabel *label_2;
    QProgressBar *pb_1;
    QPushButton *btn_cal_spd_2;
    QPushButton *btn_cal_100;
    QLabel *label_5;
    QPushButton *btn_cal_spd_3;
    QDoubleSpinBox *sp_cal_spd_4;
    QProgressBar *pb_2;
    QPushButton *btn_cal_spd_1;
    QLabel *label_4;
    QPushButton *btn_cal_80;
    QPushButton *btn_cal_30;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_cal_spd_4;
    QProgressBar *pb_4;
    QDoubleSpinBox *sp_cal_spd_1;
    QDoubleSpinBox *sp_cal_spd_2;
    QDoubleSpinBox *sp_cal_spd_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FMU_Calibration)
    {
        if (FMU_Calibration->objectName().isEmpty())
            FMU_Calibration->setObjectName(QStringLiteral("FMU_Calibration"));
        FMU_Calibration->resize(800, 600);
        centralwidget = new QWidget(FMU_Calibration);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(29, 19, 731, 511));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_pump = new QWidget();
        tab_pump->setObjectName(QStringLiteral("tab_pump"));
        verticalLayoutWidget_2 = new QWidget(tab_pump);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(9, 19, 701, 431));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pb_3 = new QProgressBar(verticalLayoutWidget_2);
        pb_3->setObjectName(QStringLiteral("pb_3"));
        pb_3->setMaximum(10);
        pb_3->setValue(0);

        gridLayout->addWidget(pb_3, 2, 2, 1, 1);

        btn_cal_50 = new QPushButton(verticalLayoutWidget_2);
        btn_cal_50->setObjectName(QStringLiteral("btn_cal_50"));

        gridLayout->addWidget(btn_cal_50, 1, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        pb_1 = new QProgressBar(verticalLayoutWidget_2);
        pb_1->setObjectName(QStringLiteral("pb_1"));
        pb_1->setMaximum(10);
        pb_1->setValue(0);

        gridLayout->addWidget(pb_1, 0, 2, 1, 1);

        btn_cal_spd_2 = new QPushButton(verticalLayoutWidget_2);
        btn_cal_spd_2->setObjectName(QStringLiteral("btn_cal_spd_2"));

        gridLayout->addWidget(btn_cal_spd_2, 1, 4, 1, 1);

        btn_cal_100 = new QPushButton(verticalLayoutWidget_2);
        btn_cal_100->setObjectName(QStringLiteral("btn_cal_100"));

        gridLayout->addWidget(btn_cal_100, 3, 1, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        btn_cal_spd_3 = new QPushButton(verticalLayoutWidget_2);
        btn_cal_spd_3->setObjectName(QStringLiteral("btn_cal_spd_3"));

        gridLayout->addWidget(btn_cal_spd_3, 2, 4, 1, 1);

        sp_cal_spd_4 = new QDoubleSpinBox(verticalLayoutWidget_2);
        sp_cal_spd_4->setObjectName(QStringLiteral("sp_cal_spd_4"));
        sp_cal_spd_4->setDecimals(0);
        sp_cal_spd_4->setMaximum(150);
        sp_cal_spd_4->setValue(103);

        gridLayout->addWidget(sp_cal_spd_4, 3, 3, 1, 1);

        pb_2 = new QProgressBar(verticalLayoutWidget_2);
        pb_2->setObjectName(QStringLiteral("pb_2"));
        pb_2->setMaximum(10);
        pb_2->setValue(0);

        gridLayout->addWidget(pb_2, 1, 2, 1, 1);

        btn_cal_spd_1 = new QPushButton(verticalLayoutWidget_2);
        btn_cal_spd_1->setObjectName(QStringLiteral("btn_cal_spd_1"));

        gridLayout->addWidget(btn_cal_spd_1, 0, 4, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        btn_cal_80 = new QPushButton(verticalLayoutWidget_2);
        btn_cal_80->setObjectName(QStringLiteral("btn_cal_80"));

        gridLayout->addWidget(btn_cal_80, 2, 1, 1, 1);

        btn_cal_30 = new QPushButton(verticalLayoutWidget_2);
        btn_cal_30->setObjectName(QStringLiteral("btn_cal_30"));

        gridLayout->addWidget(btn_cal_30, 0, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        btn_cal_spd_4 = new QPushButton(verticalLayoutWidget_2);
        btn_cal_spd_4->setObjectName(QStringLiteral("btn_cal_spd_4"));

        gridLayout->addWidget(btn_cal_spd_4, 3, 4, 1, 1);

        pb_4 = new QProgressBar(verticalLayoutWidget_2);
        pb_4->setObjectName(QStringLiteral("pb_4"));
        pb_4->setMaximum(10);
        pb_4->setValue(0);

        gridLayout->addWidget(pb_4, 3, 2, 1, 1);

        sp_cal_spd_1 = new QDoubleSpinBox(verticalLayoutWidget_2);
        sp_cal_spd_1->setObjectName(QStringLiteral("sp_cal_spd_1"));
        sp_cal_spd_1->setDecimals(0);
        sp_cal_spd_1->setMaximum(200);
        sp_cal_spd_1->setValue(35);

        gridLayout->addWidget(sp_cal_spd_1, 0, 3, 1, 1);

        sp_cal_spd_2 = new QDoubleSpinBox(verticalLayoutWidget_2);
        sp_cal_spd_2->setObjectName(QStringLiteral("sp_cal_spd_2"));
        sp_cal_spd_2->setDecimals(0);
        sp_cal_spd_2->setMaximum(200);
        sp_cal_spd_2->setValue(62);

        gridLayout->addWidget(sp_cal_spd_2, 1, 3, 1, 1);

        sp_cal_spd_3 = new QDoubleSpinBox(verticalLayoutWidget_2);
        sp_cal_spd_3->setObjectName(QStringLiteral("sp_cal_spd_3"));
        sp_cal_spd_3->setDecimals(0);
        sp_cal_spd_3->setMaximum(200);
        sp_cal_spd_3->setValue(87);

        gridLayout->addWidget(sp_cal_spd_3, 2, 3, 1, 1);

        gridLayout->setColumnStretch(0, 2);

        verticalLayout_2->addLayout(gridLayout);

        verticalLayout_2->setStretch(0, 1);
        tabWidget->addTab(tab_pump, QString());

        verticalLayout->addWidget(tabWidget);

        FMU_Calibration->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FMU_Calibration);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        FMU_Calibration->setMenuBar(menubar);
        statusbar = new QStatusBar(FMU_Calibration);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FMU_Calibration->setStatusBar(statusbar);

        retranslateUi(FMU_Calibration);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FMU_Calibration);
    } // setupUi

    void retranslateUi(QMainWindow *FMU_Calibration)
    {
        FMU_Calibration->setWindowTitle(QApplication::translate("FMU_Calibration", "MainWindow", 0));
        label->setText(QApplication::translate("FMU_Calibration", "Please do all three calibration", 0));
        label_6->setText(QApplication::translate("FMU_Calibration", "Warning: The machine will dispense during calibration.\n"
"  Press Calibrate, measure dispensed milk, fill out volume in ml, press set", 0));
        btn_cal_50->setText(QApplication::translate("FMU_Calibration", "cailbration", 0));
        label_2->setText(QApplication::translate("FMU_Calibration", "pump calibration speed 80%", 0));
        btn_cal_spd_2->setText(QApplication::translate("FMU_Calibration", "Set", 0));
        btn_cal_100->setText(QApplication::translate("FMU_Calibration", "cailbration", 0));
        label_5->setText(QApplication::translate("FMU_Calibration", "pump calibration speed 100%", 0));
        btn_cal_spd_3->setText(QApplication::translate("FMU_Calibration", "Set", 0));
        btn_cal_spd_1->setText(QApplication::translate("FMU_Calibration", "Set", 0));
        label_4->setText(QApplication::translate("FMU_Calibration", "pump calibration speed 30%", 0));
        btn_cal_80->setText(QApplication::translate("FMU_Calibration", "cailbration", 0));
        btn_cal_30->setText(QApplication::translate("FMU_Calibration", "cailbration", 0));
        label_3->setText(QApplication::translate("FMU_Calibration", "pump calibration speed 50%", 0));
        btn_cal_spd_4->setText(QApplication::translate("FMU_Calibration", "Set", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_pump), QApplication::translate("FMU_Calibration", "Pump Calibration", 0));
    } // retranslateUi

};

namespace Ui {
    class FMU_Calibration: public Ui_FMU_Calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMU_CALIBRATION_H

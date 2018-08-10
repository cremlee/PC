/********************************************************************************
** Form generated from reading UI file 'wbsdgeneralwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDGENERALWINDOW_H
#define UI_WBSDGENERALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDGeneralWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *rightBIB;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_19;
    QComboBox *instantCoffee;
    QLabel *label_18;
    QComboBox *leftBIB;
    QLabel *label_17;
    QComboBox *cb_fmuswitch;
    QPushButton *btn_instant;
    QLabel *label_11;
    QPushButton *btn_fmu;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *deairTimer;
    QSpinBox *sp_test;
    QLabel *label_9;
    QComboBox *instantFan;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *phoneOper;
    QLineEdit *phoneServ;
    QLabel *label_7;
    QComboBox *paymentOpt;
    QLabel *label_6;
    QLabel *label_8;
    QComboBox *switchOver;
    QLabel *label_3;
    QComboBox *comboBox_5;
    QLabel *label_20;
    QComboBox *cbenablepay;
    QLabel *label_21;
    QComboBox *cb_payDispenMode;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *operatorAccess;
    QPushButton *languages;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDGeneralWindow)
    {
        if (WBSDGeneralWindow->objectName().isEmpty())
            WBSDGeneralWindow->setObjectName(QStringLiteral("WBSDGeneralWindow"));
        WBSDGeneralWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDGeneralWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 20, 761, 491));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        rightBIB = new QComboBox(verticalLayoutWidget_2);
        rightBIB->setObjectName(QStringLiteral("rightBIB"));

        gridLayout->addWidget(rightBIB, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 6, 1, 1);

        label_19 = new QLabel(verticalLayoutWidget_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_19, 0, 5, 1, 1);

        instantCoffee = new QComboBox(verticalLayoutWidget_2);
        instantCoffee->setObjectName(QStringLiteral("instantCoffee"));

        gridLayout->addWidget(instantCoffee, 1, 5, 1, 1);

        label_18 = new QLabel(verticalLayoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setLayoutDirection(Qt::LeftToRight);
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_18, 0, 3, 1, 1);

        leftBIB = new QComboBox(verticalLayoutWidget_2);
        leftBIB->setObjectName(QStringLiteral("leftBIB"));

        gridLayout->addWidget(leftBIB, 1, 1, 1, 1);

        label_17 = new QLabel(verticalLayoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_17, 0, 1, 1, 1);

        cb_fmuswitch = new QComboBox(verticalLayoutWidget_2);
        cb_fmuswitch->setObjectName(QStringLiteral("cb_fmuswitch"));

        gridLayout->addWidget(cb_fmuswitch, 1, 8, 1, 1);

        btn_instant = new QPushButton(verticalLayoutWidget_2);
        btn_instant->setObjectName(QStringLiteral("btn_instant"));

        gridLayout->addWidget(btn_instant, 2, 5, 1, 1);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 0, 8, 1, 1);

        btn_fmu = new QPushButton(verticalLayoutWidget_2);
        btn_fmu->setObjectName(QStringLiteral("btn_fmu"));

        gridLayout->addWidget(btn_fmu, 2, 8, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 8, 0, 1, 1);

        deairTimer = new QComboBox(verticalLayoutWidget_2);
        deairTimer->setObjectName(QStringLiteral("deairTimer"));
        deairTimer->setEnabled(true);

        gridLayout_2->addWidget(deairTimer, 9, 1, 1, 1);

        sp_test = new QSpinBox(verticalLayoutWidget_2);
        sp_test->setObjectName(QStringLiteral("sp_test"));
        sp_test->setMaximum(65535);
        sp_test->setSingleStep(50);

        gridLayout_2->addWidget(sp_test, 10, 1, 1, 1);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 10, 0, 1, 1);

        instantFan = new QComboBox(verticalLayoutWidget_2);
        instantFan->setObjectName(QStringLiteral("instantFan"));
        instantFan->setEnabled(true);

        gridLayout_2->addWidget(instantFan, 8, 1, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 9, 0, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        phoneOper = new QLineEdit(verticalLayoutWidget_2);
        phoneOper->setObjectName(QStringLiteral("phoneOper"));
        sizePolicy.setHeightForWidth(phoneOper->sizePolicy().hasHeightForWidth());
        phoneOper->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(phoneOper, 3, 1, 1, 1);

        phoneServ = new QLineEdit(verticalLayoutWidget_2);
        phoneServ->setObjectName(QStringLiteral("phoneServ"));
        sizePolicy.setHeightForWidth(phoneServ->sizePolicy().hasHeightForWidth());
        phoneServ->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(phoneServ, 4, 1, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(false);

        gridLayout_2->addWidget(label_7, 6, 0, 1, 1);

        paymentOpt = new QComboBox(verticalLayoutWidget_2);
        paymentOpt->setObjectName(QStringLiteral("paymentOpt"));
        paymentOpt->setEnabled(false);

        gridLayout_2->addWidget(paymentOpt, 5, 1, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(false);

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(true);

        gridLayout_2->addWidget(label_8, 7, 0, 1, 1);

        switchOver = new QComboBox(verticalLayoutWidget_2);
        switchOver->setObjectName(QStringLiteral("switchOver"));
        switchOver->setEnabled(true);

        gridLayout_2->addWidget(switchOver, 7, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        comboBox_5 = new QComboBox(verticalLayoutWidget_2);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setEnabled(false);

        gridLayout_2->addWidget(comboBox_5, 6, 1, 1, 1);

        label_20 = new QLabel(verticalLayoutWidget_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_20, 1, 0, 1, 1);

        cbenablepay = new QComboBox(verticalLayoutWidget_2);
        cbenablepay->setObjectName(QStringLiteral("cbenablepay"));

        gridLayout_2->addWidget(cbenablepay, 1, 1, 1, 1);

        label_21 = new QLabel(verticalLayoutWidget_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_21, 2, 0, 1, 1);

        cb_payDispenMode = new QComboBox(verticalLayoutWidget_2);
        cb_payDispenMode->setObjectName(QStringLiteral("cb_payDispenMode"));

        gridLayout_2->addWidget(cb_payDispenMode, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        operatorAccess = new QPushButton(verticalLayoutWidget_2);
        operatorAccess->setObjectName(QStringLiteral("operatorAccess"));
        operatorAccess->setEnabled(false);

        verticalLayout->addWidget(operatorAccess);

        languages = new QPushButton(verticalLayoutWidget_2);
        languages->setObjectName(QStringLiteral("languages"));
        languages->setEnabled(false);

        verticalLayout->addWidget(languages);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 4);
        verticalLayout_2->setStretch(4, 1);
        verticalLayout_2->setStretch(5, 1);
        WBSDGeneralWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDGeneralWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDGeneralWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDGeneralWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDGeneralWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(leftBIB, rightBIB);
        QWidget::setTabOrder(rightBIB, instantCoffee);
        QWidget::setTabOrder(instantCoffee, operatorAccess);
        QWidget::setTabOrder(operatorAccess, languages);
        QWidget::setTabOrder(languages, phoneOper);
        QWidget::setTabOrder(phoneOper, phoneServ);
        QWidget::setTabOrder(phoneServ, paymentOpt);
        QWidget::setTabOrder(paymentOpt, comboBox_5);
        QWidget::setTabOrder(comboBox_5, switchOver);

        retranslateUi(WBSDGeneralWindow);

        QMetaObject::connectSlotsByName(WBSDGeneralWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDGeneralWindow)
    {
        WBSDGeneralWindow->setWindowTitle(QApplication::translate("WBSDGeneralWindow", "General settings", 0));
        label->setText(QApplication::translate("WBSDGeneralWindow", "Dispenser configuration", 0));
        label_19->setText(QApplication::translate("WBSDGeneralWindow", "Compartment", 0));
        label_18->setText(QApplication::translate("WBSDGeneralWindow", "Right BIB", 0));
        label_17->setText(QApplication::translate("WBSDGeneralWindow", "Left BIB", 0));
        btn_instant->setText(QApplication::translate("WBSDGeneralWindow", "Instant calibration and testing", 0));
        label_11->setText(QApplication::translate("WBSDGeneralWindow", "MMP Part", 0));
        btn_fmu->setText(QApplication::translate("WBSDGeneralWindow", "MMP Setting", 0));
        label_2->setText(QApplication::translate("WBSDGeneralWindow", "Instant fan timer", 0));
        label_9->setText(QApplication::translate("WBSDGeneralWindow", "DB_AIR_TIME MCB DP 2", 0));
        label_5->setText(QApplication::translate("WBSDGeneralWindow", "Deair timer", 0));
        label_4->setText(QApplication::translate("WBSDGeneralWindow", "Service telephone number", 0));
#ifndef QT_NO_TOOLTIP
        phoneOper->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        phoneOper->setText(QString());
        phoneServ->setText(QString());
        label_7->setText(QApplication::translate("WBSDGeneralWindow", "Cold water value", 0));
        label_6->setText(QApplication::translate("WBSDGeneralWindow", "Payment", 0));
        label_8->setText(QApplication::translate("WBSDGeneralWindow", "Switch over function", 0));
        label_3->setText(QApplication::translate("WBSDGeneralWindow", "Operator telephone number", 0));
        label_20->setText(QApplication::translate("WBSDGeneralWindow", "extern payment system", 0));
        label_21->setText(QApplication::translate("WBSDGeneralWindow", "Dispense mode for payment", 0));
        operatorAccess->setText(QApplication::translate("WBSDGeneralWindow", "Operator access", 0));
        languages->setText(QApplication::translate("WBSDGeneralWindow", "Language", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDGeneralWindow: public Ui_WBSDGeneralWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDGENERALWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'wbsdpaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDPAYWINDOW_H
#define UI_WBSDPAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDPayWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QFrame *line_2;
    QLabel *lblRFIDTimeOut;
    QComboBox *cboClearCreditTime;
    QFrame *line;
    QLabel *lblPayEnabled;
    QLabel *lblRFIDMode;
    QLabel *lblCurrency;
    QComboBox *cboSaleType;
    QLabel *lblSaletype;
    QLabel *lblClearCreditTime;
    QComboBox *cboCurrency;
    QComboBox *cboRFIDMode;
    QComboBox *cboRFIDTimeout;
    QComboBox *cboPaymentEnabled;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *button9;
    QPushButton *button10;
    QPushButton *button11;
    QGridLayout *gridLayout_3;
    QPushButton *button6;
    QPushButton *button3;
    QPushButton *button2;
    QPushButton *button4;
    QPushButton *button1;
    QPushButton *button5;
    QPushButton *button7;
    QPushButton *button8;
    QFrame *line_4;
    QGridLayout *gridLayout_4;
    QPushButton *btnCoinChanelF;
    QPushButton *btnCoinChanelA;
    QPushButton *btnCoinChanelE;
    QPushButton *btnCoinChanelB;
    QPushButton *btnCoinChanelD;
    QPushButton *btnCoinChanelC;
    QFrame *line_3;
    QGridLayout *gridLayout_cashbox;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_2;
    QLabel *label_9;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QLabel *label_10;
    QLabel *lbl_flag_full_2;
    QLabel *lbl_flag_warn_2;
    QLabel *lbl_flag_counters;
    QPushButton *btn_setwarn_2;
    QLabel *label;
    QLabel *label_2;
    QFrame *line_6;
    QGridLayout *gridLayout_2;
    QPushButton *btnReset;
    QLabel *lblMoneyInCashBox;
    QLabel *lblFreeVendTokens;
    QLabel *lblTotalCollected;
    QLabel *lblTotalTurnOver;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WBSDPayWindow)
    {
        if (WBSDPayWindow->objectName().isEmpty())
            WBSDPayWindow->setObjectName(QStringLiteral("WBSDPayWindow"));
        WBSDPayWindow->resize(1119, 635);
        centralwidget = new QWidget(WBSDPayWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 10, 1091, 585));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 10, 50, 10);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 1, 1, 1);

        lblRFIDTimeOut = new QLabel(verticalLayoutWidget);
        lblRFIDTimeOut->setObjectName(QStringLiteral("lblRFIDTimeOut"));

        gridLayout->addWidget(lblRFIDTimeOut, 2, 0, 1, 1);

        cboClearCreditTime = new QComboBox(verticalLayoutWidget);
        cboClearCreditTime->setObjectName(QStringLiteral("cboClearCreditTime"));

        gridLayout->addWidget(cboClearCreditTime, 5, 1, 1, 1);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 1);

        lblPayEnabled = new QLabel(verticalLayoutWidget);
        lblPayEnabled->setObjectName(QStringLiteral("lblPayEnabled"));

        gridLayout->addWidget(lblPayEnabled, 4, 0, 1, 1);

        lblRFIDMode = new QLabel(verticalLayoutWidget);
        lblRFIDMode->setObjectName(QStringLiteral("lblRFIDMode"));

        gridLayout->addWidget(lblRFIDMode, 1, 0, 1, 1);

        lblCurrency = new QLabel(verticalLayoutWidget);
        lblCurrency->setObjectName(QStringLiteral("lblCurrency"));

        gridLayout->addWidget(lblCurrency, 7, 0, 1, 1);

        cboSaleType = new QComboBox(verticalLayoutWidget);
        cboSaleType->setObjectName(QStringLiteral("cboSaleType"));

        gridLayout->addWidget(cboSaleType, 6, 1, 1, 1);

        lblSaletype = new QLabel(verticalLayoutWidget);
        lblSaletype->setObjectName(QStringLiteral("lblSaletype"));

        gridLayout->addWidget(lblSaletype, 6, 0, 1, 1);

        lblClearCreditTime = new QLabel(verticalLayoutWidget);
        lblClearCreditTime->setObjectName(QStringLiteral("lblClearCreditTime"));

        gridLayout->addWidget(lblClearCreditTime, 5, 0, 1, 1);

        cboCurrency = new QComboBox(verticalLayoutWidget);
        cboCurrency->setObjectName(QStringLiteral("cboCurrency"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(cboCurrency->sizePolicy().hasHeightForWidth());
        cboCurrency->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cboCurrency, 7, 1, 1, 1);

        cboRFIDMode = new QComboBox(verticalLayoutWidget);
        cboRFIDMode->setObjectName(QStringLiteral("cboRFIDMode"));

        gridLayout->addWidget(cboRFIDMode, 1, 1, 1, 1);

        cboRFIDTimeout = new QComboBox(verticalLayoutWidget);
        cboRFIDTimeout->setObjectName(QStringLiteral("cboRFIDTimeout"));

        gridLayout->addWidget(cboRFIDTimeout, 2, 1, 1, 1);

        cboPaymentEnabled = new QComboBox(verticalLayoutWidget);
        cboPaymentEnabled->setObjectName(QStringLiteral("cboPaymentEnabled"));

        gridLayout->addWidget(cboPaymentEnabled, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line_5 = new QFrame(verticalLayoutWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(40);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, 50, -1);
        button9 = new QPushButton(verticalLayoutWidget);
        button9->setObjectName(QStringLiteral("button9"));
        button9->setEnabled(false);

        horizontalLayout->addWidget(button9);

        button10 = new QPushButton(verticalLayoutWidget);
        button10->setObjectName(QStringLiteral("button10"));
        button10->setEnabled(false);

        horizontalLayout->addWidget(button10);

        button11 = new QPushButton(verticalLayoutWidget);
        button11->setObjectName(QStringLiteral("button11"));
        button11->setEnabled(false);

        horizontalLayout->addWidget(button11);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setHorizontalSpacing(50);
        gridLayout_3->setVerticalSpacing(9);
        gridLayout_3->setContentsMargins(50, -1, 50, -1);
        button6 = new QPushButton(verticalLayoutWidget);
        button6->setObjectName(QStringLiteral("button6"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button6, 2, 2, 1, 1);

        button3 = new QPushButton(verticalLayoutWidget);
        button3->setObjectName(QStringLiteral("button3"));
        sizePolicy1.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button3, 2, 1, 1, 1);

        button2 = new QPushButton(verticalLayoutWidget);
        button2->setObjectName(QStringLiteral("button2"));
        sizePolicy1.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button2, 1, 1, 1, 1);

        button4 = new QPushButton(verticalLayoutWidget);
        button4->setObjectName(QStringLiteral("button4"));
        sizePolicy1.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button4, 0, 2, 1, 1);

        button1 = new QPushButton(verticalLayoutWidget);
        button1->setObjectName(QStringLiteral("button1"));
        sizePolicy1.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button1, 0, 1, 1, 1);

        button5 = new QPushButton(verticalLayoutWidget);
        button5->setObjectName(QStringLiteral("button5"));
        sizePolicy1.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button5, 1, 2, 1, 1);

        button7 = new QPushButton(verticalLayoutWidget);
        button7->setObjectName(QStringLiteral("button7"));
        button7->setEnabled(true);
        sizePolicy1.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button7, 0, 0, 1, 1);

        button8 = new QPushButton(verticalLayoutWidget);
        button8->setObjectName(QStringLiteral("button8"));
        sizePolicy1.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(button8, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        line_4 = new QFrame(verticalLayoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_4->setHorizontalSpacing(32);
        gridLayout_4->setVerticalSpacing(9);
        gridLayout_4->setContentsMargins(10, -1, 10, -1);
        btnCoinChanelF = new QPushButton(verticalLayoutWidget);
        btnCoinChanelF->setObjectName(QStringLiteral("btnCoinChanelF"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnCoinChanelF->sizePolicy().hasHeightForWidth());
        btnCoinChanelF->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(btnCoinChanelF, 0, 5, 1, 1);

        btnCoinChanelA = new QPushButton(verticalLayoutWidget);
        btnCoinChanelA->setObjectName(QStringLiteral("btnCoinChanelA"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnCoinChanelA->sizePolicy().hasHeightForWidth());
        btnCoinChanelA->setSizePolicy(sizePolicy3);
        btnCoinChanelA->setMinimumSize(QSize(60, 55));

        gridLayout_4->addWidget(btnCoinChanelA, 0, 0, 1, 1);

        btnCoinChanelE = new QPushButton(verticalLayoutWidget);
        btnCoinChanelE->setObjectName(QStringLiteral("btnCoinChanelE"));
        sizePolicy2.setHeightForWidth(btnCoinChanelE->sizePolicy().hasHeightForWidth());
        btnCoinChanelE->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(btnCoinChanelE, 0, 4, 1, 1);

        btnCoinChanelB = new QPushButton(verticalLayoutWidget);
        btnCoinChanelB->setObjectName(QStringLiteral("btnCoinChanelB"));
        sizePolicy2.setHeightForWidth(btnCoinChanelB->sizePolicy().hasHeightForWidth());
        btnCoinChanelB->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(btnCoinChanelB, 0, 1, 1, 1);

        btnCoinChanelD = new QPushButton(verticalLayoutWidget);
        btnCoinChanelD->setObjectName(QStringLiteral("btnCoinChanelD"));
        sizePolicy2.setHeightForWidth(btnCoinChanelD->sizePolicy().hasHeightForWidth());
        btnCoinChanelD->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(btnCoinChanelD, 0, 3, 1, 1);

        btnCoinChanelC = new QPushButton(verticalLayoutWidget);
        btnCoinChanelC->setObjectName(QStringLiteral("btnCoinChanelC"));
        sizePolicy2.setHeightForWidth(btnCoinChanelC->sizePolicy().hasHeightForWidth());
        btnCoinChanelC->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(btnCoinChanelC, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        line_3 = new QFrame(verticalLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        gridLayout_cashbox = new QGridLayout();
        gridLayout_cashbox->setObjectName(QStringLiteral("gridLayout_cashbox"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_cashbox->addWidget(label_6, 6, 0, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_cashbox->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_cashbox->addWidget(label_8, 1, 0, 1, 1);

        horizontalSlider_4 = new QSlider(verticalLayoutWidget);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(horizontalSlider_4->sizePolicy().hasHeightForWidth());
        horizontalSlider_4->setSizePolicy(sizePolicy4);
        horizontalSlider_4->setMaximum(300);
        horizontalSlider_4->setSingleStep(5);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_4->setTickPosition(QSlider::TicksBelow);

        gridLayout_cashbox->addWidget(horizontalSlider_4, 1, 1, 1, 1);

        horizontalSlider_2 = new QSlider(verticalLayoutWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy5);
        horizontalSlider_2->setMaximum(300);
        horizontalSlider_2->setSingleStep(5);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);

        gridLayout_cashbox->addWidget(horizontalSlider_2, 0, 1, 1, 1);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_cashbox->addWidget(label_9, 5, 0, 1, 1);

        spinBox_3 = new QSpinBox(verticalLayoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(300);

        gridLayout_cashbox->addWidget(spinBox_3, 0, 2, 1, 1);

        spinBox_4 = new QSpinBox(verticalLayoutWidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMaximum(300);

        gridLayout_cashbox->addWidget(spinBox_4, 1, 2, 1, 1);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_cashbox->addWidget(label_10, 7, 0, 1, 1);

        lbl_flag_full_2 = new QLabel(verticalLayoutWidget);
        lbl_flag_full_2->setObjectName(QStringLiteral("lbl_flag_full_2"));
        lbl_flag_full_2->setAlignment(Qt::AlignCenter);

        gridLayout_cashbox->addWidget(lbl_flag_full_2, 6, 1, 1, 1);

        lbl_flag_warn_2 = new QLabel(verticalLayoutWidget);
        lbl_flag_warn_2->setObjectName(QStringLiteral("lbl_flag_warn_2"));
        lbl_flag_warn_2->setAlignment(Qt::AlignCenter);

        gridLayout_cashbox->addWidget(lbl_flag_warn_2, 7, 1, 1, 1);

        lbl_flag_counters = new QLabel(verticalLayoutWidget);
        lbl_flag_counters->setObjectName(QStringLiteral("lbl_flag_counters"));
        lbl_flag_counters->setAlignment(Qt::AlignCenter);

        gridLayout_cashbox->addWidget(lbl_flag_counters, 5, 1, 1, 1);

        btn_setwarn_2 = new QPushButton(verticalLayoutWidget);
        btn_setwarn_2->setObjectName(QStringLiteral("btn_setwarn_2"));

        gridLayout_cashbox->addWidget(btn_setwarn_2, 2, 3, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_cashbox->addWidget(label, 0, 3, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_cashbox->addWidget(label_2, 1, 3, 1, 1);

        gridLayout_cashbox->setColumnStretch(0, 1);
        gridLayout_cashbox->setColumnStretch(1, 3);
        gridLayout_cashbox->setColumnStretch(2, 1);
        gridLayout_cashbox->setColumnStretch(3, 1);

        verticalLayout->addLayout(gridLayout_cashbox);

        line_6 = new QFrame(verticalLayoutWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnReset = new QPushButton(verticalLayoutWidget);
        btnReset->setObjectName(QStringLiteral("btnReset"));

        gridLayout_2->addWidget(btnReset, 0, 6, 1, 1);

        lblMoneyInCashBox = new QLabel(verticalLayoutWidget);
        lblMoneyInCashBox->setObjectName(QStringLiteral("lblMoneyInCashBox"));

        gridLayout_2->addWidget(lblMoneyInCashBox, 0, 4, 1, 1);

        lblFreeVendTokens = new QLabel(verticalLayoutWidget);
        lblFreeVendTokens->setObjectName(QStringLiteral("lblFreeVendTokens"));

        gridLayout_2->addWidget(lblFreeVendTokens, 0, 2, 1, 1);

        lblTotalCollected = new QLabel(verticalLayoutWidget);
        lblTotalCollected->setObjectName(QStringLiteral("lblTotalCollected"));

        gridLayout_2->addWidget(lblTotalCollected, 0, 1, 1, 1);

        lblTotalTurnOver = new QLabel(verticalLayoutWidget);
        lblTotalTurnOver->setObjectName(QStringLiteral("lblTotalTurnOver"));

        gridLayout_2->addWidget(lblTotalTurnOver, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        WBSDPayWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WBSDPayWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDPayWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(WBSDPayWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1119, 21));
        WBSDPayWindow->setMenuBar(menubar);
        QWidget::setTabOrder(cboRFIDMode, cboRFIDTimeout);
        QWidget::setTabOrder(cboRFIDTimeout, cboPaymentEnabled);
        QWidget::setTabOrder(cboPaymentEnabled, cboClearCreditTime);
        QWidget::setTabOrder(cboClearCreditTime, cboSaleType);
        QWidget::setTabOrder(cboSaleType, cboCurrency);
        QWidget::setTabOrder(cboCurrency, button9);
        QWidget::setTabOrder(button9, button10);
        QWidget::setTabOrder(button10, button11);
        QWidget::setTabOrder(button11, button7);
        QWidget::setTabOrder(button7, button1);
        QWidget::setTabOrder(button1, button4);
        QWidget::setTabOrder(button4, button8);
        QWidget::setTabOrder(button8, button2);
        QWidget::setTabOrder(button2, button5);
        QWidget::setTabOrder(button5, button3);
        QWidget::setTabOrder(button3, button6);
        QWidget::setTabOrder(button6, btnCoinChanelA);
        QWidget::setTabOrder(btnCoinChanelA, btnCoinChanelB);
        QWidget::setTabOrder(btnCoinChanelB, btnCoinChanelC);
        QWidget::setTabOrder(btnCoinChanelC, btnCoinChanelD);
        QWidget::setTabOrder(btnCoinChanelD, btnCoinChanelE);
        QWidget::setTabOrder(btnCoinChanelE, btnCoinChanelF);
        QWidget::setTabOrder(btnCoinChanelF, btnReset);

        retranslateUi(WBSDPayWindow);
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), horizontalSlider_4, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_4, SIGNAL(valueChanged(int)), spinBox_4, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), horizontalSlider_2, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(WBSDPayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDPayWindow)
    {
        WBSDPayWindow->setWindowTitle(QApplication::translate("WBSDPayWindow", "Payment/RFID settings", 0));
        lblRFIDTimeOut->setText(QApplication::translate("WBSDPayWindow", "RFID Timeout x 10 sec", 0));
        lblPayEnabled->setText(QApplication::translate("WBSDPayWindow", "Payment enabled", 0));
        lblRFIDMode->setText(QApplication::translate("WBSDPayWindow", "RFID Mode", 0));
        lblCurrency->setText(QApplication::translate("WBSDPayWindow", "Currency", 0));
        lblSaletype->setText(QApplication::translate("WBSDPayWindow", "Vendor mode", 0));
        lblClearCreditTime->setText(QApplication::translate("WBSDPayWindow", "Clear credit time (minutes)", 0));
        button9->setText(QString());
        button10->setText(QString());
        button11->setText(QString());
        button6->setText(QApplication::translate("WBSDPayWindow", "Price Button 6", 0));
        button3->setText(QApplication::translate("WBSDPayWindow", "Price Button 3", 0));
        button2->setText(QApplication::translate("WBSDPayWindow", "Price Button 2", 0));
        button4->setText(QApplication::translate("WBSDPayWindow", "Price Button 4", 0));
        button1->setText(QApplication::translate("WBSDPayWindow", "Price Button 1", 0));
        button5->setText(QApplication::translate("WBSDPayWindow", "Price Button 5", 0));
        button7->setText(QApplication::translate("WBSDPayWindow", "Price Button 7", 0));
        button8->setText(QApplication::translate("WBSDPayWindow", "Price Button 8", 0));
        btnCoinChanelF->setText(QApplication::translate("WBSDPayWindow", "Coin Channel F", 0));
        btnCoinChanelA->setText(QApplication::translate("WBSDPayWindow", "Coin Channel A", 0));
        btnCoinChanelE->setText(QApplication::translate("WBSDPayWindow", "Coin Channel E", 0));
        btnCoinChanelB->setText(QApplication::translate("WBSDPayWindow", "Coin Channel B", 0));
        btnCoinChanelD->setText(QApplication::translate("WBSDPayWindow", "Coin Channel D", 0));
        btnCoinChanelC->setText(QApplication::translate("WBSDPayWindow", "Coin Channel C", 0));
        label_6->setText(QApplication::translate("WBSDPayWindow", "Cashbox Full Flag", 0));
        label_7->setText(QApplication::translate("WBSDPayWindow", "Cashbox Warning Set Value", 0));
        label_8->setText(QApplication::translate("WBSDPayWindow", "Cashbox Full Set Value", 0));
        label_9->setText(QApplication::translate("WBSDPayWindow", "Cashbox Coin Counters", 0));
        label_10->setText(QApplication::translate("WBSDPayWindow", "Cashbox Warning Flag", 0));
        lbl_flag_full_2->setText(QApplication::translate("WBSDPayWindow", "-", 0));
        lbl_flag_warn_2->setText(QApplication::translate("WBSDPayWindow", "-", 0));
        lbl_flag_counters->setText(QApplication::translate("WBSDPayWindow", "-", 0));
        btn_setwarn_2->setText(QApplication::translate("WBSDPayWindow", "Set cashbox  value", 0));
        label->setText(QApplication::translate("WBSDPayWindow", "coins", 0));
        label_2->setText(QApplication::translate("WBSDPayWindow", "coins", 0));
        btnReset->setText(QApplication::translate("WBSDPayWindow", "Collect cashbox", 0));
        lblMoneyInCashBox->setText(QApplication::translate("WBSDPayWindow", "Money in cashbox", 0));
        lblFreeVendTokens->setText(QApplication::translate("WBSDPayWindow", "Free vend tokens", 0));
        lblTotalCollected->setText(QApplication::translate("WBSDPayWindow", "Total collected money", 0));
        lblTotalTurnOver->setText(QApplication::translate("WBSDPayWindow", "Total turnover", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDPayWindow: public Ui_WBSDPayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDPAYWINDOW_H

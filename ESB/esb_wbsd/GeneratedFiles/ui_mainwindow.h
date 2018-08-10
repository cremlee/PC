/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_6;
    QListWidget *lstMetaData;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_25;
    QFrame *fraStatus;
    QLabel *label_26;
    QGroupBox *fraButtons;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *btn7;
    QPushButton *pushButton_3;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn8;
    QPushButton *btnM1;
    QPushButton *btnP1;
    QPushButton *btnC1;
    QPushButton *btnR1;
    QPushButton *btnC2_2;
    QPushButton *btnP2;
    QPushButton *btnM2;
    QPushButton *btnR2;
    QPushButton *btnC3;
    QPushButton *btnP3;
    QPushButton *btnM3;
    QPushButton *btnR3;
    QPushButton *btnC4;
    QPushButton *btnP4;
    QPushButton *btnM4;
    QPushButton *btnR4;
    QPushButton *btnC5;
    QPushButton *btnP5;
    QPushButton *btnM5;
    QPushButton *btnR5;
    QPushButton *btnC6;
    QPushButton *btnP6;
    QPushButton *btnM6;
    QPushButton *btnR6;
    QPushButton *btnP7;
    QPushButton *btnC7;
    QPushButton *btnR7;
    QPushButton *btnM7;
    QPushButton *btnC8;
    QPushButton *btnM8;
    QPushButton *btnP8;
    QPushButton *btnR8;
    QPushButton *btnTest;
    QPushButton *btnReset_2;
    QGroupBox *groupBox_5;
    QLabel *label_11;
    QLCDNumber *lcdTnkUp;
    QLabel *label_12;
    QLCDNumber *lcdTnkDown;
    QLCDNumber *lcdFridge;
    QLabel *label_13;
    QLabel *label_7;
    QLCDNumber *lcdHeater;
    QLabel *label_10;
    QLCDNumber *lcdPelitier;
    QLabel *label_14;
    QLabel *label_15;
    QLCDNumber *lcdLBIB;
    QLCDNumber *lcdRBIB;
    QLabel *label_23;
    QLabel *label_24;
    QLCDNumber *lcdDriptray;
    QLCDNumber *lcdWJM;
    QRadioButton *optModeNormal;
    QRadioButton *optModeOperator;
    QRadioButton *optModeService;
    QRadioButton *optModeManufacturer;
    QLabel *label_16;
    QRadioButton *optModeCleaner;
    QRadioButton *optModeWBSD;
    QRadioButton *optModeNurse;
    QLabel *label_17;
    QLCDNumber *lcdLevAirbr;
    QLCDNumber *lcdLevBoil;
    QLabel *label_18;
    QLabel *label_19;
    QLCDNumber *lcdFlow;
    QGroupBox *groupBox_2;
    QPushButton *btnTestInletValve;
    QPushButton *btnTestHeater;
    QPushButton *btnTestWaterPump;
    QPushButton *btnTestNOV;
    QPushButton *btnTestAirpump;
    QLCDNumber *lcdNumber;
    QPushButton *btnGetKayMappings;
    QPushButton *btnChkErrors;
    QPushButton *btnLoadMetadata;
    QPushButton *btnTestLBIBValve;
    QPushButton *btnTestLBIBAirValve;
    QPushButton *btnTestRBIBValve;
    QPushButton *btnTestRBIBAirValve;
    QPushButton *btnTestInstantValve;
    QPushButton *btnTestInstantMixer;
    QPushButton *btnTestInstantCanister;
    QPushButton *btnTestHowWaterValve;
    QPushButton *btnTestColdWaterValve;
    QPushButton *btnTestInstantFan;
    QPushButton *btnTestLB2;
    QPushButton *btnTestRB2;
    QPushButton *btnTestCooler;
    QListWidget *lstLog;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_6;
    QListWidget *lstHistoricErrors;
    QListWidget *lstActiveErrors;
    QGroupBox *groupBox_3;
    QPushButton *btnSetTime;
    QPushButton *btnRestart;
    QPushButton *btnReset;
    QComboBox *cboConf;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *cboRFID;
    QGroupBox *groupBox_7;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *lblData;
    QLabel *lblProt;
    QLabel *label_3;
    QLabel *lbltype;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *lblParams;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QComboBox *cboCommand;
    QPushButton *btnReconnect;
    QPushButton *btnResetLog;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1646, 756);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        lstMetaData = new QListWidget(groupBox_6);
        lstMetaData->setObjectName(QStringLiteral("lstMetaData"));
        lstMetaData->setGeometry(QRect(10, 80, 251, 111));
        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 20, 81, 16));
        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 40, 41, 16));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(90, 20, 151, 16));
        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(90, 40, 151, 16));
        fraStatus = new QFrame(groupBox_6);
        fraStatus->setObjectName(QStringLiteral("fraStatus"));
        fraStatus->setGeometry(QRect(240, 50, 16, 20));
        fraStatus->setStyleSheet(QLatin1String("background:rgb(170, 0, 0)\n"
""));
        fraStatus->setFrameShape(QFrame::StyledPanel);
        fraStatus->setFrameShadow(QFrame::Raised);
        label_26 = new QLabel(groupBox_6);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 60, 71, 16));

        gridLayout->addWidget(groupBox_6, 0, 0, 1, 1);

        fraButtons = new QGroupBox(centralWidget);
        fraButtons->setObjectName(QStringLiteral("fraButtons"));
        fraButtons->setStyleSheet(QStringLiteral(""));
        pushButton_2 = new QPushButton(fraButtons);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 20, 28, 28));
        pushButton_2->setStyleSheet(QStringLiteral("background:rgb(255, 0, 0)"));
        pushButton_4 = new QPushButton(fraButtons);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 20, 28, 28));
        pushButton_4->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btn7 = new QPushButton(fraButtons);
        btn7->setObjectName(QStringLiteral("btn7"));
        btn7->setGeometry(QRect(10, 70, 28, 28));
        btn7->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        pushButton_3 = new QPushButton(fraButtons);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 20, 28, 28));
        pushButton_3->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btn5 = new QPushButton(fraButtons);
        btn5->setObjectName(QStringLiteral("btn5"));
        btn5->setGeometry(QRect(220, 110, 28, 28));
        btn5->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btn6 = new QPushButton(fraButtons);
        btn6->setObjectName(QStringLiteral("btn6"));
        btn6->setGeometry(QRect(220, 160, 28, 28));
        btn6->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btn3 = new QPushButton(fraButtons);
        btn3->setObjectName(QStringLiteral("btn3"));
        btn3->setGeometry(QRect(120, 160, 28, 28));
        btn3->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btn4 = new QPushButton(fraButtons);
        btn4->setObjectName(QStringLiteral("btn4"));
        btn4->setGeometry(QRect(220, 60, 28, 28));
        btn4->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btn1 = new QPushButton(fraButtons);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setGeometry(QRect(120, 60, 28, 28));
        btn1->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btn2 = new QPushButton(fraButtons);
        btn2->setObjectName(QStringLiteral("btn2"));
        btn2->setGeometry(QRect(120, 110, 28, 28));
        btn2->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btn8 = new QPushButton(fraButtons);
        btn8->setObjectName(QStringLiteral("btn8"));
        btn8->setGeometry(QRect(10, 120, 28, 28));
        btn8->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnM1 = new QPushButton(fraButtons);
        btnM1->setObjectName(QStringLiteral("btnM1"));
        btnM1->setGeometry(QRect(150, 60, 16, 16));
        btnM1->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnP1 = new QPushButton(fraButtons);
        btnP1->setObjectName(QStringLiteral("btnP1"));
        btnP1->setGeometry(QRect(170, 60, 32, 16));
        btnP1->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnC1 = new QPushButton(fraButtons);
        btnC1->setObjectName(QStringLiteral("btnC1"));
        btnC1->setGeometry(QRect(150, 80, 16, 16));
        btnC1->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnR1 = new QPushButton(fraButtons);
        btnR1->setObjectName(QStringLiteral("btnR1"));
        btnR1->setGeometry(QRect(170, 80, 32, 16));
        btnR1->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnC2_2 = new QPushButton(fraButtons);
        btnC2_2->setObjectName(QStringLiteral("btnC2_2"));
        btnC2_2->setGeometry(QRect(150, 130, 16, 16));
        btnC2_2->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnP2 = new QPushButton(fraButtons);
        btnP2->setObjectName(QStringLiteral("btnP2"));
        btnP2->setGeometry(QRect(170, 110, 32, 16));
        btnP2->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnM2 = new QPushButton(fraButtons);
        btnM2->setObjectName(QStringLiteral("btnM2"));
        btnM2->setGeometry(QRect(150, 110, 16, 16));
        btnM2->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnR2 = new QPushButton(fraButtons);
        btnR2->setObjectName(QStringLiteral("btnR2"));
        btnR2->setGeometry(QRect(170, 130, 32, 16));
        btnR2->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnC3 = new QPushButton(fraButtons);
        btnC3->setObjectName(QStringLiteral("btnC3"));
        btnC3->setGeometry(QRect(150, 180, 16, 16));
        btnC3->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnP3 = new QPushButton(fraButtons);
        btnP3->setObjectName(QStringLiteral("btnP3"));
        btnP3->setGeometry(QRect(170, 160, 32, 16));
        btnP3->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnM3 = new QPushButton(fraButtons);
        btnM3->setObjectName(QStringLiteral("btnM3"));
        btnM3->setGeometry(QRect(150, 160, 16, 16));
        btnM3->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnR3 = new QPushButton(fraButtons);
        btnR3->setObjectName(QStringLiteral("btnR3"));
        btnR3->setGeometry(QRect(170, 180, 32, 16));
        btnR3->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnC4 = new QPushButton(fraButtons);
        btnC4->setObjectName(QStringLiteral("btnC4"));
        btnC4->setGeometry(QRect(250, 80, 16, 16));
        btnC4->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnP4 = new QPushButton(fraButtons);
        btnP4->setObjectName(QStringLiteral("btnP4"));
        btnP4->setGeometry(QRect(270, 60, 32, 16));
        btnP4->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnM4 = new QPushButton(fraButtons);
        btnM4->setObjectName(QStringLiteral("btnM4"));
        btnM4->setGeometry(QRect(250, 60, 16, 16));
        btnM4->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnR4 = new QPushButton(fraButtons);
        btnR4->setObjectName(QStringLiteral("btnR4"));
        btnR4->setGeometry(QRect(270, 80, 32, 16));
        btnR4->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnC5 = new QPushButton(fraButtons);
        btnC5->setObjectName(QStringLiteral("btnC5"));
        btnC5->setGeometry(QRect(250, 130, 16, 16));
        btnC5->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnP5 = new QPushButton(fraButtons);
        btnP5->setObjectName(QStringLiteral("btnP5"));
        btnP5->setGeometry(QRect(270, 110, 32, 16));
        btnP5->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnM5 = new QPushButton(fraButtons);
        btnM5->setObjectName(QStringLiteral("btnM5"));
        btnM5->setGeometry(QRect(250, 110, 16, 16));
        btnM5->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnR5 = new QPushButton(fraButtons);
        btnR5->setObjectName(QStringLiteral("btnR5"));
        btnR5->setGeometry(QRect(270, 130, 32, 16));
        btnR5->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnC6 = new QPushButton(fraButtons);
        btnC6->setObjectName(QStringLiteral("btnC6"));
        btnC6->setGeometry(QRect(250, 180, 16, 16));
        btnC6->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnP6 = new QPushButton(fraButtons);
        btnP6->setObjectName(QStringLiteral("btnP6"));
        btnP6->setGeometry(QRect(270, 160, 32, 16));
        btnP6->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnM6 = new QPushButton(fraButtons);
        btnM6->setObjectName(QStringLiteral("btnM6"));
        btnM6->setGeometry(QRect(250, 160, 16, 16));
        btnM6->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnR6 = new QPushButton(fraButtons);
        btnR6->setObjectName(QStringLiteral("btnR6"));
        btnR6->setGeometry(QRect(270, 180, 32, 16));
        btnR6->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnP7 = new QPushButton(fraButtons);
        btnP7->setObjectName(QStringLiteral("btnP7"));
        btnP7->setGeometry(QRect(60, 70, 32, 16));
        btnP7->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnC7 = new QPushButton(fraButtons);
        btnC7->setObjectName(QStringLiteral("btnC7"));
        btnC7->setGeometry(QRect(40, 90, 16, 16));
        btnC7->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnR7 = new QPushButton(fraButtons);
        btnR7->setObjectName(QStringLiteral("btnR7"));
        btnR7->setGeometry(QRect(60, 90, 32, 16));
        btnR7->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnM7 = new QPushButton(fraButtons);
        btnM7->setObjectName(QStringLiteral("btnM7"));
        btnM7->setGeometry(QRect(40, 70, 16, 16));
        btnM7->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnC8 = new QPushButton(fraButtons);
        btnC8->setObjectName(QStringLiteral("btnC8"));
        btnC8->setGeometry(QRect(40, 140, 16, 16));
        btnC8->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnM8 = new QPushButton(fraButtons);
        btnM8->setObjectName(QStringLiteral("btnM8"));
        btnM8->setGeometry(QRect(40, 120, 16, 16));
        btnM8->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnP8 = new QPushButton(fraButtons);
        btnP8->setObjectName(QStringLiteral("btnP8"));
        btnP8->setGeometry(QRect(60, 120, 32, 16));
        btnP8->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnR8 = new QPushButton(fraButtons);
        btnR8->setObjectName(QStringLiteral("btnR8"));
        btnR8->setGeometry(QRect(60, 140, 32, 16));
        btnR8->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));
        btnTest = new QPushButton(fraButtons);
        btnTest->setObjectName(QStringLiteral("btnTest"));
        btnTest->setGeometry(QRect(10, 20, 51, 23));
        btnReset_2 = new QPushButton(fraButtons);
        btnReset_2->setObjectName(QStringLiteral("btnReset_2"));
        btnReset_2->setGeometry(QRect(10, 170, 28, 28));
        btnReset_2->setStyleSheet(QStringLiteral("background:rgb(214, 214, 214)"));

        gridLayout->addWidget(fraButtons, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 20, 81, 16));
        lcdTnkUp = new QLCDNumber(groupBox_5);
        lcdTnkUp->setObjectName(QStringLiteral("lcdTnkUp"));
        lcdTnkUp->setGeometry(QRect(30, 40, 64, 23));
        lcdTnkUp->setStyleSheet(QStringLiteral("foreground:rgb(255, 0, 0)"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 70, 91, 16));
        lcdTnkDown = new QLCDNumber(groupBox_5);
        lcdTnkDown->setObjectName(QStringLiteral("lcdTnkDown"));
        lcdTnkDown->setGeometry(QRect(30, 90, 64, 23));
        lcdTnkDown->setStyleSheet(QStringLiteral("foreground:rgb(255, 0, 0)"));
        lcdFridge = new QLCDNumber(groupBox_5);
        lcdFridge->setObjectName(QStringLiteral("lcdFridge"));
        lcdFridge->setGeometry(QRect(30, 140, 64, 23));
        lcdFridge->setStyleSheet(QStringLiteral("foreground:rgb(0, 85, 255)"));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 120, 61, 16));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 200, 46, 13));
        lcdHeater = new QLCDNumber(groupBox_5);
        lcdHeater->setObjectName(QStringLiteral("lcdHeater"));
        lcdHeater->setGeometry(QRect(30, 220, 16, 23));
        lcdHeater->setDigitCount(1);
        lcdHeater->setMode(QLCDNumber::Bin);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(110, 200, 46, 13));
        lcdPelitier = new QLCDNumber(groupBox_5);
        lcdPelitier->setObjectName(QStringLiteral("lcdPelitier"));
        lcdPelitier->setGeometry(QRect(120, 220, 16, 23));
        lcdPelitier->setDigitCount(1);
        lcdPelitier->setMode(QLCDNumber::Bin);
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 250, 71, 16));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(90, 250, 81, 16));
        lcdLBIB = new QLCDNumber(groupBox_5);
        lcdLBIB->setObjectName(QStringLiteral("lcdLBIB"));
        lcdLBIB->setGeometry(QRect(30, 270, 16, 23));
        lcdLBIB->setDigitCount(1);
        lcdLBIB->setMode(QLCDNumber::Bin);
        lcdRBIB = new QLCDNumber(groupBox_5);
        lcdRBIB->setObjectName(QStringLiteral("lcdRBIB"));
        lcdRBIB->setGeometry(QRect(120, 270, 16, 23));
        lcdRBIB->setDigitCount(1);
        lcdRBIB->setMode(QLCDNumber::Bin);
        label_23 = new QLabel(groupBox_5);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 300, 81, 16));
        label_24 = new QLabel(groupBox_5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(90, 300, 91, 16));
        lcdDriptray = new QLCDNumber(groupBox_5);
        lcdDriptray->setObjectName(QStringLiteral("lcdDriptray"));
        lcdDriptray->setGeometry(QRect(30, 320, 16, 23));
        lcdDriptray->setDigitCount(1);
        lcdDriptray->setMode(QLCDNumber::Bin);
        lcdWJM = new QLCDNumber(groupBox_5);
        lcdWJM->setObjectName(QStringLiteral("lcdWJM"));
        lcdWJM->setGeometry(QRect(120, 320, 16, 23));
        lcdWJM->setDigitCount(1);
        lcdWJM->setMode(QLCDNumber::Bin);
        optModeNormal = new QRadioButton(groupBox_5);
        optModeNormal->setObjectName(QStringLiteral("optModeNormal"));
        optModeNormal->setGeometry(QRect(150, 40, 82, 17));
        optModeOperator = new QRadioButton(groupBox_5);
        optModeOperator->setObjectName(QStringLiteral("optModeOperator"));
        optModeOperator->setGeometry(QRect(150, 100, 82, 17));
        optModeService = new QRadioButton(groupBox_5);
        optModeService->setObjectName(QStringLiteral("optModeService"));
        optModeService->setGeometry(QRect(150, 120, 82, 17));
        optModeService->setChecked(true);
        optModeManufacturer = new QRadioButton(groupBox_5);
        optModeManufacturer->setObjectName(QStringLiteral("optModeManufacturer"));
        optModeManufacturer->setEnabled(false);
        optModeManufacturer->setGeometry(QRect(150, 140, 91, 17));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(140, 20, 101, 16));
        optModeCleaner = new QRadioButton(groupBox_5);
        optModeCleaner->setObjectName(QStringLiteral("optModeCleaner"));
        optModeCleaner->setEnabled(false);
        optModeCleaner->setGeometry(QRect(150, 80, 82, 17));
        optModeWBSD = new QRadioButton(groupBox_5);
        optModeWBSD->setObjectName(QStringLiteral("optModeWBSD"));
        optModeWBSD->setEnabled(false);
        optModeWBSD->setGeometry(QRect(150, 160, 82, 17));
        optModeWBSD->setCheckable(true);
        optModeWBSD->setChecked(false);
        optModeNurse = new QRadioButton(groupBox_5);
        optModeNurse->setObjectName(QStringLiteral("optModeNurse"));
        optModeNurse->setGeometry(QRect(150, 60, 82, 17));
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(180, 200, 61, 16));
        lcdLevAirbr = new QLCDNumber(groupBox_5);
        lcdLevAirbr->setObjectName(QStringLiteral("lcdLevAirbr"));
        lcdLevAirbr->setGeometry(QRect(200, 220, 16, 23));
        lcdLevAirbr->setDigitCount(1);
        lcdLevAirbr->setMode(QLCDNumber::Bin);
        lcdLevBoil = new QLCDNumber(groupBox_5);
        lcdLevBoil->setObjectName(QStringLiteral("lcdLevBoil"));
        lcdLevBoil->setGeometry(QRect(200, 270, 16, 23));
        lcdLevBoil->setDigitCount(1);
        lcdLevBoil->setMode(QLCDNumber::Bin);
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(180, 250, 61, 16));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(190, 300, 46, 13));
        lcdFlow = new QLCDNumber(groupBox_5);
        lcdFlow->setObjectName(QStringLiteral("lcdFlow"));
        lcdFlow->setGeometry(QRect(180, 320, 51, 23));
        lcdFlow->setSmallDecimalPoint(true);
        lcdFlow->setDigitCount(4);
        lcdFlow->setProperty("value", QVariant(13.2));

        gridLayout->addWidget(groupBox_5, 0, 2, 2, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        btnTestInletValve = new QPushButton(groupBox_2);
        btnTestInletValve->setObjectName(QStringLiteral("btnTestInletValve"));
        btnTestInletValve->setGeometry(QRect(10, 20, 211, 23));
        btnTestHeater = new QPushButton(groupBox_2);
        btnTestHeater->setObjectName(QStringLiteral("btnTestHeater"));
        btnTestHeater->setGeometry(QRect(10, 50, 211, 23));
        btnTestWaterPump = new QPushButton(groupBox_2);
        btnTestWaterPump->setObjectName(QStringLiteral("btnTestWaterPump"));
        btnTestWaterPump->setGeometry(QRect(10, 80, 111, 23));
        btnTestNOV = new QPushButton(groupBox_2);
        btnTestNOV->setObjectName(QStringLiteral("btnTestNOV"));
        btnTestNOV->setGeometry(QRect(10, 110, 211, 23));
        btnTestAirpump = new QPushButton(groupBox_2);
        btnTestAirpump->setObjectName(QStringLiteral("btnTestAirpump"));
        btnTestAirpump->setGeometry(QRect(10, 140, 211, 23));
        lcdNumber = new QLCDNumber(groupBox_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(150, 80, 64, 23));
        btnGetKayMappings = new QPushButton(groupBox_2);
        btnGetKayMappings->setObjectName(QStringLiteral("btnGetKayMappings"));
        btnGetKayMappings->setGeometry(QRect(10, 550, 221, 23));
        btnGetKayMappings->setStyleSheet(QStringLiteral("background:rgb(230, 230, 230)"));
        btnChkErrors = new QPushButton(groupBox_2);
        btnChkErrors->setObjectName(QStringLiteral("btnChkErrors"));
        btnChkErrors->setGeometry(QRect(10, 520, 221, 23));
        btnChkErrors->setStyleSheet(QStringLiteral("background:rgb(230, 230, 230)"));
        btnLoadMetadata = new QPushButton(groupBox_2);
        btnLoadMetadata->setObjectName(QStringLiteral("btnLoadMetadata"));
        btnLoadMetadata->setGeometry(QRect(10, 490, 221, 23));
        btnLoadMetadata->setStyleSheet(QStringLiteral("background:rgb(230, 230, 230)"));
        btnTestLBIBValve = new QPushButton(groupBox_2);
        btnTestLBIBValve->setObjectName(QStringLiteral("btnTestLBIBValve"));
        btnTestLBIBValve->setGeometry(QRect(10, 170, 101, 23));
        btnTestLBIBAirValve = new QPushButton(groupBox_2);
        btnTestLBIBAirValve->setObjectName(QStringLiteral("btnTestLBIBAirValve"));
        btnTestLBIBAirValve->setGeometry(QRect(130, 170, 91, 23));
        btnTestRBIBValve = new QPushButton(groupBox_2);
        btnTestRBIBValve->setObjectName(QStringLiteral("btnTestRBIBValve"));
        btnTestRBIBValve->setGeometry(QRect(10, 200, 101, 23));
        btnTestRBIBAirValve = new QPushButton(groupBox_2);
        btnTestRBIBAirValve->setObjectName(QStringLiteral("btnTestRBIBAirValve"));
        btnTestRBIBAirValve->setGeometry(QRect(130, 200, 91, 23));
        btnTestInstantValve = new QPushButton(groupBox_2);
        btnTestInstantValve->setObjectName(QStringLiteral("btnTestInstantValve"));
        btnTestInstantValve->setGeometry(QRect(10, 230, 75, 23));
        btnTestInstantMixer = new QPushButton(groupBox_2);
        btnTestInstantMixer->setObjectName(QStringLiteral("btnTestInstantMixer"));
        btnTestInstantMixer->setGeometry(QRect(90, 230, 75, 23));
        btnTestInstantCanister = new QPushButton(groupBox_2);
        btnTestInstantCanister->setObjectName(QStringLiteral("btnTestInstantCanister"));
        btnTestInstantCanister->setGeometry(QRect(170, 230, 61, 23));
        btnTestHowWaterValve = new QPushButton(groupBox_2);
        btnTestHowWaterValve->setObjectName(QStringLiteral("btnTestHowWaterValve"));
        btnTestHowWaterValve->setGeometry(QRect(10, 290, 111, 23));
        btnTestColdWaterValve = new QPushButton(groupBox_2);
        btnTestColdWaterValve->setObjectName(QStringLiteral("btnTestColdWaterValve"));
        btnTestColdWaterValve->setGeometry(QRect(130, 290, 101, 23));
        btnTestInstantFan = new QPushButton(groupBox_2);
        btnTestInstantFan->setObjectName(QStringLiteral("btnTestInstantFan"));
        btnTestInstantFan->setGeometry(QRect(90, 260, 75, 23));
        btnTestLB2 = new QPushButton(groupBox_2);
        btnTestLB2->setObjectName(QStringLiteral("btnTestLB2"));
        btnTestLB2->setGeometry(QRect(10, 380, 75, 23));
        btnTestRB2 = new QPushButton(groupBox_2);
        btnTestRB2->setObjectName(QStringLiteral("btnTestRB2"));
        btnTestRB2->setGeometry(QRect(150, 380, 75, 23));
        btnTestCooler = new QPushButton(groupBox_2);
        btnTestCooler->setObjectName(QStringLiteral("btnTestCooler"));
        btnTestCooler->setGeometry(QRect(90, 340, 75, 23));

        gridLayout->addWidget(groupBox_2, 0, 3, 3, 1);

        lstLog = new QListWidget(centralWidget);
        lstLog->setObjectName(QStringLiteral("lstLog"));

        gridLayout->addWidget(lstLog, 0, 4, 4, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 111, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 200, 281, 16));
        lstHistoricErrors = new QListWidget(groupBox);
        lstHistoricErrors->setObjectName(QStringLiteral("lstHistoricErrors"));
        lstHistoricErrors->setGeometry(QRect(20, 220, 631, 161));
        lstActiveErrors = new QListWidget(groupBox);
        lstActiveErrors->setObjectName(QStringLiteral("lstActiveErrors"));
        lstActiveErrors->setGeometry(QRect(20, 40, 631, 151));

        gridLayout->addWidget(groupBox, 1, 0, 2, 2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        btnSetTime = new QPushButton(groupBox_3);
        btnSetTime->setObjectName(QStringLiteral("btnSetTime"));
        btnSetTime->setGeometry(QRect(10, 90, 231, 23));
        btnRestart = new QPushButton(groupBox_3);
        btnRestart->setObjectName(QStringLiteral("btnRestart"));
        btnRestart->setGeometry(QRect(10, 20, 231, 23));
        btnReset = new QPushButton(groupBox_3);
        btnReset->setObjectName(QStringLiteral("btnReset"));
        btnReset->setGeometry(QRect(10, 50, 231, 23));
        cboConf = new QComboBox(groupBox_3);
        cboConf->setObjectName(QStringLiteral("cboConf"));
        cboConf->setGeometry(QRect(10, 140, 231, 22));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 120, 46, 13));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 180, 46, 13));
        cboRFID = new QComboBox(groupBox_3);
        cboRFID->setObjectName(QStringLiteral("cboRFID"));
        cboRFID->setGeometry(QRect(10, 200, 231, 22));

        gridLayout->addWidget(groupBox_3, 2, 2, 1, 1);

        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        lineEdit = new QLineEdit(groupBox_7);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 261, 20));
        label_2 = new QLabel(groupBox_7);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 20, 46, 13));
        lblData = new QLabel(groupBox_7);
        lblData->setObjectName(QStringLiteral("lblData"));
        lblData->setGeometry(QRect(60, 80, 531, 16));
        lblProt = new QLabel(groupBox_7);
        lblProt->setObjectName(QStringLiteral("lblProt"));
        lblProt->setGeometry(QRect(400, 20, 61, 16));
        label_3 = new QLabel(groupBox_7);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 46, 13));
        lbltype = new QLabel(groupBox_7);
        lbltype->setObjectName(QStringLiteral("lbltype"));
        lbltype->setGeometry(QRect(60, 40, 411, 16));
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 46, 13));
        pushButton = new QPushButton(groupBox_7);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 20, 61, 23));
        lblParams = new QLabel(groupBox_7);
        lblParams->setObjectName(QStringLiteral("lblParams"));
        lblParams->setGeometry(QRect(60, 60, 441, 16));
        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 80, 46, 13));

        gridLayout->addWidget(groupBox_7, 3, 0, 2, 2);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        cboCommand = new QComboBox(groupBox_4);
        cboCommand->setObjectName(QStringLiteral("cboCommand"));
        cboCommand->setGeometry(QRect(60, 20, 431, 22));
        cboCommand->setEditable(false);
        btnReconnect = new QPushButton(groupBox_4);
        btnReconnect->setObjectName(QStringLiteral("btnReconnect"));
        btnReconnect->setGeometry(QRect(410, 60, 75, 23));

        gridLayout->addWidget(groupBox_4, 3, 2, 2, 2);

        btnResetLog = new QPushButton(centralWidget);
        btnResetLog->setObjectName(QStringLiteral("btnResetLog"));

        gridLayout->addWidget(btnResetLog, 4, 4, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WBSD Micro", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Machine Information", 0));
        label_20->setText(QApplication::translate("MainWindow", "Service Device:", 0));
        label_21->setText(QApplication::translate("MainWindow", "Version:", 0));
        label_22->setText(QApplication::translate("MainWindow", "lblServiceDevice", 0));
        label_25->setText(QApplication::translate("MainWindow", "lblSDFirmware", 0));
        label_26->setText(QApplication::translate("MainWindow", "ESB Information", 0));
        fraButtons->setTitle(QApplication::translate("MainWindow", "Button settings", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Stop", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Str", 0));
#ifndef QT_NO_TOOLTIP
        btn7->setToolTip(QApplication::translate("MainWindow", "Hot water", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btn7->setStatusTip(QApplication::translate("MainWindow", "Hot water", 0));
#endif // QT_NO_STATUSTIP
        btn7->setText(QApplication::translate("MainWindow", "HW", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Vol", 0));
        btn5->setText(QApplication::translate("MainWindow", "5/D", 0));
        btn6->setText(QApplication::translate("MainWindow", "6/E", 0));
        btn3->setText(QApplication::translate("MainWindow", "3", 0));
        btn4->setText(QApplication::translate("MainWindow", "4/U", 0));
#ifndef QT_NO_TOOLTIP
        btn1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn1->setText(QApplication::translate("MainWindow", "1", 0));
        btn2->setText(QApplication::translate("MainWindow", "2", 0));
#ifndef QT_NO_TOOLTIP
        btn8->setToolTip(QApplication::translate("MainWindow", "Cold water", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btn8->setStatusTip(QApplication::translate("MainWindow", "Cold water", 0));
#endif // QT_NO_STATUSTIP
        btn8->setText(QApplication::translate("MainWindow", "CW", 0));
#ifndef QT_NO_TOOLTIP
        btnM1->setToolTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnM1->setStatusTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnM1->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        btnM1->setText(QApplication::translate("MainWindow", "M", 0));
#ifndef QT_NO_TOOLTIP
        btnP1->setToolTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnP1->setStatusTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnP1->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        btnP1->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        btnP1->setText(QApplication::translate("MainWindow", "P(0.0)", 0));
#ifndef QT_NO_TOOLTIP
        btnC1->setToolTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnC1->setStatusTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_STATUSTIP
        btnC1->setText(QApplication::translate("MainWindow", "C", 0));
#ifndef QT_NO_TOOLTIP
        btnR1->setToolTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnR1->setStatusTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_STATUSTIP
        btnR1->setText(QApplication::translate("MainWindow", "R(XX)", 0));
#ifndef QT_NO_TOOLTIP
        btnC2_2->setToolTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnC2_2->setStatusTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_STATUSTIP
        btnC2_2->setText(QApplication::translate("MainWindow", "C", 0));
#ifndef QT_NO_TOOLTIP
        btnP2->setToolTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnP2->setStatusTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_STATUSTIP
        btnP2->setText(QApplication::translate("MainWindow", "P(0.0)", 0));
#ifndef QT_NO_TOOLTIP
        btnM2->setToolTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnM2->setStatusTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_STATUSTIP
        btnM2->setText(QApplication::translate("MainWindow", "M", 0));
#ifndef QT_NO_TOOLTIP
        btnR2->setToolTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnR2->setStatusTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_STATUSTIP
        btnR2->setText(QApplication::translate("MainWindow", "R(XX)", 0));
#ifndef QT_NO_TOOLTIP
        btnC3->setToolTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnC3->setStatusTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_STATUSTIP
        btnC3->setText(QApplication::translate("MainWindow", "C", 0));
#ifndef QT_NO_TOOLTIP
        btnP3->setToolTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnP3->setStatusTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_STATUSTIP
        btnP3->setText(QApplication::translate("MainWindow", "P(0.0)", 0));
#ifndef QT_NO_TOOLTIP
        btnM3->setToolTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnM3->setStatusTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_STATUSTIP
        btnM3->setText(QApplication::translate("MainWindow", "M", 0));
#ifndef QT_NO_TOOLTIP
        btnR3->setToolTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnR3->setStatusTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_STATUSTIP
        btnR3->setText(QApplication::translate("MainWindow", "R(XX)", 0));
#ifndef QT_NO_TOOLTIP
        btnC4->setToolTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnC4->setStatusTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_STATUSTIP
        btnC4->setText(QApplication::translate("MainWindow", "C", 0));
#ifndef QT_NO_TOOLTIP
        btnP4->setToolTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnP4->setStatusTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        btnP4->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        btnP4->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        btnP4->setText(QApplication::translate("MainWindow", "P(0.0)", 0));
#ifndef QT_NO_TOOLTIP
        btnM4->setToolTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnM4->setStatusTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_STATUSTIP
        btnM4->setText(QApplication::translate("MainWindow", "M", 0));
#ifndef QT_NO_TOOLTIP
        btnR4->setToolTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnR4->setStatusTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_STATUSTIP
        btnR4->setText(QApplication::translate("MainWindow", "R(XX)", 0));
#ifndef QT_NO_TOOLTIP
        btnC5->setToolTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnC5->setStatusTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_STATUSTIP
        btnC5->setText(QApplication::translate("MainWindow", "C", 0));
#ifndef QT_NO_TOOLTIP
        btnP5->setToolTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnP5->setStatusTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_STATUSTIP
        btnP5->setText(QApplication::translate("MainWindow", "P(0.0)", 0));
#ifndef QT_NO_TOOLTIP
        btnM5->setToolTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnM5->setStatusTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_STATUSTIP
        btnM5->setText(QApplication::translate("MainWindow", "M", 0));
#ifndef QT_NO_TOOLTIP
        btnR5->setToolTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnR5->setStatusTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_STATUSTIP
        btnR5->setText(QApplication::translate("MainWindow", "R(XX)", 0));
#ifndef QT_NO_TOOLTIP
        btnC6->setToolTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnC6->setStatusTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_STATUSTIP
        btnC6->setText(QApplication::translate("MainWindow", "C", 0));
#ifndef QT_NO_TOOLTIP
        btnP6->setToolTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnP6->setStatusTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_STATUSTIP
        btnP6->setText(QApplication::translate("MainWindow", "P(0.0)", 0));
#ifndef QT_NO_TOOLTIP
        btnM6->setToolTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnM6->setStatusTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_STATUSTIP
        btnM6->setText(QApplication::translate("MainWindow", "M", 0));
#ifndef QT_NO_TOOLTIP
        btnR6->setToolTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnR6->setStatusTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_STATUSTIP
        btnR6->setText(QApplication::translate("MainWindow", "R(XX)", 0));
#ifndef QT_NO_TOOLTIP
        btnP7->setToolTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnP7->setStatusTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnP7->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        btnP7->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        btnP7->setText(QApplication::translate("MainWindow", "P(0.0)", 0));
#ifndef QT_NO_TOOLTIP
        btnC7->setToolTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnC7->setStatusTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_STATUSTIP
        btnC7->setText(QApplication::translate("MainWindow", "C", 0));
#ifndef QT_NO_TOOLTIP
        btnR7->setToolTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnR7->setStatusTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_STATUSTIP
        btnR7->setText(QApplication::translate("MainWindow", "R(XX)", 0));
#ifndef QT_NO_TOOLTIP
        btnM7->setToolTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnM7->setStatusTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnM7->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        btnM7->setText(QApplication::translate("MainWindow", "M", 0));
#ifndef QT_NO_TOOLTIP
        btnC8->setToolTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnC8->setStatusTip(QApplication::translate("MainWindow", "Read counters", 0));
#endif // QT_NO_STATUSTIP
        btnC8->setText(QApplication::translate("MainWindow", "C", 0));
#ifndef QT_NO_TOOLTIP
        btnM8->setToolTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnM8->setStatusTip(QApplication::translate("MainWindow", "Map recipe to button", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnM8->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        btnM8->setText(QApplication::translate("MainWindow", "M", 0));
#ifndef QT_NO_TOOLTIP
        btnP8->setToolTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnP8->setStatusTip(QApplication::translate("MainWindow", "Set price", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnP8->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        btnP8->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        btnP8->setText(QApplication::translate("MainWindow", "P(0.0)", 0));
#ifndef QT_NO_TOOLTIP
        btnR8->setToolTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnR8->setStatusTip(QApplication::translate("MainWindow", "Edit recipe", 0));
#endif // QT_NO_STATUSTIP
        btnR8->setText(QApplication::translate("MainWindow", "R(XX)", 0));
        btnTest->setText(QApplication::translate("MainWindow", "TestMode", 0));
#ifndef QT_NO_TOOLTIP
        btnReset_2->setToolTip(QApplication::translate("MainWindow", "Standby /Reset", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnReset_2->setStatusTip(QApplication::translate("MainWindow", "Standby /Reset", 0));
#endif // QT_NO_STATUSTIP
        btnReset_2->setText(QApplication::translate("MainWindow", "Rst", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Status", 0));
        label_11->setText(QApplication::translate("MainWindow", "Temp Boiler Top", 0));
        label_12->setText(QApplication::translate("MainWindow", "Temp Boiler Middle", 0));
        label_13->setText(QApplication::translate("MainWindow", "Temp cooler ", 0));
        label_7->setText(QApplication::translate("MainWindow", "Heater", 0));
        label_10->setText(QApplication::translate("MainWindow", "Peltier", 0));
        label_14->setText(QApplication::translate("MainWindow", "Left BIB Empty", 0));
        label_15->setText(QApplication::translate("MainWindow", "Right BIB Empty", 0));
        label_23->setText(QApplication::translate("MainWindow", "Driptray Sensor", 0));
        label_24->setText(QApplication::translate("MainWindow", "WJM Tray Sensor", 0));
        optModeNormal->setText(QApplication::translate("MainWindow", "Normal", 0));
        optModeOperator->setText(QApplication::translate("MainWindow", "Operator", 0));
        optModeService->setText(QApplication::translate("MainWindow", "Service", 0));
        optModeManufacturer->setText(QApplication::translate("MainWindow", "Manufacturer", 0));
        label_16->setText(QApplication::translate("MainWindow", "User level", 0));
        optModeCleaner->setText(QApplication::translate("MainWindow", "Cleaning", 0));
        optModeWBSD->setText(QApplication::translate("MainWindow", "WBSD", 0));
        optModeNurse->setText(QApplication::translate("MainWindow", "Nurse", 0));
        label_17->setText(QApplication::translate("MainWindow", "W. lev. Airb", 0));
        label_18->setText(QApplication::translate("MainWindow", "W. lev. boiler", 0));
        label_19->setText(QApplication::translate("MainWindow", "W. flow", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "HW Test", 0));
        btnTestInletValve->setText(QApplication::translate("MainWindow", "Inlet valve", 0));
        btnTestHeater->setText(QApplication::translate("MainWindow", "Heater Relay", 0));
        btnTestWaterPump->setText(QApplication::translate("MainWindow", "Water pump", 0));
        btnTestNOV->setText(QApplication::translate("MainWindow", "Normal Open Valve", 0));
        btnTestAirpump->setText(QApplication::translate("MainWindow", "Airpump", 0));
        btnGetKayMappings->setText(QApplication::translate("MainWindow", "Reload keymap", 0));
        btnChkErrors->setText(QApplication::translate("MainWindow", "Reload alarms", 0));
        btnLoadMetadata->setText(QApplication::translate("MainWindow", "Load metadata", 0));
        btnTestLBIBValve->setText(QApplication::translate("MainWindow", "LBIB Valve", 0));
        btnTestLBIBAirValve->setText(QApplication::translate("MainWindow", "LBIB  AirValve", 0));
        btnTestRBIBValve->setText(QApplication::translate("MainWindow", "RBIB Valve", 0));
        btnTestRBIBAirValve->setText(QApplication::translate("MainWindow", "RBIB Airvalve", 0));
        btnTestInstantValve->setText(QApplication::translate("MainWindow", "Instant Valve", 0));
        btnTestInstantMixer->setText(QApplication::translate("MainWindow", "Instant Mixer", 0));
        btnTestInstantCanister->setText(QApplication::translate("MainWindow", "Canister", 0));
        btnTestHowWaterValve->setText(QApplication::translate("MainWindow", "Hot water valve", 0));
        btnTestColdWaterValve->setText(QApplication::translate("MainWindow", "Cold water valve", 0));
        btnTestInstantFan->setText(QApplication::translate("MainWindow", "Instant Fan", 0));
        btnTestLB2->setText(QApplication::translate("MainWindow", "Left B2", 0));
        btnTestRB2->setText(QApplication::translate("MainWindow", "Right B2", 0));
        btnTestCooler->setText(QApplication::translate("MainWindow", "Cooler", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Alarms", 0));
        label->setText(QApplication::translate("MainWindow", "Active alarms", 0));
        label_6->setText(QApplication::translate("MainWindow", "Historic alarms", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Machine control", 0));
        btnSetTime->setText(QApplication::translate("MainWindow", "Set time", 0));
        btnRestart->setText(QApplication::translate("MainWindow", "Restart", 0));
        btnReset->setText(QApplication::translate("MainWindow", "Factory Reset", 0));
        label_8->setText(QApplication::translate("MainWindow", "Config", 0));
        label_9->setText(QApplication::translate("MainWindow", "RFID", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Direct communication", 0));
        lineEdit->setInputMask(QString());
        label_2->setText(QApplication::translate("MainWindow", "Prot:", 0));
        lblData->setText(QApplication::translate("MainWindow", "null", 0));
        lblProt->setText(QApplication::translate("MainWindow", "null", 0));
        label_3->setText(QApplication::translate("MainWindow", "Type:", 0));
        lbltype->setText(QApplication::translate("MainWindow", "null", 0));
        label_4->setText(QApplication::translate("MainWindow", "Params:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "send", 0));
        lblParams->setText(QApplication::translate("MainWindow", "null", 0));
        label_5->setText(QApplication::translate("MainWindow", "Data:", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Communication", 0));
        btnReconnect->setText(QApplication::translate("MainWindow", "Reconnect", 0));
        btnResetLog->setText(QApplication::translate("MainWindow", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

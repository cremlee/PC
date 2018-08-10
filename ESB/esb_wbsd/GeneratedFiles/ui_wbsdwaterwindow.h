/********************************************************************************
** Form generated from reading UI file 'wbsdwaterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDWATERWINDOW_H
#define UI_WBSDWATERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDWaterWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *cboUseDescaleCounters;
    QComboBox *cboUseWaterFilterCounters;
    QLabel *lblDecalcCounter;
    QLabel *label_14;
    QLabel *lblWaterFilter4;
    QLabel *lblWaterFilter3;
    QLabel *boilerTempU;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label;
    QPushButton *btnResetDecalc;
    QFrame *line_2;
    QDoubleSpinBox *topTemp;
    QLabel *label_15;
    QPushButton *btnResetWaterfilter;
    QLabel *label_3;
    QLabel *lblDescaleFilter3;
    QLabel *boilerTempM;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_3;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lblWaterFilter2;
    QLabel *levelState;
    QLabel *lblWaterFilter1;
    QLabel *lblWaterFilterCounter;
    QLabel *lblDescaleFilter4;
    QFrame *line;
    QDoubleSpinBox *blockTemp;
    QLabel *label_4;
    QLabel *lblDescaleFilter1;
    QComboBox *cboBlockOnDecalc;
    QLabel *heatingState;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *cboBlockOnFilter;
    QLabel *lblDescaleFilter2;
    QDoubleSpinBox *spiFilterResetVal;
    QDoubleSpinBox *spiDecalcResetVal;
    QDoubleSpinBox *spiDecalcWarn;
    QDoubleSpinBox *spiFilterWarn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDWaterWindow)
    {
        if (WBSDWaterWindow->objectName().isEmpty())
            WBSDWaterWindow->setObjectName(QStringLiteral("WBSDWaterWindow"));
        WBSDWaterWindow->resize(841, 600);
        centralwidget = new QWidget(WBSDWaterWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 951, 532));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 20, 0, 20);
        cboUseDescaleCounters = new QComboBox(gridLayoutWidget);
        cboUseDescaleCounters->setObjectName(QStringLiteral("cboUseDescaleCounters"));

        gridLayout->addWidget(cboUseDescaleCounters, 15, 2, 1, 1);

        cboUseWaterFilterCounters = new QComboBox(gridLayoutWidget);
        cboUseWaterFilterCounters->setObjectName(QStringLiteral("cboUseWaterFilterCounters"));

        gridLayout->addWidget(cboUseWaterFilterCounters, 7, 2, 1, 1);

        lblDecalcCounter = new QLabel(gridLayoutWidget);
        lblDecalcCounter->setObjectName(QStringLiteral("lblDecalcCounter"));
        lblDecalcCounter->setEnabled(true);

        gridLayout->addWidget(lblDecalcCounter, 16, 2, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 15, 1, 1, 1);

        lblWaterFilter4 = new QLabel(gridLayoutWidget);
        lblWaterFilter4->setObjectName(QStringLiteral("lblWaterFilter4"));
        lblWaterFilter4->setEnabled(true);

        gridLayout->addWidget(lblWaterFilter4, 12, 1, 1, 1);

        lblWaterFilter3 = new QLabel(gridLayoutWidget);
        lblWaterFilter3->setObjectName(QStringLiteral("lblWaterFilter3"));
        lblWaterFilter3->setEnabled(true);

        gridLayout->addWidget(lblWaterFilter3, 10, 1, 1, 1);

        boilerTempU = new QLabel(gridLayoutWidget);
        boilerTempU->setObjectName(QStringLiteral("boilerTempU"));

        gridLayout->addWidget(boilerTempU, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 13, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        btnResetDecalc = new QPushButton(gridLayoutWidget);
        btnResetDecalc->setObjectName(QStringLiteral("btnResetDecalc"));
        btnResetDecalc->setEnabled(true);

        gridLayout->addWidget(btnResetDecalc, 26, 2, 1, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 14, 2, 1, 1);

        topTemp = new QDoubleSpinBox(gridLayoutWidget);
        topTemp->setObjectName(QStringLiteral("topTemp"));
        topTemp->setContextMenuPolicy(Qt::DefaultContextMenu);
        topTemp->setAutoFillBackground(true);
        topTemp->setStyleSheet(QStringLiteral("gridline-color: rgb(0, 0, 0);"));
        topTemp->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        topTemp->setDecimals(1);
        topTemp->setSingleStep(0.5);
        topTemp->setValue(100);

        gridLayout->addWidget(topTemp, 2, 2, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 7, 1, 1, 1);

        btnResetWaterfilter = new QPushButton(gridLayoutWidget);
        btnResetWaterfilter->setObjectName(QStringLiteral("btnResetWaterfilter"));
        btnResetWaterfilter->setEnabled(true);

        gridLayout->addWidget(btnResetWaterfilter, 13, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        lblDescaleFilter3 = new QLabel(gridLayoutWidget);
        lblDescaleFilter3->setObjectName(QStringLiteral("lblDescaleFilter3"));
        lblDescaleFilter3->setEnabled(true);

        gridLayout->addWidget(lblDescaleFilter3, 19, 1, 1, 1);

        boilerTempM = new QLabel(gridLayoutWidget);
        boilerTempM->setObjectName(QStringLiteral("boilerTempM"));

        gridLayout->addWidget(boilerTempM, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 26, 1, 1, 1);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 6, 1, 1, 1);

        line_4 = new QFrame(gridLayoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 6, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 10, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        lblWaterFilter2 = new QLabel(gridLayoutWidget);
        lblWaterFilter2->setObjectName(QStringLiteral("lblWaterFilter2"));
        lblWaterFilter2->setEnabled(true);

        gridLayout->addWidget(lblWaterFilter2, 9, 1, 1, 1);

        levelState = new QLabel(gridLayoutWidget);
        levelState->setObjectName(QStringLiteral("levelState"));

        gridLayout->addWidget(levelState, 5, 2, 1, 1);

        lblWaterFilter1 = new QLabel(gridLayoutWidget);
        lblWaterFilter1->setObjectName(QStringLiteral("lblWaterFilter1"));

        gridLayout->addWidget(lblWaterFilter1, 8, 1, 1, 1);

        lblWaterFilterCounter = new QLabel(gridLayoutWidget);
        lblWaterFilterCounter->setObjectName(QStringLiteral("lblWaterFilterCounter"));

        gridLayout->addWidget(lblWaterFilterCounter, 8, 2, 1, 1);

        lblDescaleFilter4 = new QLabel(gridLayoutWidget);
        lblDescaleFilter4->setObjectName(QStringLiteral("lblDescaleFilter4"));
        lblDescaleFilter4->setEnabled(true);

        gridLayout->addWidget(lblDescaleFilter4, 20, 1, 1, 1);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 14, 1, 1, 1);

        blockTemp = new QDoubleSpinBox(gridLayoutWidget);
        blockTemp->setObjectName(QStringLiteral("blockTemp"));
        blockTemp->setDecimals(1);
        blockTemp->setSingleStep(0.5);
        blockTemp->setValue(100);

        gridLayout->addWidget(blockTemp, 3, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        lblDescaleFilter1 = new QLabel(gridLayoutWidget);
        lblDescaleFilter1->setObjectName(QStringLiteral("lblDescaleFilter1"));
        lblDescaleFilter1->setEnabled(true);

        gridLayout->addWidget(lblDescaleFilter1, 16, 1, 1, 1);

        cboBlockOnDecalc = new QComboBox(gridLayoutWidget);
        cboBlockOnDecalc->setObjectName(QStringLiteral("cboBlockOnDecalc"));
        cboBlockOnDecalc->setEnabled(true);
        cboBlockOnDecalc->setEditable(false);

        gridLayout->addWidget(cboBlockOnDecalc, 17, 2, 1, 1);

        heatingState = new QLabel(gridLayoutWidget);
        heatingState->setObjectName(QStringLiteral("heatingState"));

        gridLayout->addWidget(heatingState, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 10, 0, 1, 1);

        cboBlockOnFilter = new QComboBox(gridLayoutWidget);
        cboBlockOnFilter->setObjectName(QStringLiteral("cboBlockOnFilter"));
        cboBlockOnFilter->setEnabled(true);
        cboBlockOnFilter->setEditable(false);

        gridLayout->addWidget(cboBlockOnFilter, 9, 2, 1, 1);

        lblDescaleFilter2 = new QLabel(gridLayoutWidget);
        lblDescaleFilter2->setObjectName(QStringLiteral("lblDescaleFilter2"));
        lblDescaleFilter2->setEnabled(true);

        gridLayout->addWidget(lblDescaleFilter2, 17, 1, 1, 1);

        spiFilterResetVal = new QDoubleSpinBox(gridLayoutWidget);
        spiFilterResetVal->setObjectName(QStringLiteral("spiFilterResetVal"));
        spiFilterResetVal->setMaximum(1e+07);

        gridLayout->addWidget(spiFilterResetVal, 12, 2, 1, 1);

        spiDecalcResetVal = new QDoubleSpinBox(gridLayoutWidget);
        spiDecalcResetVal->setObjectName(QStringLiteral("spiDecalcResetVal"));
        spiDecalcResetVal->setMaximum(99999);

        gridLayout->addWidget(spiDecalcResetVal, 20, 2, 1, 1);

        spiDecalcWarn = new QDoubleSpinBox(gridLayoutWidget);
        spiDecalcWarn->setObjectName(QStringLiteral("spiDecalcWarn"));

        gridLayout->addWidget(spiDecalcWarn, 19, 2, 1, 1);

        spiFilterWarn = new QDoubleSpinBox(gridLayoutWidget);
        spiFilterWarn->setObjectName(QStringLiteral("spiFilterWarn"));

        gridLayout->addWidget(spiFilterWarn, 10, 2, 1, 1);

        WBSDWaterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDWaterWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 841, 21));
        WBSDWaterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDWaterWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDWaterWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(topTemp, blockTemp);
        QWidget::setTabOrder(blockTemp, cboUseWaterFilterCounters);
        QWidget::setTabOrder(cboUseWaterFilterCounters, cboBlockOnFilter);
        QWidget::setTabOrder(cboBlockOnFilter, btnResetWaterfilter);
        QWidget::setTabOrder(btnResetWaterfilter, cboUseDescaleCounters);
        QWidget::setTabOrder(cboUseDescaleCounters, cboBlockOnDecalc);
        QWidget::setTabOrder(cboBlockOnDecalc, btnResetDecalc);

        retranslateUi(WBSDWaterWindow);

        QMetaObject::connectSlotsByName(WBSDWaterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDWaterWindow)
    {
        WBSDWaterWindow->setWindowTitle(QApplication::translate("WBSDWaterWindow", "Water system", 0));
        lblDecalcCounter->setText(QApplication::translate("WBSDWaterWindow", "0", 0));
        label_14->setText(QApplication::translate("WBSDWaterWindow", "Use descale counters(change it from false to true will  \n"
" set the descale counter reset value to the factory value 150L)", 0));
        lblWaterFilter4->setText(QApplication::translate("WBSDWaterWindow", "water counter reset value  (A reset of the dispenser \n"
"is needed to implement in the dispenser. A value of 0 \n"
"will set \342\200\234 use waterfilter counters\342\200\235 to Disabled)", 0));
        lblWaterFilter3->setText(QApplication::translate("WBSDWaterWindow", "Waterfilter warn level                   \357\274\210Liters\357\274\211  ", 0));
        boilerTempU->setText(QApplication::translate("WBSDWaterWindow", "-", 0));
        label_2->setText(QApplication::translate("WBSDWaterWindow", "Boiler temperature (UPPER)", 0));
        label->setText(QApplication::translate("WBSDWaterWindow", "Boiler temperature (MID)", 0));
        btnResetDecalc->setText(QApplication::translate("WBSDWaterWindow", "Start descaling routine", 0));
        label_15->setText(QApplication::translate("WBSDWaterWindow", "Use waterfilter counters (change it from Disabled to Enabled will  \n"
" set the Water counter reset value to the factory value 2000L)", 0));
        btnResetWaterfilter->setText(QApplication::translate("WBSDWaterWindow", "Reset waterfilter counter", 0));
        label_3->setText(QApplication::translate("WBSDWaterWindow", "Boiler temperature set-point (\302\260C)", 0));
        lblDescaleFilter3->setText(QApplication::translate("WBSDWaterWindow", "descale filter warn level               \357\274\210Liters\357\274\211  ", 0));
        boilerTempM->setText(QApplication::translate("WBSDWaterWindow", "-", 0));
        label_5->setText(QApplication::translate("WBSDWaterWindow", "Heating", 0));
        label_6->setText(QApplication::translate("WBSDWaterWindow", "Normal boiler level", 0));
        lblWaterFilter2->setText(QApplication::translate("WBSDWaterWindow", "Warning machine on Waterfilter counter reached", 0));
        levelState->setText(QApplication::translate("WBSDWaterWindow", "-", 0));
        lblWaterFilter1->setText(QApplication::translate("WBSDWaterWindow", "Waterfilter amount left counter     \357\274\210Liters\357\274\211", 0));
        lblWaterFilterCounter->setText(QApplication::translate("WBSDWaterWindow", "0", 0));
        lblDescaleFilter4->setText(QApplication::translate("WBSDWaterWindow", "descale counter reset value(A value of 0  will set \342\200\234 use descale counters\342\200\235 to Disabled)", 0));
        label_4->setText(QApplication::translate("WBSDWaterWindow", "Block temperature set-point (\302\260C)", 0));
        lblDescaleFilter1->setText(QApplication::translate("WBSDWaterWindow", "descale amount left counter          \357\274\210Liters\357\274\211  ", 0));
        cboBlockOnDecalc->clear();
        cboBlockOnDecalc->insertItems(0, QStringList()
         << QApplication::translate("WBSDWaterWindow", "Disable", 0)
        );
        heatingState->setText(QApplication::translate("WBSDWaterWindow", "-", 0));
        cboBlockOnFilter->clear();
        cboBlockOnFilter->insertItems(0, QStringList()
         << QApplication::translate("WBSDWaterWindow", "Disable", 0)
        );
        lblDescaleFilter2->setText(QApplication::translate("WBSDWaterWindow", "Warning machine on descale counter reached", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDWaterWindow: public Ui_WBSDWaterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDWATERWINDOW_H

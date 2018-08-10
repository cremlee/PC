/********************************************************************************
** Form generated from reading UI file 'bibrecipe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBRECIPE_H
#define UI_BIBRECIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BIBRecipe
{
public:
    QLabel *label_20;
    QSpinBox *spinBox;
    QLabel *label_23;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_25;
    QComboBox *cboDefSize_2;
    QSpinBox *spinBox_6;
    QLabel *label_11;
    QLabel *lblLBIBPulsesStrong;
    QSpinBox *spinBox_5;
    QLabel *label_15;
    QLabel *label_12;
    QLabel *label_19;
    QLabel *label_10;
    QLabel *label_16;
    QLabel *label_24;
    QLabel *lblLBIBPulsesNormal;
    QLabel *lblLBIBPulsesMild;
    QLabel *label;
    QLabel *label_17;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_8;
    QLabel *label_27;
    QLabel *lblLBIB_RTDVol;
    QLabel *label_21;
    QSlider *horizontalSlider;
    QSpinBox *spinBox_3;
    QLabel *label_14;
    QLabel *label_26;
    QSlider *horizontalSlider_2;
    QSpinBox *spinBox_4;
    QLabel *label_22;
    QLabel *label_13;

    void setupUi(QGroupBox *BIBRecipe)
    {
        if (BIBRecipe->objectName().isEmpty())
            BIBRecipe->setObjectName(QStringLiteral("BIBRecipe"));
        BIBRecipe->resize(350, 500);
        label_20 = new QLabel(BIBRecipe);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(270, 310, 61, 20));
        spinBox = new QSpinBox(BIBRecipe);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(130, 60, 61, 22));
        spinBox->setMaximum(100);
        spinBox->setValue(100);
        label_23 = new QLabel(BIBRecipe);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 390, 91, 16));
        label_18 = new QLabel(BIBRecipe);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 330, 46, 13));
        doubleSpinBox = new QDoubleSpinBox(BIBRecipe);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(130, 210, 71, 22));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMaximum(20);
        doubleSpinBox->setSingleStep(0.5);
        doubleSpinBox->setValue(10);
        label_25 = new QLabel(BIBRecipe);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(300, 370, 31, 16));
        cboDefSize_2 = new QComboBox(BIBRecipe);
        cboDefSize_2->setObjectName(QStringLiteral("cboDefSize_2"));
        cboDefSize_2->setGeometry(QRect(130, 170, 71, 22));
        spinBox_6 = new QSpinBox(BIBRecipe);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setGeometry(QRect(130, 270, 71, 22));
        label_11 = new QLabel(BIBRecipe);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 210, 91, 21));
        lblLBIBPulsesStrong = new QLabel(BIBRecipe);
        lblLBIBPulsesStrong->setObjectName(QStringLiteral("lblLBIBPulsesStrong"));
        lblLBIBPulsesStrong->setGeometry(QRect(200, 140, 121, 21));
        spinBox_5 = new QSpinBox(BIBRecipe);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setGeometry(QRect(130, 250, 71, 22));
        label_15 = new QLabel(BIBRecipe);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 170, 101, 21));
        label_12 = new QLabel(BIBRecipe);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 100, 71, 20));
        label_19 = new QLabel(BIBRecipe);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(110, 310, 61, 16));
        label_10 = new QLabel(BIBRecipe);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 60, 101, 21));
        label_16 = new QLabel(BIBRecipe);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 250, 111, 21));
        label_24 = new QLabel(BIBRecipe);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(120, 370, 61, 16));
        lblLBIBPulsesNormal = new QLabel(BIBRecipe);
        lblLBIBPulsesNormal->setObjectName(QStringLiteral("lblLBIBPulsesNormal"));
        lblLBIBPulsesNormal->setGeometry(QRect(200, 120, 121, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblLBIBPulsesNormal->setFont(font);
        lblLBIBPulsesMild = new QLabel(BIBRecipe);
        lblLBIBPulsesMild->setObjectName(QStringLiteral("lblLBIBPulsesMild"));
        lblLBIBPulsesMild->setGeometry(QRect(200, 100, 121, 21));
        label = new QLabel(BIBRecipe);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 91, 21));
        label_17 = new QLabel(BIBRecipe);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 270, 111, 21));
        spinBox_7 = new QSpinBox(BIBRecipe);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setGeometry(QRect(130, 420, 71, 22));
        spinBox_7->setMinimum(-5000);
        spinBox_7->setMaximum(5000);
        spinBox_7->setSingleStep(100);
        spinBox_2 = new QSpinBox(BIBRecipe);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(130, 100, 61, 22));
        spinBox_2->setValue(23);
        spinBox_8 = new QSpinBox(BIBRecipe);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setGeometry(QRect(130, 440, 71, 22));
        spinBox_8->setMaximum(9900);
        spinBox_8->setSingleStep(100);
        spinBox_8->setValue(2500);
        label_27 = new QLabel(BIBRecipe);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(210, 210, 111, 21));
        lblLBIB_RTDVol = new QLabel(BIBRecipe);
        lblLBIB_RTDVol->setObjectName(QStringLiteral("lblLBIB_RTDVol"));
        lblLBIB_RTDVol->setGeometry(QRect(200, 60, 61, 21));
        label_21 = new QLabel(BIBRecipe);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 420, 111, 21));
        horizontalSlider = new QSlider(BIBRecipe);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(130, 330, 191, 19));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox_3 = new QSpinBox(BIBRecipe);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(130, 120, 61, 22));
        spinBox_3->setFont(font);
        spinBox_3->setValue(23);
        label_14 = new QLabel(BIBRecipe);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 140, 81, 20));
        label_26 = new QLabel(BIBRecipe);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(130, 20, 46, 21));
        label_26->setFont(font);
        horizontalSlider_2 = new QSlider(BIBRecipe);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(130, 390, 191, 20));
        horizontalSlider_2->setMinimum(40);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        spinBox_4 = new QSpinBox(BIBRecipe);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(130, 140, 61, 22));
        spinBox_4->setValue(23);
        label_22 = new QLabel(BIBRecipe);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 440, 101, 16));
        label_13 = new QLabel(BIBRecipe);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 120, 91, 20));
        label_13->setFont(font);

        retranslateUi(BIBRecipe);

        QMetaObject::connectSlotsByName(BIBRecipe);
    } // setupUi

    void retranslateUi(QGroupBox *BIBRecipe)
    {
        BIBRecipe->setWindowTitle(QApplication::translate("BIBRecipe", "GroupBox", 0));
        BIBRecipe->setTitle(QApplication::translate("BIBRecipe", "BIB", 0));
        label_20->setText(QApplication::translate("BIBRecipe", "100% foam", 0));
        spinBox->setSuffix(QApplication::translate("BIBRecipe", "%", 0));
        label_23->setText(QApplication::translate("BIBRecipe", "Airpump speed", 0));
        label_18->setText(QApplication::translate("BIBRecipe", "Airvalve", 0));
        doubleSpinBox->setSuffix(QApplication::translate("BIBRecipe", "ml/s", 0));
        label_25->setText(QApplication::translate("BIBRecipe", "100%", 0));
        spinBox_6->setSuffix(QApplication::translate("BIBRecipe", "ms", 0));
        label_11->setText(QApplication::translate("BIBRecipe", "Target flow rate", 0));
        lblLBIBPulsesStrong->setText(QApplication::translate("BIBRecipe", "50 p. + 110 ml w.", 0));
        spinBox_5->setSuffix(QApplication::translate("BIBRecipe", "ms", 0));
        spinBox_5->setPrefix(QString());
        label_15->setText(QApplication::translate("BIBRecipe", "Default Strength", 0));
        label_12->setText(QApplication::translate("BIBRecipe", "Mild Ratio", 0));
        label_19->setText(QApplication::translate("BIBRecipe", "100% Black", 0));
        label_10->setText(QApplication::translate("BIBRecipe", "Percent of drink", 0));
        label_16->setText(QApplication::translate("BIBRecipe", "Ingridient start delay", 0));
        label_24->setText(QApplication::translate("BIBRecipe", "OFF  40%", 0));
        lblLBIBPulsesNormal->setText(QApplication::translate("BIBRecipe", "30 p. + 119 ml w.", 0));
        lblLBIBPulsesMild->setText(QApplication::translate("BIBRecipe", "10 p. + 121 ml w.", 0));
        label->setText(QApplication::translate("BIBRecipe", "Ingridient type", 0));
        label_17->setText(QApplication::translate("BIBRecipe", "Ingridient stop delay", 0));
        spinBox_7->setSuffix(QApplication::translate("BIBRecipe", "ms", 0));
        spinBox_7->setPrefix(QString());
        spinBox_2->setPrefix(QApplication::translate("BIBRecipe", "1:", 0));
        spinBox_8->setSuffix(QApplication::translate("BIBRecipe", "ms", 0));
        label_27->setText(QApplication::translate("BIBRecipe", "10,7 Sec disp time", 0));
        lblLBIB_RTDVol->setText(QApplication::translate("BIBRecipe", "125 ml", 0));
        label_21->setText(QApplication::translate("BIBRecipe", "Airpump start delay", 0));
        spinBox_3->setPrefix(QApplication::translate("BIBRecipe", "1:", 0));
        label_14->setText(QApplication::translate("BIBRecipe", "Strong Ratio", 0));
        label_26->setText(QApplication::translate("BIBRecipe", "COFFEE", 0));
        spinBox_4->setPrefix(QApplication::translate("BIBRecipe", "1:", 0));
        label_22->setText(QApplication::translate("BIBRecipe", "Airpump runlength", 0));
        label_13->setText(QApplication::translate("BIBRecipe", "Normal Ratio", 0));
    } // retranslateUi

};

namespace Ui {
    class BIBRecipe: public Ui_BIBRecipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBRECIPE_H

/********************************************************************************
** Form generated from reading UI file 'instrecipe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRECIPE_H
#define UI_INSTRECIPE_H

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

class Ui_InstRecipe
{
public:
    QLabel *label_74;
    QLabel *label_56;
    QSpinBox *spinBox_18;
    QLabel *label_59;
    QLabel *lblLBIBPulsesStrong_3;
    QSpinBox *spinBox_19;
    QLabel *label_66;
    QSpinBox *spinBox_10;
    QLabel *lblLBIB_RTDVol_3;
    QLabel *label_61;
    QSlider *horizontalSlider_6;
    QLabel *label_60;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_55;
    QLabel *lblLBIBPulsesNormal_3;
    QLabel *label_54;
    QLabel *lblLBIBPulsesMild_3;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_68;
    QComboBox *cboDefSize_4;
    QLabel *label_67;
    QLabel *label_58;
    QLabel *label_53;
    QSpinBox *spinBox_21;
    QDoubleSpinBox *doubleSpinBox_9;
    QLabel *label_71;
    QSpinBox *spinBox_22;
    QSpinBox *spinBox_20;
    QSpinBox *spinBox_17;
    QLabel *label_57;
    QLabel *label_70;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_65;
    QLabel *label_75;
    QLabel *label_69;

    void setupUi(QGroupBox *InstRecipe)
    {
        if (InstRecipe->objectName().isEmpty())
            InstRecipe->setObjectName(QStringLiteral("InstRecipe"));
        InstRecipe->resize(350, 500);
        label_74 = new QLabel(InstRecipe);
        label_74->setObjectName(QStringLiteral("label_74"));
        label_74->setGeometry(QRect(10, 440, 101, 16));
        label_56 = new QLabel(InstRecipe);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(10, 120, 91, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_56->setFont(font);
        spinBox_18 = new QSpinBox(InstRecipe);
        spinBox_18->setObjectName(QStringLiteral("spinBox_18"));
        spinBox_18->setGeometry(QRect(130, 270, 71, 22));
        label_59 = new QLabel(InstRecipe);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(10, 210, 91, 21));
        lblLBIBPulsesStrong_3 = new QLabel(InstRecipe);
        lblLBIBPulsesStrong_3->setObjectName(QStringLiteral("lblLBIBPulsesStrong_3"));
        lblLBIBPulsesStrong_3->setGeometry(QRect(200, 140, 121, 21));
        spinBox_19 = new QSpinBox(InstRecipe);
        spinBox_19->setObjectName(QStringLiteral("spinBox_19"));
        spinBox_19->setGeometry(QRect(130, 300, 71, 22));
        spinBox_19->setMinimum(-5000);
        spinBox_19->setMaximum(5000);
        spinBox_19->setSingleStep(100);
        label_66 = new QLabel(InstRecipe);
        label_66->setObjectName(QStringLiteral("label_66"));
        label_66->setGeometry(QRect(10, 320, 101, 16));
        spinBox_10 = new QSpinBox(InstRecipe);
        spinBox_10->setObjectName(QStringLiteral("spinBox_10"));
        spinBox_10->setGeometry(QRect(130, 60, 61, 22));
        spinBox_10->setMaximum(100);
        spinBox_10->setValue(100);
        lblLBIB_RTDVol_3 = new QLabel(InstRecipe);
        lblLBIB_RTDVol_3->setObjectName(QStringLiteral("lblLBIB_RTDVol_3"));
        lblLBIB_RTDVol_3->setGeometry(QRect(200, 60, 61, 21));
        label_61 = new QLabel(InstRecipe);
        label_61->setObjectName(QStringLiteral("label_61"));
        label_61->setGeometry(QRect(10, 270, 111, 21));
        horizontalSlider_6 = new QSlider(InstRecipe);
        horizontalSlider_6->setObjectName(QStringLiteral("horizontalSlider_6"));
        horizontalSlider_6->setGeometry(QRect(130, 370, 191, 20));
        horizontalSlider_6->setMinimum(40);
        horizontalSlider_6->setMaximum(100);
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        label_60 = new QLabel(InstRecipe);
        label_60->setObjectName(QStringLiteral("label_60"));
        label_60->setGeometry(QRect(10, 250, 111, 21));
        doubleSpinBox_8 = new QDoubleSpinBox(InstRecipe);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(130, 120, 62, 22));
        doubleSpinBox_8->setDecimals(0);
        doubleSpinBox_8->setMinimum(50);
        doubleSpinBox_8->setValue(85);
        label_55 = new QLabel(InstRecipe);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(10, 100, 71, 20));
        lblLBIBPulsesNormal_3 = new QLabel(InstRecipe);
        lblLBIBPulsesNormal_3->setObjectName(QStringLiteral("lblLBIBPulsesNormal_3"));
        lblLBIBPulsesNormal_3->setGeometry(QRect(200, 120, 121, 21));
        lblLBIBPulsesNormal_3->setFont(font);
        label_54 = new QLabel(InstRecipe);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(10, 60, 101, 21));
        lblLBIBPulsesMild_3 = new QLabel(InstRecipe);
        lblLBIBPulsesMild_3->setObjectName(QStringLiteral("lblLBIBPulsesMild_3"));
        lblLBIBPulsesMild_3->setGeometry(QRect(200, 100, 121, 21));
        doubleSpinBox_7 = new QDoubleSpinBox(InstRecipe);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(130, 100, 62, 22));
        doubleSpinBox_7->setDecimals(0);
        doubleSpinBox_7->setMinimum(50);
        doubleSpinBox_7->setValue(70);
        label_68 = new QLabel(InstRecipe);
        label_68->setObjectName(QStringLiteral("label_68"));
        label_68->setGeometry(QRect(120, 350, 61, 16));
        cboDefSize_4 = new QComboBox(InstRecipe);
        cboDefSize_4->setObjectName(QStringLiteral("cboDefSize_4"));
        cboDefSize_4->setGeometry(QRect(130, 170, 71, 22));
        label_67 = new QLabel(InstRecipe);
        label_67->setObjectName(QStringLiteral("label_67"));
        label_67->setGeometry(QRect(10, 370, 91, 16));
        label_58 = new QLabel(InstRecipe);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setGeometry(QRect(10, 170, 101, 21));
        label_53 = new QLabel(InstRecipe);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(10, 20, 91, 21));
        spinBox_21 = new QSpinBox(InstRecipe);
        spinBox_21->setObjectName(QStringLiteral("spinBox_21"));
        spinBox_21->setGeometry(QRect(130, 420, 71, 22));
        spinBox_21->setMinimum(-5000);
        spinBox_21->setMaximum(5000);
        spinBox_21->setSingleStep(100);
        doubleSpinBox_9 = new QDoubleSpinBox(InstRecipe);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(130, 140, 62, 22));
        doubleSpinBox_9->setDecimals(0);
        doubleSpinBox_9->setMinimum(50);
        doubleSpinBox_9->setSingleStep(1);
        doubleSpinBox_9->setValue(100);
        label_71 = new QLabel(InstRecipe);
        label_71->setObjectName(QStringLiteral("label_71"));
        label_71->setGeometry(QRect(210, 210, 111, 21));
        spinBox_22 = new QSpinBox(InstRecipe);
        spinBox_22->setObjectName(QStringLiteral("spinBox_22"));
        spinBox_22->setGeometry(QRect(130, 440, 71, 22));
        spinBox_22->setMaximum(9900);
        spinBox_22->setSingleStep(100);
        spinBox_22->setValue(2500);
        spinBox_20 = new QSpinBox(InstRecipe);
        spinBox_20->setObjectName(QStringLiteral("spinBox_20"));
        spinBox_20->setGeometry(QRect(130, 320, 71, 22));
        spinBox_20->setMaximum(9900);
        spinBox_20->setSingleStep(100);
        spinBox_20->setValue(2500);
        spinBox_17 = new QSpinBox(InstRecipe);
        spinBox_17->setObjectName(QStringLiteral("spinBox_17"));
        spinBox_17->setGeometry(QRect(130, 250, 71, 22));
        label_57 = new QLabel(InstRecipe);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(10, 140, 81, 20));
        label_70 = new QLabel(InstRecipe);
        label_70->setObjectName(QStringLiteral("label_70"));
        label_70->setGeometry(QRect(130, 20, 181, 21));
        label_70->setFont(font);
        doubleSpinBox_6 = new QDoubleSpinBox(InstRecipe);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(130, 210, 71, 22));
        doubleSpinBox_6->setDecimals(1);
        doubleSpinBox_6->setMaximum(20);
        doubleSpinBox_6->setSingleStep(0.5);
        doubleSpinBox_6->setValue(10);
        label_65 = new QLabel(InstRecipe);
        label_65->setObjectName(QStringLiteral("label_65"));
        label_65->setGeometry(QRect(10, 300, 111, 21));
        label_75 = new QLabel(InstRecipe);
        label_75->setObjectName(QStringLiteral("label_75"));
        label_75->setGeometry(QRect(10, 420, 111, 21));
        label_69 = new QLabel(InstRecipe);
        label_69->setObjectName(QStringLiteral("label_69"));
        label_69->setGeometry(QRect(300, 350, 31, 16));

        retranslateUi(InstRecipe);

        QMetaObject::connectSlotsByName(InstRecipe);
    } // setupUi

    void retranslateUi(QGroupBox *InstRecipe)
    {
        InstRecipe->setWindowTitle(QApplication::translate("InstRecipe", "GroupBox", 0));
        InstRecipe->setTitle(QApplication::translate("InstRecipe", "Instant", 0));
        label_74->setText(QApplication::translate("InstRecipe", "Fan runlength", 0));
        label_56->setText(QApplication::translate("InstRecipe", "Normal speed", 0));
        spinBox_18->setSuffix(QApplication::translate("InstRecipe", "ms", 0));
        label_59->setText(QApplication::translate("InstRecipe", "Target flow rate", 0));
        lblLBIBPulsesStrong_3->setText(QApplication::translate("InstRecipe", "50 p. + 50 ml w.", 0));
        spinBox_19->setSuffix(QApplication::translate("InstRecipe", "ms", 0));
        spinBox_19->setPrefix(QString());
        label_66->setText(QApplication::translate("InstRecipe", "Mixer stop delay", 0));
        spinBox_10->setSuffix(QApplication::translate("InstRecipe", "%", 0));
        lblLBIB_RTDVol_3->setText(QApplication::translate("InstRecipe", "125 ml", 0));
        label_61->setText(QApplication::translate("InstRecipe", "Ingridient stop delay", 0));
        label_60->setText(QApplication::translate("InstRecipe", "Ingridient start delay", 0));
        doubleSpinBox_8->setPrefix(QString());
        doubleSpinBox_8->setSuffix(QApplication::translate("InstRecipe", "%", 0));
        label_55->setText(QApplication::translate("InstRecipe", "Mild speed", 0));
        lblLBIBPulsesNormal_3->setText(QApplication::translate("InstRecipe", "300 p. + 75 ml w.", 0));
        label_54->setText(QApplication::translate("InstRecipe", "Percent of drink", 0));
        lblLBIBPulsesMild_3->setText(QApplication::translate("InstRecipe", "100 p. + 95 ml w.", 0));
        doubleSpinBox_7->setPrefix(QString());
        doubleSpinBox_7->setSuffix(QApplication::translate("InstRecipe", "%", 0));
        label_68->setText(QApplication::translate("InstRecipe", "OFF  40%", 0));
        label_67->setText(QApplication::translate("InstRecipe", "Mixer speed", 0));
        label_58->setText(QApplication::translate("InstRecipe", "Default Strength", 0));
        label_53->setText(QApplication::translate("InstRecipe", "Ingridient type", 0));
        spinBox_21->setSuffix(QApplication::translate("InstRecipe", "ms", 0));
        spinBox_21->setPrefix(QString());
        doubleSpinBox_9->setPrefix(QString());
        doubleSpinBox_9->setSuffix(QApplication::translate("InstRecipe", "%", 0));
        label_71->setText(QApplication::translate("InstRecipe", "10,7 Sec disp time", 0));
        spinBox_22->setSuffix(QApplication::translate("InstRecipe", "ms", 0));
        spinBox_20->setSuffix(QApplication::translate("InstRecipe", "ms", 0));
        spinBox_17->setSuffix(QApplication::translate("InstRecipe", "ms", 0));
        spinBox_17->setPrefix(QString());
        label_57->setText(QApplication::translate("InstRecipe", "Strong speed", 0));
        label_70->setText(QApplication::translate("InstRecipe", "INSTANT", 0));
        doubleSpinBox_6->setSuffix(QApplication::translate("InstRecipe", "ml/s", 0));
        label_65->setText(QApplication::translate("InstRecipe", "Mixer start delay", 0));
        label_75->setText(QApplication::translate("InstRecipe", "Fan start delay", 0));
        label_69->setText(QApplication::translate("InstRecipe", "100%", 0));
    } // retranslateUi

};

namespace Ui {
    class InstRecipe: public Ui_InstRecipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRECIPE_H

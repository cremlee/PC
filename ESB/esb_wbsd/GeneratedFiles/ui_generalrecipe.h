/********************************************************************************
** Form generated from reading UI file 'generalrecipe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALRECIPE_H
#define UI_GENERALRECIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_GeneralRecipe
{
public:
    QLabel *lblDeAirTimeValue;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_7;
    QSpinBox *spRTDLarge_3;
    QComboBox *cboSeq1;
    QLabel *label_6;
    QSpinBox *spPrTime;
    QLabel *label_5;
    QSpinBox *spRTDLarge;
    QLabel *lblDeAirTime;
    QComboBox *cboDefSize;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *cboSeq3;
    QSpinBox *spRTDLarge_2;
    QLabel *label_9;
    QComboBox *cboSeq2;
    QLabel *label;
    QLabel *lblKey;
    QSpinBox *spinBox;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *txtRecipeName;

    void setupUi(QGroupBox *GeneralRecipe)
    {
        if (GeneralRecipe->objectName().isEmpty())
            GeneralRecipe->setObjectName(QStringLiteral("GeneralRecipe"));
        GeneralRecipe->resize(350, 500);
        lblDeAirTimeValue = new QLabel(GeneralRecipe);
        lblDeAirTimeValue->setObjectName(QStringLiteral("lblDeAirTimeValue"));
        lblDeAirTimeValue->setGeometry(QRect(200, 120, 46, 21));
        label_8 = new QLabel(GeneralRecipe);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 460, 151, 21));
        label_4 = new QLabel(GeneralRecipe);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 200, 121, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_7 = new QLabel(GeneralRecipe);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 430, 151, 21));
        spRTDLarge_3 = new QSpinBox(GeneralRecipe);
        spRTDLarge_3->setObjectName(QStringLiteral("spRTDLarge_3"));
        spRTDLarge_3->setGeometry(QRect(200, 220, 111, 22));
        spRTDLarge_3->setMaximum(1500);
        spRTDLarge_3->setSingleStep(5);
        spRTDLarge_3->setValue(150);
        cboSeq1 = new QComboBox(GeneralRecipe);
        cboSeq1->setObjectName(QStringLiteral("cboSeq1"));
        cboSeq1->setGeometry(QRect(200, 400, 111, 22));
        label_6 = new QLabel(GeneralRecipe);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 400, 141, 21));
        spPrTime = new QSpinBox(GeneralRecipe);
        spPrTime->setObjectName(QStringLiteral("spPrTime"));
        spPrTime->setGeometry(QRect(200, 150, 111, 22));
        spPrTime->setMaximum(3000);
        spPrTime->setSingleStep(100);
        spPrTime->setValue(300);
        label_5 = new QLabel(GeneralRecipe);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 220, 111, 20));
        spRTDLarge = new QSpinBox(GeneralRecipe);
        spRTDLarge->setObjectName(QStringLiteral("spRTDLarge"));
        spRTDLarge->setGeometry(QRect(200, 180, 111, 22));
        spRTDLarge->setMaximum(1500);
        spRTDLarge->setSingleStep(5);
        spRTDLarge->setValue(100);
        lblDeAirTime = new QLabel(GeneralRecipe);
        lblDeAirTime->setObjectName(QStringLiteral("lblDeAirTime"));
        lblDeAirTime->setGeometry(QRect(10, 120, 91, 21));
        cboDefSize = new QComboBox(GeneralRecipe);
        cboDefSize->setObjectName(QStringLiteral("cboDefSize"));
        cboDefSize->setGeometry(QRect(200, 250, 111, 22));
        label_3 = new QLabel(GeneralRecipe);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 180, 131, 20));
        label_2 = new QLabel(GeneralRecipe);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 150, 121, 21));
        cboSeq3 = new QComboBox(GeneralRecipe);
        cboSeq3->setObjectName(QStringLiteral("cboSeq3"));
        cboSeq3->setGeometry(QRect(200, 460, 111, 22));
        spRTDLarge_2 = new QSpinBox(GeneralRecipe);
        spRTDLarge_2->setObjectName(QStringLiteral("spRTDLarge_2"));
        spRTDLarge_2->setGeometry(QRect(200, 200, 111, 22));
        spRTDLarge_2->setFont(font);
        spRTDLarge_2->setMaximum(1500);
        spRTDLarge_2->setSingleStep(5);
        spRTDLarge_2->setValue(125);
        label_9 = new QLabel(GeneralRecipe);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 250, 101, 21));
        cboSeq2 = new QComboBox(GeneralRecipe);
        cboSeq2->setObjectName(QStringLiteral("cboSeq2"));
        cboSeq2->setGeometry(QRect(200, 430, 111, 22));
        label = new QLabel(GeneralRecipe);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 91, 21));
        lblKey = new QLabel(GeneralRecipe);
        lblKey->setObjectName(QStringLiteral("lblKey"));
        lblKey->setGeometry(QRect(200, 90, 111, 16));
        spinBox = new QSpinBox(GeneralRecipe);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(200, 30, 61, 22));
        spinBox->setValue(6);
        label_12 = new QLabel(GeneralRecipe);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 60, 46, 13));
        label_13 = new QLabel(GeneralRecipe);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 90, 131, 16));
        txtRecipeName = new QLineEdit(GeneralRecipe);
        txtRecipeName->setObjectName(QStringLiteral("txtRecipeName"));
        txtRecipeName->setGeometry(QRect(200, 60, 113, 20));

        retranslateUi(GeneralRecipe);

        QMetaObject::connectSlotsByName(GeneralRecipe);
    } // setupUi

    void retranslateUi(QGroupBox *GeneralRecipe)
    {
        GeneralRecipe->setWindowTitle(QApplication::translate("GeneralRecipe", "GroupBox", 0));
        GeneralRecipe->setTitle(QApplication::translate("GeneralRecipe", "General Settings", 0));
        lblDeAirTimeValue->setText(QApplication::translate("GeneralRecipe", "1500 ms", 0));
        label_8->setText(QApplication::translate("GeneralRecipe", "Sequence 3", 0));
        label_4->setText(QApplication::translate("GeneralRecipe", "RTD Volume Medium", 0));
        label_7->setText(QApplication::translate("GeneralRecipe", "Sequence 2", 0));
        spRTDLarge_3->setSuffix(QApplication::translate("GeneralRecipe", "ml", 0));
        label_6->setText(QApplication::translate("GeneralRecipe", "Sequence 1", 0));
        spPrTime->setSuffix(QApplication::translate("GeneralRecipe", "ms", 0));
        label_5->setText(QApplication::translate("GeneralRecipe", "RTD Volume Large", 0));
        spRTDLarge->setSuffix(QApplication::translate("GeneralRecipe", "ml", 0));
        lblDeAirTime->setText(QApplication::translate("GeneralRecipe", "De air time (DA)", 0));
        label_3->setText(QApplication::translate("GeneralRecipe", "RTD Volume Small", 0));
        label_2->setText(QApplication::translate("GeneralRecipe", "Preassure time (PT)", 0));
        spRTDLarge_2->setSuffix(QApplication::translate("GeneralRecipe", "ml", 0));
        label_9->setText(QApplication::translate("GeneralRecipe", "Default Size", 0));
        label->setText(QApplication::translate("GeneralRecipe", "Recipe Number", 0));
        lblKey->setText(QApplication::translate("GeneralRecipe", "TextLabel", 0));
        label_12->setText(QApplication::translate("GeneralRecipe", "Name", 0));
        label_13->setText(QApplication::translate("GeneralRecipe", "Generated key SEQ+FL16", 0));
        txtRecipeName->setText(QApplication::translate("GeneralRecipe", "Coffee", 0));
    } // retranslateUi

};

namespace Ui {
    class GeneralRecipe: public Ui_GeneralRecipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALRECIPE_H

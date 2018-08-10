/********************************************************************************
** Form generated from reading UI file 'frmlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOGIN_H
#define UI_FRMLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_frmLogin
{
public:
    QGroupBox *groupBox;
    QComboBox *txtUserName;
    QLabel *labUserName;
    QPushButton *btnLogin;
    QLabel *labCompany;
    QLabel *labTitle;
    QGroupBox *gboxSoftKey;
    QPushButton *btn0;
    QPushButton *btn7;
    QPushButton *btn6;
    QPushButton *btnJ;
    QPushButton *btnY;
    QPushButton *btnK;
    QPushButton *btnG;
    QPushButton *btn3;
    QPushButton *btn2;
    QPushButton *btnQ;
    QPushButton *btnA;
    QPushButton *btnZ;
    QPushButton *btnP;
    QPushButton *btn4;
    QPushButton *btnF;
    QPushButton *btnC;
    QPushButton *btn9;
    QPushButton *btnO;
    QPushButton *btn1;
    QPushButton *btnR;
    QPushButton *btnN;
    QPushButton *btn8;
    QPushButton *btnH;
    QPushButton *btnU;
    QPushButton *btnV;
    QPushButton *btnX;
    QPushButton *btnE;
    QPushButton *btnI;
    QPushButton *btnS;
    QPushButton *btnW;
    QPushButton *btnL;
    QPushButton *btnT;
    QPushButton *btnB;
    QPushButton *btnD;
    QPushButton *btnM;
    QPushButton *btn5;
    QPushButton *btnDelete;

    void setupUi(QDialog *frmLogin)
    {
        if (frmLogin->objectName().isEmpty())
            frmLogin->setObjectName(QStringLiteral("frmLogin"));
        frmLogin->resize(439, 229);
        QIcon icon;
        icon.addFile(QStringLiteral(":/mainpics/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        frmLogin->setWindowIcon(icon);
        frmLogin->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(170, 255, 255);\n"
""));
        groupBox = new QGroupBox(frmLogin);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 421, 141));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 255);"));
        txtUserName = new QComboBox(groupBox);
        txtUserName->setObjectName(QStringLiteral("txtUserName"));
        txtUserName->setGeometry(QRect(140, 40, 141, 28));
        labUserName = new QLabel(groupBox);
        labUserName->setObjectName(QStringLiteral("labUserName"));
        labUserName->setGeometry(QRect(20, 40, 101, 31));
        btnLogin = new QPushButton(groupBox);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));
        btnLogin->setGeometry(QRect(300, 40, 101, 28));
        btnLogin->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLogin->setIcon(icon1);
        btnLogin->setIconSize(QSize(20, 20));
        labCompany = new QLabel(groupBox);
        labCompany->setObjectName(QStringLiteral("labCompany"));
        labCompany->setGeometry(QRect(20, 100, 381, 31));
        labTitle = new QLabel(frmLogin);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        labTitle->setGeometry(QRect(3, 0, 431, 70));
        labTitle->setAlignment(Qt::AlignCenter);
        gboxSoftKey = new QGroupBox(frmLogin);
        gboxSoftKey->setObjectName(QStringLiteral("gboxSoftKey"));
        gboxSoftKey->setGeometry(QRect(30, 230, 261, 61));
        gboxSoftKey->setAutoFillBackground(false);
        gboxSoftKey->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	font: 12pt \"\345\256\213\344\275\223\";\n"
"}\n"
"QPushButton {\n"
"    border: 1px solid #333333;    \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #111111;\n"
"    border-color: #333333;\n"
"    color: yellow;\n"
"}"));
        btn0 = new QPushButton(gboxSoftKey);
        btn0->setObjectName(QStringLiteral("btn0"));
        btn0->setGeometry(QRect(180, 20, 21, 21));
        btn0->setCursor(QCursor(Qt::PointingHandCursor));
        btn7 = new QPushButton(gboxSoftKey);
        btn7->setObjectName(QStringLiteral("btn7"));
        btn7->setGeometry(QRect(200, 40, 21, 21));
        btn7->setCursor(QCursor(Qt::PointingHandCursor));
        btn6 = new QPushButton(gboxSoftKey);
        btn6->setObjectName(QStringLiteral("btn6"));
        btn6->setGeometry(QRect(180, 40, 21, 21));
        btn6->setCursor(QCursor(Qt::PointingHandCursor));
        btnJ = new QPushButton(gboxSoftKey);
        btnJ->setObjectName(QStringLiteral("btnJ"));
        btnJ->setGeometry(QRect(120, 20, 21, 21));
        btnJ->setCursor(QCursor(Qt::PointingHandCursor));
        btnY = new QPushButton(gboxSoftKey);
        btnY->setObjectName(QStringLiteral("btnY"));
        btnY->setGeometry(QRect(100, 0, 21, 21));
        btnY->setCursor(QCursor(Qt::PointingHandCursor));
        btnK = new QPushButton(gboxSoftKey);
        btnK->setObjectName(QStringLiteral("btnK"));
        btnK->setGeometry(QRect(140, 20, 21, 21));
        btnK->setCursor(QCursor(Qt::PointingHandCursor));
        btnG = new QPushButton(gboxSoftKey);
        btnG->setObjectName(QStringLiteral("btnG"));
        btnG->setGeometry(QRect(80, 20, 21, 21));
        btnG->setCursor(QCursor(Qt::PointingHandCursor));
        btn3 = new QPushButton(gboxSoftKey);
        btn3->setObjectName(QStringLiteral("btn3"));
        btn3->setGeometry(QRect(240, 20, 21, 21));
        btn3->setCursor(QCursor(Qt::PointingHandCursor));
        btn2 = new QPushButton(gboxSoftKey);
        btn2->setObjectName(QStringLiteral("btn2"));
        btn2->setGeometry(QRect(220, 20, 21, 21));
        btn2->setCursor(QCursor(Qt::PointingHandCursor));
        btnQ = new QPushButton(gboxSoftKey);
        btnQ->setObjectName(QStringLiteral("btnQ"));
        btnQ->setGeometry(QRect(0, 0, 21, 21));
        btnQ->setCursor(QCursor(Qt::PointingHandCursor));
        btnA = new QPushButton(gboxSoftKey);
        btnA->setObjectName(QStringLiteral("btnA"));
        btnA->setGeometry(QRect(0, 20, 21, 21));
        btnA->setCursor(QCursor(Qt::PointingHandCursor));
        btnZ = new QPushButton(gboxSoftKey);
        btnZ->setObjectName(QStringLiteral("btnZ"));
        btnZ->setGeometry(QRect(0, 40, 21, 21));
        btnZ->setCursor(QCursor(Qt::PointingHandCursor));
        btnP = new QPushButton(gboxSoftKey);
        btnP->setObjectName(QStringLiteral("btnP"));
        btnP->setGeometry(QRect(180, 0, 21, 21));
        btnP->setCursor(QCursor(Qt::PointingHandCursor));
        btn4 = new QPushButton(gboxSoftKey);
        btn4->setObjectName(QStringLiteral("btn4"));
        btn4->setGeometry(QRect(140, 40, 21, 21));
        btn4->setCursor(QCursor(Qt::PointingHandCursor));
        btnF = new QPushButton(gboxSoftKey);
        btnF->setObjectName(QStringLiteral("btnF"));
        btnF->setGeometry(QRect(60, 20, 21, 21));
        btnF->setCursor(QCursor(Qt::PointingHandCursor));
        btnC = new QPushButton(gboxSoftKey);
        btnC->setObjectName(QStringLiteral("btnC"));
        btnC->setGeometry(QRect(40, 40, 21, 21));
        btnC->setCursor(QCursor(Qt::PointingHandCursor));
        btn9 = new QPushButton(gboxSoftKey);
        btn9->setObjectName(QStringLiteral("btn9"));
        btn9->setGeometry(QRect(240, 40, 21, 21));
        btn9->setCursor(QCursor(Qt::PointingHandCursor));
        btnO = new QPushButton(gboxSoftKey);
        btnO->setObjectName(QStringLiteral("btnO"));
        btnO->setGeometry(QRect(160, 0, 21, 21));
        btnO->setCursor(QCursor(Qt::PointingHandCursor));
        btn1 = new QPushButton(gboxSoftKey);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setGeometry(QRect(200, 20, 21, 21));
        btn1->setCursor(QCursor(Qt::PointingHandCursor));
        btnR = new QPushButton(gboxSoftKey);
        btnR->setObjectName(QStringLiteral("btnR"));
        btnR->setGeometry(QRect(60, 0, 21, 21));
        btnR->setCursor(QCursor(Qt::PointingHandCursor));
        btnN = new QPushButton(gboxSoftKey);
        btnN->setObjectName(QStringLiteral("btnN"));
        btnN->setGeometry(QRect(100, 40, 21, 21));
        btnN->setCursor(QCursor(Qt::PointingHandCursor));
        btn8 = new QPushButton(gboxSoftKey);
        btn8->setObjectName(QStringLiteral("btn8"));
        btn8->setGeometry(QRect(220, 40, 21, 21));
        btn8->setCursor(QCursor(Qt::PointingHandCursor));
        btnH = new QPushButton(gboxSoftKey);
        btnH->setObjectName(QStringLiteral("btnH"));
        btnH->setGeometry(QRect(100, 20, 21, 21));
        btnH->setCursor(QCursor(Qt::PointingHandCursor));
        btnU = new QPushButton(gboxSoftKey);
        btnU->setObjectName(QStringLiteral("btnU"));
        btnU->setGeometry(QRect(120, 0, 21, 21));
        btnU->setCursor(QCursor(Qt::PointingHandCursor));
        btnV = new QPushButton(gboxSoftKey);
        btnV->setObjectName(QStringLiteral("btnV"));
        btnV->setGeometry(QRect(60, 40, 21, 21));
        btnV->setCursor(QCursor(Qt::PointingHandCursor));
        btnX = new QPushButton(gboxSoftKey);
        btnX->setObjectName(QStringLiteral("btnX"));
        btnX->setGeometry(QRect(20, 40, 21, 21));
        btnX->setCursor(QCursor(Qt::PointingHandCursor));
        btnE = new QPushButton(gboxSoftKey);
        btnE->setObjectName(QStringLiteral("btnE"));
        btnE->setGeometry(QRect(40, 0, 21, 21));
        btnE->setCursor(QCursor(Qt::PointingHandCursor));
        btnI = new QPushButton(gboxSoftKey);
        btnI->setObjectName(QStringLiteral("btnI"));
        btnI->setGeometry(QRect(140, 0, 21, 21));
        btnI->setCursor(QCursor(Qt::PointingHandCursor));
        btnS = new QPushButton(gboxSoftKey);
        btnS->setObjectName(QStringLiteral("btnS"));
        btnS->setGeometry(QRect(20, 20, 21, 21));
        btnS->setCursor(QCursor(Qt::PointingHandCursor));
        btnW = new QPushButton(gboxSoftKey);
        btnW->setObjectName(QStringLiteral("btnW"));
        btnW->setGeometry(QRect(20, 0, 21, 21));
        btnW->setCursor(QCursor(Qt::PointingHandCursor));
        btnL = new QPushButton(gboxSoftKey);
        btnL->setObjectName(QStringLiteral("btnL"));
        btnL->setGeometry(QRect(160, 20, 21, 21));
        btnL->setCursor(QCursor(Qt::PointingHandCursor));
        btnT = new QPushButton(gboxSoftKey);
        btnT->setObjectName(QStringLiteral("btnT"));
        btnT->setGeometry(QRect(80, 0, 21, 21));
        btnT->setCursor(QCursor(Qt::PointingHandCursor));
        btnB = new QPushButton(gboxSoftKey);
        btnB->setObjectName(QStringLiteral("btnB"));
        btnB->setGeometry(QRect(80, 40, 21, 21));
        btnB->setCursor(QCursor(Qt::PointingHandCursor));
        btnD = new QPushButton(gboxSoftKey);
        btnD->setObjectName(QStringLiteral("btnD"));
        btnD->setGeometry(QRect(40, 20, 21, 21));
        btnD->setCursor(QCursor(Qt::PointingHandCursor));
        btnM = new QPushButton(gboxSoftKey);
        btnM->setObjectName(QStringLiteral("btnM"));
        btnM->setGeometry(QRect(120, 40, 21, 21));
        btnM->setCursor(QCursor(Qt::PointingHandCursor));
        btn5 = new QPushButton(gboxSoftKey);
        btn5->setObjectName(QStringLiteral("btn5"));
        btn5->setGeometry(QRect(160, 40, 21, 21));
        btn5->setCursor(QCursor(Qt::PointingHandCursor));
        btnDelete = new QPushButton(gboxSoftKey);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(200, 0, 61, 21));
        btnDelete->setCursor(QCursor(Qt::PointingHandCursor));
        QWidget::setTabOrder(txtUserName, btnLogin);

        retranslateUi(frmLogin);

        QMetaObject::connectSlotsByName(frmLogin);
    } // setupUi

    void retranslateUi(QDialog *frmLogin)
    {
        frmLogin->setWindowTitle(QApplication::translate("frmLogin", "Country Select", 0));
        groupBox->setTitle(QString());
        txtUserName->clear();
        txtUserName->insertItems(0, QStringList()
         << QApplication::translate("frmLogin", "USA", 0)
         << QApplication::translate("frmLogin", "Other", 0)
        );
        labUserName->setText(QApplication::translate("frmLogin", "Select country", 0));
        btnLogin->setText(QApplication::translate("frmLogin", "OK", 0));
        labCompany->setText(QApplication::translate("frmLogin", "Support By\357\274\232Crem", 0));
        labTitle->setText(QApplication::translate("frmLogin", "WBSD-Compact_PC_Tool", 0));
        gboxSoftKey->setTitle(QString());
        btn0->setText(QApplication::translate("frmLogin", "0", 0));
        btn7->setText(QApplication::translate("frmLogin", "7", 0));
        btn6->setText(QApplication::translate("frmLogin", "6", 0));
        btnJ->setText(QApplication::translate("frmLogin", "J", 0));
        btnY->setText(QApplication::translate("frmLogin", "Y", 0));
        btnK->setText(QApplication::translate("frmLogin", "K", 0));
        btnG->setText(QApplication::translate("frmLogin", "G", 0));
        btn3->setText(QApplication::translate("frmLogin", "3", 0));
        btn2->setText(QApplication::translate("frmLogin", "2", 0));
        btnQ->setText(QApplication::translate("frmLogin", "Q", 0));
        btnA->setText(QApplication::translate("frmLogin", "A", 0));
        btnZ->setText(QApplication::translate("frmLogin", "Z", 0));
        btnP->setText(QApplication::translate("frmLogin", "P", 0));
        btn4->setText(QApplication::translate("frmLogin", "4", 0));
        btnF->setText(QApplication::translate("frmLogin", "F", 0));
        btnC->setText(QApplication::translate("frmLogin", "C", 0));
        btn9->setText(QApplication::translate("frmLogin", "9", 0));
        btnO->setText(QApplication::translate("frmLogin", "O", 0));
        btn1->setText(QApplication::translate("frmLogin", "1", 0));
        btnR->setText(QApplication::translate("frmLogin", "R", 0));
        btnN->setText(QApplication::translate("frmLogin", "N", 0));
        btn8->setText(QApplication::translate("frmLogin", "8", 0));
        btnH->setText(QApplication::translate("frmLogin", "H", 0));
        btnU->setText(QApplication::translate("frmLogin", "U", 0));
        btnV->setText(QApplication::translate("frmLogin", "V", 0));
        btnX->setText(QApplication::translate("frmLogin", "X", 0));
        btnE->setText(QApplication::translate("frmLogin", "E", 0));
        btnI->setText(QApplication::translate("frmLogin", "I", 0));
        btnS->setText(QApplication::translate("frmLogin", "S", 0));
        btnW->setText(QApplication::translate("frmLogin", "W", 0));
        btnL->setText(QApplication::translate("frmLogin", "L", 0));
        btnT->setText(QApplication::translate("frmLogin", "T", 0));
        btnB->setText(QApplication::translate("frmLogin", "B", 0));
        btnD->setText(QApplication::translate("frmLogin", "D", 0));
        btnM->setText(QApplication::translate("frmLogin", "M", 0));
        btn5->setText(QApplication::translate("frmLogin", "5", 0));
        btnDelete->setText(QApplication::translate("frmLogin", "\342\206\220", 0));
    } // retranslateUi

};

namespace Ui {
    class frmLogin: public Ui_frmLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOGIN_H

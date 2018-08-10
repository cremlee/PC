/********************************************************************************
** Form generated from reading UI file 'wbsdstartpage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDSTARTPAGE_H
#define UI_WBSDSTARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDStartPage
{
public:
    QGridLayout *gridLayout;
    QFrame *connStatusPic;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnlan;
    QPushButton *generalButton;
    QPushButton *timeButton;
    QPushButton *displayButton;
    QPushButton *countersButton;
    QPushButton *testButton;
    QPushButton *waterButton;
    QPushButton *drinkButton;
    QPushButton *errorButton;
    QPushButton *updateBtn;
    QPushButton *payButton;
    QLabel *lb_txt;
    QGridLayout *gridLayout_3;
    QLabel *connStatusText;
    QFrame *connStatusInd;

    void setupUi(QWidget *WBSDStartPage)
    {
        if (WBSDStartPage->objectName().isEmpty())
            WBSDStartPage->setObjectName(QStringLiteral("WBSDStartPage"));
        WBSDStartPage->resize(548, 501);
        gridLayout = new QGridLayout(WBSDStartPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        connStatusPic = new QFrame(WBSDStartPage);
        connStatusPic->setObjectName(QStringLiteral("connStatusPic"));
        connStatusPic->setFrameShape(QFrame::StyledPanel);
        connStatusPic->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(connStatusPic, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(7);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(50, -1, 50, -1);
        btnlan = new QPushButton(WBSDStartPage);
        btnlan->setObjectName(QStringLiteral("btnlan"));

        gridLayout_2->addWidget(btnlan, 4, 1, 1, 1);

        generalButton = new QPushButton(WBSDStartPage);
        generalButton->setObjectName(QStringLiteral("generalButton"));

        gridLayout_2->addWidget(generalButton, 1, 1, 1, 1);

        timeButton = new QPushButton(WBSDStartPage);
        timeButton->setObjectName(QStringLiteral("timeButton"));

        gridLayout_2->addWidget(timeButton, 3, 0, 1, 1);

        displayButton = new QPushButton(WBSDStartPage);
        displayButton->setObjectName(QStringLiteral("displayButton"));

        gridLayout_2->addWidget(displayButton, 2, 1, 1, 1);

        countersButton = new QPushButton(WBSDStartPage);
        countersButton->setObjectName(QStringLiteral("countersButton"));

        gridLayout_2->addWidget(countersButton, 1, 0, 1, 1);

        testButton = new QPushButton(WBSDStartPage);
        testButton->setObjectName(QStringLiteral("testButton"));

        gridLayout_2->addWidget(testButton, 4, 0, 1, 1);

        waterButton = new QPushButton(WBSDStartPage);
        waterButton->setObjectName(QStringLiteral("waterButton"));

        gridLayout_2->addWidget(waterButton, 0, 1, 1, 1);

        drinkButton = new QPushButton(WBSDStartPage);
        drinkButton->setObjectName(QStringLiteral("drinkButton"));

        gridLayout_2->addWidget(drinkButton, 2, 0, 1, 1);

        errorButton = new QPushButton(WBSDStartPage);
        errorButton->setObjectName(QStringLiteral("errorButton"));

        gridLayout_2->addWidget(errorButton, 0, 0, 1, 1);

        updateBtn = new QPushButton(WBSDStartPage);
        updateBtn->setObjectName(QStringLiteral("updateBtn"));

        gridLayout_2->addWidget(updateBtn, 5, 0, 1, 1);

        payButton = new QPushButton(WBSDStartPage);
        payButton->setObjectName(QStringLiteral("payButton"));
        payButton->setEnabled(true);

        gridLayout_2->addWidget(payButton, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        lb_txt = new QLabel(WBSDStartPage);
        lb_txt->setObjectName(QStringLiteral("lb_txt"));
        QFont font;
        font.setPointSize(10);
        lb_txt->setFont(font);
        lb_txt->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lb_txt);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        connStatusText = new QLabel(WBSDStartPage);
        connStatusText->setObjectName(QStringLiteral("connStatusText"));

        gridLayout_3->addWidget(connStatusText, 0, 1, 1, 1);

        connStatusInd = new QFrame(WBSDStartPage);
        connStatusInd->setObjectName(QStringLiteral("connStatusInd"));
        connStatusInd->setMaximumSize(QSize(25, 25));
        connStatusInd->setFrameShape(QFrame::StyledPanel);
        connStatusInd->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(connStatusInd, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        QWidget::setTabOrder(errorButton, waterButton);
        QWidget::setTabOrder(waterButton, countersButton);
        QWidget::setTabOrder(countersButton, generalButton);
        QWidget::setTabOrder(generalButton, drinkButton);
        QWidget::setTabOrder(drinkButton, displayButton);
        QWidget::setTabOrder(displayButton, timeButton);
        QWidget::setTabOrder(timeButton, payButton);
        QWidget::setTabOrder(payButton, testButton);

        retranslateUi(WBSDStartPage);

        QMetaObject::connectSlotsByName(WBSDStartPage);
    } // setupUi

    void retranslateUi(QWidget *WBSDStartPage)
    {
        WBSDStartPage->setWindowTitle(QApplication::translate("WBSDStartPage", "Form", 0));
        btnlan->setText(QApplication::translate("WBSDStartPage", "Clone/backup and restore", 0));
        generalButton->setText(QApplication::translate("WBSDStartPage", "General settings", 0));
        timeButton->setText(QApplication::translate("WBSDStartPage", "Time and events", 0));
        displayButton->setText(QApplication::translate("WBSDStartPage", "Display settings", 0));
        countersButton->setText(QApplication::translate("WBSDStartPage", "Counters", 0));
        testButton->setText(QApplication::translate("WBSDStartPage", "Testing", 0));
        waterButton->setText(QApplication::translate("WBSDStartPage", "Water system", 0));
        drinkButton->setText(QApplication::translate("WBSDStartPage", "Drink settings", 0));
        errorButton->setText(QApplication::translate("WBSDStartPage", "Errors", 0));
        updateBtn->setText(QApplication::translate("WBSDStartPage", "Firmware update", 0));
        payButton->setText(QApplication::translate("WBSDStartPage", "Payment/RFID settings", 0));
        lb_txt->setText(QApplication::translate("WBSDStartPage", "Get machine type,please wait!", 0));
        connStatusText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WBSDStartPage: public Ui_WBSDStartPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDSTARTPAGE_H

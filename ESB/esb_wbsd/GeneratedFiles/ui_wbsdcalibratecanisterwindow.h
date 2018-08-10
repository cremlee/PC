/********************************************************************************
** Form generated from reading UI file 'wbsdcalibratecanisterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDCALIBRATECANISTERWINDOW_H
#define UI_WBSDCALIBRATECANISTERWINDOW_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDCalibrateCanisterwindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *lblRes;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *lblInfo;
    QLabel *lbl_img;
    QPushButton *btn_close;
    QLabel *label_min;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WBSDCalibrateCanisterwindow)
    {
        if (WBSDCalibrateCanisterwindow->objectName().isEmpty())
            WBSDCalibrateCanisterwindow->setObjectName(QStringLiteral("WBSDCalibrateCanisterwindow"));
        WBSDCalibrateCanisterwindow->resize(634, 342);
        WBSDCalibrateCanisterwindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(WBSDCalibrateCanisterwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 611, 261));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(20);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 5, 10, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        lblRes = new QLabel(gridLayoutWidget);
        lblRes->setObjectName(QStringLiteral("lblRes"));
        lblRes->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblRes->sizePolicy().hasHeightForWidth());
        lblRes->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lblRes, 2, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(0);
        doubleSpinBox->setMaximum(501);
        doubleSpinBox->setSingleStep(0.1);
        doubleSpinBox->setValue(0.1);

        gridLayout->addWidget(doubleSpinBox, 2, 1, 1, 1);

        lblInfo = new QLabel(gridLayoutWidget);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblInfo->sizePolicy().hasHeightForWidth());
        lblInfo->setSizePolicy(sizePolicy2);
        lblInfo->setTextFormat(Qt::PlainText);
        lblInfo->setWordWrap(true);

        gridLayout->addWidget(lblInfo, 1, 1, 1, 1);

        lbl_img = new QLabel(gridLayoutWidget);
        lbl_img->setObjectName(QStringLiteral("lbl_img"));
        sizePolicy2.setHeightForWidth(lbl_img->sizePolicy().hasHeightForWidth());
        lbl_img->setSizePolicy(sizePolicy2);
        lbl_img->setStyleSheet(QStringLiteral("border-image: url(:/mainpics/help.png);"));

        gridLayout->addWidget(lbl_img, 1, 0, 1, 1);

        btn_close = new QPushButton(gridLayoutWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        sizePolicy.setHeightForWidth(btn_close->sizePolicy().hasHeightForWidth());
        btn_close->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btn_close, 5, 0, 1, 1);

        label_min = new QLabel(gridLayoutWidget);
        label_min->setObjectName(QStringLiteral("label_min"));
        sizePolicy1.setHeightForWidth(label_min->sizePolicy().hasHeightForWidth());
        label_min->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_min, 2, 2, 1, 1);

        WBSDCalibrateCanisterwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDCalibrateCanisterwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 634, 21));
        WBSDCalibrateCanisterwindow->setMenuBar(menubar);
        QWidget::setTabOrder(doubleSpinBox, pushButton);

        retranslateUi(WBSDCalibrateCanisterwindow);

        QMetaObject::connectSlotsByName(WBSDCalibrateCanisterwindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDCalibrateCanisterwindow)
    {
        WBSDCalibrateCanisterwindow->setWindowTitle(QApplication::translate("WBSDCalibrateCanisterwindow", "Calibrate canister", 0));
        pushButton->setText(QApplication::translate("WBSDCalibrateCanisterwindow", "Set ", 0));
        lblRes->setText(QApplication::translate("WBSDCalibrateCanisterwindow", "Measured grams in cup", 0));
        lblInfo->setText(QApplication::translate("WBSDCalibrateCanisterwindow", "Place measuring cup under canister and press Enter button on machine. Then measure the cup and fill in the measured amount (Grams).  (Do not include weight of measuring cup)  Stop button (Red) stops the calibration.\n"
"The calibration must be done with a full instant auger", 0));
        lbl_img->setText(QString());
        btn_close->setText(QApplication::translate("WBSDCalibrateCanisterwindow", "Close", 0));
        label_min->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WBSDCalibrateCanisterwindow: public Ui_WBSDCalibrateCanisterwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDCALIBRATECANISTERWINDOW_H

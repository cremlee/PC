/********************************************************************************
** Form generated from reading UI file 'wbsdinstantwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDINSTANTWINDOW_H
#define UI_WBSDINSTANTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDInstantWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QGridLayout *gridLayout_2;
    QLabel *lblCal100;
    QPushButton *btnCal50;
    QPushButton *btnCal100;
    QPushButton *btnCal75;
    QLabel *lblCal75;
    QLabel *label_6;
    QLabel *lblCal50;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *lb_img1;
    QLabel *lb_img2;
    QLabel *lb_img3;
    QLabel *label_min_50;
    QLabel *label_min_75;
    QLabel *label_min_100;
    QLabel *label_min_title_4;
    QFrame *line;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QPushButton *instantMixer;
    QPushButton *instantWaterVal;
    QPushButton *instantCanister;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QPushButton *instantFan;
    QFrame *line_2;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QDoubleSpinBox *spIngVolGr;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDInstantWindow)
    {
        if (WBSDInstantWindow->objectName().isEmpty())
            WBSDInstantWindow->setObjectName(QStringLiteral("WBSDInstantWindow"));
        WBSDInstantWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDInstantWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 771, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 30, 50, 0);
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setPointSize(12);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lblCal100 = new QLabel(verticalLayoutWidget);
        lblCal100->setObjectName(QStringLiteral("lblCal100"));

        gridLayout_2->addWidget(lblCal100, 3, 1, 1, 1);

        btnCal50 = new QPushButton(verticalLayoutWidget);
        btnCal50->setObjectName(QStringLiteral("btnCal50"));

        gridLayout_2->addWidget(btnCal50, 1, 2, 1, 1);

        btnCal100 = new QPushButton(verticalLayoutWidget);
        btnCal100->setObjectName(QStringLiteral("btnCal100"));

        gridLayout_2->addWidget(btnCal100, 3, 2, 1, 1);

        btnCal75 = new QPushButton(verticalLayoutWidget);
        btnCal75->setObjectName(QStringLiteral("btnCal75"));

        gridLayout_2->addWidget(btnCal75, 2, 2, 1, 1);

        lblCal75 = new QLabel(verticalLayoutWidget);
        lblCal75->setObjectName(QStringLiteral("lblCal75"));

        gridLayout_2->addWidget(lblCal75, 2, 1, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lblCal50 = new QLabel(verticalLayoutWidget);
        lblCal50->setObjectName(QStringLiteral("lblCal50"));

        gridLayout_2->addWidget(lblCal50, 1, 1, 1, 1);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lb_img1 = new QLabel(verticalLayoutWidget);
        lb_img1->setObjectName(QStringLiteral("lb_img1"));
        lb_img1->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(lb_img1, 1, 4, 1, 1);

        lb_img2 = new QLabel(verticalLayoutWidget);
        lb_img2->setObjectName(QStringLiteral("lb_img2"));
        lb_img2->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(lb_img2, 2, 4, 1, 1);

        lb_img3 = new QLabel(verticalLayoutWidget);
        lb_img3->setObjectName(QStringLiteral("lb_img3"));
        lb_img3->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(lb_img3, 3, 4, 1, 1);

        label_min_50 = new QLabel(verticalLayoutWidget);
        label_min_50->setObjectName(QStringLiteral("label_min_50"));
        label_min_50->setLayoutDirection(Qt::RightToLeft);
        label_min_50->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_min_50, 1, 3, 1, 1);

        label_min_75 = new QLabel(verticalLayoutWidget);
        label_min_75->setObjectName(QStringLiteral("label_min_75"));
        label_min_75->setLayoutDirection(Qt::RightToLeft);
        label_min_75->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_min_75, 2, 3, 1, 1);

        label_min_100 = new QLabel(verticalLayoutWidget);
        label_min_100->setObjectName(QStringLiteral("label_min_100"));
        label_min_100->setLayoutDirection(Qt::RightToLeft);
        label_min_100->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_min_100, 3, 3, 1, 1);

        label_min_title_4 = new QLabel(verticalLayoutWidget);
        label_min_title_4->setObjectName(QStringLiteral("label_min_title_4"));
        label_min_title_4->setLayoutDirection(Qt::RightToLeft);
        label_min_title_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_min_title_4, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        instantMixer = new QPushButton(verticalLayoutWidget);
        instantMixer->setObjectName(QStringLiteral("instantMixer"));

        gridLayout->addWidget(instantMixer, 1, 1, 1, 1);

        instantWaterVal = new QPushButton(verticalLayoutWidget);
        instantWaterVal->setObjectName(QStringLiteral("instantWaterVal"));

        gridLayout->addWidget(instantWaterVal, 0, 1, 1, 1);

        instantCanister = new QPushButton(verticalLayoutWidget);
        instantCanister->setObjectName(QStringLiteral("instantCanister"));

        gridLayout->addWidget(instantCanister, 2, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        instantFan = new QPushButton(verticalLayoutWidget);
        instantFan->setObjectName(QStringLiteral("instantFan"));

        gridLayout->addWidget(instantFan, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setEnabled(false);

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        spIngVolGr = new QDoubleSpinBox(verticalLayoutWidget);
        spIngVolGr->setObjectName(QStringLiteral("spIngVolGr"));
        spIngVolGr->setEnabled(false);
        spIngVolGr->setMinimum(0.05);
        spIngVolGr->setMaximum(2);
        spIngVolGr->setSingleStep(0.01);
        spIngVolGr->setValue(0.25);

        gridLayout_3->addWidget(spIngVolGr, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        WBSDInstantWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDInstantWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDInstantWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDInstantWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDInstantWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(instantWaterVal, instantMixer);
        QWidget::setTabOrder(instantMixer, instantCanister);
        QWidget::setTabOrder(instantCanister, instantFan);

        retranslateUi(WBSDInstantWindow);

        QMetaObject::connectSlotsByName(WBSDInstantWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDInstantWindow)
    {
        WBSDInstantWindow->setWindowTitle(QApplication::translate("WBSDInstantWindow", "Instant tests", 0));
        label_7->setText(QApplication::translate("WBSDInstantWindow", " calibration must be done with a full instant auger", 0));
        lblCal100->setText(QApplication::translate("WBSDInstantWindow", "5.5 G / Sec", 0));
        btnCal50->setText(QApplication::translate("WBSDInstantWindow", "Calibrate", 0));
        btnCal100->setText(QApplication::translate("WBSDInstantWindow", "Calibrate", 0));
        btnCal75->setText(QApplication::translate("WBSDInstantWindow", "Calibrate", 0));
        lblCal75->setText(QApplication::translate("WBSDInstantWindow", "5.0 G / Sec", 0));
        label_6->setText(QApplication::translate("WBSDInstantWindow", "Calibrate canister", 0));
        lblCal50->setText(QApplication::translate("WBSDInstantWindow", "4.5 G / Sec", 0));
        label_10->setText(QApplication::translate("WBSDInstantWindow", "Canister speed 100%", 0));
        label_8->setText(QApplication::translate("WBSDInstantWindow", "Canister speed 75%", 0));
        label_5->setText(QApplication::translate("WBSDInstantWindow", "Canister speed 50%", 0));
        lb_img1->setText(QString());
        lb_img2->setText(QString());
        lb_img3->setText(QString());
        label_min_50->setText(QString());
        label_min_75->setText(QString());
        label_min_100->setText(QString());
        label_min_title_4->setText(QApplication::translate("WBSDInstantWindow", "MinValue", 0));
        label_4->setText(QApplication::translate("WBSDInstantWindow", "Instant fan", 0));
        instantMixer->setText(QApplication::translate("WBSDInstantWindow", "Activate", 0));
        instantWaterVal->setText(QApplication::translate("WBSDInstantWindow", "Activate", 0));
        instantCanister->setText(QApplication::translate("WBSDInstantWindow", "Activate", 0));
        label_2->setText(QApplication::translate("WBSDInstantWindow", "Instant mixer", 0));
        label_3->setText(QApplication::translate("WBSDInstantWindow", "Instant canister", 0));
        label->setText(QApplication::translate("WBSDInstantWindow", "Instant water valve", 0));
        instantFan->setText(QApplication::translate("WBSDInstantWindow", "Activate", 0));
        label_12->setText(QApplication::translate("WBSDInstantWindow", "Ingredient gram per ml", 0));
        spIngVolGr->setSuffix(QApplication::translate("WBSDInstantWindow", "  g / ml", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDInstantWindow: public Ui_WBSDInstantWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDINSTANTWINDOW_H

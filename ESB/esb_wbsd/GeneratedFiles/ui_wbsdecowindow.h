/********************************************************************************
** Form generated from reading UI file 'wbsdecowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDECOWINDOW_H
#define UI_WBSDECOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mywin.h"

QT_BEGIN_NAMESPACE

class Ui_WBSDEcoWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QDoubleSpinBox *ecoSetTemp;
    QLabel *label_4;
    QComboBox *ecoWakeup;
    QLabel *label_2;
    QLabel *label_7;
    QComboBox *holidayMode;
    QLabel *label;
    QComboBox *ecoMode;
    QLabel *label_3;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_10;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_9;
    QTimeEdit *Pdt_5;
    QTimeEdit *Pdt_3;
    QTimeEdit *Pdt_6;
    QTimeEdit *Pdt_7;
    QLabel *label_18;
    QTimeEdit *Pdt_2;
    QLabel *label_6;
    QTimeEdit *Pdt_1;
    QTimeEdit *Pdt_4;
    QLabel *label_14;
    QLabel *label_8;
    QTimeEdit *Tedt_7;
    QTimeEdit *Tedt_1;
    QTimeEdit *Tedt_2;
    QTimeEdit *Tedt_3;
    QTimeEdit *Tedt_4;
    QTimeEdit *Tedt_5;
    QTimeEdit *Tedt_6;
    mywin *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDEcoWindow)
    {
        if (WBSDEcoWindow->objectName().isEmpty())
            WBSDEcoWindow->setObjectName(QStringLiteral("WBSDEcoWindow"));
        WBSDEcoWindow->resize(764, 405);
        centralwidget = new QWidget(WBSDEcoWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 761, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(50, -1, 50, -1);
        ecoSetTemp = new QDoubleSpinBox(verticalLayoutWidget);
        ecoSetTemp->setObjectName(QStringLiteral("ecoSetTemp"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ecoSetTemp->sizePolicy().hasHeightForWidth());
        ecoSetTemp->setSizePolicy(sizePolicy);
        ecoSetTemp->setAutoFillBackground(true);
        ecoSetTemp->setKeyboardTracking(true);
        ecoSetTemp->setDecimals(1);
        ecoSetTemp->setMinimum(1);
        ecoSetTemp->setMaximum(200);
        ecoSetTemp->setSingleStep(0.5);

        gridLayout->addWidget(ecoSetTemp, 3, 1, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        ecoWakeup = new QComboBox(verticalLayoutWidget);
        ecoWakeup->setObjectName(QStringLiteral("ecoWakeup"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ecoWakeup->sizePolicy().hasHeightForWidth());
        ecoWakeup->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(ecoWakeup, 2, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        holidayMode = new QComboBox(verticalLayoutWidget);
        holidayMode->setObjectName(QStringLiteral("holidayMode"));
        sizePolicy2.setHeightForWidth(holidayMode->sizePolicy().hasHeightForWidth());
        holidayMode->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(holidayMode, 1, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ecoMode = new QComboBox(verticalLayoutWidget);
        ecoMode->setObjectName(QStringLiteral("ecoMode"));
        sizePolicy2.setHeightForWidth(ecoMode->sizePolicy().hasHeightForWidth());
        ecoMode->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(ecoMode, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, -1, 0, -1);
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        label_13->setMaximumSize(QSize(16777215, 20));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_13, 0, 7, 1, 1);

        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);
        label_17->setMaximumSize(QSize(16777215, 20));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_17, 0, 5, 1, 1);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setMaximumSize(QSize(16777215, 20));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 0, 3, 1, 1);

        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setMaximumSize(QSize(16777215, 20));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_15, 0, 6, 1, 1);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setMaximumSize(QSize(16777215, 20));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_16, 0, 1, 1, 1);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 2, 0, 1, 1);

        Pdt_5 = new QTimeEdit(verticalLayoutWidget);
        Pdt_5->setObjectName(QStringLiteral("Pdt_5"));
        sizePolicy2.setHeightForWidth(Pdt_5->sizePolicy().hasHeightForWidth());
        Pdt_5->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Pdt_5, 2, 6, 1, 1);

        Pdt_3 = new QTimeEdit(verticalLayoutWidget);
        Pdt_3->setObjectName(QStringLiteral("Pdt_3"));
        sizePolicy2.setHeightForWidth(Pdt_3->sizePolicy().hasHeightForWidth());
        Pdt_3->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Pdt_3, 2, 4, 1, 1);

        Pdt_6 = new QTimeEdit(verticalLayoutWidget);
        Pdt_6->setObjectName(QStringLiteral("Pdt_6"));
        sizePolicy2.setHeightForWidth(Pdt_6->sizePolicy().hasHeightForWidth());
        Pdt_6->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Pdt_6, 2, 7, 1, 1);

        Pdt_7 = new QTimeEdit(verticalLayoutWidget);
        Pdt_7->setObjectName(QStringLiteral("Pdt_7"));
        sizePolicy2.setHeightForWidth(Pdt_7->sizePolicy().hasHeightForWidth());
        Pdt_7->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Pdt_7, 2, 1, 1, 1);

        label_18 = new QLabel(verticalLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);
        label_18->setMaximumSize(QSize(100, 20));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_18, 0, 0, 1, 1);

        Pdt_2 = new QTimeEdit(verticalLayoutWidget);
        Pdt_2->setObjectName(QStringLiteral("Pdt_2"));
        sizePolicy2.setHeightForWidth(Pdt_2->sizePolicy().hasHeightForWidth());
        Pdt_2->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Pdt_2, 2, 3, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMaximumSize(QSize(16777215, 20));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        Pdt_1 = new QTimeEdit(verticalLayoutWidget);
        Pdt_1->setObjectName(QStringLiteral("Pdt_1"));
        sizePolicy2.setHeightForWidth(Pdt_1->sizePolicy().hasHeightForWidth());
        Pdt_1->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Pdt_1, 2, 2, 1, 1);

        Pdt_4 = new QTimeEdit(verticalLayoutWidget);
        Pdt_4->setObjectName(QStringLiteral("Pdt_4"));
        sizePolicy2.setHeightForWidth(Pdt_4->sizePolicy().hasHeightForWidth());
        Pdt_4->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Pdt_4, 2, 5, 1, 1);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setMaximumSize(QSize(16777215, 20));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_14, 0, 4, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        Tedt_7 = new QTimeEdit(verticalLayoutWidget);
        Tedt_7->setObjectName(QStringLiteral("Tedt_7"));
        sizePolicy2.setHeightForWidth(Tedt_7->sizePolicy().hasHeightForWidth());
        Tedt_7->setSizePolicy(sizePolicy2);
        Tedt_7->setMinimumTime(QTime(0, 0, 0));
        Tedt_7->setCurrentSection(QDateTimeEdit::HourSection);

        gridLayout_2->addWidget(Tedt_7, 3, 1, 1, 1);

        Tedt_1 = new QTimeEdit(verticalLayoutWidget);
        Tedt_1->setObjectName(QStringLiteral("Tedt_1"));
        sizePolicy2.setHeightForWidth(Tedt_1->sizePolicy().hasHeightForWidth());
        Tedt_1->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Tedt_1, 3, 2, 1, 1);

        Tedt_2 = new QTimeEdit(verticalLayoutWidget);
        Tedt_2->setObjectName(QStringLiteral("Tedt_2"));
        sizePolicy2.setHeightForWidth(Tedt_2->sizePolicy().hasHeightForWidth());
        Tedt_2->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Tedt_2, 3, 3, 1, 1);

        Tedt_3 = new QTimeEdit(verticalLayoutWidget);
        Tedt_3->setObjectName(QStringLiteral("Tedt_3"));
        sizePolicy2.setHeightForWidth(Tedt_3->sizePolicy().hasHeightForWidth());
        Tedt_3->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Tedt_3, 3, 4, 1, 1);

        Tedt_4 = new QTimeEdit(verticalLayoutWidget);
        Tedt_4->setObjectName(QStringLiteral("Tedt_4"));
        sizePolicy2.setHeightForWidth(Tedt_4->sizePolicy().hasHeightForWidth());
        Tedt_4->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Tedt_4, 3, 5, 1, 1);

        Tedt_5 = new QTimeEdit(verticalLayoutWidget);
        Tedt_5->setObjectName(QStringLiteral("Tedt_5"));
        sizePolicy2.setHeightForWidth(Tedt_5->sizePolicy().hasHeightForWidth());
        Tedt_5->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Tedt_5, 3, 6, 1, 1);

        Tedt_6 = new QTimeEdit(verticalLayoutWidget);
        Tedt_6->setObjectName(QStringLiteral("Tedt_6"));
        sizePolicy2.setHeightForWidth(Tedt_6->sizePolicy().hasHeightForWidth());
        Tedt_6->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Tedt_6, 3, 7, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        widget = new mywin(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 5);
        WBSDEcoWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDEcoWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 764, 21));
        WBSDEcoWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDEcoWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDEcoWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(holidayMode, ecoWakeup);
        QWidget::setTabOrder(ecoWakeup, ecoSetTemp);

        retranslateUi(WBSDEcoWindow);

        QMetaObject::connectSlotsByName(WBSDEcoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDEcoWindow)
    {
        WBSDEcoWindow->setWindowTitle(QApplication::translate("WBSDEcoWindow", "Eco moment", 0));
        label_4->setText(QApplication::translate("WBSDEcoWindow", "Boiler temperature in ECO mode (\302\260C)", 0));
        label_2->setText(QApplication::translate("WBSDEcoWindow", "ECO wakeup", 0));
        label_7->setText(QApplication::translate("WBSDEcoWindow", "Holiday mode", 0));
        label->setText(QApplication::translate("WBSDEcoWindow", "ECO mode", 0));
        label_3->setText(QApplication::translate("WBSDEcoWindow", "End time must be before than start time!", 0));
        label_13->setText(QApplication::translate("WBSDEcoWindow", "Saturday", 0));
        label_17->setText(QApplication::translate("WBSDEcoWindow", "Thursday", 0));
        label_10->setText(QApplication::translate("WBSDEcoWindow", "Tuesday", 0));
        label_15->setText(QApplication::translate("WBSDEcoWindow", "Friday", 0));
        label_16->setText(QApplication::translate("WBSDEcoWindow", "Sunday", 0));
        label_9->setText(QApplication::translate("WBSDEcoWindow", "Active     end", 0));
        Pdt_5->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Pdt_3->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Pdt_6->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Pdt_7->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        label_18->setText(QApplication::translate("WBSDEcoWindow", " ECO Setting", 0));
        Pdt_2->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        label_6->setText(QApplication::translate("WBSDEcoWindow", "Monday ", 0));
        Pdt_1->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Pdt_4->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        label_14->setText(QApplication::translate("WBSDEcoWindow", "Wednesday", 0));
        label_8->setText(QApplication::translate("WBSDEcoWindow", " Active   start", 0));
        Tedt_7->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Tedt_1->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Tedt_2->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Tedt_3->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Tedt_4->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Tedt_5->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
        Tedt_6->setDisplayFormat(QApplication::translate("WBSDEcoWindow", "HH:mm", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDEcoWindow: public Ui_WBSDEcoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDECOWINDOW_H

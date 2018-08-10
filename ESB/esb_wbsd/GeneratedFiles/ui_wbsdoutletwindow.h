/********************************************************************************
** Form generated from reading UI file 'wbsdoutletwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDOUTLETWINDOW_H
#define UI_WBSDOUTLETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_WBSDOutletWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_7;
    QPushButton *hotWaterValve;
    QLabel *label_5;
    QLabel *label;
    QPushButton *inletValve;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *coldWaterValve;
    QPushButton *lbibAirValve;
    QLabel *label_8;
    QPushButton *lbibValve;
    QPushButton *normalOpenValve;
    QLabel *label_2;
    QPushButton *rbibValve;
    QPushButton *rbibAirValve;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDOutletWindow)
    {
        if (WBSDOutletWindow->objectName().isEmpty())
            WBSDOutletWindow->setObjectName(QStringLiteral("WBSDOutletWindow"));
        WBSDOutletWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDOutletWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 761, 275));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 1, 1, 1);

        hotWaterValve = new QPushButton(gridLayoutWidget);
        hotWaterValve->setObjectName(QStringLiteral("hotWaterValve"));

        gridLayout->addWidget(hotWaterValve, 0, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        inletValve = new QPushButton(gridLayoutWidget);
        inletValve->setObjectName(QStringLiteral("inletValve"));
        inletValve->setEnabled(true);

        gridLayout->addWidget(inletValve, 3, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        coldWaterValve = new QPushButton(gridLayoutWidget);
        coldWaterValve->setObjectName(QStringLiteral("coldWaterValve"));

        gridLayout->addWidget(coldWaterValve, 1, 2, 1, 1);

        lbibAirValve = new QPushButton(gridLayoutWidget);
        lbibAirValve->setObjectName(QStringLiteral("lbibAirValve"));

        gridLayout->addWidget(lbibAirValve, 5, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 7, 1, 1, 1);

        lbibValve = new QPushButton(gridLayoutWidget);
        lbibValve->setObjectName(QStringLiteral("lbibValve"));

        gridLayout->addWidget(lbibValve, 4, 2, 1, 1);

        normalOpenValve = new QPushButton(gridLayoutWidget);
        normalOpenValve->setObjectName(QStringLiteral("normalOpenValve"));

        gridLayout->addWidget(normalOpenValve, 2, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        rbibValve = new QPushButton(gridLayoutWidget);
        rbibValve->setObjectName(QStringLiteral("rbibValve"));

        gridLayout->addWidget(rbibValve, 6, 2, 1, 1);

        rbibAirValve = new QPushButton(gridLayoutWidget);
        rbibAirValve->setObjectName(QStringLiteral("rbibAirValve"));

        gridLayout->addWidget(rbibAirValve, 7, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        WBSDOutletWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDOutletWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDOutletWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDOutletWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDOutletWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(hotWaterValve, coldWaterValve);
        QWidget::setTabOrder(coldWaterValve, normalOpenValve);
        QWidget::setTabOrder(normalOpenValve, inletValve);
        QWidget::setTabOrder(inletValve, lbibValve);
        QWidget::setTabOrder(lbibValve, lbibAirValve);
        QWidget::setTabOrder(lbibAirValve, rbibValve);
        QWidget::setTabOrder(rbibValve, rbibAirValve);

        retranslateUi(WBSDOutletWindow);

        QMetaObject::connectSlotsByName(WBSDOutletWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDOutletWindow)
    {
        WBSDOutletWindow->setWindowTitle(QApplication::translate("WBSDOutletWindow", "Valves", 0));
        label_4->setText(QApplication::translate("WBSDOutletWindow", "Inlet valve", 0));
        label_7->setText(QApplication::translate("WBSDOutletWindow", "RBIB water valve", 0));
        hotWaterValve->setText(QApplication::translate("WBSDOutletWindow", "Activate", 0));
        label_5->setText(QApplication::translate("WBSDOutletWindow", "LBIB water valve", 0));
        label->setText(QApplication::translate("WBSDOutletWindow", "Hot water valve", 0));
        inletValve->setText(QApplication::translate("WBSDOutletWindow", "Activate", 0));
        label_6->setText(QApplication::translate("WBSDOutletWindow", "LBIB air valve", 0));
        label_3->setText(QApplication::translate("WBSDOutletWindow", "Normal open valve", 0));
        coldWaterValve->setText(QApplication::translate("WBSDOutletWindow", "Activate", 0));
        lbibAirValve->setText(QApplication::translate("WBSDOutletWindow", "Activate", 0));
        label_8->setText(QApplication::translate("WBSDOutletWindow", "RBIB air valve", 0));
        lbibValve->setText(QApplication::translate("WBSDOutletWindow", "Activate", 0));
        normalOpenValve->setText(QApplication::translate("WBSDOutletWindow", "Activate", 0));
        label_2->setText(QApplication::translate("WBSDOutletWindow", "Cold water valve", 0));
        rbibValve->setText(QApplication::translate("WBSDOutletWindow", "Activate", 0));
        rbibAirValve->setText(QApplication::translate("WBSDOutletWindow", "Activate", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDOutletWindow: public Ui_WBSDOutletWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDOUTLETWINDOW_H

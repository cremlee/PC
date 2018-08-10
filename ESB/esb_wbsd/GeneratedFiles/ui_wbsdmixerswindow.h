/********************************************************************************
** Form generated from reading UI file 'wbsdmixerswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDMIXERSWINDOW_H
#define UI_WBSDMIXERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDMixersWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QComboBox *comboBox_2;
    QPushButton *pushButton_4;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_6;
    QPushButton *pushButton;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_10;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuBack;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDMixersWindow)
    {
        if (WBSDMixersWindow->objectName().isEmpty())
            WBSDMixersWindow->setObjectName(QStringLiteral("WBSDMixersWindow"));
        WBSDMixersWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDMixersWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 751, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 5, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 2, 1, 1);

        comboBox_2 = new QComboBox(gridLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 6, 2, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 7, 2, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 4, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 7, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 5, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 6, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 2, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        WBSDMixersWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDMixersWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuBack = new QMenu(menubar);
        menuBack->setObjectName(QStringLiteral("menuBack"));
        WBSDMixersWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDMixersWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDMixersWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, comboBox);
        QWidget::setTabOrder(comboBox, pushButton_3);
        QWidget::setTabOrder(pushButton_3, comboBox_2);
        QWidget::setTabOrder(comboBox_2, pushButton_4);

        menubar->addAction(menuBack->menuAction());

        retranslateUi(WBSDMixersWindow);

        QMetaObject::connectSlotsByName(WBSDMixersWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDMixersWindow)
    {
        WBSDMixersWindow->setWindowTitle(QApplication::translate("WBSDMixersWindow", "Mixers", 0));
        label_5->setText(QApplication::translate("WBSDMixersWindow", "Right mixer", 0));
        label_7->setText(QApplication::translate("WBSDMixersWindow", "Valve position left MAD position", 0));
        pushButton_2->setText(QApplication::translate("WBSDMixersWindow", "Activate", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("WBSDMixersWindow", "O-C", 0)
        );
        pushButton_4->setText(QApplication::translate("WBSDMixersWindow", "Activate", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("WBSDMixersWindow", "O-C", 0)
        );
        label_2->setText(QApplication::translate("WBSDMixersWindow", "Left mixer", 0));
        label_6->setText(QApplication::translate("WBSDMixersWindow", "Valve position left MAD position", 0));
        pushButton->setText(QApplication::translate("WBSDMixersWindow", "Activate", 0));
        label_9->setText(QApplication::translate("WBSDMixersWindow", "Valve position right MAD position", 0));
        pushButton_3->setText(QApplication::translate("WBSDMixersWindow", "Activate", 0));
        label_4->setText(QApplication::translate("WBSDMixersWindow", "On", 0));
        label_8->setText(QApplication::translate("WBSDMixersWindow", "Valve position right MAD position", 0));
        label->setText(QApplication::translate("WBSDMixersWindow", "Left mixer safety", 0));
        label_10->setText(QApplication::translate("WBSDMixersWindow", "On", 0));
        label_3->setText(QApplication::translate("WBSDMixersWindow", "Right mixer safety", 0));
        menuBack->setTitle(QApplication::translate("WBSDMixersWindow", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDMixersWindow: public Ui_WBSDMixersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDMIXERSWINDOW_H

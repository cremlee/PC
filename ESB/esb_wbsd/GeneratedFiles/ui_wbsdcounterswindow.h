/********************************************************************************
** Form generated from reading UI file 'wbsdcounterswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDCOUNTERSWINDOW_H
#define UI_WBSDCOUNTERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDCountersWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button4;
    QPushButton *button6;
    QPushButton *button3;
    QPushButton *button5;
    QPushButton *button1;
    QPushButton *button2;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonTotal;
    QPushButton *ResetCounters;
    QPushButton *button7;
    QPushButton *button8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDCountersWindow)
    {
        if (WBSDCountersWindow->objectName().isEmpty())
            WBSDCountersWindow->setObjectName(QStringLiteral("WBSDCountersWindow"));
        WBSDCountersWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDCountersWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 30, 701, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 20, 50, 40);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setHorizontalSpacing(40);
        gridLayout_3->setVerticalSpacing(15);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        button4 = new QPushButton(verticalLayoutWidget);
        button4->setObjectName(QStringLiteral("button4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button4, 0, 3, 1, 1);

        button6 = new QPushButton(verticalLayoutWidget);
        button6->setObjectName(QStringLiteral("button6"));
        sizePolicy.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button6, 2, 3, 1, 1);

        button3 = new QPushButton(verticalLayoutWidget);
        button3->setObjectName(QStringLiteral("button3"));
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button3, 2, 2, 1, 1);

        button5 = new QPushButton(verticalLayoutWidget);
        button5->setObjectName(QStringLiteral("button5"));
        sizePolicy.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button5, 1, 3, 1, 1);

        button1 = new QPushButton(verticalLayoutWidget);
        button1->setObjectName(QStringLiteral("button1"));
        sizePolicy.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button1, 0, 2, 1, 1);

        button2 = new QPushButton(verticalLayoutWidget);
        button2->setObjectName(QStringLiteral("button2"));
        sizePolicy.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        buttonTotal = new QPushButton(verticalLayoutWidget);
        buttonTotal->setObjectName(QStringLiteral("buttonTotal"));
        sizePolicy.setHeightForWidth(buttonTotal->sizePolicy().hasHeightForWidth());
        buttonTotal->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        buttonTotal->setFont(font);

        gridLayout_3->addWidget(buttonTotal, 3, 2, 1, 1);

        ResetCounters = new QPushButton(verticalLayoutWidget);
        ResetCounters->setObjectName(QStringLiteral("ResetCounters"));
        sizePolicy.setHeightForWidth(ResetCounters->sizePolicy().hasHeightForWidth());
        ResetCounters->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(ResetCounters, 4, 2, 1, 1);

        button7 = new QPushButton(verticalLayoutWidget);
        button7->setObjectName(QStringLiteral("button7"));
        sizePolicy.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button7, 0, 1, 1, 1);

        button8 = new QPushButton(verticalLayoutWidget);
        button8->setObjectName(QStringLiteral("button8"));
        sizePolicy.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button8, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        WBSDCountersWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDCountersWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDCountersWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDCountersWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDCountersWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(button1, button2);
        QWidget::setTabOrder(button2, button3);
        QWidget::setTabOrder(button3, button4);
        QWidget::setTabOrder(button4, button5);
        QWidget::setTabOrder(button5, button6);
        QWidget::setTabOrder(button6, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);

        retranslateUi(WBSDCountersWindow);

        QMetaObject::connectSlotsByName(WBSDCountersWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDCountersWindow)
    {
        WBSDCountersWindow->setWindowTitle(QApplication::translate("WBSDCountersWindow", "Button counters", 0));
        pushButton_4->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        button4->setText(QApplication::translate("WBSDCountersWindow", "Button 4", 0));
        button6->setText(QApplication::translate("WBSDCountersWindow", "Button 6", 0));
        button3->setText(QApplication::translate("WBSDCountersWindow", "Button 3", 0));
        button5->setText(QApplication::translate("WBSDCountersWindow", "Button 5", 0));
        button1->setText(QApplication::translate("WBSDCountersWindow", "Button 1", 0));
        button2->setText(QApplication::translate("WBSDCountersWindow", "Button 2", 0));
        buttonTotal->setText(QApplication::translate("WBSDCountersWindow", "Counters Total", 0));
        ResetCounters->setText(QApplication::translate("WBSDCountersWindow", "Reset Counters", 0));
        button7->setText(QApplication::translate("WBSDCountersWindow", "Button7", 0));
        button8->setText(QApplication::translate("WBSDCountersWindow", "Button 8", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDCountersWindow: public Ui_WBSDCountersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDCOUNTERSWINDOW_H

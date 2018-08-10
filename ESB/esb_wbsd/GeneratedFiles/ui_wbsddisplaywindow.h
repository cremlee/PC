/********************************************************************************
** Form generated from reading UI file 'wbsddisplaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDDISPLAYWINDOW_H
#define UI_WBSDDISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_WBSDDisplayWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_6;
    QComboBox *cb_LCD;
    QPushButton *pbrst;
    QLabel *label;
    QPushButton *buttonTest;
    QLabel *label_3;
    QComboBox *soundTest;
    QLabel *label_2;
    QPushButton *lcdSegment;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDDisplayWindow)
    {
        if (WBSDDisplayWindow->objectName().isEmpty())
            WBSDDisplayWindow->setObjectName(QStringLiteral("WBSDDisplayWindow"));
        WBSDDisplayWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDDisplayWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 761, 186));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 20, 50, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        cb_LCD = new QComboBox(verticalLayoutWidget);
        cb_LCD->setObjectName(QStringLiteral("cb_LCD"));

        gridLayout->addWidget(cb_LCD, 3, 1, 1, 1);

        pbrst = new QPushButton(verticalLayoutWidget);
        pbrst->setObjectName(QStringLiteral("pbrst"));

        gridLayout->addWidget(pbrst, 1, 2, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        buttonTest = new QPushButton(verticalLayoutWidget);
        buttonTest->setObjectName(QStringLiteral("buttonTest"));

        gridLayout->addWidget(buttonTest, 0, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        soundTest = new QComboBox(verticalLayoutWidget);
        soundTest->setObjectName(QStringLiteral("soundTest"));

        gridLayout->addWidget(soundTest, 2, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lcdSegment = new QPushButton(verticalLayoutWidget);
        lcdSegment->setObjectName(QStringLiteral("lcdSegment"));

        gridLayout->addWidget(lcdSegment, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));

        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        WBSDDisplayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDDisplayWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDDisplayWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDDisplayWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDDisplayWindow->setStatusBar(statusbar);

        retranslateUi(WBSDDisplayWindow);

        QMetaObject::connectSlotsByName(WBSDDisplayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDDisplayWindow)
    {
        WBSDDisplayWindow->setWindowTitle(QApplication::translate("WBSDDisplayWindow", "Display options", 0));
        label_4->setText(QApplication::translate("WBSDDisplayWindow", "LCD Selection", 0));
        label_6->setText(QApplication::translate("WBSDDisplayWindow", "Reset the Machine after this selection changed", 0));
        pbrst->setText(QApplication::translate("WBSDDisplayWindow", "LCD Show Reset", 0));
        label->setText(QApplication::translate("WBSDDisplayWindow", "LCD Segment", 0));
        buttonTest->setText(QApplication::translate("WBSDDisplayWindow", "UIB Button Screen", 0));
        label_3->setText(QApplication::translate("WBSDDisplayWindow", "Sound", 0));
        label_2->setText(QApplication::translate("WBSDDisplayWindow", "UIB Button Test", 0));
        lcdSegment->setText(QApplication::translate("WBSDDisplayWindow", "Activate", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDDisplayWindow: public Ui_WBSDDisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDDISPLAYWINDOW_H

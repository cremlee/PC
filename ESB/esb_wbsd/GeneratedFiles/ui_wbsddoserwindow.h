/********************************************************************************
** Form generated from reading UI file 'wbsddoserwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDDOSERWINDOW_H
#define UI_WBSDDOSERWINDOW_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDDoserWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *rightB2Test;
    QLabel *label;
    QPushButton *leftB2Test;
    QLabel *label_2;
    QGridLayout *gridLayout_3;
    QPushButton *leftB2SlowTest;
    QLabel *leftSlowLab;
    QLabel *rightSlowLab;
    QPushButton *rightB2SlowTest;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDDoserWindow)
    {
        if (WBSDDoserWindow->objectName().isEmpty())
            WBSDDoserWindow->setObjectName(QStringLiteral("WBSDDoserWindow"));
        WBSDDoserWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDDoserWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 751, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 20, 50, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, -1, -1, -1);
        rightB2Test = new QPushButton(verticalLayoutWidget);
        rightB2Test->setObjectName(QStringLiteral("rightB2Test"));

        gridLayout->addWidget(rightB2Test, 1, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        leftB2Test = new QPushButton(verticalLayoutWidget);
        leftB2Test->setObjectName(QStringLiteral("leftB2Test"));

        gridLayout->addWidget(leftB2Test, 0, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        verticalLayout->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        leftB2SlowTest = new QPushButton(verticalLayoutWidget);
        leftB2SlowTest->setObjectName(QStringLiteral("leftB2SlowTest"));
        leftB2SlowTest->setEnabled(false);

        gridLayout_3->addWidget(leftB2SlowTest, 0, 1, 1, 1);

        leftSlowLab = new QLabel(verticalLayoutWidget);
        leftSlowLab->setObjectName(QStringLiteral("leftSlowLab"));
        leftSlowLab->setEnabled(false);

        gridLayout_3->addWidget(leftSlowLab, 0, 0, 1, 1);

        rightSlowLab = new QLabel(verticalLayoutWidget);
        rightSlowLab->setObjectName(QStringLiteral("rightSlowLab"));
        rightSlowLab->setEnabled(false);

        gridLayout_3->addWidget(rightSlowLab, 1, 0, 1, 1);

        rightB2SlowTest = new QPushButton(verticalLayoutWidget);
        rightB2SlowTest->setObjectName(QStringLiteral("rightB2SlowTest"));
        rightB2SlowTest->setEnabled(false);

        gridLayout_3->addWidget(rightB2SlowTest, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        WBSDDoserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDDoserWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDDoserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDDoserWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDDoserWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(leftB2Test, rightB2Test);

        retranslateUi(WBSDDoserWindow);

        QMetaObject::connectSlotsByName(WBSDDoserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDDoserWindow)
    {
        WBSDDoserWindow->setWindowTitle(QApplication::translate("WBSDDoserWindow", "B2 doser system", 0));
        rightB2Test->setText(QApplication::translate("WBSDDoserWindow", "Activate", 0));
        label->setText(QApplication::translate("WBSDDoserWindow", "Right B2 test", 0));
        leftB2Test->setText(QApplication::translate("WBSDDoserWindow", "Activate", 0));
        label_2->setText(QApplication::translate("WBSDDoserWindow", "Left B2 test", 0));
        leftB2SlowTest->setText(QApplication::translate("WBSDDoserWindow", "Activate", 0));
        leftSlowLab->setText(QApplication::translate("WBSDDoserWindow", "Left B2 slow test", 0));
        rightSlowLab->setText(QApplication::translate("WBSDDoserWindow", "Right B2 slow test", 0));
        rightB2SlowTest->setText(QApplication::translate("WBSDDoserWindow", "Activate", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDDoserWindow: public Ui_WBSDDoserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDDOSERWINDOW_H

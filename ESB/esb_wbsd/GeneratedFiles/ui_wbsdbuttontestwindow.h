/********************************************************************************
** Form generated from reading UI file 'wbsdbuttontestwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDBUTTONTESTWINDOW_H
#define UI_WBSDBUTTONTESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDButtonTestWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *button9;
    QPushButton *button10;
    QPushButton *button11;
    QLabel *label_2;
    QGridLayout *gridLayout_3;
    QPushButton *button3;
    QPushButton *button6;
    QPushButton *button1;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button2;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button12;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDButtonTestWindow)
    {
        if (WBSDButtonTestWindow->objectName().isEmpty())
            WBSDButtonTestWindow->setObjectName(QStringLiteral("WBSDButtonTestWindow"));
        WBSDButtonTestWindow->resize(622, 585);
        centralwidget = new QWidget(WBSDButtonTestWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 40, 551, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(20);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(30, 30, 10, 30);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(100, -1, -1, -1);
        button9 = new QPushButton(gridLayoutWidget);
        button9->setObjectName(QStringLiteral("button9"));
        button9->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button9->sizePolicy().hasHeightForWidth());
        button9->setSizePolicy(sizePolicy);
        button9->setMinimumSize(QSize(80, 37));

        horizontalLayout->addWidget(button9);

        button10 = new QPushButton(gridLayoutWidget);
        button10->setObjectName(QStringLiteral("button10"));
        button10->setEnabled(true);
        sizePolicy.setHeightForWidth(button10->sizePolicy().hasHeightForWidth());
        button10->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button10);

        button11 = new QPushButton(gridLayoutWidget);
        button11->setObjectName(QStringLiteral("button11"));
        button11->setEnabled(true);
        sizePolicy.setHeightForWidth(button11->sizePolicy().hasHeightForWidth());
        button11->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button11);


        gridLayout->addLayout(horizontalLayout, 1, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(17);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setHorizontalSpacing(30);
        gridLayout_3->setVerticalSpacing(20);
        gridLayout_3->setContentsMargins(10, 10, 10, 10);
        button3 = new QPushButton(gridLayoutWidget);
        button3->setObjectName(QStringLiteral("button3"));
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button3, 2, 2, 1, 1);

        button6 = new QPushButton(gridLayoutWidget);
        button6->setObjectName(QStringLiteral("button6"));
        sizePolicy.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button6, 2, 3, 1, 1);

        button1 = new QPushButton(gridLayoutWidget);
        button1->setObjectName(QStringLiteral("button1"));
        sizePolicy.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button1, 0, 2, 1, 1);

        button4 = new QPushButton(gridLayoutWidget);
        button4->setObjectName(QStringLiteral("button4"));
        sizePolicy.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button4, 0, 3, 1, 1);

        button5 = new QPushButton(gridLayoutWidget);
        button5->setObjectName(QStringLiteral("button5"));
        sizePolicy.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button5, 1, 3, 1, 1);

        button2 = new QPushButton(gridLayoutWidget);
        button2->setObjectName(QStringLiteral("button2"));
        sizePolicy.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button2, 1, 2, 1, 1);

        button7 = new QPushButton(gridLayoutWidget);
        button7->setObjectName(QStringLiteral("button7"));
        sizePolicy.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button7, 0, 1, 1, 1);

        button8 = new QPushButton(gridLayoutWidget);
        button8->setObjectName(QStringLiteral("button8"));
        sizePolicy.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(button8, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 2, 2, 1, 1);

        button12 = new QPushButton(gridLayoutWidget);
        button12->setObjectName(QStringLiteral("button12"));
        sizePolicy.setHeightForWidth(button12->sizePolicy().hasHeightForWidth());
        button12->setSizePolicy(sizePolicy);

        gridLayout->addWidget(button12, 1, 0, 1, 1);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 1, 1, 1);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy1);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setRowStretch(2, 8);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(2, 5);
        WBSDButtonTestWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDButtonTestWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 622, 21));
        WBSDButtonTestWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDButtonTestWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDButtonTestWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(button1, button2);
        QWidget::setTabOrder(button2, button3);
        QWidget::setTabOrder(button3, button4);
        QWidget::setTabOrder(button4, button5);
        QWidget::setTabOrder(button5, button6);
        QWidget::setTabOrder(button6, button7);
        QWidget::setTabOrder(button7, button8);
        QWidget::setTabOrder(button8, button9);
        QWidget::setTabOrder(button9, button10);
        QWidget::setTabOrder(button10, button11);

        retranslateUi(WBSDButtonTestWindow);

        QMetaObject::connectSlotsByName(WBSDButtonTestWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDButtonTestWindow)
    {
        WBSDButtonTestWindow->setWindowTitle(QApplication::translate("WBSDButtonTestWindow", "Button test", 0));
        label->setText(QApplication::translate("WBSDButtonTestWindow", "Side Door", 0));
        button9->setText(QString());
        button10->setText(QString());
        button11->setText(QString());
        label_2->setText(QApplication::translate("WBSDButtonTestWindow", "Front Door", 0));
        button3->setText(QString());
        button6->setText(QString());
        button1->setText(QString());
        button4->setText(QString());
        button5->setText(QString());
        button2->setText(QString());
        button7->setText(QString());
        button8->setText(QString());
        button12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WBSDButtonTestWindow: public Ui_WBSDButtonTestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDBUTTONTESTWINDOW_H

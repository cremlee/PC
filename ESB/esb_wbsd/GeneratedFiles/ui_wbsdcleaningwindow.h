/********************************************************************************
** Form generated from reading UI file 'wbsdcleaningwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDCLEANINGWINDOW_H
#define UI_WBSDCLEANINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDCleaningWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *flLabSaturday_2;
    QComboBox *cb_auto_flag;
    QComboBox *flFriday;
    QComboBox *clTuesday;
    QFrame *line;
    QFrame *line_4;
    QComboBox *flWednesday;
    QFrame *line_2;
    QComboBox *clSunday;
    QLabel *flLabTuesday;
    QLabel *label;
    QComboBox *flushMode;
    QLabel *clLabWednesday;
    QComboBox *flThursday;
    QLabel *clLabSaturday;
    QLabel *flLabSaturday;
    QLabel *clLabMonday;
    QComboBox *flSunday;
    QComboBox *clSaturday;
    QComboBox *cleanMode;
    QLabel *clLabThursday;
    QComboBox *clFriday;
    QLabel *flLabThursday;
    QLabel *flLabWednesday;
    QComboBox *clThursday;
    QComboBox *flTuesday;
    QComboBox *flSaturday;
    QLabel *clLabSunday;
    QLabel *flLabMonday;
    QLabel *clLabFriday;
    QComboBox *clWednesday;
    QLabel *clLabTuesday;
    QLabel *flLabFriday;
    QComboBox *clMonday;
    QLabel *flLabSunday;
    QComboBox *flMonday;
    QLabel *cleanLabMode;
    QFrame *line_3;
    QFrame *line_5;
    QFrame *line_6;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WBSDCleaningWindow)
    {
        if (WBSDCleaningWindow->objectName().isEmpty())
            WBSDCleaningWindow->setObjectName(QStringLiteral("WBSDCleaningWindow"));
        WBSDCleaningWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDCleaningWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 751, 521));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(50, 0, 50, 0);
        flLabSaturday_2 = new QLabel(gridLayoutWidget);
        flLabSaturday_2->setObjectName(QStringLiteral("flLabSaturday_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(flLabSaturday_2->sizePolicy().hasHeightForWidth());
        flLabSaturday_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(flLabSaturday_2, 19, 0, 1, 1);

        cb_auto_flag = new QComboBox(gridLayoutWidget);
        cb_auto_flag->setObjectName(QStringLiteral("cb_auto_flag"));

        gridLayout->addWidget(cb_auto_flag, 19, 1, 1, 1);

        flFriday = new QComboBox(gridLayoutWidget);
        flFriday->setObjectName(QStringLiteral("flFriday"));

        gridLayout->addWidget(flFriday, 16, 1, 1, 1);

        clTuesday = new QComboBox(gridLayoutWidget);
        clTuesday->setObjectName(QStringLiteral("clTuesday"));
        clTuesday->setEnabled(true);

        gridLayout->addWidget(clTuesday, 4, 1, 1, 1);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 9, 0, 1, 1);

        line_4 = new QFrame(gridLayoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 0, 1, 1, 1);

        flWednesday = new QComboBox(gridLayoutWidget);
        flWednesday->setObjectName(QStringLiteral("flWednesday"));

        gridLayout->addWidget(flWednesday, 14, 1, 1, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 9, 1, 1, 1);

        clSunday = new QComboBox(gridLayoutWidget);
        clSunday->setObjectName(QStringLiteral("clSunday"));
        clSunday->setEnabled(true);

        gridLayout->addWidget(clSunday, 2, 1, 1, 1);

        flLabTuesday = new QLabel(gridLayoutWidget);
        flLabTuesday->setObjectName(QStringLiteral("flLabTuesday"));

        gridLayout->addWidget(flLabTuesday, 13, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 10, 0, 1, 1);

        flushMode = new QComboBox(gridLayoutWidget);
        flushMode->setObjectName(QStringLiteral("flushMode"));

        gridLayout->addWidget(flushMode, 10, 1, 1, 1);

        clLabWednesday = new QLabel(gridLayoutWidget);
        clLabWednesday->setObjectName(QStringLiteral("clLabWednesday"));
        clLabWednesday->setEnabled(true);

        gridLayout->addWidget(clLabWednesday, 5, 0, 1, 1);

        flThursday = new QComboBox(gridLayoutWidget);
        flThursday->setObjectName(QStringLiteral("flThursday"));

        gridLayout->addWidget(flThursday, 15, 1, 1, 1);

        clLabSaturday = new QLabel(gridLayoutWidget);
        clLabSaturday->setObjectName(QStringLiteral("clLabSaturday"));
        clLabSaturday->setEnabled(true);

        gridLayout->addWidget(clLabSaturday, 8, 0, 1, 1);

        flLabSaturday = new QLabel(gridLayoutWidget);
        flLabSaturday->setObjectName(QStringLiteral("flLabSaturday"));

        gridLayout->addWidget(flLabSaturday, 17, 0, 1, 1);

        clLabMonday = new QLabel(gridLayoutWidget);
        clLabMonday->setObjectName(QStringLiteral("clLabMonday"));
        clLabMonday->setEnabled(true);

        gridLayout->addWidget(clLabMonday, 3, 0, 1, 1);

        flSunday = new QComboBox(gridLayoutWidget);
        flSunday->setObjectName(QStringLiteral("flSunday"));

        gridLayout->addWidget(flSunday, 11, 1, 1, 1);

        clSaturday = new QComboBox(gridLayoutWidget);
        clSaturday->setObjectName(QStringLiteral("clSaturday"));
        clSaturday->setEnabled(true);

        gridLayout->addWidget(clSaturday, 8, 1, 1, 1);

        cleanMode = new QComboBox(gridLayoutWidget);
        cleanMode->setObjectName(QStringLiteral("cleanMode"));

        gridLayout->addWidget(cleanMode, 1, 1, 1, 1);

        clLabThursday = new QLabel(gridLayoutWidget);
        clLabThursday->setObjectName(QStringLiteral("clLabThursday"));
        clLabThursday->setEnabled(true);

        gridLayout->addWidget(clLabThursday, 6, 0, 1, 1);

        clFriday = new QComboBox(gridLayoutWidget);
        clFriday->setObjectName(QStringLiteral("clFriday"));
        clFriday->setEnabled(true);

        gridLayout->addWidget(clFriday, 7, 1, 1, 1);

        flLabThursday = new QLabel(gridLayoutWidget);
        flLabThursday->setObjectName(QStringLiteral("flLabThursday"));

        gridLayout->addWidget(flLabThursday, 15, 0, 1, 1);

        flLabWednesday = new QLabel(gridLayoutWidget);
        flLabWednesday->setObjectName(QStringLiteral("flLabWednesday"));

        gridLayout->addWidget(flLabWednesday, 14, 0, 1, 1);

        clThursday = new QComboBox(gridLayoutWidget);
        clThursday->setObjectName(QStringLiteral("clThursday"));
        clThursday->setEnabled(true);

        gridLayout->addWidget(clThursday, 6, 1, 1, 1);

        flTuesday = new QComboBox(gridLayoutWidget);
        flTuesday->setObjectName(QStringLiteral("flTuesday"));

        gridLayout->addWidget(flTuesday, 13, 1, 1, 1);

        flSaturday = new QComboBox(gridLayoutWidget);
        flSaturday->setObjectName(QStringLiteral("flSaturday"));

        gridLayout->addWidget(flSaturday, 17, 1, 1, 1);

        clLabSunday = new QLabel(gridLayoutWidget);
        clLabSunday->setObjectName(QStringLiteral("clLabSunday"));
        clLabSunday->setEnabled(true);

        gridLayout->addWidget(clLabSunday, 2, 0, 1, 1);

        flLabMonday = new QLabel(gridLayoutWidget);
        flLabMonday->setObjectName(QStringLiteral("flLabMonday"));

        gridLayout->addWidget(flLabMonday, 12, 0, 1, 1);

        clLabFriday = new QLabel(gridLayoutWidget);
        clLabFriday->setObjectName(QStringLiteral("clLabFriday"));
        clLabFriday->setEnabled(true);

        gridLayout->addWidget(clLabFriday, 7, 0, 1, 1);

        clWednesday = new QComboBox(gridLayoutWidget);
        clWednesday->setObjectName(QStringLiteral("clWednesday"));
        clWednesday->setEnabled(true);

        gridLayout->addWidget(clWednesday, 5, 1, 1, 1);

        clLabTuesday = new QLabel(gridLayoutWidget);
        clLabTuesday->setObjectName(QStringLiteral("clLabTuesday"));
        clLabTuesday->setEnabled(true);

        gridLayout->addWidget(clLabTuesday, 4, 0, 1, 1);

        flLabFriday = new QLabel(gridLayoutWidget);
        flLabFriday->setObjectName(QStringLiteral("flLabFriday"));

        gridLayout->addWidget(flLabFriday, 16, 0, 1, 1);

        clMonday = new QComboBox(gridLayoutWidget);
        clMonday->setObjectName(QStringLiteral("clMonday"));
        clMonday->setEnabled(true);

        gridLayout->addWidget(clMonday, 3, 1, 1, 1);

        flLabSunday = new QLabel(gridLayoutWidget);
        flLabSunday->setObjectName(QStringLiteral("flLabSunday"));

        gridLayout->addWidget(flLabSunday, 11, 0, 1, 1);

        flMonday = new QComboBox(gridLayoutWidget);
        flMonday->setObjectName(QStringLiteral("flMonday"));

        gridLayout->addWidget(flMonday, 12, 1, 1, 1);

        cleanLabMode = new QLabel(gridLayoutWidget);
        cleanLabMode->setObjectName(QStringLiteral("cleanLabMode"));

        gridLayout->addWidget(cleanLabMode, 1, 0, 1, 1);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 0, 1, 1);

        line_5 = new QFrame(gridLayoutWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 20, 0, 1, 1);

        line_6 = new QFrame(gridLayoutWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 20, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 18, 0, 1, 1);

        WBSDCleaningWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDCleaningWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDCleaningWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WBSDCleaningWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDCleaningWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(cleanMode, clSunday);
        QWidget::setTabOrder(clSunday, clMonday);
        QWidget::setTabOrder(clMonday, clTuesday);
        QWidget::setTabOrder(clTuesday, clWednesday);
        QWidget::setTabOrder(clWednesday, clThursday);
        QWidget::setTabOrder(clThursday, clFriday);
        QWidget::setTabOrder(clFriday, clSaturday);
        QWidget::setTabOrder(clSaturday, flushMode);
        QWidget::setTabOrder(flushMode, flSunday);
        QWidget::setTabOrder(flSunday, flMonday);
        QWidget::setTabOrder(flMonday, flTuesday);
        QWidget::setTabOrder(flTuesday, flWednesday);
        QWidget::setTabOrder(flWednesday, flThursday);
        QWidget::setTabOrder(flThursday, flFriday);
        QWidget::setTabOrder(flFriday, flSaturday);

        retranslateUi(WBSDCleaningWindow);

        QMetaObject::connectSlotsByName(WBSDCleaningWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDCleaningWindow)
    {
        WBSDCleaningWindow->setWindowTitle(QApplication::translate("WBSDCleaningWindow", "Cleaning moment", 0));
        flLabSaturday_2->setText(QApplication::translate("WBSDCleaningWindow", "Cleanshot ", 0));
        flLabTuesday->setText(QApplication::translate("WBSDCleaningWindow", "Flushing on Tuesday", 0));
        label->setText(QApplication::translate("WBSDCleaningWindow", "Flushing mode", 0));
        clLabWednesday->setText(QApplication::translate("WBSDCleaningWindow", "Cleaning on Wednesday", 0));
        clLabSaturday->setText(QApplication::translate("WBSDCleaningWindow", "Cleaning on Saturday", 0));
        flLabSaturday->setText(QApplication::translate("WBSDCleaningWindow", "Flushing on Saturday", 0));
        clLabMonday->setText(QApplication::translate("WBSDCleaningWindow", "Cleaning on Monday", 0));
        clLabThursday->setText(QApplication::translate("WBSDCleaningWindow", "Cleaning on Thursday", 0));
        flLabThursday->setText(QApplication::translate("WBSDCleaningWindow", "Flushing on Thursday", 0));
        flLabWednesday->setText(QApplication::translate("WBSDCleaningWindow", "Flushing on Wednesday", 0));
        clLabSunday->setText(QApplication::translate("WBSDCleaningWindow", "Cleaning on Sunday", 0));
        flLabMonday->setText(QApplication::translate("WBSDCleaningWindow", "Flushing on Monday", 0));
        clLabFriday->setText(QApplication::translate("WBSDCleaningWindow", "Cleaning on Friday", 0));
        clLabTuesday->setText(QApplication::translate("WBSDCleaningWindow", "Cleaning on Tuesday", 0));
        flLabFriday->setText(QApplication::translate("WBSDCleaningWindow", "Flushing on Friday", 0));
        flLabSunday->setText(QApplication::translate("WBSDCleaningWindow", "Flushing on Sunday", 0));
        cleanLabMode->setText(QApplication::translate("WBSDCleaningWindow", "Cleaning mode", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDCleaningWindow: public Ui_WBSDCleaningWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDCLEANINGWINDOW_H

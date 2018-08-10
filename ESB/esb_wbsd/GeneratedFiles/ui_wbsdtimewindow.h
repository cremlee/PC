/********************************************************************************
** Form generated from reading UI file 'wbsdtimewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDTIMEWINDOW_H
#define UI_WBSDTIMEWINDOW_H

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDTimeWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *timeFormat;
    QLabel *currentDate;
    QLabel *currentTime;
    QPushButton *setDate;
    QPushButton *setTime;
    QVBoxLayout *verticalLayout;
    QPushButton *pbtn_skipclean;
    QPushButton *cleaningButton;
    QPushButton *ecoButton;
    QPushButton *pbtn_hpyhour;
    QGridLayout *gridLayout_2;
    QComboBox *dtsEnable;
    QLabel *dtsEndTimeLbl;
    QLabel *label_4;
    QComboBox *dtsStartTime;
    QLabel *dtsEndWeekLbl;
    QLabel *dtsEndDayLbl;
    QComboBox *dtsEndWeek;
    QLabel *dtsEndMonthLbl;
    QLabel *dtsStartDayLbl;
    QLabel *dtsStartWeekLbl;
    QLabel *dtsStartMonthLbl;
    QComboBox *dtsEndMonth;
    QComboBox *dtsStartWeek;
    QLabel *dtsStartTimeLbl;
    QComboBox *dtsStartDay;
    QComboBox *dtsEndDay;
    QComboBox *dtsEndTime;
    QComboBox *dtsStartMonth;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WBSDTimeWindow)
    {
        if (WBSDTimeWindow->objectName().isEmpty())
            WBSDTimeWindow->setObjectName(QStringLiteral("WBSDTimeWindow"));
        WBSDTimeWindow->resize(800, 600);
        centralwidget = new QWidget(WBSDTimeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(19, 19, 761, 451));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(50, 0, 50, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 0, -1);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        timeFormat = new QComboBox(verticalLayoutWidget_2);
        timeFormat->setObjectName(QStringLiteral("timeFormat"));

        gridLayout->addWidget(timeFormat, 2, 1, 1, 1);

        currentDate = new QLabel(verticalLayoutWidget_2);
        currentDate->setObjectName(QStringLiteral("currentDate"));

        gridLayout->addWidget(currentDate, 0, 1, 1, 1);

        currentTime = new QLabel(verticalLayoutWidget_2);
        currentTime->setObjectName(QStringLiteral("currentTime"));

        gridLayout->addWidget(currentTime, 1, 1, 1, 1);

        setDate = new QPushButton(verticalLayoutWidget_2);
        setDate->setObjectName(QStringLiteral("setDate"));

        gridLayout->addWidget(setDate, 0, 0, 1, 1);

        setTime = new QPushButton(verticalLayoutWidget_2);
        setTime->setObjectName(QStringLiteral("setTime"));

        gridLayout->addWidget(setTime, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        pbtn_skipclean = new QPushButton(verticalLayoutWidget_2);
        pbtn_skipclean->setObjectName(QStringLiteral("pbtn_skipclean"));

        verticalLayout->addWidget(pbtn_skipclean);

        cleaningButton = new QPushButton(verticalLayoutWidget_2);
        cleaningButton->setObjectName(QStringLiteral("cleaningButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cleaningButton->sizePolicy().hasHeightForWidth());
        cleaningButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(cleaningButton);

        ecoButton = new QPushButton(verticalLayoutWidget_2);
        ecoButton->setObjectName(QStringLiteral("ecoButton"));

        verticalLayout->addWidget(ecoButton);

        pbtn_hpyhour = new QPushButton(verticalLayoutWidget_2);
        pbtn_hpyhour->setObjectName(QStringLiteral("pbtn_hpyhour"));

        verticalLayout->addWidget(pbtn_hpyhour);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        dtsEnable = new QComboBox(verticalLayoutWidget_2);
        dtsEnable->setObjectName(QStringLiteral("dtsEnable"));

        gridLayout_2->addWidget(dtsEnable, 0, 1, 1, 1);

        dtsEndTimeLbl = new QLabel(verticalLayoutWidget_2);
        dtsEndTimeLbl->setObjectName(QStringLiteral("dtsEndTimeLbl"));

        gridLayout_2->addWidget(dtsEndTimeLbl, 8, 0, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        dtsStartTime = new QComboBox(verticalLayoutWidget_2);
        dtsStartTime->setObjectName(QStringLiteral("dtsStartTime"));

        gridLayout_2->addWidget(dtsStartTime, 4, 1, 1, 1);

        dtsEndWeekLbl = new QLabel(verticalLayoutWidget_2);
        dtsEndWeekLbl->setObjectName(QStringLiteral("dtsEndWeekLbl"));

        gridLayout_2->addWidget(dtsEndWeekLbl, 6, 0, 1, 1);

        dtsEndDayLbl = new QLabel(verticalLayoutWidget_2);
        dtsEndDayLbl->setObjectName(QStringLiteral("dtsEndDayLbl"));

        gridLayout_2->addWidget(dtsEndDayLbl, 7, 0, 1, 1);

        dtsEndWeek = new QComboBox(verticalLayoutWidget_2);
        dtsEndWeek->setObjectName(QStringLiteral("dtsEndWeek"));

        gridLayout_2->addWidget(dtsEndWeek, 6, 1, 1, 1);

        dtsEndMonthLbl = new QLabel(verticalLayoutWidget_2);
        dtsEndMonthLbl->setObjectName(QStringLiteral("dtsEndMonthLbl"));

        gridLayout_2->addWidget(dtsEndMonthLbl, 5, 0, 1, 1);

        dtsStartDayLbl = new QLabel(verticalLayoutWidget_2);
        dtsStartDayLbl->setObjectName(QStringLiteral("dtsStartDayLbl"));

        gridLayout_2->addWidget(dtsStartDayLbl, 3, 0, 1, 1);

        dtsStartWeekLbl = new QLabel(verticalLayoutWidget_2);
        dtsStartWeekLbl->setObjectName(QStringLiteral("dtsStartWeekLbl"));

        gridLayout_2->addWidget(dtsStartWeekLbl, 2, 0, 1, 1);

        dtsStartMonthLbl = new QLabel(verticalLayoutWidget_2);
        dtsStartMonthLbl->setObjectName(QStringLiteral("dtsStartMonthLbl"));

        gridLayout_2->addWidget(dtsStartMonthLbl, 1, 0, 1, 1);

        dtsEndMonth = new QComboBox(verticalLayoutWidget_2);
        dtsEndMonth->setObjectName(QStringLiteral("dtsEndMonth"));

        gridLayout_2->addWidget(dtsEndMonth, 5, 1, 1, 1);

        dtsStartWeek = new QComboBox(verticalLayoutWidget_2);
        dtsStartWeek->setObjectName(QStringLiteral("dtsStartWeek"));

        gridLayout_2->addWidget(dtsStartWeek, 2, 1, 1, 1);

        dtsStartTimeLbl = new QLabel(verticalLayoutWidget_2);
        dtsStartTimeLbl->setObjectName(QStringLiteral("dtsStartTimeLbl"));

        gridLayout_2->addWidget(dtsStartTimeLbl, 4, 0, 1, 1);

        dtsStartDay = new QComboBox(verticalLayoutWidget_2);
        dtsStartDay->setObjectName(QStringLiteral("dtsStartDay"));

        gridLayout_2->addWidget(dtsStartDay, 3, 1, 1, 1);

        dtsEndDay = new QComboBox(verticalLayoutWidget_2);
        dtsEndDay->setObjectName(QStringLiteral("dtsEndDay"));

        gridLayout_2->addWidget(dtsEndDay, 7, 1, 1, 1);

        dtsEndTime = new QComboBox(verticalLayoutWidget_2);
        dtsEndTime->setObjectName(QStringLiteral("dtsEndTime"));

        gridLayout_2->addWidget(dtsEndTime, 8, 1, 1, 1);

        dtsStartMonth = new QComboBox(verticalLayoutWidget_2);
        dtsStartMonth->setObjectName(QStringLiteral("dtsStartMonth"));

        gridLayout_2->addWidget(dtsStartMonth, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        WBSDTimeWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WBSDTimeWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WBSDTimeWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(WBSDTimeWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WBSDTimeWindow->setMenuBar(menubar);
        QWidget::setTabOrder(setDate, setTime);
        QWidget::setTabOrder(setTime, timeFormat);
        QWidget::setTabOrder(timeFormat, ecoButton);
        QWidget::setTabOrder(ecoButton, dtsEnable);
        QWidget::setTabOrder(dtsEnable, dtsStartMonth);
        QWidget::setTabOrder(dtsStartMonth, dtsStartWeek);
        QWidget::setTabOrder(dtsStartWeek, dtsStartDay);
        QWidget::setTabOrder(dtsStartDay, dtsStartTime);
        QWidget::setTabOrder(dtsStartTime, dtsEndMonth);
        QWidget::setTabOrder(dtsEndMonth, dtsEndWeek);
        QWidget::setTabOrder(dtsEndWeek, dtsEndDay);
        QWidget::setTabOrder(dtsEndDay, dtsEndTime);

        retranslateUi(WBSDTimeWindow);

        QMetaObject::connectSlotsByName(WBSDTimeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDTimeWindow)
    {
        WBSDTimeWindow->setWindowTitle(QApplication::translate("WBSDTimeWindow", "Time & Event", 0));
        label_3->setText(QApplication::translate("WBSDTimeWindow", "Format time representation", 0));
        currentDate->setText(QString());
        currentTime->setText(QString());
        setDate->setText(QApplication::translate("WBSDTimeWindow", "Set current date", 0));
        setTime->setText(QApplication::translate("WBSDTimeWindow", "Set current time", 0));
        pbtn_skipclean->setText(QApplication::translate("WBSDTimeWindow", "Skip cleaning/flushing overdue", 0));
        cleaningButton->setText(QApplication::translate("WBSDTimeWindow", "Cleaning moment", 0));
        ecoButton->setText(QApplication::translate("WBSDTimeWindow", "ECO moment", 0));
        pbtn_hpyhour->setText(QApplication::translate("WBSDTimeWindow", "Happy Hour setting", 0));
        dtsEndTimeLbl->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving end - time (hour)", 0));
        label_4->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving", 0));
        dtsEndWeekLbl->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving end - week", 0));
        dtsEndDayLbl->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving end - day", 0));
        dtsEndMonthLbl->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving end - month", 0));
        dtsStartDayLbl->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving start - day", 0));
        dtsStartWeekLbl->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving start - week", 0));
        dtsStartMonthLbl->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving start - month", 0));
        dtsStartTimeLbl->setText(QApplication::translate("WBSDTimeWindow", "Daylight saving start - time (hour)", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDTimeWindow: public Ui_WBSDTimeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDTIMEWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'wbsd_happyhour.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSD_HAPPYHOUR_H
#define UI_WBSD_HAPPYHOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wbsdHappyHour
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout1;
    QCheckBox *chb_mode1;
    QCheckBox *chb_mode2;
    QCheckBox *chb_mode3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_11;
    QLabel *label;
    QFrame *line;
    QGridLayout *gridLayout2;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QTimeEdit *mode1_tes;
    QTimeEdit *mode1_tee;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout3;
    QLabel *label_5;
    QTimeEdit *mode2_tes;
    QLabel *label_6;
    QTimeEdit *mod2_tee;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout4;
    QLabel *label_8;
    QTimeEdit *mod3_tes;
    QLabel *label_9;
    QTimeEdit *mod3_tee;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wbsdHappyHour)
    {
        if (wbsdHappyHour->objectName().isEmpty())
            wbsdHappyHour->setObjectName(QStringLiteral("wbsdHappyHour"));
        wbsdHappyHour->resize(800, 600);
        centralwidget = new QWidget(wbsdHappyHour);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 40, 878, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        gridLayout1->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout1->setVerticalSpacing(2);
        chb_mode1 = new QCheckBox(verticalLayoutWidget);
        chb_mode1->setObjectName(QStringLiteral("chb_mode1"));
        QFont font;
        font.setPointSize(12);
        chb_mode1->setFont(font);
        chb_mode1->setLayoutDirection(Qt::RightToLeft);
        chb_mode1->setAutoFillBackground(false);
        chb_mode1->setTristate(false);

        gridLayout1->addWidget(chb_mode1, 1, 1, 1, 1);

        chb_mode2 = new QCheckBox(verticalLayoutWidget);
        chb_mode2->setObjectName(QStringLiteral("chb_mode2"));
        chb_mode2->setFont(font);
        chb_mode2->setLayoutDirection(Qt::RightToLeft);

        gridLayout1->addWidget(chb_mode2, 2, 1, 1, 1);

        chb_mode3 = new QCheckBox(verticalLayoutWidget);
        chb_mode3->setObjectName(QStringLiteral("chb_mode3"));
        chb_mode3->setFont(font);
        chb_mode3->setLayoutDirection(Qt::RightToLeft);

        gridLayout1->addWidget(chb_mode3, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(label_11, 0, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 22));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(false);
        label->setMargin(-1);

        gridLayout1->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout1);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        gridLayout2 = new QGridLayout();
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        gridLayout2->setVerticalSpacing(2);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4->setWordWrap(false);
        label_4->setMargin(-1);

        gridLayout2->addWidget(label_4, 2, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 17));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(false);
        label_2->setMargin(-1);

        gridLayout2->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3->setWordWrap(false);
        label_3->setMargin(-1);

        gridLayout2->addWidget(label_3, 1, 1, 1, 1);

        mode1_tes = new QTimeEdit(verticalLayoutWidget);
        mode1_tes->setObjectName(QStringLiteral("mode1_tes"));

        gridLayout2->addWidget(mode1_tes, 1, 2, 1, 1);

        mode1_tee = new QTimeEdit(verticalLayoutWidget);
        mode1_tee->setObjectName(QStringLiteral("mode1_tee"));

        gridLayout2->addWidget(mode1_tee, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout2->addItem(horizontalSpacer, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout2);

        gridLayout3 = new QGridLayout();
        gridLayout3->setObjectName(QStringLiteral("gridLayout3"));
        gridLayout3->setHorizontalSpacing(6);
        gridLayout3->setVerticalSpacing(2);
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);
        label_5->setTextFormat(Qt::AutoText);
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_5->setWordWrap(false);
        label_5->setMargin(-1);

        gridLayout3->addWidget(label_5, 1, 1, 1, 1);

        mode2_tes = new QTimeEdit(verticalLayoutWidget);
        mode2_tes->setObjectName(QStringLiteral("mode2_tes"));

        gridLayout3->addWidget(mode2_tes, 1, 2, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(0, 18));
        label_6->setFont(font3);
        label_6->setTextFormat(Qt::AutoText);
        label_6->setScaledContents(false);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_6->setWordWrap(false);
        label_6->setMargin(-1);

        gridLayout3->addWidget(label_6, 0, 0, 1, 1);

        mod2_tee = new QTimeEdit(verticalLayoutWidget);
        mod2_tee->setObjectName(QStringLiteral("mod2_tee"));

        gridLayout3->addWidget(mod2_tee, 2, 2, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);
        label_7->setTextFormat(Qt::AutoText);
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_7->setWordWrap(false);
        label_7->setMargin(-1);

        gridLayout3->addWidget(label_7, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout3->addItem(horizontalSpacer_3, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout3);

        gridLayout4 = new QGridLayout();
        gridLayout4->setObjectName(QStringLiteral("gridLayout4"));
        gridLayout4->setVerticalSpacing(2);
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);
        label_8->setTextFormat(Qt::AutoText);
        label_8->setScaledContents(false);
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_8->setWordWrap(false);
        label_8->setMargin(-1);

        gridLayout4->addWidget(label_8, 1, 1, 1, 1);

        mod3_tes = new QTimeEdit(verticalLayoutWidget);
        mod3_tes->setObjectName(QStringLiteral("mod3_tes"));

        gridLayout4->addWidget(mod3_tes, 1, 2, 1, 1);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(0, 18));
        label_9->setFont(font3);
        label_9->setTextFormat(Qt::AutoText);
        label_9->setScaledContents(false);
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_9->setWordWrap(false);
        label_9->setMargin(-1);

        gridLayout4->addWidget(label_9, 0, 0, 1, 1);

        mod3_tee = new QTimeEdit(verticalLayoutWidget);
        mod3_tee->setObjectName(QStringLiteral("mod3_tee"));

        gridLayout4->addWidget(mod3_tee, 2, 2, 1, 1);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font2);
        label_10->setTextFormat(Qt::AutoText);
        label_10->setScaledContents(false);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_10->setWordWrap(false);
        label_10->setMargin(-1);

        gridLayout4->addWidget(label_10, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout4->addItem(horizontalSpacer_4, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout4);

        wbsdHappyHour->setCentralWidget(centralwidget);
        menubar = new QMenuBar(wbsdHappyHour);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        wbsdHappyHour->setMenuBar(menubar);
        statusbar = new QStatusBar(wbsdHappyHour);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        wbsdHappyHour->setStatusBar(statusbar);

        retranslateUi(wbsdHappyHour);

        QMetaObject::connectSlotsByName(wbsdHappyHour);
    } // setupUi

    void retranslateUi(QMainWindow *wbsdHappyHour)
    {
        wbsdHappyHour->setWindowTitle(QApplication::translate("wbsdHappyHour", "Happy hour setting", 0));
        chb_mode1->setText(QApplication::translate("wbsdHappyHour", "Happy hour mode 1           ", 0));
        chb_mode2->setText(QApplication::translate("wbsdHappyHour", "Happy hour mode 2           ", 0));
        chb_mode3->setText(QApplication::translate("wbsdHappyHour", "Happy hour mode 3           ", 0));
        label_11->setText(QApplication::translate("wbsdHappyHour", "Checked =  Enable,Unchecked = Disable", 0));
        label->setText(QApplication::translate("wbsdHappyHour", " Happy Hour Mode Selection ", 0));
        label_4->setText(QApplication::translate("wbsdHappyHour", "Happy Hour End Time", 0));
        label_2->setText(QApplication::translate("wbsdHappyHour", "Happy Hour Mode1 Setting", 0));
        label_3->setText(QApplication::translate("wbsdHappyHour", "Happy Hour Start Time", 0));
        mode1_tes->setDisplayFormat(QApplication::translate("wbsdHappyHour", "HH:mm", 0));
        mode1_tee->setDisplayFormat(QApplication::translate("wbsdHappyHour", "HH:mm", 0));
        label_5->setText(QApplication::translate("wbsdHappyHour", "Happy Hour Start Time", 0));
        mode2_tes->setDisplayFormat(QApplication::translate("wbsdHappyHour", "HH:mm", 0));
        label_6->setText(QApplication::translate("wbsdHappyHour", "Happy Hour Mode2 Setting", 0));
        mod2_tee->setDisplayFormat(QApplication::translate("wbsdHappyHour", "HH:mm", 0));
        label_7->setText(QApplication::translate("wbsdHappyHour", "Happy Hour End Time", 0));
        label_8->setText(QApplication::translate("wbsdHappyHour", "Happy Hour Start Time", 0));
        mod3_tes->setDisplayFormat(QApplication::translate("wbsdHappyHour", "HH:mm", 0));
        label_9->setText(QApplication::translate("wbsdHappyHour", "Happy Hour Mode3 Setting", 0));
        mod3_tee->setDisplayFormat(QApplication::translate("wbsdHappyHour", "HH:mm", 0));
        label_10->setText(QApplication::translate("wbsdHappyHour", "Happy Hour End Time", 0));
    } // retranslateUi

};

namespace Ui {
    class wbsdHappyHour: public Ui_wbsdHappyHour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSD_HAPPYHOUR_H

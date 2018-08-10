/********************************************************************************
** Form generated from reading UI file 'wbsd_clone.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSD_CLONE_H
#define UI_WBSD_CLONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wbsdclone
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *line_6;
    QProgressBar *progressBar;
    QFrame *line_3;
    QPushButton *btn_restore;
    QPushButton *btn_backup;
    QLabel *label_4;
    QProgressBar *progressBar_3;
    QVBoxLayout *verticalLayout;
    QPushButton *btnd;
    QPushButton *btnr;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnlang;
    QPushButton *btnlang_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QFrame *line;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QProgressBar *progressBar_2;
    QFrame *line_11;
    QPushButton *btn_clear;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wbsdclone)
    {
        if (wbsdclone->objectName().isEmpty())
            wbsdclone->setObjectName(QStringLiteral("wbsdclone"));
        wbsdclone->resize(746, 537);
        centralwidget = new QWidget(wbsdclone);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 682, 475));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line_6 = new QFrame(gridLayoutWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line_6->sizePolicy().hasHeightForWidth());
        line_6->setSizePolicy(sizePolicy);
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 8, 0, 1, 4);

        progressBar = new QProgressBar(gridLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMaximumSize(QSize(256, 16777215));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 3, 1, 1, 2);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy2);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 2, 1, 1, 3);

        btn_restore = new QPushButton(gridLayoutWidget);
        btn_restore->setObjectName(QStringLiteral("btn_restore"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_restore->sizePolicy().hasHeightForWidth());
        btn_restore->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(btn_restore, 11, 1, 1, 1);

        btn_backup = new QPushButton(gridLayoutWidget);
        btn_backup->setObjectName(QStringLiteral("btn_backup"));

        gridLayout->addWidget(btn_backup, 11, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        label_4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(label_4, 11, 2, 1, 2);

        progressBar_3 = new QProgressBar(gridLayoutWidget);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        sizePolicy1.setHeightForWidth(progressBar_3->sizePolicy().hasHeightForWidth());
        progressBar_3->setSizePolicy(sizePolicy1);
        progressBar_3->setValue(0);

        gridLayout->addWidget(progressBar_3, 4, 1, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnd = new QPushButton(gridLayoutWidget);
        btnd->setObjectName(QStringLiteral("btnd"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnd->sizePolicy().hasHeightForWidth());
        btnd->setSizePolicy(sizePolicy5);
        btnd->setMinimumSize(QSize(112, 60));
        btnd->setMaximumSize(QSize(100, 60));

        verticalLayout->addWidget(btnd);

        btnr = new QPushButton(gridLayoutWidget);
        btnr->setObjectName(QStringLiteral("btnr"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btnr->sizePolicy().hasHeightForWidth());
        btnr->setSizePolicy(sizePolicy6);
        btnr->setMinimumSize(QSize(112, 60));
        btnr->setMaximumSize(QSize(100, 60));

        verticalLayout->addWidget(btnr);


        gridLayout->addLayout(verticalLayout, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnlang = new QPushButton(gridLayoutWidget);
        btnlang->setObjectName(QStringLiteral("btnlang"));
        sizePolicy5.setHeightForWidth(btnlang->sizePolicy().hasHeightForWidth());
        btnlang->setSizePolicy(sizePolicy5);
        btnlang->setMinimumSize(QSize(112, 60));
        btnlang->setMaximumSize(QSize(16777215, 60));

        verticalLayout_2->addWidget(btnlang);

        btnlang_2 = new QPushButton(gridLayoutWidget);
        btnlang_2->setObjectName(QStringLiteral("btnlang_2"));
        sizePolicy5.setHeightForWidth(btnlang_2->sizePolicy().hasHeightForWidth());
        btnlang_2->setSizePolicy(sizePolicy5);
        btnlang_2->setMinimumSize(QSize(0, 60));
        btnlang_2->setMaximumSize(QSize(112, 60));

        verticalLayout_2->addWidget(btnlang_2);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy7);
        QFont font;
        font.setPointSize(8);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy7.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy7);
        label_7->setFont(font);
        label_7->setTextFormat(Qt::PlainText);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(false);

        verticalLayout_3->addWidget(label_7);


        gridLayout->addLayout(verticalLayout_3, 1, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 5, 3, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy8);

        gridLayout->addWidget(label, 3, 3, 1, 1);

        plainTextEdit = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(4);
        sizePolicy9.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy9);

        gridLayout->addWidget(plainTextEdit, 1, 0, 5, 1);

        progressBar_2 = new QProgressBar(gridLayoutWidget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        sizePolicy1.setHeightForWidth(progressBar_2->sizePolicy().hasHeightForWidth());
        progressBar_2->setSizePolicy(sizePolicy1);
        progressBar_2->setValue(0);

        gridLayout->addWidget(progressBar_2, 5, 1, 1, 2);

        line_11 = new QFrame(gridLayoutWidget);
        line_11->setObjectName(QStringLiteral("line_11"));
        sizePolicy2.setHeightForWidth(line_11->sizePolicy().hasHeightForWidth());
        line_11->setSizePolicy(sizePolicy2);
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_11, 0, 1, 1, 3);

        btn_clear = new QPushButton(gridLayoutWidget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setMaximumSize(QSize(120, 16777215));
        btn_clear->setLayoutDirection(Qt::LeftToRight);
        btn_clear->setAutoDefault(false);

        gridLayout->addWidget(btn_clear, 7, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 3, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(1);
        sizePolicy10.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy10);

        gridLayout->addWidget(pushButton, 10, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(1);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy11);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 10, 2, 1, 2);

        wbsdclone->setCentralWidget(centralwidget);
        menubar = new QMenuBar(wbsdclone);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 746, 21));
        wbsdclone->setMenuBar(menubar);
        statusbar = new QStatusBar(wbsdclone);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        wbsdclone->setStatusBar(statusbar);

        retranslateUi(wbsdclone);

        QMetaObject::connectSlotsByName(wbsdclone);
    } // setupUi

    void retranslateUi(QMainWindow *wbsdclone)
    {
        wbsdclone->setWindowTitle(QApplication::translate("wbsdclone", "MainWindow", 0));
        btn_restore->setText(QApplication::translate("wbsdclone", "Restore", 0));
        btn_backup->setText(QApplication::translate("wbsdclone", "Backup", 0));
        label_4->setText(QApplication::translate("wbsdclone", " This function is only used to recovery customer setting\n"
" after update firmware.The backup file (only for update \n"
" from MCB SW <0.99 to MCB SW 1.10)includes counters, \n"
" button layout, configuration,cleaning settings, eco \n"
" settings and display settings.Please note that \n"
" instant milk recipes will have to be reprogrammed.", 0));
        btnd->setText(QApplication::translate("wbsdclone", "upload database\n"
" to dispenser", 0));
        btnr->setText(QApplication::translate("wbsdclone", "upload machine\n"
" recipesto dispenser", 0));
        btnlang->setText(QApplication::translate("wbsdclone", "clone database \n"
" from dispenser", 0));
        btnlang_2->setText(QApplication::translate("wbsdclone", "clone machine recipes\n"
"  from  dispenser", 0));
        label_6->setText(QApplication::translate("wbsdclone", "This function is used to clone or \n"
"upload machine setting from one to\n"
"another. Database contains \342\200\234drink \n"
"button settings(recipe under button)\n"
"configuration, eco settings, \342\200\246 It \n"
"does not clone counter info and\n"
"recipe settings (volume,ratio)", 0));
        label_7->setText(QApplication::translate("wbsdclone", "This function is used to clone\n"
"or upload machine recipes from\n"
"one to another.When cloning \n"
"recipes,the machine recipes will\n"
"be copied to the computer. When\n"
"uploading machine recipes,the\n"
"the drink settings will be overwriten", 0));
        label_2->setText(QApplication::translate("wbsdclone", "backup&restore", 0));
        label->setText(QApplication::translate("wbsdclone", "database", 0));
        btn_clear->setText(QApplication::translate("wbsdclone", "Clear Text", 0));
        label_3->setText(QApplication::translate("wbsdclone", "recipe", 0));
        pushButton->setText(QApplication::translate("wbsdclone", "clone/upload external\n"
"module setting", 0));
        label_5->setText(QApplication::translate("wbsdclone", "clone/upload setting from external module", 0));
    } // retranslateUi

};

namespace Ui {
    class wbsdclone: public Ui_wbsdclone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSD_CLONE_H

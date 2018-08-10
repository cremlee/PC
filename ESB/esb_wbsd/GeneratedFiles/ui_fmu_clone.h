/********************************************************************************
** Form generated from reading UI file 'fmu_clone.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMU_CLONE_H
#define UI_FMU_CLONE_H

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

class Ui_FMU_CLONE
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QProgressBar *pb_set;
    QFrame *line_3;
    QPushButton *btn_clear;
    QLabel *label_3;
    QFrame *line_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_4;
    QLabel *label;
    QPlainTextEdit *lsbox;
    QFrame *line_11;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_upload_set;
    QPushButton *btn_upload_rcp;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_clone_set;
    QPushButton *btn_clone_rcp;
    QProgressBar *pb_rcp;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FMU_CLONE)
    {
        if (FMU_CLONE->objectName().isEmpty())
            FMU_CLONE->setObjectName(QStringLiteral("FMU_CLONE"));
        FMU_CLONE->resize(789, 522);
        centralwidget = new QWidget(FMU_CLONE);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 0, 760, 475));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_set = new QProgressBar(gridLayoutWidget_2);
        pb_set->setObjectName(QStringLiteral("pb_set"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_set->sizePolicy().hasHeightForWidth());
        pb_set->setSizePolicy(sizePolicy);
        pb_set->setMaximumSize(QSize(256, 16777215));
        pb_set->setValue(0);

        gridLayout_2->addWidget(pb_set, 3, 1, 1, 2);

        line_3 = new QFrame(gridLayoutWidget_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy1);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 2, 1, 1, 3);

        btn_clear = new QPushButton(gridLayoutWidget_2);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setMaximumSize(QSize(120, 16777215));
        btn_clear->setLayoutDirection(Qt::LeftToRight);
        btn_clear->setAutoDefault(false);

        gridLayout_2->addWidget(btn_clear, 7, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 4, 3, 1, 1);

        line_6 = new QFrame(gridLayoutWidget_2);
        line_6->setObjectName(QStringLiteral("line_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line_6->sizePolicy().hasHeightForWidth());
        line_6->setSizePolicy(sizePolicy2);
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_6, 8, 0, 1, 4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout_3->addWidget(label_2);

        line = new QFrame(gridLayoutWidget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_3->addWidget(label_4);


        gridLayout_2->addLayout(verticalLayout_3, 1, 3, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setFont(font);

        gridLayout_2->addWidget(label, 3, 3, 1, 1);

        lsbox = new QPlainTextEdit(gridLayoutWidget_2);
        lsbox->setObjectName(QStringLiteral("lsbox"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(4);
        sizePolicy4.setHeightForWidth(lsbox->sizePolicy().hasHeightForWidth());
        lsbox->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(lsbox, 1, 0, 5, 1);

        line_11 = new QFrame(gridLayoutWidget_2);
        line_11->setObjectName(QStringLiteral("line_11"));
        sizePolicy1.setHeightForWidth(line_11->sizePolicy().hasHeightForWidth());
        line_11->setSizePolicy(sizePolicy1);
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_11, 0, 1, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_upload_set = new QPushButton(gridLayoutWidget_2);
        btn_upload_set->setObjectName(QStringLiteral("btn_upload_set"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btn_upload_set->sizePolicy().hasHeightForWidth());
        btn_upload_set->setSizePolicy(sizePolicy5);
        btn_upload_set->setMinimumSize(QSize(112, 60));
        btn_upload_set->setMaximumSize(QSize(100, 60));

        verticalLayout->addWidget(btn_upload_set);

        btn_upload_rcp = new QPushButton(gridLayoutWidget_2);
        btn_upload_rcp->setObjectName(QStringLiteral("btn_upload_rcp"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btn_upload_rcp->sizePolicy().hasHeightForWidth());
        btn_upload_rcp->setSizePolicy(sizePolicy6);
        btn_upload_rcp->setMinimumSize(QSize(112, 60));
        btn_upload_rcp->setMaximumSize(QSize(100, 60));

        verticalLayout->addWidget(btn_upload_rcp);


        gridLayout_2->addLayout(verticalLayout, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btn_clone_set = new QPushButton(gridLayoutWidget_2);
        btn_clone_set->setObjectName(QStringLiteral("btn_clone_set"));
        sizePolicy5.setHeightForWidth(btn_clone_set->sizePolicy().hasHeightForWidth());
        btn_clone_set->setSizePolicy(sizePolicy5);
        btn_clone_set->setMinimumSize(QSize(112, 60));
        btn_clone_set->setMaximumSize(QSize(16777215, 60));

        verticalLayout_2->addWidget(btn_clone_set);

        btn_clone_rcp = new QPushButton(gridLayoutWidget_2);
        btn_clone_rcp->setObjectName(QStringLiteral("btn_clone_rcp"));
        sizePolicy5.setHeightForWidth(btn_clone_rcp->sizePolicy().hasHeightForWidth());
        btn_clone_rcp->setSizePolicy(sizePolicy5);
        btn_clone_rcp->setMinimumSize(QSize(0, 60));
        btn_clone_rcp->setMaximumSize(QSize(112, 60));

        verticalLayout_2->addWidget(btn_clone_rcp);


        gridLayout_2->addLayout(verticalLayout_2, 1, 1, 1, 1);

        pb_rcp = new QProgressBar(gridLayoutWidget_2);
        pb_rcp->setObjectName(QStringLiteral("pb_rcp"));
        sizePolicy.setHeightForWidth(pb_rcp->sizePolicy().hasHeightForWidth());
        pb_rcp->setSizePolicy(sizePolicy);
        pb_rcp->setValue(0);

        gridLayout_2->addWidget(pb_rcp, 4, 1, 1, 2);

        FMU_CLONE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FMU_CLONE);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 789, 21));
        FMU_CLONE->setMenuBar(menubar);
        statusbar = new QStatusBar(FMU_CLONE);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FMU_CLONE->setStatusBar(statusbar);

        retranslateUi(FMU_CLONE);

        QMetaObject::connectSlotsByName(FMU_CLONE);
    } // setupUi

    void retranslateUi(QMainWindow *FMU_CLONE)
    {
        FMU_CLONE->setWindowTitle(QApplication::translate("FMU_CLONE", "MainWindow", 0));
        btn_clear->setText(QApplication::translate("FMU_CLONE", "Clear Text", 0));
        label_3->setText(QApplication::translate("FMU_CLONE", "Recipes", 0));
        label_2->setText(QApplication::translate("FMU_CLONE", "This function is used to clone/upload \n"
"all settings from one MMP module to another", 0));
        label_4->setText(QApplication::translate("FMU_CLONE", "This function is used to clone/upload \n"
"all recipes from one MMP module to another", 0));
        label->setText(QApplication::translate("FMU_CLONE", "Settings", 0));
        btn_upload_set->setText(QApplication::translate("FMU_CLONE", "upload MMP settings", 0));
        btn_upload_rcp->setText(QApplication::translate("FMU_CLONE", "upload MMP recipes", 0));
        btn_clone_set->setText(QApplication::translate("FMU_CLONE", "clone MMP settings", 0));
        btn_clone_rcp->setText(QApplication::translate("FMU_CLONE", "clone MMP recipes", 0));
    } // retranslateUi

};

namespace Ui {
    class FMU_CLONE: public Ui_FMU_CLONE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMU_CLONE_H

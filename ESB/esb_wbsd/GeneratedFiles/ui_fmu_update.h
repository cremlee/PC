/********************************************************************************
** Form generated from reading UI file 'fmu_update.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMU_UPDATE_H
#define UI_FMU_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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

class Ui_FMU_UPDATE
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *lbl_ver_fmu;
    QLabel *lbl_currentversion_2;
    QLabel *lbl_ver_fth;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *btn_openfile;
    QLabel *lbl_description;
    QPushButton *btn_ok;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FMU_UPDATE)
    {
        if (FMU_UPDATE->objectName().isEmpty())
            FMU_UPDATE->setObjectName(QStringLiteral("FMU_UPDATE"));
        FMU_UPDATE->resize(403, 436);
        centralwidget = new QWidget(FMU_UPDATE);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 361, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lbl_ver_fmu = new QLabel(verticalLayoutWidget);
        lbl_ver_fmu->setObjectName(QStringLiteral("lbl_ver_fmu"));

        horizontalLayout->addWidget(lbl_ver_fmu);

        lbl_currentversion_2 = new QLabel(verticalLayoutWidget);
        lbl_currentversion_2->setObjectName(QStringLiteral("lbl_currentversion_2"));

        horizontalLayout->addWidget(lbl_currentversion_2);

        lbl_ver_fth = new QLabel(verticalLayoutWidget);
        lbl_ver_fth->setObjectName(QStringLiteral("lbl_ver_fth"));

        horizontalLayout->addWidget(lbl_ver_fth);


        verticalLayout->addLayout(horizontalLayout);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        btn_openfile = new QPushButton(verticalLayoutWidget);
        btn_openfile->setObjectName(QStringLiteral("btn_openfile"));

        gridLayout->addWidget(btn_openfile, 0, 1, 1, 1);

        lbl_description = new QLabel(verticalLayoutWidget);
        lbl_description->setObjectName(QStringLiteral("lbl_description"));

        gridLayout->addWidget(lbl_description, 1, 1, 1, 1);

        btn_ok = new QPushButton(verticalLayoutWidget);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));

        gridLayout->addWidget(btn_ok, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 5);
        FMU_UPDATE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FMU_UPDATE);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 403, 21));
        FMU_UPDATE->setMenuBar(menubar);
        statusbar = new QStatusBar(FMU_UPDATE);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FMU_UPDATE->setStatusBar(statusbar);
        QWidget::setTabOrder(btn_openfile, btn_ok);

        retranslateUi(FMU_UPDATE);

        QMetaObject::connectSlotsByName(FMU_UPDATE);
    } // setupUi

    void retranslateUi(QMainWindow *FMU_UPDATE)
    {
        FMU_UPDATE->setWindowTitle(QApplication::translate("FMU_UPDATE", "MainWindow", 0));
        label->setText(QApplication::translate("FMU_UPDATE", "Version Information", 0));
        label_2->setText(QApplication::translate("FMU_UPDATE", "UC  Version:", 0));
        lbl_ver_fmu->setText(QApplication::translate("FMU_UPDATE", "v1.0.0", 0));
        lbl_currentversion_2->setText(QApplication::translate("FMU_UPDATE", "FTH Version", 0));
        lbl_ver_fth->setText(QApplication::translate("FMU_UPDATE", "v1.0.0", 0));
        label_4->setText(QApplication::translate("FMU_UPDATE", "Upgrate/Downgrade", 0));
        label_5->setText(QApplication::translate("FMU_UPDATE", "MMP Package", 0));
        label_7->setText(QApplication::translate("FMU_UPDATE", "Description", 0));
        label_8->setText(QApplication::translate("FMU_UPDATE", "Update", 0));
        btn_openfile->setText(QApplication::translate("FMU_UPDATE", "Select", 0));
        lbl_description->setText(QApplication::translate("FMU_UPDATE", "-", 0));
        btn_ok->setText(QApplication::translate("FMU_UPDATE", "go", 0));
    } // retranslateUi

};

namespace Ui {
    class FMU_UPDATE: public Ui_FMU_UPDATE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMU_UPDATE_H

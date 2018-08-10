/********************************************************************************
** Form generated from reading UI file 'wbsd_run.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSD_RUN_H
#define UI_WBSD_RUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wbsd_run
{
public:
    QWidget *centralwidget;
    QLabel *lb_clr;
    QLabel *lb_st;
    QFrame *frame;
    QLabel *label;

    void setupUi(QWidget *wbsd_run)
    {
        if (wbsd_run->objectName().isEmpty())
            wbsd_run->setObjectName(QStringLiteral("wbsd_run"));
        wbsd_run->resize(360, 210);
        wbsd_run->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(wbsd_run);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lb_clr = new QLabel(centralwidget);
        lb_clr->setObjectName(QStringLiteral("lb_clr"));
        lb_clr->setGeometry(QRect(30, 180, 21, 20));
        lb_clr->setStyleSheet(QStringLiteral("background:rgb(170, 0, 0)"));
        lb_st = new QLabel(centralwidget);
        lb_st->setObjectName(QStringLiteral("lb_st"));
        lb_st->setGeometry(QRect(60, 180, 91, 21));
        QFont font;
        font.setPointSize(10);
        lb_st->setFont(font);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(29, 19, 301, 81));
        frame->setStyleSheet(QStringLiteral("image: url(:/mainpics/3.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(35, 112, 291, 31));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(wbsd_run);

        QMetaObject::connectSlotsByName(wbsd_run);
    } // setupUi

    void retranslateUi(QWidget *wbsd_run)
    {
        wbsd_run->setWindowTitle(QApplication::translate("wbsd_run", "MainWindow", 0));
        lb_clr->setText(QString());
        lb_st->setText(QApplication::translate("wbsd_run", "connecting", 0));
        label->setText(QApplication::translate("wbsd_run", "Programe init,please wait!", 0));
    } // retranslateUi

};

namespace Ui {
    class wbsd_run: public Ui_wbsd_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSD_RUN_H

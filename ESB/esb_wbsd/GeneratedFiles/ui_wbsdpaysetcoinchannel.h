/********************************************************************************
** Form generated from reading UI file 'wbsdpaysetcoinchannel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDPAYSETCOINCHANNEL_H
#define UI_WBSDPAYSETCOINCHANNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDPaySetCoinChannel
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QDoubleSpinBox *dblChannelValue;
    QLabel *lblFVToken;
    QLabel *lblChannelName;
    QCheckBox *chkFVToken;
    QPushButton *btnCancel;
    QPushButton *btnOK;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WBSDPaySetCoinChannel)
    {
        if (WBSDPaySetCoinChannel->objectName().isEmpty())
            WBSDPaySetCoinChannel->setObjectName(QStringLiteral("WBSDPaySetCoinChannel"));
        WBSDPaySetCoinChannel->resize(397, 272);
        centralwidget = new QWidget(WBSDPaySetCoinChannel);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 10, 351, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(19);
        gridLayout->setVerticalSpacing(21);
        gridLayout->setContentsMargins(10, 0, 10, 5);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        dblChannelValue = new QDoubleSpinBox(gridLayoutWidget);
        dblChannelValue->setObjectName(QStringLiteral("dblChannelValue"));
        dblChannelValue->setSingleStep(0.05);

        gridLayout->addWidget(dblChannelValue, 2, 1, 1, 1);

        lblFVToken = new QLabel(gridLayoutWidget);
        lblFVToken->setObjectName(QStringLiteral("lblFVToken"));

        gridLayout->addWidget(lblFVToken, 1, 0, 1, 1);

        lblChannelName = new QLabel(gridLayoutWidget);
        lblChannelName->setObjectName(QStringLiteral("lblChannelName"));

        gridLayout->addWidget(lblChannelName, 0, 1, 1, 1);

        chkFVToken = new QCheckBox(gridLayoutWidget);
        chkFVToken->setObjectName(QStringLiteral("chkFVToken"));

        gridLayout->addWidget(chkFVToken, 1, 1, 1, 1);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        gridLayout->addWidget(btnCancel, 3, 0, 1, 1);

        btnOK = new QPushButton(gridLayoutWidget);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setAutoDefault(false);
        btnOK->setDefault(true);

        gridLayout->addWidget(btnOK, 3, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        WBSDPaySetCoinChannel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDPaySetCoinChannel);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 397, 21));
        WBSDPaySetCoinChannel->setMenuBar(menubar);
        QWidget::setTabOrder(chkFVToken, dblChannelValue);
        QWidget::setTabOrder(dblChannelValue, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);

        retranslateUi(WBSDPaySetCoinChannel);

        QMetaObject::connectSlotsByName(WBSDPaySetCoinChannel);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDPaySetCoinChannel)
    {
        WBSDPaySetCoinChannel->setWindowTitle(QApplication::translate("WBSDPaySetCoinChannel", "Set coinchannel value", 0));
        label_3->setText(QApplication::translate("WBSDPaySetCoinChannel", "Channel", 0));
        label->setText(QApplication::translate("WBSDPaySetCoinChannel", "Set  Value", 0));
        lblFVToken->setText(QApplication::translate("WBSDPaySetCoinChannel", "Freevend token", 0));
        lblChannelName->setText(QApplication::translate("WBSDPaySetCoinChannel", "TextLabel", 0));
        chkFVToken->setText(QString());
        btnCancel->setText(QApplication::translate("WBSDPaySetCoinChannel", "Cancel", 0));
        btnOK->setText(QApplication::translate("WBSDPaySetCoinChannel", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDPaySetCoinChannel: public Ui_WBSDPaySetCoinChannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDPAYSETCOINCHANNEL_H

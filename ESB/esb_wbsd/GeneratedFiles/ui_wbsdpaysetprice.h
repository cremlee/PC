/********************************************************************************
** Form generated from reading UI file 'wbsdpaysetprice.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBSDPAYSETPRICE_H
#define UI_WBSDPAYSETPRICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBSDPaySetPrice
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *lblRecipeName;
    QLabel *lblButtonNumber;
    QLabel *label;
    QDoubleSpinBox *dblPrice;
    QLabel *label_2;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WBSDPaySetPrice)
    {
        if (WBSDPaySetPrice->objectName().isEmpty())
            WBSDPaySetPrice->setObjectName(QStringLiteral("WBSDPaySetPrice"));
        WBSDPaySetPrice->resize(397, 272);
        centralwidget = new QWidget(WBSDPaySetPrice);
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

        lblRecipeName = new QLabel(gridLayoutWidget);
        lblRecipeName->setObjectName(QStringLiteral("lblRecipeName"));

        gridLayout->addWidget(lblRecipeName, 1, 1, 1, 1);

        lblButtonNumber = new QLabel(gridLayoutWidget);
        lblButtonNumber->setObjectName(QStringLiteral("lblButtonNumber"));

        gridLayout->addWidget(lblButtonNumber, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        dblPrice = new QDoubleSpinBox(gridLayoutWidget);
        dblPrice->setObjectName(QStringLiteral("dblPrice"));
        dblPrice->setSingleStep(0.1);

        gridLayout->addWidget(dblPrice, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        btnOK = new QPushButton(gridLayoutWidget);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setAutoDefault(false);
        btnOK->setDefault(true);

        gridLayout->addWidget(btnOK, 3, 0, 1, 1);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        gridLayout->addWidget(btnCancel, 3, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        WBSDPaySetPrice->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WBSDPaySetPrice);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 397, 21));
        WBSDPaySetPrice->setMenuBar(menubar);
        QWidget::setTabOrder(dblPrice, btnCancel);

        retranslateUi(WBSDPaySetPrice);

        QMetaObject::connectSlotsByName(WBSDPaySetPrice);
    } // setupUi

    void retranslateUi(QMainWindow *WBSDPaySetPrice)
    {
        WBSDPaySetPrice->setWindowTitle(QApplication::translate("WBSDPaySetPrice", "Set beverage price", 0));
        label_3->setText(QApplication::translate("WBSDPaySetPrice", "Button", 0));
        lblRecipeName->setText(QApplication::translate("WBSDPaySetPrice", "TextLabel", 0));
        lblButtonNumber->setText(QApplication::translate("WBSDPaySetPrice", "TextLabel", 0));
        label->setText(QApplication::translate("WBSDPaySetPrice", "Set price", 0));
        label_2->setText(QApplication::translate("WBSDPaySetPrice", "Recipe", 0));
        btnOK->setText(QApplication::translate("WBSDPaySetPrice", "OK", 0));
        btnCancel->setText(QApplication::translate("WBSDPaySetPrice", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class WBSDPaySetPrice: public Ui_WBSDPaySetPrice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBSDPAYSETPRICE_H

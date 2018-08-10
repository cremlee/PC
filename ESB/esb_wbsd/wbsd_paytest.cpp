#include "wbsd_paytest.h"
#include "ui_wbsd_paytest.h"
#include"parametermsg.h"
#include<QDebug>
WBSDpaytest::WBSDpaytest(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDpaytest)
{
    ui->setupUi(this);
    this->centralWidget()->setLayout(ui->horizontalLayout);
    this->setWindowTitle("payment test");
}

WBSDpaytest::~WBSDpaytest()
{
    delete ui;
}

void WBSDpaytest::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDpaytest::gotMessage(Message aMsg)
{
    //qDebug()<<"aMsg.getType()"<<aMsg.getType();
    //qDebug()<<"aMsg.getBoard()"<<aMsg.getBoard();
    //qDebug()<<"aMsg.getDataBaseType()"<<aMsg.getDataBaseType();
    int numberOfDecimals=2;
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::UIB) && (aMsg.getDataBaseType()==Message::DP) )
    {
        switch(aMsg.getParameters().at(3)){
        case 10:
            this->ui->plainTextEdit->appendPlainText(QString("Get Button1 Price Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));
            break;
        case 12:
            this->ui->plainTextEdit->appendPlainText(QString("Get Button3 Price Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));

            break;
        case 13:
            this->ui->plainTextEdit->appendPlainText(QString("Get Button4 Price Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));

            break;
        case 14:
            this->ui->plainTextEdit->appendPlainText(QString("Get Button5 Price Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));
            break;
        case 15:
            this->ui->plainTextEdit->appendPlainText(QString("Get Button6 Price Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));
            break;
        case 11:
            this->ui->plainTextEdit->appendPlainText(QString("Get Button2 Price Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));

            break;
        default:
            break;
        }
    }
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DP) )
    {
        switch(aMsg.getParameters().at(3)){
        case 10:
            this->ui->plainTextEdit->appendPlainText(QString("Get Coin Channel_A Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));
            break;
        case 12:
            this->ui->plainTextEdit->appendPlainText(QString("Get Coin Channel_C Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));

            break;
        case 13:
            this->ui->plainTextEdit->appendPlainText(QString("Get Coin Channel_D Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));

            break;
        case 14:
            this->ui->plainTextEdit->appendPlainText(QString("Get Coin Channel_E Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));
            break;
        case 15:
            this->ui->plainTextEdit->appendPlainText(QString("Get Coin Channel_F Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));
            this->ui->plainTextEdit->appendPlainText("Coin Communication Param test finished");

            break;
        case 11:
            this->ui->plainTextEdit->appendPlainText(QString("Get Coin Channel_B Param: %1").arg(QString::number((float)aMsg.getDataInt()/100,'f',numberOfDecimals)));

            break;
        default:
            break;
        }
    }
}

void WBSDpaytest::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDpaytest::on_btn_test_clicked()
{
    ui->plainTextEdit->appendPlainText("Coin Communication Param test starting");
    ui->plainTextEdit->appendPlainText("!!!Coin Communication Param test is only for param not hardware!!!");
    for(int db=10;db<16;db++)
    {
    ParameterMsg counterResetMsg(Message::UIB,Message::DP, db);
    counterResetMsg.getWord();
    itsBaseWindow->addMessageToQue(counterResetMsg);
    }

    for(int db=10;db<16;db++)
    {
    ParameterMsg counterResetMsg(Message::MCB,Message::DP, db);
    counterResetMsg.getWord();
    itsBaseWindow->addMessageToQue(counterResetMsg);
    }
}

void WBSDpaytest::updatetestresult(QString a)
{
    ui->plainTextEdit->appendPlainText(a);
}

void WBSDpaytest::on_menuBack_triggered()
{
    this->close();
}

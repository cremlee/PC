#include "WbsdCalibrateCanister.h"
#include "wbsdbasedialog.h"
#include "ui_WbsdCalibrateCanister.h"
#include "parametermsg.h"
#include <QDebug>

WbsdCalibrateCanister::WbsdCalibrateCanister(QWidget *parent) :
    WBSDBaseDialog(parent),
    ui(new Ui::WbsdCalibrateCanister)
{
    ui->setupUi(this);

}

WbsdCalibrateCanister::~WbsdCalibrateCanister()
{
    delete ui;
}


void WbsdCalibrateCanister::updateData()
{
        ParameterMsg msg(Message::MCB,Message::AP,17);
        msg.getWord();
        itsBaseWindow->addMessageToQue(msg);
}

void WbsdCalibrateCanister::connectionStatusChanged(int aStatus,StringMessage aMSG){
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WbsdCalibrateCanister::gotMessage(Message aMsg){

    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DV)){
        unsigned char index=aMsg.getParameters().at(3);
        qDebug() << "msg:" << (index);
    }


}

void WbsdCalibrateCanister::startCalibrate(){
    ParameterMsg msg(Message::MCB,Message::DV,17);
    msg.setNibble(0,1);
    itsBaseWindow->addMessageToQue(msg);
}

void WbsdCalibrateCanister::checkProgress(){

}

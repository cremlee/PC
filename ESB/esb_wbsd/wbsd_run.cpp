#include "wbsd_run.h"
#include "ui_wbsd_run.h"
#include"parametermsg.h"
#include"wbsd_serial_port.h"
#include"wbsdmainwindow.h"
void wbsd_run::deviceDiscovered(const QextPortInfo &info)
{
    if ((info.vendorID==1003)  && (info.productID==8216)){
        wbsd_SERIAL_PORT::instance()->reconnect(info.portName);

    }

}

void wbsd_run::deviceRemoved(const QextPortInfo &info)
{
    if ((info.vendorID==1003)  && (info.productID==8216)){
        wbsd_SERIAL_PORT::instance()->disconnect();
    }
}

void wbsd_run::updateConnectionStatus(int, StringMessage)
{

}

void wbsd_run::gotMessage(Message aMsg)
{
    unsigned int aVal;
    Message::qtype atype=aMsg.getType();
    switch (atype){
        case (Message::REPLY_DB):
            switch ((unsigned char)aMsg.getBoard()){
                case (Message::MCB):
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DP:
                            switch(aMsg.getParameters().at(3)){
                                case (33):
                                    aVal=aMsg.getDataUInt();
                                    if((aVal & 0x00ff) ==1)
                                    {
                                        //todo:esbblack
                                    }else
                                    {
                                        //todo:esb
                                        WBSDMainWindow* mywin = new WBSDMainWindow() ;
                                        mywin->show();

                                    }
                                    break;
                                default:
                                    break;
                            }
                    }
                    break;
                default:
                    break;
            }
    }
}

void wbsd_run::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    if(aStatus == wbsd_SERIAL_PORT::CS_LOCALESB){
    ParameterMsg msg1(Message::MCB,Message::DP,33);
    msg1.getChar(0);
    wbsd_SERIAL_PORT::instance()->addMessageToQue(msg1);
    }
}



wbsd_run::wbsd_run(WBSDBaseWindow *parent):
    WBSDChildWindow(parent),
    ui(new Ui::wbsd_run)
{
    ui->setupUi(this);

   itsBaseWindow->connectToMessages(this);
}

wbsd_run::~wbsd_run()
{
    delete ui;

}


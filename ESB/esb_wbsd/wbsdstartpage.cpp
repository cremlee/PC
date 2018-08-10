#include "wbsdstartpage.h"
#include "ui_wbsdstartpage.h"
#include "qdebug.h"
#include "wbsdpaywindow.h"
#include "wbsderrorwindow.h"
#include "wbsdwaterwindow.h"
#include "wbsdcounterswindow.h"
#include "wbsdtestingwindow.h"
#include "wbsdgeneralwindow.h"
#include "wbsddrinkwindow.h"
#include "wbsddisplayoptwindow.h"
#include "wbsdtimewindow.h"
#include "wbsdchildwindow.h"
#include <qdebug.h>
#include "wbsd_serial_port.h"
#include "application.h"
#include "databasehelper.h"
#include<QProcess>
/*modify by lee
first check the MCB Ver if it is below 0.86 ,then give warning and close it.
*/
static const char* connecting_start[] = {
    QT_TRANSLATE_NOOP("startpage_conn_status", "Disconnected"),
    QT_TRANSLATE_NOOP("startpage_conn_status", "Connecting..."),
    QT_TRANSLATE_NOOP("startpage_conn_status", "Connected")
};

WBSDStartPage::WBSDStartPage(WBSDBaseWindow *parent) :
    WBSDWidget(parent,0),
    ui(new Ui::WBSDStartPage)
{
    ui->setupUi(this);
    IsBakMode = false;
    errorWindow = 0;
    waterWindow = 0;
    countersWindow = 0;//new WBSDCountersWindow(itsBaseWindow);
    testingWindow = 0; //new WBSDTestingWindow;
    generalWindow = 0;//new WBSDGeneralWindow;
    drinkWindow = 0; //new WBSDDrinkWindow;
    displayWindow = 0;//new WBSDDisplayOptWindow;
    timeWindow = 0; //new WBSDTimeWindow;
	payWindow=0;
    _wbsd_update =0;
    _wbsdclone=0;
    itsBaseWindow->connectToMessages(this);
    setLabelTexts();
    ui->lb_txt->setVisible(true);
    ui->errorButton->setVisible(false);
    ui->waterButton->setVisible(false);
    ui->countersButton->setVisible(false);
    ui->generalButton->setVisible(false);
    ui->drinkButton->setVisible(false);
    ui->displayButton->setVisible(false);
    ui->timeButton->setVisible(false);
    ui->payButton->setVisible(false);
    ui->testButton->setVisible(false);
    ui->btnlan->setVisible(false);
    ui->updateBtn->setVisible(false);


}

void WBSDStartPage::connectionStatusChanged(int aStatus,StringMessage aMSG){
    qDebug() << "WBSDStartPage::connectionStatusChanged Status:" << aStatus;
    static int currentState = CON_SHOW_INIT;

    if ((aStatus == wbsd_SERIAL_PORT::CS_CONNECTING)&& currentState != CON_SHOW_CONNECT){
        qDebug() << " connectionStatusChanged  !!!!!!!!";
            enableButtons(false);
            itsBaseWindow->sendclose();
            itsBaseWindow->showConnectionStatus(CON_SHOW_CONNECT);
            currentState = CON_SHOW_CONNECT;
            Message msg;
            msg.msg[0]=0x02;
            msg.msg[1]=0xb7;
            msg.msg[2]=0xa1;
            msg.msg[3]=0x60;
            msg.msg[4]=0x00;
            msg.msg[5]=0x00;
            msg.msg[6]=0x00;
            msg.msg[7]=0x00;
            itsBaseWindow->addMessageToQue(msg);

            ParameterMsg msg1(Message::MCB,Message::DP,33);
            msg1.getWord();
            wbsd_SERIAL_PORT::instance()->addMessageToQue(msg1);

            ui->connStatusText->setText(Application::translate("startpage_conn_status",connecting_start[1]));
            ui->connStatusInd->setStyleSheet("background:rgb(200,200,0)");

    }
    else if ((aStatus == wbsd_SERIAL_PORT::CS_LOCALESB)&& currentState != CON_SHOW_NONE) {
        qDebug() << " connectionStatusChanged  -------";
            enableButtons(true);
            itsBaseWindow->showConnectionStatus(CON_SHOW_NONE);
            currentState = CON_SHOW_NONE;
            ui->connStatusText->setText(Application::translate("startpage_conn_status",connecting_start[2]));
            ui->connStatusInd->setStyleSheet("background:rgb(0,200,0)");
    }
    else if ((aStatus == wbsd_SERIAL_PORT::CS_DISCONNECTED) && currentState != CON_SHOW_OVERVIEW) {
        qDebug() << " connectionStatusChanged  +++++++";
            enableButtons(false);
            itsBaseWindow->showConnectionStatus(CON_SHOW_OVERVIEW);
            currentState = CON_SHOW_OVERVIEW;
            ui->connStatusText->setText(Application::translate("startpage_conn_status",connecting_start[0]));
            ui->connStatusInd->setStyleSheet("background:rgb(200,0,0)");

                //generalWindow->close();

    }


}


WBSDStartPage::~WBSDStartPage()
{
    delete ui;
}

void WBSDStartPage::gotMessage(Message aMsg){
    if(IsBakMode) return;
    float vermcb;
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
//                                aVal=aMsg.getDataUInt();
//                                if((aVal & 0x00ff) ==1)
//                                {
//                                    //todo:esbblack
//                                    QProcess *ps = new QProcess();
//                                    ps->start(".\\black\\Compact_PC_Tool.exe");
//                                    qApp->quit();
//                                }else
//                                {
                                    //todo:esb
//                                    ui->lb_txt->setVisible(false);
//                                    ui->errorButton->setVisible(true);
//                                    ui->waterButton->setVisible(true);
//                                    ui->countersButton->setVisible(true);
//                                    ui->generalButton->setVisible(true);
//                                    ui->drinkButton->setVisible(true);
//                                    ui->displayButton->setVisible(true);
//                                    ui->timeButton->setVisible(true);
//                                    ui->payButton->setVisible(true);
//                                    ui->testButton->setVisible(true);
//                                    ui->btnlan->setVisible(true);
//                                    ui->updateBtn->setVisible(false);

                                    if(DataBaseHelper::getInstance()->getMachineState() == 0)
                                    {
                                        if(wbsd_SERIAL_PORT::instance()->theConnectionStatus == 20 && DataBaseHelper::getInstance()->getlast()==1)
                                        {
                                             qDebug() << "WBSDCleaningWindow::gotMessage aaaaaaaaaaaaaaa" ;
                                        ParameterMsg msg1(Message::MCB,Message::DP,0,Message::SET_PARAMETER);
                                        msg1.setBit(15,1);
                                        wbsd_SERIAL_PORT::instance()->addMessageToQue(msg1);

                                        ParameterMsg query1(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
                                        query1.setNibble(3,2);
                                        wbsd_SERIAL_PORT::instance()->addMessageToQue(query1);

                                        ParameterMsg query2(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
                                        query2.setNibble(2,1);
                                        wbsd_SERIAL_PORT::instance()->addMessageToQue(query2);

                                        }
                                    }
                                    else
                                    {
                                        if(wbsd_SERIAL_PORT::instance()->theConnectionStatus == 20 && DataBaseHelper::getInstance()->getlast()==0)
                                        {
                                          ParameterMsg msg1(Message::MCB,Message::DP,0,Message::SET_PARAMETER);
                                          msg1.setBit(15,0);
                                          wbsd_SERIAL_PORT::instance()->addMessageToQue(msg1);

                                          ParameterMsg query1(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
                                          query1.setNibble(3,1);
                                          wbsd_SERIAL_PORT::instance()->addMessageToQue(query1);

                                          ParameterMsg query2(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
                                          query2.setNibble(2,3);
                                          wbsd_SERIAL_PORT::instance()->addMessageToQue(query2);
                                        }
                                    }
                                //}
                                break;
                            default:
                                break;
                        }
                }
                break;

            default:
                break;
        }
        break;
    case (Message::METADATA_ANSWER):
        {
            StringMessage sm(aMsg);
            qDebug()<<"vermcb="<<sm.getList();
            QList <QString> al=sm.getList();
            QList <QString> a2=al.at(1).split(":");
            if(a2.at(1).startsWith("b",Qt::CaseInsensitive)){
               QProcess *ps = new QProcess();
               ps->start(".\\black\\Compact_PC_Tool.exe");
               qApp->quit();
            }else
            {
                ui->lb_txt->setVisible(false);
                ui->errorButton->setVisible(true);
                ui->waterButton->setVisible(true);
                ui->countersButton->setVisible(true);
                ui->generalButton->setVisible(true);
                ui->drinkButton->setVisible(true);
                ui->displayButton->setVisible(true);
                ui->timeButton->setVisible(true);
                ui->payButton->setVisible(true);
                ui->testButton->setVisible(true);
                ui->btnlan->setVisible(true);
                ui->updateBtn->setVisible(false);

//                if(DataBaseHelper::getInstance()->getMachineState() == 0)
//                {
//                     qDebug() << "WBSDCleaningWindow::gotMessage aaaaaaaaaaaaaaa" ;
//                    if(wbsd_SERIAL_PORT::instance()->theConnectionStatus == 20 && DataBaseHelper::getInstance()->getlast()==1)
//                    {
//                    ParameterMsg msg1(Message::MCB,Message::DP,0,Message::SET_PARAMETER);
//                    msg1.setBit(15,1);
//                    wbsd_SERIAL_PORT::instance()->addMessageToQue(msg1);

//                    ParameterMsg query1(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
//                    query1.setNibble(3,2);
//                    wbsd_SERIAL_PORT::instance()->addMessageToQue(query1);

//                    ParameterMsg query2(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
//                    query2.setNibble(2,1);
//                    wbsd_SERIAL_PORT::instance()->addMessageToQue(query2);

//                    }
//                }
//                else
//                {
//                    if(wbsd_SERIAL_PORT::instance()->theConnectionStatus == 20 && DataBaseHelper::getInstance()->getlast()==0)
//                    {
//                         qDebug() << "WBSDCleaningWindow::gotMessage aaaaaaaaaaaaaaa" ;
//                      ParameterMsg msg1(Message::MCB,Message::DP,0,Message::SET_PARAMETER);
//                      msg1.setBit(15,0);
//                      wbsd_SERIAL_PORT::instance()->addMessageToQue(msg1);

//                      ParameterMsg query1(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
//                      query1.setNibble(3,1);
//                      wbsd_SERIAL_PORT::instance()->addMessageToQue(query1);

//                      ParameterMsg query2(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
//                      query2.setNibble(2,3);
//                      wbsd_SERIAL_PORT::instance()->addMessageToQue(query2);
//                    }
//                }
            }
        }
        break;
}


}

void WBSDStartPage::on_errorButton_clicked()
{
    if (errorWindow==0)
    {
        errorWindow= new WBSDErrorWindow(itsBaseWindow);
        errorWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( errorWindow, SIGNAL(destroyed()), this, SLOT(on_errorWindow_destroyd()));
    }
    errorWindow->show();

}

void WBSDStartPage::on_waterButton_clicked()
{
    if (waterWindow==0)
    {
		waterWindow=new WBSDWaterWindow(itsBaseWindow);
        waterWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( waterWindow, SIGNAL(destroyed()), this, SLOT(on_waterWindow_destroyd()));
    }
    waterWindow->show();
}

void WBSDStartPage::on_countersButton_clicked()
{
    if (countersWindow==0)
    {
	    countersWindow = new WBSDCountersWindow(itsBaseWindow);
        countersWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( countersWindow, SIGNAL(destroyed()), this, SLOT(on_countersWindow_destroyd()));
    }
    countersWindow->show();
}

void WBSDStartPage::on_generalButton_clicked()
{
    if (generalWindow==0)
    {
        generalWindow = new WBSDGeneralWindow(itsBaseWindow);
        generalWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( generalWindow, SIGNAL(iclose()), this, SLOT(on_generalWindow_destroyd()));
    }
    generalWindow->show();
}
void WBSDStartPage::on_drinkButton_clicked()
{
    if (drinkWindow==0)
    {
        drinkWindow = new WBSDDrinkWindow(itsBaseWindow);
        drinkWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( drinkWindow, SIGNAL(iclose()), this, SLOT(on_drinkWindow_destroyd()));
    }
    drinkWindow->show();
}

void WBSDStartPage::on_displayButton_clicked()
{
    if (displayWindow==0)
    {
        displayWindow = new WBSDDisplayOptWindow(itsBaseWindow);
        displayWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( displayWindow, SIGNAL(destroyed()), this, SLOT(on_displayWindow_destroyd()));
    }
    displayWindow->show();
}

void WBSDStartPage::on_timeButton_clicked()
{
    if (timeWindow==0)
    {
        timeWindow = new WBSDTimeWindow(itsBaseWindow);
        timeWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( timeWindow, SIGNAL(destroyed()), this, SLOT(on_timeWindow_destroyd()));
    }
    timeWindow->show();
}

void WBSDStartPage::on_payButton_clicked()
{
    QString qs=QString("RJDEBUG Pay Button");
    qDebug () << qs;

    if (payWindow==0)
    {
		payWindow = new WBSDPayWindow(itsBaseWindow);
        payWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( payWindow, SIGNAL(destroyed()), this, SLOT(on_payWindow_destroyd()));
    }
    payWindow->show();

}

void WBSDStartPage::on_testButton_clicked()
{
    if (testingWindow==0)
    {
        testingWindow = new WBSDTestingWindow(itsBaseWindow);
        testingWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( testingWindow, SIGNAL(destroyed()), this, SLOT(on_testingWindow_destroyd()));
    }
    testingWindow->show();
}

void WBSDStartPage::on_updateBtn_clicked()
{
    if (_wbsd_update==0)
    {
        _wbsd_update = new wbsd_update(itsBaseWindow);
        _wbsd_update->setAttribute(Qt::WA_DeleteOnClose, true);
        connect( _wbsd_update, SIGNAL(destroyed()), this, SLOT(on_update_destroyd()));
    }
    _wbsd_update->show();

}

void WBSDStartPage::on_btnlan_clicked()
{
    if (_wbsdclone==0)
    {
        _wbsdclone = new wbsdclone(itsBaseWindow,IsBakMode);
        _wbsdclone->setAttribute(Qt::WA_DeleteOnClose, true);
        /*modify by lee 2015-1-6 if bakmode is on just show backup and restore
         * need to set a flag for clonewindows
        */
        connect( _wbsdclone, SIGNAL(destroyed()), this, SLOT(on_clone_destroyed()));
    }
    _wbsdclone->show();

}

void WBSDStartPage::updateinfo(int index)
{
    if(currentState == 2 )
    {
        ui->connStatusText->setText(Application::translate("startpage_conn_status",connecting_start[2]));
        ui->connStatusInd->setStyleSheet("background:rgb(0,200,0)");
    }
    else
        {
    ui->connStatusText->setText(Application::translate("startpage_conn_status",connecting_start[0]));
    ui->connStatusInd->setStyleSheet("background:rgb(200,0,0)");
        }
}

void WBSDStartPage::setLabelTexts()
{
    static const char* startLabels[] = {
        QT_TRANSLATE_NOOP("start_labels_txt", "Errors"),
        QT_TRANSLATE_NOOP("start_labels_txt", "Water system"),
        QT_TRANSLATE_NOOP("start_labels_txt", "Counters"),
        QT_TRANSLATE_NOOP("start_labels_txt", "General settings"),
        QT_TRANSLATE_NOOP("start_labels_txt", "Drink settings"),
        QT_TRANSLATE_NOOP("start_labels_txt", "Display settings"),
        QT_TRANSLATE_NOOP("start_labels_txt", "Time and events"),
        QT_TRANSLATE_NOOP("start_labels_txt", "Payment/RFID settings"),
        QT_TRANSLATE_NOOP("start_labels_txt", "Testing"),
        QT_TRANSLATE_NOOP("start_labels_txt", "Clone/backup")

    };

    ui->errorButton->setText(Application::translate("start_labels_txt",startLabels[0]));
    ui->waterButton->setText(Application::translate("start_labels_txt",startLabels[1]));
    ui->countersButton->setText(Application::translate("start_labels_txt",startLabels[2]));
    ui->generalButton->setText(Application::translate("start_labels_txt",startLabels[3]));
    ui->drinkButton->setText(Application::translate("start_labels_txt",startLabels[4]));
    ui->displayButton->setText(Application::translate("start_labels_txt",startLabels[5]));
    ui->timeButton->setText(Application::translate("start_labels_txt",startLabels[6]));
    ui->payButton->setText(Application::translate("start_labels_txt",startLabels[7]));
    ui->testButton->setText(Application::translate("start_labels_txt",startLabels[8]));
    ui->btnlan->setText(Application::translate("start_labels_txt",startLabels[9]));
}

void WBSDStartPage::enableButtons(bool enable)
{
    ui->errorButton->setEnabled(enable);
    ui->waterButton->setEnabled(enable);
    ui->countersButton->setEnabled(enable);
    ui->generalButton->setEnabled(enable);
    ui->drinkButton->setEnabled(enable);
    ui->displayButton->setEnabled(enable);
    ui->timeButton->setEnabled(enable);
    ui->payButton->setEnabled(enable);
    ui->testButton->setEnabled(enable);
    ui->btnlan->setEnabled(enable);
    ui->updateBtn->setEnabled(enable);
    //ui->updateBtn->setVisible(false);
    //menuService_level->setEnabled(true);  //Enable service

}

void WBSDStartPage::on_errorWindow_destroyd()
{
    qDebug() << "on_errorWindow_destroyd";
    errorWindow = 0;
}

void WBSDStartPage::on_waterWindow_destroyd()
{
    qDebug() << "on_waterWindow_destroyd";
    waterWindow = 0;
}

void WBSDStartPage::on_countersWindow_destroyd()
{
    qDebug() << "on_countersWindow_destroyd";
    countersWindow = 0;


}


void WBSDStartPage::on_generalWindow_destroyd()
{
    qDebug() << "on_generalWindow_destroyd"<<generalWindow;

    generalWindow=0;
}


void WBSDStartPage::on_displayWindow_destroyd()
{
    qDebug() << "on_displayWindow_destroyd";
    displayWindow = 0;
}


void WBSDStartPage::on_timeWindow_destroyd()
{
    qDebug() << "on_timeWindow_destroyd";
    timeWindow = 0;
}

void WBSDStartPage::on_testingWindow_destroyd()
{
    qDebug() << "on_testingWindow_destroyd";
    testingWindow = 0;
//    ParameterMsg queryServ(Message::UIB,Message::DV,2);
//    queryServ.setNibble(0,_LASTMODE);
//    itsBaseWindow->addMessageToQue(queryServ);
}

void WBSDStartPage::on_drinkWindow_destroyd()
{
    qDebug() << "on_drinkWindow_destroyd";
    drinkWindow = 0;
}
void WBSDStartPage::on_payWindow_destroyd()
{
    qDebug() << "on_payWindow_destroyd";
    payWindow = 0;
}

void WBSDStartPage::on_clone_destroyed()
{
    _wbsdclone =0;
}

void WBSDStartPage::on_update_destroyd()
{
    _wbsd_update =0;
}



#include <qmessagebox>

#include "wbsdwaterwindow.h"
#include "ui_wbsdwaterwindow.h"
#include "qdebug.h"
#include "message.h"
#include "wbsdchildwindow.h"
#include "qtimer.h"
#include "qbytearray.h"
#include "qstring.h"
#include "application.h"
#include "databasehelper.h"
/*modify by Lee 2014-10-10

Something about the defination of DBS changed.
10-17-2014 : need to been modify to stop the setpoint change bug ;//do it afternoon
*/
/*modify by lee
为了解决E241问题，现在改默认的Top和Mid Temp如下：


Instant,
Standard
Payment

Top : 92.8
Mid: 89.0


Water tank version:

Top : 90.2
Mid: 86

请做好记录

*/
static double oz_tmp = 0.26417205;
static int gal_tmp=128;
WBSDWaterWindow::WBSDWaterWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDWaterWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_water", "Back")
    };
    _isWaterTank =false;
    _pwcnt = 2;
    ui->setupUi(this);
    _upflab1 =true;
    _upflab2= false;
    menuBack = new QAction(Application::translate("back_water",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    ParameterMsg msg1(Message::MCB,Message::DP,0);
    msg1.getWord();
    itsBaseWindow->addMessageToQue(msg1);
	myTimer=new QTimer(this);
	myTimer->setSingleShot(true);

    ParameterMsg filtermsg6(Message::MCB,Message::DP, 27);
    filtermsg6.getWord();
    itsBaseWindow->addMessageToQue(filtermsg6);

    //modify by Lee get DP4 to get if watertank exist?
    ParameterMsg queryd(Message::MCB,Message::DP, 4);
    queryd.getWord();
    itsBaseWindow->addMessageToQue(queryd);

    ParameterMsg query1(Message::MCB,Message::AP, 2);
    ParameterMsg query2(Message::MCB,Message::AP, 0);
    ParameterMsg query3(Message::MCB,Message::AP, 6);
    ParameterMsg query4(Message::MCB,Message::AP,21);
    query1.getFloat();
    query2.getFloat();
    query3.getFloat();
    query4.getFloat();
	itsBaseWindow->addMessageToQue(query1);
	itsBaseWindow->addMessageToQue(query2);
	itsBaseWindow->addMessageToQue(query3);
    itsBaseWindow->addMessageToQue(query4);

    DataBaseHelper::getInstance()->populateComboFromTabKat("019",ui->cboBlockOnFilter);
    DataBaseHelper::getInstance()->populateComboFromTabKat("019",ui->cboBlockOnDecalc);
    DataBaseHelper::getInstance()->populateComboFromTabKat("019",ui->cboUseDescaleCounters);
    DataBaseHelper::getInstance()->populateComboFromTabKat("019",ui->cboUseWaterFilterCounters);
	//# DB_LOCK_ON_FILTER: [MCB DP: 29: Bit00] 
	//# DB_LOCK_ON_DECALC: [MCB DP: 29: Bit01] 
	//# DB_FILTER_WARN_LEVEL10: [MCB DP: 29: NIBBLE2] 
	//# DB_DECALC_WARN_LEVEL10: [MCB DP: 29: NIBBLE3] 
    ParameterMsg filtermsg1(Message::MCB,Message::AP, 202);
    filtermsg1.getFloat();
	itsBaseWindow->addMessageToQue(filtermsg1);

    ParameterMsg filtermsg4(Message::MCB,Message::AP, 204);
    filtermsg4.getFloat();
    itsBaseWindow->addMessageToQue(filtermsg4);

	//# DB_DECALC_RESET_AMOUNT: [MCB DP: 30: WORD] 
    ParameterMsg filtermsg2(Message::MCB,Message::AP, 203);
    filtermsg2.getFloat();
	itsBaseWindow->addMessageToQue(filtermsg2);
	//# DB_FILTER_RESET_AMOUNT: [MCB DP: 31: WORD] 
    ParameterMsg filtermsg3(Message::MCB,Message::AP, 201);
    filtermsg3.getFloat();
	itsBaseWindow->addMessageToQue(filtermsg3);

    /*Lee.li Modify 2014-9-24
      fix the screen show
    */
    this->ui->centralwidget->setLayout(ui->gridLayout);


    /*Lee.li Modify 2014-9-24

    */

    /*modify by Lee  c/f  */

/**
	//DB_DECALC_WTR_AMOUNT_LEFT     &cu_ap[192]
    ParameterMsg filtermsg4(Message::MCB,Message::AP, 192);
    filtermsg4.getWord();
	itsBaseWindow->addMessageToQue(filtermsg4);
	//DB_FILTER_WTR_AMOUNT_LEFT     &cu_ap[193]
    ParameterMsg filtermsg5(Message::MCB,Message::AP, 193);
    filtermsg5.getWord();
	itsBaseWindow->addMessageToQue(filtermsg5);
**/

    //ui->btnResetDecalc->hide();
	updateData();

    //qDebug()<<"Machine_state = "<< itsBaseWindow->getMachineUnit();
    myTimer = new QTimer(this);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(savest()));
    myTimer->setInterval(2000);
    myTimer->start();


}

void WBSDWaterWindow::on_cboBlockOnFilter_activated(int index){
    ParameterMsg query1(Message::MCB,Message::DP, 27, Message::SET_PARAMETER);
    query1.setBit(8,index);
	itsBaseWindow->addMessageToQue(query1);
    ParameterMsg query(Message::MCB,Message::AP, 201);
    query.getFloat();
	itsBaseWindow->addMessageToQue(query);
}
void WBSDWaterWindow::on_cboBlockOnDecalc_activated(int index){
    ParameterMsg query1(Message::MCB,Message::DP, 27, Message::SET_PARAMETER);
    query1.setBit(9,index);
	itsBaseWindow->addMessageToQue(query1);
    ParameterMsg query(Message::MCB,Message::AP, 203);
    query.getFloat();
	itsBaseWindow->addMessageToQue(query);
}
void WBSDWaterWindow::on_cboUseDescaleCounters_activated(int index){
	enable_descalefilter(index>0);
    if (index>0){
        ParameterMsg query1(Message::MCB,Message::AP, 203, Message::SET_PARAMETER);
        if(itsBaseWindow->getUnitTmp() == 1)
        {
            query1.setFloat(150*33.814);
        }else
        {
          query1.setFloat(150);
        }

		itsBaseWindow->addMessageToQue(query1);
	} else
	{
        ParameterMsg query1(Message::MCB,Message::AP, 203, Message::SET_PARAMETER);
        query1.setFloat(0);
		itsBaseWindow->addMessageToQue(query1);
    }
}
void WBSDWaterWindow::on_cboUseWaterFilterCounters_activated(int index){
	enable_waterfilter(index>0);
    if (index>0){
        ParameterMsg query1(Message::MCB,Message::AP, 201, Message::SET_PARAMETER);
        if(itsBaseWindow->getUnitTmp() == 1)
        {
            query1.setFloat(2000*33.814);
        }else
        {
            query1.setFloat(2000);
        }
		itsBaseWindow->addMessageToQue(query1);
	} else
	{
        ParameterMsg query1(Message::MCB,Message::AP, 201, Message::SET_PARAMETER);
        query1.setFloat(0);
		itsBaseWindow->addMessageToQue(query1);
    }
}

void WBSDWaterWindow::on_spiFilterResetVal_editingFinished(){
    ParameterMsg query1(Message::MCB,Message::AP, 201, Message::SET_PARAMETER);
    if(itsBaseWindow->getUnitTmp() == 1)
    {
        query1.setFloat(ui->spiFilterResetVal->value()*128);
    }
    else
    {
        query1.setFloat(ui->spiFilterResetVal->value());
    }
	itsBaseWindow->addMessageToQue(query1);
}
void WBSDWaterWindow::on_spiFilterWarn_editingFinished(){
    ParameterMsg query1(Message::MCB,Message::AP, 202, Message::SET_PARAMETER);
    float v=ui->spiFilterWarn->value();
    if(itsBaseWindow->getUnitTmp() == 1)
    {
       query1.setFloat(v*128);
    }else
    {
       query1.setFloat(v);
    }
	itsBaseWindow->addMessageToQue(query1);

//    ParameterMsg query(Message::MCB,Message::AP, 202);
//    query.getFloat();
//	itsBaseWindow->addMessageToQue(query);

}
void WBSDWaterWindow::on_spiDecalcResetVal_editingFinished(){
    ParameterMsg query1(Message::MCB,Message::AP, 203, Message::SET_PARAMETER);
    if(itsBaseWindow->getUnitTmp() == 1)
    {
        query1.setFloat(ui->spiDecalcResetVal->value()*128);
    }else
    {
        query1.setFloat(ui->spiDecalcResetVal->value());
    }
	itsBaseWindow->addMessageToQue(query1);
}
void WBSDWaterWindow::on_spiDecalcWarn_editingFinished(){
    ParameterMsg query1(Message::MCB,Message::AP, 204, Message::SET_PARAMETER);
    float v=ui->spiDecalcWarn->value();
    if(itsBaseWindow->getUnitTmp() == 1)
    {
       query1.setFloat(v*128);
    }else
    {
       query1.setFloat(v);
    }

	itsBaseWindow->addMessageToQue(query1);

//    ParameterMsg query(Message::MCB,Message::AP, 204);
//    query.getFloat();
//    itsBaseWindow->addMessageToQue(query);
}

void WBSDWaterWindow::on_btnResetWaterfilter_clicked(){
	QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QObject::tr("Confirm filter change"), QObject::tr("Are you sure you whant to reset filter counter?"),QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
		ParameterMsg query1(Message::MCB,Message::DV, 21, Message::SET_PARAMETER);
		query1.setBit(5,1);
		itsBaseWindow->addMessageToQue(query1);
	}

}
void WBSDWaterWindow::on_btnResetDecalc_clicked(){
	QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QObject::tr("Confirm descaling"), QObject::tr("Confirm start of descaling routine?"),QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        //ParameterMsg queryServ(Message::UIB,Message::DV,2);
        //queryServ.setNibble(0,0);
        //itsBaseWindow->addMessageToQue(queryServ);


        ParameterMsg query1(Message::MCB,Message::DP, 33, Message::SET_PARAMETER);
        query1.setChar(1,1);
		itsBaseWindow->addMessageToQue(query1);
	}
}


void WBSDWaterWindow::enable_waterfilter(bool aFlag){
	ui->lblWaterFilter1->setEnabled(aFlag);
	ui->lblWaterFilter2->setEnabled(aFlag);
	ui->lblWaterFilter3->setEnabled(aFlag);
	ui->lblWaterFilter4->setEnabled(aFlag);
	ui->cboBlockOnFilter->setEnabled(aFlag);
	ui->spiFilterResetVal->setEnabled(aFlag);
	ui->spiFilterWarn->setEnabled(aFlag);
	ui->lblWaterFilterCounter->setEnabled(aFlag);
	ui->btnResetWaterfilter->setEnabled(aFlag);
}
void WBSDWaterWindow::enable_descalefilter(bool aFlag){
	ui->lblDescaleFilter1->setEnabled(aFlag);
	ui->lblDescaleFilter2->setEnabled(aFlag);
	ui->lblDescaleFilter3->setEnabled(aFlag);
	ui->lblDescaleFilter4->setEnabled(aFlag);
	ui->cboBlockOnDecalc->setEnabled(aFlag);
	ui->spiDecalcResetVal->setEnabled(aFlag);
	ui->spiDecalcWarn->setEnabled(aFlag);
	ui->lblDecalcCounter->setEnabled(aFlag);
	ui->btnResetDecalc->setEnabled(aFlag);
}


void WBSDWaterWindow::update_cbo(QComboBox* theBox, unsigned int conf)
{
	int noItems = theBox->count();
	int index;

	for (index=0; index<noItems; index++){
		int itemVal = theBox->itemData(index).toInt();
		if (conf==itemVal) {
			theBox->setCurrentIndex(index);
			break;
		}
	}
}


WBSDWaterWindow::~WBSDWaterWindow()
{
    myTimer->stop();
	myTimer->deleteLater();
	myTimer=0;
	delete ui;
	this->deleteLater();

}

void WBSDWaterWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();

}

void WBSDWaterWindow::updateBoilerTempU(QString temp)
{
    //RJ TO DO automatic °C/F
    QString tempText;
    if(itsBaseWindow->getUnitTmp() == 0)
    {
        tempText = QString("%1 °C").arg(temp);
    }
    else
    {
        tempText = QString("%1 °F").arg(temp);
    }
    ui->boilerTempU->setText(tempText);
}
void WBSDWaterWindow::updateBoilerTempM(QString temp)
{
    //RJ TO DO automatic °C/F
    QString tempText;
    if(itsBaseWindow->getUnitTmp() == 0)
    {
        tempText = QString("%1 °C").arg(temp);
    }
    else
    {
        tempText = QString("%1 °F").arg(temp);
    }
	ui->boilerTempM->setText(tempText);
}
static const char* lvlState[] = {
    QT_TRANSLATE_NOOP("Level_State_Txt", "No Water"),
    QT_TRANSLATE_NOOP("Level_State_Txt", "Refill"),
    QT_TRANSLATE_NOOP("Level_State_Txt", "Filling"),
    QT_TRANSLATE_NOOP("Level_State_Txt", "Long Filling"),
    QT_TRANSLATE_NOOP("Level_State_Txt", "Full"),
    QT_TRANSLATE_NOOP("Level_State_Txt", "Error"),
    QT_TRANSLATE_NOOP("Level_State_Txt", "Test"),
    QT_TRANSLATE_NOOP("Level_State_Txt", "Standby"),
    QT_TRANSLATE_NOOP("Level_State_Txt", "Dispense")
};
void WBSDWaterWindow::updateLevelState(int aState){


    switch (aState) {
        case 0:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[0]));
                break;
        case 1:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[1]));
                break;
        case 2:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[2]));
                break;
        case 3:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[3]));
                break;
        case 4:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[4]));
                break;
        case 5:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[5]));
                break;
        case 6:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[6]));
                break;
        case 7:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[7]));
                break;
        case 8:
            ui->levelState->setText(Application::translate("Level_State_Txt",lvlState[8]));
                break;
        default:
                break;
    }
    /*ui->lcdLevBoilSt->setDecMode();
    ui->lcdLevBoilSt->display(aState);
    ui->lcdLevBoilSt->update();*/

}
static const char* heatest[] = {
    QT_TRANSLATE_NOOP("Heat_State_Txt", "ON"),
    QT_TRANSLATE_NOOP("Heat_State_Txt", "OFF")

};
void WBSDWaterWindow::updateHeatingState(int aState)
{
    switch (aState) {
        case 0:
        ui->heatingState->setText(Application::translate("Heat_State_Txt",heatest[1]));
                break;
        case 1:
        ui->heatingState->setText(Application::translate("Heat_State_Txt",heatest[0]));
                break;
        default:
                break;
    }
}

void WBSDWaterWindow::updateTopTemp(double temp)
{
    if(fisequal(temp,_lastupvalue)) return;
    ui->topTemp->setValue(temp);
    _lastupvalue = temp;
}

void WBSDWaterWindow::updateFilterExchange(unsigned int val)
{
//    qDebug () << "RJDEBUG updateFilterExchange";
    //    ui->filterExchange->setValue(val);
}

bool WBSDWaterWindow::fisequal(double a, double b)
{
    if((-0.001<(a-b)) && ((a-b)<0.001)) return true;
    return false;
}
/*need to modify for watertank offset =5 other =2.8*/
void WBSDWaterWindow::on_topTemp_editingFinished() {

    if(_upflab1) {_upflab1 =false ;return;}

   if(fisequal(_lastupvalue,ui->topTemp->value())) return;
   _lastupvalue = ui->topTemp->value();
    if(itsBaseWindow->getUnitTmp() == 1)
    {
        if(ui->topTemp->value() < 122 ) return;
    }else
    {
        if(ui->topTemp->value() < 50 ) return;
    }

    if(_isWaterTank)
    {
        if(itsBaseWindow->getUnitTmp() == 1)
        {
            if(ui->topTemp->value() >  197.6) QMessageBox::question(this,QObject::tr("Setting Warning"),QObject::tr("Set temperature too high may cause Error 241"),QMessageBox::Ok);
        }else
        {
            if(ui->topTemp->value() >   92) QMessageBox::question(this,QObject::tr("Setting Warning"),QObject::tr("Set temperature too high may cause Error 241"),QMessageBox::Ok);
        }
    }
    else
    {
        if(itsBaseWindow->getUnitTmp() == 1)
        {
            if(ui->topTemp->value() >  200.8) QMessageBox::question(this,QObject::tr("Setting Warning"),QObject::tr("Set temperature too high may cause Error 241"),QMessageBox::Ok);
        }else
        {
            if(ui->topTemp->value() >   93.8) QMessageBox::question(this,QObject::tr("Setting Warning"),QObject::tr("Set temperature too high may cause Error 241"),QMessageBox::Ok);
        }
    }



    ParameterMsg query1(Message::MCB,Message::AP, 2, Message::SET_PARAMETER);
    ParameterMsg query2(Message::MCB,Message::AP, 0, Message::SET_PARAMETER);
    if(_isWaterTank)
    {
        query1.setFloat(ui->topTemp->value()-4.2);
    }else
    {
        query1.setFloat(ui->topTemp->value()-2.8);
    }
    query2.setFloat(ui->topTemp->value()); //Offset top block temp - temp set point
	itsBaseWindow->addMessageToQue(query1);
	itsBaseWindow->addMessageToQue(query2);    
}





void WBSDWaterWindow::updateBlockTemp(double temp)
{
    _upflab2 = true;
    ui->blockTemp->setValue(temp);
    _lastblockvalue=ui->blockTemp->value();
}

void WBSDWaterWindow::on_blockTemp_editingFinished() {
    if(_upflab2) {_upflab2 =false ;return;}
    if(ui->blockTemp->value() < 75 ) return;
    ParameterMsg query1(Message::MCB,Message::AP, 6, Message::SET_PARAMETER);
    query1.setFloat(ui->blockTemp->value());
	itsBaseWindow->addMessageToQue(query1);
}


void WBSDWaterWindow::connectionStatusChanged(int aStatus,StringMessage aMSG){
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDWaterWindow::updateData(){
    ParameterMsg msg1(Message::MCB,Message::AV,0);
    ParameterMsg msg2(Message::MCB,Message::AV,1);
    ParameterMsg msg3(Message::MCB,Message::AV,2);
    ParameterMsg msg4(Message::MCB,Message::DV,1);
    ParameterMsg msg5(Message::MCB,Message::DV,2);
    msg1.getWord();
    msg2.getWord();
    msg3.getWord();
	msg4.getWord();
	msg5.getWord();
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg3);
    itsBaseWindow->addMessageToQue(msg4);
    itsBaseWindow->addMessageToQue(msg5);

	//DB_DECALC_WTR_AMOUNT_LEFT     &cu_ap[192]
    ParameterMsg filtermsg4(Message::MCB,Message::AP, 192);
    filtermsg4.getFloat();
	itsBaseWindow->addMessageToQue(filtermsg4);
	//DB_FILTER_WTR_AMOUNT_LEFT     &cu_ap[193]
    ParameterMsg filtermsg5(Message::MCB,Message::AP, 193);
    filtermsg5.getFloat();
	itsBaseWindow->addMessageToQue(filtermsg5);

}

void WBSDWaterWindow::savest()
{
    if(_pwcnt>0) return;
    if(!fisequal(_lastblockvalue,ui->blockTemp->value()) && !fisequal(100,ui->blockTemp->value()))
    {
        _lastblockvalue = ui->blockTemp->value();
        this->on_blockTemp_editingFinished();
        qDebug()<<"saveest block"<<_lastblockvalue;
    }
    if(!fisequal(_lastupvalue,ui->topTemp->value()) && !fisequal(100,ui->topTemp->value()))
    {

        this->on_topTemp_editingFinished();
        qDebug()<<"saveest up"<<_lastupvalue;

    }

}

void WBSDWaterWindow::gotMessage(Message aMsg)
{
    QString txt;
    char aLevelState;
    unsigned int aVal;
    float aValf;
    unsigned int tempVar;
    char aRfgState;
    QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
	qDebug() << aMsg.getDataInt();

    Message::qtype atype=aMsg.getType();
    switch (atype){
    case (Message::REPLY_DB):
        switch ((unsigned char)aMsg.getBoard()){
        case Message::MCB:
            switch ((unsigned char)aMsg.getDataBaseType())
            {

             case Message::DV:
                switch(aMsg.getParameters().at(3)){

                case 1:
                    aVal=aMsg.getDataUInt();
                    updateHeatingState((int)(aVal & 0x01));
                    break;
                case 2:
                    aVal=aMsg.getDataUInt();
                    updateLevelState((int)(aVal & 0xf0) >> 4);
					if (myTimer!=0) 
                        myTimer->singleShot(1000,this,SLOT(updateData()));
					 break;

                }
                break;
            case Message::AP:
                switch((unsigned char)aMsg.getParameters().at(3)){
                    case 0:
                        //if(_pwcnt<=0)break;
                        _pwcnt--;

                        if(!fisequal(ui->topTemp->value(),aMsg.getDataFloat()) && aMsg.getDataFloat()<=212)
                        {
                            qDebug()<<"updateTopTemp"<<aMsg.getDataFloat()<<"ui->topTemp->value()"<<ui->topTemp->value();
                            updateTopTemp(aMsg.getDataFloat());
                        }
                        else
                        {
                            qDebug()<<"updateTopTemp1="<<aMsg.getDataFloat()<<"ui->topTemp->value()1="<<ui->topTemp->value();

                        }
                        break;
                    case 6:
                    //if(_pwcnt<=0)break;
                        _pwcnt--;
                        if(!fisequal(ui->blockTemp->value(),aMsg.getDataFloat()))
                        {
                            updateBlockTemp(aMsg.getDataFloat());
                        }
                        break;
                    case 192: //DB_DECALC_WTR_AMOUNT_LEFT
                    if(itsBaseWindow->getUnitTmp() == 1)
                    {
                        ui->lblDecalcCounter->setText(QString().sprintf("%.2f",aMsg.getDataFloat()/1000*oz_tmp,6));
                        ui->lblDescaleFilter1->setText(QObject::tr("descale amount left counter          （Gallons）  "));
                    }else
                    {
                        ui->lblDecalcCounter->setText(QString("%1").arg(aMsg.getDataFloat()/1000,6,'g'));
                        ui->lblDescaleFilter1->setText(QObject::tr("descale amount left counter          （Liters）  "));

                    }
                        break;
                    case 193: //DB_FILTER_WTR_AMOUNT_LEFT
                    if(itsBaseWindow->getUnitTmp() == 1)
                    {
                        ui->lblWaterFilterCounter->setText(QString().sprintf("%.2f",aMsg.getDataFloat()/1000*oz_tmp,6));
                        ui->lblWaterFilter1->setText(QObject::tr("Waterfilter amount left counter     （Gallons）"));
                    }else
                    {
						ui->lblWaterFilterCounter->setText(QString("%1").arg(aMsg.getDataFloat()/1000,6,'g'));
                        ui->lblWaterFilter1->setText(QObject::tr("Waterfilter amount left counter     （Liters）"));
                    }
                    break;
                    case 201:
                    aValf=aMsg.getDataFloat();
                    if(itsBaseWindow->getUnitTmp() == 1)
                    {
                         ui->spiFilterResetVal->setValue(aValf/128);
                    }else
                    {
                         ui->spiFilterResetVal->setValue(aValf);
                    }

                    enable_waterfilter(aValf>0);
                    if (aValf==0){
                        update_cbo(ui->cboUseWaterFilterCounters,0);
                    } else {
                        update_cbo(ui->cboUseWaterFilterCounters,1);
                    }
                    break;
                    case 202:
                    //# DB_LOCK_ON_FILTER: [MCB DP: 29: Bit00]
                    //# DB_LOCK_ON_DECALC: [MCB DP: 29: Bit01]
                    aValf=aMsg.getDataFloat();
                    if(itsBaseWindow->getUnitTmp() == 1)
                    {
                        ui->spiFilterWarn->setValue(aValf/128);
                    }else
                    {
                       ui->spiFilterWarn->setValue(aValf);
                    }

                   break;
                    case 203:
                    aValf=aMsg.getDataFloat();
                    if(itsBaseWindow->getUnitTmp() == 1)
                    {
                        ui->spiDecalcResetVal->setValue(aValf/128);
                    }else {
                       ui->spiDecalcResetVal->setValue(aValf);
                    }

                    enable_descalefilter(aValf>0);
                    if (aValf==0){
                        update_cbo(ui->cboUseDescaleCounters,0);
                    } else {
                        update_cbo(ui->cboUseDescaleCounters,1);
                    }
                    break;
                    case 204:
                    //# DB_LOCK_ON_FILTER: [MCB DP: 29: Bit00]
                    //# DB_LOCK_ON_DECALC: [MCB DP: 29: Bit01]
                    aValf=aMsg.getDataFloat();
                    if(itsBaseWindow->getUnitTmp() == 1)
                    {
                        ui->spiDecalcWarn->setValue(aValf/128);
                    }else
                    {
                       ui->spiDecalcWarn->setValue(aValf);
                    }
                     break;

                    default:
                        break;
                }

                break;
            case Message::AV:
                switch(aMsg.getParameters().at(3)){
                    case 0:
                        updateBoilerTempU(QString::number(aMsg.getDataFloat()));
                        break;
                    case 1:
                        updateBoilerTempM(QString::number(aMsg.getDataFloat()));
                        break;
                    default:
                        break;
                }
                break;
            case Message::DP:
                switch(aMsg.getParameters().at(3)){
                case (0):
                    aVal=aMsg.getDataUInt();
                    qDebug()<<"(0x8000 & aVal) >> 15"<<((0x8000 & aVal) >> 15);
                    itsBaseWindow->setUnitTmp((0x8000 & aVal) >> 15);
                    /*modify by Lee  c/f  */
                    if(itsBaseWindow->getUnitTmp() == 0)
                    {
                        ui->spiDecalcWarn->setMaximum(15);
                        ui->spiFilterWarn->setMaximum(15);
                        ui->spiDecalcWarn->setSingleStep(5);
                        ui->spiFilterWarn->setSingleStep(5);
                        ui->topTemp->setMaximum(94);
                        ui->blockTemp->setMaximum(94);
                        ui->label_3->setText(QObject::tr("Boiler temperature set-point (°C)"));
                        ui->label_4->setText(QObject::tr("Block temperature set-point (°C)"));
                        qDebug()<<"setMaximum "<<ui->topTemp->value();
                    }
                    else
                    {
                        ui->spiDecalcWarn->setMaximum(3.96);
                        ui->spiFilterWarn->setMaximum(3.96);
                        ui->spiDecalcWarn->setSingleStep(1.32);
                        ui->spiFilterWarn->setSingleStep(1.32);
                        ui->topTemp->setMaximum(201);
                        ui->blockTemp->setMaximum(201);
                        ui->label_3->setText(QObject::tr("Boiler temperature set-point (°F)"));
                        ui->label_4->setText(QObject::tr("Block temperature set-point (°F)"));
                        qDebug()<<"setMaximum "<<ui->topTemp->value();
                    }
                    if(itsBaseWindow->getUnitTmp() == 0)
                    {
                        ui->label_14->setText(QObject::tr("Use descale counters(change it from Disabled to Enabled will  \n set the descale counter reset value to the factory value 150 L)"));
                        ui->label_15->setText(QObject::tr("Use waterfilter counters (change it from Disabled to Enabled will  \n set the Water counter reset value to the factory value 2000 L)"));
                        ui->lblWaterFilter3->setText(QObject::tr("Waterfilter warn level                   （Liters）  "));
                        ui->lblDescaleFilter3->setText(QObject::tr("descale filter warn level               （Liters）  "));
                    }
                    else
                    {
                        ui->label_14->setText(QObject::tr("Use descale counters(change it from Disabled to Enabled will  \n set the descale counter reset value to the factory value 39.63 Gal)"));
                        ui->label_15->setText(QObject::tr("Use waterfilter counters (change it from Disabled to Enabled will  \n set the Water counter reset value to the factory value 528.34 Gal)"));
                        ui->lblWaterFilter3->setText(QObject::tr("Waterfilter warn level                   （Gallons）  "));
                        ui->lblDescaleFilter3->setText(QObject::tr("descale filter warn level               （Gallons）  "));
                    }
                    break;
                case 4://get watertank
                    aVal=aMsg.getDataUInt();
                    _isWaterTank = (((aVal&0xF0)==208)?true:false);
                    qDebug()<<(aVal&0xF0);
                    break;
                case 27:/*modify by lee 11-4-2014*/
                    aVal=aMsg.getDataUInt();
                    if((aVal&0x100)==0x100)
                    {
                        update_cbo(ui->cboBlockOnFilter,1);
                    }else
                    {
                        update_cbo(ui->cboBlockOnFilter,0);
                    }

                    update_cbo(ui->cboBlockOnDecalc,((aVal&0x200)==0x200)?1:0);
                    break;
                default:
                    break;
                }
            }
            break;
		}
		
}
}



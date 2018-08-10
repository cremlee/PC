#include "qstack.h"
#include "wbsddisplayoptwindow.h"
#include "ui_wbsddisplayoptwindow.h"
#include "qdebug.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "message.h"
#include "application.h"
#include "databasehelper.h"
#include "lngmessage.h"
#include "wbsd_serial_port.h"

#include <QFile>
#include <QFileDialog>
#include <QList>
/*modify  by lee

Display settings: Volume mode (off, cup volume, milk, sugar).

There is choco in the machine, so sugar and milk are not possible.
There is a spec in the WBSD in which is mentioned”prevent technicians from entering impossible selections”.
19-8-2014 Should be solved in next release.
3-9-2014 No liquid mik strenth adjustments, only instant milk.
5-9-2014: Does not matter what is selected as compartment, preselection can be set to cup volume, milk and sugar.  When milk is selected in the compartment: sugar feeding speed should not be possible. When sugar is selected, milk ratio should not be possible. When tea, coffee or choco is selected, milk ratio an sugar feeding speed should not be possible.

10-17-2014: water fliter and descaling should been added into.
modefy by lee
add happy hour  setting 20151123
version 1.38
*/
WBSDDisplayOptWindow::WBSDDisplayOptWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDDisplayOptWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_displayopt", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_displayopt",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
	lngbuffer=new QByteArray ();
    configSettingsIndex();
    updateData();
    /*modify by Lee.li*/

    if(itsBaseWindow->getMachineUnit() == WBSDBaseWindow::UNIT_USA)
        ui->cb_Ani->setEnabled(false);
    ui->centralwidget->setLayout(ui->gridLayout);
}

WBSDDisplayOptWindow::~WBSDDisplayOptWindow()
{
    delete ui;
}

void WBSDDisplayOptWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
}

void WBSDDisplayOptWindow::configSettingsIndex()
{
    static const char* tempUnit[] = {
        QT_TRANSLATE_NOOP("display_tempunit", "Celsius"),
        QT_TRANSLATE_NOOP("display_tempunit", "Fahrenheit")
    };
    static const char* numMode[] = {
        QT_TRANSLATE_NOOP("display_nummode", "Show cooler temp"),
        QT_TRANSLATE_NOOP("display_nummode", "Show time")
    };
    static const char* showOpTel[] = {
        QT_TRANSLATE_NOOP("display_optel", "Disable"),
        QT_TRANSLATE_NOOP("display_optel", "Show operator phone number if error and drink button pressed")
    };
    static const char* showServTel[] = {
        QT_TRANSLATE_NOOP("display_servtel", "Disable"),
        QT_TRANSLATE_NOOP("display_servtel", "Show service phone number if error and drink button pressed")
    };
    static const char* enableDisable[] = {
        QT_TRANSLATE_NOOP("display_enabledisable", "Disable"),
        QT_TRANSLATE_NOOP("display_enabledisable", "Enable")
    };
    static const char* volMode[] = {
        QT_TRANSLATE_NOOP("display_volmode", "Disable"),
        QT_TRANSLATE_NOOP("display_volmode", "Cup volume"),
        QT_TRANSLATE_NOOP("display_volmode", "Instant milk"),
        QT_TRANSLATE_NOOP("display_volmode", "Sugar")
    };
    static const char* LCDANI[] = {
        QT_TRANSLATE_NOOP("LCDANI", "HIDE"),
        QT_TRANSLATE_NOOP("LCDANI", "SHOW")

    };
    static const char* cupsize[] ={
        QT_TRANSLATE_NOOP("display_cupsize", "Small"),
        QT_TRANSLATE_NOOP("display_cupsize", "Medium"),
        QT_TRANSLATE_NOOP("display_cupsize", "Large")
    };


    ui->cobcupsize->addItem(Application::translate("display_cupsize",cupsize[0]),0x01);
    ui->cobcupsize->addItem(Application::translate("display_cupsize",cupsize[1]),0x02);
    ui->cobcupsize->addItem(Application::translate("display_cupsize",cupsize[2]),0x03);

    DataBaseHelper::getInstance()->populateComboFromTabKat("012",ui->tempUnit);
    DataBaseHelper::getInstance()->populateComboFromTabKat("006",ui->showNumMode);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->showHotW);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->showOpTel);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->showServTel);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->showLogo);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->strMode);
    //Need to be Improve
    DataBaseHelper::getInstance()->populateComboFromTabKat("007",ui->volMode);
    //
    DataBaseHelper::getInstance()->populateComboFromTabKat("004",ui->ledDIM);

	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowCleaning);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowCounters);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowDate);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowECO);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowPay);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowPhone);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowRFID);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowStrength);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowVol);
	DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboShowWelcome);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cb_Ani);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cbdescal);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cbwf);

    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowHpy);
    DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cboOperShowCountersRst);



    //ui->cb_Ani->addItem(Application::translate("LCDANI",LCDANI[0]),0x0);
    //ui->cb_Ani->addItem(Application::translate("LCDANI",LCDANI[1]),0x1);
//    ui->tempUnit->addItem(Application::translate("display_tempunit",tempUnit[0]),0x0);
//    ui->tempUnit->addItem(Application::translate("display_tempunit",tempUnit[1]),0x1);
//    ui->showNumMode->addItem(Application::translate("display_nummode",numMode[0]),0x0);
//    ui->showNumMode->addItem(Application::translate("display_nummode",numMode[1]),0x1);
//    ui->showHotW->addItem(Application::translate("display_enabledisable",enableDisable[0]),0x0);
//   ui->showHotW->addItem(Application::translate("display_enabledisable",enableDisable[1]),0x1);
//    ui->showOpTel->addItem(Application::translate("display_optel",showOpTel[0]),0x0);
//    ui->showOpTel->addItem(Application::translate("display_optel",showOpTel[1]),0x1);
//    ui->showServTel->addItem(Application::translate("display_servtel",showServTel[0]),0x0);
//    ui->showServTel->addItem(Application::translate("display_servtel",showServTel[1]),0x1);
//    ui->showLogo->addItem(Application::translate("display_enabledisable",enableDisable[0]),0x0);
//    ui->showLogo->addItem(Application::translate("display_enabledisable",enableDisable[1]),0x1);
//    ui->strMode->addItem(Application::translate("display_enabledisable",enableDisable[0]),0x0);
//    ui->strMode->addItem(Application::translate("display_enabledisable",enableDisable[1]),0x1);
//    ui->volMode->addItem(Application::translate("display_volmode",volMode[0]),0x0);
//    ui->volMode->addItem(Application::translate("display_volmode",volMode[1]),0x1);
//    ui->volMode->addItem(Application::translate("display_volmode",volMode[2]),0x2);
//    ui->volMode->addItem(Application::translate("display_volmode",volMode[3]),0x3);

    boardDp0BitField = 0;
    doorDp0BitField = 0;
    doorDp18BitField = 0;
}

void WBSDDisplayOptWindow::updateTempUnit(int conf)
{
    int noItems = ui->tempUnit->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->tempUnit->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->tempUnit->setCurrentIndex(index);
            break;
        }
    }
    itsBaseWindow->setUnitTmp(ui->tempUnit->itemData(index).toInt());
    QString qss=QString("RJDEBUG WBSDDisplayOptWindow::updateTempUnit index %1").arg(index);
    qDebug () << qss;
}

void WBSDDisplayOptWindow::updateShowLogo(int conf)
{
    int noItems = ui->showLogo->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->showLogo->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->showLogo->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDDisplayOptWindow::updateShowLogo index %1").arg(index);
    qDebug () << qss;
}

void WBSDDisplayOptWindow::updateshowNumMode(int conf)
{

    int noItems = ui->showNumMode->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->showNumMode->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->showNumMode->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDDisplayOptWindow::updateshowNumMode index %1").arg(index);
    qDebug () << qss;
}

void WBSDDisplayOptWindow::updateshowOpTel(int conf)
{
    int noItems = ui->showOpTel->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->showOpTel->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->showOpTel->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDDisplayOptWindow::updateshowOpTel index %1").arg(index);
    qDebug () << qss;
}

void WBSDDisplayOptWindow::updateshowServTel(int conf)
{
    int noItems = ui->showServTel->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->showServTel->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->showServTel->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDDisplayOptWindow::updateshowServTel index %1").arg(index);
    qDebug () << qss;
}

void WBSDDisplayOptWindow::updateStrMode(int conf)
{
    int noItems = ui->strMode->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->strMode->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->strMode->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDDisplayOptWindow::updateStrMode index %1").arg(index);
    qDebug () << qss;
}

void WBSDDisplayOptWindow::updateVolMode(int conf)
{
    int noItems = ui->volMode->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->volMode->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->volMode->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDDisplayOptWindow::updateVolMode index %1").arg(index);
    qDebug () << qss;
}


//DP16
void WBSDDisplayOptWindow::updateStartMessage(int conf){
	int noItems = ui->cboShowWelcome->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboShowWelcome->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboShowWelcome->setCurrentIndex(index);
            break;
        }
    }
}

void WBSDDisplayOptWindow::updateOptShowClean(int conf){
	int noItems = ui->cboOperShowCleaning->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboOperShowCleaning->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowCleaning->setCurrentIndex(index);
            break;
        }
    }
}
//DP8
void WBSDDisplayOptWindow::updateOptShowECO(int conf){
	int noItems = ui->cboOperShowECO->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboOperShowECO->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowECO->setCurrentIndex(index);
            break;
        }
    }
}
void WBSDDisplayOptWindow::updateOptShowPHONE(int conf){
	int noItems = ui->cboOperShowPhone->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboOperShowPhone->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowPhone->setCurrentIndex(index);
            break;
        }
    }
}
void WBSDDisplayOptWindow::updateOptShowPAY(int conf){
	int noItems = ui->cboOperShowPay->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboOperShowPay->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowPay->setCurrentIndex(index);
            break;
        }
    }
}
void WBSDDisplayOptWindow::updateOptShowRFID(int conf){
	int noItems = ui->cboOperShowRFID->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboOperShowRFID->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowRFID->setCurrentIndex(index);
            break;
        }
    }
}
//dp23
void WBSDDisplayOptWindow::updatewf(int conf)
{
    int flag;
    if((conf & 0x00000002)== 0x02)
    {
        //show
        flag =1;
    }else
    {
        //off
        flag =0;
    }
    int noItems = ui->cbwf->count();
    int index;
    for (index=0; index<noItems; index++){
        int itemVal = ui->cbwf->itemData(index).toInt();
        if ((flag)==itemVal) {
            ui->cbwf->setCurrentIndex(index);
            break;
        }
    }
}

void WBSDDisplayOptWindow::updatedc(int conf)
{
    int flag;
    if((conf & 0x00000001)== 0x01)
    {
        //show
        flag =1;
    }else
    {
        //off
        flag =0;
    }
    int noItems = ui->cbdescal->count();
    int index;
    for (index=0; index<noItems; index++){
        int itemVal = ui->cbdescal->itemData(index).toInt();
        if ((flag)==itemVal) {
            ui->cbdescal->setCurrentIndex(index);
            break;
        }
    }
}

void WBSDDisplayOptWindow::updateHpy(int conf)
{
    int flag;
    if((conf & 0x00000004)== 0x04)
    {
        //show
        flag =1;
    }else
    {
        //off
        flag =0;
    }
    int noItems = ui->cboOperShowHpy->count();
    int index;
    for (index=0; index<noItems; index++){
        int itemVal = ui->cboOperShowHpy->itemData(index).toInt();
        if ((flag)==itemVal) {
            ui->cboOperShowHpy->setCurrentIndex(index);
            break;
        }
    }
}

void WBSDDisplayOptWindow::updateRstbtn(int conf)
{
    int flag;
    if((conf & 0x00000020)== 0x20)
    {
        //show
        flag =1;
    }else
    {
        //off
        flag =0;
    }
    int noItems = ui->cboOperShowCountersRst->count();
    int index;
    for (index=0; index<noItems; index++){
        int itemVal = ui->cboOperShowCountersRst->itemData(index).toInt();
        if ((flag)==itemVal) {
            ui->cboOperShowCountersRst->setCurrentIndex(index);
            break;
        }
    }
}
//DP4
void WBSDDisplayOptWindow::updateOptShowCounters(int conf){
	int noItems = ui->cboOperShowCounters->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboOperShowCounters->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowCounters->setCurrentIndex(index);
            break;
        }
    }
}
void WBSDDisplayOptWindow::updateOptShowVolume(int conf){
	int noItems = ui->cboOperShowVol->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboOperShowVol->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowVol->setCurrentIndex(index);
            break;
        }
    }
}
void WBSDDisplayOptWindow::updateOptShowStrength(int conf){
	int noItems = ui->cboOperShowStrength->count();
    int index;
    for (index=0; index<noItems; index++){
		int itemVal = ui->cboOperShowStrength->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowStrength->setCurrentIndex(index);
            break;
        }
    }
}
void WBSDDisplayOptWindow::updateOptShowDate(int conf){
	int noItems = ui->cboOperShowDate->count();
    int index;
    for (index=0; index<noItems; index++){
        int itemVal = ui->cboOperShowDate->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->cboOperShowDate->setCurrentIndex(index);
            break;
        }
    }
}




void WBSDDisplayOptWindow::updateHotWarn(int conf)
{
    int noItems = ui->showHotW->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->showHotW->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->showHotW->setCurrentIndex(index);
            break;
        }
    }
}

void WBSDDisplayOptWindow::updateLedDIM(int conf)
{
    int noItems = ui->ledDIM->count();
    int index;

    QString qss=QString("RJDEBUG updateLedDIM value %1").arg(conf);
    qDebug () << qss;

    for (index=0; index<noItems; index++){
        int itemVal = ui->ledDIM->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->ledDIM->setCurrentIndex(index);
            break;
        }
    }
}

void WBSDDisplayOptWindow::on_tempUnit_activated(int index)
{
    int value = ui->tempUnit->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_tempUnit_activated value %1").arg(value);
    qDebug () << qss;

    setBodyDP0Parameter(value, 15);
    itsBaseWindow->setUnitTmp(value);
}

void WBSDDisplayOptWindow::on_showHotW_activated(int index)
{
    int value = ui->showHotW->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_showHotW_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP18Parameter(value, 1, 1);

}
void WBSDDisplayOptWindow::on_btnUpload_clicked()
{
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
	QString filename=QFileDialog::getOpenFileName(this,"Select language file",".//lng","lng (*.lng)");

	if (filename!=""){
		ui->btnUpload->setEnabled(false);
		this->setCursor(Qt::WaitCursor);
		QFile f( filename );
		f.open( QIODevice::ReadOnly);
		QDataStream stream(&f);
		QByteArray aLngFile;
//		instream.setCodec("UTF-16"); // change the file codec to UTF-16.
		while (!stream.atEnd()){
			char *temp = new char[1];
			stream.readRawData(temp, 1);
			aLngFile.append(*temp);
			delete [] temp;
		}
		LngMessage aMsg(aLngFile);
		itsBaseWindow->addMessageToQue(aMsg);		
	}
    //wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

	void WBSDDisplayOptWindow::sendLanguageFile(){
	}
	
	QByteArray  WBSDDisplayOptWindow::getlngLine(){
		return QByteArray();
	}


void WBSDDisplayOptWindow::on_showNumMode_activated(int index)
{
    int value = ui->showNumMode->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_showNumMode_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP0Parameter(value, 4, 0);
}

void WBSDDisplayOptWindow::on_showLogo_activated(int index)
{
    int value = ui->showLogo->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_showLogoMode_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP0Parameter(value, 1, 11);
}

void WBSDDisplayOptWindow::on_showOpTel_activated(int index)
{
    int value = ui->showOpTel->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_showOpTel_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP0Parameter(value, 1, 9);
}

void WBSDDisplayOptWindow::on_showServTel_activated(int index)
{
    int value = ui->showServTel->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_showServTel_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP0Parameter(value, 1, 10);
}

void WBSDDisplayOptWindow::on_strMode_activated(int index)
{
    int value = ui->strMode->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_strMode_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP0Parameter(value, 1, 8);
}

void WBSDDisplayOptWindow::on_volMode_activated(int index)
{
    int value = ui->volMode->itemData(index).toInt();
    QString qss=QString("RJDEBUG on_volMode_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP0Parameter(value, 4, 4);
}

void WBSDDisplayOptWindow::on_ledDIM_activated(int index)
{
    int value = ui->ledDIM->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_ledDim_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP18Parameter(value, 4, 4);
}

// Send Body Unit DP block 0 message. Need to add all bit data in block 0.
void WBSDDisplayOptWindow::setBodyDP0Parameter(int value, int bitPos)
{
    QString qs=QString("RJDEBUG WBSDDisplayOptWindow::setBodyDP0Parameter, value = %1, bit pos = %2").arg(value).arg(bitPos);
    qDebug () << qs;

    if (value == 1) {
        boardDp0BitField = boardDp0BitField | (value << bitPos);
    }
    else { //Value 0
        boardDp0BitField = boardDp0BitField & ~(0x01 << bitPos);
    }

    ParameterMsg query(Message::MCB,Message::DP, 0, Message::SET_PARAMETER);
    query.setWord(boardDp0BitField);
    itsBaseWindow->addMessageToQue(query);
}

// Send Door Unit DP block 0 message. Need to add all bit data in block 0.
void WBSDDisplayOptWindow::setDoorDP0Parameter(int value, int bitLen, int offset)
{
    QString qs=QString("RJDEBUG WBSDDisplayOptWindow::setDoorDP0Parameter, value = %1, offset = %2, bitLen=%3").arg(value).arg(offset).arg(bitLen);
    qDebug () << qs;
    unsigned int debug_i =0;
    unsigned int val = 0;
    ParameterMsg query(Message::UIB,Message::DP, 0, Message::SET_PARAMETER);
	switch (bitLen){
	case 1:
		query.setBit(offset,value);
		break;
	case 4:
		query.setNibble(offset/4,value);
		break;
	case 8:
		query.setChar(offset/8,value);
		break;
	}
    itsBaseWindow->addMessageToQue(query);
}

void WBSDDisplayOptWindow::setDoorDP4Parameter(int value, int bitLen, int offset)
{
    unsigned int debug_i =0;
    unsigned int val = 0;


    ParameterMsg query(Message::UIB,Message::DP, 4, Message::SET_PARAMETER);
	switch (bitLen){
	case 1:
		query.setBit(offset,value);
		break;
	case 4:
		query.setNibble(offset/4,value);
		break;
	case 8:
		query.setChar(offset/8,value);
		break;
	}
    itsBaseWindow->addMessageToQue(query);
}
void WBSDDisplayOptWindow::setDoorDP8Parameter(int value, int bitLen, int offset)
{
    unsigned int debug_i =0;
    unsigned int val = 0;


    ParameterMsg query(Message::UIB,Message::DP, 8, Message::SET_PARAMETER);
	switch (bitLen){
	case 1:
		query.setBit(offset,value);
		break;
	case 4:
		query.setNibble(offset/4,value);
		break;
	case 8:
		query.setChar(offset/8,value);
		break;
	}
    itsBaseWindow->addMessageToQue(query);
}

// Send Door Unit DP block 16 message. Need to add all bit data in block 0.
void WBSDDisplayOptWindow::setDoorDP18Parameter(int value, int bitLen, int offset)
{
    QString qs=QString("RJDEBUG WBSDDisplayOptWindow::setDoorDP16Parameter, value = %1, offset = %2, bitLen=%3").arg(value).arg(offset).arg(bitLen);
    qDebug () << qs;

    ParameterMsg query(Message::UIB,Message::DP, 18, Message::SET_PARAMETER);
	switch (bitLen){
	case 1:
		query.setBit(offset,value);
		break;
	case 4:
		query.setNibble(offset/4,value);
		break;
	case 8:
		query.setChar(offset/8,value);
		break;
	}
    itsBaseWindow->addMessageToQue(query);
}

void WBSDDisplayOptWindow::on_cboShowWelcome_activated(int index){
    int value = ui->cboShowWelcome->itemData(index).toInt();
    setDoorDP18Parameter(value, 1, 2);
}
void WBSDDisplayOptWindow::on_cboOperShowCleaning_activated(int index){
    int value = ui->cboOperShowCleaning->itemData(index).toInt();
    setDoorDP18Parameter(value, 1, 3);
}

void WBSDDisplayOptWindow::on_cboOperShowCounters_activated(int index){
    int value = ui->cboOperShowCounters->itemData(index).toInt();
    setDoorDP4Parameter(value, 1, 3);
}

void WBSDDisplayOptWindow::on_cboOperShowCountersRst_activated(int index)
{
    int value = ui->cboOperShowCountersRst->itemData(index).toInt();
    ParameterMsg query(Message::UIB,Message::DP, 23, Message::SET_PARAMETER);
    query.setBit(5,value);
    itsBaseWindow->addMessageToQue(query);
}
void WBSDDisplayOptWindow::on_cboOperShowDate_activated(int index){
    int value = ui->cboOperShowDate->itemData(index).toInt();
    setDoorDP4Parameter(value, 1, 0);
}
void WBSDDisplayOptWindow::on_cboOperShowVol_activated(int index){
    int value = ui->cboOperShowVol->itemData(index).toInt();
    setDoorDP4Parameter(value, 1, 2);
}
void WBSDDisplayOptWindow::on_cboOperShowStrength_activated(int index){
    int value = ui->cboOperShowStrength->itemData(index).toInt();
    setDoorDP4Parameter(value, 1, 1);
}

void WBSDDisplayOptWindow::on_cboOperShowHpy_activated(int index)
{
  int value = ui->cboOperShowHpy->itemData(index).toInt();
  ParameterMsg query(Message::UIB,Message::DP, 23, Message::SET_PARAMETER);
  query.setBit(2,value);
  itsBaseWindow->addMessageToQue(query);
}

void WBSDDisplayOptWindow::on_cbwf_activated(int index)
{
    int value = ui->cbwf->itemData(index).toInt();
    ParameterMsg pmsg(Message::UIB,Message::DP,23,Message::SET_PARAMETER);
    pmsg.setBit(1,value);
    itsBaseWindow->addMessageToQue(pmsg);
}

void WBSDDisplayOptWindow::on_cbdescal_activated(int index)
{
    int value = ui->cbdescal->itemData(index).toInt();
    ParameterMsg pmsg(Message::UIB,Message::DP,23,Message::SET_PARAMETER);
    pmsg.setBit(0,value);
    itsBaseWindow->addMessageToQue(pmsg);
}

void WBSDDisplayOptWindow::on_cboOperShowECO_activated(int index){
    int value = ui->cboOperShowECO->itemData(index).toInt();
    setDoorDP8Parameter(value, 1, 3);
}
void WBSDDisplayOptWindow::on_cboOperShowPhone_activated(int index){
    int value = ui->cboOperShowPhone->itemData(index).toInt();
    setDoorDP8Parameter(value, 1, 2);
}
void WBSDDisplayOptWindow::on_cboOperShowPay_activated(int index){
    int value = ui->cboOperShowPay->itemData(index).toInt();
    setDoorDP8Parameter(value, 1, 1);
}
void WBSDDisplayOptWindow::on_cboOperShowRFID_activated(int index){
    int value = ui->cboOperShowRFID->itemData(index).toInt();
    setDoorDP8Parameter(value, 1, 0);
}



void WBSDDisplayOptWindow::gotMessage(Message aMsg)
{
    QString txt;
        char aLevelState;
        unsigned int aVal;
        char aRfgState;
        int tempUnitValue;
        QByteArray data=aMsg.getData();
        QString hex=QString(data.toHex());
        qDebug() << "RJDEBUG WBSDDisplayOptWindow::gotMessage";
        Message::qtype atype=aMsg.getType();
        switch (atype){
            case (Message::ANSWER_LANGUAGE):
				this->setCursor(Qt::ArrowCursor);
				this->ui->btnUpload->setEnabled(true);
				break;
            case (Message::REPLY_DB):
                switch ((unsigned char)aMsg.getBoard()){
                    case (Message::MCB):
                        switch ((unsigned char)aMsg.getDataBaseType()){
                            case Message::DP:
                                switch(aMsg.getParameters().at(3)){
                                case (0):
                                    aVal=aMsg.getDataUInt();
                                    boardDp0BitField = aVal;
                                    qDebug() << "WBSDDisplayOptWindow::gotMessage MCB:DP:0. field=" << boardDp0BitField;
                                    tempUnitValue=(0x8000 & aVal) >> 15;
                                    qDebug()<<"tempUnitValue"<<tempUnitValue;
                                    updateTempUnit(tempUnitValue);
                                    break;
                                case (4):
                                    aVal=aMsg.getDataUInt();
                                    int  valInstant=(0x00F0 & aVal) >> 4;
                                    updateVolModeSelectItem(valInstant);
                                    qDebug()<< " valInstant "<< valInstant ;
                                    break;
                                }


                        }
                        break;
                    case (Message::UIB):
                        switch ((unsigned char)aMsg.getDataBaseType()){
                            case Message::DP:
                                switch (aMsg.getParameters().at(3)){
                                    case (0):
                                        aVal=aMsg.getDataUInt();
                                        doorDp0BitField = aVal;
                                        updateshowNumMode(0xF & aVal);
                                        updateShowLogo((0x800 & aVal) >> 11);
                                        updateshowOpTel((0x200 & aVal) >> 9);
                                        updateshowServTel((0x400 & aVal) >> 10);
                                        updateStrMode((0x0100 & aVal) >> 8);
                                        updateVolMode((0x00F0 & aVal) >> 4);
										qDebug() << "DP0:" << data.toHex();
                                        break;
                                    case (4):
                                        aVal=aMsg.getDataUInt();
                                        updateOptShowCounters((0x8 & aVal) >> 3);
                                        updateOptShowVolume((0x4 & aVal) >> 2);
                                        updateOptShowStrength((0x2 & aVal) >> 1);
                                        updateOptShowDate((0x1 & aVal) );
										qDebug() << "DP4:" << data.toHex();
										break;
                                    case (8):
                                        aVal=aMsg.getDataUInt();
                                        updateOptShowECO((0x8 & aVal) >> 3);
                                        updateOptShowPHONE((0x4 & aVal) >> 2);
										updateOptShowPAY((0x2 & aVal) >> 1);
                                        updateOptShowRFID((0x1 & aVal) );
										qDebug() << "DP8:" << data.toHex();
										break;
                                    case (18):
                                        aVal=aMsg.getDataUInt();
                                        doorDp18BitField = aVal;
                                        qDebug() << "WBSDDisplayOptWindow::gotMessage UIB:DP:16. field=" << doorDp18BitField;
                                        updateOptShowClean((0x8 & aVal) >> 3);
                                        updateStartMessage((0x4 & aVal) >> 2);
                                        updateHotWarn((0x2 & aVal) >> 1);
                                        updateLedDIM((0xF0 & aVal) >> 4);
										qDebug() << "DP18:" << data.toHex();
                                        break;
                                case (23):
                                        aVal=aMsg.getDataUInt();
                                        updatedc(aVal);
                                        updatewf(aVal);
                                        UpdateLCDInfo(aVal);
                                        updateHpy(aVal);
                                        updateRstbtn(aVal);
                                        break;
                                case 19:
                                     aVal=(aMsg.getDataUInt() & 0x0f);
                                     if((aVal-1)>=0)
                                     ui->cobcupsize->setCurrentIndex(aVal-1);
                                    break;
                                }
                        }
                        break;
                    default:
                        break;
                }
        }
}

void WBSDDisplayOptWindow::UpdateLCDInfo(uint a)
{
    if((a & 0x10)==0x10) ui->cb_Ani->setCurrentIndex(1);
    else ui->cb_Ani->setCurrentIndex(0);
    if((a & 0x08)==0x08)
    {
        ui->cb_Ani->setVisible(true);
        ui->label_9->setVisible(true);
        ui->showLogo->setVisible(false);
        ui->label_6->setVisible(false);
    }
    else
    {
        ui->cb_Ani->setVisible(false);
        ui->label_9->setVisible(false);
        ui->showLogo->setVisible(true);
        ui->label_6->setVisible(true);
        ParameterMsg queryServ(Message::UIB,Message::DP,23);
        queryServ.setBit(4,0);
        itsBaseWindow->addMessageToQue(queryServ);

    }
}

void WBSDDisplayOptWindow::on_cb_Ani_activated(int index)
{
    ParameterMsg queryServ(Message::UIB,Message::DP,23);
    queryServ.setBit(4,index);
    itsBaseWindow->addMessageToQue(queryServ);
}

void WBSDDisplayOptWindow::on_cobcupsize_activated(int index)
{
    ParameterMsg queryServ(Message::UIB,Message::DP,19);
    queryServ.setNibble(0,ui->cobcupsize->itemData(index).toInt());
    itsBaseWindow->addMessageToQue(queryServ);
}

void WBSDDisplayOptWindow::connectionStatusChanged(int aStatus,StringMessage aMSG){
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDDisplayOptWindow::updateVolModeSelectItem(int instantconf)
{
    switch (instantconf) {
    case 6: //milk
        for (int index=0; index<ui->volMode->count(); index++){

            qDebug()<<"ui->cboOperShowVol->itemData(index).toInt()="<<ui->volMode->itemData(index).toInt();
            if ( ui->volMode->itemData(index).toInt() == 3 ) {
                ui->volMode->removeItem(index);
                break;
            }
        }
        break;
    case 9: //sugar
        for (int index=0; index<ui->volMode->count(); index++){

            qDebug()<<"ui->cboOperShowVol->itemData(index).toInt()="<<ui->volMode->itemData(index).toInt();
            if ( ui->volMode->itemData(index).toInt() == 2 ) {
                ui->volMode->removeItem(index);
                break;
            }
        }
        break;
    case 7:
    case 8:
    case 10:
    case 0:
    case 13:
    case 14:
    case 15:

        for (int index=0; index<ui->volMode->count(); index++){

            qDebug()<<"ui->cboOperShowVol->itemData(index).toInt()="<<ui->volMode->itemData(index).toInt();
            if (ui->volMode->itemData(index).toInt() == 2 || ui->volMode->itemData(index).toInt() == 3 ) {
                ui->volMode->removeItem(index);
                index--;
            }
        }
        break;
    default:
        break;
    }

    //update current show;
    int value = ui->volMode->itemData(ui->volMode->currentIndex()).toInt();
    QString qss=QString("RJDEBUG on_volMode_activated value %1").arg(value);
    qDebug () << qss;
    setDoorDP0Parameter(value, 4, 4);

}

//Update initial data
void WBSDDisplayOptWindow::updateData(){
    qDebug() << "RJDEBUG WBSDDisplayOptWindow::updateData";
    ParameterMsg msg1(Message::MCB,Message::DP,0);
    ParameterMsg msg2(Message::UIB,Message::DP,0);
    ParameterMsg msg3(Message::UIB,Message::DP,18);
    ParameterMsg msg4(Message::UIB,Message::DP,4);
    ParameterMsg msg5(Message::UIB,Message::DP,8);
    ParameterMsg msg6(Message::MCB,Message::DP,4);
    ParameterMsg msg7(Message::UIB,Message::DP,23);
    ParameterMsg msg8(Message::UIB,Message::DP,19);
    msg1.getWord();
    msg2.getWord();
    msg3.getWord();
    msg4.getWord();
    msg5.getWord();
    msg6.getWord();
    msg7.getWord();
    msg8.getWord();
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg3);
    itsBaseWindow->addMessageToQue(msg4);
    itsBaseWindow->addMessageToQue(msg5);
    itsBaseWindow->addMessageToQue(msg6);
    itsBaseWindow->addMessageToQue(msg7);
    itsBaseWindow->addMessageToQue(msg8);
}

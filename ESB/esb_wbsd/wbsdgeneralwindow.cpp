#include "wbsdgeneralwindow.h"
#include "ui_wbsdgeneralwindow.h"
#include "qdebug.h"
#include <QRegExp>
#include "databasehelper.h"
#include "application.h"
#include<QMessageBox>
#include<QList>
#define FMU_ON
/*modify by Lee 11-3-2014
add the state funtion
in USA state some param should be changed and some function btn
can be grayed-out.

for the softkey for instant calibration on this screen need???

2015-02-11
Coffee BIB2 only selectable when Coffee in BIB 1 (or coffee in BIB2 automatically sets coffee in BIB1)
Decaf BIB1 only selectable when Decaf in BIB 2(or decaf in BIB1 automatically sets decaf in BIB2)

2017-07-17
db setting for fmu disable or not.
#FMU_ENABLE : [MCB:DP:26:BIT06]
P129:1:26:7:0:1

*/
int oe_empty=0;
int oe_instant_milk=6;
int oe_tea=7;
int oe_instant_choco=8;
int oe_sugar=9;
int oe_coffee=10;
int oe_decaf=11;
int oe_water_tank=13;
int oe_CF330=14;
int oe_NRIG13=15;

int valueCF330 = 0xE << 4;
int valueNRIG130 = 0xF << 4;

QString GetBibType(int bibvalue)
{
    QString ret ="";
    switch (bibvalue) {
    case 0:
        ret ="no concentrate";
        break;
    case 1:
         ret ="coffee";
        break;
    case 2:
         ret ="decaf";
        break;
    case 3:
         ret ="milk";
        break;
    case 4:
         ret ="tea";
        break;
    case 5:
         ret ="choco";
        break;
    default:
        break;
    }
    return ret;
}


WBSDGeneralWindow::WBSDGeneralWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDGeneralWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_general", "Back")
    };

    ui->setupUi(this);
    instantWindow=0;
    fmu_settingwin =0;
    menuBack = new QAction(Application::translate("back_general",back[0]), this);
    ui->menubar->addAction(menuBack);
    ui->menubar->setEnabled(true);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    configSettingsIndex();
    ui->languages->hide();
    ui->operatorAccess->hide();
	ui->label_6->hide();
	ui->paymentOpt->hide();

    connect(ui->sp_test,SIGNAL(editingFinished()),this,SLOT(test()));
    regExpPhone = QRegExp("^\\+?[0-9\\()\\-\\s]+"); //Phone number. Allow chars 0-9, (, ), +, -, ´ ´
    validatorPhone = new QRegExpValidator(regExpPhone, this);
    ui->phoneOper->setValidator(validatorPhone);
    ui->phoneServ->setValidator(validatorPhone);
    MAXLEN_PHONE = 15;  //Max length phone numbers
    ui->phoneOper->setMaxLength(MAXLEN_PHONE);
    ui->phoneServ->setMaxLength(MAXLEN_PHONE);
	updateData();
    ui->centralwidget->setLayout(ui->verticalLayout_2);
    if(itsBaseWindow->getMachineUnit() ==WBSDBaseWindow::UNIT_USA)
    {
        ui->switchOver->setEnabled(false);
        ui->label_8->setEnabled(false);
        ui->label_2->hide();
        ui->label_5->hide();
        ui->deairTimer->hide();
        ui->instantFan->hide();
        ui->label_19->setText("Component");
        ui->label_11->hide();
        ui->btn_fmu->hide();
        ui->cb_fmuswitch->hide();

    }else
    {
        ui->label_19->setText(QObject::tr("Compartment"));
    }
    ui->label_2->hide();
    ui->label_5->hide();
    ui->deairTimer->hide();
    ui->instantFan->hide();
    ui->label_9->hide();
    ui->sp_test->hide();

    /******keep for fmu part**********/
#ifndef FMU_ON
    ui->btn_fmu->hide();
    ui->cb_fmuswitch->hide();
    ui->label_11->hide();
#endif
}

WBSDGeneralWindow::~WBSDGeneralWindow()
{
    delete ui;
}

void WBSDGeneralWindow::closeEvent(QCloseEvent *evt)
{
    emit iclose();
}

void WBSDGeneralWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
}

void WBSDGeneralWindow::configSettingsIndex()
{
    static const char* enableDisable[] = {
        QT_TRANSLATE_NOOP("general_enabledisable", "Disable"),
        QT_TRANSLATE_NOOP("general_enabledisable", "Enable"),
        QT_TRANSLATE_NOOP("general_dispen_mode", "One Step"),
        QT_TRANSLATE_NOOP("general_dispen_mode", "Two Steps"),
        QT_TRANSLATE_NOOP("general_pay_mode", "OFF"),
        QT_TRANSLATE_NOOP("general_pay_mode", "JPNPAY"),
        QT_TRANSLATE_NOOP("general_pay_mode", "NAYAX"),
        QT_TRANSLATE_NOOP("general_pay_mode", "COGES")

    };

    qDebug() << "WBSDGeneralWindow::configSettingsIndex: ui->leftBIB";
    DataBaseHelper::getInstance()->populateComboFromTabKat("110",ui->leftBIB);
    qDebug() << "WBSDGeneralWindow::configSettingsIndex: ui->rightBIB";
    DataBaseHelper::getInstance()->populateComboFromTabKat("111",ui->rightBIB);
    qDebug() << "WBSDGeneralWindow::configSettingsIndex: ui->instantCoffee";
    DataBaseHelper::getInstance()->populateComboFromTabKat("112",ui->instantCoffee);

    ui->switchOver->addItem(Application::translate("general_enabledisable",enableDisable[0]),0x0);
    ui->switchOver->addItem(Application::translate("general_enabledisable",enableDisable[1]),0x1);

	DataBaseHelper::getInstance()->populateComboFromTabKat("019",ui->paymentOpt);
    DataBaseHelper::getInstance()->populateComboFromTabKat("032",ui->instantFan);
    DataBaseHelper::getInstance()->populateComboFromTabKat("032",ui->deairTimer);
    boardDp0BitField = 0;
    //DataBaseHelper::getInstance()->populateComboFromTabKat("005",ui->cbenablepay);

    ui->cb_payDispenMode->addItem(Application::translate("general_dispen_mode",enableDisable[2]),0x1);
    ui->cb_payDispenMode->addItem(Application::translate("general_dispen_mode",enableDisable[3]),0x0);

    ui->cbenablepay->addItem(Application::translate("general_pay_mode",enableDisable[4]),0x0);
    ui->cbenablepay->addItem(Application::translate("general_pay_mode",enableDisable[5]),0x1);
    ui->cbenablepay->addItem(Application::translate("general_pay_mode",enableDisable[6]),0x2);
    ui->cbenablepay->addItem(Application::translate("general_pay_mode",enableDisable[7]),0x3);

    ui->cb_fmuswitch->addItem(Application::translate("general_enabledisable",enableDisable[0]),0x0);
    ui->cb_fmuswitch->addItem(Application::translate("general_enabledisable",enableDisable[1]),0x1);


    /*modify by Lee 11-02-2014
    Remove “no conc” and “coffee”, make “decaf” only option.
    Remove “no conc”, “decaf” and “milk”, make “coffee” only option.
    Remove “CF330” , “NRI-G13” and “water tank”, change “coffee/decaf” to “instant coffee” and “empty” to “not used”. Add “instant cappuccino”.????
    Not used in the US, can be grayed-out.
    Default to “on” with no adjustment
    Is this used on the US version?

    modify by lee 2015-6-3 modify the DB file with the no concentrate add 1 to the var-end
    */
    if(itsBaseWindow->getMachineUnit() ==WBSDBaseWindow::UNIT_USA)
    {
        //ui->switchOver->setEnabled(false);
        //ui->deairTimer->setEnabled(false);
        //ui->label_5->setEnabled(false);
        //ui->label_8->setEnabled(false);
        ui->leftBIB->setEnabled(false);
        ui->rightBIB->setEnabled(false);
        for (int index=0; index<ui->leftBIB->count();){
            if(ui->leftBIB->itemData(index).toInt()!=2)
            {
                ui->leftBIB->removeItem(index);
            }else
            {
            index++;
            }
        }
        for (int index=0; index<ui->rightBIB->count(); ){
            if(ui->rightBIB->itemData(index).toInt()!=1)
            {
                ui->rightBIB->removeItem(index);
            }
            else
            {
            index++;
            }
        }
        /*Remove “CF330” , “NRI-G13” and “water tank”,
         *change “coffee/decaf” to “instant coffee”  //
         *
         * and “empty” to “not used”. Add “instant cappuccino”.*/
        for (int index=0; index<ui->instantCoffee->count(); ){
            if(ui->instantCoffee->itemData(index).toInt()==13 || ui->instantCoffee->itemData(index).toInt()==14
                    ||ui->instantCoffee->itemData(index).toInt()==15)
            {
                ui->instantCoffee->removeItem(index);
            }

            else
            {
                if(ui->instantCoffee->itemData(index).toInt()==0)
                {
                    ui->instantCoffee->setItemText(index,"not used");

                }
                index++;
            }
        }
    }
    else
    {

    }


}

void WBSDGeneralWindow::updateLeftBIB(unsigned int conf)
{
    int noItems = ui->leftBIB->count();
    int index;
    int index_f =99; //rj debug remove!

    for (index=0; index<noItems; index++){
        int itemVal = ui->leftBIB->itemData(index).toInt();
        if ((conf )==itemVal) {
            ui->leftBIB->setCurrentIndex(index);
            index_f = index;
            _lastlftIndex = index;
            break;
        }
    }
}

void WBSDGeneralWindow::updateRightBIB(unsigned int conf)
{
    int noItems = ui->rightBIB->count();
    int index;
    int index_f =99; //rj debug remove!

    for (index=0; index<noItems; index++){
        int itemVal = ui->rightBIB->itemData(index).toInt();
        if ((conf )==itemVal) {
            ui->rightBIB->setCurrentIndex(index);
            index_f = index;
            _lastrgtIndex =index;
            break;
        }
    }
}

void WBSDGeneralWindow::updateInstantCoffee(unsigned int conf)
{
    int noItems = ui->instantCoffee->count();
    int index;
    int index_f =99; //rj debug remove!
    if(ui->cb_fmuswitch->currentIndex()!=1)
    {
        ui->cbenablepay->setEnabled(true);
        if(ui->cbenablepay->currentIndex()!=0)
        {
            ui->cb_payDispenMode->setEnabled(true);
            ui->label_21->setEnabled(true);
        }
    }
    for (index=0; index<noItems; index++){
        int itemVal = ui->instantCoffee->itemData(index).toInt();
        if ((conf )==itemVal) {
            ui->instantCoffee->setCurrentIndex(index);
            index_f = index;
            _lastInstantIndex = index;
            break;
        }
    }
	switch (conf) {
	case 0: //oe_empty
        //ui->instantCoffee->setCurrentText();
	case 6:  //oe_instant_milk:
	case 7:  //oe_tea:
	case 8:  //oe_instant_choco:
	case 9:  // oe_sugar:
	case 10: // oe_coffee:
    case 11: //oe_decaf:
	case 13: //oe_water_tank:
			updatePaymentOpt(0);
            ui->paymentOpt->setEnabled(false);
			ui->label_6->setEnabled(false);
			break;
	case 14: // oe_CF330: 
	case 15: // oe_NRIG13: 
			updatePaymentOpt(1);
			ui->paymentOpt->setEnabled(true);
            ui->cb_payDispenMode->setEnabled(false);
            ui->label_6->setEnabled(true);
            ui->cbenablepay->setEnabled(false);
            ui->cbenablepay->activated(0);
            ui->label_21->setEnabled(false);
			break;
	}


    QString qss=QString("RJDEBUG WBSDGeneralWindow::updateInstantCoffee value = %1, index found %2 (99=not found)").arg(conf).arg(index_f);
    qDebug () << qss;
}

void WBSDGeneralWindow::updatePaymentOpt(unsigned int conf)
{
   //String qs=QString("RJDEBUG WBSDGeneralWindow::updatePaymentOpt conf %1").arg(conf);
   //Debug () << qs;

    int noItems = ui->paymentOpt->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->paymentOpt->itemData(index).toInt();
        if (conf==itemVal) {
            ui->paymentOpt->setCurrentIndex(index);
            break;
        }
    }
   //String qss=QString("RJDEBUG WBSDGeneralWindow::updatePaymentOpt index %1").arg(index);
   //Debug () << qss;
}

void WBSDGeneralWindow::updateSwitchOver(unsigned int conf)
{
  //QString qs=QString("RJDEBUG WBSDGeneralWindow::updateSwitchOver conf %1").arg(conf);
  //qDebug () << qs;


    if (conf==1 && ui->leftBIB->itemData(ui->leftBIB->currentIndex()).toInt()!=ui->rightBIB->itemData(ui->rightBIB->currentIndex()).toInt())
    {
        this->ui->switchOver->setCurrentIndex(0);
        conf=0;
        setBodyDP0Parameter(0, 4);
    }


    int noItems = ui->switchOver->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->switchOver->itemData(index).toInt();
        if (conf==itemVal) {
            ui->switchOver->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDGeneralWindow::updateSwitchOver index %1").arg(index);
    qDebug () << qss;
}

void WBSDGeneralWindow::updateInstantFan(unsigned int conf)
{
    QString qs=QString("RJDEBUG WBSDGeneralWindow::updateInstantFan conf %1").arg(conf);
    qDebug () << qs;

    int noItems = ui->instantFan->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->instantFan->itemData(index).toInt();
        if (conf==itemVal) {
            ui->instantFan->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDGeneralWindow::updateInstantFan index %1").arg(index);
    qDebug () << qss;
}

void WBSDGeneralWindow::updateDeairTimer(unsigned int conf)
{
    //QString qs=QString("RJDEBUG WBSDGeneralWindow::updateDeairTimer conf %1").arg(conf);
    //qDebug () << qs;

    int noItems = ui->deairTimer->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->deairTimer->itemData(index).toInt();
        if (conf==itemVal) {
            ui->deairTimer->setCurrentIndex(index);
            break;
        }
    }
    //QString qss=QString("RJDEBUG WBSDGeneralWindow::updateDeairTimer index %1").arg(index);
    //qDebug () << qss;
}

void WBSDGeneralWindow::updatepayenable(unsigned int conf)
{
    int noItems = ui->cbenablepay->count();
        int index;

        for (index=0; index<noItems; index++){
            int itemVal = ui->cbenablepay->itemData(index).toInt();
            if (conf==itemVal) {
                if(itemVal == 0)
                {
                    //off
                    ui->cb_payDispenMode->setEnabled(false);
                    ui->label_21->setEnabled(false);
                }
                ui->cbenablepay->setCurrentIndex(index);
                break;
            }
        }
}

void WBSDGeneralWindow::updatedispenMode(unsigned int conf)
{
    int noItems = ui->cb_payDispenMode->count();
        int index;

        for (index=0; index<noItems; index++){
            int itemVal = ui->cb_payDispenMode->itemData(index).toInt();
            if (conf==itemVal) {

                ui->cb_payDispenMode->setCurrentIndex(index);
                break;
            }
        }
}

void WBSDGeneralWindow::updatefmuswitch(unsigned int conf)
{
    int noItems = ui->cb_fmuswitch->count();
        int index;
        for (index=0; index<noItems; index++){
            int itemVal = ui->cb_fmuswitch->itemData(index).toInt();
            if (conf==itemVal) {
                ui->cb_fmuswitch->setCurrentIndex(index);
                _lastfmuindex = index;
                if(itemVal == 0)
                {
                    ui->btn_fmu->setEnabled(false);
                }else
                {
                    ui->cbenablepay->activated(0);
                    ui->cbenablepay->setEnabled(false);
                }
                break;
            }
        }
}


QString WBSDGeneralWindow::CheckButtonIsOk(QList<int> a)
{
    QString ret ="";
    if (!a.contains(RcpID_Btn1) && RcpID_Btn1!=0)
    {
        ret +=" Button1 ";
    }
    if (!a.contains(RcpID_Btn2) && RcpID_Btn2!=0)
    {
        ret +=" Button2 ";
    }
    if (!a.contains(RcpID_Btn3) && RcpID_Btn3!=0)
    {
        ret +=" Button3 ";
    }
    if (!a.contains(RcpID_Btn4) && RcpID_Btn4!=0)
    {
        ret +=" Button4 ";
    }
    if (!a.contains(RcpID_Btn5) && RcpID_Btn5!=0)
    {
        ret +=" Button5 ";
    }
    if (!a.contains(RcpID_Btn6) && RcpID_Btn6!=0)
    {
        ret +=" Button6 ";
    }
    if(ret!="") ret=QObject::tr("This new configuration results in invalid recipes for button:")+ret;
    return ret;
}

void WBSDGeneralWindow::updatePhoneOperator(unsigned int digits, unsigned int block)
{
    QString numberBlock;
    const unsigned int DIGITS_PER_BLOCK = 4;
    const unsigned int NUMBER_SIZE = 4; //Bit size per digit
    unsigned int digit = 0;
    unsigned int shift = 12;
    static BOOL eol_new_block = DFALSE; // True if eol is reached in a new block

    if (block == 1) //Beginning of new phone number
        eol_new_block = DFALSE;

    if(!eol_new_block)
    {
        for(int i = 0; i < DIGITS_PER_BLOCK; i++) {
            if (block == 4 && shift == 0)   //Last block only 3 digits
                break;
            digit = 0xF & (digits >> shift);
            shift -= NUMBER_SIZE;
            switch (digit) {
                case 0x0:
                    //qDebug () << "0";
                    numberBlock.append('0');
                    break;
                case 0x1:
                    //qDebug () << "1";
                    numberBlock.append('1');
                    break;
                case 0x2:
                    //qDebug () << "2";
                    numberBlock.append('2');
                    break;
                case 0x3:
                    //qDebug () << "3";
                    numberBlock.append('3');
                    break;
                case 0x4:
                    //qDebug () << "4";
                    numberBlock.append('4');
                    break;
                case 0x5:
                    //qDebug () << "5";
                    numberBlock.append('5');
                    break;
                case 0x6:
                    //qDebug () << "6";
                    numberBlock.append('6');
                    break;
                case 0x7:
                    //qDebug () << "7";
                    numberBlock.append('7');
                    break;
                case 0x8:
                    //qDebug () << "8";
                    numberBlock.append('8');
                    break;
                case 0x9:
                    //qDebug () << "9";
                    numberBlock.append('9');
                    break;
                case 0xA:
                    //qDebug () << "(";
                    numberBlock.append('(');
                    break;
                case 0xB:
                    //qDebug () << ")";
                    numberBlock.append(')');
                    break;
                case 0xC:
                    //qDebug () << "-";
                    numberBlock.append('-');
                    break;
                case 0xD:
                    //qDebug () << "+";
                    numberBlock.append('+');
                    break;
                case 0xE:
                    //qDebug () << " ";
                    numberBlock.append(' ');
                    break;
                case 0xF:
                    //qDebug () << "EOL";
                    i = DIGITS_PER_BLOCK; //EOL, terminate string
                    eol_new_block = DTRUE;
                    break;
                default: //Space if any strange value
                    //qDebug () << "default (space)";
                    numberBlock.append(' ');
            }
        }
    }

    if (block == 1) {
        operatorNumber.clear(); //Clear number if block 1 (start of a new number)
        operatorNumber.append(numberBlock);
        ui->phoneOper->setText(operatorNumber);
    }
    else {
        operatorNumber.append(numberBlock);
        ui->phoneOper->setText(operatorNumber);
    }
}

void WBSDGeneralWindow::updatePhoneService(unsigned int digits, unsigned int block)
{
    QString numberBlock;
    const unsigned int DIGITS_PER_BLOCK = 4;
    const unsigned int NUMBER_SIZE = 4; //Bit size per digit
    unsigned int digit = 0;
    unsigned int shift = 12;

    static BOOL eol_new_block = DFALSE; // True if eol is reached in a new block

    if (block == 5) //Beginning of new phone number
        eol_new_block = DFALSE;

    if(!eol_new_block)
    {
        for(int i = 0; i < DIGITS_PER_BLOCK; i++) {
            if (block == 8 && shift == 0)   //Last block only 3 digits
                break;
            digit = 0xF & (digits >> shift);
            shift -= NUMBER_SIZE;
            switch (digit) {
                case 0x0:
                    //qDebug () << "0";
                    numberBlock.append('0');
                    break;
                case 0x1:
                    //qDebug () << "1";
                    numberBlock.append('1');
                    break;
                case 0x2:
                    //qDebug () << "2";
                    numberBlock.append('2');
                    break;
                case 0x3:
                    //qDebug () << "3";
                    numberBlock.append('3');
                    break;
                case 0x4:
                    //qDebug () << "4";
                    numberBlock.append('4');
                    break;
                case 0x5:
                    //qDebug () << "5";
                    numberBlock.append('5');
                    break;
                case 0x6:
                    //qDebug () << "6";
                    numberBlock.append('6');
                    break;
                case 0x7:
                    //qDebug () << "7";
                    numberBlock.append('7');
                    break;
                case 0x8:
                    //qDebug () << "8";
                    numberBlock.append('8');
                    break;
                case 0x9:
                    //qDebug () << "9";
                    numberBlock.append('9');
                    break;
                case 0xA:
                    //qDebug () << "(";
                    numberBlock.append('(');
                    break;
                case 0xB:
                    //qDebug () << ")";
                    numberBlock.append(')');
                    break;
                case 0xC:
                    //qDebug () << "-";
                    numberBlock.append('-');
                    break;
                case 0xD:
                    //qDebug () << "+";
                    numberBlock.append('+');
                    break;
                case 0xE:
                    //qDebug () << " ";
                    numberBlock.append(' ');
                    break;
                case 0xF:
                    //qDebug () << "EOL";
                    i = DIGITS_PER_BLOCK; //EOL, terminate string
                    eol_new_block = DTRUE;
                    break;
                default: //Space if any strange value
                    //qDebug () << "default (space)";
                    numberBlock.append(' ');
            }
        }
    }

    if (block == 5) {
        serviceNumber.clear(); //Clear number if block 5 (start of a new number)
        serviceNumber.append(numberBlock);
        ui->phoneServ->setText(serviceNumber);
    }
    else {
        serviceNumber.append(numberBlock);
        ui->phoneServ->setText(serviceNumber);
    }
}
/*modify by lee
*/
void WBSDGeneralWindow::on_leftBIB_activated(int index)
{
    int valLeftBIB = ui->leftBIB->itemData(index).toInt();
    int valRightBIB = ui->rightBIB->itemData(ui->rightBIB->currentIndex()).toInt();
    int valInstantCoffee = ui->instantCoffee->itemData(ui->instantCoffee->currentIndex()).toInt();
    int fmu_on = ui->cb_fmuswitch->itemData(ui->cb_fmuswitch->currentIndex()).toInt();
    int value = (valLeftBIB << 12) | (valRightBIB << 8) | (valInstantCoffee << 4);

    if(valRightBIB == 1 && (valLeftBIB!=2 && valLeftBIB!=1))
    {
        /*
         *need to change the show msg
         *
         */
        QMessageBox::warning(this,QObject::tr("Setting Not Allowed"),QObject::tr("if you want to change this BIB setting \n please first change the right bib setting!"),QMessageBox::Ok);
        ui->leftBIB->setCurrentIndex(_lastlftIndex);
        return;
    }
    if(valLeftBIB ==2 && valRightBIB!=2)
    {
        /*decaf - decaf is ok, other is not allowed
         * 2015-03-18 to do
        need to show info about "decaf-xxx is not allowed"
        */


      QMessageBox::StandardButton reply1 = QMessageBox::question(this,QObject::tr("Setting Not Allowed"),"decaf-"+GetBibType(valRightBIB)+QObject::tr(" is not allowed,change to Decaf-Decaf ?"),QMessageBox::Ok|QMessageBox::Cancel);
      if(reply1 == QMessageBox::Ok)
      {
          ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
          query.setNibble(2,2);
          itsBaseWindow->addMessageToQue(query);
      }
        else
      {
          qDebug()<<"_lastlftIndex"<<_lastlftIndex;
          ui->leftBIB->setCurrentIndex(_lastlftIndex);
          return;
      }
    }
    //判断是否需要设置cleanmode
    if((valLeftBIB == 3 || valLeftBIB==5) && _crtCleanMode!=2)
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,QObject::tr("Confirm this Setting"),QObject::tr("this Setting will change the CleaningMode,Are you Sure?"),QMessageBox::Ok|QMessageBox::Cancel);
        if(reply == QMessageBox::Ok)
        {
            ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
            query.setNibble(3,valLeftBIB );
            itsBaseWindow->addMessageToQue(query);
        ParameterMsg msg12(Message::MCB,Message::DP,27,Message::SET_PARAMETER);
        msg12.setNibble(1,2);
        itsBaseWindow->addMessageToQue(msg12);

        _lastlftIndex = ui->leftBIB->currentIndex();
        _crtCleanMode =2;
        }else
        {
            ui->leftBIB->setCurrentIndex(_lastlftIndex);
        }
    }
    else
    {
        ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
        query.setNibble(3,valLeftBIB );
        //query.setWord(value);
        itsBaseWindow->addMessageToQue(query);
    }


    if((valLeftBIB != 1 || valRightBIB != 1) && this->ui->switchOver->currentIndex()!=0)
    {
        this->ui->switchOver->setCurrentIndex(0);
        int value = ui->switchOver->itemData(0).toInt();
        setBodyDP0Parameter(value, 4);
    }
    //获取当前所有可用菜单,判断按钮配置是否还可有
    QList<int> crtrcplst = DataBaseHelper::getInstance()->GetCurrentValidRcp("100",valLeftBIB,valRightBIB,valInstantCoffee,fmu_on);
    qDebug()<<"crtrcplst"<<crtrcplst;
    QString ret =CheckButtonIsOk(crtrcplst);
    if(ret!="") QMessageBox::warning(this,QObject::tr("Drink Button Warning"),ret,QMessageBox::Ok);

    _lastlftIndex = ui->leftBIB->currentIndex();
    qDebug()<<"Set _lastlftIndex ="<<_lastlftIndex;
}

void WBSDGeneralWindow::on_rightBIB_activated(int index)
{
    int lastValrightBib = ui->rightBIB->itemData(_lastrgtIndex).toInt();
    int valRightBIB = ui->rightBIB->itemData(index).toInt();

    int fmu_on = ui->cb_fmuswitch->itemData(ui->cb_fmuswitch->currentIndex()).toInt();
    int valLeftBIB = ui->leftBIB->itemData(ui->leftBIB->currentIndex()).toInt();
    int valInstantCoffee = ui->instantCoffee->itemData(ui->instantCoffee->currentIndex()).toInt();
    int value = (valLeftBIB << 12) | (valRightBIB << 8) | (valInstantCoffee << 4);
    QString qss=QString("RJDEBUG on_rightBIB_activated value %1").arg(valRightBIB);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_rightBIB_activated value total %1").arg(value);
    qDebug () << qsss;
    if(valLeftBIB == 2 && (valRightBIB!=2 && valRightBIB!=1))
    {
        QMessageBox::warning(this,QObject::tr("Setting Not Allowed"),QObject::tr("if you want to change this BIB setting \n please first change the left bib setting!"),QMessageBox::Ok);
        ui->rightBIB->setCurrentIndex(_lastrgtIndex);
        return;
    }
    if(lastValrightBib!=3 && lastValrightBib!=5)
    {
        if(valRightBIB ==3 || valRightBIB==5)
        {
            /*When changing from NO MILK to MILK: Change to default days (MO/THU) ON and blocking
            */
            QMessageBox::StandardButton reply = QMessageBox::question(this,QObject::tr("Confirm this Setting"),QObject::tr("This setting will cause Cleaning day setting Change to default days (MO/THU) ON and blocking!Are you Sure?"),QMessageBox::Ok|QMessageBox::Cancel);
            if(reply == QMessageBox::Ok)
            {
            ParameterMsg message(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
            message.setBit(15,1);
            itsBaseWindow->addMessageToQue(message);
            ParameterMsg message1(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
            message1.setBit(12,1);
            itsBaseWindow->addMessageToQue(message1);

            ParameterMsg message2(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
            message2.setBit(9,0);
            itsBaseWindow->addMessageToQue(message2);
            ParameterMsg message3(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
            message3.setBit(10,0);
            itsBaseWindow->addMessageToQue(message3);
            ParameterMsg message4(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
            message4.setBit(11,0);
            itsBaseWindow->addMessageToQue(message4);
            ParameterMsg message5(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
            message5.setBit(13,0);
            itsBaseWindow->addMessageToQue(message5);
            ParameterMsg message6(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
            message6.setBit(14,0);
            itsBaseWindow->addMessageToQue(message6);

            ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
            query.setNibble(2,valRightBIB);
            itsBaseWindow->addMessageToQue(query);
            ParameterMsg msg12(Message::MCB,Message::DP,27,Message::SET_PARAMETER);
            msg12.setNibble(1,2);
            itsBaseWindow->addMessageToQue(msg12);
            _crtCleanMode =2;
            _lastrgtIndex = ui->rightBIB->currentIndex();
            }
            else
            {
             ui->rightBIB->setCurrentIndex(_lastrgtIndex);
             return;
            }
        }
    }
    if(valRightBIB==1 && valLeftBIB !=1 )
    {
        /*Coffee - coffee is ok, other is not allowed
         * 2015-03-18 to do
           need to show info about "XXX-coffee is not allowed"
        */
        QMessageBox::StandardButton reply1 = QMessageBox::question(this,QObject::tr("Setting Not Allowed"),GetBibType(valLeftBIB)+QObject::tr("-coffee is not allowed,change to coffee-coffee ?"),QMessageBox::Ok|QMessageBox::Cancel);
        if(reply1 == QMessageBox::Ok)
        {
            ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
            query.setNibble(3,1);
            itsBaseWindow->addMessageToQue(query);
        }
        else
        {
            ui->rightBIB->setCurrentIndex(_lastrgtIndex);
            return;
        }

    }
/*to-do-modify
 * When changing from NO MILK to MILK: Change to default days (MO/THU) ON and blocking
 * When changing to NO MILK: Leave like it is
 */

        ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
        query.setNibble(2,valRightBIB);
        itsBaseWindow->addMessageToQue(query);



    if((valLeftBIB != 1 || valRightBIB != 1) && this->ui->switchOver->currentIndex()!=0)
    {
        this->ui->switchOver->setCurrentIndex(0);
        int value = ui->switchOver->itemData(0).toInt();
        setBodyDP0Parameter(value, 4);
    }

    //获取当前所有可用菜单,判断按钮配置是否还可有
    QList<int> crtrcplst = DataBaseHelper::getInstance()->GetCurrentValidRcp("100",valLeftBIB,valRightBIB,valInstantCoffee,fmu_on);
    qDebug()<<"crtrcplst"<<crtrcplst;
    QString ret =CheckButtonIsOk(crtrcplst);
    if(ret!="") QMessageBox::warning(this,QObject::tr("Drink Button Warning"),ret,QMessageBox::Ok);
    _lastrgtIndex = ui->rightBIB->currentIndex();
}

void WBSDGeneralWindow::on_instantCoffee_activated(int index)
{
    int valInstantCoffee = ui->instantCoffee->itemData(index).toInt();
    int valLeftBIB = ui->leftBIB->itemData(ui->leftBIB->currentIndex()).toInt();
    int valRightBIB = ui->rightBIB->itemData(ui->rightBIB->currentIndex()).toInt();
    int value = (valLeftBIB << 12) | (valRightBIB << 8) | (valInstantCoffee << 4);
    QString qss=QString("RJDEBUG on_instantCoffee_activated value %1").arg(valInstantCoffee);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_instantCoffee_activated value total %1").arg(value);
    qDebug () << qsss;
    int fmu_on = ui->cb_fmuswitch->itemData(ui->cb_fmuswitch->currentIndex()).toInt();
    //获取当前所有可用菜单,判断按钮配置是否还可有
    QList<int> crtrcplst = DataBaseHelper::getInstance()->GetCurrentValidRcp("100",valLeftBIB,valRightBIB,valInstantCoffee,fmu_on);
    qDebug()<<"crtrcplst"<<crtrcplst;
    QString ret =CheckButtonIsOk(crtrcplst);
    if(ret!="") QMessageBox::warning(this,QObject::tr("Drink Button Warning"),ret,QMessageBox::Ok);

    ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
    query.setNibble(1,valInstantCoffee);
    itsBaseWindow->addMessageToQue(query);

	ParameterMsg msgCONCENTRATE_OE(Message::MCB,Message::DP, 27, Message::SET_PARAMETER); //BIT12
	ParameterMsg msgMIXER_OE(Message::MCB,Message::DP, 27, Message::SET_PARAMETER); //BIT13
	ParameterMsg msgINST_WTR_VALVE_OE(Message::MCB,Message::DP, 26, Message::SET_PARAMETER); //BIT2
	ParameterMsg msgINST_FAN_OE(Message::MCB,Message::DP, 26, Message::SET_PARAMETER);  //BIT3
	ParameterMsg msgINLET_VALVE_OE(Message::MCB,Message::DP, 27, Message::SET_PARAMETER);  //BIT15
	ParameterMsg msgPay_E(Message::MCB,Message::DP, 0, Message::SET_PARAMETER);  //BIT9
	ParameterMsg msgPay_View(Message::UIB,Message::DP, 8, Message::SET_PARAMETER);  //BIT1

    if(ui->cb_fmuswitch->currentIndex()!=1)
        ui->cbenablepay->setEnabled(true);

	switch (valInstantCoffee) {
	case 0: //oe_empty
			msgCONCENTRATE_OE.setBit(12,0);
			msgMIXER_OE.setBit(13,0);
			msgINST_WTR_VALVE_OE.setBit(2,0);
			msgINST_FAN_OE.setBit(3,0);
			msgINLET_VALVE_OE.setBit(15,1);
			msgPay_E.setBit(9,0);
			msgPay_View.setBit(1,0);
			updatePaymentOpt(0);
			ui->label_6->setEnabled(false);
			ui->paymentOpt->setEnabled(false);
            ui->btn_instant->setEnabled(false);
        break;
	case 6:  //oe_instant_milk:
	case 7:  //oe_tea:
	case 8:  //oe_instant_choco:
	case 9:  // oe_sugar:
	case 10: // oe_coffee:
	case 11: //oe_decaf:
            if(index!= _lastInstantIndex)
            {
                QMessageBox::warning(this,QObject::tr("Instant Changed"),QObject::tr("Instant Conf Changed,Calibration must be done !"),QMessageBox::Ok);
            }
			msgCONCENTRATE_OE.setBit(12,1);
			msgMIXER_OE.setBit(13,1);
			msgINST_WTR_VALVE_OE.setBit(2,1);
			msgINST_FAN_OE.setBit(3,1);
			msgINLET_VALVE_OE.setBit(15,1);
			msgPay_E.setBit(9,0);
			msgPay_View.setBit(1,0);
			updatePaymentOpt(0);
			ui->label_6->setEnabled(false);
			ui->paymentOpt->setEnabled(false);
            ui->btn_instant->setEnabled(true);
			break;
	case 13: //oe_water_tank:
			msgCONCENTRATE_OE.setBit(12,0);
			msgMIXER_OE.setBit(13,0);
			msgINST_WTR_VALVE_OE.setBit(2,0);
			msgINST_FAN_OE.setBit(3,0);
			msgINLET_VALVE_OE.setBit(15,0);
			msgPay_E.setBit(9,0);
			msgPay_View.setBit(1,0);
			updatePaymentOpt(0);
			ui->paymentOpt->setEnabled(false);
			ui->label_6->setEnabled(false);
            ui->btn_instant->setEnabled(false);
			break;
	case 14: // oe_CF330: 
	case 15: // oe_NRIG13: 
			msgCONCENTRATE_OE.setBit(12,0);
			msgMIXER_OE.setBit(13,0);
			msgINST_WTR_VALVE_OE.setBit(2,0);
			msgINST_FAN_OE.setBit(3,0);
			msgINLET_VALVE_OE.setBit(15,1);
			msgPay_E.setBit(9,1);
			msgPay_View.setBit(1,1);
			updatePaymentOpt(1);
			ui->paymentOpt->setEnabled(true);
			ui->label_6->setEnabled(true);
            ui->btn_instant->setEnabled(false);
            ui->cbenablepay->setEnabled(false);
            ui->cbenablepay->activated(0);
			break;
	}

	itsBaseWindow->addMessageToQue(msgCONCENTRATE_OE);
	itsBaseWindow->addMessageToQue(msgMIXER_OE);
	itsBaseWindow->addMessageToQue(msgINST_WTR_VALVE_OE);
	itsBaseWindow->addMessageToQue(msgINST_FAN_OE);
	itsBaseWindow->addMessageToQue(msgINLET_VALVE_OE);
	itsBaseWindow->addMessageToQue(msgPay_E);
	itsBaseWindow->addMessageToQue(msgPay_View);
}

void WBSDGeneralWindow::on_paymentOpt_activated(int index)
{
    int value = ui->paymentOpt->itemData(index).toInt();
    int instantIndex = ui->instantCoffee->currentIndex();
    int valInstantCoffee = ui->instantCoffee->itemData(instantIndex).toInt();

    if(valInstantCoffee == valueCF330 || valInstantCoffee == valueNRIG130) //Payment is mandatory
    {
        value = 1;
        ui->paymentOpt->setCurrentIndex(value);

    }
    else
    {
        setBodyDP0Parameter(value, 9);

    }

    QString qss=QString("RJDEBUG on_paymentOpt_activated value %1").arg(value);
    qDebug () << qss;
}

void WBSDGeneralWindow::on_switchOver_activated(int index)
{
    if (ui->leftBIB->itemData(ui->leftBIB->currentIndex()).toInt()!=ui->rightBIB->itemData(ui->rightBIB->currentIndex()).toInt())
    {
		this->ui->switchOver->setCurrentIndex(0);
		index=0;
	}
	int value = ui->switchOver->itemData(index).toInt();
    setBodyDP0Parameter(value, 4);

    QString qss=QString("RJDEBUG on_switchOver_activated value %1").arg(value);
    qDebug () << qss;
}

void WBSDGeneralWindow::on_cbenablepay_activated(int index)
{
    int value = (ui->cbenablepay->itemData(index).toInt() == 0? 0:1);
    int dat = ui->cbenablepay->itemData(index).toInt() ;
    ParameterMsg message(Message::UIB,Message::DP, 23, Message::SET_PARAMETER);
    message.setBit(7,value);
    itsBaseWindow->addMessageToQue(message);
    if(value!=0)
    {
        ParameterMsg message1(Message::MAB,Message::DP, 0, Message::SET_PARAMETER);
        message1.setNibble(1,dat-1);
        itsBaseWindow->addMessageToQue(message1);
        ui->cb_payDispenMode->setEnabled(true);
        ui->label_21->setEnabled(true);
    }
}

void WBSDGeneralWindow::on_cb_payDispenMode_activated(int index)
{
    int value = ui->cb_payDispenMode->itemData(index).toInt();
    ParameterMsg message(Message::UIB,Message::DP, 23, Message::SET_PARAMETER);
    message.setBit(8,value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDGeneralWindow::on_instantFan_activated(int index)
{
    int value = ui->instantFan->itemData(index).toInt();
    setBodyDP25Parameter(value, 4, 8);

    qDebug() << "RJDEBUG on_instantFan_activated value =" << value;
}

void WBSDGeneralWindow::on_deairTimer_activated(int index)
{
    int value = ui->instantFan->itemData(index).toInt();
    setBodyDP25Parameter(value, 4, 12);

    qDebug() << "RJDEBUG on_instantFan_activated value =" << value;
}

void WBSDGeneralWindow::on_btn_instant_clicked()
{
    if (instantWindow==0)
        instantWindow = new WBSDInstantWindow(itsBaseWindow);
    instantWindow->setAttribute(Qt::WA_DeleteOnClose,true);
    instantWindow->show();
    this->hide();
    connect(instantWindow,SIGNAL(iclose()),this,SLOT(show()));
    connect(instantWindow,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void WBSDGeneralWindow::on_btn_fmu_clicked()
{
    if (fmu_settingwin==0)
        fmu_settingwin = new FMU_SETTING(itsBaseWindow);
    fmu_settingwin->setAttribute(Qt::WA_DeleteOnClose,true);
    fmu_settingwin->show();
    this->hide();
    connect(fmu_settingwin,SIGNAL(iclose()),this,SLOT(show()));
    connect(fmu_settingwin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void WBSDGeneralWindow::on_cb_fmuswitch_activated(int index)
{
    int valLeftBIB = ui->leftBIB->itemData(ui->leftBIB->currentIndex()).toInt();
    int valRightBIB = ui->rightBIB->itemData(ui->rightBIB->currentIndex()).toInt();
    int valInstantCoffee = ui->instantCoffee->itemData(ui->instantCoffee->currentIndex()).toInt();
    int fmu_on = ui->cb_fmuswitch->itemData(index).toInt();
    //modify by lee set the fmu part enable or disable
    if(ui->cb_fmuswitch->itemData(index).toInt()== 0)
    {
        ui->btn_fmu->setEnabled(false);
        int instantcof= ui->instantCoffee->itemData(ui->instantCoffee->currentIndex()).toInt();
        if(instantcof!=14 && instantcof!=15)
        {
            ui->cbenablepay->setEnabled(true);
            ui->switchOver->setEnabled(true);
        }
        ParameterMsg query(Message::MCB,Message::DP, 26, Message::SET_PARAMETER);
        query.setBit(6,ui->cb_fmuswitch->itemData(index).toInt());
        itsBaseWindow->addMessageToQue(query);
    }else
    {
        ParameterMsg query(Message::MCB,Message::DP, 26, Message::SET_PARAMETER);
        query.setBit(6,ui->cb_fmuswitch->itemData(index).toInt());
        itsBaseWindow->addMessageToQue(query);
        ui->btn_fmu->setEnabled(true);
        ui->cbenablepay->activated(0);
        ui->cbenablepay->setEnabled(false);
        if(_crtCleanMode!=2)
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this,QObject::tr("Confirm this Setting"),QObject::tr("This setting will cause Cleaning day setting Change to default days (MO/THU) ON and blocking!Are you Sure?"),QMessageBox::Ok|QMessageBox::Cancel);
            if(reply == QMessageBox::Ok)
            {
                ParameterMsg query(Message::MCB,Message::DP, 26, Message::SET_PARAMETER);
                query.setBit(6,1);
                itsBaseWindow->addMessageToQue(query);
                ParameterMsg msg12(Message::MCB,Message::DP,27,Message::SET_PARAMETER);
                msg12.setNibble(1,2);
                itsBaseWindow->addMessageToQue(msg12);
                ParameterMsg message(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
                message.setBit(15,1);
                itsBaseWindow->addMessageToQue(message);
                ParameterMsg message1(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
                message1.setBit(12,1);
                itsBaseWindow->addMessageToQue(message1);

                ParameterMsg message2(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
                message2.setBit(9,0);
                itsBaseWindow->addMessageToQue(message2);
                ParameterMsg message3(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
                message3.setBit(10,0);
                itsBaseWindow->addMessageToQue(message3);
                ParameterMsg message4(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
                message4.setBit(11,0);
                itsBaseWindow->addMessageToQue(message4);
                ParameterMsg message5(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
                message5.setBit(13,0);
                itsBaseWindow->addMessageToQue(message5);
                ParameterMsg message6(Message::MCB,Message::DP, 1, Message::SET_PARAMETER);
                message6.setBit(14,0);
                itsBaseWindow->addMessageToQue(message6);
                _lastfmuindex = ui->cb_fmuswitch->currentIndex();
                _crtCleanMode =2;
              }

            else
            {
                ui->cb_fmuswitch->setCurrentIndex(_lastfmuindex);
            }
        }
    }
    QList<int> crtrcplst = DataBaseHelper::getInstance()->GetCurrentValidRcp("100",valLeftBIB,valRightBIB,valInstantCoffee,fmu_on);
    qDebug()<<"crtrcplst"<<crtrcplst;
    QString ret =CheckButtonIsOk(crtrcplst);
    if(ret!="") QMessageBox::warning(this,QObject::tr("Drink Button Warning"),ret,QMessageBox::Ok);

}


void WBSDGeneralWindow::test()
{
    int val = ui->sp_test->value();
    ParameterMsg query(Message::MCB,Message::DP, 2, Message::SET_PARAMETER);
    query.setWord(val);
    itsBaseWindow->addMessageToQue(query);
}

void WBSDGeneralWindow::destroywin()
{
    instantWindow =0;
    fmu_settingwin=0;
}

void WBSDGeneralWindow::on_phoneOper_editingFinished()
{
    QString phoneNr = ui->phoneOper->text();
    int bit = 12;
    unsigned int block = 1; //Start DP block 1
    unsigned int data = 0;
    const unsigned int NUMBER_SIZE = 4;
    unsigned int value;
    int len = phoneNr.length();

    for(int i = 0; i < MAXLEN_PHONE; i++) { //for(int i = 0; ((len>i) && (i < MAXLEN_PHONE)); i++) {
        if (i >= len)
        {
            qDebug () << "insert EOL";
            data = data | (0xF << bit); //Add EOL in phone string

        }
        else
        {
            switch ((char)phoneNr.at(i).toLatin1()) {
					case '0':
						qDebug () << "0";
						value = 0x0;
						break;
					case '1':
						qDebug () << "1";
						value = 0x1;
						break;
					case '2':
						qDebug () << "2";
						value = 0x2;
						break;
					case '3':
						qDebug () << "3";
						value = 0x3;
						break;
					case '4':
						qDebug () << "4";
						value = 0x4;
						break;
					case '5':
						qDebug () << "5";
						value = 0x5;
						break;
					case '6':
						qDebug () << "6";
						value = 0x6;
						break;
					case '7':
						qDebug () << "7";
						value = 0x7;
						break;
					case '8':
						qDebug () << "8";
						value = 0x8;
						break;
					case '9':
						qDebug () << "9";
						value = 0x9;
						break;
					case '(':
						qDebug () << "(";
						value = 0xA;
						break;
					case ')':
						qDebug () << ")";
						value = 0xB;
						break;
					case '-':
						qDebug () << "-";
						value = 0xC;
						break;
					case '+':
						qDebug () << "+";
						value = 0xD;
						break;
					case ' ':
						qDebug () << "space";
						value = 0xE; //space
						break;
					default:
						qDebug () << "default space";
						value = 0xE; //default space
						break;
				}
				data = data | (value << bit); //Add value in string
        }
        bit -= NUMBER_SIZE;
        if (bit < 0 || (bit == 0 && block == 4)) { //Ready to send block message
            qDebug () << "send phone block" << printf("%x",data);
            ParameterMsg message(Message::UIB,Message::DP, block, Message::SET_PARAMETER);
            message.setWord(data);
            itsBaseWindow->addMessageToQue(message);
            bit = 12;
            data = 0;
            block += 1;
        }

    }
    qDebug() << "RJDEBUG on_phoneOper_editingFinished";
}

void WBSDGeneralWindow::on_phoneServ_editingFinished()
{
    QString phoneNr = ui->phoneServ->text();
    int bit = 12;
    unsigned int block = 5; //Start DP block 5
    unsigned int data = 0;
    const unsigned int NUMBER_SIZE = 4;
    unsigned int value;
    int len = phoneNr.length();

    for(int i = 0; i < MAXLEN_PHONE; i++) { //for(int i = 0; ((len>i) && (i < MAXLEN_PHONE)); i++) {
        if (i >= len)
        {
            qDebug () << "insert EOL";
            data = data | (0xF << bit); //Add EOL in phone string

        }
        else
        {
            switch ((char)phoneNr.at(i).toLatin1()) {
				case '0':
					qDebug () << "0";
					value = 0x0;
					break;
				case '1':
					qDebug () << "1";
					value = 0x1;
					break;
				case '2':
					qDebug () << "2";
					value = 0x2;
					break;
				case '3':
					qDebug () << "3";
					value = 0x3;
					break;
				case '4':
					qDebug () << "4";
					value = 0x4;
					break;
				case '5':
					qDebug () << "5";
					value = 0x5;
					break;
				case '6':
					qDebug () << "6";
					value = 0x6;
					break;
				case '7':
					qDebug () << "7";
					value = 0x7;
					break;
				case '8':
					qDebug () << "8";
					value = 0x8;
					break;
				case '9':
					qDebug () << "9";
					value = 0x9;
					break;
				case '(':
					qDebug () << "(";
					value = 0xA;
					break;
				case ')':
					qDebug () << ")";
					value = 0xB;
					break;
				case '-':
					qDebug () << "-";
					value = 0xC;
					break;
				case '+':
					qDebug () << "+";
					value = 0xD;
					break;
				case ' ':
					qDebug () << "space";
					value = 0xE; //space
					break;
				default:
					qDebug () << "default space";
					value = 0xE; //default space
					break;
			}
            data = data | (value << bit); //Add value in string
        }
        bit -= NUMBER_SIZE;
        if (bit < 0 || (bit == 0 && block == 8)) { //Ready to send block message
            qDebug () << "send phone block";
            ParameterMsg message(Message::UIB,Message::DP, block, Message::SET_PARAMETER);
            message.setWord(data);
            itsBaseWindow->addMessageToQue(message);
            bit = 12;
            data = 0;
            block += 1;
        }

    }

    qDebug() << "RJDEBUG on_phoneServ_editingFinished";
}

// Send Body Unit DP block 0 message. Need to add all bit data in block 0.
void WBSDGeneralWindow::setBodyDP0Parameter(int value, int bitPos)
{
    QString qs=QString("RJDEBUG WBSDGeneralWindow::setBodyDP0Parameter, value = %1, bit pos = %2").arg(value).arg(bitPos);
    qDebug () << qs;
    ParameterMsg message(Message::MCB,Message::DP, 0, Message::SET_PARAMETER);
    message.setBit(bitPos,value);
    itsBaseWindow->addMessageToQue(message);
}

// Send Door Unit DP block 25 message. Need to add all bit data in block 0.
void WBSDGeneralWindow::setBodyDP25Parameter(int value, int bitLen, int offset)
{
    QString qs=QString("RJDEBUG WBSDGeneralWindow::setDoorDP25Parameter, value = %1, offset = %2, bitLen=%3").arg(value).arg(offset).arg(bitLen);
    qDebug () << qs;

    ParameterMsg query(Message::MCB,Message::DP, 25, Message::SET_PARAMETER);
	switch (bitLen){
	case 1:
		query.setBit(offset,value);
		break;
	case 4:
		query.setNibble(offset/4,value);
		break;
	}
    itsBaseWindow->addMessageToQue(query);
}

void WBSDGeneralWindow::gotMessage(Message aMsg)
{
    QString txt;
        char aLevelState;
        unsigned int aVal;
        char aRfgState;
        int payValue, valLeftBIB, valRightBIB, valInstant;

        QByteArray data=aMsg.getData();
        QString hex=QString(data.toHex());

        Message::qtype atype=aMsg.getType();
        switch (atype){
            case (Message::REPLY_DB):
                switch ((unsigned char)aMsg.getBoard()){
                    case (Message::MAB):
                    if((unsigned char)aMsg.getDataBaseType() == Message::DP)
                    {
                        if(aMsg.getParameters().at(3) ==0)
                        {
                            qDebug() << "RJDEBUG WBSDGeneralWindow::gotMessage"<<data.toHex();
                            updatepayenable(aMsg.getDataUInt()+1);
                        }
                    }
                    break;
                    case (Message::MCB):
                        switch ((unsigned char)aMsg.getDataBaseType()){
                            case Message::DP:

                                switch(aMsg.getParameters().at(3)){
                                    case 6:
                                    RcpID_Btn1 = (aMsg.getDataUInt() & 0xFF00)>>8 ;
                                    RcpID_Btn2 = aMsg.getDataUInt() & 0x00FF;

                                    break;
                                    case 7:
                                    RcpID_Btn3 = (aMsg.getDataUInt() & 0xFF00)>>8 ;
                                    RcpID_Btn4 = aMsg.getDataUInt() & 0x00FF;
                                    break;
                                    case 8:
                                    RcpID_Btn5 = (aMsg.getDataUInt() & 0xFF00)>>8 ;
                                    RcpID_Btn6 = aMsg.getDataUInt() & 0x00FF;
                                    qDebug()<<RcpID_Btn1<<RcpID_Btn2<<RcpID_Btn3<<RcpID_Btn4<<RcpID_Btn5<<RcpID_Btn6;
                                        break;
                                    case (0):
                                        aVal=aMsg.getDataUInt();
                                        boardDp0BitField = aVal;
                                        payValue=(0x200 & boardDp0BitField) >> 9;
                                        updatePaymentOpt(payValue);
                                        updateSwitchOver((0x10 & boardDp0BitField) >> 4);
                                        break;
                                    case 2:
                                     aVal=aMsg.getDataUInt();
                                     if(aVal!=ui->sp_test->value())
                                     ui->sp_test->setValue(aVal);
                                    break;
                                    case (4):
                                        aVal=aMsg.getDataUInt();
                                        valLeftBIB=(0xF000 & aVal) >> 12;
                                        valRightBIB=(0x0F00 & aVal) >> 8;
                                        valInstant=(0x00F0 & aVal) >> 4;
                                        if(itsBaseWindow->getMachineUnit() == WBSDBaseWindow::UNIT_USA)
                                        {

                                            if(valLeftBIB!=2)
                                            {
                                                ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
                                                query.setNibble(3,2);
                                                itsBaseWindow->addMessageToQue(query);
                                            }
                                            if(valRightBIB!=1)
                                            {
                                                ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
                                                query.setNibble(2,1);
                                                itsBaseWindow->addMessageToQue(query);
                                            }
                                            if(valInstant == 13 || valInstant == 14 || valInstant == 15)
                                            {
                                                ParameterMsg query(Message::MCB,Message::DP, 4, Message::SET_PARAMETER);
                                                query.setNibble(1,0);
                                                itsBaseWindow->addMessageToQue(query);
                                            }
                                        }

                                            updateLeftBIB(valLeftBIB);
                                            updateRightBIB(valRightBIB);
                                            updateInstantCoffee(valInstant);
                                            if(valInstant==0 || valInstant == 13 || valInstant == 14 || valInstant == 15)
                                            {
                                                ui->btn_instant->setEnabled(false);
                                            }
                                            /*
                                             *modify by lee;
                                             *record the last instant conf
                                             *if the last instant conf changed
                                             *warning give "calibration should be done"
                                             */
                                            else
                                            {

                                            }
										qDebug() << valLeftBIB << " " << valRightBIB << " "<< valInstant ;
                                        break;
                                    case (25):
                                        aVal=aMsg.getDataUInt();
                                        boardDp25BitField=aVal;
                                        updateInstantFan((0x0F00 & boardDp25BitField) >> 8);
                                        updateDeairTimer((0xF000 & boardDp25BitField) >> 12);
                                        break;
                                    case (26):
                                        aVal=aMsg.getDataUInt();
                                        updatefmuswitch((aVal&0x40)>>6);
                                        break;
                                    case(27)://判断当前的cleanMode
                                        aVal=aMsg.getDataUInt();
                                        _crtCleanMode = (aVal>>4) &0x0F;
                                    break;
                                    default:
                                        break;
                                }
 
                        }
                        break;
                    case (Message::UIB):
                        switch ((unsigned char)aMsg.getDataBaseType()){
                            case Message::DP:
                                switch (aMsg.getParameters().at(3)){
                                    case (1):
                                        aVal=aMsg.getDataUInt();
                                        updatePhoneOperator(0xFFFF & aVal, 1);
                                        break;
                                    case (2):
                                        aVal=aMsg.getDataUInt();
                                        updatePhoneOperator(0xFFFF & aVal, 2);
                                        break;
                                    case (3):
                                        aVal=aMsg.getDataUInt();
                                        updatePhoneOperator(0xFFFF & aVal, 3);
                                        break;
                                    case (4):
                                        aVal=aMsg.getDataUInt();
                                        updatePhoneOperator(0xFFFF & aVal, 4);
                                        break;
                                    case (5):
                                        aVal=aMsg.getDataUInt();
                                        updatePhoneService(0xFFFF & aVal, 5);
                                        break;
                                    case (6):
                                        aVal=aMsg.getDataUInt();
                                        updatePhoneService(0xFFFF & aVal, 6);
                                        break;
                                    case (7):
                                        aVal=aMsg.getDataUInt();
                                        updatePhoneService(0xFFFF & aVal, 7);
                                        break;
                                    case (8):
                                        aVal=aMsg.getDataUInt();
                                        updatePhoneService(0xFFFF & aVal, 8);
                                        break;
                                    case (23):
                                        aVal=aMsg.getDataUInt();
                                        if(((0x80 &aVal)>>7) == 0)
                                        {
                                            updatepayenable((0x80 &aVal)>>7);
                                        }else
                                        {
                                            ParameterMsg msg12(Message::MAB,Message::DP,0);
                                            msg12.getNibble(1);
                                            itsBaseWindow->addMessageToQue(msg12);
                                        }

                                        updatedispenMode(((aVal >>8) &0x01));
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

void WBSDGeneralWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

//Update initial data
void WBSDGeneralWindow::updateData()
{
  //  qDebug() << "RJDEBUG WBSDGeneralWindow::updateData";
    ParameterMsg msg12(Message::MCB,Message::DP,27);
    msg12.getWord();
    itsBaseWindow->addMessageToQue(msg12);

    ParameterMsg msg14(Message::MCB,Message::DP,26);
    msg14.getWord();
    itsBaseWindow->addMessageToQue(msg14);

    ParameterMsg msg1(Message::MCB,Message::DP,0);
    ParameterMsg msg2(Message::MCB,Message::DP,4);
    ParameterMsg msg3(Message::UIB,Message::DP,1); //Operator number ->
    ParameterMsg msg4(Message::UIB,Message::DP,2);
    ParameterMsg msg5(Message::UIB,Message::DP,3);
    ParameterMsg msg6(Message::UIB,Message::DP,4);
    ParameterMsg msg7(Message::UIB,Message::DP,5); //Service number ->
    ParameterMsg msg8(Message::UIB,Message::DP,6);
    ParameterMsg msg9(Message::UIB,Message::DP,7);
    ParameterMsg msg10(Message::UIB,Message::DP,8);
    ParameterMsg msg11(Message::MCB,Message::DP,25); //fans
    ParameterMsg msg13(Message::UIB,Message::DP,23);
    msg2.getWord();
    msg1.getWord();

    msg3.getWord();
    msg4.getWord();
    msg5.getWord();
    msg6.getWord();
    msg7.getWord();
    msg8.getWord();
    msg9.getWord();
    msg10.getWord();
    msg11.getWord();
    msg13.getWord();
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg3);
    itsBaseWindow->addMessageToQue(msg4);
    itsBaseWindow->addMessageToQue(msg5);
    itsBaseWindow->addMessageToQue(msg6);
    itsBaseWindow->addMessageToQue(msg7);
    itsBaseWindow->addMessageToQue(msg8);
    itsBaseWindow->addMessageToQue(msg9);
    itsBaseWindow->addMessageToQue(msg10);
    itsBaseWindow->addMessageToQue(msg11);
    itsBaseWindow->addMessageToQue(msg13);

    ParameterMsg aaa(Message::MCB,Message::DP,2);
    aaa.getWord();
    itsBaseWindow->addMessageToQue(aaa);
    ParameterMsg aaa1(Message::MCB,Message::DP,6);
    aaa1.getWord();
    itsBaseWindow->addMessageToQue(aaa1);
    ParameterMsg aaa2(Message::MCB,Message::DP,7);
    aaa2.getWord();
    itsBaseWindow->addMessageToQue(aaa2);
    ParameterMsg aaa3(Message::MCB,Message::DP,8);
    aaa3.getWord();
    itsBaseWindow->addMessageToQue(aaa3);
}





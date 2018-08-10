#include "wbsdpaywindow.h"
#include "ui_wbsdpaywindow.h"
#include "qdebug.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "application.h"
#include "databasehelper.h"
#include "wbsdpaysetprice.h"
#include "wbsdpaysetcoinchannel.h"
#include "qmessagebox.h"
#include "qtimer.h"
#include "qmath.h"
WBSDPayWindow::WBSDPayWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDPayWindow)
{
    static const char* back[] = {
                QT_TRANSLATE_NOOP("back_pay", "Back")
            };
    ui->setupUi(this);
	setPrice=0;
	setCoinChannelDlg=0;
    //payWindow = new WBSDPayWindow;

    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
	menuBack->setEnabled(true);
    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

//#define DB_PAYMENT_ENABLE     &cu_dp[0],BIT09
//#define DB_MULTI_VEND         &cu_dp[0],BIT08

    //
    numberOfDecimals=2;

	DataBaseHelper::getInstance()->populateComboFromTabKat("035",ui->cboCurrency);
	DataBaseHelper::getInstance()->populateComboFromTabKat("033",ui->cboClearCreditTime);
	DataBaseHelper::getInstance()->populateComboFromTabKat("002",ui->cboRFIDMode);
	DataBaseHelper::getInstance()->populateComboFromTabKat("029",ui->cboSaleType);
	DataBaseHelper::getInstance()->populateComboFromTabKat("019",ui->cboPaymentEnabled);
	DataBaseHelper::getInstance()->populateComboFromTabKat("033",ui->cboRFIDTimeout);
	enable_pay(false,false);
	updateData();
    /*Lee.li Modify 2014-9-24
      fix the screen show
    */
    ui->centralwidget->setLayout(ui->verticalLayout);

}

void WBSDPayWindow::on_cboCurrency_activated(int index){
	int data=ui->cboCurrency->itemData(ui->cboCurrency->currentIndex()).toInt();
	ParameterMsg msg(Message::UIB,Message::DP, 22, Message::SET_PARAMETER);  //BIT9
	msg.setChar(1,data);
	itsBaseWindow->addMessageToQue(msg);


	ParameterMsg msgclearCreditTime_and_msgcurrency(Message::UIB,Message::DP, 22);
	msgclearCreditTime_and_msgcurrency.getWord();
	itsBaseWindow->addMessageToQue(msgclearCreditTime_and_msgcurrency);

}

void WBSDPayWindow::on_cboRFIDMode_activated(int index){
	int data=ui->cboRFIDMode->itemData(ui->cboRFIDMode->currentIndex()).toInt();
	if (data==2){
		ui->lblRFIDTimeOut->setEnabled(true);
		ui->cboRFIDTimeout->setEnabled(true);
	} else {
		ui->lblRFIDTimeOut->setEnabled(false);
		ui->cboRFIDTimeout->setEnabled(false);
	}
	ParameterMsg msg(Message::UIB,Message::DP, 18, Message::SET_PARAMETER);  //BIT9
	msg.setNibble(3,data);
	itsBaseWindow->addMessageToQue(msg);
	if (data>0){
		ParameterMsg nurse(Message::UIB,Message::DP, 18, Message::SET_PARAMETER);  
		msg.setBit(0,1);
		itsBaseWindow->addMessageToQue(msg);
	} else {
		ParameterMsg msg(Message::UIB,Message::DP, 18, Message::SET_PARAMETER);  
		msg.setBit(0,0);
		itsBaseWindow->addMessageToQue(msg);
	}
	ParameterMsg msgclearCreditTime_and_msgcurrency(Message::UIB,Message::DP, 22);
	msgclearCreditTime_and_msgcurrency.getWord();
	itsBaseWindow->addMessageToQue(msgclearCreditTime_and_msgcurrency);
}
void WBSDPayWindow::on_cboClearCreditTime_activated(int index){
	int data=ui->cboClearCreditTime->itemData(ui->cboClearCreditTime->currentIndex()).toInt();
	ParameterMsg msg(Message::UIB,Message::DP, 22, Message::SET_PARAMETER);  //BIT9
	msg.setNibble(0,data);
	itsBaseWindow->addMessageToQue(msg);
	ParameterMsg msgclearCreditTime_and_msgcurrency(Message::UIB,Message::DP, 22);
	msgclearCreditTime_and_msgcurrency.getWord();
	itsBaseWindow->addMessageToQue(msgclearCreditTime_and_msgcurrency);
}

void WBSDPayWindow::on_cboSaleType_activated(int index){
	int data=ui->cboSaleType->itemData(ui->cboSaleType->currentIndex()).toInt();
	ParameterMsg msg(Message::MCB,Message::DP, 0, Message::SET_PARAMETER);  //BIT9
	msg.setBit(8,data);
	itsBaseWindow->addMessageToQue(msg);
	ParameterMsg msgpay_enabled_and_msgpay_type(Message::MCB,Message::DP, 0);
	msgpay_enabled_and_msgpay_type.getWord();
	itsBaseWindow->addMessageToQue(msgpay_enabled_and_msgpay_type);
}

void WBSDPayWindow::on_cboPaymentEnabled_activated(int index){
  if (index==1){
	enable_pay(true);
	ParameterMsg msgPay_E(Message::MCB,Message::DP, 0, Message::SET_PARAMETER);  //BIT9
	msgPay_E.setBit(9,1);
	itsBaseWindow->addMessageToQue(msgPay_E);
//	ParameterMsg msgPay_View(Message::UIB,Message::DP, 8, Message::SET_PARAMETER);  //BIT1
//	msgPay_View.setBit(1,1);
//	itsBaseWindow->addMessageToQue(msgPay_View);
	ParameterMsg msgpay_enabled_and_msgpay_type(Message::MCB,Message::DP, 0);
	msgpay_enabled_and_msgpay_type.getWord();
	itsBaseWindow->addMessageToQue(msgpay_enabled_and_msgpay_type);

  } else {
	enable_pay(false);
	ParameterMsg msgPay_E(Message::MCB,Message::DP, 0, Message::SET_PARAMETER);  //BIT9
	msgPay_E.setBit(9,0);
	itsBaseWindow->addMessageToQue(msgPay_E);
//	ParameterMsg msgPay_View(Message::UIB,Message::DP, 8, Message::SET_PARAMETER);  //BIT1
//	msgPay_View.setBit(1,0);
//	itsBaseWindow->addMessageToQue(msgPay_View);
	ParameterMsg msgpay_enabled_and_msgpay_type(Message::MCB,Message::DP, 0);
	msgpay_enabled_and_msgpay_type.getWord();
	itsBaseWindow->addMessageToQue(msgpay_enabled_and_msgpay_type);
  }
}

void WBSDPayWindow::on_cboRFIDTimeout_activated(int arg1){
	int data=ui->cboRFIDTimeout->itemData(ui->cboRFIDTimeout->currentIndex()).toInt();
	ParameterMsg msgpay_enabled_and_msgpay_type(Message::UIB,Message::DP, 18);
	msgpay_enabled_and_msgpay_type.setNibble(2,data);
	itsBaseWindow->addMessageToQue(msgpay_enabled_and_msgpay_type);
}

	void WBSDPayWindow::update_cbo(QComboBox* theBox, unsigned int conf)
{
	int noItems = theBox->count();
	int index;
	for (index=0; index<noItems; index++){
		int itemVal = theBox->itemData(index).toInt();
        if (conf==itemVal ) {
            theBox->setCurrentIndex(index);
            if( theBox == ui->cboCurrency)
            {
                if(conf == 21) //for jap
                {
                   numberOfDecimals  = 0;
                }
                else
                {
                    numberOfDecimals = 2;
                }
                this->updateForm();
            }
			break;
		}
	}
}

void WBSDPayWindow::enable_pay(bool enabled,bool paycbo){
	//ui->cboRFIDMode->setEnabled(enabled);
	ui->cboPaymentEnabled->setEnabled(paycbo);
	ui->lblPayEnabled->setEnabled(paycbo);

	ui->cboCurrency->setEnabled(enabled);
	ui->cboClearCreditTime->setEnabled(enabled);
	ui->cboSaleType->setEnabled(enabled);
	ui->btnCoinChanelA->setEnabled(enabled);
	ui->btnCoinChanelB->setEnabled(enabled);
	ui->btnCoinChanelC->setEnabled(enabled);
	ui->btnCoinChanelD->setEnabled(enabled);
	ui->btnCoinChanelE->setEnabled(enabled);
	ui->btnCoinChanelF->setEnabled(enabled);
	ui->btnCoinChanelF->setEnabled(enabled);
	ui->button1->setEnabled(enabled);
	ui->button2->setEnabled(enabled);
	ui->button3->setEnabled(enabled);
	ui->button4->setEnabled(enabled);
	ui->button5->setEnabled(enabled);
	ui->button6->setEnabled(enabled);
	ui->button7->setEnabled(enabled);
	ui->button8->setEnabled(enabled);

	ui->lblClearCreditTime->setEnabled(enabled);
	ui->lblCurrency->setEnabled(enabled);
	ui->lblSaletype->setEnabled(enabled);

	ui->lblMoneyInCashBox->setEnabled(enabled);
    ui->lblTotalTurnOver->setEnabled(enabled);
	ui->lblFreeVendTokens->setEnabled(enabled);
	ui->lblTotalCollected->setEnabled(enabled);
	ui->btnReset->setEnabled(enabled);
    ui->lbl_flag_counters->setEnabled(enabled);
    ui->lbl_flag_full_2->setEnabled(enabled);
    ui->lbl_flag_warn_2->setEnabled(enabled);

    ui->btn_setwarn_2->setEnabled(enabled);
    //ui->btn_setfull_2->setEnabled(enabled);
    //ui->btn_setreset_2->setEnabled(enabled);

    ui->spinBox_3->setEnabled(enabled);
    ui->spinBox_4->setEnabled(enabled);
    ui->horizontalSlider_2->setEnabled(enabled);
    ui->horizontalSlider_4->setEnabled(enabled);


    ui->label->setEnabled(enabled);
    ui->label_2->setEnabled(enabled);
    ui->label_6->setEnabled(enabled);
    ui->label_7->setEnabled(enabled);
    ui->label_8->setEnabled(enabled);
    ui->label_9->setEnabled(enabled);
    ui->label_10->setEnabled(enabled);

}


WBSDPayWindow::~WBSDPayWindow()
{
    delete ui;
}

void WBSDPayWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
	setPrice->deleteLater();
}

void WBSDPayWindow::on_button1_clicked()
{
	if (setPrice!=0)
		setPrice->deleteLater();
	setPrice=new WBSDPaySetPrice(QString("%2 [%1]").arg(drinkNoButton1).arg(drinkNameButton1),drinkPriceButton1,1,numberOfDecimals,tokenValChannelA,itsBaseWindow);
    this->hide();
    connect(setPrice,SIGNAL(iclose()),this,SLOT(show()));
    setPrice->show();
}

void WBSDPayWindow::on_button2_clicked()
{
	if (setPrice!=0)
		setPrice->deleteLater();
	setPrice=new WBSDPaySetPrice(QString("%2 [%1]").arg(drinkNoButton2).arg(drinkNameButton2),drinkPriceButton2,2,numberOfDecimals,tokenValChannelA,itsBaseWindow);

    this->hide();
    connect(setPrice,SIGNAL(iclose()),this,SLOT(show()));
    setPrice->show();
}

void WBSDPayWindow::on_button3_clicked()
{
	if (setPrice!=0)
		setPrice->deleteLater();
	setPrice=new WBSDPaySetPrice(QString("%2 [%1]").arg(drinkNoButton3).arg(drinkNameButton3),drinkPriceButton3,3,numberOfDecimals,tokenValChannelA,itsBaseWindow);

    this->hide();
    connect(setPrice,SIGNAL(iclose()),this,SLOT(show()));
    setPrice->show();
}

void WBSDPayWindow::on_button4_clicked()
{
	if (setPrice!=0)
		setPrice->deleteLater();
	setPrice=new WBSDPaySetPrice(QString("%2 [%1]").arg(drinkNoButton4).arg(drinkNameButton4),drinkPriceButton4,4,numberOfDecimals,tokenValChannelA,itsBaseWindow);
    this->hide();
    connect(setPrice,SIGNAL(iclose()),this,SLOT(show()));
    setPrice->show();
}

void WBSDPayWindow::on_button5_clicked()
{
	if (setPrice!=0)
		setPrice->deleteLater();
	setPrice=new WBSDPaySetPrice(QString("%2 [%1]").arg(drinkNoButton5).arg(drinkNameButton5),drinkPriceButton5,5,numberOfDecimals,tokenValChannelA,itsBaseWindow);
    this->hide();
    connect(setPrice,SIGNAL(iclose()),this,SLOT(show()));
    setPrice->show();
}

void WBSDPayWindow::on_button6_clicked()
{
	if (setPrice!=0)
		setPrice->deleteLater();
	setPrice=new WBSDPaySetPrice(QString("%2 [%1]").arg(drinkNoButton6).arg(drinkNameButton6),drinkPriceButton6,6,numberOfDecimals,tokenValChannelA,itsBaseWindow);
    this->hide();
    connect(setPrice,SIGNAL(iclose()),this,SLOT(show()));
    setPrice->show();
}

void WBSDPayWindow::on_button7_clicked()
{
	if (setPrice!=0)
		setPrice->deleteLater();
	setPrice=new WBSDPaySetPrice(QString("%2 [%1]").arg(drinkNoButton7).arg(drinkNameButton7),drinkPriceButton7,7,numberOfDecimals,tokenValChannelA,itsBaseWindow);
    this->hide();
    connect(setPrice,SIGNAL(iclose()),this,SLOT(show()));
    setPrice->show();
}

void WBSDPayWindow::on_button8_clicked()
{
	if (setPrice!=0)
		setPrice->deleteLater();
	setPrice=new WBSDPaySetPrice(QString("%2 [%1]").arg(drinkNoButton8).arg(drinkNameButton8),drinkPriceButton8,8,numberOfDecimals,tokenValChannelA,itsBaseWindow);
    this->hide();
    connect(setPrice,SIGNAL(iclose()),this,SLOT(show()));
    setPrice->show();
}

void WBSDPayWindow::on_btnCoinChanelA_clicked()
{
	if (setCoinChannelDlg!=0)
		setCoinChannelDlg->deleteLater();
	setCoinChannelDlg=new WBSDPaySetCoinChannel(1,tokenValChannelA,numberOfDecimals,itsBaseWindow);
    this->hide();
    connect(setCoinChannelDlg,SIGNAL(iclose()),this,SLOT(show()));
    setCoinChannelDlg->show();
}
void WBSDPayWindow::on_btnCoinChanelB_clicked()
{
	if (setCoinChannelDlg!=0)
		setCoinChannelDlg->deleteLater();
	setCoinChannelDlg=new WBSDPaySetCoinChannel(2,tokenValChannelB,numberOfDecimals,itsBaseWindow);
    this->hide();
    connect(setCoinChannelDlg,SIGNAL(iclose()),this,SLOT(show()));
    setCoinChannelDlg->show();
}
void WBSDPayWindow::on_btnCoinChanelC_clicked()
{
	if (setCoinChannelDlg!=0)
		setCoinChannelDlg->deleteLater();
	setCoinChannelDlg=new WBSDPaySetCoinChannel(3,tokenValChannelC,numberOfDecimals,itsBaseWindow);
    this->hide();
    connect(setCoinChannelDlg,SIGNAL(iclose()),this,SLOT(show()));
    setCoinChannelDlg->show();
}
void WBSDPayWindow::on_btnCoinChanelD_clicked()
{
	if (setCoinChannelDlg!=0)
		setCoinChannelDlg->deleteLater();
	setCoinChannelDlg=new WBSDPaySetCoinChannel(4,tokenValChannelD,numberOfDecimals,itsBaseWindow);
    this->hide();
    connect(setCoinChannelDlg,SIGNAL(iclose()),this,SLOT(show()));
    setCoinChannelDlg->show();
}
void WBSDPayWindow::on_btnCoinChanelE_clicked()
{
	if (setCoinChannelDlg!=0)
		setCoinChannelDlg->deleteLater();
	setCoinChannelDlg=new WBSDPaySetCoinChannel(5,tokenValChannelE,numberOfDecimals,itsBaseWindow);
    this->hide();
    connect(setCoinChannelDlg,SIGNAL(iclose()),this,SLOT(show()));
    setCoinChannelDlg->show();
}
void WBSDPayWindow::on_btnCoinChanelF_clicked()
{
	if (setCoinChannelDlg!=0)
		setCoinChannelDlg->deleteLater();
	setCoinChannelDlg=new WBSDPaySetCoinChannel(6,tokenValChannelF,numberOfDecimals,itsBaseWindow);
    this->hide();
    connect(setCoinChannelDlg,SIGNAL(iclose()),this,SLOT(show()));
    setCoinChannelDlg->show();
}



void WBSDPayWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDPayWindow::updateForm()
{
    ui->button1->setText(QObject::tr("Button 1\n%2 [%1]\nPrice %3").arg(drinkNoButton1).arg(drinkNameButton1).arg(QString::number((float)drinkPriceButton1/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->button2->setText(QObject::tr("Button 2\n%2 [%1]\nPrice %3").arg(drinkNoButton2).arg(drinkNameButton2).arg(QString::number((float)drinkPriceButton2/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->button3->setText(QObject::tr("Button 3\n%2 [%1]\nPrice %3").arg(drinkNoButton3).arg(drinkNameButton3).arg(QString::number((float)drinkPriceButton3/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->button4->setText(QObject::tr("Button 4\n%2 [%1]\nPrice %3").arg(drinkNoButton4).arg(drinkNameButton4).arg(QString::number((float)drinkPriceButton4/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->button5->setText(QObject::tr("Button 5\n%2 [%1]\nPrice %3").arg(drinkNoButton5).arg(drinkNameButton5).arg(QString::number((float)drinkPriceButton5/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->button6->setText(QObject::tr("Button 6\n%2 [%1]\nPrice %3").arg(drinkNoButton6).arg(drinkNameButton6).arg(QString::number((float)drinkPriceButton6/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->button7->setText(QObject::tr("Button 7\n%2 [%1]\nPrice %3").arg(drinkNoButton7).arg(drinkNameButton7).arg(QString::number((float)drinkPriceButton7/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->button8->setText(QObject::tr("Button 8\n%2 [%1]\nPrice %30").arg(drinkNoButton8).arg(drinkNameButton8).arg(QString::number((float)drinkPriceButton8/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
	double v=(double)tokenValChannelA/qPow(10,numberOfDecimals);
    ui->btnCoinChanelA->setText(QObject::tr("Coin channel A\nValue:%1").arg(QString::number(v,'f',numberOfDecimals)));
    ui->btnCoinChanelB->setText(QObject::tr("Coin channel B\nValue:%1").arg(QString::number((double)tokenValChannelB/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->btnCoinChanelC->setText(QObject::tr("Coin channel C\nValue:%1").arg(QString::number((double)tokenValChannelC/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->btnCoinChanelD->setText(QObject::tr("Coin channel D\nValue:%1").arg(QString::number((double)tokenValChannelD/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
    ui->btnCoinChanelE->setText(QObject::tr("Coin channel E\nValue:%1").arg(QString::number((double)tokenValChannelE/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
	if (tokenValChannelF==0) {
        ui->btnCoinChanelF->setText(QObject::tr("Coin channel F\nFV Token"));
	} else {
        ui->btnCoinChanelF->setText(QObject::tr("Coin channel F\nValue:%1").arg(QString::number((double)tokenValChannelF/qPow(10,numberOfDecimals),'f',numberOfDecimals)));
	}

}



void WBSDPayWindow::updateData()
{
		ParameterMsg msg_inst_comp(Message::MCB,Message::DP, 4);
		msg_inst_comp.getNibble(1);
		itsBaseWindow->addMessageToQue(msg_inst_comp);

		ParameterMsg msg_RFID(Message::UIB,Message::DP, 18);
		msg_RFID.getWord();
		itsBaseWindow->addMessageToQue(msg_RFID);

//#define DB_EMPTY_CASHBOX     &ui_dv[0],BIT05

		
// 129	3	11	ANALOG	COLLECT_CASHBOX	RO	0	ANALOG
// 129	3	21	ANALOG	DB_COLLECT_MONEY		1	ANALOG
// 129	3	23	ANALOG	TURNOVER		0	ANALOG
//DB_COLLECT_MONEY = Total
//DB_COLLECT_CASHBOX = I Pengabox
        /*
         *
         * modify by lee 2015-1009
         */
	readPayCounters();
    ParameterMsg msg_cashbox66(Message::MCB,Message::DP, 59);
    msg_cashbox66.getWord();
    itsBaseWindow->addMessageToQue(msg_cashbox66);

    ParameterMsg msg_cashbox67(Message::MCB,Message::DP, 60);
    msg_cashbox67.getWord();
    itsBaseWindow->addMessageToQue(msg_cashbox67);

    ParameterMsg nayx(Message::UIB,Message::DP, 23);
    nayx.getWord();
    itsBaseWindow->addMessageToQue(nayx);

}

void WBSDPayWindow::loadPayData(int conf){

	if ((conf==14) || (conf==15)) { 
		ParameterMsg msgpay_enabled_and_msgpay_type(Message::MCB,Message::DP, 0);
		msgpay_enabled_and_msgpay_type.getWord();
		itsBaseWindow->addMessageToQue(msgpay_enabled_and_msgpay_type);

		ParameterMsg msgclearCreditTime_and_msgcurrency(Message::UIB,Message::DP, 22);
		msgclearCreditTime_and_msgcurrency.getWord();
		itsBaseWindow->addMessageToQue(msgclearCreditTime_and_msgcurrency);




		ParameterMsg msg0(Message::MCB,Message::DP, 6);
		ParameterMsg msg1(Message::MCB,Message::DP, 7);
		ParameterMsg msg2(Message::MCB,Message::DP, 8);
		ParameterMsg msg3(Message::MCB,Message::DP, 9);
		msg0.getWord();
		msg1.getWord();
		msg2.getWord();
		msg3.getWord();
		itsBaseWindow->addMessageToQue(msg0);
		itsBaseWindow->addMessageToQue(msg1);
		itsBaseWindow->addMessageToQue(msg2);
		itsBaseWindow->addMessageToQue(msg3);


		ParameterMsg uimsg10(Message::UIB,Message::DP, 10);
		ParameterMsg uimsg11(Message::UIB,Message::DP, 11);
		ParameterMsg uimsg12(Message::UIB,Message::DP, 12);
		ParameterMsg uimsg13(Message::UIB,Message::DP, 13);
		ParameterMsg uimsg14(Message::UIB,Message::DP, 14);
		ParameterMsg uimsg15(Message::UIB,Message::DP, 15);
		ParameterMsg uimsg16(Message::UIB,Message::DP, 16);
		ParameterMsg uimsg17(Message::UIB,Message::DP, 17);
		uimsg10.getWord();
		uimsg11.getWord();
		uimsg12.getWord();
		uimsg13.getWord();
		uimsg14.getWord();
		uimsg15.getWord();
		uimsg16.getWord();
		uimsg17.getWord();
		itsBaseWindow->addMessageToQue(uimsg10);
		itsBaseWindow->addMessageToQue(uimsg11);
		itsBaseWindow->addMessageToQue(uimsg12);
		itsBaseWindow->addMessageToQue(uimsg13);
		itsBaseWindow->addMessageToQue(uimsg14);
		itsBaseWindow->addMessageToQue(uimsg15);
		itsBaseWindow->addMessageToQue(uimsg16);
		itsBaseWindow->addMessageToQue(uimsg17);


		ParameterMsg msg10(Message::MCB,Message::DP, 10);
		ParameterMsg msg11(Message::MCB,Message::DP, 11);
		ParameterMsg msg12(Message::MCB,Message::DP, 12);
		ParameterMsg msg13(Message::MCB,Message::DP, 13);
		ParameterMsg msg14(Message::MCB,Message::DP, 14);
		ParameterMsg msg15(Message::MCB,Message::DP, 15);
		msg10.getWord();
		msg11.getWord();
		msg12.getWord();
		msg13.getWord();
		msg14.getWord();
		msg15.getWord();
		itsBaseWindow->addMessageToQue(msg10);
		itsBaseWindow->addMessageToQue(msg11);
		itsBaseWindow->addMessageToQue(msg12);
		itsBaseWindow->addMessageToQue(msg13);
		itsBaseWindow->addMessageToQue(msg14);
		itsBaseWindow->addMessageToQue(msg15);
	} else {
		enable_pay(false,false);
		update_cbo(ui->cboPaymentEnabled,0); 
    }
}

void WBSDPayWindow::showpriceset()
{


    ParameterMsg msgclearCreditTime_and_msgcurrency(Message::UIB,Message::DP, 22);
    msgclearCreditTime_and_msgcurrency.getWord();
    itsBaseWindow->addMessageToQue(msgclearCreditTime_and_msgcurrency);
    ParameterMsg uimsg10(Message::UIB,Message::DP, 10);
    ParameterMsg uimsg11(Message::UIB,Message::DP, 11);
    ParameterMsg uimsg12(Message::UIB,Message::DP, 12);
    ParameterMsg uimsg13(Message::UIB,Message::DP, 13);
    ParameterMsg uimsg14(Message::UIB,Message::DP, 14);
    ParameterMsg uimsg15(Message::UIB,Message::DP, 15);
    ParameterMsg uimsg16(Message::UIB,Message::DP, 16);
    ParameterMsg uimsg17(Message::UIB,Message::DP, 17);
    uimsg10.getWord();
    uimsg11.getWord();
    uimsg12.getWord();
    uimsg13.getWord();
    uimsg14.getWord();
    uimsg15.getWord();
    uimsg16.getWord();
    uimsg17.getWord();
    itsBaseWindow->addMessageToQue(uimsg10);
    itsBaseWindow->addMessageToQue(uimsg11);
    itsBaseWindow->addMessageToQue(uimsg12);
    itsBaseWindow->addMessageToQue(uimsg13);
    itsBaseWindow->addMessageToQue(uimsg14);
    itsBaseWindow->addMessageToQue(uimsg15);
    itsBaseWindow->addMessageToQue(uimsg16);
    itsBaseWindow->addMessageToQue(uimsg17);

    ParameterMsg msg0(Message::MCB,Message::DP, 6);
    ParameterMsg msg1(Message::MCB,Message::DP, 7);
    ParameterMsg msg2(Message::MCB,Message::DP, 8);
    ParameterMsg msg3(Message::MCB,Message::DP, 9);
    msg0.getWord();
    msg1.getWord();
    msg2.getWord();
    msg3.getWord();
    itsBaseWindow->addMessageToQue(msg0);
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg3);

    ParameterMsg msg10(Message::MCB,Message::DP, 10);
    ParameterMsg msg11(Message::MCB,Message::DP, 11);
    ParameterMsg msg12(Message::MCB,Message::DP, 12);
    ParameterMsg msg13(Message::MCB,Message::DP, 13);
    ParameterMsg msg14(Message::MCB,Message::DP, 14);
    ParameterMsg msg15(Message::MCB,Message::DP, 15);
    msg10.getWord();
    msg11.getWord();
    msg12.getWord();
    msg13.getWord();
    msg14.getWord();
    msg15.getWord();
    itsBaseWindow->addMessageToQue(msg10);
    itsBaseWindow->addMessageToQue(msg11);
    itsBaseWindow->addMessageToQue(msg12);
    itsBaseWindow->addMessageToQue(msg13);
    itsBaseWindow->addMessageToQue(msg14);
    itsBaseWindow->addMessageToQue(msg15);
    ui->button1->setEnabled(true);
    ui->button2->setEnabled(true);
    ui->button3->setEnabled(true);
    ui->button4->setEnabled(true);
    ui->button5->setEnabled(true);
    ui->button6->setEnabled(true);
    ui->button7->setEnabled(true);
    ui->button8->setEnabled(true);
    ui->cboCurrency->setEnabled(true);
}

void WBSDPayWindow::gotMessage(Message aMsg)
{
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DP)){
		int high=aMsg.getDataInt() & 0x00FF;
		int low=(aMsg.getDataInt() >> 8) & 0x00FF;

		qDebug() << aMsg.getData().toHex();
		qDebug() << low;
		qDebug() << high;

        switch(aMsg.getParameters().at(3)){
			case 0:
				update_cbo(ui->cboPaymentEnabled,((aMsg.getDataInt() & 0x0200)>>9)); 
				low=(aMsg.getDataInt() & 0x0200)>>9;
				low=aMsg.getDataInt();
				low=low & 0x0200;
				enable_pay(low>0);
				update_cbo(ui->cboSaleType,(aMsg.getDataInt() & 0x0100)>>8);  
				break;
			case 4:
				loadPayData(aMsg.getDataInt());
				break;
            case 6:
				drinkNoButton1=low;
				drinkNoButton2=high;
				drinkNameButton1=DataBaseHelper::getInstance()->getTabKatString("100",low);
				drinkNameButton2=DataBaseHelper::getInstance()->getTabKatString("100",high);
                break;
            case 7:
				drinkNoButton3=low;
				drinkNoButton4=high;
				drinkNameButton3=DataBaseHelper::getInstance()->getTabKatString("100",low);
				drinkNameButton4=DataBaseHelper::getInstance()->getTabKatString("100",high);
                break;
            case 8:
				drinkNoButton5=low;
				drinkNoButton6=high;
				drinkNameButton5=DataBaseHelper::getInstance()->getTabKatString("100",low);
				drinkNameButton6=DataBaseHelper::getInstance()->getTabKatString("100",high);
                break;
            case 9:
				drinkNoButton7=low;
				drinkNoButton8=high;
				drinkNameButton7=DataBaseHelper::getInstance()->getTabKatString("100",low);
				drinkNameButton8=DataBaseHelper::getInstance()->getTabKatString("100",high);
                break;
            case 10:
				tokenValChannelA=aMsg.getDataInt();;
				updateForm();
                break;
            case 11:
				tokenValChannelB=aMsg.getDataInt();;
				updateForm();
                break;
            case 12:
				tokenValChannelC=aMsg.getDataInt();;
				updateForm();
                break;
            case 13:
				tokenValChannelD=aMsg.getDataInt();;
				updateForm();
                break;
            case 14:
				tokenValChannelE=aMsg.getDataInt();;
				updateForm();
                break;
            case 15:
				tokenValChannelF=aMsg.getDataInt();;
				updateForm();
                break;
            case 41:
            /*2014-12-29 modify by lee :add payment counter and full check*/
/*modify by lee 2015-10-09
 *              #define DB_FULLCOIN_WARNING_VALUE  &cu_dp[60]
                #define DB_FULLCOIN_VALUE          &cu_dp[59]
                #define DB_TOTAL_COIN           &cu_dp[58]
 *
 *
 */
                break;
            case 42:

                ui->lbl_flag_full_2->setText(((aMsg.getDataInt() & 0x100)==0x100?QObject::tr("FLAG_ON"):QObject::tr("FLAG_OFF")));
                ui->lbl_flag_warn_2->setText(((aMsg.getDataInt() & 0x200)==0x200?QObject::tr("FLAG_ON"):QObject::tr("FLAG_OFF")));
                break;
            case 58:
                ui->lbl_flag_counters->setText(QString().number((aMsg.getDataInt())));
                 break;
        case 59:
            //qDebug()<<"67date ="<<aMsg.getDataInt();
            if(((aMsg.getDataInt()) )!= ui->horizontalSlider_4->value())
            ui->horizontalSlider_4->setValue(((aMsg.getDataInt()) ));
             break;
        case 60:
            qDebug()<<"66date ="<<aMsg.getDataInt();
            if(((aMsg.getDataInt()) )!= ui->horizontalSlider_2->value())
        ui->horizontalSlider_2->setValue(((aMsg.getDataInt()) ));
             break;
            default:
                break;
        }
    } else
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::UIB) && (aMsg.getDataBaseType()==Message::DP)){
		int high=aMsg.getDataInt() & 0x00FF;
		int low=(aMsg.getDataInt() >> 8) & 0x00FF;
        switch(aMsg.getParameters().at(3)){
            case 23:
                if(((0x80 &aMsg.getDataInt())>>7) ==1)
                {
                    //enable price set
                    showpriceset();
                }
                break;
            case 10:
				drinkPriceButton1=aMsg.getDataInt();
				updateForm();
                break;
            case 11:
				drinkPriceButton2=aMsg.getDataInt();
				updateForm();
                break;
            case 12:
				drinkPriceButton3=aMsg.getDataInt();
				updateForm();
                break;
            case 13:
				drinkPriceButton4=aMsg.getDataInt();
				updateForm();
                break;
            case 14:
				drinkPriceButton5=aMsg.getDataInt();
				updateForm();
                break;
            case 15:
				drinkPriceButton6=aMsg.getDataInt();
				updateForm();
                break;
            case 16:
				drinkPriceButton7=aMsg.getDataInt();
				updateForm();
                break;
            case 17:
				drinkPriceButton8=aMsg.getDataInt();
				updateForm();
                break;
            case 18:
				high=aMsg.getDataInt();
				high=(aMsg.getDataInt() & 0xf000);
				high=high>>12;
				update_cbo(ui->cboRFIDMode,high); 
				if (high==2){
					ui->lblRFIDTimeOut->setEnabled(true);
					ui->cboRFIDTimeout->setEnabled(true);
				} else {
					ui->lblRFIDTimeOut->setEnabled(false);
					ui->cboRFIDTimeout->setEnabled(false);
				}
				low=(aMsg.getDataInt() & 0x0f00)>>8;
				update_cbo(ui->cboRFIDTimeout,low); 
                break;
            case 22:
				update_cbo(ui->cboCurrency,low); 
				high=high & 0x0F;
				update_cbo(ui->cboClearCreditTime,high); 
                break;
            default:
                break;
        }
	}
	else
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::AP)){
		float money;
		unsigned char p= aMsg.getParameters().at(3);
		qDebug() << "MCB AP:" << p << " " << QString("%1").arg((unsigned int)(aMsg.getParameters().at(3)));
		switch((unsigned int) p){
            case 11:
				money=aMsg.getDataFloat();
                ui->lblMoneyInCashBox->setText(QObject::tr("Money in cashbox %1").arg(QString::number(money,'f',numberOfDecimals)));
                break;
            case 21:
				money=aMsg.getDataFloat();
                ui->lblTotalCollected->setText(QObject::tr("Total collected money %1").arg(QString::number(money,'f',numberOfDecimals)));
                break;
            case 23:
				money=aMsg.getDataFloat();
                ui->lblTotalTurnOver->setText(QObject::tr("Total turnover %1").arg(QString::number(money,'f',numberOfDecimals)));
				break;
            case 194:
				money=aMsg.getDataFloat();
                ui->lblFreeVendTokens->setText(QObject::tr("Total tokens %1").arg(QString::number(money,'f',numberOfDecimals)));
				QTimer::singleShot(1000,this,SLOT(readPayCounters()));
				break;
            default:
                break;
        }
	}
}
void WBSDPayWindow::readPayCounters(){
		ParameterMsg counterMsg(Message::MCB,Message::AP, 23);
		counterMsg.getWord();
		itsBaseWindow->addMessageToQue(counterMsg);

		ParameterMsg counterMsg1(Message::MCB,Message::AP, 11);
		counterMsg1.getWord();
		itsBaseWindow->addMessageToQue(counterMsg1);

		ParameterMsg counterMsg2(Message::MCB,Message::AP, 21);
		counterMsg2.getWord();
		itsBaseWindow->addMessageToQue(counterMsg2);

		ParameterMsg counterMsg3(Message::MCB,Message::AP, 194);
		counterMsg3.getWord();
		itsBaseWindow->addMessageToQue(counterMsg3);



        ParameterMsg msg_cashbox42(Message::MCB,Message::DP, 42);
        msg_cashbox42.getWord();
        itsBaseWindow->addMessageToQue(msg_cashbox42);

        ParameterMsg msg_cashbox65(Message::MCB,Message::DP, 58);
        msg_cashbox65.getWord();
        itsBaseWindow->addMessageToQue(msg_cashbox65);

}

void WBSDPayWindow::on_btn_setwarn_2_clicked()
{
    if (ui->spinBox_4->value()<ui->spinBox_3->value())
    {
        QMessageBox::critical(this,"Value Illegal","The full value is illegal ,please check and set again!");
        return;
    }
    ParameterMsg msg_cashbox411(Message::MCB,Message::DP, 59,Message::SET_PARAMETER);
    msg_cashbox411.setWord(ui->spinBox_4->value());
    itsBaseWindow->addMessageToQue(msg_cashbox411);
    qDebug()<<"ui->spinBox_3->value()"<<ui->spinBox_4->value();
    ParameterMsg msg_cashbox410(Message::MCB,Message::DP, 60,Message::SET_PARAMETER);
    msg_cashbox410.setWord(ui->spinBox_3->value());
    itsBaseWindow->addMessageToQue(msg_cashbox410);
    qDebug()<<"ui->spinBox_4->value()"<<ui->spinBox_3->value();

}

void WBSDPayWindow::on_btn_setfull_2_clicked()
{
    if (ui->spinBox_4->value()<ui->spinBox_3->value())
    {
        QMessageBox::critical(this,"Value Illegal","The full value is illegal ,please check and set again!");
        return;
    }
    ParameterMsg msg_cashbox411(Message::MCB,Message::DP, 59,Message::SET_PARAMETER);
    msg_cashbox411.setWord(ui->spinBox_4->value());
    itsBaseWindow->addMessageToQue(msg_cashbox411);

    ParameterMsg msg_cashbox410(Message::MCB,Message::DP, 60,Message::SET_PARAMETER);
    msg_cashbox410.setWord(ui->spinBox_3->value());
    itsBaseWindow->addMessageToQue(msg_cashbox410);

}

void WBSDPayWindow::on_btn_setreset_2_clicked()
{
    ParameterMsg msg_cashbox41(Message::MCB,Message::DP, 42,Message::SET_PARAMETER);
    msg_cashbox41.setChar(0,0);
    itsBaseWindow->addMessageToQue(msg_cashbox41);
}

void WBSDPayWindow::on_btnReset_clicked(){
	QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QObject::tr("Confirm reset"), QObject::tr("Confirm reset of cashbox?"),QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
		ParameterMsg counterResetMsg(Message::UIB,Message::DV, 0);
		counterResetMsg.setBit(5,1);
		itsBaseWindow->addMessageToQue(counterResetMsg);
    }
}

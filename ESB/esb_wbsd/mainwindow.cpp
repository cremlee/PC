#include "mainwindow.h"
#include "QByteArray.h"
#include "ui_mainwindow.h"
#include "wbsd_serial_port.h"
#include "parametermsg.h"
#include "message.h"
#include "qstring.h"
#include "qextserialenumerator.h"
#include "qvariant.h"
#include "qdebug.h"
#include "errormessage.h"
#include "qtimer.h"
#include "qdatetime.h"
#include "stringmessage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	init=true;
	qe=new QextSerialEnumerator(this);
	qe->setUpNotifications();

	connect (qe,SIGNAL(deviceDiscovered(const QextPortInfo)),this,SLOT(deviceDiscovered(const QextPortInfo)));
	connect (qe,SIGNAL(deviceRemoved(const QextPortInfo)),this,SLOT(deviceRemoved(const QextPortInfo)));

	err_act=0;
	err_total=0;
	err_query_type=0;
	err_query_number=0;

	QList<QextPortInfo> portList=qe->getPorts();

    ui->setupUi(this);


	connect(wbsd_SERIAL_PORT::itsInstance,SIGNAL(gotMessage(Message)),this,SLOT(gotMessage(Message)));
	connect(wbsd_SERIAL_PORT::itsInstance,SIGNAL(connectionStatusChanged(int,StringMessage)),this,SLOT(connectionStatusChanged(int,StringMessage)));
	connect(wbsd_SERIAL_PORT::itsInstance,SIGNAL(log(QString)),this,SLOT(log(QString)));
	timerTemp=new QTimer(this);
	connect(timerTemp,SIGNAL(timeout()),this,SLOT(onTimerTemp()));
	

	int sel=0; 
	for (int i=0;i<portList.count();i++){
		QString qs=QString("%2:\t %1 [%3:%4]").arg(portList.at(i).friendName).arg(portList.at(i).portName).arg(portList.at(i).vendorID).arg(portList.at(i).productID);
		ui->cboCommand->addItem(qs,QVariant::fromValue(portList.at(i)));
		if ((portList.at(i).vendorID==1003)  && (portList.at(i).productID==8216)){
			wbsd_SERIAL_PORT::instance()->reconnect(portList.at(i).portName);
			sel=i;
		}
	}

	ui->cboConf->addItem("DEVELOPENT NOCONN",0x0000);
	ui->cboConf->addItem("Coffee-Milk-None",0x1300);
	ui->cboConf->addItem("Coffee-Milk-Milk",0x1360);
	ui->cboConf->addItem("Coffee-Milk-Tea",0x1370);
	ui->cboConf->addItem("Coffee-Milk-Choc",0x1380);
	ui->cboConf->addItem("Coffee-Milk-Sugar",0x1390);
	ui->cboConf->addItem("Coffee-Milk-Tank",0x13d0);
	ui->cboConf->addItem("Coffee-Milk-CF330",0x13E0);
	ui->cboConf->addItem("Coffee-Milk-NRI-G13",0x13F0);
	ui->cboConf->addItem("Coffee-Coffee-None",0x1100);
	ui->cboConf->addItem("Coffee-Coffee-Milk",0x1160);
	ui->cboConf->addItem("Coffee-Coffee-Tea",0x1170);
	ui->cboConf->addItem("Coffee-Coffee-Choc",0x1180);
	ui->cboConf->addItem("Coffee-Coffee-Sugar",0x1190);
	ui->cboConf->addItem("Coffee-Coffee-Tank",0x11d0);
	ui->cboConf->addItem("Coffee-Coffee-CF330",0x11E0);
	ui->cboConf->addItem("Coffee-Coffee-NRI-G13",0x11F0);
	ui->cboConf->addItem("Coffee-Decaf-None",0x1200);
	ui->cboConf->addItem("Coffee-Decaf-Milk",0x1260);
	ui->cboConf->addItem("Coffee-Decaf-Tea",0x1270);
	ui->cboConf->addItem("Coffee-Decaf-Choc",0x1280);
	ui->cboConf->addItem("Coffee-Decaf-Sugar",0x1290);
	ui->cboConf->addItem("Coffee-Decaf-Tank",0x12d0);
	ui->cboConf->addItem("Coffee-Decaf-CF330",0x12E0);
	ui->cboConf->addItem("Coffee-Decaf-NRI-G13",0x12F0);
	ui->cboRFID->addItem("No-RFID",0x0000);
	ui->cboRFID->addItem("Toggle on detect",0x1201);
	ui->cboRFID->addItem("One drink",0x2201);
	ui->cboCommand->setCurrentIndex(sel);
	ParameterMsg query1(Message::MCB,Message::DP,6);
	ParameterMsg query2(Message::MCB,Message::DP,7);
	ParameterMsg query3(Message::MCB,Message::DP,8);
	ParameterMsg query4(Message::MCB,Message::DP,9);
	ParameterMsg query5(Message::MCB,Message::DP,4);
	ParameterMsg query6(Message::UIB,Message::DP,14);
	query1.getWord();
	query2.getWord();
	query3.getWord();
	query4.getWord();
	query5.getWord();
	query6.getWord();
	queryQue.append(query1);
	queryQue.append(query2);
	queryQue.append(query3);
	queryQue.append(query4);
	queryQue.append(query5);
	queryQue.append(query6);


	timerTemp->setSingleShot(true);
	timerTemp->start(1000);
	init=false;
}

void MainWindow::connectionStatusChanged(int aStatus,StringMessage aMSG){
	init=true;
	switch (aStatus){
	case wbsd_SERIAL_PORT::CS_DISCONNECTED:
		ui->fraStatus->setStyleSheet("background:rgb(200,000,0)");
		ui->lstLog->clear();
		ui->lstHistoricErrors->clear();
		ui->lstActiveErrors->clear();
		ui->lstMetaData->clear();
		ui->lcdTnkUp->display(0);
		ui->lcdTnkDown->display(0);
		ui->lcdFridge->display(0);
		ui->lcdHeater->display(0);
		ui->lcdDriptray->display(0);
		ui->lcdFlow->display(0);
		ui->lcdLBIB->display(0);
		ui->lcdRBIB->display(0);
		ui->lcdLevAirbr->display(0);
		ui->lcdLevBoil->display(0);
		ui->lcdNumber->display(0);
		ui->lcdPelitier->display(0);
		timerTemp->stop();

		break;
	case wbsd_SERIAL_PORT::CS_CONNECTING:
		ui->fraStatus->setStyleSheet("background:rgb(200,200,0)");
		break;
	case wbsd_SERIAL_PORT::CS_SERVICEDEVICE:
		ui->fraStatus->setStyleSheet("background:rgb(200,200,200)");
		break;
	case wbsd_SERIAL_PORT::CS_LOCALESB:
		ui->fraStatus->setStyleSheet("background:rgb(0,200,0)");
		on_btnLoadMetadata_clicked();
		on_btnChkErrors_clicked();
		on_btnGetKayMappings_clicked();
		timerTemp->setSingleShot(true);
		timerTemp->start(1000);
		init=false;
		//doMessageQue();
		//timerTemp->start();
		break;
	default: 
		ui->fraStatus->setStyleSheet("background:rgb(0,0,100)");
		break;
	}

}


void MainWindow::onTimerTemp(){

	ParameterMsg msg1(Message::MCB,Message::AV,0);
	ParameterMsg msg2(Message::MCB,Message::AV,1);
	ParameterMsg msg3(Message::MCB,Message::AV,2);
	msg1.getWord();
	msg2.getWord();
	msg3.getWord();
	queryQue.append(msg1);	
	queryQue.append(msg2);	
	queryQue.append(msg3);	
	doMessageQue();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCboConf(unsigned int aVal){
	aVal=(0xFFFFFFF0 & aVal);
	int s=ui->cboConf->count();
	for (int index=0; index<s;index++){
		int v=ui->cboConf->itemData(index).toInt();
		if (v==aVal) {
			ui->cboConf->setCurrentIndex(index);
			break;
		}
	}
}

void MainWindow::setCboRfid(unsigned int aVal){
//	aVal=(0xFFFFFFF0 & aVal);
	int s=ui->cboRFID->count();
	for (int index=0; index<s;index++){
		int v=ui->cboRFID->itemData(index).toInt();
		if (v==aVal) {
			ui->cboRFID->setCurrentIndex(index);
			break;
		}
	}
}


void MainWindow::gotMessage(Message aMsg)
{
    ui->lblProt->setText(QByteArray(aMsg.getProtocoll()).toHex());
    ui->lbltype->setText(aMsg.getHeader().toHex());
    ui->lblParams->setText(aMsg.getParameters().toHex());
    QString txt;
	QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
	Message::qtype atype=aMsg.getType();
	switch (atype){
	case (Message::REPLY_DB):
		switch ((unsigned char)aMsg.getBoard()){
		case Message::MCB:
			switch ((unsigned char)aMsg.getDataBaseType())
			{
			case Message::DP:
				switch(aMsg.getParameters().at(3)){
				case 4:
					setCboConf(aMsg.getDataUInt());
					break;
				case 6:
					ui->btnR2->setText(QString("R(%1)").arg(aMsg.getDataInt() & 0x00ff));
					ui->btnR1->setText(QString("R(%1)").arg(aMsg.getDataInt()>>8));
					break;
				case 7:
					ui->btnR4->setText(QString("R(%1)").arg(aMsg.getDataInt() & 0x00ff));
					ui->btnR3->setText(QString("R(%1)").arg(aMsg.getDataInt()>>8));
					break;
				case 8:
					ui->btnR6->setText(QString("R(%1)").arg(aMsg.getDataInt() & 0x00ff));
					ui->btnR5->setText(QString("R(%1)").arg(aMsg.getDataInt()>>8));
					break;
				case 9:
					ui->btnR8->setText(QString("R(%1)").arg(aMsg.getDataInt() & 0x00ff));
					ui->btnR7->setText(QString("R(%1)").arg(aMsg.getDataInt()>>8));
					break;
				case 10:
					break;
				}
				break;
			case Message::DV:
				break;
			case Message::AP:
				break;
			case Message::AV:
				switch(aMsg.getParameters().at(3)){
					case 0:
						ui->lcdTnkUp->setDecMode();
						ui->lcdTnkUp->display(aMsg.getDataFloat());
						ui->lcdTnkUp->update();
						break;
					case 1:
						ui->lcdTnkDown->setDecMode();
						ui->lcdTnkDown->display(aMsg.getDataFloat());
						ui->lcdTnkDown->update();
						break;
					case 2:
						ui->lcdFridge->setDecMode();
						ui->lcdFridge->display(aMsg.getDataFloat());
						ui->lcdFridge->update();
//						timerTemp->setSingleShot(1000);
						timerTemp->start(1000);
						break;
					default:
						break;
				}
			}
			break;

		case Message::UIB:
			switch (aMsg.getDataBaseType())
			{
				case Message::DP:
					switch(aMsg.getParameters().at(3)){
						case 14:
							setCboRfid(aMsg.getDataUInt());
							break;
					}
					break;
				case Message::DV:/**
				switch(aMsg.getParameters().at(3)){
						case 0:
						case 1:   //Buttonmap
							//toggleButtons(aMsg.getDataUInt());
						case 3:
					}			***/
				case Message::AP:
				case Message::AV:
				default:
					break;
			}
			break;
		}
		break;
	case (Message::REPLY_ERR_COUNT_ACT):
	case (Message::REPLY_ERR_COUNT_HIST):
		txt=QString("Hex:[0x%1] Number of errors:[%2]").arg(hex).arg(aMsg.getDataInt());
		qDebug() << "Meddelande ut:" << aMsg.msg.toHex();
		gotErrorCountMsg(ErrorMessage(aMsg));
		break;
	case (Message::REPLY_ERR_ACT):
	case (Message::REPLY_ERR_HIST):
		txt=QString("Hex:[0x%1]").arg(hex);
		gotErrorMsg(ErrorMessage(aMsg));
		break;
	case (Message::REPLY_REC):
		txt=QString("Hex:[0x%1]").arg(hex);
		break;
	case (Message::METADATA_ANSWER):
		{
			ui->lstMetaData->clear();
			StringMessage sm(aMsg);
			QList <QString> al=sm.getList();
			for (int i=0;i<al.size();i++)
				ui->lstMetaData->addItem(al.at(i));
		}
	break;
	default:
		txt=QString("Hex:[0x%1] String[%2]").arg(hex).arg(QString(data));
		break;
	}
    ui->lblData->setText(txt);
	doMessageQue();
}

void MainWindow::gotErrorCountMsg(ErrorMessage aMsg){
	err_query_number=0;
	if (aMsg.getType()==Message::REPLY_ERR_COUNT_ACT){
		err_act=aMsg.getDataInt();
		queryQue.append(ErrorMessage(Message::ERR_TOTAL_ERRORS_IN_LOG,0));		
		return;
	}
	if (aMsg.getType()==Message::REPLY_ERR_COUNT_HIST){
		err_total=aMsg.getDataInt();
		if(err_act>0){
			err_messages_act.clear();
			err_messages_hist.clear();
			queryQue.append(ErrorMessage(Message::ERR_ACTIVE,0));
		} else if(err_total>0){
			err_messages_act.clear();
			err_messages_hist.clear();
			queryQue.append(ErrorMessage(Message::ERR_HISTORIC,0));
			return;
		}
	}
}

void MainWindow::gotErrorMsg(ErrorMessage aMsg){
	if (aMsg.getType()==Message::REPLY_ERR_ACT){
		err_messages_act.append(aMsg);
		if (err_messages_act.count()<err_act){
			queryQue.append(ErrorMessage(Message::ERR_ACTIVE,++err_query_number));
			return;
		} else {
			ui->lstActiveErrors->clear();
			for (int i=0;i<err_messages_act.count();i++){
				ErrorMessage e=err_messages_act.at(i);
				ui->lstActiveErrors->addItem(e.toString());
			}
			err_query_number=0;
			queryQue.append(ErrorMessage(Message::ERR_HISTORIC,0));
		}
		return;
	}
	if (aMsg.getType()==Message::REPLY_ERR_HIST){
		err_messages_hist.append(aMsg);
		if (err_messages_hist.count()<err_total){
			queryQue.append(ErrorMessage(Message::ERR_HISTORIC,++err_query_number));
			return;
		}
		else
		{
			ui->lstHistoricErrors->clear();
			for (int i=0;i<err_messages_hist.count();i++){
				ErrorMessage e=err_messages_hist.at(i);
				ui->lstHistoricErrors->addItem(e.toString());
			}
		}
	}
}
void MainWindow::on_btnChkErrors_clicked(){

	ui->lstActiveErrors->clear();
	ui->lstHistoricErrors->clear();
	queryQue.append(ErrorMessage(Message::ERR_NUMBER_ACTIVE,0));
	doMessageQue();
}

void MainWindow::on_btnGetKayMappings_clicked(){
	ParameterMsg query1(Message::MCB,Message::DP,6);
	ParameterMsg query2(Message::MCB,Message::DP,7);
	ParameterMsg query3(Message::MCB,Message::DP,8);
	ParameterMsg query4(Message::MCB,Message::DP,9);
	query1.getWord();
	query2.getWord();
	query3.getWord();
	query4.getWord();
	queryQue.append(query1);
	queryQue.append(query2);
	queryQue.append(query3);
	queryQue.append(query4);
	doMessageQue();
}

void MainWindow::on_btnSetTime_clicked(){
	QDateTime dt=QDateTime::currentDateTime();
	ParameterMsg query1(Message::UIB,Message::DV,8);
	ParameterMsg query2(Message::UIB,Message::DV,9);
	ParameterMsg query3(Message::UIB,Message::DV,10);
	qDebug() << query1.setWord(dt.date().year());
	qDebug() << query2.setWord(dt.date().month(),dt.date().day());
	qDebug() << query3.setWord(dt.time().hour(),dt.time().minute());
	queryQue.append(query1);
	queryQue.append(query2);
	queryQue.append(query3);
	qDebug() << query1.setWord(0);
	qDebug() << query2.setWord(0,0);
	qDebug() << query3.setWord(0,0);
	queryQue.append(query1);
	queryQue.append(query2);
	queryQue.append(query3);
	doMessageQue();
}

void MainWindow::doMessageQue(){
	if (init)
		return;
	if (queryQue.length()>0){
        //RJ NO SENDING
        //Message msg=queryQue.takeFirst();
        //wbsd_SERIAL_PORT::instance()->send(msg);
        QString qs=QString("RJ doMessageQue!");
        qDebug () << qs;
	}
}



void MainWindow::on_pushButton_clicked(){
    ui->lblProt->setText("");
    ui->lbltype->setText("");
    ui->lblParams->setText("");
    ui->lblData->setText("");
    QString text=ui->lineEdit->text();
    QByteArray myArr;
    QStringList aList=text.split(";");
    for (int i=0;i<aList.size();i++){
		QString aStr=aList[i].trimmed();
        bool ok=false;
        int x=aStr.toInt(&ok,16);
        myArr[i]=(char)(x & 0xff);
    }
	queryQue.append(Message(myArr));
	doMessageQue();
}

void MainWindow::deviceDiscovered(const QextPortInfo &info){
	int i=0;
	while (i<ui->cboCommand->count()){
		QextPortInfo pi=ui->cboCommand->itemData(i++).value<QextPortInfo>();
		if (info.portName==pi.portName){
			QString qs=QString("%1: Skipped already there").arg(info.portName);
			qDebug () << qs;
			return;
		}
	}
	QString qs=QString("%2:\t %1 [%3:%4] Added").arg(info.friendName).arg(info.portName).arg(info.vendorID).arg(info.productID);
    qDebug () << qs;
	ui->cboCommand->setInsertPolicy(QComboBox::InsertAlphabetically);
	ui->cboCommand->addItem(qs,QVariant::fromValue(info));
	if ((info.vendorID==1003)  && (info.productID==8216)){
		wbsd_SERIAL_PORT::instance()->reconnect(info.portName);
	}
}

void MainWindow::deviceRemoved(const QextPortInfo &info){
	int i=0;
	while (i<ui->cboCommand->count()){
		QextPortInfo pi=ui->cboCommand->itemData(i++).value<QextPortInfo>();
		if (info.portName==pi.portName){
			ui->cboCommand->removeItem(--i);				
			QString qs=QString("%2:\t %1 [%3:%4] Removed").arg(info.friendName).arg(info.portName).arg(info.vendorID).arg(info.productID);
			qDebug () << qs;
		}
	}
	if ((info.vendorID==1003)  && (info.productID==8216)){
		wbsd_SERIAL_PORT::instance()->disconnect();
	}
}
void MainWindow::connected(QString aStr){
	ui->lblData->setText(aStr.replace("\r"," ").remove("\n"));
	//this->repaint();

	qDebug() << aStr;
}



void MainWindow::on_btnRestart_clicked()
{
//P130:0:0:512    REBOOT_UIB
//P129:0:0:4 	REBOOT_MAIN
	ParameterMsg query1(Message::MCB,Message::DV,0);
	ParameterMsg query2(Message::UIB,Message::DV,0);
	qDebug() << query1.setBit(2,1);
	qDebug() << query2.setBit(9,1);
	queryQue.append(query1);
	queryQue.append(query2);
	doMessageQue();


}

void MainWindow::on_btnReset_clicked()
{
	ParameterMsg query1(Message::MCB,Message::DV,0);
	ParameterMsg query2(Message::UIB,Message::DV,0);
	qDebug() << query1.setBit(11,1);
	qDebug() << query2.setBit(10,1);
	queryQue.append(query1);
	queryQue.append(query2);
	doMessageQue();
}



void MainWindow::on_cboConf_activated(int index)
{
	if (init) return;
	ParameterMsg query1(Message::MCB,Message::DP,4);
	ParameterMsg query2(Message::MCB,Message::DP,26);
	ParameterMsg query3(Message::MCB,Message::DP,27);
	int v=ui->cboConf->itemData(index).toInt();
	qDebug() << query1.setWord(v);
	
	int u1=0;
	int u2=0;
	if (v>0){
		u1=u1 | 0xc003;
		u2=u2 | 0xc800;
		if (v && 0xf000){
			u1=u1 | 0x1500;
		}
		if (v && 0x0f00){
			u1=u1 | 0x1a00;
		}
		v=(v & 0x00f0); 
		v=v >> 4;
		if ((v>0) && (v<13)){
			u1=u1 | 0x000c;
			u2=u2 | 0x3000;
		}
	}
	query2.setWord(u1);
	query3.setWord(u2);
	queryQue.append(query1);
	queryQue.append(query2);
	queryQue.append(query3);
	doMessageQue();
}

void MainWindow::on_cboRFID_activated(int index)
{
	if (init) return;
	ParameterMsg query1(Message::UIB,Message::DP,14);
	int v=ui->cboRFID->itemData(index).toInt();
	qDebug() << query1.setWord(v);
	queryQue.append(query1);
	doMessageQue();
}

void MainWindow::on_btnTest_clicked()
{

}

void MainWindow::on_optModeNormal_clicked(bool checked)
{
	if (init) return;
	ParameterMsg query1(Message::UIB,Message::DV,2);
	qDebug() << query1.setNibble(0,1);
	queryQue.append(query1);
	doMessageQue();

}

void MainWindow::on_optModeNurse_clicked(bool checked)
{
	if (init) return;
	ParameterMsg query1(Message::UIB,Message::DV,2);
	qDebug() << query1.setNibble(0,2);
	queryQue.append(query1);
	doMessageQue();

}

void MainWindow::on_optModeCleaner_clicked(bool checked)
{
	if (init) return;
	ParameterMsg query1(Message::UIB,Message::DV,2);
	qDebug() << query1.setNibble(0,3);
	queryQue.append(query1);
	doMessageQue();

}

void MainWindow::on_optModeOperator_clicked(bool checked)
{
	if (init) return;
	ParameterMsg query1(Message::UIB,Message::DV,2);
	qDebug() << query1.setNibble(0,4);
	queryQue.append(query1);
	doMessageQue();
}

void MainWindow::on_optModeService_clicked(bool checked)
{
	if (init) return;
	ParameterMsg query1(Message::UIB,Message::DV,2);
	qDebug() << query1.setNibble(0,5);
	queryQue.append(query1);
	doMessageQue();
}

void MainWindow::on_optModeManufacturer_clicked(bool checked)
{
	if (init) return;
	ParameterMsg query1(Message::UIB,Message::DV,2);
	qDebug() << query1.setNibble(0,6);
	queryQue.append(query1);
	doMessageQue();

}

void MainWindow::on_optModeWBSD_clicked(bool checked)
{
	if (init) return;
	ParameterMsg query1(Message::UIB,Message::DV,2);
	qDebug() << query1.setNibble(0,7);
	queryQue.append(query1);
	doMessageQue();

}

void MainWindow::on_btnLoadMetadata_clicked(){
	//02;B7;A1;60;00;00;00;00;
	Message msg;
	msg.msg[0]=0x02;
	msg.msg[1]=0xb7;
	msg.msg[2]=0xa1;
	msg.msg[3]=0x60;
	msg.msg[4]=0x00;
	msg.msg[5]=0x00;
	msg.msg[6]=0x00;
	msg.msg[7]=0x00;
	queryQue.append(msg);
	doMessageQue();
//	ParameterMsg query1(Message::UIB,Message::DV,2);
//	qDebug() << query1.setNibble(0,7);
//	queryQue.append(query1);
	doMessageQue();
}

void MainWindow::on_btn1_clicked()
{

}
void MainWindow::log(QString aString){
	ui->lstLog->addItem(aString);
}

void MainWindow::on_btnResetLog_clicked(){
	ui->lstLog->clear();
}


void MainWindow::on_btnTestNOV_pressed()
{
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(4,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}

void MainWindow::on_btnTestNOV_released()
{
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(4,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestInletValve_pressed()
{
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(2,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}

void MainWindow::on_btnTestInletValve_released()
{
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(2,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestHeater_pressed()
{
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(3,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}

void MainWindow::on_btnTestHeater_released()
{
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(3,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestWaterPump_pressed()
{
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,16);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(14,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}

void MainWindow::on_btnTestWaterPump_released()
{
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,16);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(14,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}
void MainWindow::on_btnTestAirpump_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(12,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestAirpump_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(12,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestLBIBValve_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(8,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestLBIBValve_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(8,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestLBIBAirValve_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(10,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestLBIBAirValve_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(10,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestRBIBValve_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(9,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestRBIBValve_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(9,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestRBIBAirValve_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(11,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestRBIBAirValve_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(11,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestInstantValve_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(5,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestInstantValve_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(5,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestInstantMixer_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(0,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestInstantMixer_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(0,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestInstantCanister_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,16);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(15,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestInstantCanister_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,16);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(15,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestHowWaterValve_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(14,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestHowWaterValve_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(14,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestColdWaterValve_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(7,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestColdWaterValve_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(7,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestInstantFan_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(6,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestInstantFan_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(6,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestLB2_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,16);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(13,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestLB2_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,16);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(13,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestRB2_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,16);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(12,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestRB2_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,16);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(12,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}

void MainWindow::on_btnTestCooler_pressed(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,1);
    qDebug() << query2.setBit(1,1);
    queryQue.append(query1);
    queryQue.append(query2);
    doMessageQue();
}
void MainWindow::on_btnTestCooler_released(){
    ParameterMsg query1(Message::MCB,Message::DV,2);
    ParameterMsg query2(Message::MCB,Message::DV,15);
    qDebug() << query1.setBit(10,0);
    qDebug() << query2.setBit(1,0);
    queryQue.append(query2);
    queryQue.append(query1);
    doMessageQue();
}



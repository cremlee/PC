#include <QMainWindow>
#include "application.h"
#include "wbsdpaysetcoinchannel.h"
#include "WBSDChildWindow.h"
#include "parametermsg.h"
#include "ui_wbsdpaysetcoinchannel.h"
#include "qdebug.h"
#include "qmessagebox.h"
#include "qmath.h"




WBSDPaySetCoinChannel::WBSDPaySetCoinChannel(int aChannel,int aValue,int decimals, WBSDBaseWindow  *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDPaySetCoinChannel)
{

	this->ui->setupUi(this);
	numberOfDecimals=decimals;

	itsChannel=aChannel;
	itsValue=aValue;
	ui->dblChannelValue->setDecimals(decimals);
	switch (aChannel) {
	case 1:
		ui->lblChannelName->setText("A");
		ui->dblChannelValue->setValue(aValue/qPow(10,numberOfDecimals));
        ui->chkFVToken->hide();
        ui->lblFVToken->hide();
        break;
	case 2:
		ui->lblChannelName->setText("B");
		ui->dblChannelValue->setValue(aValue/qPow(10,numberOfDecimals));
        ui->chkFVToken->hide();
        ui->lblFVToken->hide();
        break;
	case 3:
		ui->lblChannelName->setText("C");
		ui->dblChannelValue->setValue(aValue/qPow(10,numberOfDecimals));
        ui->chkFVToken->hide();
        ui->lblFVToken->hide();
        break;
	case 4:
		ui->lblChannelName->setText("D");
		ui->dblChannelValue->setValue(aValue/qPow(10,numberOfDecimals));
        ui->chkFVToken->hide();
        ui->lblFVToken->hide();
        break;
	case 5:
		ui->lblChannelName->setText("E");
		ui->dblChannelValue->setValue(aValue/qPow(10,numberOfDecimals));
        ui->chkFVToken->hide();
        ui->lblFVToken->hide();
        break;
	case 6:
		ui->lblChannelName->setText("F");
		ui->dblChannelValue->setValue(aValue/qPow(10,numberOfDecimals));
		if (aValue==0){
			ui->chkFVToken->setChecked(true);
			ui->dblChannelValue->setValue(0);
			ui->dblChannelValue->setEnabled(false);
			ui->label->setEnabled(false);
			itsValue=0;
		}
		break;
	}
    /*modify by Lee.Li
     */
    ui->centralwidget->setLayout(ui->gridLayout);
}

void WBSDPaySetCoinChannel::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

WBSDPaySetCoinChannel::~WBSDPaySetCoinChannel()
{
        this->deleteLater();
}

void WBSDPaySetCoinChannel::on_pushButton_clicked(){
}
void WBSDPaySetCoinChannel::on_dblChannelValue_editingFinished(){
	itsValue=ui->dblChannelValue->value()*qPow(10,numberOfDecimals);
}
void WBSDPaySetCoinChannel::gotMessage(Message aMsg){
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DP)){
        switch(aMsg.getParameters().at(3)){
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
				this->close();
                break;
            default:
                break;
        }
    } 
}
void WBSDPaySetCoinChannel::updateData(){
}

void WBSDPaySetCoinChannel::on_btnOK_clicked(){
	QMessageBox::StandardButton reply;

    if(((9+itsChannel) == 15) && (!ui->chkFVToken->isChecked()) && ((int)(ui->dblChannelValue->value()*qPow(10,numberOfDecimals)) == 0))
    {
        QMessageBox::question(this, "Value not Set", "Please Set a Value!!",QMessageBox::Yes);
        return;
    }
    reply = QMessageBox::question(this, "Confirm save", "Do you want to save?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
		int db=9+itsChannel;

		int price=(int)(ui->dblChannelValue->value()*qPow(10,numberOfDecimals));
        if(db == 15 && ui->chkFVToken->isChecked())
        {
            price =0;
        }

		ParameterMsg counterResetMsg(Message::MCB,Message::DP, db,Message::SET_PARAMETER);
		qDebug() << "Price: " << price << " Channel: " << db;
		counterResetMsg.setWord(price);
		itsBaseWindow->addMessageToQue(counterResetMsg);
    }
}
void WBSDPaySetCoinChannel::on_btnCancel_clicked(){
	this->close();
}

void WBSDPaySetCoinChannel::on_chkFVToken_toggled(bool checked)
{
    if (checked){
        //ui->dblChannelValue->setValue(0);
        ui->dblChannelValue->setEnabled(false);
        ui->label->setEnabled(false);
        itsValue=0;
    } else {
        ui->dblChannelValue->setEnabled(true);
        ui->label->setEnabled(true);
        itsValue=0;
    }
}

void WBSDPaySetCoinChannel::closeEvent(QCloseEvent *)
{
    emit iclose();
}

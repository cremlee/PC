#include <QMainWindow>
#include "application.h"
#include "wbsdpaysetprice.h"
#include "WBSDChildWindow.h"
#include "parametermsg.h"
#include "ui_wbsdpaysetprice.h"
#include "qdebug.h"
#include "qmessagebox.h"
#include "qmath.h"




WBSDPaySetPrice::WBSDPaySetPrice(QString aDrinkName,int aDrinkPrice,int aDrinkNumber,int decimals,int tokenVal,WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDPaySetPrice)
{
	this->ui->setupUi(this);
    if(decimals == 2)
    {
        ui->dblPrice->setMaximum(99.99);

    }else
    {
        ui->dblPrice->setMaximum(65535);
    }
	ui->dblPrice->setValue(aDrinkPrice/(qPow(10,decimals)));
	ui->dblPrice->setSingleStep(tokenVal/(qPow(10,decimals)));
	ui->lblButtonNumber->setText(QString("%1").arg(aDrinkNumber));
	ui->lblRecipeName->setText(aDrinkName);
	numberOfDecimals=decimals;
	ui->dblPrice->setDecimals(decimals); 
	itsDrinkName=aDrinkName;
	itsDrinkNumber=aDrinkNumber;
	itsDrinkPrice=aDrinkPrice;
    /*Lee.li Modify 2014-9-24
      fix the screen show
    */

    ui->centralwidget->setLayout(ui->gridLayout);
}

void WBSDPaySetPrice::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

WBSDPaySetPrice::~WBSDPaySetPrice()
{

}

void WBSDPaySetPrice::on_btnOK_clicked(){
	QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm save", "Do you want to save?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
		int db=9+itsDrinkNumber;
		int mult=qPow(10,numberOfDecimals);
        qDebug()<<"ui->dblPrice->value()"<<ui->dblPrice->value()*mult;
        double price =0;
           price=     (ui->dblPrice->value()*mult);
		ParameterMsg counterResetMsg(Message::UIB,Message::DP, db,Message::SET_PARAMETER);
		counterResetMsg.setWord(price);
		itsBaseWindow->addMessageToQue(counterResetMsg);
		ParameterMsg counterResetMsgRead(Message::UIB,Message::DP, db);
		counterResetMsgRead.getWord();
		itsBaseWindow->addMessageToQue(counterResetMsgRead);
		this->close();
    }
}
void WBSDPaySetPrice::on_btnCancel_clicked(){
	this->close();
}
void WBSDPaySetPrice::on_dblPrice_editingFinished(){
}

void WBSDPaySetPrice::gotMessage(Message aMsg){
}
void WBSDPaySetPrice::updateData(){
}

void WBSDPaySetPrice::closeEvent(QCloseEvent *)
{
    emit iclose();
}

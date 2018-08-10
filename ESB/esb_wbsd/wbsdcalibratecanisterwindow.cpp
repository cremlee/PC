#include <QMainWindow>
#include "application.h"
#include "wbsdcalibratecanisterwindow.h"
#include "WBSDChildWindow.h"
#include "parametermsg.h"
#include "ui_wbsdcalibratecanisterwindow.h"
#include "qdebug.h"
#include<QMessageBox>


WBSDCalibrateCanisterwindow::WBSDCalibrateCanisterwindow(int aSpeed, qreal a, WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDCalibrateCanisterwindow)
{
    this->ui->setupUi(this);
	reload(aSpeed);
    ui->centralwidget->setLayout(ui->gridLayout);
    connect(ui->doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(myvalue(double)));
    //this->setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->ui->doubleSpinBox->setEnabled(false);
    this->ui->pushButton->setEnabled(false);
    /*modify by lee
     * if a == 0 ,no min value need to deal with
     * else a max limit need to be set
     *
     */
    if(a==0)
    {
        ui->label_min->setVisible(false);
    }else
    {

        qreal minvalue = (qreal)qRound(a*100) /10;
        ui->label_min->setText(QObject::tr("Min Value:")+QString::number(a*10,'f',1));
        qDebug()<<"minvalue"<<minvalue;
        _minValue = minvalue;
        //ui->doubleSpinBox->setMinimum(minvalue);
    }
}
void WBSDCalibrateCanisterwindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDCalibrateCanisterwindow::reload(int aSpeed){
	theSpeed=aSpeed;
    _isdone = false;
	if (theSpeed==1){
		ParameterMsg msg1(Message::MCB,Message::AP,24);
        msg1.getFloat();
		itsBaseWindow->addMessageToQue(msg1);
   } else if (theSpeed==2){
		ParameterMsg msg1(Message::MCB,Message::AP,25);
        msg1.getFloat();
		itsBaseWindow->addMessageToQue(msg1);
   } else {
		ParameterMsg msg1(Message::MCB,Message::AP,26);
        msg1.getFloat();
		itsBaseWindow->addMessageToQue(msg1);
   }



    ParameterMsg gmsg1(Message::MCB,Message::DV,ParameterMsg::SET_PARAMETER);
	gmsg1.setNibble(0,theSpeed);
	itsBaseWindow->addMessageToQue(gmsg1);
	updateData();

}
void WBSDCalibrateCanisterwindow::updateData()
{
    qDebug() << "WBSDInstantWindow::updateData";
    ParameterMsg msg1(Message::MCB,Message::DV,17);
	msg1.getWord();
    itsBaseWindow->addMessageToQue(msg1);
}

void WBSDCalibrateCanisterwindow::closeEvent(QCloseEvent *)
{
    ParameterMsg gmsg1(Message::MCB,Message::DV,ParameterMsg::SET_PARAMETER);
    gmsg1.setNibble(0,0);
    itsBaseWindow->addMessageToQue(gmsg1);
    theSpeed=0;
    emit iclose();
}

void WBSDCalibrateCanisterwindow::gotMessage(Message aMsg)
{
    QString txt;
    char aLevelState;
    unsigned int aVal;
    char aRfgState;
    QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
    Message::qtype atype=aMsg.getType();
	switch (atype){
	    case (Message::REPLY_DB):
			switch ((unsigned char)aMsg.getBoard()){
			case Message::MCB:
				switch ((unsigned char)aMsg.getDataBaseType())
				{

				 case Message::AP:
					switch(aMsg.getParameters().at(3)){
						case 24:
							if (theSpeed=1)
								this->ui->doubleSpinBox->setValue(aMsg.getDataFloat()*10);
							break;
						case 25:
							if (theSpeed=2)
								this->ui->doubleSpinBox->setValue(aMsg.getDataFloat()*10);
							break;
						case 26:
							if (theSpeed=3)
								this->ui->doubleSpinBox->setValue(aMsg.getDataFloat()*10);
							break;
					}
					break;
				 case Message::DV:
					switch(aMsg.getParameters().at(3)){
						case 17:
							int adata= aMsg.getDataInt() & 0x000F;
                            qDebug()<<"dv17 value ="<<adata;
							if ((adata<8) && (adata>0)){
                                this->ui->doubleSpinBox->setEnabled(false);
                                this->ui->pushButton->setEnabled(true);
							} else if (adata>8){
                                this->ui->doubleSpinBox->setEnabled(false);
                                this->ui->pushButton->setEnabled(false);

							} else {
								this->ui->doubleSpinBox->setEnabled(true);
								this->ui->pushButton->setEnabled(true);
							}
							if (theSpeed>0){
								QTimer::singleShot(500,this,SLOT(updateData()));
							}
							break;
					}
					break;

			}
    }
	}
}
WBSDCalibrateCanisterwindow::~WBSDCalibrateCanisterwindow()
{

    delete ui;
}



void WBSDCalibrateCanisterwindow::on_pushButton_clicked()
{
        ParameterMsg gmsg1(Message::MCB,Message::DV,ParameterMsg::SET_PARAMETER);
		gmsg1.setNibble(0,0);
		itsBaseWindow->addMessageToQue(gmsg1);
        if (theSpeed==1){
            ParameterMsg msg1(Message::MCB,Message::AP,24,ParameterMsg::SET_PARAMETER);
            msg1.setFloat(this->ui->doubleSpinBox->value()/10);
            itsBaseWindow->addMessageToQue(msg1);
       } else if (theSpeed==2){
            ParameterMsg msg1(Message::MCB,Message::AP,25,ParameterMsg::SET_PARAMETER);
            msg1.setFloat(this->ui->doubleSpinBox->value()/10);
            itsBaseWindow->addMessageToQue(msg1);
       } else {
            ParameterMsg msg1(Message::MCB,Message::AP,26,ParameterMsg::SET_PARAMETER);
            msg1.setFloat(this->ui->doubleSpinBox->value()/10);
            itsBaseWindow->addMessageToQue(msg1);
       }

        if (theSpeed==1){
            ParameterMsg gmsg1(Message::MCB,Message::AP,24);
            gmsg1.getWord();
            itsBaseWindow->addMessageToQue(gmsg1);
       } else if (theSpeed==2){
            ParameterMsg gmsg1(Message::MCB,Message::AP,25);
            gmsg1.getWord();
            itsBaseWindow->addMessageToQue(gmsg1);
       } else {
            ParameterMsg ggmsg1(Message::MCB,Message::AP,26);
            ggmsg1.getWord();
            itsBaseWindow->addMessageToQue(ggmsg1);
       }
		theSpeed=0;
        _isdone =true;
		this->close();
}

void WBSDCalibrateCanisterwindow::on_doubleSpinBox_editingFinished()
{

    if(this->ui->doubleSpinBox->value() < _minValue)
    {
        QMessageBox::warning(this,QObject::tr("Warning"),QObject::tr("Calibration value is out of range,it will be over written by min-value,Be aware that the actual dosing won't be in line with the setting."),QMessageBox::Ok);
        this->ui->doubleSpinBox->setValue(_minValue);
    }


}

void WBSDCalibrateCanisterwindow::myvalue(double a)
{
    if(itsBaseWindow->getUnitTmp()==0)
    {
        //ui->label->setText("");
    }else
    {
        //ui->label->setText(QString().sprintf("%.3f  oz",a/28.35));
    }
}

void WBSDCalibrateCanisterwindow::on_btn_close_clicked()
{
    ParameterMsg gmsg1(Message::MCB,Message::DV,ParameterMsg::SET_PARAMETER);
    gmsg1.setNibble(0,0);
    itsBaseWindow->addMessageToQue(gmsg1);
    theSpeed=0;
    this->close();
}

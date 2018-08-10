#include "wbsdinstantwindow.h"
#include "ui_wbsdinstantwindow.h"
#include "qdebug.h"
#include "wbsdchildwindow.h"
#include "application.h"
#include "wbsdcalibratecanisterwindow.h"
#include"QMessageBox"
#include<QCloseEvent>
/*momify by lee
 * add calibration min value
 * modify the creater of calibrationwindow class ,add one input param
 * instant conf = milk ,choco  enable this function
 * calc the  max gram value of all relation recipe(according to the instant conf)
 * calc the 50,75,100 value ,show it in the windows
 * do the calibration ,if the actual value is smaller the the value  I calc.show the warning msg and overwrite it with the calc value.
 *when this win closed do the value compare.if the value is not correct give
 *the warning msg
 *change the text in the calibration so it is more clear that the calibration must be done with a full instant auger
 */
#define CANISTER_MIN_50(a)  a/90*50
#define CANISTER_MIN_75(a)  a/90*75
#define CANISTER_MIN_100(a)  a/90*100
WBSDInstantWindow::WBSDInstantWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDInstantWindow)
{
    stylelock="border-image: url(:/mainpics/update.png); border: 0px;";
    theCalWindow=0;
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_instant", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_instant",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));


/*
 * DP4 -- get instant conf
 */
    Canister_Min_Value =0;
    Canister_Min_Value_50 =0;
    Canister_Min_Value_75 =0;
    Canister_Min_Value_100 =0;
    Canister_Crt_Value_50 =0;
    Canister_Crt_Value_75 =0;
    Canister_Crt_Value_100=0;

    ui->label_min_title_4->setVisible(false);
    ui->label_min_50->setVisible(false);
    ui->label_min_75->setVisible(false);
    ui->label_min_100->setVisible(false);
    ParameterMsg msg4(Message::MCB,Message::DP,4);
    msg4.getWord();
    itsBaseWindow->addMessageToQue(msg4);

    ParameterMsg msg1(Message::MCB,Message::DP,0);
    msg1.getWord();
    itsBaseWindow->addMessageToQue(msg1);


    ParameterMsg query(Message::MCB,Message::AP, 24);
    query.getFloat();
    itsBaseWindow->addMessageToQue(query);

	updateData();
    ui->centralwidget->setLayout(ui->verticalLayout);
    ui->label_12->hide();
    ui->spIngVolGr->hide();

}

WBSDInstantWindow::~WBSDInstantWindow()
{
    delete ui;
}
bool floastIsSmall(qreal a1,qreal a2)
{
    qDebug()<<"a1========"<<a1;
    qDebug()<<"a2========"<<a2;
    if(a2-a1>0.01) return true;
    return false;
}

void WBSDInstantWindow::closeEvent(QCloseEvent* evt)
{
    //if(Canister_Min_Value!=0 &&(Canister_Crt_Value_50<Canister_Min_Value_50 || Canister_Crt_Value_75<Canister_Min_Value_75||Canister_Crt_Value_100<Canister_Min_Value_100))
    if(Canister_Min_Value!=0 &&(floastIsSmall(Canister_Crt_Value_50,Canister_Min_Value_50) || floastIsSmall(Canister_Crt_Value_75,Canister_Min_Value_75)||floastIsSmall(Canister_Crt_Value_100,Canister_Min_Value_100)))

    {
        QMessageBox::StandardButton button;
        button = QMessageBox::question(this, tr("Waring"),
            QString(tr("Warning：Canister Value is out of range,it will be overwritten by the min-value ,do you want to quit?")),
            QMessageBox::Yes | QMessageBox::No);

        if (button == QMessageBox::No) {
            //event->ignore();  //忽略退出信号，程序继续运行
            evt->ignore();
        }
        else if (button == QMessageBox::Yes) {

            adjustthecalibrationvalue();
            emit iclose();
            evt->accept();
        }
    }
}

void WBSDInstantWindow::adjustthecalibrationvalue()
{
   if (Canister_Crt_Value_50<Canister_Min_Value_50)
   {
       ParameterMsg msg1(Message::MCB,Message::AP,24,ParameterMsg::SET_PARAMETER);
       msg1.setFloat(Canister_Min_Value_50+0.001);
       itsBaseWindow->addMessageToQue(msg1);
   }
   if (Canister_Crt_Value_75<Canister_Min_Value_75)
   {
       ParameterMsg msg1(Message::MCB,Message::AP,25,ParameterMsg::SET_PARAMETER);
       msg1.setFloat(Canister_Min_Value_75+0.001);
       itsBaseWindow->addMessageToQue(msg1);
   }
   if (Canister_Crt_Value_100<Canister_Min_Value_100)
   {
       ParameterMsg msg1(Message::MCB,Message::AP,26,ParameterMsg::SET_PARAMETER);
       msg1.setFloat(Canister_Min_Value_100+0.001);
       itsBaseWindow->addMessageToQue(msg1);
   }
}

void WBSDInstantWindow::on_menuBack_triggered()
{
    this->close();    
}

void WBSDInstantWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDInstantWindow::on_instantWaterVal_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,1);
    message2.setBit(5,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDInstantWindow::on_instantWaterVal_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,0);
    message2.setBit(5,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDInstantWindow::on_instantMixer_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,1);
    message2.setBit(0,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDInstantWindow::on_instantMixer_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,0);
    message2.setBit(0,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDInstantWindow::on_instantCanister_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,1);
    message2.setBit(15,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDInstantWindow::on_instantCanister_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,0);
    message2.setBit(15,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDInstantWindow::on_instantFan_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,1);
    message2.setBit(6,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDInstantWindow::on_instantFan_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,0);
    message2.setBit(6,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDInstantWindow::updateData()
{
    qDebug() << "WBSDInstantWindow::updateData";

	ParameterMsg query1=ParameterMsg(Message::MCB,Message::AP, 24);
	ParameterMsg query2=ParameterMsg(Message::MCB,Message::AP, 25);
	ParameterMsg query3=ParameterMsg(Message::MCB,Message::AP, 26);
	ParameterMsg query4=ParameterMsg(Message::MCB,Message::AP, 27);
	query1.getFloat();
	query2.getFloat();
	query3.getFloat();
	query4.getFloat();
	itsBaseWindow->addMessageToQue(query1);
	itsBaseWindow->addMessageToQue(query2);
	itsBaseWindow->addMessageToQue(query3);
	itsBaseWindow->addMessageToQue(query4);

}

void WBSDInstantWindow::gotMessage(Message aMsg)
{
    QString txt;
    char aLevelState;
    unsigned int aVal;
    char aRfgState;
    QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
    Message::qtype atype=aMsg.getType();
	ParameterMsg query(Message::MCB,Message::AP, 25);
    char instant_confVal=0;
	switch (atype){
	    case (Message::REPLY_DB):
			switch ((unsigned char)aMsg.getBoard()){
			case Message::MCB:
				switch ((unsigned char)aMsg.getDataBaseType())
				{

                case Message::DP:
                    if(aMsg.getParameters().at(3)==0)
                    {
                        aVal=aMsg.getDataUInt();
                        qDebug()<<"(0x8000 & aVal) >> 15"<<((0x8000 & aVal) >> 15);
                        itsBaseWindow->setUnitTmp((0x8000 & aVal) >> 15);
                    }
                    /*
                     * bit 4-7 = instant_conf
                     */
                    if(aMsg.getParameters().at(3)==4)
                    {
                        aVal=aMsg.getDataUInt();
                        instant_confVal = ((aVal>>4) & 0x0f);
                        if(instant_confVal == 6 || instant_confVal == 8)
                        {
                            if(itsBaseWindow->getMachineUnit() ==WBSDBaseWindow::UNIT_USA)
                            {
                                break;
                            }
                            GetCanisterMinValue(instant_confVal);
                        }
                    }
                    break;
				 case Message::DV:
					switch(aMsg.getParameters().at(3)){

					case 1:
						aVal=aMsg.getDataUInt();
						break;
					case 2:
						aVal=aMsg.getDataUInt();
						if (myTimer!=0)
							myTimer->singleShot(500,this,SLOT(updateData()));
						 break;

					}
					break;
				case Message::AP:
					switch(aMsg.getParameters().at(3)){
						case 24:
                           // if(itsBaseWindow->getUnitTmp()==0)
                            //{
                                Canister_Crt_Value_50 = aMsg.getDataFloat();
                                this->ui->lblCal50->setText(QString().sprintf("%2.1f gram/sec",Canister_Crt_Value_50));

//                            }else
//                            {
//                                this->ui->lblCal50->setText(QString().sprintf("%2.1f gram/sec    %2.3f oz/sec",aMsg.getDataFloat(),aMsg.getDataFloat()/28.35));

//                            }

                            break;
						case 25:
                        //if(itsBaseWindow->getUnitTmp()==0)
                        //{
                        Canister_Crt_Value_75 = aMsg.getDataFloat();
                            this->ui->lblCal75->setText(QString().sprintf("%2.1f gram/sec",Canister_Crt_Value_75));

                        //}else
                        //{
                            //this->ui->lblCal75->setText(QString().sprintf("%2.3f oz/sec",aMsg.getDataFloat()/28.35));
                           // this->ui->lblCal75->setText(QString().sprintf("%2.1f gram/sec    %2.3f oz/sec",aMsg.getDataFloat(),aMsg.getDataFloat()/28.35));

                        //}
                        break;
						case 26:
                        //if(itsBaseWindow->getUnitTmp()==0)
                        //{
                            Canister_Crt_Value_100 = aMsg.getDataFloat();
                            this->ui->lblCal100->setText(QString().sprintf("%2.1f gram/sec",Canister_Crt_Value_100));

                       // }else
                       // {
                            //this->ui->lblCal100->setText(QString().sprintf("%2.3f oz/sec",aMsg.getDataFloat()/28.35));
                           // this->ui->lblCal100->setText(QString().sprintf("%2.1f gram/sec    %2.3f oz/sec",aMsg.getDataFloat(),aMsg.getDataFloat()/28.35));

                       // }
                            break;
						case 27:
							this->ui->spIngVolGr->setValue(aMsg.getDataFloat());
							break;
						default:
							break;
					}

					break;
				case Message::AV:
					switch(aMsg.getParameters().at(3)){
						case 0:
							break;
						default:
							break;
					}
				}
				break;

			}
    }
}
void WBSDInstantWindow::on_spIngVolGr_editingFinished()
{
    ParameterMsg query(Message::MCB,Message::AP, 27, Message::SET_PARAMETER);
    query.setFloat(this->ui->spIngVolGr->value());
    itsBaseWindow->addMessageToQue(query);
}

void WBSDInstantWindow::on_btnCal50_clicked()
{
    if (theCalWindow==0)    {
        theCalWindow = new WBSDCalibrateCanisterwindow(1,Canister_Min_Value_50,itsBaseWindow);
    } else {
        theCalWindow->reload(1);
    }
    _crtspeed =1;
   theCalWindow->setWindowModality(Qt::ApplicationModal);
   theCalWindow->show();
   connect(theCalWindow,SIGNAL(iclose()),this,SLOT(test()));

}

void WBSDInstantWindow::on_btnCal75_clicked()
{
    if (theCalWindow==0)    {
        theCalWindow = new WBSDCalibrateCanisterwindow(2,Canister_Min_Value_75,itsBaseWindow);
    } else {
        theCalWindow->reload(2);
    }
    _crtspeed =2;
   theCalWindow->setWindowModality(Qt::ApplicationModal);
   theCalWindow->show();
   connect(theCalWindow,SIGNAL(iclose()),this,SLOT(test()));
}

void WBSDInstantWindow::on_btnCal100_clicked()
{
    if (theCalWindow==0)    {
        theCalWindow = new WBSDCalibrateCanisterwindow(3,Canister_Min_Value_100,itsBaseWindow);
    } else {
        theCalWindow->reload(3);
    }
    _crtspeed =3;
   theCalWindow->setWindowModality(Qt::ApplicationModal);
   theCalWindow->show();
   connect(theCalWindow,SIGNAL(iclose()),this,SLOT(test()));
}

void WBSDInstantWindow::test()
{
    this->hide();

    if(theCalWindow->isworked())
    {
    if(_crtspeed ==1) ui->lb_img1->setStyleSheet(stylelock);
    if(_crtspeed ==2) ui->lb_img2->setStyleSheet(stylelock);
    if(_crtspeed ==3) ui->lb_img3->setStyleSheet(stylelock);
    }
    theCalWindow =0;
    this->show();
}
//Get the min value of canister
qreal WBSDInstantWindow::GetCanisterMinValue(int canconf)
{
   qreal instantval=0;
   QList<int> rcplst=DataBaseHelper::getInstance()->GetCurrentValidRcp("100",canconf);
   Recipe *rcptmp;
   foreach (int item,rcplst) {
       rcptmp = new Recipe();
       DataBaseHelper::getInstance()->loadRecipe(rcptmp,item);
       qreal valtmp = rcptmp->instant_gram_max/(((rcptmp->instant_percent*rcptmp->instant_ingredient_rtd_standard/100-rcptmp->instant_gram_max)/rcptmp->instant_water_flow)-0.2);
       instantval = instantval>valtmp?instantval:valtmp;
       qDebug()<<"RCPID ="<<rcptmp->id <<"instantval ="<<instantval;
   }
   qDebug()<<"instantval = "<<instantval;
   Canister_Min_Value = instantval;

   ui->label_min_title_4->setVisible(true);
   ui->label_min_50->setVisible(true);
   ui->label_min_75->setVisible(true);
   ui->label_min_100->setVisible(true);
   Canister_Min_Value_50 = CANISTER_MIN_50(Canister_Min_Value);
   Canister_Min_Value_75 = CANISTER_MIN_75(Canister_Min_Value);
   Canister_Min_Value_100 = CANISTER_MIN_100(Canister_Min_Value);
   ui->label_min_50->setText(QString::number(Canister_Min_Value_50,'f',1)+" grams/sec");
   ui->label_min_75->setText(QString::number(Canister_Min_Value_75,'f',1)+" grams/sec");
   ui->label_min_100->setText(QString::number(Canister_Min_Value_100,'f',1)+" grams/sec");
}

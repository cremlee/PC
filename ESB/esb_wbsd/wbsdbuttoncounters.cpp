#include "WBSDButtoncounters.h"
#include "ui_WBSDButtoncounters.h"
#include "wbsdchildwindow.h"
#include "parametermsg.h"
#include "qdebug.h"
#include "application.h"

WBSDButtonCounters::WBSDButtonCounters(int button,WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDButtonCounters)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_buttoncounter", "Back")
    };
	
    ui->setupUi(this);
    static double oz_tmp = 33.814;
    static int gal_tmp=128;
    menuBack = new QAction(Application::translate("back_buttoncounter",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
	
	itsButton=button;
	updateData();
    this->setWindowTitle(QObject::tr("Button %1 Counters").arg(button));
    ui->centralwidget->setLayout(ui->gridLayout);
    if(itsBaseWindow->getUnitTmp() == 0)
    {
        ui->lblUnitLiters0->setText(QObject::tr("Litres"));
        ui->lblUnitLiters1->setText(QObject::tr("Litres"));
        ui->lblUnitLiters3->setText(QObject::tr("Litres"));
        ui->lblUnitLiters4->setText(QObject::tr("Litres"));
        ui->lblUnitLiters5->setText(QObject::tr("Litres"));
        ui->lblUnitLiters6->setText(QObject::tr("Litres"));
        ui->lblUnitLiters7->setText(QObject::tr("Litres"));
        ui->lblUnitLiters8->setText(QObject::tr("Litres"));
    }else
    {
        ui->lblUnitLiters0->setText(QObject::tr("Gallons"));
        ui->lblUnitLiters1->setText(QObject::tr("Gallons"));
        ui->lblUnitLiters3->setText(QObject::tr("Gallons"));
        ui->lblUnitLiters4->setText(QObject::tr("Gallons"));
        ui->lblUnitLiters5->setText(QObject::tr("Gallons"));
        ui->lblUnitLiters6->setText(QObject::tr("Gallons"));
        ui->lblUnitLiters7->setText(QObject::tr("Gallons"));
        ui->lblUnitLiters8->setText(QObject::tr("Gallons"));
    }
}

	WBSDButtonCounters::~WBSDButtonCounters()
{
    delete ui;
}

void WBSDButtonCounters::on_menuBack_triggered()
{
    qDebug()<<"buttonCount parent="<<this->parent();

    this->close();
}

void WBSDButtonCounters::updateData()
{
	for (int i=0;i<=25;i++){
		qDebug() << QString("Läser %1").arg((itsButton-1)*26+28+i);
		ParameterMsg msg(Message::MCB,Message::AP,(itsButton-1)*26+28+i);
        msg.getFloat();
		itsBaseWindow->addMessageToQue(msg);
	}
}

void WBSDButtonCounters::connectionStatusChanged(int aStatus,StringMessage aMSG){
	itsBaseWindow->disconnectToMessages(this);
	if(aStatus<20)
    {
        isblockiclose =true;
        this->close();
        this->deleteLater();
    }
}

void WBSDButtonCounters::closeEvent(QCloseEvent *)
{
    if(!isblockiclose)
    emit iclose();
    emit destroyed(itsButton);
}

void WBSDButtonCounters::gotMessage(Message aMsg){

	if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::AP)){
		unsigned char index=aMsg.getParameters().at(3);
		qDebug() << "Errmsg:" << (index - ((itsButton-1)*26)-28) << " <-- " << index;
		switch(index - ((itsButton-1)*26)-28){
			case 0:
                updateSmallMild(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 1:
                updateSmallNormal(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 2:
                updateSmallStrong(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 3:
                updateMediumMild(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 4:
                updateMediumNormal(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 5:
                updateMediumStrong(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 6:
                updateLargeMild(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 7:
                updateLargeNormal(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 8:
                updateLargeStrong(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 9:
                updateFFLWMild(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()/128));
				break;
			case 10:
                updateFFLWNormal(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()/128));
				break;
			case 11:
                updateFFLWStrong(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()/128));
				break;
			case 12:
                updateRTDVol(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()/128));
				break;
			case 13:
                updateSmallMildNr(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 14:
                updateSmallNormalNr(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 15:
                updateSmallStrongNr(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()));
				break;
			case 16:


                ui->mediumMildNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat())));
				break;
			case 17:
                ui->mediumNormalNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat())));
				break;
			case 18:
                ui->mediumStrongNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat())));
				break;
			case 19:
                ui->largeMildNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat())));
				break;
			case 20:
                ui->largeNormalNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat())));
				break;
			case 21:
                ui->largeStrongNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat())));
				break;
			case 22:
                ui->fflwMildNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()/128)));
				break;
			case 23:
                ui->fflwNormalNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()/128)));
				break;
			case 24:
                ui->fflwStrongNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()/128)));
				break;
			case 25:
                ui->rtdVolNr->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat():aMsg.getDataFloat()/128)));
				break;
			default:
				break;
		}
	}


}



void WBSDButtonCounters::updateSmallMild(float volCount)
{
    ui->smallMild->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateSmallNormal(float volCount)
{
    ui->smallNormal->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateSmallStrong(float volCount)
{
    ui->smallStrong->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateMediumMild(float volCount)
{
    ui->mediumMild->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateMediumNormal(float volCount)
{
    ui->mediumNormal->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateMediumStrong(float volCount)
{
    ui->mediumStrong->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateLargeMild(float volCount)
{
    ui->largeMild->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateLargeNormal(float volCount)
{
    ui->largeNormal->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateLargeStrong(float volCount)
{
    ui->largeStrong->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateFFLWMild(float volCount)
{
    ui->fflwMild->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateFFLWNormal(float volCount)
{
    ui->fflwNormal->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateFFLWStrong(float volCount)
{
    ui->fflwStrong->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateRTDVol(float volCount)
{
    ui->rtdVol->setText(QString::number(volCount));
}




void WBSDButtonCounters::updateSmallMildNr(float volCount)
{
    ui->smallMildNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateSmallNormalNr(float volCount)
{
    ui->smallNormalNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateSmallStrongNr(float volCount)
{
    ui->smallStrongNr->setText(QString::number(volCount));
}


void WBSDButtonCounters::updateMediumMildNr(float volCount)
{
    ui->mediumMildNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateMediumNormalNr(float volCount)
{
    ui->mediumNormalNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateMediumStrongNr(float volCount)
{
    ui->mediumStrongNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateLargeMildNr(float volCount)
{
    ui->largeMildNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateLargeNormalNr(float volCount)
{
    ui->largeNormalNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateLargeStrongNr(float volCount)
{
    ui->largeStrongNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateFFLWMildNr(float volCount)
{
    ui->mediumStrongNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateFFLWNormaldNr(float volCount)
{
    ui->largeMildNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateFFLWStrongNr(float volCount)
{
    ui->largeNormalNr->setText(QString::number(volCount));
}

void WBSDButtonCounters::updateRTDVolNr(float volCount)
{
    ui->largeStrongNr->setText(QString::number(volCount));
}


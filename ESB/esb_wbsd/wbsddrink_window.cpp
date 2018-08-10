#include "wbsddrink_window.h"
#include "ui_wbsddrink_window.h"
#include "wbsdchildwindow.h"
#include "parametermsg.h"
#include "qdebug.h"
#include "application.h"
#include "databasehelper.h"
#include <QMessageBox>
#include "rcpmessage.h"
#define FMU_ON
/*modify by Lee
make USA only oz in RTD
unit change 0.1 oz = 3 ml  / 1oz = 29ml  / 10oz=295ml

*/
static ushort oz_ge =  3;
static ushort oz_shi = 29;
static ushort oz_bai = 295;

int oz2ml(float a)
{
    float tmp = a*10;
    int myoz =0;
    if((tmp-(int)tmp)>=0.5)
    {
        myoz = (int)tmp +1;
    }
    else
    {
        myoz = (int)tmp;
    }


    qDebug()<<"Current oz *10 = "<<myoz;
    int ozge  = myoz%10;
    int ozshi = ((myoz%100) /10);
    int ozbai = myoz/100;
    qDebug()<<"Current ozge = "<<ozge;
    qDebug()<<"Current ozshi = "<<ozshi;
    qDebug()<<"Current ozbai = "<<ozbai;
    return ozge*oz_ge+oz_shi*ozshi+ozbai*oz_bai;

}

float ml2oz(int a)
{
    int ml_295 = a/295;
    a  = a-295*ml_295;
    int ml_29 = a/29;
    a = a-29*ml_29;
    int ml_3 = a/3;
    return ml_295*10+ml_29+(float)ml_3/10;
}

WBSDDrink_Window::WBSDDrink_Window(int button,WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDDrink_Window)
{
    static const char* back[] = {
            QT_TRANSLATE_NOOP("back_drinkbutton", "Back")
        };

	itsRecipe=new Recipe();
    ui->setupUi(this);
#ifndef FMU_ON
    QLayoutItem *child;
        while(child=this->ui->verticalLayout_2->layout()->takeAt(0)) {
            delete child;
        }
    ui->tb_main->removeTab(3);
#endif
    fmurcpwin =0;
   //qDebug()<<"mychange ="<< ml2oz(oz2ml(13.199999999999));
    menuBack = new QAction(Application::translate("back_drinkbutton",back[0]), this);
    menuBack->setEnabled(true);
    //ui->tb_fmu->setEnabled(false);
    setEnableFmu (false);
    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    ParameterMsg msg14(Message::MCB,Message::DP,26);
    msg14.getWord();
    itsBaseWindow->addMessageToQue(msg14);

    ParameterMsg msg1(Message::MCB,Message::DP,0);
    msg1.getWord();
    itsBaseWindow->addMessageToQue(msg1);
    ParameterMsg query(Message::MCB,Message::DP, 2);
    query.getWord();
    itsBaseWindow->addMessageToQue(query);

    ParameterMsg query1(Message::MCB,Message::AP, 27);
    query1.getWord();
    itsBaseWindow->addMessageToQue(query1);


    isVisible=true;
    reload(button);
    ui->centralwidget->setLayout(ui->gridLayout);


    connect(ui->tb_main,SIGNAL(currentChanged(int)),this,SLOT(tabwidgetchange(int)));
    ui->tb_main->setCurrentIndex(0);
    ui->sp_fmu_per->setEnabled(false);
//    ui->cb_fmu_id->addItem(tr("hot wet"),1);
//    ui->cb_fmu_id->addItem(tr("hot dry"),2);
//    ui->cb_fmu_id->addItem(tr("cold dry"),3);
//    ui->cb_fmu_id->addItem(tr("cold wet"),4);

    ui->cb_fmu_id->addItem(tr("Cafe au lait/Cafe au lait sugar"),15);
    ui->cb_fmu_id->addItem(tr("Cafe au lait foam"),35);
    ui->cb_fmu_id->addItem(tr("Cappuccino/Cappuccino sugar"),13);
    ui->cb_fmu_id->addItem(tr("Coffee milk/Weiner Melange"),22);
    ui->cb_fmu_id->addItem(tr("Hot milk"),2);
    ui->cb_fmu_id->addItem(tr("Hot milk foamed"),33);
    ui->cb_fmu_id->addItem(tr("Latte"),25);
    ui->cb_fmu_id->addItem(tr("Latte macchiato"),17);
    ui->cb_fmu_id->addItem(tr("Choco de luxe (instant choco)"),36);
    ui->cb_fmu_id->addItem(tr("Wiener melange (instant choco)"),37);
    /*modify by Lee
    1:USA selected: not confirm.
    2:Other selected: oz not show.

    */
    if(itsBaseWindow->getMachineUnit() ==WBSDBaseWindow::UNIT_USA)
    {
        ui->spLBibAirpump->hide();
        ui->lblLBibAirpump->hide();
        ui->spRBibAirpump->hide();
        ui->lblRBibAirpump->hide();
    }
    else
    {

        ui->lbl_s->hide();
        ui->lbl_m->hide();
        ui->lbl_l->hide();
        ui->label_3->hide();
        ui->label_4->hide();
    }
    ui->lbl_s->hide();
    ui->lbl_m->hide();
    ui->lbl_l->hide();
    ui->label_3->hide();
    ui->label_4->hide();


}

WBSDDrink_Window::~WBSDDrink_Window()
{
    delete ui;
	delete itsRecipe;
	delete menuBack;
}

void WBSDDrink_Window::reload(){
int itsDb;
	int itsHiLo;
	switch (itsButton){
	case 1:
			itsDb=6;
			itsHiLo=1;
			break;
	case 2:
			itsDb=6;
			itsHiLo=0;
			break;
	case 3:
			itsDb=7;
			itsHiLo=1;
			break;
	case 4:
			itsDb=7;
			itsHiLo=0;
			break;
	case 5:
			itsDb=8;
			itsHiLo=1;
			break;
	case 6:
			itsDb=8;
			itsHiLo=0;
			break;
	case 7:
			itsDb=9;
			itsHiLo=1;
			break;
	case 8:
			itsDb=9;
			itsHiLo=0;
			break;
	}
	ParameterMsg query(Message::MCB,Message::DP, itsDb , Message::SET_PARAMETER);
	query.setChar(itsHiLo,(char)itsRecipe->getId() & 0x00FF);
    itsBaseWindow->addMessageToQue(query);
}

void WBSDDrink_Window::tabwidgetchange(int index)
{

    switch (index) {
    case 0:
        ui->tb_main->currentWidget()->setLayout(ui->tbw0);
        break;
    case 1:
        ui->tb_main->currentWidget()->setLayout(ui->tbw1);
        break;
    case 2:
        ui->tb_main->currentWidget()->setLayout(ui->tbw2);
        break;
    default:
        break;
    }

}

void WBSDDrink_Window::destroywin()
{
    fmurcpwin =0;
}

void WBSDDrink_Window::fmurcpchange(int i)
{
    for(int j=0;j<ui->cb_fmu_id->count();j++)
    {
        if(i == ui->cb_fmu_id->itemData(j).toInt())
        {
            this->ui->cb_fmu_id->setCurrentIndex(j);
            break;
        }
    }

    itsRecipe->fmu_id = i;
}

void WBSDDrink_Window::reload(int button)
{
	isVisible=true;
	isNewDrink=false;
    itsButton=button;
	if (button==7){
		DataBaseHelper::getInstance()->populateValidRecipes("100",ui->cboRecipe,70,0,0);
	}
	else if (button==8){
		DataBaseHelper::getInstance()->populateValidRecipes("100",ui->cboRecipe,80,0,0);
	} else {
		ParameterMsg msg0(Message::MCB,Message::DP, 4);
		msg0.getWord();
		itsBaseWindow->addMessageToQue(msg0);
	}

	int itsDb;
	switch (itsButton){
	case 1:
	case 2:
			itsDb=6;
			break;
	case 3:
	case 4:
			itsDb=7;
			break;
	case 5:
	case 6:
			itsDb=8;
			break;
	case 7:
	case 8:
			itsDb=9;
			break;

	}

	this->ui->spLBibPercentOfDrink->setMaximum(100);
	this->ui->spLBibPercentOfDrink->setMinimum(0);

	ParameterMsg msg1(Message::MCB,Message::DP, itsDb);
	msg1.getWord();
	itsBaseWindow->addMessageToQue(msg1);

	this->ui->btnSetDefault->setVisible(false);

	setEnableRTDGrp(false);
	setEnableLBIBGrp(false);
	setEnableRBIBGrp(false);
	setEnableInstGrp(false);
	setEnableButtons(false);


    this->setWindowTitle(QObject::tr("Button %1 drink settings").arg(button));
}

void WBSDDrink_Window::closeEvent(QCloseEvent *)
{
    if(!isblockiclose)
    emit iclose();
}

int WBSDDrink_Window::getStepPer(int seq)
{
    int ret;
    switch (seq){
    case 0:
        ret = itsRecipe->getLeft_bib_percent();
        break;
    case 1:
        ret = itsRecipe->getRight_bib_percent();
        break;
    case 2:
        ret = itsRecipe->getInstant_percent();
        break;
    case 3:
        ret =100;
        break;
    case 4:
        ret =100;
        break;
     case 16:
        ret =itsRecipe->fmu_percentage;
        break;
    }

    return ret;
}

void WBSDDrink_Window::setStepPer(int seq, int value)
{
    switch (seq){
    case 0:
        itsRecipe->left_bib_percent = value;
        break;
    case 1:
        itsRecipe->right_bib_percent = value;
        break;
    case 2:
        itsRecipe->instant_percent =value;
        break;
    case 3:

        break;
    case 4:

        break;
     case 16:
        itsRecipe->fmu_percentage=value;
        ui->sp_fmu_per->setValue(value);
        break;
    }
}



void WBSDDrink_Window::on_menuBack_triggered()
{
	on_btnCancel_clicked()	;
}

void WBSDDrink_Window::setEnableButtons(bool aStatus){
	this->ui->btnSave->setEnabled(aStatus);
	this->ui->btnRestoreDefault->setEnabled(true);
    this->ui->btnSetDefault->setEnabled(true);
}

void WBSDDrink_Window::setEnableFmu(bool aStatus)
{
    qDebug()<<"setEnableFmu == "<<aStatus;
    ui->cb_fmu_id->setEnabled(aStatus);
    ui->btn_fmu_rcp->setEnabled(aStatus);
    //ui->sp_fmu_per->setEnabled(aStatus);
//    if(!aStatus)
//    {
//        ui->tb_main->removeTab(3);
//    }
}
void WBSDDrink_Window::setEnableRTDGrp(bool aStatus)
{
//	this->ui->grpRTD->setEnabled(aStatus);
	this->ui->lblRTD1->setEnabled(aStatus);
	this->ui->spRTDLarge->setEnabled(aStatus);
	this->ui->spRTDSmall->setEnabled(aStatus);
	this->ui->lblRTDMax->setEnabled(aStatus);
	this->ui->spRTDMedium->setEnabled(aStatus);
	this->ui->lblRTD2->setEnabled(aStatus);
	this->ui->lblRTD3->setEnabled(aStatus);
	this->ui->lblRTDMin->setEnabled(aStatus);
	this->ui->lblRTDBound->setEnabled(aStatus);

}

void WBSDDrink_Window::setEnableLBIBGrp(bool aStatus)
{
//	this->ui->grpLBib->setEnabled(aStatus);
	this->ui->lblLBib1->setEnabled(aStatus);
	this->ui->lblMaxRatioLBib->setEnabled(aStatus);

	this->ui->lblLBib2->setEnabled(aStatus);
	this->ui->lblLBib3->setEnabled(aStatus);
	this->ui->lblMinRatioLBib->setEnabled(aStatus);
	this->ui->lblLBibBound->setEnabled(aStatus);
	this->ui->spLBibStrong->setEnabled(aStatus);
	this->ui->spLBibMedium->setEnabled(aStatus);
	this->ui->spLBibMild->setEnabled(aStatus);

	this->ui->spLBibPercentOfDrink->setEnabled(aStatus);

	this->ui->lblPercentOfDrinkBoundaries->setEnabled(aStatus);
	this->ui->lblPercentofDrink->setEnabled(aStatus);
	this->ui->lblRBibPercentOfDrink->setEnabled(aStatus);
    this->ui->lblPercentOfDrinkBoundaries_2->setEnabled(aStatus);

	this->ui->lblLBibAirpump->setEnabled(aStatus);
	this->ui->spLBibAirpump->setEnabled(aStatus);


}

void WBSDDrink_Window::setEnableRBIBGrp(bool aStatus)
{
//	this->ui->grpRightBIB->setEnabled(aStatus);
	this->ui->lblRBib1->setEnabled(aStatus);
	this->ui->lblMaxRatioRBib->setEnabled(aStatus);
	this->ui->lblRBib2->setEnabled(aStatus);
	this->ui->lblRBib3->setEnabled(aStatus);
	this->ui->lblMinRatioRBib->setEnabled(aStatus);
	this->ui->lblRBibBound->setEnabled(aStatus);
	this->ui->spRBibStrong->setEnabled(aStatus);
	this->ui->spRBibMild->setEnabled(aStatus);
	this->ui->spRBibMedium->setEnabled(aStatus);

	this->ui->spLBibPercentOfDrink->setEnabled(aStatus);
	this->ui->lblPercentOfDrinkBoundaries->setEnabled(aStatus);
	this->ui->lblPercentofDrink->setEnabled(aStatus);
	this->ui->lblRBibPercentOfDrink->setEnabled(aStatus);

	this->ui->lblRBibAirpump->setEnabled(aStatus);
	this->ui->spRBibAirpump->setEnabled(aStatus);

}

void WBSDDrink_Window::setEnableInstGrp(bool aStatus)
{
//	this->ui->grpInst->setEnabled(aStatus);
	this->ui->lblInst1->setEnabled(aStatus);
	this->ui->lblCanMax->setEnabled(aStatus);
	this->ui->lblInst2->setEnabled(aStatus);
	this->ui->lblInst3->setEnabled(aStatus);
	this->ui->lblCanMin->setEnabled(aStatus);
	this->ui->lblInstBound->setEnabled(aStatus);
	this->ui->spCanGramStrong->setEnabled(aStatus);
	this->ui->spCanGramMedium->setEnabled(aStatus);
	this->ui->spCanGramMild->setEnabled(aStatus);
	this->ui->lblInstRTDBase->setEnabled(aStatus);
}

QString WBSDDrink_Window::enableDrink(int aType){
	int aDrink;
	QString aDb;
	QString retStr="";
    qDebug()<<"enableDrink(int aType) == "<<aType;
	switch (aType){
	case 0:
		setEnableRTDGrp(true);
		setEnableLBIBGrp(true);
		aDrink=itsRecipe->getLeft_bib_type();
		aDb="110";
		break;
	case 1:
		setEnableRTDGrp(true);
		setEnableRBIBGrp(true);
		aDrink=itsRecipe->getRight_bib_type();
		aDb="111";
		break;
	case 2:
		setEnableRTDGrp(true);
		setEnableInstGrp(true);
		aDrink=itsRecipe->getInstant_type();
		aDb="112";
		break;
	case 3:
		setEnableRTDGrp(true);
		aDrink=itsRecipe->getInstant_type();
		retStr="Hot water";
		break;
	case 4:
		setEnableRTDGrp(true);
		retStr="Cold water";
		break;
     case 16:
        setEnableRTDGrp(true);
        setEnableFmu(true);
        retStr="MMP Milk";
	}
	if (retStr.length()<1){
		retStr=DataBaseHelper::getInstance()->getTabKatString(aDb,aDrink);
	}
	return retStr;
}



void WBSDDrink_Window::updateData()
{
    qDebug()<<"itsrecipe= "<<this->itsRecipe->right_bib_percent<<this->itsRecipe->left_bib_percent;
	setEnableRTDGrp(false);
	setEnableLBIBGrp(false);
	setEnableRBIBGrp(false);
	setEnableInstGrp(false);
	setEnableButtons(false);
    ui->spLBibPercentOfDrink_2->setEnabled(false);
    setEnableFmu(false);
	QString recipeString="";
	QString step1;
	QString step2;
	QString step3;
#ifdef FMU_ON
    ui->spd1->setEnabled(false);
    ui->sp1->setEnabled(false);
    ui->spd2->setEnabled(false);
    ui->sp2->setEnabled(false);
    ui->spd3->setEnabled(false);
    ui->sp3->setEnabled(false);
#endif
	if (itsRecipe->seq1!=8){
        step1 = enableDrink(itsRecipe->seq1);
        #ifdef FMU_ON
        ui->spd1->setEnabled(true);
        ui->sp1->setEnabled(true);
        ui->lb1->setText(step1);
        ui->spd1->setValue(getStepPer(itsRecipe->seq1));
#endif
        recipeString.append(step1);
		if (itsRecipe->seq2!=8){
            step2 = enableDrink(itsRecipe->seq2);
            #ifdef FMU_ON
            ui->spd2->setEnabled(true);
            ui->sp2->setEnabled(true);
            ui->lb2->setText(step2);
            ui->spd2->setValue(getStepPer(itsRecipe->seq2));
#endif
			recipeString.append("  -->  ");				
            recipeString.append(step2);
			if (itsRecipe->seq3!=8){

				recipeString.append("  -->  ");				
                recipeString.append(enableDrink(itsRecipe->seq3));
                #ifdef FMU_ON
                ui->spd3->setValue(getStepPer(itsRecipe->seq3));
                ui->sp3->setEnabled(false);
                ui->sp3->setEnabled(false);
                ui->lb3->setText(enableDrink(itsRecipe->seq3));
                ui->spd1->setEnabled(false);
                ui->sp1->setEnabled(false);
                ui->spd2->setEnabled(false);
                ui->sp2->setEnabled(false);
                #endif
			}
		}
	}

	int b=itsRecipe->left_bib_percent;
	int c=itsRecipe->right_bib_percent;
    itsRecipe->left_bib_percent =b;
	itsRecipe->right_bib_percent=c;
	if (abs(itsRecipe->left_bib_percent_max-itsRecipe->left_bib_percent_min)<0.05){
		this->ui->spLBibPercentOfDrink->setValue(itsRecipe->left_bib_percent);
        this->ui->spLBibPercentOfDrink->setVisible(false);
		this->ui->lblPercentOfDrinkBoundaries->setVisible(false);
		this->ui->lblPercentofDrink->setVisible(false);
		this->ui->lblRBibPercentOfDrink->setVisible(false);
        ui->spLBibPercentOfDrink_2->setVisible(false);
        ui->lblPercentOfDrinkBoundaries_2->setVisible(false);
	} else
	{
        //this->ui->lblRBibPercentOfDrink->setText(QString().sprintf("Right bib percent: %d",itsRecipe->right_bib_percent));
		this->ui->lblPercentOfDrinkBoundaries->setText(QString().sprintf("Min:%d   Max:%d  ",itsRecipe->left_bib_percent_min,itsRecipe->left_bib_percent_max));
        //this->ui->lblPercentOfDrinkBoundaries_2->setText(QString().sprintf("Min:%d   Max:%d  ",itsRecipe->left_bib_percent_min,itsRecipe->left_bib_percent_max));
        ui->spLBibPercentOfDrink_2->setValue(itsRecipe->right_bib_percent);
        this->ui->spLBibPercentOfDrink->setValue(itsRecipe->left_bib_percent);
		this->ui->spLBibPercentOfDrink->setVisible(true);
		this->ui->lblPercentOfDrinkBoundaries->setVisible(true);
		this->ui->lblPercentofDrink->setVisible(true);
		this->ui->lblRBibPercentOfDrink->setVisible(true);
        ui->spLBibPercentOfDrink_2->setVisible(true);
        ui->lblPercentOfDrinkBoundaries_2->setVisible(false);
	}

	this->ui->lblOrderTXT->setText(recipeString);
	this->ui->lblMaxRatioLBib->setText(QString().sprintf("Max: %2.1f",itsRecipe->left_bib_ratio_max));
	this->ui->lblMinRatioLBib->setText(QString().sprintf("Min: %2.1f",itsRecipe->left_bib_ratio_min));

    if(itsBaseWindow->getUnitTmp() != 0)
    {

        this->ui->lblRTDMax->setText(QString().sprintf("Max: %.1f oz",ml2oz( itsRecipe->rtd_max)));
        this->ui->lblRTDMin->setText(QString().sprintf("Min: %.1f oz",ml2oz( itsRecipe->rtd_min)));
    }
else
    {
        this->ui->lblRTDMax->setText(QString().sprintf("Max: %d ml",itsRecipe->rtd_max));
        this->ui->lblRTDMin->setText(QString().sprintf("Min: %d ml",itsRecipe->rtd_min));
    }
    this->ui->lblMaxRatioRBib->setText(QString().sprintf("Max: %2.1f",itsRecipe->right_bib_ratio_max));
	this->ui->lblMinRatioRBib->setText(QString().sprintf("Min: %2.1f",itsRecipe->right_bib_ratio_min));
	this->ui->lblCanMax->setText(QString().sprintf("Max: %2.1f",itsRecipe->instant_gram_max));
	this->ui->lblCanMin->setText(QString().sprintf("Min: %2.1f",itsRecipe->instant_gram_min));

    if(itsBaseWindow->getUnitTmp() != 0)
    {
        this->ui->spRTDSmall->setDecimals(1);
        this->ui->spRTDMedium->setDecimals(1);
        this->ui->spRTDLarge->setDecimals(1);
        ui->lblRTD1->setText(QObject::tr("Volume small (oz):"));
        ui->lblRTD2->setText(QObject::tr("Volume medium (oz):"));
        ui->lblRTD3->setText(QObject::tr("Volume large (oz):"));
        this->ui->spRTDSmall->setValue(ml2oz( itsRecipe->small_cup));
        this->ui->spRTDMedium->setValue(ml2oz( itsRecipe->medium_cup));
        this->ui->spRTDLarge->setValue(ml2oz( itsRecipe->large_cup));
    }
    else
    {
        this->ui->spRTDSmall->setDecimals(0);
        this->ui->spRTDMedium->setDecimals(0);
        this->ui->spRTDLarge->setDecimals(0);
        ui->lblRTD1->setText(QObject::tr("Volume small (ml):"));
        ui->lblRTD2->setText(QObject::tr("Volume medium (ml):"));
        ui->lblRTD3->setText(QObject::tr("Volume large (ml):"));
        this->ui->spRTDSmall->setValue((int)itsRecipe->small_cup);
        this->ui->spRTDMedium->setValue((int)itsRecipe->medium_cup);
        this->ui->spRTDLarge->setValue((int)itsRecipe->large_cup);
    }


	this->ui->spLBibMild->setValue(itsRecipe->left_bib_mild_ratio);
	this->ui->spLBibMedium->setValue(itsRecipe->left_bib_norm_ratio);
	this->ui->spLBibStrong->setValue(itsRecipe->left_bib_strong_ratio);
	this->ui->spLBibAirpump->setValue(itsRecipe->left_bib_airpump_speed);

	this->ui->spRBibMild->setValue(itsRecipe->right_bib_mild_ratio);
	this->ui->spRBibMedium->setValue(itsRecipe->right_bib_norm_ratio);
    qDebug()<<"itsRecipe->right_bib_strong_ratio21="<<itsRecipe->right_bib_strong_ratio;
	this->ui->spRBibStrong->setValue(itsRecipe->right_bib_strong_ratio);
    qDebug()<<"itsRecipe->right_bib_strong_ratio22="<<itsRecipe->right_bib_strong_ratio;

	this->ui->spRBibAirpump->setValue(itsRecipe->right_bib_airpump_speed);
    qDebug()<<"itsRecipe->spRBibAirpump="<<itsRecipe->right_bib_airpump_speed;

     qDebug()<<"itsRecipe->fmu_id == "<<itsRecipe->fmu_id;
    if(itsRecipe->fmu_id!=0   && (itsRecipe->seq1==16 || itsRecipe->seq2==16||itsRecipe->seq3==16))
    {
        setEnableFmu(true);
        for(int i=0;i<ui->cb_fmu_id->count();i++)
        {
            if(itsRecipe->fmu_id == ui->cb_fmu_id->itemData(i).toInt())
            {
                this->ui->cb_fmu_id->setCurrentIndex(i);
                break;
            }
        }
        qDebug()<<"itsRecipe->fmu_id="<<itsRecipe->fmu_id;
        this->ui->sp_fmu_per->setValue(itsRecipe->fmu_percentage);
        qDebug()<<"itsRecipe->fmu_percentage="<<itsRecipe->fmu_percentage;
    }else
    {
        setEnableFmu(false);
    }
/*
 *
 * disable instant grams selection if the instant config is not milk or sugar!!!!
 * modify by Lee 2015-06-17
 */
    if ((itsRecipe->instant_type==7) || (itsRecipe->instant_type==8) || (itsRecipe->instant_type==11) || (itsRecipe->instant_type==10)){
		this->ui->spCanGramStrong->setEnabled(false);
		this->ui->spCanGramStrong->setVisible(false);
		this->ui->spCanGramMedium->setValue(itsRecipe->instant_ingredient_gram_norm);
		this->ui->spCanGramMild->setEnabled(false);
		this->ui->spCanGramMild->setVisible(false);
	}
	this->ui->spCanGramStrong->setValue(itsRecipe->instant_ingredient_gram_strong);
	this->ui->spCanGramMedium->setValue(itsRecipe->instant_ingredient_gram_norm);
	this->ui->spCanGramMild->setValue(itsRecipe->instant_ingredient_gram_mild);
	this->ui->btnSave->setEnabled(isNewDrink);
	this->ui->lblInstRTDBase->setVisible(false);

    this->ui->lblInst1->setText(QObject::tr("Grams strong/%1 ml").arg(itsRecipe->instant_ingredient_rtd_standard));
    this->ui->lblInst2->setText(QObject::tr("Grams normal/%1 ml").arg(itsRecipe->instant_ingredient_rtd_standard));
    this->ui->lblInst3->setText(QObject::tr("Grams mild/%1 ml").arg(itsRecipe->instant_ingredient_rtd_standard));


    this->ui->label_5->hide();
    this->ui->label_6->hide();
    this->ui->label_7->hide();

    if(itsBaseWindow->getUnitTmp() != 0)
    {
        //this->ui->label_5->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramMild->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
        //this->ui->label_6->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramMedium->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
        //this->ui->label_7->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramStrong->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
    }
	this->ui->spRBibMild->setMaximum(itsRecipe->right_bib_ratio_max);
	this->ui->spRBibMild->setMinimum(itsRecipe->right_bib_ratio_min);
	this->ui->spRBibMedium->setMaximum(itsRecipe->right_bib_ratio_max);
	this->ui->spRBibMedium->setMinimum(itsRecipe->right_bib_ratio_min);
	this->ui->spRBibStrong->setMaximum(itsRecipe->right_bib_ratio_max);
	this->ui->spRBibStrong->setMinimum(itsRecipe->right_bib_ratio_min);
	this->ui->spCanGramMild->setMaximum(itsRecipe->instant_gram_max);
	this->ui->spCanGramMild->setMinimum(itsRecipe->instant_gram_min);
	this->ui->spCanGramMedium->setMaximum(itsRecipe->instant_gram_max);
	this->ui->spCanGramMedium->setMinimum(itsRecipe->instant_gram_min);
	this->ui->spCanGramStrong->setMaximum(itsRecipe->instant_gram_max);
	this->ui->spCanGramStrong->setMinimum(itsRecipe->instant_gram_min);
    this->ui->spLBibMild->setMaximum(itsRecipe->left_bib_ratio_max);
    this->ui->spLBibMild->setMinimum(itsRecipe->left_bib_ratio_min);
    this->ui->spLBibMedium->setMaximum(itsRecipe->left_bib_ratio_max);
    this->ui->spLBibMedium->setMinimum(itsRecipe->left_bib_ratio_min);
    this->ui->spLBibStrong->setMaximum(itsRecipe->left_bib_ratio_max);
    this->ui->spLBibStrong->setMinimum(itsRecipe->left_bib_ratio_min);
	this->ui->spLBibPercentOfDrink->setMaximum(itsRecipe->left_bib_percent_max);
	this->ui->spLBibPercentOfDrink->setMinimum(itsRecipe->left_bib_percent_min);
    //this->ui->spLBibPercentOfDrink_2->setMaximum(itsRecipe->left_bib_percent_max);
    //this->ui->spLBibPercentOfDrink_2->setMinimum(itsRecipe->left_bib_percent_min);


    if(itsBaseWindow->getUnitTmp() != 0)
    {
        this->ui->spRTDSmall->setMaximum(ml2oz( itsRecipe->rtd_max));
        this->ui->spRTDSmall->setMinimum(ml2oz( itsRecipe->rtd_min));
        this->ui->spRTDMedium->setMaximum(ml2oz( itsRecipe->rtd_max));
        this->ui->spRTDMedium->setMinimum(ml2oz( itsRecipe->rtd_min));
        this->ui->spRTDLarge->setMaximum(ml2oz( itsRecipe->rtd_max));
        this->ui->spRTDLarge->setMinimum(ml2oz( itsRecipe->rtd_min));
    }else
    {
        this->ui->spRTDSmall->setMaximum(itsRecipe->rtd_max);
        this->ui->spRTDSmall->setMinimum(itsRecipe->rtd_min);
        this->ui->spRTDMedium->setMaximum(itsRecipe->rtd_max);
        this->ui->spRTDMedium->setMinimum(itsRecipe->rtd_min);
        this->ui->spRTDLarge->setMaximum(itsRecipe->rtd_max);
        this->ui->spRTDLarge->setMinimum(itsRecipe->rtd_min);
    }
    /*
     * disable the rtd volume for us if the dispensetype is push&hold
     * modify by Lee 2015-06-17
     * version 1.20
     */
        qDebug()<<"itsRecipe->dispense_type"<<itsRecipe->dispense_type;
        qDebug()<<"getMachineUnit"<<itsBaseWindow->getMachineUnit();
    if(itsBaseWindow->getMachineUnit() ==WBSDBaseWindow::UNIT_USA && itsRecipe->dispense_type == 1 )
    {
        //qDebug()<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        this->ui->spRTDSmall->setEnabled(false);
        this->ui->spRTDMedium->setEnabled(false);
        this->ui->spRTDLarge->setEnabled(false);
    }
}

void WBSDDrink_Window::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
		isVisible=false;
             isblockiclose = true;
		this->close();
        this->deleteLater();
    }
}

void WBSDDrink_Window::on_cboRecipe_activated(int index)
{
    ui->sp2->setValue(0);
    ui->sp3->setValue(0);
    ui->lb2->setText("-");
    ui->lb3->setText("-");
	int itsDb;
	int itsHiLo;
	switch (itsButton){
	case 1:
			itsDb=6;
			itsHiLo=1;
			break;
	case 2:
			itsDb=6;
			itsHiLo=0;
			break;
	case 3:
			itsDb=7;
			itsHiLo=1;
			break;
	case 4:
			itsDb=7;
			itsHiLo=0;
			break;
	case 5:
			itsDb=8;
			itsHiLo=1;
			break;
	case 6:
			itsDb=8;
			itsHiLo=0;
			break;
	case 7:
			itsDb=9;
			itsHiLo=1;
			break;
	case 8:
			itsDb=9;
			itsHiLo=0;
			break;
	}
	int value = ui->cboRecipe->itemData(index).toInt();
	setEnableRTDGrp(false);
	setEnableLBIBGrp(false);
	setEnableRBIBGrp(false);
	setEnableInstGrp(false);
	setEnableButtons(false);
    itsRecipe->fmu_id=0;
	if (itsRecipe->loadFromDB(value)){
		itsBaseWindow->addMessageToQue(RcpMessage(value));
		isNewDrink=true;
	}
}

bool WBSDDrink_Window::setTabKatCBO(int aValue,QComboBox* aCombo){
    int noItems = aCombo->count();
    int index;
    int index_f =99; //rj debug remove!

    for (index=0; index<noItems; index++){
        int itemVal = aCombo->itemData(index).toInt();
        if ((aValue )==itemVal) {
            aCombo->setCurrentIndex(index);
            index_f = index;
            break;
        }
    }
    /*modify by lee if crt rcp is ok
    if not give the hint.
    disable this function 2015-6-3
    */
    /*
    if(index_f == 99)
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Drink Setting Waring","Current drink setting is no longer valid,do you want to set it to no recipe!!",QMessageBox::Ok|QMessageBox::Cancel);
        if(reply == QMessageBox::Ok)
        {
            int itsDb;
            int itsHiLo;
            switch (itsButton){
            case 1:
                    itsDb=6;
                    itsHiLo=1;
                    break;
            case 2:
                    itsDb=6;
                    itsHiLo=0;
                    break;
            case 3:
                    itsDb=7;
                    itsHiLo=1;
                    break;
            case 4:
                    itsDb=7;
                    itsHiLo=0;
                    break;
            case 5:
                    itsDb=8;
                    itsHiLo=1;
                    break;
            case 6:
                    itsDb=8;
                    itsHiLo=0;
                    break;
            case 7:
                    itsDb=9;
                    itsHiLo=1;
                    break;
            case 8:
                    itsDb=9;
                    itsHiLo=0;
                    break;
            }
            int value = ui->cboRecipe->itemData(index).toInt();
            if (itsRecipe->loadFromDB(value)){
                ParameterMsg query(Message::MCB,Message::DP, itsDb, Message::SET_PARAMETER);
                query.setChar(itsHiLo,(char)itsRecipe->getId() & 0x00FF);
                itsBaseWindow->addMessageToQue(query);
            }
            return false;
        }
    }*/
    return true;
}


void WBSDDrink_Window::gotMessage(Message aMsg)
{
    int aVal;
    if ((aMsg.getType()==Message::ANSWER_SET_RCP))
    {
        qDebug()<<"Message::ANSWER_SET_RCP"<<aMsg.getData().toHex();
    }
	qDebug() << "ANSWER_RECIPE";
	if (!isVisible)
		return ;
    if (aMsg.getType()==Message::ANSWER_RECIPE_P0){
		this->ui->spRBibMild->setMaximum(2000);
		this->ui->spRBibMild->setMinimum(0);
		this->ui->spRBibMedium->setMaximum(2000);
		this->ui->spRBibMedium->setMinimum(0);
		this->ui->spRBibStrong->setMaximum(2000);
		this->ui->spRBibStrong->setMinimum(0);
		this->ui->spCanGramMild->setMaximum(2000);
		this->ui->spCanGramMild->setMinimum(0);
		this->ui->spCanGramMedium->setMaximum(2000);
		this->ui->spCanGramMedium->setMinimum(0);
		this->ui->spCanGramStrong->setMaximum(2000);
		this->ui->spCanGramStrong->setMinimum(0);
		this->ui->spLBibMild->setMaximum(2000);
		this->ui->spLBibMild->setMinimum(0);
		this->ui->spLBibMedium->setMaximum(2000);
		this->ui->spLBibMedium->setMinimum(0);
		this->ui->spLBibStrong->setMaximum(2000);
		this->ui->spLBibStrong->setMinimum(0);
		this->ui->spLBibPercentOfDrink->setMaximum(2000);
		this->ui->spLBibPercentOfDrink->setMinimum(0);
	
		this->ui->spRTDSmall->setMaximum(2000);
		this->ui->spRTDSmall->setMinimum(0);
		this->ui->spRTDMedium->setMaximum(2000);
		this->ui->spRTDMedium->setMinimum(0);
		this->ui->spRTDLarge->setMaximum(2000);
		this->ui->spRTDLarge->setMinimum(0);

		itsRecipe->large_cup=aMsg.getDataInt(2,false,2);
		itsRecipe->medium_cup=aMsg.getDataInt(3,false,2);
		itsRecipe->small_cup=aMsg.getDataInt(4,false,2);
		itsBaseWindow->addMessageToQue(RcpMessage(itsRecipe->getId(),1));
		qDebug() << "ANSWER_RECIPE_P0";
		return;
	}
    if (aMsg.getType()==Message::ANSWER_RECIPE_P1){
		qDebug() << "ANSWER_RECIPE_P1_Start";
		itsRecipe->left_bib_mild_ratio=aMsg.getDataFloat(1,false);
		itsRecipe->left_bib_norm_ratio=aMsg.getDataFloat(2,false);
		itsRecipe->left_bib_strong_ratio=aMsg.getDataFloat(3,false);
		itsRecipe->left_bib_percent=aMsg.getDataInt(8,false,2);
		itsRecipe->right_bib_percent=aMsg.getDataInt(9,false,2);
		itsBaseWindow->addMessageToQue(RcpMessage(itsRecipe->getId(),2));
		qDebug() << "ANSWER_RECIPE_P1";
		return;
	}
    if (aMsg.getType()==Message::ANSWER_RECIPE_P2){
		qDebug() << "ANSWER_RECIPE_P2_Start";
		itsRecipe->right_bib_mild_ratio=aMsg.getDataFloat(1,false);		
        itsRecipe->right_bib_norm_ratio=aMsg.getDataFloat(2,false);

        itsRecipe->right_bib_strong_ratio=aMsg.getDataFloat(3,false);
        qDebug()<<"itsRecipe->right_bib_strong_ratio"<<itsRecipe->right_bib_strong_ratio;
        itsRecipe->left_bib_airpump_speed=aMsg.getDataInt(8,false,2);
        itsRecipe->right_bib_airpump_speed=aMsg.getDataInt(9,false,2);
		itsBaseWindow->addMessageToQue(RcpMessage(itsRecipe->getId(),3));
		qDebug() << "ANSWER_RECIPE_P2";
		return;
	}
    if (aMsg.getType()==Message::ANSWER_RECIPE_P3){
        qDebug()<<"Message::ANSWER_RECIPE_P3"<<aMsg.getData().toHex();
		itsRecipe->instant_ingredient_gram_mild=aMsg.getDataFloat(1,false);
		itsRecipe->instant_ingredient_gram_norm=aMsg.getDataFloat(2,false);
		itsRecipe->instant_ingredient_gram_strong=aMsg.getDataFloat(3,false);
        //add by lee : for fmu function
#ifdef FMU_ON
        itsRecipe->fmu_id=aMsg.getDataInt(8,false,2);
        itsRecipe->fmu_percentage=aMsg.getDataInt(9,false,2);
#endif
//		qDebug() <<"RLINE:" << itsRecipe->toRLine();
        qDebug()<<"itsRecipe->right_bib_strong_ratio3="<<itsRecipe->right_bib_strong_ratio;

		updateData();
		qDebug() << "ANSWER_RECIPE_P3";
		return;
	}
    if (aMsg.getType()==Message::ANSWER_SET_RCP){
		setEnableRTDGrp(false);
		setEnableLBIBGrp(false);
		setEnableRBIBGrp(false);
		setEnableInstGrp(false);
		setEnableButtons(false);
		QTimer::singleShot(100,this,SLOT(reload()));
		qDebug() << "Set recipe";
		return;
	}

	if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DP)){
		int high=aMsg.getDataInt() & 0x00FF;
		int low=(aMsg.getDataInt() >> 8) & 0x00FF;

		itsCfg=aMsg.getDataInt();

        switch(aMsg.getParameters().at(3)){
            case 0:
             aVal=aMsg.getDataUInt();
            qDebug()<<"(0x8000 & aVal) >> 15"<<((0x8000 & aVal) >> 15);
            itsBaseWindow->setUnitTmp((0x8000 & aVal) >> 15);
            /*modify by Lee  c/f  */
//            if(itsBaseWindow->getUnitTmp() == 0)
//            {
//                ui->lbl_s->hide();
//                ui->lbl_m->hide();
//                ui->lbl_l->hide();
//                ui->label_3->hide();
//                ui->label_4->hide();
//            }else
//            {
//                ui->lbl_s->show();
//                ui->lbl_m->show();
//                ui->lbl_l->show();
//                ui->label_3->show();
//                ui->label_4->show();
//            }
                break;
            case 2:
				itsRecipe->de_airtime=aMsg.getDataInt();
				break;
			case 4:
                DataBaseHelper::getInstance()->populateValidRecipes("100",ui->cboRecipe,(0xF000 & aMsg.getDataUInt()) >> 12,(0x0F00 & aMsg.getDataUInt()) >> 8,(0x00F0 & aMsg.getDataUInt()) >> 4,isfmuon);
				break;
            case 6:
            case 7:
            case 8:
            case 9:
				if (itsButton%2==0){
                    //setTabKatCBO(high,ui->cboRecipe);
                    if (setTabKatCBO(high,ui->cboRecipe) && itsRecipe->loadFromDB(high)){
						RcpMessage rcpmsg(high);
					    itsBaseWindow->addMessageToQue(rcpmsg);
//						updateData();
					}

				} else {
                    //setTabKatCBO(low,ui->cboRecipe);
                    if (setTabKatCBO(low,ui->cboRecipe) && itsRecipe->loadFromDB(low)){
						RcpMessage rcpmsg(low);
					    itsBaseWindow->addMessageToQue(rcpmsg);
//						updateData();
					}
				}
                break;
        case 26:
            aVal=aMsg.getDataUInt();
            if(((aVal&0x40)>>6) == 0)
            {
                 setEnableFmu(false);
                 isfmuon =0;
            }else
            {
                isfmuon =1;
            }
            break;
            default:
                break;
        }
    }

	if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::AP)){
        switch(aMsg.getParameters().at(3)){
			case 27:
				itsRecipe->ingr_ml_per_gram=aMsg.getDataFloat();
				break;

            default:
                break;
        }
    }

}

void WBSDDrink_Window::on_btnSave_clicked()
{
int itsDb;
	int itsHiLo;
	switch (itsButton){
	case 1:
			itsDb=6;
			itsHiLo=1;
			break;
	case 2:
			itsDb=6;
			itsHiLo=0;
			break;
	case 3:
			itsDb=7;
			itsHiLo=1;
			break;
	case 4:
			itsDb=7;
			itsHiLo=0;
			break;
	case 5:
			itsDb=8;
			itsHiLo=1;
			break;
	case 6:
			itsDb=8;
			itsHiLo=0;
			break;
	case 7:
			itsDb=9;
			itsHiLo=1;
			break;
	case 8:
			itsDb=9;
			itsHiLo=0;
			break;
	}
	QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QObject::tr("Confirm save"), QObject::tr("Save changes to machine?"),QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
		isNewDrink=false;
		RcpMessage aRMsg(*itsRecipe);
        itsBaseWindow->addMessageToQue(aRMsg);

        ParameterMsg query(Message::MCB,Message::DP, itsDb, Message::SET_PARAMETER);
        query.setChar(itsHiLo,(char)itsRecipe->getId() & 0x00FF);
        itsBaseWindow->addMessageToQue(query);
        updateData();


    } else {
    }
}

void WBSDDrink_Window::on_btnCancel_clicked()
{
    QMessageBox::StandardButton reply;
	if (this->ui->btnSave->isEnabled()){
        reply = QMessageBox::question(this, QObject::tr("Close window"), QObject::tr("Changes have not been written to machine\nPlease confirm closing of window!"),QMessageBox::Yes|QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			isVisible=false;
			this->close();
		}
	} else {
			isVisible=false;
			this->close();
	}

}

void WBSDDrink_Window::on_btnSetDefault_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,QObject::tr( "Save to DB"), QObject::tr("Please confirm saving new default values!"),QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if (itsRecipe->saveToDb()){
            updateData();
        }
    }
}

void WBSDDrink_Window::on_btnRestoreDefault_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QObject::tr("Reload window"), QObject::tr("Changes have not been written to machine\nPlease confirm reloading!"),QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if (itsRecipe->loadFromDB(itsRecipe->getId())){
			isNewDrink=true;
            updateData();
        }
    }
}


void WBSDDrink_Window::on_spRTDSmall_valueChanged(int arg1)
{
    setEnableButtons(true);
    if(itsBaseWindow->getUnitTmp() != 0)
    {
        itsRecipe->small_cup = oz2ml(this->ui->spRTDSmall->value());
    }else
    {
        itsRecipe->small_cup=this->ui->spRTDSmall->value();
    }
    //ui->lbl_s->setText(QString::number((double)this->ui->spRTDSmall->value()/_ozunit)+" (oz)");
}

void WBSDDrink_Window::on_spRTDSmall_editingFinished()
{
    setEnableButtons(true);
    if(itsBaseWindow->getUnitTmp() != 0)
    {
        itsRecipe->small_cup = oz2ml(this->ui->spRTDSmall->value());
    }else
    {
        itsRecipe->small_cup=this->ui->spRTDSmall->value();
    }
}


void WBSDDrink_Window::on_spRTDMedium_valueChanged(int arg1)
{
    setEnableButtons(true);
    if(itsBaseWindow->getUnitTmp() != 0)
    {
        itsRecipe->medium_cup=oz2ml(this->ui->spRTDMedium->value());
    }else
    {
    itsRecipe->medium_cup=this->ui->spRTDMedium->value();
    }
     //ui->lbl_m->setText(QString::number((double)this->ui->spRTDMedium->value()/_ozunit)+" (oz)");
}

void WBSDDrink_Window::on_spRTDMedium_editingFinished()
{
    setEnableButtons(true);
    if(itsBaseWindow->getUnitTmp() != 0)
    {
        itsRecipe->medium_cup=oz2ml(this->ui->spRTDMedium->value());
    }else
    {
        itsRecipe->medium_cup=this->ui->spRTDMedium->value();
    }
}


void WBSDDrink_Window::on_spRTDLarge_valueChanged(int arg1)
{
    setEnableButtons(true);
    if(itsBaseWindow->getUnitTmp() != 0)
    {
        itsRecipe->large_cup=oz2ml(this->ui->spRTDLarge->value());
    }else
    {
        itsRecipe->large_cup=this->ui->spRTDLarge->value();
    }
    //ui->lbl_l->setText(QString::number((double)this->ui->spRTDLarge->value()/_ozunit)+" (oz)");
}
void WBSDDrink_Window::on_spRTDLarge_editingFinished()
{
    setEnableButtons(true);
    if(itsBaseWindow->getUnitTmp() != 0)
    {
        itsRecipe->large_cup=oz2ml(this->ui->spRTDLarge->value());
    }else
    {
        itsRecipe->large_cup=this->ui->spRTDLarge->value();
    }
}


void WBSDDrink_Window::on_spLBibStrong_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->left_bib_strong_ratio=this->ui->spLBibStrong->value();
}
void WBSDDrink_Window::on_spLBibStrong_editingFinished()
{
    setEnableButtons(true);
    itsRecipe->left_bib_strong_ratio=this->ui->spLBibStrong->value();
}


void WBSDDrink_Window::on_spLBibMedium_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->left_bib_norm_ratio=this->ui->spLBibMedium->value();
}

void WBSDDrink_Window::on_spLBibMedium_editingFinished()
{
    setEnableButtons(true);
    itsRecipe->left_bib_norm_ratio=this->ui->spLBibMedium->value();
}


void WBSDDrink_Window::on_spLBibMild_valueChanged(double arg1)
{
    setEnableButtons(true);
			itsRecipe->left_bib_mild_ratio=this->ui->spLBibMild->value();
}
void WBSDDrink_Window::on_spLBibMild_editingFinished()
{
    setEnableButtons(true);
			itsRecipe->left_bib_mild_ratio=this->ui->spLBibMild->value();
}


void WBSDDrink_Window::on_spRBibStrong_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->right_bib_strong_ratio=this->ui->spRBibStrong->value();
}
void WBSDDrink_Window::on_spRBibStrong_editingFinished()
{
    setEnableButtons(true);
    itsRecipe->right_bib_strong_ratio=this->ui->spRBibStrong->value();
}


void WBSDDrink_Window::on_spRBibMedium_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->right_bib_norm_ratio=this->ui->spRBibMedium->value();
}

void WBSDDrink_Window::on_spRBibMedium_editingFinished()
{
    setEnableButtons(true);
    itsRecipe->right_bib_norm_ratio=this->ui->spRBibMedium->value();
}



void WBSDDrink_Window::on_spRBibMild_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->right_bib_mild_ratio=this->ui->spRBibMild->value();
}

void WBSDDrink_Window::on_spRBibMild_editingFinished()
{
    setEnableButtons(true);
     itsRecipe->right_bib_mild_ratio=this->ui->spRBibMild->value();
}


void WBSDDrink_Window::on_spCanGramStrong_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->instant_ingredient_gram_strong=this->ui->spCanGramStrong->value();
    if(itsBaseWindow->getUnitTmp() != 0)
    {
       //this->ui->label_5->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramMild->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
        //this->ui->label_6->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramMedium->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
        //this->ui->label_7->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramStrong->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
    }
}
void WBSDDrink_Window::on_spCanGramStrong_editingFinished()
{
    setEnableButtons(true);
    itsRecipe->instant_ingredient_gram_strong=this->ui->spCanGramStrong->value();
}

void WBSDDrink_Window::on_spCanGramMedium_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->instant_ingredient_gram_norm=this->ui->spCanGramMedium->value();
    if(itsBaseWindow->getUnitTmp() != 0)
    {
        //this->ui->label_5->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramMild->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
        //this->ui->label_6->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramMedium->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
        //this->ui->label_7->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramStrong->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
    }
}
void WBSDDrink_Window::on_spCanGramMedium_editingFinished()
{
    setEnableButtons(true);
    itsRecipe->instant_ingredient_gram_norm=this->ui->spCanGramMedium->value();
}

void WBSDDrink_Window::on_spCanGramMild_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->instant_ingredient_gram_mild=this->ui->spCanGramMild->value();
    if(itsBaseWindow->getUnitTmp() != 0)
    {
        //this->ui->label_5->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramMild->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
        //this->ui->label_6->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramMedium->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
        //this->ui->label_7->setText(QString().sprintf("%.4f pound/%.2f oz",this->ui->spCanGramStrong->value()*0.0022,itsRecipe->instant_ingredient_rtd_standard/_ozunit));
    }
}
void WBSDDrink_Window::on_spCanGramMild_editingFinished()
{
    setEnableButtons(true);
    itsRecipe->instant_ingredient_gram_mild=this->ui->spCanGramMild->value();
}


void WBSDDrink_Window::on_spLBibPercentOfDrink_editingFinished()
{
    setEnableButtons(true);
    itsRecipe->left_bib_percent=this->ui->spLBibPercentOfDrink->value();
    itsRecipe->right_bib_percent=100-itsRecipe->left_bib_percent;
    //this->ui->lblRBibPercentOfDrink->setText(QString().sprintf("Right BIB percent: %d",itsRecipe->right_bib_percent));
    ui->spLBibPercentOfDrink_2->setValue(itsRecipe->right_bib_percent);
}



void WBSDDrink_Window::on_spLBibPercentOfDrink_valueChanged(double arg1)
{
    setEnableButtons(true);
    itsRecipe->left_bib_percent=this->ui->spLBibPercentOfDrink->value();
    itsRecipe->right_bib_percent=100-itsRecipe->left_bib_percent;
    //this->ui->lblRBibPercentOfDrink->setText(QString().sprintf("Right BIB percent: %d",itsRecipe->right_bib_percent));
    ui->spLBibPercentOfDrink_2->setValue(itsRecipe->right_bib_percent);
}




void WBSDDrink_Window::on_spLBibAirpump_editingFinished()
{
    setEnableButtons(true);
	itsRecipe->left_bib_airpump_speed=this->ui->spLBibAirpump->value();
}


void WBSDDrink_Window::on_spLBibAirpump_valueChanged(double arg1)
{
    setEnableButtons(true);
	itsRecipe->left_bib_airpump_speed=this->ui->spLBibAirpump->value();
}
void WBSDDrink_Window::on_spRBibAirpump_editingFinished()
{
    setEnableButtons(true);
	itsRecipe->right_bib_airpump_speed=this->ui->spRBibAirpump->value();
}


void WBSDDrink_Window::on_spRBibAirpump_valueChanged(double arg1)
{
    setEnableButtons(true);
	itsRecipe->right_bib_airpump_speed=this->ui->spRBibAirpump->value();
}


void WBSDDrink_Window::on_btn_fmu_rcp_clicked()
{
    if (fmurcpwin==0)
        fmurcpwin = new FMU_PARAMETER(itsBaseWindow,itsRecipe->fmu_id);
    fmurcpwin->setAttribute(Qt::WA_DeleteOnClose,true);
    fmurcpwin->show();
    this->hide();
    connect(fmurcpwin,SIGNAL(iclose()),this,SLOT(show()));
    connect(fmurcpwin,SIGNAL(rcpidchange(int)),this,SLOT(fmurcpchange(int)));
    connect(fmurcpwin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void WBSDDrink_Window::on_cb_fmu_id_activated(int index)
{
    setEnableButtons(true);
    itsRecipe->fmu_id = ui->cb_fmu_id->itemData(index).toInt();
}

void WBSDDrink_Window::on_sp_fmu_per_valueChanged(int arg1)
{
    itsRecipe->fmu_percentage = ui->sp_fmu_per->value();
    setEnableButtons(true);

}

void WBSDDrink_Window::on_btn_fmu_rcp_destroyed()
{

}

void WBSDDrink_Window::on_spd1_valueChanged(int value)
{
    if(itsRecipe->seq1!=8 &&itsRecipe->seq2!=8 &&itsRecipe->seq3!=8)
        return;
    setEnableButtons(true);
    if(itsRecipe->seq1!=8)
    {
        setStepPer(itsRecipe->seq1,value);

    }
    if(itsRecipe->seq2!=8)
    {
        setStepPer(itsRecipe->seq2,100-value);
        ui->spd2->setValue(100-value);
    }

}

void WBSDDrink_Window::on_spd2_valueChanged(int value)
{
    if(itsRecipe->seq1!=8 &&itsRecipe->seq2!=8 &&itsRecipe->seq3!=8)
        return;
    setEnableButtons(true);
    if(itsRecipe->seq1!=8)
    {
        setStepPer(itsRecipe->seq1,100-value);
        ui->spd1->setValue(100-value);

    }
    if(itsRecipe->seq1!=8)
    {
        setStepPer(itsRecipe->seq2,value);

    }
}

void WBSDDrink_Window::on_sp1_valueChanged(int arg1)
{
    if(itsRecipe->seq1!=8 &&itsRecipe->seq2!=8 &&itsRecipe->seq3!=8)
        return;
    setEnableButtons(true);
    if(itsRecipe->seq1!=8)
    {
        setStepPer(itsRecipe->seq1,arg1);

    }
    if(itsRecipe->seq2!=8)
    {
        setStepPer(itsRecipe->seq2,100-arg1);
        ui->spd2->setValue(100-arg1);
    }
}

void WBSDDrink_Window::on_sp2_valueChanged(int arg1)
{
    if(itsRecipe->seq1!=8 &&itsRecipe->seq2!=8 &&itsRecipe->seq3!=8)
        return;
    setEnableButtons(true);
        if(itsRecipe->seq1!=8)
        {
            setStepPer(itsRecipe->seq1,100-arg1);
            ui->spd1->setValue(100-arg1);

        }
        if(itsRecipe->seq1!=8)
        {
            setStepPer(itsRecipe->seq2,arg1);

        }
}

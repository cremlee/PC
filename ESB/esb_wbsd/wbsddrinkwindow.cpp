#include "wbsddrinkwindow.h"
#include "ui_wbsddrinkwindow.h"
#include "wbsddrink_window.h"
#include "qdebug.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "application.h"
#include "databasehelper.h"

WBSDDrinkWindow::WBSDDrinkWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDDrinkWindow)
{
    static const char* back[] = {
                QT_TRANSLATE_NOOP("back_drink", "Back")
            };
    ui->setupUi(this);
    //drinkWindow = new WBSDDrink_Window;

    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
	menuBack->setEnabled(true);
    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
	updateData();
    button1DrinkWndw = 0;
    button2DrinkWndw = 0;
    button3DrinkWndw = 0;
    button4DrinkWndw = 0;
    button5DrinkWndw = 0;
    button6DrinkWndw = 0;
    button7DrinkWndw = 0;
    button8DrinkWndw = 0;
    ui->centralwidget->setLayout(ui->verticalLayout);
}

WBSDDrinkWindow::~WBSDDrinkWindow()
{
    delete ui;
}

void WBSDDrinkWindow::closeEvent(QCloseEvent *)
{

    emit iclose();
}

void WBSDDrinkWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
}

void WBSDDrinkWindow::on_button1_clicked()
{
    if (button1DrinkWndw==0){
        button1DrinkWndw = new WBSDDrink_Window(1,itsBaseWindow);
    crtDrink_Window = button1DrinkWndw;
    button1DrinkWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button1DrinkWndw,SIGNAL(destroyed()),this,SLOT(on_crtDrink_Window_destroyed()));
    }
    else
        button1DrinkWndw->reload(1);
    button1DrinkWndw->setWindowModality(Qt::ApplicationModal);
    button1DrinkWndw->show();
    this->hide();
    connect(button1DrinkWndw,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDDrinkWindow::on_button2_clicked()
{
    if (button2DrinkWndw==0)
    {
            button2DrinkWndw = new WBSDDrink_Window(2,itsBaseWindow);
        crtDrink_Window = button2DrinkWndw;
        button2DrinkWndw->setAttribute(Qt::WA_DeleteOnClose,true);
        connect(button2DrinkWndw,SIGNAL(destroyed()),this,SLOT(on_crtDrink_Window_destroyed()));
        }
    else
        button2DrinkWndw->reload(2);
    button2DrinkWndw->setWindowModality(Qt::ApplicationModal);
    button2DrinkWndw->show();
    this->hide();
    connect(button2DrinkWndw,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDDrinkWindow::on_button3_clicked()
{
    if (button3DrinkWndw==0)
    {
            button3DrinkWndw = new WBSDDrink_Window(3,itsBaseWindow);
        crtDrink_Window = button3DrinkWndw;
        button3DrinkWndw->setAttribute(Qt::WA_DeleteOnClose,true);
        connect(button3DrinkWndw,SIGNAL(destroyed()),this,SLOT(on_crtDrink_Window_destroyed()));
        }
    else
        button3DrinkWndw->reload(3);
    button3DrinkWndw->setWindowModality(Qt::ApplicationModal);
    button3DrinkWndw->show();
    this->hide();
    connect(button3DrinkWndw,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDDrinkWindow::on_button4_clicked()
{
    if (button4DrinkWndw==0)
    {
            button4DrinkWndw = new WBSDDrink_Window(4,itsBaseWindow);
        crtDrink_Window = button4DrinkWndw;
        button4DrinkWndw->setAttribute(Qt::WA_DeleteOnClose,true);
        connect(button4DrinkWndw,SIGNAL(destroyed()),this,SLOT(on_crtDrink_Window_destroyed()));
        }
    else
        button4DrinkWndw->reload(4);
    button4DrinkWndw->setWindowModality(Qt::ApplicationModal);
    button4DrinkWndw->show();
    this->hide();
    connect(button4DrinkWndw,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDDrinkWindow::on_button5_clicked()
{
    if (button5DrinkWndw==0)
    {
            button5DrinkWndw = new WBSDDrink_Window(5,itsBaseWindow);
        crtDrink_Window = button5DrinkWndw;
        button5DrinkWndw->setAttribute(Qt::WA_DeleteOnClose,true);
        connect(button5DrinkWndw,SIGNAL(destroyed()),this,SLOT(on_crtDrink_Window_destroyed()));
        }
    else
        button5DrinkWndw->reload(5);
    button5DrinkWndw->setWindowModality(Qt::ApplicationModal);
    button5DrinkWndw->show();
    this->hide();
    connect(button5DrinkWndw,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDDrinkWindow::on_button6_clicked()
{
    if (button6DrinkWndw==0)
    {
            button6DrinkWndw = new WBSDDrink_Window(6,itsBaseWindow);
        crtDrink_Window = button6DrinkWndw;
        button6DrinkWndw->setAttribute(Qt::WA_DeleteOnClose,true);
        connect(button6DrinkWndw,SIGNAL(destroyed()),this,SLOT(on_crtDrink_Window_destroyed()));
        }
    else
        button6DrinkWndw->reload(6);
    button6DrinkWndw->setWindowModality(Qt::ApplicationModal);
    button6DrinkWndw->show();
    this->hide();
    connect(button6DrinkWndw,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDDrinkWindow::on_button7_clicked()
{
    if (button7DrinkWndw==0)
    {
            button7DrinkWndw = new WBSDDrink_Window(7,itsBaseWindow);
        crtDrink_Window = button7DrinkWndw;
        button7DrinkWndw->setAttribute(Qt::WA_DeleteOnClose,true);
        connect(button7DrinkWndw,SIGNAL(destroyed()),this,SLOT(on_crtDrink_Window_destroyed()));
        }
    else
        button7DrinkWndw->reload(7);
    button7DrinkWndw->setWindowModality(Qt::ApplicationModal);
    button7DrinkWndw->show();
    this->hide();
    connect(button7DrinkWndw,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDDrinkWindow::on_button8_clicked()
{
    if (button8DrinkWndw==0)
    {
            button8DrinkWndw = new WBSDDrink_Window(8,itsBaseWindow);
        crtDrink_Window = button8DrinkWndw;
        button8DrinkWndw->setAttribute(Qt::WA_DeleteOnClose,true);
        connect(button8DrinkWndw,SIGNAL(destroyed()),this,SLOT(on_crtDrink_Window_destroyed()));
        }
    else
        button8DrinkWndw->reload(8);
    button8DrinkWndw->setWindowModality(Qt::ApplicationModal);
    button8DrinkWndw->show();
    this->hide();
    connect(button8DrinkWndw,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDDrinkWindow::on_crtDrink_Window_destroyed()
{
    if (crtDrink_Window == button1DrinkWndw) {
        button1DrinkWndw =0;
        return;}
    if (crtDrink_Window == button2DrinkWndw) {
        button2DrinkWndw =0;
        return;}
    if (crtDrink_Window == button3DrinkWndw) {
        button3DrinkWndw =0;
        return;}
    if (crtDrink_Window == button4DrinkWndw) {
        button4DrinkWndw =0;
        return;}
    if (crtDrink_Window == button5DrinkWndw) {
        button5DrinkWndw =0;
        return;}
    if (crtDrink_Window == button6DrinkWndw) {
        button6DrinkWndw =0;
        return;}
    if (crtDrink_Window == button7DrinkWndw) {
        button7DrinkWndw =0;
        return;}
    if (crtDrink_Window == button8DrinkWndw) {
        button8DrinkWndw =0;
        return;}

}

void WBSDDrinkWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    qDebug()<<"++++++++++++++++++++++++++++++++connectionStatusChanged"<<aStatus;

    if(aStatus<20)
    {
        qDebug()<<"++++++++++++++++++++++++++++++++connectionStatusChanged";
        isblockiclose = true;
        this->close();
        this->deleteLater();
    }
     itsBaseWindow->disconnectToMessages(this);
}

//QList<int> crtrcplst = DataBaseHelper::getInstance()->GetCurrentValidRcp("100",valLeftBIB,valRightBIB,valInstantCoffee);

void WBSDDrinkWindow::updateData()
{
        ParameterMsg msg26 (Message::MCB,Message::DP, 26);
        ParameterMsg msg (Message::MCB,Message::DP, 4);
		ParameterMsg msg0(Message::MCB,Message::DP, 6);
		ParameterMsg msg1(Message::MCB,Message::DP, 7);
		ParameterMsg msg2(Message::MCB,Message::DP, 8);
		ParameterMsg msg3(Message::MCB,Message::DP, 9);
         msg.getWord();
		msg0.getWord();
		msg1.getWord();
		msg2.getWord();
		msg3.getWord();
        msg26.getWord();
         itsBaseWindow->addMessageToQue(msg26);
        itsBaseWindow->addMessageToQue(msg);
		itsBaseWindow->addMessageToQue(msg0);
		itsBaseWindow->addMessageToQue(msg1);
		itsBaseWindow->addMessageToQue(msg2);
		itsBaseWindow->addMessageToQue(msg3);
	}

void WBSDDrinkWindow::setNorecip(int itsDb,int itsHiLo)
{
    ParameterMsg query(Message::MCB,Message::DP, itsDb, Message::SET_PARAMETER);
    query.setChar(itsHiLo,0);
    itsBaseWindow->addMessageToQue(query);
}

void WBSDDrinkWindow::gotMessage(Message aMsg)
{

    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DP)){
		int high=aMsg.getDataInt() & 0x00FF;
		int low=(aMsg.getDataInt() >> 8) & 0x00FF;
qDebug()<<"++++++++++++++++++++++++++++++++";
		qDebug() << aMsg.getData().toHex();
		qDebug() << low;
		qDebug() << high;
/*
 * need to do set no recipe function
 */
        switch(aMsg.getParameters().at(3)){
        case 26:
            fmuon = ((aMsg.getDataUInt()&0x40) ==0x40?1:0);
            break;
            case (4):
            valLeftBIB=(0xF000 & aMsg.getDataUInt()) >> 12;
            valRightBIB=(0x0F00 & aMsg.getDataUInt()) >> 8;
            valInstant=(0x00F0 & aMsg.getDataUInt()) >> 4;
            crtrcplst = DataBaseHelper::getInstance()->GetCurrentValidRcp("100",valLeftBIB,valRightBIB,valInstant,fmuon);
            qDebug()<<"++++++++++++++++++++++++++++++++"<<crtrcplst;
            break;
            case 6:
            if(!crtrcplst.contains(low) && low!=0)
            {
               low =0;
               setNorecip(6,1);
            }
            if(!crtrcplst.contains(high) && high!=0)
            {
               high =0;
               setNorecip(6,0);
            }
                ui->button1->setText(QString("[%1] %2").arg(low).arg(DataBaseHelper::getInstance()->getTabKatString("100",low)));
                ui->button2->setText(QString("[%1] %2").arg(high).arg(DataBaseHelper::getInstance()->getTabKatString("100",high)));
                break;
            case 7:
            if(!crtrcplst.contains(low) && low!=0)
            {
               low =0;
               setNorecip(7,1);
            }
            if(!crtrcplst.contains(high) && high!=0)
            {
               high =0;
               setNorecip(7,0);
            }
				ui->button3->setText(QString ("[%1] %2").arg(low).arg(DataBaseHelper::getInstance()->getTabKatString("100",low)));
				ui->button4->setText(QString ("[%1] %2").arg(high).arg(DataBaseHelper::getInstance()->getTabKatString("100",high)));
                break;
            case 8:
            if(!crtrcplst.contains(low) && low!=0)
            {
               low =0;
               setNorecip(8,1);
            }
            if(!crtrcplst.contains(high) && high!=0)
            {
               high =0;
               setNorecip(8,0);
            }
				ui->button5->setText(QString ("[%1] %2").arg(low).arg(DataBaseHelper::getInstance()->getTabKatString("100",low)));
				ui->button6->setText(QString ("[%1] %2").arg(high).arg(DataBaseHelper::getInstance()->getTabKatString("100",high)));
                break;
            case 9:
				ui->button7->setText(QString ("[%1] %2").arg(low).arg(DataBaseHelper::getInstance()->getTabKatString("100",low)));
				ui->button8->setText(QString ("[%1] %2").arg(high).arg(DataBaseHelper::getInstance()->getTabKatString("100",high)));
                break;
            default:
                break;
        }
    }

}

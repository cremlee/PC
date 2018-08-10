#include "wbsdtestingwindow.h"
#include "ui_wbsdtestingwindow.h"
#include "wbsdoutletwindow.h"
#include "wbsdboilerwindow.h"
#include "wbsdmixerswindow.h"
#include "wbsddoserwindow.h"
#include "wbsddisplaywindow.h"
#include "wbsdversionwindow.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "qdebug.h"
#include "application.h"
#define FMU_ON
WBSDTestingWindow::WBSDTestingWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDTestingWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_testing", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_testing",back[0]), this);
	menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    outletWindow = 0; //new WBSDOutletWindow;
    boilerWindow = new WBSDBoilerWindow; //RJ remove WBSDBoilerWindow class from project
    coolingWindow = new WBSDCoolingWindow; //RJ remove WBSDCoolingWindow class from project
    mixersWindow = new WBSDMixersWindow; //RJ remove WBSDMixersWindow class from project
    doserWindow = 0; //new WBSDDoserWindow;
    displayWindow = 0; //new WBSDDisplayWindow;
    versionWindow = 0; //new WBSDVersionWindow;
    wbsdexternwin =0;
    pumpWindow = 0;
    heaterWindow = 0;
    instantWindow = 0;
    paytest =0;

    _getflag = true;
    ParameterMsg queryServ1(Message::UIB,Message::DV,2);
    queryServ1.getNibble(0);
    itsBaseWindow->addMessageToQue(queryServ1);

    ParameterMsg queryServ(Message::UIB,Message::DV,2);
	queryServ.setNibble(0,5);
	itsBaseWindow->addMessageToQue(queryServ);
   /* Lee.li Modify 2014-9-24
      fix the screen show
    */
    ParameterMsg aaa(Message::MCB,Message::DP,4);
    aaa.getWord();
    itsBaseWindow->addMessageToQue(aaa);
    updateData();

    ui->paymentButton->hide();
    ui->centralwidget->setLayout(ui->verticalLayout);
#ifndef FMU_ON
    ui->btn_ext_tst->hide();
#endif
}

WBSDTestingWindow::~WBSDTestingWindow()
{
    delete ui;
}

void WBSDTestingWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
}

void WBSDTestingWindow::closeEvent(QCloseEvent *)
{
    //判断是否要回到
//    ParameterMsg queryServ(Message::UIB,Message::DV,2);
//    queryServ.setNibble(0,_LASTMODE);
//    itsBaseWindow->addMessageToQue(queryServ);
    if(!isblockiclose)
    {
    ParameterMsg queryServ(Message::UIB,Message::DV,2);
    queryServ.setNibble(0,_LASTMODE);
    itsBaseWindow->addMessageToQue(queryServ);
    }
}


void WBSDTestingWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
     qDebug()<<"WBSDTestingWindow::connectionStatusChanged("<<aStatus;
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        isblockiclose =true;
        this->close();
        this->deleteLater();
    }
}

void WBSDTestingWindow::on_outletButton_clicked()
{
    if (outletWindow==0)
        outletWindow = new WBSDOutletWindow(itsBaseWindow);
    outletWindow->show();
    this->hide();
    connect(outletWindow,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDTestingWindow::on_pumpButton_clicked()
{
    if (pumpWindow==0)
        pumpWindow = new WBSDPumpWindow(itsBaseWindow);
    pumpWindow->show();
    this->hide();
    connect(pumpWindow,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDTestingWindow::on_heaterButton_clicked()
{
    if (heaterWindow==0)
    {
        heaterWindow = new WBSDHeaterWindow(itsBaseWindow);    
        heaterWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        connect(heaterWindow,SIGNAL(destroyed()),this,SLOT(heaterWindow_dest()));
    }
    this->hide();
    connect(heaterWindow,SIGNAL(iclose()),this,SLOT(show()));
    heaterWindow->show();
}

void WBSDTestingWindow::on_instantButton_clicked()
{
    if (instantWindow==0)
        instantWindow = new WBSDInstantWindow(itsBaseWindow);
    instantWindow->show();
    this->hide();
    connect(instantWindow,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDTestingWindow::on_doserButton_clicked()
{
    if (doserWindow==0)
        doserWindow = new WBSDDoserWindow(itsBaseWindow);
    doserWindow->show();
    this->hide();
    connect(doserWindow,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDTestingWindow::on_displayButton_clicked()
{
    if (displayWindow==0)
        displayWindow = new WBSDDisplayWindow(itsBaseWindow);
    displayWindow->show();
    this->hide();
    connect(displayWindow,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDTestingWindow::on_paymentButton_clicked()
{

            if (paytest==0)
                paytest = new WBSDpaytest(itsBaseWindow);
            paytest->show();
            this->hide();
            connect(paytest,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDTestingWindow::on_versionsButton_clicked()
{
    if (versionWindow==0)
        versionWindow = new WBSDVersionWindow(itsBaseWindow);
    versionWindow->show();
    this->hide();
    connect(versionWindow,SIGNAL(iclose()),this,SLOT(show()));
}

void WBSDTestingWindow::updateData()
{
    ParameterMsg pmsg(Message::MCB,Message::DP,0);
    pmsg.getWord();
    itsBaseWindow->addMessageToQue(pmsg);

    ParameterMsg msg14(Message::MCB,Message::DP,26);
    msg14.getWord();
    itsBaseWindow->addMessageToQue(msg14);
}

void WBSDTestingWindow::heaterWindow_dest()
{
    heaterWindow=0;
}

void WBSDTestingWindow::UpdataPaytest(bool flag)
{
    ui->paymentButton->setEnabled(flag);
}

void WBSDTestingWindow::gotMessage(Message aMsg)
{
    unsigned int aVal,valInstant;
    char dpval;
    if ( _getflag && (aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::UIB) && (aMsg.getDataBaseType()==Message::DV)){

        if(aMsg.getParameters().at(3) == 2)
        {
            _getflag =false;
          _LASTMODE = aMsg.getDataInt();
          qDebug()<<"_LASTMODE"<<_LASTMODE;
        }
    }
   if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DP)){
       switch(aMsg.getParameters().at(3)){
           case 0:
           dpval = (aMsg.getDataInt() >> 8) & 0x00FF;
           if((dpval & 0x02) == 0x02)
           {
               UpdataPaytest(true);
           }else
           {
               UpdataPaytest(false);
           }
           break;
       case 4:
           aVal=aMsg.getDataUInt();
           valInstant=(0x00F0 & aVal) >> 4;
           if(valInstant == 13 || valInstant == 14 || valInstant == 15|| valInstant == 0)
           {
               ui->instantButton->setEnabled(false);
           }
           else
           {
              ui->instantButton->setEnabled(true);
           }
           break;
       case 26:
           aVal=aMsg.getDataUInt();
           if(((aVal&0x40)>>6) == 0)
            ui->btn_ext_tst->setEnabled(false);
           else
             ui->btn_ext_tst->setEnabled(true);
           break;
       default:
           break;
   }
   }
}


void WBSDTestingWindow::on_btn_ext_tst_clicked()
{
    if (wbsdexternwin==0)
        wbsdexternwin = new WBSD_EXTERN_TOOL(itsBaseWindow);
    wbsdexternwin->show();
    this->hide();
    connect(wbsdexternwin,SIGNAL(iclose()),this,SLOT(show()));
}

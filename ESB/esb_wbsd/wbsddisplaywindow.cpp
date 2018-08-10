#include "wbsddisplaywindow.h"
#include "ui_wbsddisplaywindow.h"
#include "wbsdchildwindow.h"
#include "qdebug.h"
#include "application.h"
#include <QThread>
/*
#define DB_LCD_ISNEW        &ui_dp[23],BIT03 //jerry 20150423 new LCD module
#define DB_SHOW_CUPANI      &ui_dp[23],BIT02 //jerry 20150423 new LCD module
*/
WBSDDisplayWindow::WBSDDisplayWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDDisplayWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_display", "Back")
    };

    static const char* soundtest[] = {
        QT_TRANSLATE_NOOP("display_soundtest", "No beep"),
        QT_TRANSLATE_NOOP("display_soundtest", "Safety error"),
        QT_TRANSLATE_NOOP("display_soundtest", "Error"),
        QT_TRANSLATE_NOOP("display_soundtest", "Cleaning"),
        QT_TRANSLATE_NOOP("display_soundtest", "Attention"),
        QT_TRANSLATE_NOOP("display_soundtest", "RFID")
    };

    static const char* LCDSelect[] = {
        QT_TRANSLATE_NOOP("LCDSelect", "OLD"),
        QT_TRANSLATE_NOOP("LCDSelect", "NEW")

    };
    static const char* LCDANI[] = {
        QT_TRANSLATE_NOOP("LCDANI", "HIDE"),
        QT_TRANSLATE_NOOP("LCDANI", "SHOW")

    };
    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_display",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    ui->soundTest->addItem(Application::translate("display_soundtest",soundtest[0]),0x0);
    ui->soundTest->addItem(Application::translate("display_soundtest",soundtest[1]),0x1);
    ui->soundTest->addItem(Application::translate("display_soundtest",soundtest[2]),0x2);
    ui->soundTest->addItem(Application::translate("display_soundtest",soundtest[3]),0x3);
    ui->soundTest->addItem(Application::translate("display_soundtest",soundtest[4]),0x4);
    ui->soundTest->addItem(Application::translate("display_soundtest",soundtest[5]),0x5);


    ui->cb_LCD->addItem(Application::translate("LCDSelect",LCDSelect[0]),0x0);
    ui->cb_LCD->addItem(Application::translate("LCDSelect",LCDSelect[1]),0x1);



    updateData();
    buttonTestWindow = 0;
    this->centralWidget()->setLayout(ui->verticalLayout);
    ui->pbrst->hide();
    if(itsBaseWindow->getMachineUnit() == WBSDBaseWindow::UNIT_USA)
    ui->cb_LCD->setEnabled(false);
}

WBSDDisplayWindow::~WBSDDisplayWindow()
{
    delete ui;
}

void WBSDDisplayWindow::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDDisplayWindow::on_menuBack_triggered()
{
    this->close();
}

void WBSDDisplayWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDDisplayWindow::on_lcdSegment_clicked()
{
    ParameterMsg message1(Message::UIB,Message::DV,0);
    message1.setBit(2,1);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDDisplayWindow::on_buttonTest_clicked()
{
    if (buttonTestWindow==0)
        buttonTestWindow = new WBSDButtonTestWindow(itsBaseWindow);
    connect(buttonTestWindow,SIGNAL(destroyed()),this,SLOT(testwclose()));
    connect(buttonTestWindow,SIGNAL(iclose()),this,SLOT(show()));
    this->hide();
    buttonTestWindow->show();
}

void WBSDDisplayWindow::on_soundTest_activated(int index)
{
    int value = ui->soundTest->itemData(index).toInt();

    QString qss=QString("RJDEBUG on_soundTest_activated value %1").arg(value);
    qDebug () << qss;
    /*modify lee.li 2014-9-25 beep
    write to CU DV block 16 nibble 0 a value of 1 to 5 to get different beeps.
    ParameterMsg query(Message::MCB,Message::DV, 3, Message::SET_PARAMETER);
    query.setWord(value << 4); */

//    ParameterMsg message1(Message::MCB,Message::DV,2, Message::SET_PARAMETER);

//    message1.setBit(10,1);
//    itsBaseWindow->addMessageToQue(message1);

    ParameterMsg query(Message::MCB,Message::DV,16, Message::SET_PARAMETER);
    query.setNibble(0,index);
    itsBaseWindow->addMessageToQue(query);
}

void WBSDDisplayWindow::on_pbrst_clicked()
{
    ParameterMsg queryServ(Message::UIB,Message::DV,2,Message::SET_PARAMETER);
    queryServ.setNibble(0,5);
    itsBaseWindow->addMessageToQue(queryServ);
}

void WBSDDisplayWindow::on_cb_LCD_activated(int index)
{
    ParameterMsg queryServ(Message::UIB,Message::DP,23,Message::SET_PARAMETER);
    queryServ.setBit(3,index);
    itsBaseWindow->addMessageToQue(queryServ);
}

void WBSDDisplayWindow::on_cb_Ani_activated(int index)
{
    ParameterMsg queryServ(Message::UIB,Message::DP,23,Message::SET_PARAMETER);
    queryServ.setBit(4,index);
    itsBaseWindow->addMessageToQue(queryServ);
}

void WBSDDisplayWindow::updateData()
{
    ParameterMsg query(Message::MCB,Message::DV, 16);
    query.getNibble(0);
    itsBaseWindow->addMessageToQue(query);

    ParameterMsg query1(Message::UIB,Message::DP, 23);
    query1.getWord();
    itsBaseWindow->addMessageToQue(query1);

}

void WBSDDisplayWindow::testwclose()
{
    buttonTestWindow=0;
}

void WBSDDisplayWindow::UpdateLCDInfo(uint a)
{


    if((a & 0x08)==0x08)
    {

        if(ui->cb_LCD->currentIndex()!=1)
        {
            ui->cb_LCD->setCurrentIndex(1);

        }
    }
    else
    {
        if(ui->cb_LCD->currentIndex()==1)
        {
        ui->cb_LCD->setCurrentIndex(0);

        }


    }
}

void WBSDDisplayWindow::gotMessage(Message aMsg)
{
   QString txt;
   unsigned int aVal;
   if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::UIB) && (aMsg.getDataBaseType()==Message::DP) )
   {

       if(aMsg.getParameters().at(3) == 23)
       {
           aVal = aMsg.getDataUInt();
           UpdateLCDInfo(aVal);
           qDebug()<<"UIB23=="<<aVal;
       }
   }
}

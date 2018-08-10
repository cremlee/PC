#include "wbsdpumpwindow.h"
#include "ui_wbsdpumpwindow.h"
#include "wbsdchildwindow.h"
#include "application.h"

WBSDPumpWindow::WBSDPumpWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDPumpWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_pump", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_pump",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    ui->rbibLabel->hide();
    ui->rbibPump->hide();
    /*Lee.li Modify 2014-9-24
      fix the screen show
    */
    ui->centralwidget->setLayout(ui->verticalLayout);
    ui->btn_setpump->hide();
    if(itsBaseWindow->getMachineUnit() ==WBSDBaseWindow::UNIT_USA)
    {
        ui->label_3->setEnabled(false);
        ui->lbibPump->setEnabled(false);
    }
}

WBSDPumpWindow::~WBSDPumpWindow()
{
    delete ui;
}

void WBSDPumpWindow::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDPumpWindow::on_menuBack_triggered()
{
    this->close();
}

void WBSDPumpWindow::on_btn_setpump_clicked()
{
//    ParameterMsg message1(Message::MCB,Message::DV,1);
//    ParameterMsg message2(Message::MCB,Message::DV,1);
//    message1.setBit(11,1);
//    message2.setBit(10,1);
//    itsBaseWindow->addMessageToQue(message2);
//    itsBaseWindow->addMessageToQue(message1);



    ParameterMsg message3(Message::MCB,Message::DV,1);
    message3.getWord();
    itsBaseWindow->addMessageToQue(message3);


}

void WBSDPumpWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDPumpWindow::on_waterPump_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,1);
    message2.setBit(14,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDPumpWindow::on_waterPump_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,16);
    message1.setBit(10,0);
    message2.setBit(14,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDPumpWindow::on_rbibPump_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,1);
    message2.setBit(13,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDPumpWindow::on_rbibPump_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,0);
    message2.setBit(13,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDPumpWindow::on_lbibPump_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,1);
    message2.setBit(12,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDPumpWindow::on_lbibPump_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2);
    ParameterMsg message2(Message::MCB,Message::DV,15);
    message1.setBit(10,0);
    message2.setBit(12,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDPumpWindow::updateData()
{
    qDebug() << "WBSDPumpWindow::updateData";
}

void WBSDPumpWindow::gotMessage(Message aMsg)
{
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DV) )
    {
        qDebug()<<"dv value ="<<aMsg.getDataUInt();
    }
}

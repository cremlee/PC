#include "wbsdcounterswindow.h"
#include "ui_wbsdcounterswindow.h"
#include "wbsdbuttoncounters.h"
#include "qdebug.h"
#include "wbsdchildwindow.h"
#include "application.h"

WBSDCountersWindow::WBSDCountersWindow(WBSDBaseWindow *parent) :
	WBSDChildWindow(parent),
    ui(new Ui::WBSDCountersWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_counter", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_counter",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    button1CountersWndw = 0;
    button2CountersWndw = 0;
    button3CountersWndw = 0;
    button4CountersWndw = 0;
    button5CountersWndw = 0;
    button6CountersWndw = 0;
    button7CountersWndw = 0;
    button8CountersWndw = 0;
    buttonTotalWndw = 0;
    ui->centralwidget->setLayout(ui->verticalLayout);
    /*Lee.li Modify 2014-9-24

    */
    ParameterMsg msg1(Message::MCB,Message::DP,0);
    msg1.getWord();
    itsBaseWindow->addMessageToQue(msg1);
}

WBSDCountersWindow::~WBSDCountersWindow()
{
    delete ui;
}

void WBSDCountersWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
}

void WBSDCountersWindow::connectionStatusChanged(int aStatus,StringMessage aMSG){
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDCountersWindow::on_button1_clicked()
{
	if (button1CountersWndw==0)
		button1CountersWndw = new WBSDButtonCounters(1,itsBaseWindow);
	else
		button1CountersWndw->updateData();
	button1CountersWndw->setWindowModality(Qt::ApplicationModal);
	button1CountersWndw->show();
    this->hide();
	//button1CountersWndw->deleteLater();
button1CountersWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button1CountersWndw,SIGNAL(iclose()),this,SLOT(show()));
    connect(button1CountersWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));

}

void WBSDCountersWindow::on_button2_clicked()
{
	if (button2CountersWndw==0)
		button2CountersWndw = new WBSDButtonCounters(2,itsBaseWindow);
	else
		button2CountersWndw->updateData();
	button2CountersWndw->setWindowModality(Qt::ApplicationModal);
	button2CountersWndw->show();
    this->hide();
    //button1CountersWndw->deleteLater();
button2CountersWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button2CountersWndw,SIGNAL(iclose()),this,SLOT(show()));
     connect(button2CountersWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));
}
void WBSDCountersWindow::on_button3_clicked()
{
	if (button3CountersWndw==0)
		button3CountersWndw = new WBSDButtonCounters(3,itsBaseWindow);
	else
		button3CountersWndw->updateData();
	button3CountersWndw->setWindowModality(Qt::ApplicationModal);
	button3CountersWndw->show();
    this->hide();
    //button1CountersWndw->deleteLater();
button3CountersWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button3CountersWndw,SIGNAL(iclose()),this,SLOT(show()));
     connect(button3CountersWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));
}

void WBSDCountersWindow::on_button4_clicked()
{
	if (button4CountersWndw==0)
		button4CountersWndw = new WBSDButtonCounters(4,itsBaseWindow);
	else
		button4CountersWndw->updateData();
	button4CountersWndw->setWindowModality(Qt::ApplicationModal);
	button4CountersWndw->show();
    this->hide();
    //button1CountersWndw->deleteLater();
button4CountersWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button4CountersWndw,SIGNAL(iclose()),this,SLOT(show()));
     connect(button4CountersWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));
}
void WBSDCountersWindow::on_button5_clicked()
{
	if (button5CountersWndw==0)
		button5CountersWndw = new WBSDButtonCounters(5,itsBaseWindow);
	else
		button5CountersWndw->updateData();
	button5CountersWndw->setWindowModality(Qt::ApplicationModal);
	button5CountersWndw->show();
    this->hide();
    //button1CountersWndw->deleteLater();
button5CountersWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button5CountersWndw,SIGNAL(iclose()),this,SLOT(show()));
    connect(button5CountersWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));
}
void WBSDCountersWindow::on_button6_clicked()
{
	if (button6CountersWndw==0)
		button6CountersWndw = new WBSDButtonCounters(6,itsBaseWindow);
	else
		button6CountersWndw->updateData();
	button6CountersWndw->setWindowModality(Qt::ApplicationModal);
	button6CountersWndw->show();
    this->hide();
    //button1CountersWndw->deleteLater();
button6CountersWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button6CountersWndw,SIGNAL(iclose()),this,SLOT(show()));
     connect(button6CountersWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));
}
void WBSDCountersWindow::on_button7_clicked()
{
	if (button7CountersWndw==0)
        button7CountersWndw = new WBSDbtn78cnt(7,itsBaseWindow);
	else
		button7CountersWndw->updateData();
	button7CountersWndw->setWindowModality(Qt::ApplicationModal);
	button7CountersWndw->show();
    this->hide();
    //button1CountersWndw->deleteLater();
button7CountersWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button7CountersWndw,SIGNAL(iclose()),this,SLOT(show()));
     connect(button7CountersWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));
}
void WBSDCountersWindow::on_button8_clicked()
{
	if (button8CountersWndw==0)
        button8CountersWndw = new WBSDbtn78cnt(8,itsBaseWindow);
	else
		button8CountersWndw->updateData();
	button8CountersWndw->setWindowModality(Qt::ApplicationModal);
	button8CountersWndw->show();
    this->hide();
    //button1CountersWndw->deleteLater();
button8CountersWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(button8CountersWndw,SIGNAL(iclose()),this,SLOT(show()));
    connect(button8CountersWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));
}
void WBSDCountersWindow::on_buttonTotal_clicked()
{
    if (buttonTotalWndw==0)
        buttonTotalWndw = new WBSDCountersTotal(itsBaseWindow);
    else
        buttonTotalWndw->updateData();
    buttonTotalWndw->setWindowModality(Qt::ApplicationModal);
    buttonTotalWndw->setAttribute(Qt::WA_DeleteOnClose,true);
    buttonTotalWndw->show();
    this->hide();
    //button1CountersWndw->deleteLater();

    connect(buttonTotalWndw,SIGNAL(iclose()),this,SLOT(show()));
    connect(buttonTotalWndw,SIGNAL(destroyed(int)),this,SLOT(destroywin(int)));
}

void WBSDCountersWindow::on_ResetCounters_clicked()
{
    static const char* reset[] = {
        QT_TRANSLATE_NOOP("counter_reset_txt", "Do you really want to reset all counters?")
    };

    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel); //Focus cancel button

    msgBox.setText(Application::translate("counter_reset_txt",reset[0]));

    int ret = msgBox.exec();
    switch (ret) {
        case QMessageBox::Ok:
            resetCounters();
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }
}

void WBSDCountersWindow::destroywin(int i)
{
    qDebug() << "WBSDCountersWindow::destroywin()";
    if(i==1)
    button1CountersWndw = 0;
    if(i==2)
    button2CountersWndw = 0;
    if(i==3)
    button3CountersWndw = 0;
    if(i==4)
    button4CountersWndw = 0;
    if(i==5)
    button5CountersWndw = 0;
    if(i==6)
    button6CountersWndw = 0;
    if(i==7)
    button7CountersWndw = 0;
    if(i==8)
    button8CountersWndw = 0;
    if(i==9)
    buttonTotalWndw = 0;
}

void WBSDCountersWindow::resetCounters()
{

	ParameterMsg msg(Message::UIB,Message::DV,0,Message::SET_PARAMETER);
    msg.setBit(13,1);
    itsBaseWindow->addMessageToQue(msg);

    ParameterMsg msg1(Message::MCB,Message::DV,17);
	msg1.getBit(5);
    itsBaseWindow->addMessageToQue(msg1);

}

void WBSDCountersWindow::stopReset()
{
	ParameterMsg msg(Message::UIB,Message::DV,0,Message::SET_PARAMETER);
    msg.setBit(13,0);
    itsBaseWindow->addMessageToQue(msg);

//	ParameterMsg msg1(Message::MCB,Message::DV,17,Message::SET_PARAMETER);
//	msg1.setBit(5,0);
//    itsBaseWindow->addMessageToQue(msg1);
}

void WBSDCountersWindow::gotMessage(Message aMsg)
{
    qDebug() << "WBSDCountersWindow::gotMessage";
    unsigned int aVal;
    QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
    aVal= 0xFFFF & aMsg.getDataUInt();
    Message::qtype atype=aMsg.getType();

    switch (atype){
        case (Message::REPLY_DB):

            switch ((unsigned char)aMsg.getBoard()){

                case (Message::MCB):
                    qDebug() << "WBSDCountersWindow::gotMessage MCB";
                    switch ((unsigned char)aMsg.getDataBaseType()){
                    case Message::DP:
                        switch(aMsg.getParameters().at(3)){
                    case (0):
                        aVal=aMsg.getDataUInt();
                        qDebug()<<"(0x8000 & aVal) >> 15"<<((0x8000 & aVal) >> 15);
                        itsBaseWindow->setUnitTmp((0x8000 & aVal) >> 15);
                        break;
                        }
                        case Message::DV:
                            switch(aMsg.getParameters().at(3)){
                                case (17):
                                    aVal= 0xFFFF & aMsg.getDataUInt();
                                    if (0x1 & aVal){
                                        stopReset();
									} else {
										ParameterMsg msg1(Message::MCB,Message::DV,17);
										msg1.getBit(5);
										itsBaseWindow->addMessageToQue(msg1);
									}

                                    break;
                                default:
                                    break;
                            }

                    }
                    break;
                case (Message::UIB):
                    qDebug() << "WBSDCountersWindow::gotMessage UIB";
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DV:
                            switch(aMsg.getParameters().at(3)){
                                case (0):
                                    qDebug() << "WBSDCountersWindow::gotMessage UIB DV0";
                                    aVal= 0xFFFF & aMsg.getDataUInt();
                                    qDebug() << "WBSDCountersWindow::gotMessage aVal=" << aVal;
                                    break;
                                default:
                                    break;
                            }

                    }

                    break;
            default:
                break;
            }
    }

}

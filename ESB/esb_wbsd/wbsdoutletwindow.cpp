#include "wbsdoutletwindow.h"
#include "ui_wbsdoutletwindow.h"
#include "qdebug.h"
#include "wbsdchildwindow.h"
#include "application.h"

WBSDOutletWindow::WBSDOutletWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDOutletWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_valves", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_valves",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    updateData();
    /*modify by Lee.Li
     */
    ui->centralwidget->setLayout(ui->gridLayout);
    if(itsBaseWindow->getMachineUnit() ==WBSDBaseWindow::UNIT_USA)
    {
        ui->label_2->setEnabled(false);
        ui->label_6->setEnabled(false);
        ui->label_8->setEnabled(false);
        ui->coldWaterValve->setEnabled(false);
        ui->lbibAirValve->setEnabled(false);
        ui->rbibAirValve->setEnabled(false);
    }
}

WBSDOutletWindow::~WBSDOutletWindow()
{
    delete ui;
}

void WBSDOutletWindow::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDOutletWindow::on_menuBack_triggered()
{
    this->close();
}

void WBSDOutletWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDOutletWindow::on_hotWaterValve_pressed()
{
	ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,1);
    message2.setBit(14,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDOutletWindow::on_hotWaterValve_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,0);
    message2.setBit(14,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDOutletWindow::on_coldWaterValve_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,1);
    message2.setBit(7,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDOutletWindow::on_coldWaterValve_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,0);
    message2.setBit(7,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDOutletWindow::on_normalOpenValve_pressed()
{
	ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,1);
    message2.setBit(4,1);
	qDebug() << "No 1";
    itsBaseWindow->addMessageToQue(message1);
	qDebug() << "No 2";
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDOutletWindow::on_normalOpenValve_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,0);
    message2.setBit(4,0);
	qDebug() << "No 2 r";
    itsBaseWindow->addMessageToQue(message2);
	qDebug() << "No 1 r";
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDOutletWindow::on_inletValve_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,1);
    message2.setBit(2,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDOutletWindow::on_inletValve_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,0);
    message2.setBit(2,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDOutletWindow::on_lbibValve_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,1);
    message2.setBit(8,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDOutletWindow::on_lbibValve_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,0);
    message2.setBit(8,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDOutletWindow::on_lbibAirValve_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,1);
    message2.setBit(10,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDOutletWindow::on_lbibAirValve_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,0);
    message2.setBit(10,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDOutletWindow::on_rbibValve_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,1);
    message2.setBit(9,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDOutletWindow::on_rbibValve_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,0);
    message2.setBit(9,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDOutletWindow::on_rbibAirValve_pressed()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,1);
    message2.setBit(11,1);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
}

void WBSDOutletWindow::on_rbibAirValve_released()
{
    ParameterMsg message1(Message::MCB,Message::DV,2,Message::SET_PARAMETER);
    ParameterMsg message2(Message::MCB,Message::DV,15,Message::SET_PARAMETER);
    message1.setBit(10,0);
    message2.setBit(11,0);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message1);
}

void WBSDOutletWindow::updateData()
{
    qDebug() << "WBSDOutletWindow::updateData";
}

void WBSDOutletWindow::gotMessage(Message aMsg)
{
}




#include "fmu_calibration.h"
#include "ui_fmu_calibration.h"
#include"fmu_test.h"
#include"parametermsg.h"
#include "fmu_message.h"
#include<qdebug.h>
#include<application.h>
static const char* back[] = {
        QT_TRANSLATE_NOOP("back_version", "Back")
    };
FMU_Calibration::FMU_Calibration(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::FMU_Calibration)
{

    ui->setupUi(this);
    currenttype = 0;
    myTimer=new QTimer(this);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(finishcal()));
    mtimer1 = new QTimer(this);
    ui->btn_cal_spd_1->setEnabled(false);
    ui->btn_cal_spd_2->setEnabled(false);
    ui->btn_cal_spd_3->setEnabled(false);
    ui->btn_cal_spd_4->setEnabled(false);

    ui->label_5->setVisible(false);
    ui->pb_4->setVisible(false);
    ui->btn_cal_100->setVisible(false);
    ui->btn_cal_spd_4->setVisible(false);
    ui->sp_cal_spd_4->setVisible(false);
    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    this->setWindowTitle(QObject::tr("MMP Calibration"));
}

FMU_Calibration::~FMU_Calibration()
{
    myTimer->stop();
    myTimer->deleteLater();
    myTimer=0;
    mtimer1->stop();
    mtimer1->deleteLater();
    mtimer1 =0;
    delete ui;
}

void FMU_Calibration::closeEvent(QCloseEvent *evt)
{
    if(!isblockiclose)
     emit iclose();
}

void FMU_Calibration::gotMessage(Message aMsg)
{
    qDebug()<<"got message=="<<aMsg.getMsg().toHex();

}

void FMU_Calibration::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        isblockiclose = true;
        this->close();
        this->deleteLater();
    }
}

void FMU_Calibration::updateCalSpdValue(QDoubleSpinBox *lb, int value)
{
    lb->setValue(value);
}

void FMU_Calibration::on_btn_cal_spd_1_clicked()
{
    //to-do : send cal msg to mcb
//    ParameterMsg msg(Message::UIB,Message::TV,fmu_test::CAL_30_SET);
//    msg.setFloat(ui->sp_cal_spd_1->value());
//    itsBaseWindow->addMessageToQue(msg);

    fmu_message msg;
    msg.CalibrationSet(0x10,30,(int)ui->sp_cal_spd_1->value());
    qDebug()<<"FMU_Calibration = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);
    ui->btn_cal_spd_1->setEnabled(false);
    QTimer::singleShot(4000,this,SLOT(enablesp1()));
}

void FMU_Calibration::on_btn_cal_spd_2_clicked()
{
//    //to-do : send cal msg to mcb
//    ParameterMsg msg(Message::UIB,Message::TV,fmu_test::CAL_50_SET);
//    msg.setFloat(ui->sp_cal_spd_2->value());
//    itsBaseWindow->addMessageToQue(msg);

    fmu_message msg;
    msg.CalibrationSet(0x10,50,(int)ui->sp_cal_spd_2->value());
    qDebug()<<"FMU_Calibration = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);
ui->btn_cal_spd_2->setEnabled(false);
        QTimer::singleShot(4000,this,SLOT(enablesp2()));
}

void FMU_Calibration::on_btn_cal_spd_3_clicked()
{
//    //to-do : send cal msg to mcb
//    ParameterMsg msg(Message::UIB,Message::TV,fmu_test::CAL_80_SET);
//    msg.setFloat(ui->sp_cal_spd_3->value());
//    itsBaseWindow->addMessageToQue(msg);

    fmu_message msg;
    msg.CalibrationSet(0x10,80,(int)ui->sp_cal_spd_3->value());
    qDebug()<<"FMU_Calibration = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);
ui->btn_cal_spd_3->setEnabled(false);
        QTimer::singleShot(4000,this,SLOT(enablesp3()));
}

void FMU_Calibration::on_btn_cal_30_clicked()
{
    itsBaseWindow->setOt(15000);
    fmu_message msg;
    msg.CalibrationRun(0x10,30);
    qDebug()<<"FMU_Calibration = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);

    currenttype = 1;
    myTimer->start(1000);
    ui->pb_1->setValue(0);
    ui->btn_cal_30->setEnabled(false);
}

void FMU_Calibration::on_btn_cal_50_clicked()
{
    itsBaseWindow->setOt(15000);
    fmu_message msg;
    msg.CalibrationRun(0x10,50);
    qDebug()<<"FMU_Calibration = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);

    currenttype = 2;
    myTimer->start(1000);
    ui->pb_2->setValue(0);
    ui->btn_cal_50->setEnabled(false);
}

void FMU_Calibration::on_btn_cal_80_clicked()
{
    itsBaseWindow->setOt(15000);
    fmu_message msg;
    msg.CalibrationRun(0x10,80);
    qDebug()<<"FMU_Calibration = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);

    currenttype = 3;
    myTimer->start(1000);
    ui->pb_3->setValue(0);
    ui->btn_cal_80->setEnabled(false);
}

void FMU_Calibration::finishcal()
{
    if(currenttype == 1)
    {
        ui->pb_1->setValue(ui->pb_1->value()+1);
        if(ui->pb_1->value()>=10)
        {
            myTimer->stop();
            ui->btn_cal_spd_1->setEnabled(true);
            ui->btn_cal_30->setEnabled(true);
        }
    }
    if(currenttype == 2)
    {
        ui->pb_2->setValue(ui->pb_2->value()+1);
        if(ui->pb_2->value()>=10)
        {
            myTimer->stop();
            ui->btn_cal_spd_2->setEnabled(true);
            ui->btn_cal_50->setEnabled(true);
        }
    }
    if(currenttype == 3)
    {
        ui->pb_3->setValue(ui->pb_3->value()+1);
        if(ui->pb_3->value()>=10)
        {
            myTimer->stop();
            ui->btn_cal_spd_3->setEnabled(true);
            ui->btn_cal_80->setEnabled(true);
        }
    }
    if(currenttype == 4)
    {
        myTimer->stop();
        ui->pb_4->setValue(ui->pb_4->value()+1);
        if(ui->pb_4->value()>=10)
        {
            ui->btn_cal_spd_4->setEnabled(true);
        }
    }
    itsBaseWindow->setOt(5000);
}

void FMU_Calibration::on_btn_cal_100_clicked()
{
    fmu_message msg;
    msg.CalibrationRun(0x10,100);
    qDebug()<<"FMU_Calibration = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);

    currenttype = 4;
    myTimer->start(1000);
    ui->pb_4->setValue(0);
}

void FMU_Calibration::on_btn_cal_spd_4_clicked()
{
    fmu_message msg;
    msg.CalibrationSet(0x10,100,(int)ui->sp_cal_spd_4->value());
    qDebug()<<"FMU_Calibration = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);
}

void FMU_Calibration::enablesp1()
{
    ui->btn_cal_spd_1->setEnabled(true);
    qDebug()<<"enablesp1 = ";
}

void FMU_Calibration::enablesp2()
{
    ui->btn_cal_spd_2->setEnabled(true);
}

void FMU_Calibration::enablesp3()
{
    ui->btn_cal_spd_3->setEnabled(true);
}

void FMU_Calibration::on_menuBack_triggered()
{
    this->close();
}

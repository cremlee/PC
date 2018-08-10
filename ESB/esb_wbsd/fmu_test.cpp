#include "fmu_test.h"
#include "ui_fmu_test.h"
#include"parametermsg.h"
#include"fmu_message.h"
#include"qdebug.h"
#include<application.h>
static const char* back[] = {
        QT_TRANSLATE_NOOP("back_version", "Back")
    };
fmu_test::fmu_test(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::fmu_test)
{
    ui->setupUi(this);
    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    myTimer = new QTimer(this);
    //updateinfo();
    fmu_message msg;
    msg.GetParam(110);
    qDebug()<<"send message=="<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);
    msg.GetParam(116);
    qDebug()<<"send message=="<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);

    ui->lbl_fth_efast->hide();
    ui->label_9->hide();
    ui->btn_fan_condensor->setVisible(false);
    ui->btn_flush->setVisible(false);
    this->setWindowTitle(QObject::tr("MMP testing"));
}

fmu_test::~fmu_test()
{
    myTimer->stop();
    myTimer->deleteLater();
    myTimer=0;
    delete ui;
}

void fmu_test::closeEvent(QCloseEvent *evt)
{
    if(!isblockiclose)
     emit iclose();
}

void fmu_test::gotMessage(Message aMsg)
{
    Message::qtype atype=aMsg.getType();
    if(atype == fmu_message::FMU_TEST)
    {
       bool f;
       int testID = aMsg.getMsg().mid(6,1).toHex().toInt(&f,16);
       int testResult = aMsg.getMsg().mid(4,2).toHex().toInt(&f,16);
       testResult = ((testResult&0x00ff)<< 8) +((testResult&0xff00) >>8);
       showtestresult(testID,testResult);
    }
    if(atype == fmu_message::FMU_PARAM_GET)
    {
       bool f;
       int flag = aMsg.getMsg().mid(4,4).toHex().toInt(&f,16);
       int value = aMsg.getMsg().mid(8,4).toHex().toInt(&f,16);
       if((flag ) == 110)
       {
           mConductivevalue=value;

       }else if(flag==116)
       {
           mplusevalue=value;
       }

    }
    qDebug()<<"got message=="<<aMsg.getMsg().toHex();
}

void fmu_test::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        isblockiclose = true;
        this->close();
        this->deleteLater();
    }
}



void fmu_test::valvetest(fmu_test::test_type type)
{
    if(type ==fmu_test::PUMP || type ==fmu_test::FLOW_METER )
    {
         ui->lbl_tst_info->setText("Warning: The machine will dispense during these tests");
    }
    else
    {
        ui->lbl_tst_info->setText("");
    }
    fmu_message msg;
    msg.TestFunc(type);
    qDebug()<<"valvetest = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);
}

void fmu_test::updateinfo()
{

        fmu_message msg;
        msg.TestFunc(0x81);
        itsBaseWindow->addMessageToQue(msg);

        msg.TestFunc(0x82);
        itsBaseWindow->addMessageToQue(msg);

        msg.TestFunc(0x84);
        itsBaseWindow->addMessageToQue(msg);

        msg.TestFunc(0x8A);
        itsBaseWindow->addMessageToQue(msg);

}

QString converttoresult(int result)
{
    if(result == 0)
    {
        return "NOT CONNECTED";
    }
    else if(result ==0x01)
    {
        return "OK";
    }
    else if(result ==0x02)
    {
        return "ERROR";
    }
    return "unknow";
}

//PUMP=0x01,
//VALVE_AIR=0x02,
//VALVE_INLET=0x03,
//VALVE_MILK=0x04,
//VALVE_CLEAN=0x05,
//VALVE_FLUSH=0x06,
//FAN_BOX =0x07,
//FAN_CONDENSOR=0x08,
//FLOW_METER=0x09,
//FTH_ELEMENT_1=0x0A,
//FTH_ELEMENT_2=0x0B,
//COMPRESSOR=0x0C,
void fmu_test::showtestresult(int id, int result)
{
    QString part="";
     QString info;
    switch (id) {
    case PUMP:
        part = "PUMP:"+converttoresult(result);
        itsBaseWindow->setOt(5000);
        break;
    case VALVE_AIR:
        part = "VALVE_AIR:"+converttoresult(result);
        break;
    case VALVE_INLET:
        part = "VALVE_INLET:"+converttoresult(result);
        break;
    case VALVE_MILK:
        part = "VALVE_MILK:"+converttoresult(result);
        break;
    case VALVE_CLEAN:
        part = "VALVE_CLEAN:"+converttoresult(result);
        break;
    case VALVE_FLUSH:
        part = "VALVE_FLUSH:"+converttoresult(result);
        break;
    case FAN_BOX:
        part = "FAN_BOX:"+converttoresult(result);
        break;
    case FAN_CONDENSOR:
        part = "FAN_CONDENSOR:"+converttoresult(result);
        break;
    case FLOW_METER:
        part = "FLOW_METER:"+QString::number(result)+" pulses (approximately: "+QString::number(1000.f*result/mplusevalue)+"ml)";
        itsBaseWindow->setOt(5000);
        break;
    case FTH_ELEMENT_1:
        part = "FTH_ELEMENT_1:"+converttoresult(result);
        break;
    case FTH_ELEMENT_2:
        part = "FTH_ELEMENT_2:"+converttoresult(result);
        break;
    case 0x81:
        info = "milk";
        if(mConductivevalue<result)
        {
            info="air or water";
        }
        ui->lbl_sor_conductive->setText(info);
        break;
    case 0x82:
        ui->lbl_ntc_mix->setText(QString().sprintf("%.2f",result/10.f)+" ℃");
        break;
    case 0x83:
         //ui->lbl_ntc_cool->setText(QString::number(result));
        break;
    case 0x84:
        ui->lbl_fth_efast->setText(QString::number(result));
        break;
    case 0x85:
       // ui->lbl_fth_current_1->setText(QString::number(result));
        break;
    case 0x86:
       // ui->lbl_fth_current_2->setText(QString::number(result));
        break;
    case 0x87:
       // ui->lbl_sor_fth_1->setText(QString::number(result));
        break;
    case 0x88:
       // ui->lbl_sor_fth_2->setText(QString::number(result));
        break;
    case 0x89:
       // ui->lbl_ntc_fth->setText(QString::number(result));
        break;
    case 0x8A:
        ui->lbl_sor_milk->setText((result==1?"ON":"OFF"));
        if(ui->tabWidget->currentIndex()==1)
        {
            myTimer->singleShot(1000,this,SLOT(updateinfo()));
        }
        break;
    case 0x8B:
       // ui->lbl_sor_clean->setText(QString::number(result));
        break;
    default:
        break;
    }
    if(part!="")
    {
        ui->lbl_tst_info->setText(part);
    }
}



void fmu_test::on_btn_flush_clicked()
{
    valvetest(fmu_test::VALVE_FLUSH);
}

void fmu_test::on_btn_inlet_clicked()
{
    valvetest(fmu_test::VALVE_INLET);
}

void fmu_test::on_btn_milk_clicked()
{
    valvetest(fmu_test::VALVE_MILK);
}

void fmu_test::on_btn_clean_clicked()
{
    valvetest(fmu_test::VALVE_CLEAN);
}

void fmu_test::on_btn_air_clicked()
{
    valvetest(fmu_test::VALVE_AIR);
}

void fmu_test::on_btn_pump_clicked()

{

    itsBaseWindow->setOt(15000);
    valvetest(fmu_test::PUMP);
}

void fmu_test::on_btn_fan_box_clicked()
{
    valvetest(fmu_test::FAN_BOX);
}

void fmu_test::on_btn_fan_condensor_clicked()
{
    valvetest(fmu_test::FAN_CONDENSOR);
}

void fmu_test::on_btn_relay_1_clicked()
{
    valvetest(fmu_test::FTH_ELEMENT_1);
}

void fmu_test::on_btn_relay_2_clicked()
{
    valvetest(fmu_test::FTH_ELEMENT_2);
}

void fmu_test::on_btn_compressor_clicked()
{
    valvetest(fmu_test::COMPRESSOR);
}

void fmu_test::on_btn_flowmeter_clicked()

{
    itsBaseWindow->setOt(15000);
    valvetest(fmu_test::FLOW_METER);
}

void fmu_test::on_tabWidget_currentChanged(int index)
{
    ui->lbl_tst_info->setText("");
    if(index == 1)
    {
        updateinfo();
    }else
    {

    }
}

void fmu_test::on_menuBack_triggered()
{
     this->close();
}

#include "fmu_setting.h"
#include "ui_fmu_setting.h"
#include"application.h"
#include "fmu_clone.h"
#include "parametermsg.h"
#include<QMessageBox>
static const char* back[] = {
        QT_TRANSLATE_NOOP("back_version", "Back")
    };
/*2.	Heating opt bit for PC-TOOL  cu_dp 33, bit00*/
static const char* FMUSet[] = {
    QT_TRANSLATE_NOOP("fmu_set", "ON"),
    QT_TRANSLATE_NOOP("fmu_set", "OFF")
};

static const char* Hardness[] = {
    QT_TRANSLATE_NOOP("hardness", "<8"),
    QT_TRANSLATE_NOOP("hardness", "8"),
    QT_TRANSLATE_NOOP("hardness", "9"),
    QT_TRANSLATE_NOOP("hardness", "10"),
    QT_TRANSLATE_NOOP("hardness", "11"),
    QT_TRANSLATE_NOOP("hardness", "12"),
    QT_TRANSLATE_NOOP("hardness", "14"),
    QT_TRANSLATE_NOOP("hardness", "15"),
    QT_TRANSLATE_NOOP("hardness", "16"),
    QT_TRANSLATE_NOOP("hardness", "17"),
    QT_TRANSLATE_NOOP("hardness", "18")
};

FMU_SETTING::FMU_SETTING(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::FMU_SETTING)
{
    paramsetwin =0;
    fmutestwin=0;
    fmuerrorwin =0;
    fmucalibrationwin=0;
    fmuupwin =0;
    fmuclonewin =0;
    ui->setupUi(this);
    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    ui->cb_element_switch->addItem(Application::translate("fmu_set",FMUSet[1]),0x0);
    ui->cb_element_switch->addItem(Application::translate("fmu_set",FMUSet[0]),0x1);   

    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[0]),0);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[1]),180);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[2]),170);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[3]),160);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[4]),150);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[5]),140);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[6]),100);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[7]),80);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[8]),60);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[9]),40);
    ui->cb_hardness->addItem(Application::translate("hardness",Hardness[10]),20);

    ui->btn_up->setVisible(false);
    ui->btn_error->setVisible(false);
    this->setWindowTitle(QObject::tr("MMP Setting"));
    ParameterMsg queryd(Message::MCB,Message::DP, 33);
    queryd.getWord();
    itsBaseWindow->addMessageToQue(queryd);
    fmu_message msg;
    msg.GetParam(124);
    itsBaseWindow->addMessageToQue(msg);
}



FMU_SETTING::~FMU_SETTING()
{
    delete ui;

}

void FMU_SETTING::closeEvent(QCloseEvent *evt)
{
    if(!isblockiclose)
    emit iclose();
}


void FMU_SETTING::gotMessage(Message aMsg)
{
    unsigned int aVal;
    int flag ;
    int value;
    bool f;
    QByteArray data=aMsg.getData();
    Message::qtype atype=aMsg.getType();
    switch (atype){
        case (Message::REPLY_DB):
            switch ((unsigned char)aMsg.getBoard()){
                case (Message::MCB):
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DP:
                            switch(aMsg.getParameters().at(3)){
                                case (33):
                                    aVal=aMsg.getDataUInt();
                                    update_cb_element_switch(aVal&0x01);
                                    break;
                                default:
                                    break;
                            }
                    }
                    break;
            }
             break;
    case fmu_message::FMU_PARAM_GET:
         flag = aMsg.getMsg().mid(4,4).toHex().toInt(&f,16);
         value = aMsg.getMsg().mid(8,4).toHex().toInt(&f,16);
        if((flag &0xffff0000) == 0)
        {
            if(flag == 124)
            {
                updateHardness(value);
                if(value >0)
                {
                    ui->lbl_descale->setText("ON");
                }
                else
                {
                    ui->lbl_descale->setText("OFF");
                }
            }
        }
        break;
    }
}

void FMU_SETTING::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        isblockiclose = true;
        this->close();
        this->deleteLater();
    }
}

void FMU_SETTING::on_btn_param_clicked()
{
    if (paramsetwin==0)
        paramsetwin = new FMU_PARAMETER(itsBaseWindow);
    paramsetwin->setAttribute(Qt::WA_DeleteOnClose,true);
    paramsetwin->show();
    this->hide();
    connect(paramsetwin,SIGNAL(iclose()),this,SLOT(show()));
    connect(paramsetwin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void FMU_SETTING::on_btn_test_clicked()
{
    if (fmutestwin==0)
        fmutestwin = new fmu_test(itsBaseWindow);
    fmutestwin->setAttribute(Qt::WA_DeleteOnClose,true);
    fmutestwin->show();
    this->hide();
    connect(fmutestwin,SIGNAL(iclose()),this,SLOT(show()));
    connect(fmutestwin,SIGNAL(destroyed()),this,SLOT(destroywin()));

}

void FMU_SETTING::on_btn_error_clicked()
{
            if (fmuerrorwin==0)
                fmuerrorwin = new fmu_error(itsBaseWindow);
            fmuerrorwin->setAttribute(Qt::WA_DeleteOnClose,true);
            fmuerrorwin->show();
            this->hide();
            connect(fmuerrorwin,SIGNAL(iclose()),this,SLOT(show()));
            connect(fmuerrorwin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void FMU_SETTING::on_btn_cal_clicked()
{
    if (fmucalibrationwin==0)
        fmucalibrationwin = new FMU_Calibration(itsBaseWindow);
    fmucalibrationwin->setAttribute(Qt::WA_DeleteOnClose,true);
    fmucalibrationwin->show();
    this->hide();
    connect(fmucalibrationwin,SIGNAL(iclose()),this,SLOT(show()));
    connect(fmucalibrationwin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void FMU_SETTING::on_btn_up_clicked()
{
    if (fmuupwin==0)
        fmuupwin = new FMU_UPDATE(itsBaseWindow);
    fmuupwin->setAttribute(Qt::WA_DeleteOnClose,true);
    fmuupwin->show();
    this->hide();
    connect(fmuupwin,SIGNAL(iclose()),this,SLOT(show()));
    connect(fmuupwin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void FMU_SETTING::destroywin()
{
     paramsetwin=0;
     fmutestwin=0;
     fmucalibrationwin=0;
     fmuerrorwin=0;
     fmuupwin=0;
    fmuclonewin=0;
}

void FMU_SETTING::on_cb_element_switch_activated(int index)
{
    //todo:set conf to wbsd
    ParameterMsg query1(Message::MCB,Message::DP, 33, Message::SET_PARAMETER);
    int value = ui->cb_element_switch->itemData(index).toInt();
    query1.setBit(0,value);
    itsBaseWindow->addMessageToQue(query1);
}

void FMU_SETTING::update_cb_element_switch(int conf)
{
    int noItems = ui->cb_element_switch->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->cb_element_switch->itemData(index).toInt();
        if (conf==itemVal) {
            ui->cb_element_switch->setCurrentIndex(index);
            break;
        }
    }
}

void FMU_SETTING::updateHardness(int value)
{
    int noItems = ui->cb_hardness->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->cb_hardness->itemData(index).toInt();
        if (value==itemVal) {
            ui->cb_hardness->setCurrentIndex(index);
            break;
        }
    }
}



void FMU_SETTING::on_btn_clone_clicked()
{
    if (fmuclonewin==0)
        fmuclonewin = new FMU_CLONE(itsBaseWindow);
    fmuclonewin->setAttribute(Qt::WA_DeleteOnClose,true);
    fmuclonewin->show();
    this->hide();
    connect(fmuclonewin,SIGNAL(iclose()),this,SLOT(show()));
    connect(fmuclonewin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void FMU_SETTING::on_menuBack_triggered()
{
    this->close();
}

void FMU_SETTING::on_pbtn_rest_clicked()
{
    fmu_message msg;
    msg.ResetDescaleCounter();
    itsBaseWindow->addMessageToQue(msg);
}

void FMU_SETTING::on_cb_hardness_activated(int index)
{
    fmu_message msg;
    int value = ui->cb_hardness->itemData(index).toInt();
    msg.SetParam(124,value);
    itsBaseWindow->addMessageToQue(msg);
    if(value <=100 && value!=0)
    {
        QMessageBox::about(NULL, "Warning", "Please install softener for MMP");
    }
}

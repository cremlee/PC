#include "fmu_error.h"
#include "ui_fmu_error.h"
#include"parametermsg.h"
#include"fmu_test.h"
fmu_error::fmu_error(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::fmu_error)
{
    ui->setupUi(this);
    InitListview();
    myTimer = new QTimer(this);
    geterror();
}

fmu_error::~fmu_error()
{
    myTimer->stop();
    myTimer->deleteLater();
    myTimer=0;
    delete ui;
}

void fmu_error::closeEvent(QCloseEvent *evt)
{
     emit iclose();
}

void fmu_error::gotMessage(Message aMsg)
{
    Message::qtype atype=aMsg.getType();
    switch (atype){
    case (Message::REPLY_DB):
        switch ((unsigned char)aMsg.getBoard()){
        case Message::UIB:
            switch ((unsigned char)aMsg.getDataBaseType())
            {
                case Message::TV:
                    switch(aMsg.getParameters().at(3)){
                        case fmu_test::ERROR_H:
                            refreshHmask(aMsg.getDataInt());
                            if (myTimer!=0)
                                myTimer->singleShot(2000,this,SLOT(geterror()));
                            break;
                        case fmu_test::ERROR_L:
                            refreshLmask(aMsg.getDataInt());
                            break;
                    }
                    break;
            }
            break;
        }
    }
}

void fmu_error::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void fmu_error::geterror()
{
    ParameterMsg msg(Message::UIB,Message::TV,fmu_test::ERROR_H);
    msg.setWord(1);
    itsBaseWindow->addMessageToQue(msg);

    ParameterMsg msg1(Message::UIB,Message::TV,fmu_test::ERROR_L);
    msg1.setWord(1);
    itsBaseWindow->addMessageToQue(msg1);
}

void fmu_error::InitListview()
{
    QListWidgetItem *pump_item = new QListWidgetItem();
    //dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
    pump_item->setText(tr("Pump"));
    ui->listWidget->addItem(pump_item);

    QListWidgetItem *valve_item = new QListWidgetItem();
    //dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
    valve_item->setText(tr("Valves"));
    ui->listWidget->addItem(valve_item);

    QListWidgetItem *sensor_item = new QListWidgetItem();
    //dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
    sensor_item->setText(tr("Sensors"));
    ui->listWidget->addItem(sensor_item);

    QListWidgetItem *fan_item = new QListWidgetItem();
    //dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
    fan_item->setText(tr("Fans"));
    ui->listWidget->addItem(fan_item);

    QListWidgetItem *pcb_item = new QListWidgetItem();
    //dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
    pcb_item->setText(tr("PCB"));
    ui->listWidget->addItem(pcb_item);

    QListWidgetItem *fth_item = new QListWidgetItem();
    //dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
    fth_item->setText(tr("FTH module"));
    ui->listWidget->addItem(fth_item);

    QListWidgetItem *cleaning_item = new QListWidgetItem();
    //dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
    cleaning_item->setText(tr("cleaning"));
    ui->listWidget->addItem(cleaning_item);

    QListWidgetItem *container_item = new QListWidgetItem();
    //dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
    container_item->setText(tr("container"));
    ui->listWidget->addItem(container_item);

    ui->listWidget->setStyleSheet("QListWidget{border:1px solid gray; color:black; }"
                               "QListWidget::Item{padding-top:20px; padding-bottom:4px; }"
                               "QListWidget::Item:hover{background:skyblue; }"
                               "QListWidget::item:selected{background:lightgray; color:red; }"
                               "QListWidget::item:selected:!active{border-width:0px; background:lightgreen; }"
                               );

}

void fmu_error::updateData()
{

}

void fmu_error::refreshHmask(int mask)
{
    refreshUi(ui->lb_bit_0,0,mask);
    refreshUi(ui->lb_bit_1,1,mask);
    refreshUi(ui->lb_bit_2,2,mask);
    refreshUi(ui->lb_bit_3,3,mask);
    refreshUi(ui->lb_bit_4,4,mask);
    refreshUi(ui->lb_bit_10,10,mask);
    refreshUi(ui->lb_bit_11,11,mask);
    refreshUi(ui->lb_bit_12,12,mask);
    refreshUi(ui->lb_bit_13,13,mask);
    refreshUi(ui->lb_bit_14,14,mask);
    refreshUi(ui->lb_bit_15,15,mask);
    refreshUi(ui->lb_bit_16,16,mask);
    refreshUi(ui->lb_bit_17,17,mask);
    refreshUi(ui->lb_bit_18,18,mask);
    refreshUi(ui->lb_bit_19,19,mask);
    refreshUi(ui->lb_bit_20,20,mask);
    refreshUi(ui->lb_bit_21,21,mask);
    refreshUi(ui->lb_bit_22,22,mask);
    refreshUi(ui->lb_bit_23,23,mask);
    refreshUi(ui->lb_bit_24,24,mask);
    refreshUi(ui->lb_bit_25,25,mask);
    refreshUi(ui->lb_bit_26,26,mask);
    refreshUi(ui->lb_bit_28,28,mask);
    refreshUi(ui->lb_bit_29,29,mask);
    refreshUi(ui->lb_bit_30,30,mask);
    refreshUi(ui->lb_bit_31,31,mask);
}

void fmu_error::refreshLmask(int mask)
{
    refreshUi(ui->lb_bit_32,0,mask);
    refreshUi(ui->lb_bit_33,1,mask);
    refreshUi(ui->lb_bit_35,3,mask);
    refreshUi(ui->lb_bit_36,4,mask);
    refreshUi(ui->lb_bit_37,5,mask);
    refreshUi(ui->lb_bit_38,6,mask);
    refreshUi(ui->lb_bit_40,8,mask);
    refreshUi(ui->lb_bit_41,9,mask);
    refreshUi(ui->lb_bit_42,10,mask);
    refreshUi(ui->lb_bit_43,11,mask);
    refreshUi(ui->lb_bit_44,12,mask);
    refreshUi(ui->lb_bit_45,13,mask);
    refreshUi(ui->lb_bit_46,14,mask);
    refreshUi(ui->lb_bit_47,15,mask);
    refreshUi(ui->lb_bit_50,18,mask);
    refreshUi(ui->lb_bit_51,19,mask);
    refreshUi(ui->lb_bit_52,20,mask);
    refreshUi(ui->lb_bit_53,21,mask);
    refreshUi(ui->lb_bit_54,22,mask);
    refreshUi(ui->lb_bit_55,23,mask);
    refreshUi(ui->lb_bit_56,24,mask);
//    refreshUi(ui->lb_bit_63,0,mask);
//    refreshUi(ui->lb_bit_0,0,mask);
//    refreshUi(ui->lb_bit_0,0,mask);
//    refreshUi(ui->lb_bit_0,0,mask);
}

void fmu_error::refreshUi(QLabel *lable, int index, int maskvalue)
{
    QString price = "NA";
    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::green);


    bool bitvalue = ((maskvalue >>index) & 0x01)==0x01?true:false;
    if(bitvalue)
    {
        price ="Error";
        pe.setColor(QPalette::WindowText, Qt::red);
    }
    lable->setText(price);
    lable->setPalette(pe);
}



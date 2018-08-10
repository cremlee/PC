#include "wbsd_happyhour.h"
#include "ui_wbsd_happyhour.h"
#include"application.h"
#include"parametermsg.h"
/*
 *
 *2015-02-12 add happy hour function.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

wbsdHappyHour::wbsdHappyHour(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::wbsdHappyHour)
{
    static const char* back[] = {
            QT_TRANSLATE_NOOP("back_version", "Back")
        };
    ui->setupUi(this);
    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    connect(ui->chb_mode1,SIGNAL(clicked()),this,SLOT(upSetUi()));
    connect(ui->chb_mode2,SIGNAL(clicked()),this,SLOT(upSetUi()));
    connect(ui->chb_mode3,SIGNAL(clicked()),this,SLOT(upSetUi()));
    updateData();
}

wbsdHappyHour::~wbsdHappyHour()
{
    delete ui;
}

void wbsdHappyHour::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void wbsdHappyHour::gotMessage(Message aMsg)
{
    quint16 uval=0;
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DP) )
    {
        uval = aMsg.getDataUInt();
        switch(aMsg.getParameters().at(3)){
        case 34:
            DPHappyHourUp(ui->mode1_tes,uval);
            break;
        case 35:
            DPHappyHourUp(ui->mode1_tee,uval);
            break;
        case 36:
            DPHappyHourUp(ui->mode2_tes,uval);
            break;
        case 37:
            DPHappyHourUp(ui->mod2_tee,uval);
            break;
        case 38:
            DPHappyHourUp(ui->mod3_tes,uval);
            break;
        case 39:
           DPHappyHourUp(ui->mod3_tee,uval);
            break;
        case 40:
           DPHappyHourSetFlag(uval);
            break;
        default:
            break;
        }
    }
}

void wbsdHappyHour::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void wbsdHappyHour::SetDPHappyHourTm(int block,QTimeEdit* a)
{
    int hour = a->time().hour();
    int minute = a->time().minute();
    int value = ((0xFF & hour) << 8) | (0xFF & minute);

    ParameterMsg message(Message::MCB,Message::DP, block, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void wbsdHappyHour::DPHappyHourUp(QTimeEdit *a, quint16 val)
{
    int hour, minute;
    hour = (0xFF00 & val) >> 8;
    minute = 0xFF & val;
    a->setTime(QTime(hour,minute));
}

void wbsdHappyHour::DPHappyHourSetFlag(quint16 val)
{
    ui->chb_mode1->setChecked(((val&0x02) ==0x02));
    ui->chb_mode2->setChecked(((val&0x04) ==0x04));
    ui->chb_mode3->setChecked(((val&0x08) ==0x08));
}

void wbsdHappyHour::updateData()
{
    for(int i=34;i<=40;i++)
    {
        ParameterMsg message(Message::MCB,Message::DP,i);
        message.getWord();
        itsBaseWindow->addMessageToQue(message);
    }
}

void wbsdHappyHour::on_menuBack_triggered()
{
    this->close();
}

void wbsdHappyHour::on_mode1_tes_editingFinished()
{
    SetDPHappyHourTm(34,ui->mode1_tes);
}

void wbsdHappyHour::on_mode1_tee_editingFinished()
{
    SetDPHappyHourTm(35,ui->mode1_tee);
}

void wbsdHappyHour::on_mode2_tes_editingFinished()
{
    SetDPHappyHourTm(36,ui->mode2_tes);
}

void wbsdHappyHour::on_mod2_tee_editingFinished()
{
    SetDPHappyHourTm(37,ui->mod2_tee);
}

void wbsdHappyHour::on_mod3_tes_editingFinished()
{
    SetDPHappyHourTm(38,ui->mod3_tes);
}

void wbsdHappyHour::on_mod3_tee_editingFinished()
{
    SetDPHappyHourTm(39,ui->mod3_tee);
}

void wbsdHappyHour::upSetUi()
{
    ui->gridLayout2->setEnabled(ui->chb_mode1->isChecked());
    ui->gridLayout3->setEnabled(ui->chb_mode2->isChecked());
    ui->gridLayout4->setEnabled(ui->chb_mode3->isChecked());

    int value =0;
    if(ui->chb_mode1->isChecked()) value +=2;
    if(ui->chb_mode2->isChecked()) value +=4;
    if(ui->chb_mode3->isChecked()) value +=8;
    ParameterMsg message(Message::MCB,Message::DP, 40, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);

}

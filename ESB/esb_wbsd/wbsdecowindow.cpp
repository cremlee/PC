#include "wbsdecowindow.h"
#include "ui_wbsdecowindow.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "qdebug.h"
#include "application.h"
#include"QMessageBox"
WBSDEcoWindow::WBSDEcoWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDEcoWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_eco", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_eco",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    boardDp0BitField = 0;
    updateLabels();
    updateData();
    ui->centralwidget->setLayout(ui->verticalLayout);
}

WBSDEcoWindow::~WBSDEcoWindow()
{
    delete ui;
}

void WBSDEcoWindow::on_menuBack_triggered()
{
    this->close();
}

void WBSDEcoWindow::on_Tedt_1_editingFinished()
{
    if(compareTm(ui->Pdt_1,ui->Tedt_1))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_1->setTime(ui->Pdt_1->time());
    }else
    {
    SetECODPVal(44,ui->Tedt_1);
    }
}

void WBSDEcoWindow::on_Tedt_2_editingFinished()
{
    if(compareTm(ui->Pdt_2,ui->Tedt_2))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_2->setTime(ui->Pdt_2->time());
    }else
    {
    SetECODPVal(46,ui->Tedt_2);
    }
}

void WBSDEcoWindow::on_Tedt_3_editingFinished()
{
    if(compareTm(ui->Pdt_3,ui->Tedt_3))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_3->setTime(ui->Pdt_3->time());
    }else
    {
    SetECODPVal(48,ui->Tedt_3);
    }
}

void WBSDEcoWindow::on_Tedt_4_editingFinished()
{
    if(compareTm(ui->Pdt_4,ui->Tedt_4))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_4->setTime(ui->Pdt_4->time());
    }else
    {
    SetECODPVal(50,ui->Tedt_4);
    }
}

void WBSDEcoWindow::on_Tedt_5_editingFinished()
{
    if(compareTm(ui->Pdt_5,ui->Tedt_5))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_5->setTime(ui->Pdt_5->time());
    }else
    {
    SetECODPVal(52,ui->Tedt_5);
    }
}

void WBSDEcoWindow::on_Tedt_6_editingFinished()
{
    if(compareTm(ui->Pdt_6,ui->Tedt_6))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_6->setTime(ui->Pdt_6->time());
    }
    else
    {
        SetECODPVal(54,ui->Tedt_6);
    }
}

void WBSDEcoWindow::on_Tedt_7_editingFinished()
{
    if(compareTm(ui->Pdt_7,ui->Tedt_7))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_7->setTime(ui->Pdt_7->time());
    }else
    {
    SetECODPVal(56,ui->Tedt_7);
    }
}

void WBSDEcoWindow::on_Pdt_1_editingFinished()
{    

    if(compareTm(ui->Pdt_1,ui->Tedt_1))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_1->setTime(ui->Pdt_1->time());
    }
    else
    {
        SetECODPVal(45,ui->Pdt_1);
    }
}

void WBSDEcoWindow::on_Pdt_2_editingFinished()
{

    if(compareTm(ui->Pdt_2,ui->Tedt_2))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_2->setTime(ui->Pdt_2->time());
    }
    else
    {
        SetECODPVal(47,ui->Pdt_2);
    }
}

void WBSDEcoWindow::on_Pdt_3_editingFinished()
{

    if(compareTm(ui->Pdt_3,ui->Tedt_3))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_3->setTime(ui->Pdt_3->time());
    }
    else
    {
        SetECODPVal(49,ui->Pdt_3);
    }
}

void WBSDEcoWindow::on_Pdt_4_editingFinished()
{

    if(compareTm(ui->Pdt_4,ui->Tedt_4))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_4->setTime(ui->Pdt_4->time());
    }
    else
    {
        SetECODPVal(51,ui->Pdt_4);
    }
}

void WBSDEcoWindow::on_Pdt_5_editingFinished()
{

    if(compareTm(ui->Pdt_5,ui->Tedt_5))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_5->setTime(ui->Pdt_5->time());
    }
    else
    {
        SetECODPVal(53,ui->Pdt_5);
    }
}

void WBSDEcoWindow::on_Pdt_6_editingFinished()
{

    if(compareTm(ui->Pdt_6,ui->Tedt_6))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_6->setTime(ui->Pdt_6->time());
    }
    else
    {
        SetECODPVal(55,ui->Pdt_6);
    }
}

void WBSDEcoWindow::on_Pdt_7_editingFinished()
{

    if(compareTm(ui->Pdt_7,ui->Tedt_7))
    {
        QMessageBox::question(this, QObject::tr("Seting Error"), QObject::tr("Active End must be earlyer than Active start!!!"),QMessageBox::Ok);
        ui->Tedt_7->setTime(ui->Pdt_7->time());
    }
    else
    {
        SetECODPVal(57,ui->Pdt_7);
    }
}



void WBSDEcoWindow::SetECODPVal(int block, QTimeEdit *a)
{

    int hour = a->time().hour();
    int minute = a->time().minute();
    int value = ((0xFF & hour) << 8) | (0xFF & minute);
    GetAllEcoData();
    ParameterMsg message(Message::MCB,Message::DP, block, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDEcoWindow::updateEcoSetting(int value, QTimeEdit *a)
{
    int hour, minute;
    hour = (0xFF00 & value) >> 8;
    minute = 0xFF & value;
    a->setTime(QTime(hour,minute));
}

bool WBSDEcoWindow::compareTm(QTimeEdit *a, QTimeEdit *b)
{
    int hour = a->time().hour();
    int minute = a->time().minute();
    int value = ((0xFF & hour) << 8) | (0xFF & minute);

    int hour1 = b->time().hour();
    int minute1 = b->time().minute();
    int value1 = ((0xFF & hour1) << 8) | (0xFF & minute1);
    if(value>value1)
        return true;
    return false;

}

void WBSDEcoWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDEcoWindow::updateLabels()
{
    static const char* ecoTxt[] = {
        QT_TRANSLATE_NOOP("eco_txt", "Disable"),
        QT_TRANSLATE_NOOP("eco_txt", "Enable")
    };
    ui->ecoMode->addItem(Application::translate("eco_txt",ecoTxt[0]),0x0);
    ui->ecoMode->addItem(Application::translate("eco_txt",ecoTxt[1]),0x1);

    ui->holidayMode->addItem(Application::translate("eco_txt",ecoTxt[0]),0x0);
    ui->holidayMode->addItem(Application::translate("eco_txt",ecoTxt[1]),0x1);
    ui->ecoWakeup->addItem(Application::translate("eco_txt",ecoTxt[0]),0x0);
    ui->ecoWakeup->addItem(Application::translate("eco_txt",ecoTxt[1]),0x1);

}



void WBSDEcoWindow::updateHolidayMode(unsigned int conf)
{
    int noItems = ui->holidayMode->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->holidayMode->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->holidayMode->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDEcoWindow::updateHolidayMode index %1").arg(index);
    qDebug () << qss;
}

void WBSDEcoWindow::on_ecoMode_activated(int index)
{
    qDebug () << "RJDEBUG on_ecoMode_activated";
    int value = ui->ecoMode->itemData(index).toInt();

    setBoardDP0Parameter(value, 12);

}

void WBSDEcoWindow::updateEcoWakeup(unsigned int conf)
{
    int noItems = ui->ecoWakeup->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->ecoWakeup->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->ecoWakeup->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDEcoWindow::updateEcoWakeup index %1").arg(index);
    qDebug () << qss;
}



void WBSDEcoWindow::updateEcoSetTemp(double temp)
{
    qDebug () << "on_ecoSetTemp_editingFinished == updateEcoSetTemp " << temp;
    ui->ecoSetTemp->setValue(temp);
}

void WBSDEcoWindow::updateData()
{
    qDebug() << "WBSDEcoWindow::updateData";
    ParameterMsg msg1(Message::MCB,Message::DP,0);
    ParameterMsg msg2(Message::MCB,Message::DP,22);
    ParameterMsg msg3(Message::MCB,Message::DP,23);
    ParameterMsg msg4(Message::MCB,Message::AP,22);
    msg4.getWord();
    msg1.getWord();
    msg2.getWord();
    msg3.getWord();  
    itsBaseWindow->addMessageToQue(msg4);
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg3);



    for(int i=44;i<=64;i++)
    {
        ParameterMsg message(Message::MCB,Message::DP,i);
        message.getWord();
        itsBaseWindow->addMessageToQue(message);
    }



}

void WBSDEcoWindow::closeEvent(QCloseEvent *)
{
    emit iclose();
}



void WBSDEcoWindow::on_holidayMode_activated(int index)
{
    qDebug () << "RJDEBUG on_holidayMode_activated";
    int value = ui->holidayMode->itemData(index).toInt();

    int ecoIndex = ui->ecoWakeup->currentIndex();
    int valEco = ui->ecoWakeup->itemData(ecoIndex).toInt();

    if(!valEco && index == 1) //Must have Eco Wakeup if enabling Holiday Mode
    {
        setBoardDP0Parameters(1, 10, value, 11);
    }
    else
    {
        setBoardDP0Parameter(value, 11);
    }
}

void WBSDEcoWindow::on_ecoWakeup_activated(int index)
{
    qDebug () << "RJDEBUG on_ecoWakeup_activated";
    int value = ui->ecoWakeup->itemData(index).toInt();
    setBoardDP0Parameter(value, 10);

    int holidayIndex = ui->holidayMode->currentIndex();
    int valHoliday = ui->holidayMode->itemData(holidayIndex).toInt();

    if(valHoliday && index == 0) //Disabling Eco Wakeup must disable Holiday Mode
    {
        setBoardDP0Parameters(value, 10, 0, 11);
    }
    else
    {
        setBoardDP0Parameter(value, 10);
    }
}



void WBSDEcoWindow::on_ecoSetTemp_editingFinished() {
    qDebug () << "on_ecoSetTemp_editingFinished == " << ui->ecoSetTemp->value();
    ParameterMsg message(Message::MCB,Message::AP,22, Message::SET_PARAMETER);
    message.setFloat(ui->ecoSetTemp->value());
    itsBaseWindow->addMessageToQue(message);
}

// Send Board DP block 0 message. Need to add all bit data in block 0.
void WBSDEcoWindow::setBoardDP0Parameter(unsigned int value, int bitPos)
{
    ParameterMsg message(Message::MCB,Message::DP, 0, Message::SET_PARAMETER);
    message.setBit(bitPos,value);
    QString qs=QString("RJDEBUG WBSDEcoWindow::setBoardDP0Parameter, boardDp0BitField = %1").arg(boardDp0BitField);
    qDebug () << qs;
    itsBaseWindow->addMessageToQue(message);
}

// Send Board DP block 0 message. Need to add all bit data in block 0.
void WBSDEcoWindow::setBoardDP0Parameters(unsigned int value1, unsigned int bitPos1, unsigned int value2, unsigned int bitPos2)
{
setBoardDP0Parameter(value1,bitPos1);
setBoardDP0Parameter(value2,bitPos2);

}

void WBSDEcoWindow::GetAllEcoData()
{
    //ui->Tedt_7->dis
    _lstEco.clear();
    EcoInfo_T mytmp;
    mytmp.index =0;
    mytmp.stop = ui->Tedt_7->time().hour()*60+ui->Tedt_7->time().minute();
    mytmp.start  = ui->Pdt_7->time().hour()*60+ui->Pdt_7->time().minute();
    _lstEco.append(mytmp);
    mytmp.index =1;
    mytmp.stop = ui->Tedt_1->time().hour()*60+ui->Tedt_1->time().minute();
    mytmp.start  = ui->Pdt_1->time().hour()*60+ui->Pdt_1->time().minute();
    _lstEco.append(mytmp);
    mytmp.index =2;
    mytmp.stop = ui->Tedt_2->time().hour()*60+ui->Tedt_2->time().minute();
    mytmp.start  = ui->Pdt_2->time().hour()*60+ui->Pdt_2->time().minute();
    _lstEco.append(mytmp);
    mytmp.index =3;
    mytmp.stop = ui->Tedt_3->time().hour()*60+ui->Tedt_3->time().minute();
    mytmp.start  = ui->Pdt_3->time().hour()*60+ui->Pdt_3->time().minute();
    _lstEco.append(mytmp);
    mytmp.index =4;
    mytmp.stop = ui->Tedt_4->time().hour()*60+ui->Tedt_4->time().minute();
    mytmp.start  = ui->Pdt_4->time().hour()*60+ui->Pdt_4->time().minute();
    _lstEco.append(mytmp);
    mytmp.index =5;
    mytmp.stop = ui->Tedt_5->time().hour()*60+ui->Tedt_5->time().minute();
    mytmp.start  = ui->Pdt_5->time().hour()*60+ui->Pdt_5->time().minute();
    _lstEco.append(mytmp);
    mytmp.index =6;
    mytmp.stop = ui->Tedt_6->time().hour()*60+ui->Tedt_6->time().minute();
    mytmp.start  = ui->Pdt_6->time().hour()*60+ui->Pdt_6->time().minute();
    _lstEco.append(mytmp);
    ui->widget->setPaintlist(_lstEco);
}
void WBSDEcoWindow::updateEcoMode(unsigned int conf)
{
    int noItems = ui->ecoMode->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->ecoMode->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->ecoMode->setCurrentIndex(index);
            break;
        }
    }
    if(conf == 0)
    {

        if(ui->ecoWakeup->itemData(ui->ecoWakeup->currentIndex())!=0)
        on_ecoWakeup_activated(0);
        ui->ecoWakeup->setEnabled(false);
        ui->holidayMode->setEnabled(false);
        ui->ecoSetTemp->setEnabled(false);
        ui->Pdt_1->setEnabled(false);
        ui->Pdt_2->setEnabled(false);
        ui->Pdt_3->setEnabled(false);
        ui->Pdt_4->setEnabled(false);
        ui->Pdt_5->setEnabled(false);
        ui->Pdt_6->setEnabled(false);
        ui->Pdt_7->setEnabled(false);

        ui->Tedt_1->setEnabled(false);
        ui->Tedt_2->setEnabled(false);
        ui->Tedt_3->setEnabled(false);
        ui->Tedt_4->setEnabled(false);
        ui->Tedt_5->setEnabled(false);
        ui->Tedt_6->setEnabled(false);
        ui->Tedt_7->setEnabled(false);
    }
    else
    {
        ui->ecoWakeup->setEnabled(true);
        ui->holidayMode->setEnabled(true);
        ui->ecoSetTemp->setEnabled(true);
        ui->Pdt_1->setEnabled(true);
        ui->Pdt_2->setEnabled(true);
        ui->Pdt_3->setEnabled(true);
        ui->Pdt_4->setEnabled(true);
        ui->Pdt_5->setEnabled(true);
        ui->Pdt_6->setEnabled(true);
        ui->Pdt_7->setEnabled(true);

        ui->Tedt_1->setEnabled(true);
        ui->Tedt_2->setEnabled(true);
        ui->Tedt_3->setEnabled(true);
        ui->Tedt_4->setEnabled(true);
        ui->Tedt_5->setEnabled(true);
        ui->Tedt_6->setEnabled(true);
        ui->Tedt_7->setEnabled(true);
    }
    QString qss=QString("RJDEBUG WBSDEcoWindow::updateEcoMode index %1").arg(index);
    qDebug () << qss;
}
void WBSDEcoWindow::gotMessage(Message aMsg)
{

    unsigned int aVal;
    char aLevelState;
    char aRfgState;
    QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
    qDebug() << aMsg.getBoard() <<"||"<<aMsg.getParameters().at(3);
    Message::qtype atype=aMsg.getType();
    switch (atype)
    {
    case Message::SET_PARAMETER:
        //qDebug() << aMsg.getBoard() <<"||"<<aMsg.getParameters().at(3);
        break;
    case (Message::REPLY_DB):
        switch ((unsigned char)aMsg.getBoard())
        {

        case Message::MCB:
            switch ((unsigned char)aMsg.getDataBaseType())
            {
             case Message::DP:
                switch(aMsg.getParameters().at(3))
                {
                /*
                 * modify by lee
                 * Boiler temp in US mode. When in Fahrenheit, also remove (˚C). Now it says 145.4 ˚C and this is not correct.
                 */
                    case 0:
                        aVal= aMsg.getDataUInt();
                        boardDp0BitField = aVal;
                        itsBaseWindow->setUnitTmp((0x8000 & aVal) >> 15);
                        if(itsBaseWindow->getUnitTmp() == 0)
                        {

                            ui->label_4->setText(QObject::tr("Boiler temperature in ECO mode (°C)"));
                            ui->ecoSetTemp->setMinimum(1);
                            ui->ecoSetTemp->setMaximum(96);

                        }
                        else
                        {
                             ui->label_4->setText(QObject::tr("Boiler temperature in ECO mode (°F)"));
                             ui->ecoSetTemp->setMinimum(33.8);
                             ui->ecoSetTemp->setMaximum(204.8);
                        }

                        updateEcoMode((int)((boardDp0BitField & 0x1000) >> 12));
                        updateHolidayMode((int)((boardDp0BitField & 0x800) >> 11 ));
                        updateEcoWakeup((int)((boardDp0BitField & 0x400) >> 10 ));
                        break;

                case 44:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Tedt_1);
                    break;
                case 46:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Tedt_2);
                    break;
                case 48:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Tedt_3);
                    break;
                case 50:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Tedt_4);
                    break;
                case 52:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Tedt_5);
                    break;
                case 54:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Tedt_6);
                    break;
                case 56:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Tedt_7);
                    break;
                case 45:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Pdt_1);
                    break;
                case 47:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Pdt_2);
                    break;
                case 49:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Pdt_3);
                    break;
                case 51:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Pdt_4);
                    break;
                case 53:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Pdt_5);
                    break;
                case 55:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Pdt_6);
                    break;
                case 57:
                    aVal=aMsg.getDataUInt();
                    updateEcoSetting(aVal,ui->Pdt_7);
                    GetAllEcoData();
                    break;
                }
                break;
            case Message::AP:
                switch(aMsg.getParameters().at(3))
                {
                    case 22:
                        updateEcoSetTemp(aMsg.getDataFloat());
                        break;
                    default:
                        break;
                }
                break;
            }
        }
    }
}

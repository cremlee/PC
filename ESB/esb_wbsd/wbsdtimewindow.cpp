#include "wbsdtimewindow.h"
#include "ui_wbsdtimewindow.h"
#include "wbsdcleaningwindow.h"
#include "wbsdecowindow.h"
#include "qdebug.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "application.h"

WBSDTimeWindow::WBSDTimeWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDTimeWindow)
{
    static const char* timeEventTxt[] = {
        QT_TRANSLATE_NOOP("time_event_txt", "24 hours/day"),
        QT_TRANSLATE_NOOP("time_event_txt", "AM/PM hour format"),
        QT_TRANSLATE_NOOP("time_event_txt", "Disable"),
        QT_TRANSLATE_NOOP("time_event_txt", "Enable")
    };
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_time", "Back")
    };
    cleaningWindow=0;
    ui->setupUi(this);
    ui->pbtn_skipclean->hide();
    menuBack = new QAction(Application::translate("back_time",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));

    myTimer = new QTimer(this);
    myTimer->setSingleShot(true);
    cleaningWindow = 0; //new WBSDCleaningWindow();
    ecoWindow = 0; //new WBSDEcoWindow();
    WbsdHappyHour =0;
    ui->timeFormat->addItem(Application::translate("time_event_txt",timeEventTxt[0]),0x0);
    ui->timeFormat->addItem(Application::translate("time_event_txt",timeEventTxt[1]),0x1);
    ui->dtsEnable->addItem(Application::translate("time_event_txt",timeEventTxt[2]),0x0);
    ui->dtsEnable->addItem(Application::translate("time_event_txt",timeEventTxt[3]),0x1);
    //ui->currentDate->setText(QDate::currentDate().toString());
    //ui->currentTime->setText(QTime::currentTime().toString());
    boardDp0BitField = 0;
    doorDp0BitField = 0;
    updateDTSLabels();
    updateData();

    /*Lee.li Modify 2014-9-24
      fix the screen show
    */
    ui->centralwidget->setLayout(ui->verticalLayout_2);
}

WBSDTimeWindow::~WBSDTimeWindow()
{
    myTimer->stop();
    myTimer->deleteLater();
    myTimer=0;
    delete ui;
    this->deleteLater();
}

void WBSDTimeWindow::UpdataPaytest(bool flag)
{
    ui->pbtn_hpyhour->setEnabled(flag);
}

void WBSDTimeWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
}

void WBSDTimeWindow::on_cleaningWindow_destroyd()
{
    cleaningWindow =0;
}

void WBSDTimeWindow::updateTimeFormat(int conf)
{
    int noItems = ui->timeFormat->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->timeFormat->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->timeFormat->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateTimeFormat index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::updateDTSOption(int conf)
{
    qDebug () << "RJDEBUG WBSDTimeWindow::updateDTSOption invalue=" << conf;
    int noItems = ui->dtsEnable->count();
    qDebug () << "RJDEBUG WBSDTimeWindow::updateDTSOption noItems=" << noItems;
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsEnable->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsEnable->setCurrentIndex(index);
            break;
        }
    }
    qDebug() << "RJDEBUG WBSDTimeWindow::updateDTSOption index = conf =" << index << conf;
    updateDTSEnabled(conf);
}

void WBSDTimeWindow::updateDTSStartMonth(int conf)
{
    int noItems = ui->dtsStartMonth->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsStartMonth->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsStartMonth->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateDTSStartMonth index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::updateDTSStartWeek(int conf)
{
    int noItems = ui->dtsStartWeek->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsStartWeek->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsStartWeek->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateDTSStartWeek index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::updateDTSStartDay(int conf)
{
    int noItems = ui->dtsStartDay->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsStartDay->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsStartDay->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateDTSStartDay index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::updateDTSEndMonth(int conf)
{
    int noItems = ui->dtsEndMonth->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsEndMonth->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsEndMonth->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateDTSEndMonth index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::updateDTSEndWeek(int conf)
{
    int noItems = ui->dtsEndWeek->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsEndWeek->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsEndWeek->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateDTSEndWeek index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::updateDTSEndDay(int conf)
{
    int noItems = ui->dtsEndDay->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsEndDay->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsEndDay->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateDTSEndDay index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::updateDTSStartTime(int conf)
{
    int noItems = ui->dtsStartTime->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsStartTime->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsStartTime->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateDTSStartTime index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::updateDTSEndTime(int conf)
{
    int noItems = ui->dtsEndTime->count();
    int index;

    for (index=0; index<noItems; index++){
        int itemVal = ui->dtsEndTime->itemData(index).toInt();
        if ((conf)==itemVal) {
            ui->dtsEndTime->setCurrentIndex(index);
            break;
        }
    }
    QString qss=QString("RJDEBUG WBSDTimeWindow::updateDTSEndTime index %1").arg(index);
    qDebug () << qss;
}

void WBSDTimeWindow::on_cleaningButton_clicked()
{
    QString qs=QString("RJDEBUG Cleaning Button");
    qDebug () << qs;

    if (cleaningWindow==0)
        cleaningWindow=new WBSDCleaningWindow(itsBaseWindow);
    cleaningWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    connect(cleaningWindow,SIGNAL(iclose()),this,SLOT(show()));
    connect( cleaningWindow, SIGNAL(destroyed()), this, SLOT(on_cleaningWindow_destroyd()));
    cleaningWindow->show();
    this->hide();
}

void WBSDTimeWindow::on_ecoButton_clicked()
{
    QString qs=QString("RJDEBUG ECO Button");
    qDebug () << qs;

    if (ecoWindow==0)
        ecoWindow=new WBSDEcoWindow(itsBaseWindow);
    this->hide();
    connect(ecoWindow,SIGNAL(iclose()),this,SLOT(show()));
    ecoWindow->show();
}

void WBSDTimeWindow::on_setDate_clicked() {
    qDebug() << "WBSDTimeWindow::on_setDate_clicked";
    ui->currentDate->setText(QDate::currentDate().toString()); //Show date being sent
    QDate date = QDate::currentDate();
    ParameterMsg message1(Message::UIB,Message::DV,8);
    ParameterMsg message2(Message::UIB,Message::DV,9);
    message1.setWord(date.year());
    message2.setWord(date.month(),date.day());
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);

    myTimer->singleShot(500,this,SLOT(start_date_clock()));
}

void WBSDTimeWindow::on_setTime_clicked()
{
    QTime time = QTime::currentTime();
    ui->currentTime->setText(time.toString());
    ParameterMsg message1(Message::UIB,Message::DV,10);
    message1.setWord(time.hour(),time.minute());
    itsBaseWindow->addMessageToQue(message1);

    myTimer->singleShot(500,this,SLOT(start_date_clock()));
}

void WBSDTimeWindow::on_pbtn_hpyhour_clicked()
{
    //进入happyhour setting
    if(WbsdHappyHour ==0)
    {
        WbsdHappyHour =new wbsdHappyHour(itsBaseWindow);
    }
    this->hide();
    connect(WbsdHappyHour,SIGNAL(iclose()),this,SLOT(show()));
    WbsdHappyHour->show();
}

void WBSDTimeWindow::start_date_clock()
{
    ParameterMsg message1(Message::UIB,Message::DV,8);
    ParameterMsg message2(Message::UIB,Message::DV,9);
    ParameterMsg message3(Message::UIB,Message::DV,10);

    // Send 0xFF to start counting date/clock!
    message1.setWord(0xFFFF);
    message2.setWord(0xFF,0xFF);
    message3.setWord(0xFF,0xFF);
    itsBaseWindow->addMessageToQue(message1);
    itsBaseWindow->addMessageToQue(message2);
    itsBaseWindow->addMessageToQue(message3);
}

void WBSDTimeWindow::on_timeFormat_activated(int index)
{
    qDebug () << "RJDEBUG on_timeFormat_clicked value %1";
    int value = ui->timeFormat->itemData(index).toInt();
    setDoorDP0Parameter(value, 1, 12);
}

void WBSDTimeWindow::on_dtsEnable_activated(int index)
{
    int value = ui->dtsEnable->itemData(index).toInt();
    updateDTSEnabled(value);
    qDebug () << "RJDEBUG on_dtsEnable_clicked value=" << value;

    setBoardDP0Parameter(value, 13);
}

void WBSDTimeWindow::on_dtsStartMonth_activated(int index)
{
    int dtsStartMonth = ui->dtsStartMonth->itemData(index).toInt();
    int dtsStartDay = ui->dtsStartDay->itemData(ui->dtsStartDay->currentIndex()).toInt();
    int dtsStartWeek = ui->dtsStartWeek->itemData(ui->dtsStartWeek->currentIndex()).toInt();
    int value = (dtsStartMonth << 8) | (dtsStartDay << 4) | dtsStartWeek;


    QString qss=QString("RJDEBUG on_dtsStartMonth_activated dtsStartMonth = %1 ").arg(dtsStartMonth);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_dtsStartMonth_activated value bitfield %1 ").arg(value);
    qDebug () << qsss;

    ParameterMsg message(Message::MCB,Message::DP, 16, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDTimeWindow::on_dtsStartWeek_activated(int index)
{
    int dtsStartMonth = ui->dtsStartMonth->itemData(ui->dtsStartMonth->currentIndex()).toInt();
    int dtsStartDay = ui->dtsStartDay->itemData(ui->dtsStartDay->currentIndex()).toInt();
    int dtsStartWeek = ui->dtsStartWeek->itemData(index).toInt();
    int value = (dtsStartMonth << 8) | (dtsStartDay << 4) | dtsStartWeek;


    QString qss=QString("RJDEBUG on_dtsStartWeek_activated dtsStartWeek = %1 ").arg(dtsStartWeek);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_dtsStartWeek_activated value bitfield %1 ").arg(value);
    qDebug () << qsss;

    ParameterMsg message(Message::MCB,Message::DP, 16, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDTimeWindow::on_dtsStartDay_activated(int index)
{
    int dtsStartMonth = ui->dtsStartMonth->itemData(ui->dtsStartMonth->currentIndex()).toInt();
    int dtsStartDay = ui->dtsStartDay->itemData(index).toInt();
    int dtsStartWeek = ui->dtsStartWeek->itemData(ui->dtsStartWeek->currentIndex()).toInt();
    int value = (dtsStartMonth << 8) | (dtsStartDay << 4) | dtsStartWeek;


    QString qss=QString("RJDEBUG on_dtsStartDay_activated dtsStartDay = %1 ").arg(dtsStartWeek);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_dtsStartDay_activated value bitfield %1 ").arg(value);
    qDebug () << qsss;

    ParameterMsg message(Message::MCB,Message::DP, 16, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDTimeWindow::on_dtsEndMonth_activated(int index)
{
    int dtsEndMonth = ui->dtsEndMonth->itemData(index).toInt();
    int dtsEndDay = ui->dtsEndDay->itemData(ui->dtsEndDay->currentIndex()).toInt();
    int dtsEndWeek = ui->dtsEndWeek->itemData(ui->dtsEndWeek->currentIndex()).toInt();
    int value = (dtsEndMonth << 8) | (dtsEndDay << 4) | dtsEndWeek;


    QString qss=QString("RJDEBUG on_dtsEndMonth_activated dtsEndMonth = %1 ").arg(dtsEndMonth);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_dtsEndMonth_activated value bitfield %1 ").arg(value);
    qDebug () << qsss;

    ParameterMsg message(Message::MCB,Message::DP, 17, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDTimeWindow::on_dtsEndWeek_activated(int index)
{
    int dtsEndMonth = ui->dtsEndMonth->itemData(ui->dtsEndMonth->currentIndex()).toInt();
    int dtsEndDay = ui->dtsEndDay->itemData(ui->dtsEndDay->currentIndex()).toInt();
    int dtsEndWeek = ui->dtsEndWeek->itemData(index).toInt();
    int value = (dtsEndMonth << 8) | (dtsEndDay << 4) | dtsEndWeek;


    QString qss=QString("RJDEBUG on_dtsEndWeek_activated dtsEndWeek = %1 ").arg(dtsEndWeek);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_dtsEndWeek_activated value bitfield %1 ").arg(value);
    qDebug () << qsss;

    ParameterMsg message(Message::MCB,Message::DP, 17, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDTimeWindow::on_dtsEndDay_activated(int index)
{
    int dtsEndMonth = ui->dtsEndMonth->itemData(ui->dtsEndMonth->currentIndex()).toInt();
    int dtsEndDay = ui->dtsEndDay->itemData(index).toInt();
    int dtsEndWeek = ui->dtsEndWeek->itemData(ui->dtsEndWeek->currentIndex()).toInt();
    int value = (dtsEndMonth << 8) | (dtsEndDay << 4) | dtsEndWeek;


    QString qss=QString("RJDEBUG on_dtsEndDay_activated dtsEndDay = %1 ").arg(dtsEndWeek);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_dtsEndDay_activated value bitfield %1 ").arg(value);
    qDebug () << qsss;

    ParameterMsg message(Message::MCB,Message::DP, 17, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDTimeWindow::on_dtsStartTime_activated(int index)
{
    int dtsStartTime = ui->dtsStartTime->itemData(index).toInt();
    int dtsEndTime = ui->dtsEndTime->itemData(ui->dtsEndTime->currentIndex()).toInt();
    int value = (dtsStartTime << 8) | dtsEndTime;


    QString qss=QString("RJDEBUG on_dtsStartTime_activated dtsStartTime = %1 ").arg(dtsStartTime);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_dtsStartTime_activated value bitfield %1 ").arg(value);
    qDebug () << qsss;

    ParameterMsg message(Message::MCB,Message::DP, 18, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDTimeWindow::on_dtsEndTime_activated(int index)
{
    int dtsEndTime = ui->dtsEndTime->itemData(index).toInt();
    int dtsStartTime = ui->dtsStartTime->itemData(ui->dtsStartTime->currentIndex()).toInt();
    int value = (dtsStartTime << 8) | dtsEndTime;


    QString qss=QString("RJDEBUG on_dtsEndTime_activated dtsEndTime = %1 ").arg(dtsEndTime);
    qDebug () << qss;
    QString qsss=QString("RJDEBUG on_dtsEndTime_activated value bitfield %1 ").arg(value);
    qDebug () << qsss;

    ParameterMsg message(Message::MCB,Message::DP, 18, Message::SET_PARAMETER);
    message.setWord(value);
    itsBaseWindow->addMessageToQue(message);
}
/*
 *modify by lee
 *  新增按钮用于取消cleaningoverdue状态
 */
void WBSDTimeWindow::on_pbtn_skipclean_clicked()
{
    /*
     *
     * #define DB_WBSD_FLAG         &ui_dv[12],BIT0
     */
                    ParameterMsg counterResetMsg(Message::MCB,Message::DV,21);
                    counterResetMsg.setBit(11,1);
                    itsBaseWindow->addMessageToQue(counterResetMsg);

}

void WBSDTimeWindow::connectionStatusChanged(int aStatus,StringMessage aMSG){
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

// Send Door Unit DP block 0 message. Need to add all bit data in block 0.
void WBSDTimeWindow::setDoorDP0Parameter(int value, int bitLen, int offset)
{
    ParameterMsg query(Message::UIB,Message::DP, 0, Message::SET_PARAMETER);
	switch (bitLen){
	case 1:
		query.setBit(offset,value);
		break;
	case 4:
		query.setNibble(offset/4,value);
		break;
	case 8:
		query.setChar(offset/8,value);
		break;
	}
    itsBaseWindow->addMessageToQue(query);
}

// Send Board DP block 0 message. Need to add all bit data in block 0.
void WBSDTimeWindow::setBoardDP0Parameter(int value, int bitPos)
{
    ParameterMsg message(Message::MCB,Message::DP, 0, Message::SET_PARAMETER);
    message.setBit(bitPos,value);
    itsBaseWindow->addMessageToQue(message);
}

void WBSDTimeWindow::updateData()
{
    qDebug() << "WBSDTimeWindow::updateData";
    ParameterMsg msg1(Message::MCB,Message::DP,0);
    ParameterMsg msg2(Message::UIB,Message::DP,0);
    ParameterMsg msg3(Message::MCB,Message::DP,16);
    ParameterMsg msg4(Message::MCB,Message::DP,17);
    ParameterMsg msg5(Message::MCB,Message::DP,18);
    ParameterMsg msg6(Message::MCB,Message::DP,26);
    msg1.getWord();
    msg2.getWord();
    msg3.getWord();
    msg4.getWord();
    msg5.getWord();
    msg6.getWord();
    itsBaseWindow->addMessageToQue(msg1);
    itsBaseWindow->addMessageToQue(msg2);
    itsBaseWindow->addMessageToQue(msg3);
    itsBaseWindow->addMessageToQue(msg4);
    itsBaseWindow->addMessageToQue(msg5);
    itsBaseWindow->addMessageToQue(msg6);
}

void WBSDTimeWindow::gotMessage(Message aMsg)
{
    char dpval ;
    unsigned int aVal;
    QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
    aVal= 0xFFFF & aMsg.getDataUInt();
    Message::qtype atype=aMsg.getType();
    switch (atype){
        case (Message::REPLY_DB):
            switch ((unsigned char)aMsg.getBoard()){
                case (Message::MCB):
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DP:
                            switch(aMsg.getParameters().at(3)){
                                case (0):
                                    aVal= 0xFFFF & aMsg.getDataUInt();
                                     dpval = (aMsg.getDataInt() >> 8) & 0x00FF;
                                    if((dpval & 0x02) == 0x02)
                                    {
                                        UpdataPaytest(true);
                                    }else
                                    {
                                        UpdataPaytest(false);
                                    }
                                    boardDp0BitField = aVal;
                                    qDebug() << "WBSDTimeWindow::gotMessage MCB:DP:0. field=" << boardDp0BitField;
                                    updateDTSOption((0x2000 & aVal) >> 13);
                                    break;
                                case (16):
                                    aVal= 0xFFFF & aMsg.getDataUInt();
                                    updateDTSStartMonth((0xF00 & aVal) >> 8);
                                    updateDTSStartWeek(0xF & aVal);
                                    updateDTSStartDay((0xF0 & aVal) >> 4);
                                    break;
                                case (17):
                                    aVal= 0xFFFF & aMsg.getDataUInt();
                                    updateDTSEndMonth((0xF00 & aVal) >> 8);
                                    updateDTSEndWeek(0xF & aVal);
                                    updateDTSEndDay((0xF0 & aVal) >> 4);
                                    break;
                                case (18):
                                    aVal= 0xFFFF & aMsg.getDataUInt();
                                    updateDTSStartTime((0xFF00 & aVal) >> 8);
                                    updateDTSEndTime(0xFF & aVal);
                                    break;
                                case (26):
                                    aVal=aMsg.getDataUInt();
                                    ui->pbtn_skipclean->setVisible(((aVal&0x40)>>6)==1?false:true);
                                break;
                                default:
                                    break;
                            }

                    }
                    break;
                case (Message::UIB):
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DP:
                            switch (aMsg.getParameters().at(3)){
                                case (0):
                                    aVal= 0xFFFF & aMsg.getDataUInt();
                                    doorDp0BitField = aVal;
                                    qDebug() << "WBSDTimeWindow::gotMessage UIB:DP:0. field=" << doorDp0BitField;
                                    updateTimeFormat((0x1000 & aVal) >> 12);
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

//Set text for Daylight labels
void WBSDTimeWindow::updateDTSLabels()
{
    QString time;

    static const char* month[] = {
        QT_TRANSLATE_NOOP("timeevent_month", "January"),
        QT_TRANSLATE_NOOP("timeevent_month", "February"),
        QT_TRANSLATE_NOOP("timeevent_month", "March"),
        QT_TRANSLATE_NOOP("timeevent_month", "April"),
        QT_TRANSLATE_NOOP("timeevent_month", "May"),
        QT_TRANSLATE_NOOP("timeevent_month", "June"),
        QT_TRANSLATE_NOOP("timeevent_month", "July"),
        QT_TRANSLATE_NOOP("timeevent_month", "August"),
        QT_TRANSLATE_NOOP("timeevent_month", "September"),
        QT_TRANSLATE_NOOP("timeevent_month", "October"),
        QT_TRANSLATE_NOOP("timeevent_month", "November"),
        QT_TRANSLATE_NOOP("timeevent_month", "December")
    };

    static const char* day[] = {
        QT_TRANSLATE_NOOP("timeevent_day", "Monday"),
        QT_TRANSLATE_NOOP("timeevent_day", "Tuesday"),
        QT_TRANSLATE_NOOP("timeevent_day", "Wednesday"),
        QT_TRANSLATE_NOOP("timeevent_day", "Thursday"),
        QT_TRANSLATE_NOOP("timeevent_day", "Friday"),
        QT_TRANSLATE_NOOP("timeevent_day", "Saturday"),
        QT_TRANSLATE_NOOP("timeevent_day", "Sunday")
    };

    for(int i=0;i<12;i++ ) {
        ui->dtsStartMonth->addItem(Application::translate("timeevent_month",month[i]),i+1);
        ui->dtsEndMonth->addItem(Application::translate("timeevent_month",month[i]),i+1);
    }

    for(int i=0;i<7;i++ ) {
        ui->dtsStartDay->addItem(Application::translate("timeevent_day",day[i]),i+1);
        ui->dtsEndDay->addItem(Application::translate("timeevent_day",day[i]),i+1);
    }

    for(int i=0;i<4;i++ ) {
        ui->dtsStartWeek->addItem(QString::number(i+1),i+1);
        ui->dtsEndWeek->addItem(QString::number(i+1),i+1);
    }

    for(int i=0;i<24;i++ ) {
        time = QString::number(i);
        time.append(":00");
        ui->dtsStartTime->addItem(time,i);
        ui->dtsEndTime->addItem(time,i);
    }
}

// For toggling betseen enabled/disabled for Daylight options
void WBSDTimeWindow::updateDTSEnabled(int conf)
{
    if (conf == 0) { //DTS disabled
        ui->dtsStartMonth->setDisabled(1);
        ui->dtsStartMonthLbl->setDisabled(1);
        ui->dtsStartWeek->setDisabled(1);
        ui->dtsStartWeekLbl->setDisabled(1);
        ui->dtsStartDay->setDisabled(1);
        ui->dtsStartDayLbl->setDisabled(1);
        ui->dtsStartTime->setDisabled(1);
        ui->dtsStartTimeLbl->setDisabled(1);
        ui->dtsEndMonth->setDisabled(1);
        ui->dtsEndMonthLbl->setDisabled(1);
        ui->dtsEndWeek->setDisabled(1);
        ui->dtsEndWeekLbl->setDisabled(1);
        ui->dtsEndDay->setDisabled(1);
        ui->dtsEndDayLbl->setDisabled(1);
        ui->dtsEndTime->setDisabled(1);
        ui->dtsEndTimeLbl->setDisabled(1);

    }
    else {
        ui->dtsStartMonth->setDisabled(0);
        ui->dtsStartMonthLbl->setDisabled(0);
        ui->dtsStartWeek->setDisabled(0);
        ui->dtsStartWeekLbl->setDisabled(0);
        ui->dtsStartDay->setDisabled(0);
        ui->dtsStartDayLbl->setDisabled(0);
        ui->dtsStartTime->setDisabled(0);
        ui->dtsStartTimeLbl->setDisabled(0);
        ui->dtsEndMonth->setDisabled(0);
        ui->dtsEndMonthLbl->setDisabled(0);
        ui->dtsEndWeek->setDisabled(0);
        ui->dtsEndWeekLbl->setDisabled(0);
        ui->dtsEndDay->setDisabled(0);
        ui->dtsEndDayLbl->setDisabled(0);
        ui->dtsEndTime->setDisabled(0);
        ui->dtsEndTimeLbl->setDisabled(0);
    }
}

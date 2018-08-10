#include "wbsdmainwindow.h"
#include "ui_wbsdmainwindow.h"
#include "parametermsg.h"
#include "wbsdstartpage.h"
#include "qdebug.h"
//#include <QStackedWidget>
#include "wbsd_serial_port.h"
#include "qextserialenumerator.h"
//#include "wbsdwaterwindow.h"
#include "WBSDButtoncounters.h"
#include "wbsdgeneralwindow.h"
#include "wbsdbasewindow.h"
#include <QActionGroup>
#include <QLocale>
#include "application.h"
#include "databasehelper.h"

//version 0.94 modify the clone & upload config and recipe data via WBSD; 2014-10-17
/*modify by lee
 *modify 2015-03-19 version 1.13 by lee
first check the MCB Ver if it is below 0.86 ,then give warning and close it.
*/
/* version1.14
 * fix clone bug
 * modify top tmp set water tank no change other top-93.8 mid-915
 *
 * modify by lee
 * version v1.35
 * fix the cash warning value && cash full value
 * fix the skip clean overdue bug
 * improve the process of eco
 * #############version 1.36##########################
 * add default cup size select
 *  modify by lee v1.37
 *  change the text hight for happy hour setting
 *  hide the backup & restore
 *
 *
 * version 1.56 fix led selection bug by lee 20160418
 *
 *
 * version3.29 payment price setting show price bug for jpy
 */
static const char* mainMenus[] = {
    QT_TRANSLATE_NOOP("mainwindow_menus", "Quit"),
    QT_TRANSLATE_NOOP("mainwindow_menus", "Language"),
    QT_TRANSLATE_NOOP("mainwindow_menus", "Services"),
    QT_TRANSLATE_NOOP("mainwindow_menus", "Country")
};

static const char* mainServices[] = {
    QT_TRANSLATE_NOOP("mainwindow_services", "Normal"),
    QT_TRANSLATE_NOOP("mainwindow_services", "Nurse"),
    QT_TRANSLATE_NOOP("mainwindow_services", "Cleaning"),
    QT_TRANSLATE_NOOP("mainwindow_services", "Operator"),
    QT_TRANSLATE_NOOP("mainwindow_services", "Service"),
    QT_TRANSLATE_NOOP("mainwindow_services", "Manufacturer"),
    QT_TRANSLATE_NOOP("mainwindow_services", "WBSD")
};

static const char* connecting[] = {
    QT_TRANSLATE_NOOP("conn_status", "Disconnected"),
    QT_TRANSLATE_NOOP("conn_status", "Connecting..."),
    QT_TRANSLATE_NOOP("conn_status", "Connected")
};

static const char* machine_state[] = {
    QT_TRANSLATE_NOOP("machine_state", "USA"),
    QT_TRANSLATE_NOOP("machine_state", "Other"),
    QT_TRANSLATE_NOOP("machine_state", "Select country next time")

};

WBSDMainWindow::WBSDMainWindow(QWidget *parent) :
    WBSDBaseWindow(parent),
    ui(new Ui::WBSDMainWindow)
{
	init=true;
    //timerTemp=new QTimer(this);
    ui->setupUi(this);
    startPage = new WBSDStartPage(this);
    //wbsdrun = new wbsd_run(this);
    qe=new QextSerialEnumerator(this);
    qe->setUpNotifications();

    connect (qe,SIGNAL(deviceDiscovered(const QextPortInfo)),this,SLOT(deviceDiscovered(const QextPortInfo)));
    connect (qe,SIGNAL(deviceRemoved(const QextPortInfo)),this,SLOT(deviceRemoved(const QextPortInfo)));

    QList<QextPortInfo> portList=qe->getPorts();

    connect(this,SIGNAL(newConnectionStatus(int,StringMessage)),this,SLOT(updateConnectionStatus(int,StringMessage)));
    connect(wbsd_SERIAL_PORT::itsInstance,SIGNAL(log(QString)),this,SLOT(log(QString)));

    int sel=0;
    for (int i=0;i<portList.count();i++){
        if ((portList.at(i).vendorID==1003)  && (portList.at(i).productID==8216)){
            wbsd_SERIAL_PORT::instance()->reconnect(portList.at(i).portName);
            sel=i;
        }
    }
    setMenus();
    // Languages
    QString lang = DataBaseHelper::getInstance()->getSetting("lang","31");

    int state = DataBaseHelper::getInstance()->getMachineState();
    setMachineUnit( (MachineUnit)state);
    qDebug() << "lang =" << lang;
    lastUsedLanguage = lang.toInt();
    qDebug() << "lastUsedLanguage =" << lastUsedLanguage;
    fillLanguages();
    retranslate();
    // Init connection status indication
    ui->connStatusInd->setStyleSheet("background-image: url(:mainpics/5.png);");
    ui->connStatus->setStyleSheet("background:rgb(200,0,0)");
    menuService_level->setEnabled(false);
    /* Modify by Lee.li
     * Version Show on Title*/    
    Ver_Major = 3;
    Ver_Min   = 32;
    actionStateUsa->setChecked(false);
    actionStateOther->setChecked(false);
}

WBSDMainWindow::~WBSDMainWindow()
{
    delete ui;
    qApp->quit();
}

void WBSDMainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void WBSDMainWindow::on_menuQuit_triggered()
{
    QApplication::quit();
}

void WBSDMainWindow::on_actionStateUsa_triggered()
{
    /*modify by lee
      change to US mode
      change the setting of BIB
    */
}

void WBSDMainWindow::on_actionStatechange_triggered()
{
    if(actionStatechange->isChecked())
    {
        DataBaseHelper::getInstance()->setswitch(1);
        actionStatechange->setChecked(true);
    }else
    {
        DataBaseHelper::getInstance()->setswitch(0);
        actionStatechange->setChecked(false);
    }
}

//Show startpage and hide welcome picture
static int started = 0;
void WBSDMainWindow::showConnectionStatus(int connStatus)
{    
     //0: Start page not shown. 1: Start page shown
    if(started == 0)
    {
        if (connStatus == WBSDStartPage::CON_SHOW_OVERVIEW)
        {
            ui->connStatusInd->setStyleSheet("background-image: url(:mainpics/5.png);");
            ui->connStatus->setStyleSheet("background:rgb(200,0,0)");
            ui->connStatusInfo->setText(Application::translate("conn_status",connecting[0]));
        }
        else if (connStatus == WBSDStartPage::CON_SHOW_CONNECT)
        {
            ui->connStatusInd->setStyleSheet("background-image: url(:mainpics/5.png);");
            ui->connStatus->setStyleSheet("background:rgb(200,100,0)");
            ui->connStatusInfo->setText(Application::translate("conn_status",connecting[1]));
        }
        else if (connStatus == WBSDStartPage::CON_SHOW_NONE)
        {
            //menuLanguages->setEnabled(false);
            ui->centralwidget->deleteLater();
            this->setCentralWidget(startPage); //Show start window
            started = 1;
            ui->connStatus->setStyleSheet("background:rgb(0,200,0)");
            ui->connStatusInfo->setText(Application::translate("conn_status",connecting[2]));
            menuLanguages->setEnabled(false); //disable language change
            menuService_level->setEnabled(true);  //Enable service
        }
    }
    else if(started == 1)
    {
            if (connStatus == WBSDStartPage::CON_SHOW_OVERVIEW)
            {
                menuService_level->setEnabled(false);  //Disable service

            }
            else if (connStatus == WBSDStartPage::CON_SHOW_CONNECT)
            {
                menuService_level->setEnabled(false);  //Disable service

            }
            else if (connStatus == WBSDStartPage::CON_SHOW_NONE)
            {
                menuService_level->setEnabled(true);  //Enable service

            }
    }
}

void WBSDMainWindow::updateConnectionStatus(int aLevel,StringMessage aMsg){
   if (aLevel>=20){
        setServiceLevel(5);
	} else if (aLevel==10) {
	} else if (aLevel<10){
	}
}

void WBSDMainWindow::on_actionServiceNormal_triggered(){
    setServiceLevel(1);
}


void WBSDMainWindow::on_actionServiceNurse_triggered(){
	setServiceLevel(2);
}

void WBSDMainWindow::on_actionServiceClean_triggered(){
    setServiceLevel(3);
}

void WBSDMainWindow::on_actionServiceOperator_triggered(){
    setServiceLevel(4);
}
void WBSDMainWindow::on_actionServiceService_triggered(){
    setServiceLevel(5);
}
void WBSDMainWindow::on_actionServiceManufacturer_triggered(){
    setServiceLevel(6);
}
void WBSDMainWindow::on_actionServiceWBSD_triggered(){
    setServiceLevel(7);
}
void WBSDMainWindow::setServiceLevel(int aLevel){

	ParameterMsg query1(Message::UIB,Message::DV,2);
	query1.setNibble(0,aLevel);
	addMessageToQue(query1);
    actionServiceNormal->setChecked(aLevel==1);
    actionServiceNurse->setChecked(aLevel==2);
    actionServiceCleaning->setChecked(aLevel==3);
    actionServiceOperator->setChecked(aLevel==4);
    actionServiceService->setChecked(aLevel==5);
    actionServiceManufacturer->setChecked(aLevel==6);
    actionServiceWBSD->setChecked(aLevel==7);
}

void WBSDMainWindow::deviceDiscovered(const QextPortInfo &info){
    int i=0;
    QString newDeviceName = QString("%2:\t %1 [%3:%4]").arg(info.friendName).arg(info.portName).arg(info.vendorID).arg(info.productID);
    qDebug () << newDeviceName;
    QString qs=QString("%2:\t %1 [%3:%4]").arg(info.friendName).arg(info.portName).arg(info.vendorID).arg(info.productID);
    qDebug () << qs;

    if ((info.vendorID==1003)  && (info.productID==8216)){
        wbsd_SERIAL_PORT::instance()->reconnect(info.portName);
    }

}

void WBSDMainWindow::deviceRemoved(const QextPortInfo &info){
    if ((info.vendorID==1003)  && (info.productID==8216)){
        wbsd_SERIAL_PORT::instance()->disconnect();
    }
}


void WBSDMainWindow::log(QString aString){

    //RJ debug var ska loggen hamna??!!!
    //ui->lstLog->addItem(aString);
    //startPage->errorWindow->listErrors->addItem(aString);
}

void WBSDMainWindow::setLanguage(QAction* action)
{
    Application::setLanguage(action->data().toString());
    QLocale locale(action->data().toString());
    int currLang = locale.language(); //Check enum Language for coding
    qDebug() << "currLang" << currLang;
    bool retlang = DataBaseHelper::getInstance()->setSetting("lang",QString::number(currLang)); //Save current language in db
    DataBaseHelper::getInstance()->setSetting("langStr",action->data().toString());

    qDebug() << "retlang =" << retlang;
    if(started ==1)
    {
        startPage->updateinfo(0);
    }
}

void WBSDMainWindow::fillLanguages()
{
    qDebug() << "WBSDMainWindow::fillLanguages";
    // make a group of language actions
    QActionGroup* actions = new QActionGroup(this);
    connect(actions, SIGNAL(triggered(QAction*)), this, SLOT(setLanguage(QAction*)));

    foreach (QString avail, Application::availableLanguages())
    {
        // figure out nice names for locales
        QLocale locale(avail);
        QString language = QLocale::languageToString(locale.language());
        QString country = QLocale::countryToString(locale.country());

        QString name = language + " (" + country + ")";
        if(language=="Chinese")name="中文简体";
        // construct an action
        QAction* action = menuLanguages->addAction(name);
        action->setData(avail);
        action->setCheckable(true);
        actions->addAction(action);
    }
    //Set active language the language used from previous session (or default)
    int len = menuLanguages->actions().length();
    QLocale locale;
    for(int i = 0; i<len;i++)
    {
        locale = menuLanguages->actions().at(i)->data().toString();
        if (locale.language() == lastUsedLanguage)
        {
            menuLanguages->actions().at(i)->setChecked(true);
            menuLanguages->actions().at(i)->trigger();
        }
    }
}

void WBSDMainWindow::retranslate()
{
    QString verstr;
    if(getMachineUnit() == UNIT_USA)
    {
         verstr.sprintf("Compact_PC_Tool for USA Version:%d.%.2d",Ver_Major,Ver_Min);
        this->setWindowTitle(verstr);
        //actionStateUsa->setChecked(true);
    }
    else
    {
        //QString verstr;
        verstr.sprintf("Compact_PC_Tool Version:%d.%.2d",Ver_Major,Ver_Min);
        this->setWindowTitle(verstr);
        //actionStateOther->setChecked(true);
    }

    menuQuit->setText(Application::translate("mainwindow_menus",mainMenus[0]));
    menuLanguages->setTitle(Application::translate("mainwindow_menus",mainMenus[1]));
    menuService_level->setTitle(Application::translate("mainwindow_menus",mainMenus[2]));
    menuState->setTitle(Application::translate("mainwindow_menus",mainMenus[3]));
    actionServiceNormal->setText(Application::translate("mainwindow_services",mainServices[0]));
    actionServiceNurse->setText(Application::translate("mainwindow_services",mainServices[1]));
    actionServiceCleaning->setText(Application::translate("mainwindow_services",mainServices[2]));
    actionServiceOperator->setText(Application::translate("mainwindow_services",mainServices[3]));
    actionServiceService->setText(Application::translate("mainwindow_services",mainServices[4]));
    actionServiceManufacturer->setText(Application::translate("mainwindow_services",mainServices[5]));
    actionServiceWBSD->setText(Application::translate("mainwindow_services",mainServices[6]));

    actionStateOther->setText(Application::translate("machine_state",machine_state[1]));
    actionStateUsa->setText(Application::translate("machine_state",machine_state[0]));
    actionStatechange->setText(Application::translate("machine_state",machine_state[2]));
}

void WBSDMainWindow::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        qDebug() << "changeEvent::LanguageChange";
        // apply the new language
        // all designed forms have retranslateUi() method
        ui->retranslateUi(this);
        retranslate();		
        startPage->setLabelTexts();
    }
    QMainWindow::changeEvent(event);
}

void WBSDMainWindow::setMenus()
{
   menuQuit = new QAction(Application::translate("mainwindow_menus",mainMenus[0]), this);
    ui->menubar->addAction(menuQuit);
    connect( menuQuit, SIGNAL(triggered()), this, SLOT(on_menuQuit_triggered()));
    menuLanguages = new QMenu(Application::translate("mainwindow_menus",mainMenus[1]), this);
    ui->menubar->addMenu(menuLanguages);
    if(getMachineUnit() == UNIT_USA)
    {
        menuLanguages->setEnabled(false);
    }else
    {
        menuLanguages->setEnabled(true);
    }
    menuService_level = new QMenu(Application::translate("mainwindow_menus",mainMenus[2]), this);
    ui->menubar->addMenu(menuService_level);

    actionServiceNormal = new QAction(Application::translate("mainwindow_services",mainServices[0]), this);
    actionServiceNormal->setCheckable(true);
    menuService_level->addAction(actionServiceNormal);
    connect( actionServiceNormal, SIGNAL(triggered()), this, SLOT(on_actionServiceNormal_triggered()));

    actionServiceNurse = new QAction(Application::translate("mainwindow_services",mainServices[1]), this);
    actionServiceNurse->setCheckable(true);
    actionServiceNurse->setVisible(false);
    menuService_level->addAction(actionServiceNurse);
    connect( actionServiceNurse, SIGNAL(triggered()), this, SLOT(on_actionServiceNurse_triggered()));

    actionServiceCleaning = new QAction(Application::translate("mainwindow_services",mainServices[2]), this);
    actionServiceCleaning->setCheckable(true);
    actionServiceCleaning->setVisible(false);
    menuService_level->addAction(actionServiceCleaning);
    connect( actionServiceCleaning, SIGNAL(triggered()), this, SLOT(on_actionServiceClean_triggered()));

    actionServiceOperator = new QAction(Application::translate("mainwindow_services",mainServices[3]), this);
    actionServiceOperator->setCheckable(true);
    menuService_level->addAction(actionServiceOperator);
    connect( actionServiceOperator, SIGNAL(triggered()), this, SLOT(on_actionServiceOperator_triggered()));

    actionServiceService = new QAction(Application::translate("mainwindow_services",mainServices[4]), this);
    actionServiceService->setCheckable(true);
    menuService_level->addAction(actionServiceService);
    connect( actionServiceService, SIGNAL(triggered()), this, SLOT(on_actionServiceService_triggered()));

    actionServiceManufacturer = new QAction(Application::translate("mainwindow_services",mainServices[5]), this);
    actionServiceManufacturer->setCheckable(true);
    actionServiceManufacturer->setVisible(false);
    menuService_level->addAction(actionServiceManufacturer);
    connect( actionServiceManufacturer, SIGNAL(triggered()), this, SLOT(on_actionServiceManufacturer_triggered()));

    actionServiceWBSD = new QAction(Application::translate("mainwindow_services",mainServices[6]), this);
    actionServiceWBSD->setCheckable(true);
    actionServiceWBSD->setVisible(false);
    menuService_level->addAction(actionServiceWBSD);
    connect( actionServiceWBSD, SIGNAL(triggered()), this, SLOT(on_actionServiceWBSD_triggered()));

    //QMenu *menuState;
    //QAction *actionStateOther;
    //QAction *actionStateUsa;
    menuState = new QMenu(Application::translate("mainwindow_menus",mainMenus[3]), this);
    ui->menubar->addMenu(menuState);
    actionStateOther = new QAction(Application::translate("machine_state",machine_state[1]), this);
    actionStateUsa = new QAction(Application::translate("machine_state",machine_state[0]), this);
    actionStatechange = new QAction(Application::translate("machine_state",machine_state[2]), this);

    actionStateOther->setCheckable(true);
    actionStateUsa->setCheckable(true);
    actionStatechange->setCheckable(true);

    actionStateUsa->setEnabled(false);
    actionStateOther->setEnabled(false);

    menuState->addAction(actionStatechange);
    menuState->addAction(actionStateUsa);
    menuState->addAction(actionStateOther);

    connect(actionStatechange, SIGNAL(triggered()), this, SLOT(on_actionStatechange_triggered()));

}

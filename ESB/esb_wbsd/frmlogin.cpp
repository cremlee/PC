#include "frmlogin.h"
#include "ui_frmlogin.h"
#include "wbsdmainwindow.h"
#include "wbsd_serial_port.h"
frmLogin::frmLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmLogin)
{
    ui->setupUi(this);
    this->InitForm();
}

frmLogin::~frmLogin()
{
    qDebug()<<"longin ~~~~";
    delete ui;
}

void frmLogin::InitForm()
{

}

void frmLogin::on_btnLogin_clicked()
{
    DataBaseHelper::getInstance()->setlast(DataBaseHelper::getInstance()->getMachineState());
    if(ui->txtUserName->currentIndex()==0)
    {
        DataBaseHelper::getInstance()->setMachineState(0);
        DataBaseHelper::getInstance()->ChangeDbsName(true);
    }else
    {
        DataBaseHelper::getInstance()->setMachineState(1);
        DataBaseHelper::getInstance()->ChangeDbsName(false);
    }
    DataBaseHelper::getInstance()->setswitch(0);    
    WBSDMainWindow* mywin = new WBSDMainWindow() ;
    mywin->show();
    this->hide();

}

void frmLogin::on_btnClose_clicked()
{
    qApp->quit();
}



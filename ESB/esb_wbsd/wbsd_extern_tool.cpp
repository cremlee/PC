#include "wbsd_extern_tool.h"
#include "ui_wbsd_extern_tool.h"
#include<application.h>
static const char* back[] = {
        QT_TRANSLATE_NOOP("back_version", "Back")
    };
WBSD_EXTERN_TOOL::WBSD_EXTERN_TOOL(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSD_EXTERN_TOOL)
{
    ui->setupUi(this);
    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    fmutstwin=0;
    this->setWindowTitle(QObject::tr("External module testing"));
}

WBSD_EXTERN_TOOL::~WBSD_EXTERN_TOOL()
{
    delete ui;

}

void WBSD_EXTERN_TOOL::closeEvent(QCloseEvent *evt)
{
    emit iclose();
}

void WBSD_EXTERN_TOOL::gotMessage(Message aMsg)
{

}

void WBSD_EXTERN_TOOL::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSD_EXTERN_TOOL::on_btn_fmu_tst_clicked()
{
    if (fmutstwin==0)
        fmutstwin = new fmu_test(itsBaseWindow);
    fmutstwin->setAttribute(Qt::WA_DeleteOnClose,true);
    fmutstwin->show();
    this->hide();
    connect(fmutstwin,SIGNAL(iclose()),this,SLOT(show()));
    connect(fmutstwin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void WBSD_EXTERN_TOOL::destroywin()
{
    fmutstwin=0;
}

void WBSD_EXTERN_TOOL::on_menuBack_triggered()
{
    this->close();
}

#include "wbsdbtn78cnt.h"
#include "ui_wbsdbtn78cnt.h"
#include"parametermsg.h"
#include "application.h"
WBSDbtn78cnt::WBSDbtn78cnt(int button, WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDbtn78cnt)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_buttoncounter", "Back")
    };

    ui->setupUi(this);
    menuBack = new QAction(Application::translate("back_buttoncounter",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    updateData();
    this->setWindowTitle(QObject::tr("Button %1 Counters").arg(button));
    if(itsBaseWindow->getUnitTmp() == 0)
    {
        ui->lbl1->setText(QObject::tr("Litres"));
        ui->lbl2->setText(QObject::tr("Litres"));
    }else
    {
        ui->lbl1->setText(QObject::tr("Gallons"));
        ui->lbl2->setText(QObject::tr("Gallons"));
    }
    this->centralWidget()->setLayout(ui->verticalLayout);
    if(button ==7)
    {
        ui->label_37->hide();
        ui->label_38->hide();
        ui->label_40->hide();
        ui->label_41->hide();
        ui->label_42->hide();
        ui->line_3->hide();
        ui->line_4->hide();
        ui->lbls5->hide();
        ui->lbls6->hide();

    }else
    {
    ui->lbl1->hide();
    ui->lbl2->hide();
    ui->lbls1->hide();
    ui->lbls2->hide();
    ui->lbls3->hide();
    ui->lbls4->hide();
    ui->line->hide();
    ui->line_2->hide();
    ui->label_23->hide();
    ui->label_29->hide();
    ui->label_31->hide();
    ui->label_33->hide();
    ui->label_36->hide();
    ui->label_44->hide();
    ui->label_45->hide();
    }
}

WBSDbtn78cnt::~WBSDbtn78cnt()
{
    delete ui;
}

void WBSDbtn78cnt::updateData()
{
    for (int i=195;i<=200;i++){
        ParameterMsg msg(Message::MCB,Message::AP,i);
        msg.getFloat();
        itsBaseWindow->addMessageToQue(msg);
    }
}

void WBSDbtn78cnt::gotMessage(Message aMsg)
{
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::AP)){
        unsigned char index=aMsg.getParameters().at(3);
        switch (index) {
        case 195:
            ui->lbls1->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat()/1000:aMsg.getDataFloat()/128000)));
            break;
        case 196:
            ui->lbls2->setText(QString::number(aMsg.getDataFloat()));
            break;
        case 198:
            ui->lbls3->setText(QString::number(((itsBaseWindow->getUnitTmp() == 0)?aMsg.getDataFloat()/1000:aMsg.getDataFloat()/128000)));
            break;
        case 199:
            ui->lbls4->setText(QString::number(aMsg.getDataFloat()));
            break;
        case 197:
            ui->lbls5->setText(QString::number(aMsg.getDataFloat()));
            break;
        case 200:
            ui->lbls6->setText(QString::number(aMsg.getDataFloat()));
            break;
        default:
            break;
        }
    }
}

void WBSDbtn78cnt::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDbtn78cnt::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDbtn78cnt::on_menuBack_triggered()
{
    this->close();
}

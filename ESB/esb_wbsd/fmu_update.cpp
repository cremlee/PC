#include "fmu_update.h"
#include "ui_fmu_update.h"
#include<QFileDialog>
#include<qmessagebox.h>
#include "fmu_message.h"
#include"fmu_test.h"
#include"parametermsg.h"
#include<QDebug>
FMU_UPDATE::FMU_UPDATE(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::FMU_UPDATE)
{
    ui->setupUi(this);
    _UpdateMessage =new UpdateMessage;

    ParameterMsg msg(Message::UIB,Message::TV,0xA1);
    msg.getWord();
    itsBaseWindow->addMessageToQue(msg);

    ParameterMsg msg1(Message::UIB,Message::TV,0xA2);
    msg1.getWord();
    itsBaseWindow->addMessageToQue(msg1);
}

FMU_UPDATE::~FMU_UPDATE()
{
    delete ui;
    delete _UpdateMessage;
}

void FMU_UPDATE::closeEvent(QCloseEvent *evt)
{
    emit iclose();
}

void FMU_UPDATE::gotMessage(Message aMsg)
{
    QByteArray data=aMsg.getData();
    Message::qtype atype=aMsg.getType();
//    switch (atype){
//    case (Message::REPLY_DB):
//        switch ((unsigned char)aMsg.getBoard()){
//        case Message::UIB:
//            switch ((unsigned char)aMsg.getDataBaseType())
//            {
//                case Message::TV:
//                    switch(aMsg.getParameters().at(3)){
//                    case 0xA1:
//                        ui->lbl_ver_fmu->setText("V."+aMsg.getDataInt());
//                        break;
//                    case 0xA2:
//                        ui->lbl_ver_fth->setText("V."+aMsg.getDataInt());
//                        break;
//                    }
//                    break;
//            }

//            break;
//        }
//    }
    if ((aMsg.getType()==Message::UPDATE_INIT_ANSWER))
    {
        if(aMsg.getDataInt()!=0xffffffff)
        {
            this->_crtpkgInddex =0;
            _UpdateMessage->GetCurrentMsg(this->_crtpkgInddex);
            itsBaseWindow->addMessageToQue(*_UpdateMessage);
        }
        else
        {
            QMessageBox::warning(this,"Update Failed","",QMessageBox::Ok);
        }
    }
    if ((aMsg.getType()==Message::UPDATE_MCB_ANSWER)||(aMsg.getType()==Message::UPDATE_UIB_ANSWER))
    {
        if(aMsg.getDataInt()!=0xffffffff)
        {
           // this->ui->pb_update->setValue((this->ui->pb_update->value()+1));
            if(this->_crtpkgInddex>=_UpdateMessage->pkgCnt-1)
            {
                QMessageBox::warning(this,"Update finished","",QMessageBox::Ok);

                ParameterMsg msg(Message::UIB,Message::TV,0xA1);
                msg.getWord();
                itsBaseWindow->addMessageToQue(msg);

                ParameterMsg msg1(Message::UIB,Message::TV,0xA2);
                msg1.getWord();
                itsBaseWindow->addMessageToQue(msg1);

            }else
            {
                this->_crtpkgInddex++;
                _UpdateMessage->GetCurrentMsg(this->_crtpkgInddex);
                itsBaseWindow->addMessageToQue(*_UpdateMessage);
            }
        }
        else
        {
            _UpdateMessage->GetCurrentMsg(this->_crtpkgInddex);
            itsBaseWindow->addMessageToQue(*_UpdateMessage);
        }
    }
}

void FMU_UPDATE::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void FMU_UPDATE::on_btn_openfile_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,QObject::tr("select the fmu package"),".//","fmu package (*.fmu)");
    if(filename!="")
    {
        this->setCursor(Qt::WaitCursor);
        QFile f( filename );
        f.open(QIODevice::ReadOnly);
        QDataStream stream(&f);
        QByteArray aLngFile;
        while (!stream.atEnd()){
            char *temp = new char[1];
            stream.readRawData(temp, 1);
            aLngFile.append(*temp);
            delete [] temp;
        }
        f.close();
        _UpdateMessage->refreshupdatebuf(aLngFile);
    }
    this->setCursor(Qt::ArrowCursor);
}

void FMU_UPDATE::on_btn_ok_clicked()
{
    _UpdateMessage->updateInit();
    itsBaseWindow->addMessageToQue(*_UpdateMessage);
}

void FMU_UPDATE::getversion()
{
    fmu_message msg;
    msg.GetVersion(fmu_message::UCB);
    qDebug()<<"GetVersion = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);

    msg.GetVersion(fmu_message::FTHB);
    qDebug()<<"GetVersion = "<<msg.getMsg().toHex();
    itsBaseWindow->addMessageToQue(msg);
}

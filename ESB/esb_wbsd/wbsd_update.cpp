#include "wbsd_update.h"
#include "ui_wbsd_update.h"
#include<QFileDialog>
#include<QMessageBox>
wbsd_update::wbsd_update(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::wbsd_update)
{
    ui->setupUi(this);
    ui->centralwidget->setLayout(ui->verticalLayout);
    _UpdateMessage =new UpdateMessage;
    ui->btn_update->setEnabled(false);
}

wbsd_update::~wbsd_update()
{
    delete ui;
    delete _UpdateMessage;
}

void wbsd_update::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void wbsd_update::gotMessage(Message aMsg)
{
    QByteArray data=aMsg.getData();
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
            this->ui->btn_select->setEnabled(true);
            this->ui->cb_type->setEnabled(true);
            this->ui->btn_update->setEnabled(true);
        }

    }
    if ((aMsg.getType()==Message::UPDATE_MCB_ANSWER)||(aMsg.getType()==Message::UPDATE_UIB_ANSWER))
    {
        if(aMsg.getDataInt()!=0xffffffff)
        {
            this->ui->pb_update->setValue((this->ui->pb_update->value()+1));
            if(this->_crtpkgInddex>=_UpdateMessage->pkgCnt-1)
            {
                QMessageBox::warning(this,"Update finished","",QMessageBox::Ok);
                this->ui->btn_select->setEnabled(true);
                this->ui->cb_type->setEnabled(true);
                this->ui->btn_update->setEnabled(true);
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

void wbsd_update::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void wbsd_update::on_menuBack_triggered()
{
    this->close();
}

void wbsd_update::on_btn_select_clicked()
{
    qDebug()<<"aaaaa";
    //itsBaseWindow->setWincheck(true);
    QString filename=QFileDialog::getOpenFileName(this,"Select image file",".//bin","hex (*.bin)");

    if (filename!=""){
        ui->btn_update->setEnabled(true);
        this->setCursor(Qt::WaitCursor);
        QFile f( filename );
        f.open( QIODevice::ReadOnly);
        QDataStream stream(&f);
        QByteArray aLngFile;
//		instream.setCodec("UTF-16"); // change the file codec to UTF-16.
        while (!stream.atEnd()){
            char *temp = new char[1];
            stream.readRawData(temp, 1);
            aLngFile.append(*temp);
            delete [] temp;
        }
        f.close();
        _UpdateMessage->refreshupdatebuf(aLngFile);
        this->ui->textEdit->setText(filename);

    }
    this->setCursor(Qt::ArrowCursor);

}

void wbsd_update::on_cb_type_activated(int index)
{
    _UpdateMessage->Settype(index==0?0x81:0x91);
}

void wbsd_update::on_btn_update_clicked()
{
    this->ui->btn_select->setEnabled(false);
    this->ui->cb_type->setEnabled(false);
    this->ui->btn_update->setEnabled(false);
    this->ui->pb_update->setValue(0);
    this->ui->pb_update->setMaximum(_UpdateMessage->pkgCnt);
    _UpdateMessage->updateInit();
     itsBaseWindow->addMessageToQue(*_UpdateMessage);

}

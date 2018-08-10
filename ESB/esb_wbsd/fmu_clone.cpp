#include "fmu_clone.h"
#include "fmu_message.h"
#include "ui_fmu_clone.h"
#include "wbsd_serial_port.h"
#include<qdebug.h>
#include <QFileDialog>
#include <QDateTime>
#include <qmessagebox.h>
#include<application.h>
static const char* back[] = {
        QT_TRANSLATE_NOOP("back_version", "Back")
    };
FMU_CLONE::FMU_CLONE(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::FMU_CLONE)
{
    ui->setupUi(this);
    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    CrtCount =-1;
    CrtRcpID =-1;
    CrtOpType =-1; // 1 getdb 2 setdb 3 getrcp 4 setrcp -1 idel
    connect(ui->pb_set,SIGNAL(valueChanged(int)),this,SLOT(uppbset(int)));
    connect(ui->pb_rcp,SIGNAL(valueChanged(int)),this,SLOT(uppbrcp(int)));
    this->setWindowTitle(QObject::tr("MMP Clone"));
     ui->centralwidget->setLayout(ui->gridLayout_2);
}

FMU_CLONE::~FMU_CLONE()
{
    delete ui;
}

void FMU_CLONE::closeEvent(QCloseEvent *evt)
{
    if(!isblockiclose)
     emit iclose();
}
QString Toinfo(QStringList a)
{
    QString ret="";
    for(int i=0;i<a.count();i++)
    {
        ret+=a.at(i);
    }
    return ret;
}

void FMU_CLONE::gotMessage(Message aMsg)
{
    qDebug()<<"got message=="<<aMsg.getMsg().toHex();
    Message::qtype atype=aMsg.getType();
    if(atype == fmu_message::FMU_PARAM_GET)
    {
       bool f;
       int flag = aMsg.getMsg().mid(4,4).toHex().toInt(&f,16);
       int value = aMsg.getMsg().mid(8,4).toHex().toInt(&f,16);
       if((flag &0xffff0000) == 0)
       {
           if(CrtOpType ==1)
           {
           QString txt = QString("ParamId%1:%2").arg(flag).arg(value);
           *dbsstream <<txt<<endl;
            ui->lsbox->appendPlainText(txt);
            ui->pb_set->setValue(ui->pb_set->value()+1);
           }
           else if(CrtOpType==2)
           {
               ui->pb_set->setValue(CrtRcpID++);
              qDebug()<<"lststr.size = "<<lststr.size();
               if(lststr.size()>0)
               {
               QStringList qls = lststr.at(0).split(":");
               QString a = qls.at(0);
               lststr.removeAt(0);
               fmu_message msg;
               msg.SetParam(CrtRcpID-1,qls.at(1).toInt());
               ui->lsbox->appendPlainText(QObject::tr("Upload %1 : value = %2").arg(qls.at(0)).arg(qls.at(1).toInt()));
               itsBaseWindow->addMessageToQue(msg);
               }
           }
       }
       else
       {
           if(CrtOpType ==3)
           {
               int index = flag&0x0000ffff;
               if(CrtRcpID!=((flag &0xffff0000)>>16))
               {
                   CrtRcpID = (flag &0xffff0000)>>16;
                   lstrpc.clear();
                   lstrpc.append(QString("RCPID%1:%2").arg(CrtRcpID).arg(value));
               }
               else
               {
                    lstrpc.append(QString(":%1").arg(value));
                    if(index==29)
                    {
                        QString txt = Toinfo(lstrpc);
                        *rcpstream<<txt<<endl;
                        ui->lsbox->appendPlainText(txt);
                    }
               }

               ui->pb_rcp->setValue(ui->pb_rcp->value()+1);
           }
           else if(CrtOpType ==4)
           {
               int index = flag&0x0000ffff;
                 ui->pb_rcp->setValue(CrtCount++);
               if(index==29)
               {
                   if(lststr.size()>0)
                   {
                       CrtRcpID++;
                       lstrpc.clear();
                       lstrpc = lststr.at(0).split(":");
                       lststr.removeAt(0);
                       fmu_message msg;
                       msg.SetParam(((CrtRcpID&0x0000ffff)<<16)+0,lstrpc.at(1).toInt());
                       ui->lsbox->appendPlainText(QObject::tr("Upload %1 : param %2 :value = %3").arg(lstrpc.at(0)).arg(0).arg(lstrpc.at(1).toInt()));
                       itsBaseWindow->addMessageToQue(msg);
                       lstrpc.removeAt(1);
                   }

               }
               else
               {
                   if(lstrpc.size()>1)
                   {
                       index++;
                       fmu_message msg;
                       msg.SetParam(((CrtRcpID&0x0000ffff)<<16)+index,lstrpc.at(1).toInt());
                       ui->lsbox->appendPlainText(QObject::tr("Upload %1 : param %2 :value = %3").arg(lstrpc.at(0)).arg(index).arg(lstrpc.at(1).toInt()));
                       itsBaseWindow->addMessageToQue(msg);
                       lstrpc.removeAt(1);
                   }

               }
           }
       }
    }
//    else if(atype == fmu_message::FMU_PARAM_SET)
//    {
//        bool f;
//        int flag = aMsg.getMsg().mid(4,4).toHex().toInt(&f,16);
//        int value = aMsg.getMsg().mid(8,4).toHex().toInt(&f,16);
//        if((flag &0xffff0000) == 0)
//        {
//             ui->pb_set->setValue(CrtRcpID++);
//             QStringList qls = lststr.at(0).split(":");
//             QString a = qls.at(0);
//             lststr.removeAt(0);
//             fmu_message msg;
//             msg.SetParam(CrtRcpID-1,qls.at(1).toInt());
//             ui->lsbox->appendPlainText(QObject::tr("Upload %1 : value = %2").arg(qls.at(0)).arg(qls.at(1).toInt()));
//             itsBaseWindow->addMessageToQue(msg);
//        }
//        else
//        {
//            int index = flag&0x0000ffff;
//            if(CrtRcpID!=((flag &0xffff0000)>>16))
//            {
//                CrtRcpID = (flag &0xffff0000)>>16;
//                lstrpc.clear();
//                lstrpc.append(QString("RCPID%1:%2").arg(CrtRcpID).arg(value));
//            }
//            else
//            {
//                 lstrpc.append(QString(":%1").arg(value));
//                 if(index==29)
//                 {
//                     QString txt = Toinfo(lstrpc);
//                     *rcpstream<<txt<<endl;
//                     ui->lsbox->appendPlainText(txt);
//                 }
//            }

//            ui->pb_rcp->setValue(ui->pb_rcp->value()+1);
//        }

//    }


}

void FMU_CLONE::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        isblockiclose = true;
        this->close();
        this->deleteLater();
    }
}

void FMU_CLONE::on_btn_clear_clicked()
{
    ui->lsbox->clear();
}

void FMU_CLONE::on_btn_clone_set_clicked()
{
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getSaveFileName(this,QObject::tr("clone the fmu Setting file"),".//clone","clonefile (*.fmudbclone)");


    if (filename!="")
    {
        _dbsclonefilename = filename;
        clonefiledbs = new QFile(_dbsclonefilename);
        if(clonefiledbs->exists()){QFile::remove(_dbsclonefilename);}
        if(!clonefiledbs->open(QIODevice::WriteOnly|QIODevice::Append))
        {
            ui->lsbox->appendPlainText(QObject::tr("Open file failed!!"));
            ui->btn_clone_rcp->setEnabled(true);
            ui->btn_clone_set->setEnabled(true);
            ui->btn_upload_rcp->setEnabled(true);
            ui->btn_upload_set->setEnabled(true);
            wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
            return;
        }
        dbsstream =new QTextStream(clonefiledbs);
        clonedbs("");
    }
    wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

void FMU_CLONE::clonedbs(QString filename)
{
    ui->pb_rcp->setValue(0);
    ui->pb_set->setValue(0);
    ui->btn_clone_rcp->setEnabled(false);
    ui->btn_clone_set->setEnabled(false);
    ui->btn_upload_rcp->setEnabled(false);
    ui->btn_upload_set->setEnabled(false);
    ui->pb_set->setMaximum(300);
    *dbsstream <<"#this file is configration for fmu#"<<endl;
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
    *dbsstream <<"#Create at:"<<current_date<<" #"<<endl;
    //get 0~299
    CrtOpType =1;
    ui->lsbox->appendPlainText(QObject::tr("####Start to clone Settings!####"));
    for(int i=0;i<300;i++)
    {
        fmu_message msg;
        msg.GetParam(i);
        itsBaseWindow->addMessageToQue(msg);
    }
}

void FMU_CLONE::clonercp(QString filename)
{
    ui->pb_rcp->setValue(0);
    ui->pb_set->setValue(0);
    ui->btn_clone_rcp->setEnabled(false);
    ui->btn_clone_set->setEnabled(false);
    ui->btn_upload_rcp->setEnabled(false);
    ui->btn_upload_set->setEnabled(false);
    ui->pb_rcp->setMaximum(1200);
    *rcpstream <<"#this file is recipe for fmu#"<<endl;
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
    *rcpstream <<"#Create at:"<<current_date<<" #"<<endl;
    //get 0~299
    CrtOpType =3;
    ui->lsbox->appendPlainText(QObject::tr("####Start to clone Settings!####"));
    for(int i=1;i<41;i++)
    {
        for(int j=0;j<30;j++)
        {
            fmu_message msg;
            msg.GetParam(((i&0x0000ffff)<<16)+j);
            itsBaseWindow->addMessageToQue(msg);
        }
    }
}

void FMU_CLONE::uppbset(int value)
{
    if(value == 300)
    {
        ui->lsbox->appendPlainText(QObject::tr("####finished!####"));
        ui->btn_clone_rcp->setEnabled(true);
        ui->btn_clone_set->setEnabled(true);
        ui->btn_upload_rcp->setEnabled(true);
        ui->btn_upload_set->setEnabled(true);
        if(CrtOpType == 1 )
        {
            clonefiledbs->flush();
            clonefiledbs->close();
        }
    }
}

void FMU_CLONE::uppbrcp(int value)
{
    if(value == 1200)
    {
        ui->lsbox->appendPlainText(QObject::tr("####finished!####"));
        ui->btn_clone_rcp->setEnabled(true);
        ui->btn_clone_set->setEnabled(true);
        ui->btn_upload_rcp->setEnabled(true);
        ui->btn_upload_set->setEnabled(true);
        if(CrtOpType == 3)
        {
            clonefilerpc->flush();
            clonefilerpc->close();
        }
    }
}

void FMU_CLONE::on_btn_clone_rcp_clicked()
{
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getSaveFileName(this,QObject::tr("clone the fmu Recipe file"),".//clone","clonefile (*.fmurcpclone)");


    if (filename!="")
    {
        _rcpclonefilename = filename;
        clonefilerpc = new QFile(_rcpclonefilename);
        if(clonefilerpc->exists()){QFile::remove(_rcpclonefilename);}
        if(!clonefilerpc->open(QIODevice::WriteOnly|QIODevice::Append))
        {
            ui->lsbox->appendPlainText(QObject::tr("Open file failed!!"));
            ui->btn_clone_rcp->setEnabled(true);
            ui->btn_clone_set->setEnabled(true);
            ui->btn_upload_rcp->setEnabled(true);
            ui->btn_upload_set->setEnabled(true);
            wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
            return;
        }
        rcpstream =new QTextStream(clonefilerpc);
        clonercp("");
    }
    wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

void FMU_CLONE::on_btn_upload_set_clicked()
{
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getOpenFileName(this,QObject::tr("select the fmu Setting file"),".//clone","clonefile (*.fmudbclone)");

    if(filename!="")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, QObject::tr("Confirm Upload"), QObject::tr("Upload FMU settings to FMU?"),QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QFile file(filename);
            if(!file.exists())
            {
                ui->lsbox->appendPlainText(QObject::tr("Open fmu Setting file failed!"));
                wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                return;
            }
            if(!file.open(QIODevice::ReadOnly))
            {
                ui->lsbox->appendPlainText(QObject::tr("Open fmu Setting file failed!"));
                wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                return;
            }
            ui->pb_rcp->setValue(0);
            ui->pb_set->setValue(0);
            ui->pb_set->setMaximum(300);
            ui->pb_rcp->setMaximum(120);
            ui->btn_clone_rcp->setEnabled(false);
            ui->btn_clone_set->setEnabled(false);
            ui->btn_upload_rcp->setEnabled(false);
            ui->btn_upload_set->setEnabled(false);
            QTextStream fileOut(&file);
            lststr.clear();
            while(!fileOut.atEnd())
            {
                QString strinfo = fileOut.readLine();
                if(strinfo.startsWith("ParamId"))
                lststr.append(strinfo);
            }
            file.close();
            CrtRcpID =1;
            QStringList qls = lststr.at(0).split(":");
            QString a = qls.at(0);
            lststr.removeAt(0);
            fmu_message msg;
            ui->lsbox->appendPlainText(QObject::tr("####Start to upload Settings!####"));
            CrtOpType =2;
            msg.SetParam(CrtRcpID-1,qls.at(1).toInt());
            ui->lsbox->appendPlainText(QObject::tr("Upload %1 : value = %2").arg(qls.at(0)).arg(qls.at(1).toInt()));
            itsBaseWindow->addMessageToQue(msg);
        }

    }
}

void FMU_CLONE::on_btn_upload_rcp_clicked()
{
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getOpenFileName(this,QObject::tr("select the fmu Recipe file"),".//clone","clonefile (*.fmurcpclone)");

    if(filename!="")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, QObject::tr("Confirm Upload"), QObject::tr("Upload the fmu Recipe to fmu?"),QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QFile file(filename);
            if(!file.exists())
            {
                ui->lsbox->appendPlainText(QObject::tr("Open fmu Recipe file failed!!"));
                wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                return;
            }
            if(!file.open(QIODevice::ReadOnly))
            {
                ui->lsbox->appendPlainText(QObject::tr("Open fmu Recipe file failed!!"));
                wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                return;
            }
            ui->pb_rcp->setValue(0);
            ui->pb_set->setValue(0);
            ui->pb_set->setMaximum(300);
            ui->pb_rcp->setMaximum(1200);
            ui->btn_clone_rcp->setEnabled(false);
            ui->btn_clone_set->setEnabled(false);
            ui->btn_upload_rcp->setEnabled(false);
            ui->btn_upload_set->setEnabled(false);
            QTextStream fileOut(&file);
            lststr.clear();
            while(!fileOut.atEnd())
            {
                QString strinfo = fileOut.readLine();
                if(strinfo.startsWith("RCPID"))
                lststr.append(strinfo);
            }
            file.close();
            CrtCount =1;
            CrtRcpID =1;
            lstrpc.clear();
            lstrpc = lststr.at(0).split(":");
            lststr.removeAt(0);

            fmu_message msg;
            CrtOpType =4;
            ui->lsbox->appendPlainText(QObject::tr("####Start to upload Recipes!####"));
            msg.SetParam(((CrtRcpID&0x0000ffff)<<16)+0,lstrpc.at(1).toInt());
            ui->lsbox->appendPlainText(QObject::tr("Upload %1 : param %2 :value = %3").arg(lstrpc.at(0)).arg(CrtCount-1).arg(lstrpc.at(1).toInt()));
            itsBaseWindow->addMessageToQue(msg);
            lstrpc.removeAt(1);
        }

    }
}

void FMU_CLONE::on_menuBack_triggered()
{
    this->close();
}

#include "wbsd_clone.h"
#include "ui_wbsd_clone.h"
#include "message.h"
#include<QDebug>
#include"lngmessage.h"
#include"parametermsg.h"
#include <QTextStream>
#include"databasehelper.h"
#include"rcpmessage.h"
#include<QMessageBox>
#include<QThread>
#include<QFileDialog>
#include"wbsd_serial_port.h"
#include"application.h"
/*modify by Lee
1： version control. get the current machine's Fireware version.
2： upload checking, if the fireware version is too old to support the database file,
   it should forbid the upload and give the warning msg.

   modify clone count bug
  modify by lee
  version 1.37
  add mcb db count ==61
*/
wbsdclone::wbsdclone(WBSDBaseWindow *parent, bool bakmod) :
    WBSDChildWindow(parent),
    ui(new Ui::wbsdclone)
{
    static const char* back[] = {
            QT_TRANSLATE_NOOP("back_version", "Back")
        };

    ui->setupUi(this);
    ParameterMsg msg14(Message::MCB,Message::DP,26);
    msg14.getWord();
    itsBaseWindow->addMessageToQue(msg14);
    fmuclonewin=0;
    menuBack = new QAction(Application::translate("back_doser",back[0]), this);
        menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    _isbakmode = bakmod;
    if(bakmod) //hide all clone function
    {
       ui->btnr->hide();
       ui->btnlang->hide();
       ui->btnlang_2->hide();
       ui->btnd->hide();
       ui->progressBar->hide();
       ui->progressBar_3->hide();
       ui->label_3->hide();
       ui->label_6->hide();
       ui->label_7->hide();
       ui->label->hide();
       uib_dp_bak_cnt = 16;
    }
    else
    {
        uib_dp_bak_cnt =23;
        ui->btn_backup->hide();
        ui->btn_restore->hide();
        ui->label_4->hide();
        ui->progressBar_2->hide();
        ui->label_2->hide();
    }


    _crtOpType =0;
    _crtDbsCnt = MCB_AP_CNT+MCB_DP_CNT+UIB_DP_CNT;
    ui->progressBar->setMaximum(_crtDbsCnt);
    connect(ui->progressBar,SIGNAL(valueChanged(int)),this,SLOT(dbsup(int)));
    connect(ui->progressBar_2,SIGNAL(valueChanged(int)),this,SLOT(dbsup(int)));
    _RcpIdLst = DataBaseHelper::getInstance()->GetRcpItemID();
    ui->progressBar_3->setMaximum(_RcpIdLst.count());
    itsRecipe=new Recipe();
    _crtRpcIndex=0;
    this->centralWidget()->setLayout(ui->gridLayout);
    //ui->progressBar_2->hide();
   // ui->btn_backup->hide();
   //ui->btn_restore->hide();
    //ui->progressBar_3->hide();
    //ui->label_2->hide();
    //ui->label_3->hide();
    _mcbVersion="";

    /* modify by lee  save the clone file in dif name.
     * first: if the Clone dir exis? create it; Path = :/clone;
     * second: the file has the special Name (for dbs:**.dbsclone for recipe:**.rcpclone)
     */
    _dbsclonefilename="default_dbs";
    _rcpclonefilename="default_rpc";
     clonefiledbs =0;

     clonefilerpc=0;
     rcpstream=0;
     dbsstream=0;
     bkfiledbs=0;
     dbsbkstream=0;
     this->setWindowTitle(QObject::tr("Clone"));


     ui->progressBar_2->setMaximum(204+uib_dp_bak_cnt+6);



     //get version
     Message msg;
     msg.msg[0]=0x02;
     msg.msg[1]=0xb7;
     msg.msg[2]=0xa1;
     msg.msg[3]=0x60;
     msg.msg[4]=0x00;
     msg.msg[5]=0x00;
     msg.msg[6]=0x00;
     msg.msg[7]=0x00;
     itsBaseWindow->addMessageToQue(msg);



}

wbsdclone::~wbsdclone()
{
    delete ui;
    delete itsRecipe;
    if(clonefiledbs!=0)
    delete clonefiledbs;
    if(clonefilerpc!=0)
    delete clonefilerpc;
    if(rcpstream!=0)
    delete rcpstream;
    if(dbsstream !=0)
    delete dbsstream;
    if(dbsbkstream!=0)
    delete dbsbkstream;
    if(bkfiledbs !=0)
    delete bkfiledbs;
}

void wbsdclone::Getlngcmd(int lngId)
{

}

void wbsdclone::closeEvent(QCloseEvent *)
{
    emit iclose();
}




void wbsdclone::gotMessage(Message aMsg)
{
    QByteArray data=aMsg.getData();



    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::DP) )
    {
        if(_crtOpType==1)
        {
            ui->plainTextEdit->appendPlainText(QObject::tr("MCB DP BLOCK %1 value is %2").arg((unsigned char)aMsg.getParameters().at(3)).arg(aMsg.getDataUInt()));
            //qDebug() << (int)aMsg.getMsg().at(7);
            *dbsstream <<"MCBDP:"<<(unsigned char)aMsg.getParameters().at(3)<<":"<<aMsg.getDataUInt()<<endl;
            ui->progressBar->setValue(ui->progressBar->value()+1);
            if(aMsg.getParameters().at(3)== 2)
            {
                itsRecipe->de_airtime=aMsg.getDataInt();
            }
        }
        else if(_crtOpType==4)
        {
            ui->plainTextEdit->appendPlainText(QObject::tr("MCB DP BLOCK %1 value is %2").arg((unsigned char)aMsg.getParameters().at(3)).arg(aMsg.getDataUInt()));
            *dbsbkstream<<"MCBDP:"<<(unsigned char)aMsg.getParameters().at(3)<<":"<<aMsg.getDataUInt()<<endl;
            ui->progressBar_2->setValue(ui->progressBar_2->value()+1);

        }
        else if(_crtOpType ==0)
        {
            if((unsigned char)aMsg.getParameters().at(3) == 26)
            {
               int  aVal=aMsg.getDataUInt();
                if(((aVal&0x40)>>6) == 0)
                {
                    ui->pushButton->setVisible(false);
                    ui->label_5->setVisible(false);
                }
                else
                {
                    ui->pushButton->setVisible(true);
                    ui->label_5->setVisible(true);
                }
            }
        }
    }
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::MCB) && (aMsg.getDataBaseType()==Message::AP) )
    {
        if(_crtOpType==1)
        {
            ui->plainTextEdit->appendPlainText(QObject::tr("MCB AP BLOCK %1 value is %2").arg((unsigned char)aMsg.getParameters().at(3)).arg(aMsg.getDataFloat()));
            //qDebug() << (int)aMsg.getMsg().at(7);
            *dbsstream <<"MCBAP:"<<(unsigned char)aMsg.getParameters().at(3)<<":"<<aMsg.getDataFloat()<<endl;
            ui->progressBar->setValue(ui->progressBar->value()+1);
            if(aMsg.getParameters().at(3)== 27)
            {
                itsRecipe->ingr_ml_per_gram=aMsg.getDataFloat();
            }
        }
        else if(_crtOpType==4)
        {
            ui->plainTextEdit->appendPlainText(QObject::tr("MCB AP BLOCK %1 value is %2").arg((unsigned char)aMsg.getParameters().at(3)).arg(aMsg.getDataFloat()));
           *dbsbkstream <<"MCBAP:"<<(unsigned char)aMsg.getParameters().at(3)<<":"<<aMsg.getDataFloat()<<endl;
            ui->progressBar_2->setValue(ui->progressBar_2->value()+1);
        }
    }
    if ((aMsg.getType()==Message::REPLY_DB) && ((unsigned char)aMsg.getBoard()==Message::UIB) && (aMsg.getDataBaseType()==Message::DP) )
    {
        if(_crtOpType==1)
        {
            ui->plainTextEdit->appendPlainText(QObject::tr("UIB DP BLOCK %1 value is %2").arg((unsigned char)aMsg.getParameters().at(3)).arg(aMsg.getDataUInt()));
            //qDebug() << (int)aMsg.getMsg().at(7);

            *dbsstream <<"UIBDP:"<<(unsigned char)aMsg.getParameters().at(3)<<":"<<aMsg.getDataInt()<<endl;
            ui->progressBar->setValue(ui->progressBar->value()+1);
        }
        else if(_crtOpType==4)
        {
            ui->plainTextEdit->appendPlainText(QObject::tr("UIB DP BLOCK %1 value is %2").arg((unsigned char)aMsg.getParameters().at(3)).arg(aMsg.getDataUInt()));
            if((unsigned char)aMsg.getParameters().at(3) == 16 && _isbakmode)
            {
                *dbsbkstream <<"UIBDP:"<<"18"<<":"<<(aMsg.getDataInt() & 0xfffb) <<endl;
            }else
            {
                *dbsbkstream <<"UIBDP:"<<(unsigned char)aMsg.getParameters().at(3)<<":"<<aMsg.getDataInt()<<endl;
            }
            ui->progressBar_2->setValue(ui->progressBar_2->value()+1);
        }
    }


    //get version
    if ((aMsg.getType()==Message::METADATA_ANSWER) )
    {

         StringMessage sm(aMsg);
         QList <QString> al=sm.getList();
         _mcbVersion = al.at(1);
         QString Mcbinfo = al.at(1);
         QStringList tmplst = Mcbinfo.split(":");
         qDebug()<<tmplst.at(1);
         ui->plainTextEdit->appendPlainText(QObject::tr("Current ")+_mcbVersion);
         ui->plainTextEdit->appendPlainText(QObject::tr("!!!!!!!!!!!!For Your Attention!!!!!!!!!!!!"));
         ui->plainTextEdit->appendPlainText(QObject::tr("When upload the database file,please make sure clone between same SW versions"));

    }
    //getrpc
    if (aMsg.getType()==Message::ANSWER_RECIPE_P0){
        itsRecipe->large_cup=aMsg.getDataInt(2,false,2);
        itsRecipe->medium_cup=aMsg.getDataInt(3,false,2);
        itsRecipe->small_cup=aMsg.getDataInt(4,false,2);
        itsBaseWindow->addMessageToQue(RcpMessage(itsRecipe->getId(),1));
        qDebug() << "ANSWER_RECIPE_P0";
        return;
    }
    if (aMsg.getType()==Message::ANSWER_RECIPE_P1){
        qDebug() << "ANSWER_RECIPE_P1_Start";
        itsRecipe->left_bib_mild_ratio=aMsg.getDataFloat(1,false);
        itsRecipe->left_bib_norm_ratio=aMsg.getDataFloat(2,false);
        itsRecipe->left_bib_strong_ratio=aMsg.getDataFloat(3,false);
        itsRecipe->left_bib_percent=aMsg.getDataInt(8,false,2);
        itsRecipe->right_bib_percent=aMsg.getDataInt(9,false,2);
        itsBaseWindow->addMessageToQue(RcpMessage(itsRecipe->getId(),2));
        qDebug() << "ANSWER_RECIPE_P1";
        return;
    }
    if (aMsg.getType()==Message::ANSWER_RECIPE_P2){
        qDebug() << "ANSWER_RECIPE_P2_Start";
        itsRecipe->right_bib_mild_ratio=aMsg.getDataFloat(1,false);
        itsRecipe->right_bib_norm_ratio=aMsg.getDataFloat(2,false);
        itsRecipe->right_bib_strong_ratio=aMsg.getDataFloat(3,false);
        itsRecipe->left_bib_airpump_speed=aMsg.getDataInt(8,false,2);
        itsRecipe->right_bib_airpump_speed=aMsg.getDataInt(9,false,2);;
        itsBaseWindow->addMessageToQue(RcpMessage(itsRecipe->getId(),3));
        qDebug() << "ANSWER_RECIPE_P2";
        return;
    }
    if (aMsg.getType()==Message::ANSWER_RECIPE_P3){
        itsRecipe->instant_ingredient_gram_mild=aMsg.getDataFloat(1,false);
        itsRecipe->instant_ingredient_gram_norm=aMsg.getDataFloat(2,false);
        itsRecipe->instant_ingredient_gram_strong=aMsg.getDataFloat(3,false);
        itsRecipe->fmu_id=aMsg.getDataInt(8,false,2);
        itsRecipe->fmu_percentage=aMsg.getDataInt(9,false,2);

        //finish write the rcp to the file;

        ui->plainTextEdit->appendPlainText("#################################");
        ui->plainTextEdit->appendPlainText(itsRecipe->toRLine());

        *rcpstream<<itsRecipe->toRLine()<<endl;
        //get next RPC
        ui->progressBar_3->setValue(_crtRpcIndex);
        if(_crtRpcIndex <  _RcpIdLst.count() ){
        this->getrpc((_RcpIdLst.at(_crtRpcIndex++)&0x000000ff));}else
        {
            ui->btnd->setEnabled(true);
            ui->btnlang->setEnabled(true);
            ui->btnr->setEnabled(true);
            ui->btnlang_2->setEnabled(true);
            clonefilerpc->flush();
            clonefilerpc->close();
        }
        return;
    }

    if ((aMsg.getType()==Message::ANSWER_SET_RCP)&& ( _crtOpType==2))
    {
        ui->progressBar_3->setValue(_crtRpcIndex++);
        qDebug()<<"Message::ANSWER_SET_RCP"<<aMsg.getData().toHex();
        if(!lstrpc.empty())
        {
        itsRecipe = new Recipe(lstrpc.at(0));
        this->ui->plainTextEdit->appendPlainText(QObject::tr("Upload RCP = %1").arg(lstrpc.at(0)));

        RcpMessage aRMsg(*itsRecipe);
        itsBaseWindow->addMessageToQue(aRMsg);
        lstrpc.removeAt(0);
        }
        else
        {
            ui->btnd->setEnabled(true);
            ui->btnlang->setEnabled(true);
            ui->btnr->setEnabled(true);
            ui->btnlang_2->setEnabled(true);
            _crtOpType =0;
        }
    }

    if((aMsg.getType()==Message::ANSWER_SET_PARAMETER))
    {
        if( _crtOpType==3)
        {
            ui->progressBar->setValue(_crtRpcIndex++);
            if(!lststr.empty())
            {
                QStringList qls = lststr.at(0).split(":");
                QString a = qls.at(0);
                lststr.removeAt(0);
                //QThread::msleep(5);
                if (a == "MCBDP") {
                    //set dp
                    ParameterMsg pmsg(Message::MCB,Message::DP,qls.at(1).toInt(),Message::SET_PARAMETER);
                    pmsg.setWord(qls.at(2).toInt());
                    itsBaseWindow->addMessageToQue(pmsg);
                    this->ui->plainTextEdit->appendPlainText(QObject::tr("Upload %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

                }
                if (a == "MCBAP") {
                    //set dp
                    ParameterMsg pmsg(Message::MCB,Message::AP,qls.at(1).toInt(),Message::SET_PARAMETER);
                    pmsg.setFloat(qls.at(2).toFloat());
                    itsBaseWindow->addMessageToQue(pmsg);
                    this->ui->plainTextEdit->appendPlainText(QObject::tr("Upload %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

                }
                if (a == "UIBDP") {
                    //set dp
                    ParameterMsg pmsg(Message::UIB,Message::DP,qls.at(1).toInt(), Message::SET_PARAMETER);
                    pmsg.setWord(qls.at(2).toInt());
                    itsBaseWindow->addMessageToQue(pmsg);
                    this->ui->plainTextEdit->appendPlainText(QObject::tr("Upload %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

                }
            }
            else
            {
                ui->btnd->setEnabled(true);
                ui->btnlang->setEnabled(true);
                ui->btnr->setEnabled(true);
                ui->btnlang_2->setEnabled(true);
                _crtOpType =0;
            }
        }else if(_crtOpType==5)
        {
            ui->progressBar_2->setValue(_crtRpcIndex++);
            if(!lststr.empty())
            {
                QStringList qls = lststr.at(0).split(":");
                QString a = qls.at(0);
                lststr.removeAt(0);
                //QThread::msleep(5);
                if (a == "MCBDP") {
                    //set dp
                    ParameterMsg pmsg(Message::MCB,Message::DP,qls.at(1).toInt(),Message::SET_PARAMETER);
                    pmsg.setWord(qls.at(2).toInt());
                    itsBaseWindow->addMessageToQue(pmsg);
                    this->ui->plainTextEdit->appendPlainText(QObject::tr("Restore %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

                }
                if (a == "MCBAP") {
                    //set dp
                    ParameterMsg pmsg(Message::MCB,Message::AP,qls.at(1).toInt(),Message::SET_PARAMETER);
                    pmsg.setFloat(qls.at(2).toFloat());
                    itsBaseWindow->addMessageToQue(pmsg);
                    this->ui->plainTextEdit->appendPlainText(QObject::tr("Restore %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

                }
                if (a == "UIBDP") {
                    //set dp
                    ParameterMsg pmsg(Message::UIB,Message::DP,qls.at(1).toInt(), Message::SET_PARAMETER);
                    pmsg.setWord(qls.at(2).toInt());
                    itsBaseWindow->addMessageToQue(pmsg);
                    this->ui->plainTextEdit->appendPlainText(QObject::tr("Restore %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

                }
            }
            else
            {
                ui->btnd->setEnabled(true);
                ui->btnlang->setEnabled(true);
                ui->btnr->setEnabled(true);
                ui->btnlang_2->setEnabled(true);
                _crtOpType =0;
            }
        }

    }
}

void wbsdclone::connectionStatusChanged(int aStatus, StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}
void wbsdclone::on_btnlang_clicked()
{
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getSaveFileName(this,QObject::tr("clone the dbs file"),".//clone","clonefile (*.dbsclone)");


    if (filename!="")
    {
        _dbsclonefilename = filename;
        clonefiledbs = new QFile(_dbsclonefilename);
        if(clonefiledbs->exists()){QFile::remove(_dbsclonefilename);}
        if(!clonefiledbs->open(QIODevice::WriteOnly|QIODevice::Append))
        {
            ui->plainTextEdit->appendPlainText(QObject::tr("Open file failed!!"));
            ui->btnd->setEnabled(true);
            ui->btnlang->setEnabled(true);
            ui->btnr->setEnabled(true);
            ui->btnlang_2->setEnabled(true);
            wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
            return;
        }
        if(_mcbVersion == "")
        {
            ui->plainTextEdit->appendPlainText(QObject::tr(("Get Clone File Version failed! Please Retry!")));
            ui->btnd->setEnabled(true);
            ui->btnlang->setEnabled(true);
            ui->btnr->setEnabled(true);
            ui->btnlang_2->setEnabled(true);
            wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
            return;
        }
        dbsstream =new QTextStream(clonefiledbs);
        clonedbs("");
    }
    wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

void wbsdclone::on_btnlang_2_clicked()
{
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getSaveFileName(this,QObject::tr("clone the recipe file"),".//clone","clonefile (*.rcpclone)");


    if (filename!="")
    {
        _rcpclonefilename = filename;
        clonefilerpc = new QFile(_rcpclonefilename);
        if(clonefilerpc->exists()){QFile::remove(_rcpclonefilename);}
        if(!clonefilerpc->open(QIODevice::WriteOnly|QIODevice::Append))
        {
            ui->plainTextEdit->appendPlainText(QObject::tr("Open file failed!!"));
            ui->btnd->setEnabled(true);
            ui->btnlang->setEnabled(true);
            ui->btnr->setEnabled(true);
            ui->btnlang_2->setEnabled(true);
            wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
            return;
        }
        rcpstream =new QTextStream(clonefilerpc);
        clonercp("");
    }
    wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

void wbsdclone::on_btnd_clicked()
{
    //wbsd_SERIAL_PORT::itsInstance->disableTimers();
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getOpenFileName(this,QObject::tr("select the dbs file"),".//clone","clonefile (*.dbsclone)");

    if(filename!="")
    {
        //wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
        QMessageBox::StandardButton reply = QMessageBox::question(this, QObject::tr("Confirm Upload"), QObject::tr("Upload the DBS param to machine?"),QMessageBox::Yes|QMessageBox::No);
        //wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
        if (reply == QMessageBox::Yes) {

            //

             ui->progressBar->setValue(0);
             _crtOpType =3;
             ui->btnd->setEnabled(false);
             ui->btnlang->setEnabled(false);
             ui->btnr->setEnabled(false);
             ui->btnlang_2->setEnabled(false);
             QFile file(filename);
             if(!file.exists())
             {
                 ui->plainTextEdit->appendPlainText(QObject::tr("Open DBS file failed!!"));
                 ui->btnd->setEnabled(true);
                 ui->btnlang->setEnabled(true);
                 ui->btnr->setEnabled(true);
                 ui->btnlang_2->setEnabled(true);
                 wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                 return;
             }
             if(!file.open(QIODevice::ReadOnly))
             {
                 ui->plainTextEdit->appendPlainText(QObject::tr("Open DBS file failed!!"));
                 ui->btnd->setEnabled(true);
                 ui->btnlang->setEnabled(true);
                 ui->btnr->setEnabled(true);
                 ui->btnlang_2->setEnabled(true);
                 wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                 return;
             }
             QTextStream fileOut(&file);
             lststr.clear();
             while(!fileOut.atEnd())
             {
                 lststr.append(fileOut.readLine());
             }
             file.close();
             _crtRpcIndex =1;
             //first = ver;
             if(lststr.at(0)!=_mcbVersion)
             {
                 //wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                 QMessageBox::critical(this,"Upload Error","SW version is different,can not upload!!",QMessageBox::Yes);
                 //wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
                 ui->btnd->setEnabled(true);
                 ui->btnlang->setEnabled(true);
                 ui->btnr->setEnabled(true);
                 ui->btnlang_2->setEnabled(true);
                 wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                 //wbsd_SERIAL_PORT::itsInstance->enableTimers();
                 return;
             }
             lststr.removeAt(0);
             QStringList qls = lststr.at(0).split(":");
             QString a = qls.at(0);
             lststr.removeAt(0);
             if (a == "MCBDP") {
                 //set dp
                 ParameterMsg pmsg(Message::MCB,Message::DP,qls.at(1).toInt(),Message::SET_PARAMETER);
                 pmsg.setWord(qls.at(2).toInt());
                 itsBaseWindow->addMessageToQue(pmsg);
                 this->ui->plainTextEdit->appendPlainText(QObject::tr("Upload %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

             }
             if (a == "MCBAP") {
                 //set dp
                 ParameterMsg pmsg(Message::MCB,Message::AP,qls.at(1).toInt(),Message::SET_PARAMETER);
                 pmsg.setFloat(qls.at(2).toFloat());
                 itsBaseWindow->addMessageToQue(pmsg);
                 this->ui->plainTextEdit->appendPlainText(QObject::tr("Upload %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

             }
             if (a == "UIBDP") {
                 //set dp
                 ParameterMsg pmsg(Message::UIB,Message::DP,qls.at(1).toInt(), Message::SET_PARAMETER);
                 pmsg.setWord(qls.at(2).toInt());
                 itsBaseWindow->addMessageToQue(pmsg);
                 this->ui->plainTextEdit->appendPlainText(QObject::tr("Upload %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

             }
         }
    }

wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

void wbsdclone::on_btnr_clicked()
{

   wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getOpenFileName(this,QObject::tr("select the recipe file"),".//clone","clonefile (*.rcpclone)");
    //wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    if(filename!="")
    {
        //wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
        QMessageBox::StandardButton reply = QMessageBox::question(this, QObject::tr("Confirm Upload file"), QObject::tr("Upload the RCP to machine?"),QMessageBox::Yes|QMessageBox::No);
        //wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
        if (reply == QMessageBox::Yes) {
            _crtOpType =2;
            ui->progressBar_3->setValue(0);
            QFile filerpc(filename);
            if(!filerpc.exists())
            {
                ui->plainTextEdit->appendPlainText(QObject::tr("Open RPC file failed!!"));
                ui->btnd->setEnabled(true);
                ui->btnlang->setEnabled(true);
                ui->btnr->setEnabled(true);
                ui->btnlang_2->setEnabled(true);
               wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                return;
            }
            if(!filerpc.open(QIODevice::ReadOnly))
            {
                ui->plainTextEdit->appendPlainText(QObject::tr("Open RPC file failed!!"));
                ui->btnd->setEnabled(true);
                ui->btnlang->setEnabled(true);
                ui->btnr->setEnabled(true);
                ui->btnlang_2->setEnabled(true);
                wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                return;
            }
            QTextStream fileOutrpc(&filerpc);
            lstrpc.clear();
            while(!fileOutrpc.atEnd())
            {
                lstrpc.append(fileOutrpc.readLine());
            }
            filerpc.close();

            if(!lstrpc.empty())
            {
                _crtRpcIndex =1;
                ui->btnd->setEnabled(false);
                ui->btnlang->setEnabled(false);
                ui->btnr->setEnabled(false);
                ui->btnlang_2->setEnabled(false);
                ui->progressBar_3->setMaximum(lstrpc.count());
                itsRecipe = new Recipe(lstrpc.at(0));
                this->ui->plainTextEdit->appendPlainText(QObject::tr("Upload RCP = %1").arg(lstrpc.at(0)));
                RcpMessage aRMsg(*itsRecipe);
                itsBaseWindow->addMessageToQue(aRMsg);
                lstrpc.removeAt(0);
            }
        }
    }
wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

void wbsdclone::on_btn_clear_clicked()
{
    ui->plainTextEdit->clear();
}

void wbsdclone::on_btn_backup_clicked()
{
    ui->progressBar_2->setMaximum(204+uib_dp_bak_cnt+6);
    //备份机器自定义数据块。包括counters,button map，cleaning-moment，display-setting，general-setting，service-number
    //MCB AP7-AP200
    //UIB DP0-DP23 (use for ver>0.85)  else DP0-DP15\ DP16 zuo yingshe
    //MCB DP0-DP1 DP4 DP6-DP9 DP22-DP23
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getSaveFileName(this,QObject::tr("wbsd bak file"),".//bak","bakfile (*.wbsdbak)");
    if (filename!="")
    {
        bkfiledbs = new QFile(filename);
        if(bkfiledbs->exists()){QFile::remove(filename);}
        if(!bkfiledbs->open(QIODevice::WriteOnly|QIODevice::Append))
        {
            wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
            return;
        }
        ui->btnd->setEnabled(false);
        ui->btnlang->setEnabled(false);
        ui->btnr->setEnabled(false);
        ui->btnlang_2->setEnabled(false);
    dbsbkstream =new QTextStream(bkfiledbs);
    ui->progressBar_2->setValue(0);
    _crtOpType =4;
    for(int i=7;i<=200;i++)
    {
        ParameterMsg pmsg (Message::MCB,Message::AP,i);
        pmsg.getFloat();
        itsBaseWindow->addMessageToQue(pmsg);
    }
    //15改成变量16 old  23 new
    for(int i=0;i<=uib_dp_bak_cnt;i++)
    {
        ParameterMsg pmsg (Message::UIB,Message::DP,i);
        pmsg.getWord();
        itsBaseWindow->addMessageToQue(pmsg);
    }
    ParameterMsg pmsg (Message::MCB,Message::DP,0);
    pmsg.getWord();
    itsBaseWindow->addMessageToQue(pmsg);

    ParameterMsg pmsg1 (Message::MCB,Message::DP,1);
    pmsg1.getWord();
    itsBaseWindow->addMessageToQue(pmsg1);

    ParameterMsg pmsg4 (Message::MCB,Message::DP,4);
    pmsg4.getWord();
    itsBaseWindow->addMessageToQue(pmsg4);

    ParameterMsg pmsg6 (Message::MCB,Message::DP,6);
    pmsg6.getWord();
    itsBaseWindow->addMessageToQue(pmsg6);

    ParameterMsg pmsg7 (Message::MCB,Message::DP,7);
    pmsg7.getWord();
    itsBaseWindow->addMessageToQue(pmsg7);

    ParameterMsg pmsg8 (Message::MCB,Message::DP,8);
    pmsg8.getWord();
    itsBaseWindow->addMessageToQue(pmsg8);

    ParameterMsg pmsg9 (Message::MCB,Message::DP,9);
    pmsg9.getWord();
    itsBaseWindow->addMessageToQue(pmsg9);

    for(int i=10;i<=15;i++)
    {
        ParameterMsg pmsg (Message::MCB,Message::DP,i);
        pmsg.getWord();
        itsBaseWindow->addMessageToQue(pmsg);
    }
    ParameterMsg pmsg22 (Message::MCB,Message::DP,22);
    pmsg22.getWord();
    itsBaseWindow->addMessageToQue(pmsg22);

    ParameterMsg pmsg23 (Message::MCB,Message::DP,23);
    pmsg23.getWord();
    itsBaseWindow->addMessageToQue(pmsg23);
    }
    wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

void wbsdclone::on_btn_restore_clicked()
{
    //还原设备数据
    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
    QString filename=QFileDialog::getOpenFileName(this,QObject::tr("select the bak file"),".//bak","bakfile (*.wbsdbak)");
    if(filename!="")
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, QObject::tr("Confirm Restore"), QObject::tr("Restore the machine?"),QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
             ui->progressBar_2->setValue(0);
             _crtOpType =5;
             ui->btnd->setEnabled(false);
             ui->btnlang->setEnabled(false);
             ui->btnr->setEnabled(false);
             ui->btnlang_2->setEnabled(false);
             QFile file(filename);
             if(!file.exists())
             {
                 ui->plainTextEdit->appendPlainText(QObject::tr("Open DBS BAK file failed!!"));
                 ui->btnd->setEnabled(true);
                 ui->btnlang->setEnabled(true);
                 ui->btnr->setEnabled(true);
                 ui->btnlang_2->setEnabled(true);
                 wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                 return;
             }
             if(!file.open(QIODevice::ReadOnly))
             {
                 ui->plainTextEdit->appendPlainText(QObject::tr("Open DBS BAK file failed!!"));
                 ui->btnd->setEnabled(true);
                 ui->btnlang->setEnabled(true);
                 ui->btnr->setEnabled(true);
                 ui->btnlang_2->setEnabled(true);
                 wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
                 return;
             }
             QTextStream fileOut(&file);
             lststr.clear();
             while(!fileOut.atEnd())
             {
                 lststr.append(fileOut.readLine());
             }
             file.close();
             ui->progressBar_2->setMaximum(lststr.count());
             _crtRpcIndex =1;
             QStringList qls = lststr.at(0).split(":");
             QString a = qls.at(0);
             lststr.removeAt(0);
             if (a == "MCBDP") {
                 //set dp
                 ParameterMsg pmsg(Message::MCB,Message::DP,qls.at(1).toInt(),Message::SET_PARAMETER);
                 pmsg.setWord(qls.at(2).toInt());
                 itsBaseWindow->addMessageToQue(pmsg);
                 this->ui->plainTextEdit->appendPlainText(QObject::tr("Restore %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

             }
             if (a == "MCBAP") {
                 //set dp
                 ParameterMsg pmsg(Message::MCB,Message::AP,qls.at(1).toInt(),Message::SET_PARAMETER);
                 pmsg.setFloat(qls.at(2).toFloat());
                 itsBaseWindow->addMessageToQue(pmsg);
                 this->ui->plainTextEdit->appendPlainText(QObject::tr("Restore %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

             }
             if (a == "UIBDP") {
                 //set dp
                 ParameterMsg pmsg(Message::UIB,Message::DP,qls.at(1).toInt(), Message::SET_PARAMETER);
                 pmsg.setWord(qls.at(2).toInt());
                 itsBaseWindow->addMessageToQue(pmsg);
                 this->ui->plainTextEdit->appendPlainText(QObject::tr("Restore %1 :%2  value = %3").arg(qls.at(0)).arg(qls.at(1).toInt()).arg(qls.at(2).toInt()));

             }
         }
    }
    wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}

void wbsdclone::dbsup(int cnt)
{
    if((cnt == (MCB_AP_CNT+MCB_DP_CNT+UIB_DP_CNT)) && ( _crtOpType==1))
     {
        ui->btnd->setEnabled(true);
        ui->btnlang->setEnabled(true);
        ui->btnr->setEnabled(true);
        ui->btnlang_2->setEnabled(true);
        clonefiledbs->flush();
        clonefiledbs->close();
        //判断文件是否有版本信息。
    }
    if((cnt ==(204+uib_dp_bak_cnt+6)) && ( _crtOpType==4))
    {
        ui->btnd->setEnabled(true);
        ui->btnlang->setEnabled(true);
        ui->btnr->setEnabled(true);
        ui->btnlang_2->setEnabled(true);
        bkfiledbs->flush();
        bkfiledbs->close();
    }
}

bool wbsdclone::setversion()
{
    QFile file("Version.txt");
    if(!file.exists())
    {
        return false;
    }
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }


}

void wbsdclone::getrpc(int rcpId)
{
    qDebug()<<"getrpc id ="<<rcpId;
    itsRecipe->id = rcpId;
    if (itsRecipe->loadFromDB(rcpId))
        itsBaseWindow->addMessageToQue(RcpMessage(rcpId));
}

void wbsdclone::clonedbs(QString filename)
{

    _crtOpType =1;
    ui->progressBar->setValue(0);
    ui->progressBar_3->setValue(0);
    ui->btnd->setEnabled(false);
    ui->btnlang->setEnabled(false);
    ui->btnr->setEnabled(false);
    ui->btnlang_2->setEnabled(false);

    *dbsstream <<_mcbVersion<<endl;
    //get dbs
    for(int i=0;i<MCB_DP_CNT;i++)
    {
        ParameterMsg pmsg (Message::MCB,Message::DP,i);
        pmsg.getWord();
        itsBaseWindow->addMessageToQue(pmsg);
    }

    for(int i=0;i<28;i++)
    {
        ParameterMsg pmsg (Message::MCB,Message::AP,i);
        pmsg.getWord();
        itsBaseWindow->addMessageToQue(pmsg);
    }

    for(int i=201;i<=204;i++)
    {
        ParameterMsg pmsg (Message::MCB,Message::AP,i);
        pmsg.getWord();
        itsBaseWindow->addMessageToQue(pmsg);
    }
    for(int i=0;i<UIB_DP_CNT;i++)
    {
        ParameterMsg pmsg (Message::UIB,Message::DP,i);
        pmsg.getWord();
        itsBaseWindow->addMessageToQue(pmsg);
    }
}

void wbsdclone::clonercp(QString filename)
{
    _crtOpType =1;
    ui->progressBar->setValue(0);
    ui->progressBar_3->setValue(0);
    ui->btnd->setEnabled(false);
    ui->btnlang->setEnabled(false);
    ui->btnr->setEnabled(false);
    ui->btnlang_2->setEnabled(false);
    _crtRpcIndex =0;
    this->getrpc(_RcpIdLst.at(_crtRpcIndex++));
}

QString wbsdclone::getcrtfirewareVersion()
{
    return _mcbVersion;
}

void wbsdclone::on_menuBack_triggered()
{
    this->close();
}

void wbsdclone::on_pushButton_clicked()
{
    if (fmuclonewin==0)
        fmuclonewin = new FMU_CLONE(itsBaseWindow);
    fmuclonewin->setAttribute(Qt::WA_DeleteOnClose,true);
    fmuclonewin->show();
    this->hide();
    connect(fmuclonewin,SIGNAL(iclose()),this,SLOT(show()));
    connect(fmuclonewin,SIGNAL(destroyed()),this,SLOT(destroywin()));
}

void wbsdclone::destroywin()
{
    fmuclonewin=0;
}

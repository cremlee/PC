#include "wbsdversionwindow.h"
#include "ui_wbsdversionwindow.h"
#include "wbsdchildwindow.h"
#include "qstring.h"
#include "qdebug.h"
#include "application.h"
#include "wbsd_serial_port.h"
WBSDVersionWindow::WBSDVersionWindow(WBSDBaseWindow *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDVersionWindow)
{
    static const char* back[] = {
            QT_TRANSLATE_NOOP("back_version", "Back")
        };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_doser",back[0]), this);	
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));
    updateData();
}

WBSDVersionWindow::~WBSDVersionWindow()
{
    delete ui;
}

void WBSDVersionWindow::closeEvent(QCloseEvent *)
{
    emit iclose();
}

void WBSDVersionWindow::on_menuBack_triggered()
{
    this->close();
//    this->deleteLater();
}

void WBSDVersionWindow::connectionStatusChanged(int aStatus,StringMessage aMSG)
{
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDVersionWindow::updateSWVer(QString swVer)
{
    //ui->swMajor->setText("test");
    //ui->swMinor->setText(swVer);
}

void WBSDVersionWindow::updateData()
{
    qDebug() << "WBSDVersionWindow::updateData";
    //Load meta data
    //02;B7;A1;60;00;00;00;00;
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

void WBSDVersionWindow::gotMessage(Message aMsg)
{
    qDebug() << "WBSDVersionWindow::gotMessage";
    QString txt;
    unsigned int aVal;

    QByteArray data=aMsg.getData();
    Message::qtype atype=aMsg.getType();
    switch (atype){
        case (Message::REPLY_DB):
            switch ((unsigned char)aMsg.getBoard()){
                case (Message::MCB):
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DP:
                            switch(aMsg.getParameters().at(3)){
                                case (0):
                                    aVal=aMsg.getDataUInt();
                                    break;
                                default:
                                    break;
                            }
                    }
                    break;
                case (Message::UIB):
                    switch ((unsigned char)aMsg.getDataBaseType()){
                        case Message::DV:
                            switch (aMsg.getParameters().at(3)){
                                case (7):
                                    updateSWVer(QString(data));
                                    break;
                                default:
                                    break;
                            }
                    }
                    break;                
                default:
                    break;
            }
            break;
        case (Message::METADATA_ANSWER):
            {

                ui->metaWindow->clear();
                StringMessage sm(aMsg);
				ui->metaWindow->addItem(wbsd_SERIAL_PORT::instance()->blueBoxInfoLine1) ;
				ui->metaWindow->addItem(wbsd_SERIAL_PORT::instance()->blueBoxInfoLine2) ;
				ui->metaWindow->addItem(wbsd_SERIAL_PORT::instance()->blueBoxInfoLine3) ;
                QList <QString> al=sm.getList();
                qDebug()<<"meta: "<<al;
                //处理0和1的版本号
                if(al.count()<3) break;
                //QList <QString> v1 = al.at(1).split(".");
               if(al.at(1).endsWith(".1")
                       ||al.at(1).endsWith(".2")
                       ||al.at(1).endsWith(".3")
                       ||al.at(1).endsWith(".4")
                       ||al.at(1).endsWith(".5")
                       ||al.at(1).endsWith(".6")
                       ||al.at(1).endsWith(".7")
                       ||al.at(1).endsWith(".8")
                       ||al.at(1).endsWith(".9"))
               {
                   QString tmp =al.at(1);
                   int index1 = tmp.lastIndexOf(".");
                   tmp.insert(index1+1,QString("0"));
                   ui->metaWindow->addItem(tmp);
               }
               else
               {
                   ui->metaWindow->addItem(al.at(1));
               }

               if(al.at(2).endsWith(".1")
                       ||al.at(2).endsWith(".2")
                       ||al.at(2).endsWith(".3")
                       ||al.at(2).endsWith(".4")
                       ||al.at(2).endsWith(".5")
                       ||al.at(2).endsWith(".6")
                       ||al.at(2).endsWith(".7")
                       ||al.at(2).endsWith(".8")
                       ||al.at(2).endsWith(".9"))
               {
                   QString tmp =al.at(2);
                   int index1 = tmp.lastIndexOf(".");
                   tmp.insert(index1+1,QString("0"));
                   ui->metaWindow->addItem(tmp);
               }
               else
               {
                   ui->metaWindow->addItem(al.at(2));
               }

                for (int i=3;i<al.size();i++){
                    ui->metaWindow->addItem(al.at(i));
				}
            }
        break;
    }
}

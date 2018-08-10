#include "wbsderrorwindow.h"
#include "ui_wbsderrorwindow.h"
#include "wbsd_serial_port.h"
#include "qdebug.h"
#include "errormessage.h"
#include "application.h"
#include <QFile>
#include <QFileDialog>
#include <QList>
#include <QDateTime>
#include<QMessageBox>
WBSDErrorWindow::WBSDErrorWindow(WBSDBaseWindow  *parent) :
    WBSDChildWindow(parent),
    ui(new Ui::WBSDErrorWindow)
{
    static const char* back[] = {
        QT_TRANSLATE_NOOP("back_error", "Back")
    };

    ui->setupUi(this);

    menuBack = new QAction(Application::translate("back_error",back[0]), this);
		menuBack->setEnabled(true);

    ui->menubar->addAction(menuBack);
    connect( menuBack, SIGNAL(triggered()), this, SLOT(on_menuBack_triggered()));


	ui->listActiveErr->clear();
	ui->listHistoryErr->clear();
	ui->btnSaveErrors->setEnabled(false);
	myTimer=new QTimer(this);
	myTimer->setSingleShot(true);
	myTimer->setInterval(500);
	connect(myTimer, SIGNAL(timeout()),this,SLOT(updateData()));
	myTimer->start();
    //updateData();
    err_total=0;
    ui->centralwidget->setLayout(ui->verticalLayout);
    ui->progressBar->setValue(0);
}

void WBSDErrorWindow::connectionStatusChanged(int aStatus,StringMessage aMSG){
    itsBaseWindow->disconnectToMessages(this);
    if(aStatus<20)
    {
        this->close();
        this->deleteLater();
    }
}

void WBSDErrorWindow::updateData(){
	qDebug() << "updateData";
	itsBaseWindow->addMessageToQue (ErrorMessage(Message::ERR_NUMBER_ACTIVE,0));
}


WBSDErrorWindow::~WBSDErrorWindow()
{
	myTimer->stop();
    myTimer->deleteLater();
	delete ui;
}

void WBSDErrorWindow::on_menuBack_triggered()
{
    this->close();
    this->deleteLater();
}

void WBSDErrorWindow::updateActiveErrors(QString err)
{
    ui->listActiveErr->addItem(err);
}

void WBSDErrorWindow::clearActiveErrors()
{
    ui->listActiveErr->clear();
}

void WBSDErrorWindow::updateHistoryErrors(QString err)
{
    ui->listHistoryErr->addItem(err);
}

void WBSDErrorWindow::clearHistoryErrors()
{
    ui->listHistoryErr->clear();
}

void WBSDErrorWindow::on_btnSaveErrors_clicked()
{
	QDateTime dateTime = QDateTime::currentDateTime();
	QString dateTimeString = dateTime.toString();

    wbsd_SERIAL_PORT::itsInstance->setWincheck(true);
	QString filename=QFileDialog::getSaveFileName(this,"Save log",".//log","log (*.elog)");

	if (filename!=""){
		QFile f( filename );
		f.open( QIODevice::WriteOnly );
		QTextStream out(&f);
        for (int i=0;i<err_messages_hist.count();i++){
			QString aStr;
            ErrorMessage e=err_messages_hist.at(err_messages_hist.count()-i-1);
            if(e.toString().endsWith("[200:ALM_RESTART]"))
            {
                continue;
            }
            if (aStr!=e.toString()) {
                out << e.toString();
                out << "\r\n";
                aStr=e.toString();
            }
        }
		f.close();
        ui->progressBar->setValue(0);

        QMessageBox::StandardButton reply = QMessageBox::information(this,"Save File","Save Finished!!",QMessageBox::Ok);

    }
    wbsd_SERIAL_PORT::itsInstance->setWincheck(false);
}	



void WBSDErrorWindow::on_loadErrorButton_clicked()
{
    QString qs=QString("RJ DEBUG on_loadErrorButton_clicked");
	this->setCursor(Qt::WaitCursor);
    ui->progressBar->setValue(0);
    qDebug () << qs;
	myTimer->stop();
	itsBaseWindow->addMessageToQue (ErrorMessage(Message::ERR_TOTAL_ERRORS_IN_LOG,0));
}


void WBSDErrorWindow::gotMessage(Message aMsg)
{

    char aLevelState;
    unsigned int aVal;
    char aRfgState;
    QByteArray data=aMsg.getData();
    QString hex=QString(data.toHex());
	QString txt;
	Message::qtype atype=aMsg.getType();
    switch (atype){
    case (Message::REPLY_ERR_COUNT_ACT):
        txt=QString("Hex:[0x%1] Number of errors:[%2]").arg(hex).arg(aMsg.getDataInt(0,false,2));
        qDebug() << "Meddelande ut:" << aMsg.msg.toHex() << " " << txt;
        gotErrorCountMsg(ErrorMessage(aMsg));
        break;
    case (Message::REPLY_ERR_COUNT_HIST):
        txt=QString("Hex:[0x%1] Number of histoorical errors:[%2]").arg(hex).arg(aMsg.getDataInt(0,false,2));
        qDebug() << "Meddelande ut:" << aMsg.msg.toHex() << " " << txt;
        gotErrorCountMsg(ErrorMessage(aMsg));
        break;
    case (Message::REPLY_ERR):
        txt=QString("Hex:[0x%1]").arg(hex);
		qDebug() << "Error recived: " << txt << " To Str: " << ErrorMessage(aMsg).toString();
        gotErrorMsg(ErrorMessage(aMsg));
        break;
    case (Message::REPLY_ERR_ACT):
        txt=QString("Hex:[0x%1]").arg(hex);
		qDebug() << "Act Error recived: " << txt << " To Str: " << ErrorMessage(aMsg).toString();
        gotErrorMsg(ErrorMessage(aMsg));
        break;
    case (Message::REPLY_ERR_HIST):
        txt=QString("Hex:[0x%1]").arg(hex);
		qDebug() << "Hist Error recived: " << txt << " To Str: " << ErrorMessage(aMsg).toString();
        gotErrorMsg(ErrorMessage(aMsg));
        break;
    case (Message::ERROR_PACKET):
		myTimer->start();
        break;
    default:
        break;
    }
}

void WBSDErrorWindow::gotErrorCountMsg(ErrorMessage aMsg){
	myTimer->stop();
	err_query_number=0;
    if (aMsg.getType()==Message::REPLY_ERR_COUNT_ACT){
        err_act=aMsg.getDataInt(0,false,2);
        err_messages_act.clear();
		if (err_act==0){
			clearActiveErrors();
			myTimer->start();
			this->setCursor(Qt::ArrowCursor);
		} else {
			qDebug() << "Get Active Error 0 total "<< err_act;
			itsBaseWindow->addMessageToQue(ErrorMessage(Message::ERR_ACTIVE,0));
		}
        //itsBaseWindow->addMessageToQue(ErrorMessage(Message::ERR_TOTAL_ERRORS_IN_LOG,0));
        return;
    }
    if (aMsg.getType()==Message::REPLY_ERR_COUNT_HIST){
        err_total=aMsg.getDataInt(0,false,2);
        ui->progressBar->setMaximum(err_total);
        if(err_total>0){
            err_messages_hist.clear();
			qDebug() << "Get Historocal Error 0 total " << err_total;
            itsBaseWindow->addMessageToQue(ErrorMessage(Message::ERR_HISTORIC,0));
            return;
		} else {
			myTimer->start();
			this->setCursor(Qt::ArrowCursor);
		}
	}
}

void WBSDErrorWindow::gotErrorMsg(ErrorMessage aMsg){
    if (aMsg.getType()==Message::REPLY_ERR_ACT){
        err_messages_act.append(aMsg);
        if (err_messages_act.count()<err_act){
			qDebug() << "Get Active Error " << err_query_number+1;
            itsBaseWindow->addMessageToQue(ErrorMessage(Message::ERR_ACTIVE,++err_query_number));
            return;
        } else {
            clearActiveErrors();
            for (int i=0;i<err_messages_act.count();i++){
                ErrorMessage e=err_messages_act.at(i);
                updateActiveErrors(e.toString());
            }
			myTimer->start();
			this->setCursor(Qt::ArrowCursor);
           // ui->btnSaveErrors->setEnabled(true);
        }
        return;
    }
    if (aMsg.getType()==Message::REPLY_ERR_HIST){
        err_messages_hist.append(aMsg);
        ui->progressBar->setValue(err_messages_hist.count());
        if (err_messages_hist.count()<err_total){
			qDebug() << "Get historic Error " << err_query_number+1;
            itsBaseWindow->addMessageToQue(ErrorMessage(Message::ERR_HISTORIC,++err_query_number));
            return;
        }
        else
        {
            clearHistoryErrors();
            QString aStr="";
            for (int i=0;i<err_messages_hist.count();i++){
                ErrorMessage e=err_messages_hist.at(err_messages_hist.count()-i-1);
                if(e.toString().endsWith("[200:ALM_RESTART]"))
                {
                    continue;
                }
                if (aStr!=e.toString()) {
                    updateHistoryErrors(e.toString());
                    aStr=e.toString();
                }
            }
			err_total=0;
			myTimer->start();
			this->setCursor(Qt::ArrowCursor);
			ui->btnSaveErrors->setEnabled(true);
        }
    }
}

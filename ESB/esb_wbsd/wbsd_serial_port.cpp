#include "wbsd_serial_port.h"
#include "qextserialport.h"
#include <QByteArray>
#include <QIODevice>
#include <qdebug.h>
#include "message.h"
#include <iostream>
#include <parametermsg.h>
#include <message.h>
#include <exception>
#include <qlinkedlist.h>


wbsd_SERIAL_PORT* wbsd_SERIAL_PORT::itsInstance=NULL;
QString wbsd_SERIAL_PORT::comPort="COM27";
class QextSerialPort;
wbsd_SERIAL_PORT::wbsd_SERIAL_PORT(QObject *parent) :
    QObject(parent)
{
 //   std::cout <<     wbsd_SERIAL_PORT::comPort.data();
    _ischeck = false;
    port=NULL;
    sendCounter=0;
    pingTimer=new QTimer(this);
    pingTimeOutTimer=new QTimer(this);
    resendTimer=new QTimer(this);
     /*modify lee.li */
    connect(pingTimer,SIGNAL(timeout()),this,SLOT(pingTimeout()));
    connect(pingTimeOutTimer,SIGNAL(timeout()),this,SLOT(pingTimeoutError()));
    //connect(resendTimer,SIGNAL(timeout()),this,SLOT(resend()));

}
void wbsd_SERIAL_PORT::doMessageQue(){
    //QString qsss=QString("doMessageQue q-size %1").arg(queryQue.size());
    //qDebug () << qsss;

    //if (init)
    //    return;
//	if (sendCounter==1)
//		qDebug() << "doMessageQue send sc:" << sendCounter << " inBufferSize:" << theMessage.msg.size() <<" MSG:" << msg.getMsg().toHex() << " length:" << msg.getMsg().length();;

//	if (sendCounter>0){
//		qDebug() << "doMessageQue sc:>0";
//	}


    if (queryQue.length()>0){
//		this->setCursor(Qt::WaitCursor);
        Message msg=queryQue.first();// takeFirst();



        wbsd_SERIAL_PORT::instance()->send(msg);
    }
}

    void wbsd_SERIAL_PORT::disableTimers(){
        pingTimer->stop();
        pingTimeOutTimer->stop();
        resendTimer->stop();
    }

    void wbsd_SERIAL_PORT::enableTimers(){
        pingTimer->start(TIMER_RECEIVE);
        pingTimeOutTimer->start(TIMER_SEND);
    }


int wbsd_SERIAL_PORT::addMessageToQue(Message aMsg){
//	qDebug() << aMsg.getMsg().toHex();
    if ((aMsg.msg.size()==0))  {
    return 0;
    }

    if (aMsg.getMsg().toHex().startsWith("02b7a110028200000004")){
        if (queryQue.length()>0){
            pingTimer->stop();
            pingTimer->start(TIMER_RECEIVE);
            queryQue.append(aMsg);
            doMessageQue();
            return queryQue.count();
        }
    }


    queryQue.append(aMsg);
//	qDebug() << "add to que send que:" << " queryQue.length():" << queryQue.length() <<" MSG:" << aMsg.getMsg().toHex() << " length:" << aMsg.getMsg().length() << " sendCounter:" << sendCounter;
    if  ((queryQue.length()==1) && (sendCounter==0))
        doMessageQue();
    return queryQue.count();
}
void wbsd_SERIAL_PORT::sendNext(){
        if (sendBuffer.length()>64){
            pingTimer->stop();
            pingTimer->start(TIMER_RECEIVE);
//            resendTimer->stop();
//            resendTimer->start(TIMER_SEND);
            qDebug() << sendBuffer.left(64).toHex();
            port->write(sendBuffer.left(64));
            sendBuffer=sendBuffer.remove(0,64);
            QTimer::singleShot(20,this,SLOT(sendNext()));
            port->flush();
        } else {
            pingTimer->stop();
            pingTimer->start(TIMER_RECEIVE);
//            resendTimer->stop();
//            resendTimer->start(TIMER_SEND);
            qDebug() << sendBuffer.toHex();
            port->write(sendBuffer);
            port->flush();
        }
}

void wbsd_SERIAL_PORT::send(Message msg){
    qDebug() <<"buf-->[" + msg.msg.toHex() + "]";
    try {
        sendCounter++;
        theMessage.msg.clear();
        port->readAll();
        lastSentMessage=msg;
        //pingTimer->stop();
        //pingTimer->start(TIMER_RECEIVE);
//        resendTimer->stop();
//        resendTimer->start(TIMER_SEND);
        if(msg.getMsg().toHex().startsWith("02b7b00700aa55"))
        {
            pingTimer->stop();
            pingTimer->start(TIMER_RECEIVE);
        }
        qDebug() <<"len-->[" <<msg.getMsg().length() << "]";
        if (msg.getMsg().length()>64){
            sendBuffer.clear();
            sendBuffer.append((msg.getMsg()));
            qDebug() << sendBuffer.left(64).toHex();
            port->write(sendBuffer.left(64));
            sendBuffer=sendBuffer.remove(0,64);
            port->flush();
            QTimer::singleShot(20,this,SLOT(sendNext()));
        } else {
            port->write(msg.getMsg());
            port->flush();
        }
    } catch (std::exception e) {
        qDebug() << "Exception";
    }
}

bool wbsd_SERIAL_PORT::reconnect(QString aPort){
    qDebug() << "reconnect";
    if (port!=NULL){
        port->close();
        port->disconnect(this, SLOT(onDataAvailable()));
        port->deleteLater();
        conType=0;
        theConnectionStatus=CS_DISCONNECTED;
    }
    theComPort=aPort;
    port = new QextSerialPort(aPort);  //,QextSerialPort::Polling
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    port->setBaudRate(BAUD_BLUE);
    if (!(port->open(QIODevice::ReadWrite))){
        return false;
    }
    port->flush();
    port->readAll();
    connect(port, SIGNAL(readyRead()), this, SLOT(onDataAvailable()));
    conType=1;
    //pingTimeOutTimer->start(TIMER_SEND);

    ParameterMsg pMsg(Message::UIB,Message::AV,0);
    pMsg.getWord();
    addMessageToQue(pMsg);
    QByteArray ba(4,0);
    ba[0]=0x02;
    ba[1]=0xb7;
    ba[2]=0xa0;
    ba[3]=0x14;
    pingTimer->stop();
    pingTimer->start(TIMER_RECEIVE);

    theConnectionStatus=CS_CONNECTING;
    emit connectionStatusChanged(theConnectionStatus,QString("CONNECTING"));


    port->write(ba);
    port->flush();
//	port->readAll();
    return true;
}

bool wbsd_SERIAL_PORT::disconnect(){
    qDebug() << "wbsd_SERIAL_PORT disconnect";
    if (port!=NULL){
        port->close();
        port->disconnect(this, SLOT(onDataAvailable()));
        port->deleteLater();
        port = NULL;
        conType=0;

        theConnectionStatus=CS_DISCONNECTED;
        emit connectionStatusChanged(theConnectionStatus,QString("DISCONNECT"));

    }
    return true;
}
unsigned int wbsd_SERIAL_PORT::wbsd_Fletcher16( unsigned char * buffer, unsigned int count )
{
long sum1 = 0;
long sum2 = 0;
long i;

    for( i = 0; i < count; i++ ){
        sum1 = (sum1 + buffer[i]) % 255;
        sum2 = (sum2 + sum1) % 255;
    }
    return ((sum2 << 8) | sum1);
}

void wbsd_SERIAL_PORT::ping()
{
    QByteArray ba(10,0);
    ba[0]=0x02;
    ba[1]=0xb7;
    ba[2]=0xa1;
    ba[3]=0x10;
    ba[4]=0x02;
    ba[5]=0x80;
    ba[6]=0x00;
    ba[7]=0x00;
    ba[8]=0x00;
    ba[9]=0x00;
    port->write(ba);
    port->flush();
}
void wbsd_SERIAL_PORT::onDataAvailable()
{
    //qDebug() << "onDataAvailable" ;
    pingTimeOutTimer->stop();
    pingTimer->stop();
    pingTimer->start(TIMER_RECEIVE);
    QByteArray data = port->readAll();
    QByteArray data1=data;
    QString s=QString("<--[%1][%2]").arg(data1.length()).arg(QString(data1.toHex()));
    if (data1.at(0)==0x56){
        s.append(data1);
    }
    //qDebug() << s;
    if (sendCounter<1){
      return;
    }

//	if (data1.length()>20)
//		qDebug() << data;
//	else
    //qDebug() << "Data read" ;
    emit log(s);
    emit log( "<--[" + QString(data1.replace((char)0x00,"\\0").replace((char)0x0a,"\\r").replace((char)0xd,"\\n") + "]"));
    if  (conType==1){
        data=data.replace("\r\n","?");
        QList <QByteArray> lines=data.split('?');
        blueBoxInfoLine1="CSA: " + lines.at(0);
        blueBoxInfoLine2="CSA: " + lines.at(1);
        blueBoxInfoLine3="CSA: " + lines.at(2);
        sendCounter--;
        theConnectionStatus=CS_SERVICEDEVICE;
        emit connectionStatusChanged(theConnectionStatus,QString("CS_SERVICEDEVICE ANSWERED"));
        port->flush();
        port->readAll();
        port->disconnect(this, SLOT(onDataAvailable()));
        port->close();
        port->deleteLater();
        port = new QextSerialPort(theComPort);
        connect(port, SIGNAL(readyRead()), this, SLOT(onDataAvailable()));
        port->setBaudRate(BAUD_MAGIC);
        if (port->open(QIODevice::ReadWrite)){
            conType=2;
            //pingTimer->start(TIMER_RECEIVE);
            ParameterMsg pMsg(Message::UIB,Message::AV,0);
            pMsg.getWord();
            metadataBlueBox=data;
            if (queryQue.size()>0)
                queryQue.removeFirst();
            addMessageToQue(pMsg);
            //qDebug() << "RECONNECT!!!! message sc:" << sendCounter << " MSG:" << s;
            return;
        }
        else {
            conType=0;
            return;
        }
    }
    signed int ad=theMessage.append(data);

    if (ad==-1){
        qDebug() << "Error:" << s;
//        pingTimer->stop();
//        pingTimer->start(TIMER_RECEIVE);
        resend();
        return;
    }
    if (ad==-2){
        qDebug() << "!Skipping double!";
        return;
    }
    while (ad==1){
//		qDebug() << "got message sc:" << sendCounter << " MSG:" << theMessage.msg.toHex() << " querys left:" << queryQue.length()-1;
        sendCounter--;
        if (sendCounter<0)
                sendCounter=0;
//		qDebug() << "new sc:" << sendCounter ;
//		qDebug() << "got message sc:" << sendCounter << " MSG:" << theMessage.msg.toHex() << " querys left:" << queryQue.length()-1;
        Message aM=theMessage;
//		qDebug() << "Size " << queryQue.size() << " length: " << queryQue.length();
        if (queryQue.size()>0)
            queryQue.removeFirst();
//        pingTimer->stop();
//        pingTimer->start(TIMER_RECEIVE);
        //pingTimeOutTimer->stop();
        //pingTimeOutTimer->start(TIMER_SEND);
        if (sendCounter>0){
            sendCounter=0;
        }
        /**
            aM.getType();
            aM.getBoard();
            aM.getDataBaseType();
            aM.getParameters().at(4);
            **/
            if ((aM.getType()==Message::REPLY_DB) &&
                ((unsigned char)aM.getBoard()==Message::UIB) &&
                ((unsigned char)aM.getDataBaseType()==Message::AV) &&
                (aM.getParameters().at(4)==0x00)){
                //qDebug() << "PING";
            } else if ((aM.getType()==0xFFFF)) {
                qDebug() << "Error:" << s;
                qDebug() << "ERROR:" << aM.getMsg().toHex();
                if (sendCounter==0)
                    doMessageQue();
            } else {
                emit  gotMessage(aM);
            }
            theMessage.clear();
            data.clear();
            ad=theMessage.append(data);
            if (sendCounter==0)
                doMessageQue();
    }
    if (theConnectionStatus!=CS_LOCALESB){
        theConnectionStatus=CS_LOCALESB;
        emit connectionStatusChanged(theConnectionStatus,QString(data));
    }

}
void wbsd_SERIAL_PORT::resend(){
        sendCounter--;
        if (sendCounter<0)
                sendCounter=0;
        theMessage.clear();
        port->readAll();
        theMessage.clear();
//		qDebug() << "Resending" ;
        emit log("Resending");
        qDebug() << "ERROR!!!! message sc:" << sendCounter << " MSG:" << theMessage.msg.toHex() << " querys left:" << queryQue.length()-1;
        if (queryQue.size()>9){
            Message msg=queryQue.first();// takeFirst();
            wbsd_SERIAL_PORT::instance()->send(msg);
        } else {
            qDebug() << "ERROR!!!! LONG ANSWER message sc:" << sendCounter << " MSG:" << theMessage.msg.toHex() << " querys left:" << queryQue.length()-1;
        }
}

void wbsd_SERIAL_PORT::pingTimeout(){
        qDebug() << "pingTimeout -> "<<conType;
        ParameterMsg pMsg(Message::UIB,Message::AV,0);
        pMsg.getWord();
        if (conType>0){
            addMessageToQue(pMsg);
            if(!pingTimeOutTimer->isActive() &&!_ischeck)
            {
              pingTimeOutTimer->start(TIMER_SEND);
            }
        }
}


void wbsd_SERIAL_PORT::pingTimeoutError(){
    queryQue.clear();
    conType=0;
    qDebug() << "wbsd_SERIAL_PORT -> pingTimeoutError";
    theConnectionStatus=CS_DISCONNECTED;
    emit connectionStatusChanged(theConnectionStatus,QString("PING_TIMEOUT"));
    reconnect(theComPort);
    //emit connectionStatusChanged(theConnectionStatus,QString("DISCONNECT"));
}

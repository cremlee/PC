#ifndef WBSD_SERIAL_PORT_H
#define WBSD_SERIAL_PORT_H

#include <QObject>
#include <qextserialport.h>
#include "message.h"
#include "stringmessage.h"
#include <QTimer>

class wbsd_SERIAL_PORT : public QObject
{
public:

	Q_OBJECT
public:
    long TIMER_SEND =5000;
    long TIMER_RECEIVE =5000;
	static const long TIMER_RESEND =10*30000;

	enum  connectionStatus { 
			CS_DISCONNECTED=0,
			CS_CONNECTING=1, 
			CS_DELAYED_CONNECTION=5, 
			CS_SERVICEDEVICE=10, 
			CS_LOCALESB=20, 
			CS_CONNECTING_REMOTE=30,
			CS_CONNECTED_REMOTE=40
	};

signals:
    void gotMessage(Message msg);
    void log(QString msg);
	void connectionStatusChanged(int aStatus,StringMessage aMSG);
public:
	static wbsd_SERIAL_PORT* itsInstance;	
public:
    int conType;
    int sendCounter;
	QByteArray sendBuffer;

    QString blueBoxInfoLine1;
    QString blueBoxInfoLine2;
    QString blueBoxInfoLine3;

	int theConnectionStatus;
	QString theComPort;
	QString metadataBlueBox;
    QextSerialPort *port;
    static QString comPort;
    explicit wbsd_SERIAL_PORT(QObject *parent = 0);
	Message theMessage;
	Message lastSentMessage;
	QTimer *pingTimer;
	QTimer *pingTimeOutTimer;
	QTimer *resendTimer;

    static wbsd_SERIAL_PORT*  instance(){
		if (itsInstance==NULL){
			itsInstance=new wbsd_SERIAL_PORT();
		}
		return itsInstance;
	}
    static wbsd_SERIAL_PORT*  instance(QString aComPort){
        wbsd_SERIAL_PORT::comPort=aComPort;
        if (itsInstance==NULL){
            itsInstance=new wbsd_SERIAL_PORT();
        }
        return itsInstance;
    }
/*
	void setDBAnalog(board aBoard,dbtype aType,double aValue){};
	double getDBAnalog(board aBoard,dbtype aType)
		{ return 0;}
	void setDBDigital(board aBoard,dbtype aType,int aValue){};
	int getDBDigital(board aBoard,dbtype aType)
		{ return 0;}
*/    
protected:
    QList <Message> queryQue;
    void doMessageQue();

public:
	int addMessageToQue(Message aMsg);
	bool reconnect(QString aPort);
	bool disconnect();

	void disableTimers();
	void enableTimers();
    bool IswinChecked(){return _ischeck;}
    void setWincheck(bool a){_ischeck =a;}
    void setOt(int a){TIMER_RECEIVE=a;pingTimer->stop();pingTimer->start(TIMER_RECEIVE);}
private:
    unsigned int wbsd_Fletcher16( unsigned char * buffer, unsigned int count );
    void ping();
    bool _ischeck;
public slots:
	void sendNext();
	void send(Message msg);
    void onDataAvailable();
    void pingTimeout();
    void pingTimeoutError();
    void resend();
};

#endif // WBSD_SERIAL_PORT_H

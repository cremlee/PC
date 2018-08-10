#ifndef WBSDBASEWINDOW_H
#define WBSDBASEWINDOW_H

#include <QObject>
#include <QMainWindow>
#include "message.h"
#include "stringmessage.h"
#include "ui_mainwindow.h"

class WBSDBaseWindow : public QMainWindow
{
	Q_OBJECT

signals:
	void transferMessage(Message);
	void newConnectionStatus(int,StringMessage);
    void disconnect_close();
public:
    enum MachineUnit{UNIT_USA=0,
                     UNIT_Other=1};
	WBSDBaseWindow(QWidget *parent);
	~WBSDBaseWindow();
	int addMessageToQue(Message aMsg);
	void connectToMessages(QObject *aWindow);
	void disconnectToMessages(QObject *aWindow);
    virtual void showConnectionStatus(int connStatus) = 0;
	//virtual void emitTransferMessage(Message aMsg)=0;
    int  getUnitTmp(){return curtUnitTmp;}
    void setUnitTmp(int a){curtUnitTmp=a;}
	public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void setwincheck(bool a);
    void setOt(int a);
    void sendclose();
    void setMachineUnit(MachineUnit a){_crtMachineUnit =a;}
    MachineUnit& getMachineUnit(){return _crtMachineUnit;}
protected:
    bool init;
    bool event(QEvent *event);
private:
    int curtUnitTmp;
    MachineUnit _crtMachineUnit;

};

#endif // WBSDBASEWINDOW_H

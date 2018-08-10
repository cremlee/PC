#ifndef WBSDCHILDWINDOW_H
#define WBSDCHILDWINDOW_H

#include <QObject>
#include <QMainWindow>
#include "wbsdbasewindow.h"
#include "qtimer.h"

class WBSDChildWindow : public QMainWindow
{
	Q_OBJECT

public:
	WBSDChildWindow(WBSDBaseWindow *parent);
	~WBSDChildWindow();
public slots:	
	virtual void gotMessage(Message aMsg)=0;
    virtual void connectionStatusChanged(int aStatus,StringMessage aMSG)=0;

protected:
    WBSDBaseWindow *itsBaseWindow;
	QTimer *myTimer;
    bool event(QEvent *event);
public:
    bool isblockiclose;
};

#endif // WBSDCHILDWINDOW_H

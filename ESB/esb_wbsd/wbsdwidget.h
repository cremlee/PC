#ifndef WBSDBASEWIDGET_H
#define WBSDBASEWIDGET_H

#include <qwidget.h>
#include "wbsdbasewindow.h"

class WBSDWidget : public QWidget
{
	Q_OBJECT

public:
	WBSDWidget(WBSDBaseWindow *baseWindow, QWidget *parent);
	~WBSDWidget();

	public slots:
    virtual void connectionStatusChanged(int aStatus,StringMessage aMSG)=0;

protected:
	WBSDBaseWindow *itsBaseWindow;
	
};

#endif // WBSDBASEWIDGET_H

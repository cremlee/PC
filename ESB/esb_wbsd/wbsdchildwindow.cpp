#include "wbsdchildwindow.h"
#include "wbsdbasewindow.h"
//#include<QApplication>
#include<QDesktopWidget>
#include<QDebug>
WBSDChildWindow::WBSDChildWindow(WBSDBaseWindow *parent)
	: QMainWindow(parent)
{
	itsBaseWindow=parent;
	parent->connectToMessages(this);
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - 800)/2, (deskdop->height() - 600)/2);
    isblockiclose =false;
    /*this is for full screen*/
    //setWindowFlags(Qt::Dialog);
    //this->setMinimumSize(QSize(QApplication::desktop()->width(),QApplication::desktop()->height()));
    //this->showMaximized();

}

WBSDChildWindow::~WBSDChildWindow()
{
	itsBaseWindow->disconnectToMessages(this);
    this->deleteLater();
}



bool WBSDChildWindow::event(QEvent *event)
{
    if(event->type() == QEvent::NonClientAreaMouseButtonPress)
    {
     itsBaseWindow->setwincheck(true);
    }else if(event->type() == QEvent::NonClientAreaMouseButtonRelease)
    {
        itsBaseWindow->setwincheck(false);
    }
    QMainWindow::event(event);
}



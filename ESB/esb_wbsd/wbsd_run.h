#ifndef WBSD_RUN_H
#define WBSD_RUN_H

#include <QWidget>
#include"wbsdbasewindow.h"
#include"wbsdchildwindow.h"
#include "qextserialenumerator.h"
#include"wbsdwidget.h"
namespace Ui {
class wbsd_run;
}

class wbsd_run :  public WBSDChildWindow
{
    Q_OBJECT
private slots:
    void deviceDiscovered(const QextPortInfo &info);
    void deviceRemoved(const QextPortInfo &info);
    void updateConnectionStatus(int,StringMessage);
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
public:
    explicit wbsd_run(WBSDBaseWindow *parent =0);
    ~wbsd_run();
private:
    Ui::wbsd_run *ui;

};

#endif // WBSD_RUN_H

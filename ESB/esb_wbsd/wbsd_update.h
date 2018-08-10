#ifndef WBSD_UPDATE_H
#define WBSD_UPDATE_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include<QString>
#include"updatemessage.h"
#include<qdebug.h>
namespace Ui {
class wbsd_update;
}

class wbsd_update :  public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit wbsd_update(WBSDBaseWindow *parent = 0);
    ~wbsd_update();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
private slots:
    void on_menuBack_triggered();
    void on_btn_select_clicked();
    void on_cb_type_activated(int index);
    void on_btn_update_clicked();
private:
    Ui::wbsd_update *ui;
    int firmwaretype;
    QString updatepath;
    UpdateMessage*_UpdateMessage;
    int _crtpkgInddex;

};

#endif // WBSD_UPDATE_H

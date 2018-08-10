#ifndef FMU_UPDATE_H
#define FMU_UPDATE_H

#include"wbsdbasewindow.h"
#include"wbsdchildwindow.h"
#include"updatemessage.h"
namespace Ui {
class FMU_UPDATE;
}

class FMU_UPDATE : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit FMU_UPDATE(WBSDBaseWindow *parent = 0);
    ~FMU_UPDATE();
    void closeEvent(QCloseEvent* evt);
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
signals:
    void iclose();
private slots:
    void on_btn_openfile_clicked();
    void on_btn_ok_clicked();
    void getversion();
private:
    Ui::FMU_UPDATE *ui;
    int firmwaretype;
    QString updatepath;
    UpdateMessage*_UpdateMessage;
    int _crtpkgInddex;
};

#endif // FMU_UPDATE_H

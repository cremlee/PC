#ifndef WBSDINSTANTWINDOW_H
#define WBSDINSTANTWINDOW_H

#include <QMainWindow>
#include "parametermsg.h"
#include "wbsdchildwindow.h"
#include "wbsdcalibratecanisterwindow.h"
#include"databasehelper.h"
namespace Ui {
class WBSDInstantWindow;
}

class WBSDInstantWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDInstantWindow(WBSDBaseWindow *parent);
    ~WBSDInstantWindow();
    void closeEvent(QCloseEvent* evt);
    void adjustthecalibrationvalue();
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();

private slots:
    void on_instantWaterVal_pressed();
    void on_instantWaterVal_released();
    void on_instantMixer_pressed();
    void on_instantMixer_released();
    void on_instantCanister_pressed();
    void on_instantCanister_released();
    void on_instantFan_pressed();
    void on_instantFan_released();
    void on_menuBack_triggered();    
    void on_spIngVolGr_editingFinished();
    void on_btnCal50_clicked();
    void on_btnCal75_clicked();
    void on_btnCal100_clicked();
    void test();
    qreal GetCanisterMinValue(int canconf);
private:
    Ui::WBSDInstantWindow *ui;
    QAction *menuBack;
    WBSDCalibrateCanisterwindow *theCalWindow;
    QString stylelock;
    int _crtspeed;
    qreal Canister_Min_Value_50;
    qreal Canister_Min_Value_75;
    qreal Canister_Min_Value_100;
    qreal Canister_Min_Value;
    qreal Canister_Crt_Value_50;
    qreal Canister_Crt_Value_75;
    qreal Canister_Crt_Value_100;

};

#endif // WBSDINSTANTWINDOW_H

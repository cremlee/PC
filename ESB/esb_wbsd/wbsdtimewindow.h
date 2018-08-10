#ifndef WBSDTIMEWINDOW_H
#define WBSDTIMEWINDOW_H

#include <QMainWindow>
#include "wbsdcleaningwindow.h"
#include "wbsdecowindow.h"
#include "wbsdchildwindow.h"
#include "parametermsg.h"
#include "qdatetime.h"
#include "qtimer.h"
#include"wbsd_happyhour.h"
namespace Ui {
class WBSDTimeWindow;
}

class WBSDTimeWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDTimeWindow(WBSDBaseWindow *parent);
    ~WBSDTimeWindow();

public slots:
    void UpdataPaytest(bool flag);
    void on_ecoButton_clicked();
    void on_cleaningButton_clicked();
    void on_setDate_clicked();
    void on_setTime_clicked();
    void on_pbtn_hpyhour_clicked();
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();
    void on_timeFormat_activated(int index);
    void on_dtsEnable_activated(int index);
    void on_dtsStartMonth_activated(int index);
    void on_dtsStartWeek_activated(int index);
    void on_dtsStartDay_activated(int index);
    void on_dtsStartTime_activated(int index);
    void on_dtsEndMonth_activated(int index);
    void on_dtsEndWeek_activated(int index);
    void on_dtsEndDay_activated(int index);
    void on_dtsEndTime_activated(int index);
    void on_pbtn_skipclean_clicked();
private slots:
    void start_date_clock();
    void on_menuBack_triggered();
    void on_cleaningWindow_destroyd();
    
private:
    Ui::WBSDTimeWindow *ui;
    WBSDCleaningWindow *cleaningWindow;
    WBSDEcoWindow *ecoWindow;
    wbsdHappyHour *WbsdHappyHour;
    QAction *menuBack;
    unsigned int boardDp0BitField;  //Body unit DP block 0 bit data field
    unsigned int doorDp0BitField;   //Door unit DP block 0 bit data field
    void updateTimeFormat(int conf);
    void setDoorDP0Parameter(int value, int bitLen, int offset);
    void setBoardDP0Parameter(int value, int bitPos);
    void updateDTSLabels();
    void updateDTSOption(int conf);
    void updateDTSEnabled(int conf);
    void updateDTSStartMonth(int conf);
    void updateDTSStartWeek(int conf);
    void updateDTSStartTime(int conf);
    void updateDTSStartDay(int conf);
    void updateDTSEndMonth(int conf);
    void updateDTSEndWeek(int conf);
    void updateDTSEndDay(int conf);
    void updateDTSEndTime(int conf);


};

#endif // WBSDTIMEWINDOW_H

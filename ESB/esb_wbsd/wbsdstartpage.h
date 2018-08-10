#ifndef WBSDSTARTPAGE_H
#define WBSDSTARTPAGE_H

#include <QWidget>
#include "wbsdpaywindow.h"
#include "wbsderrorwindow.h"
#include "wbsdwaterwindow.h"
#include "wbsdcounterswindow.h"
#include "wbsdtestingwindow.h"
#include "wbsdgeneralwindow.h"
#include "wbsddrinkwindow.h"
#include "wbsddisplayoptwindow.h"
#include "wbsdtimewindow.h"
#include "wbsdwidget.h"
#include"wbsd_clone.h"
#include"wbsd_update.h"
namespace Ui {
class WBSDStartPage;
}

class WBSDStartPage : public WBSDWidget
{
    Q_OBJECT
    
public:
	explicit WBSDStartPage(WBSDBaseWindow *parent = 0);
    ~WBSDStartPage();

public:
    enum  showConnectionTutorialPic {
            CON_SHOW_OVERVIEW=0,    //Show overview pic
            CON_SHOW_CONNECT=1,     //Show connect machine
            CON_SHOW_NONE=2,        //Show start window
            CON_SHOW_INIT=99        //Init
    };

public slots:
    void on_errorButton_clicked();
    void on_waterButton_clicked();
    void on_countersButton_clicked();
    void on_generalButton_clicked();
    void on_drinkButton_clicked();
    void on_displayButton_clicked();
    void on_timeButton_clicked();
    void on_payButton_clicked();
    void on_testButton_clicked();
    void on_updateBtn_clicked();
	void gotMessage(Message aMsg);
	void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void on_btnlan_clicked();
    void updateinfo(int index);
private slots:
    void on_errorWindow_destroyd();
    void on_waterWindow_destroyd();
    void on_countersWindow_destroyd();
    void on_generalWindow_destroyd();
    void on_displayWindow_destroyd();
    void on_timeWindow_destroyd();
    void on_testingWindow_destroyd();
    void on_drinkWindow_destroyd();
    void on_payWindow_destroyd();
    void on_clone_destroyed();
    void on_update_destroyd();
public:
    WBSDPayWindow *payWindow;
    WBSDErrorWindow *errorWindow;
    WBSDWaterWindow *waterWindow;
    WBSDTestingWindow *testingWindow;
    WBSDCountersWindow *countersWindow;
    WBSDGeneralWindow *generalWindow;
    WBSDDisplayOptWindow *displayWindow;
    wbsdclone *_wbsdclone;//
    wbsd_update *_wbsd_update;
    void setLabelTexts();

signals:
    void send_updateGeneralSet();
    void send_updateDisplaySet();

private:
    Ui::WBSDStartPage *ui;
    WBSDDrinkWindow *drinkWindow;
    WBSDTimeWindow *timeWindow;
    void enableButtons(bool enable);

private:
    int currentState;
    bool IsBakMode;
};

#endif // WBSDSTARTPAGE_H

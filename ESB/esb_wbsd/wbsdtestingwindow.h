#ifndef WBSDTESTINGWINDOW_H
#define WBSDTESTINGWINDOW_H

#include <QMainWindow>
#include "wbsdoutletwindow.h"
#include "wbsdboilerwindow.h"
#include "wbsdcoolingwindow.h"
#include "wbsdcoolingwindow.h"
#include "wbsdmixerswindow.h"
#include "wbsddoserwindow.h"
#include "wbsddisplaywindow.h"
#include "wbsdversionwindow.h"
#include "wbsdchildwindow.h"
#include "wbsdpumpwindow.h"
#include "wbsdheaterwindow.h"
#include "wbsdinstantwindow.h"
#include"wbsd_paytest.h"
#include"wbsd_extern_tool.h"
namespace Ui {
class WBSDTestingWindow;
}

class WBSDTestingWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDTestingWindow(WBSDBaseWindow *parent);
    ~WBSDTestingWindow();
    void closeEvent(QCloseEvent *);
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();
    void heaterWindow_dest();
    void UpdataPaytest(bool flag);
private slots:
    void on_outletButton_clicked();
    void on_doserButton_clicked();
    void on_displayButton_clicked();
    void on_paymentButton_clicked();
    void on_versionsButton_clicked();
    void on_pumpButton_clicked();
    void on_heaterButton_clicked();
    void on_instantButton_clicked();
    void on_menuBack_triggered();

    void on_btn_ext_tst_clicked();

public:

private:
    Ui::WBSDTestingWindow *ui;
    QAction *menuBack;
    WBSDCoolingWindow *coolingWindow;
    WBSDOutletWindow *outletWindow;
    WBSDBoilerWindow *boilerWindow;
    WBSDMixersWindow *mixersWindow;
    WBSDDoserWindow *doserWindow;
    WBSDDisplayWindow *displayWindow;
    WBSDVersionWindow *versionWindow;
    WBSDPumpWindow *pumpWindow;
    WBSDHeaterWindow *heaterWindow;
    WBSDInstantWindow *instantWindow;
    WBSDpaytest *paytest;
    WBSD_EXTERN_TOOL *wbsdexternwin;
    int _LASTMODE;
    bool _getflag;
};

#endif // WBSDTESTINGWINDOW_H

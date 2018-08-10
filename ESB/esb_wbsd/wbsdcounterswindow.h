#ifndef WBSDCOUNTERSWINDOW_H
#define WBSDCOUNTERSWINDOW_H

#include <QMainWindow>
#include "WBSDButtoncounters.h"
#include "parametermsg.h"
#include "wbsdchildwindow.h"
#include "wbsdcounterstotal.h"
#include <QMessageBox>
#include"wbsdbtn78cnt.h"
namespace Ui {
class WBSDCountersWindow;
}

class WBSDCountersWindow : public WBSDChildWindow
{
    Q_OBJECT

private slots:
    void on_menuBack_triggered();
    void on_buttonTotal_clicked();
    void on_ResetCounters_clicked();
    void destroywin(int i);
    
public:
	explicit WBSDCountersWindow(WBSDBaseWindow *parent = 0);
    ~WBSDCountersWindow();

public slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
	void gotMessage(Message aMsg);
	void connectionStatusChanged(int aStatus,StringMessage aMSG);

signals:
    void set_CountersButton1();
    
private:
    Ui::WBSDCountersWindow *ui;
    QAction *menuBack;
    WBSDButtonCounters *button1CountersWndw;
    WBSDButtonCounters *button2CountersWndw;
    WBSDButtonCounters *button3CountersWndw;
    WBSDButtonCounters *button4CountersWndw;
    WBSDButtonCounters *button5CountersWndw;
    WBSDButtonCounters *button6CountersWndw;
    WBSDbtn78cnt *button7CountersWndw;
    WBSDbtn78cnt *button8CountersWndw;
    WBSDCountersTotal  *buttonTotalWndw;
    QMessageBox msgBox;
    void resetCounters();
    void stopReset();

};

#endif // WBSDCOUNTERSWINDOW_H

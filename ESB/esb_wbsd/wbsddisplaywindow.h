#ifndef WBSDDISPLAYWINDOW_H
#define WBSDDISPLAYWINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "parametermsg.h"
#include "wbsdbuttontestwindow.h"

namespace Ui {
class WBSDDisplayWindow;
}

class WBSDDisplayWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDDisplayWindow(WBSDBaseWindow *parent);
    ~WBSDDisplayWindow();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();
    void testwclose();
    void UpdateLCDInfo(uint a);
private slots:
    void on_lcdSegment_clicked();
    void on_buttonTest_clicked();
    void on_menuBack_triggered();
    void on_soundTest_activated(int index);
    void on_pbrst_clicked();
    void on_cb_LCD_activated(int index);
    void on_cb_Ani_activated(int index);


private:
    Ui::WBSDDisplayWindow *ui;
    WBSDButtonTestWindow *buttonTestWindow;
    QAction *menuBack;
};

#endif // WBSDDISPLAYWINDOW_H

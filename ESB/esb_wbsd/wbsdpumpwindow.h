#ifndef WBSDPUMPWINDOW_H
#define WBSDPUMPWINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "parametermsg.h"
#include "qdebug.h"

namespace Ui {
class WBSDPumpWindow;
}

class WBSDPumpWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDPumpWindow(WBSDBaseWindow *parent);
    ~WBSDPumpWindow();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();

private slots:
    void on_waterPump_pressed();
    void on_waterPump_released();
    void on_rbibPump_pressed();
    void on_rbibPump_released();
    void on_lbibPump_pressed();
    void on_lbibPump_released();
    void on_menuBack_triggered();
void on_btn_setpump_clicked();
private:
    Ui::WBSDPumpWindow *ui;
    QAction *menuBack;
};

#endif // WBSDPUMPWINDOW_H

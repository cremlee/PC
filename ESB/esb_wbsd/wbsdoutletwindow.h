#ifndef WBSDOUTLETWINDOW_H
#define WBSDOUTLETWINDOW_H

#include <QMainWindow>
#include "parametermsg.h"
#include "wbsdchildwindow.h"

namespace Ui {
class WBSDOutletWindow;
}

class WBSDOutletWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDOutletWindow(WBSDBaseWindow *parent);
    ~WBSDOutletWindow();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();

private slots:
    void on_hotWaterValve_pressed();
    void on_hotWaterValve_released();
    void on_coldWaterValve_pressed();
    void on_coldWaterValve_released();
    void on_normalOpenValve_pressed();
    void on_normalOpenValve_released();
    void on_inletValve_pressed();
    void on_inletValve_released();
    void on_lbibValve_pressed();
    void on_lbibValve_released();
    void on_lbibAirValve_pressed();
    void on_lbibAirValve_released();
    void on_rbibValve_pressed();
    void on_rbibValve_released();
    void on_rbibAirValve_pressed();
    void on_rbibAirValve_released();
    void on_menuBack_triggered();

signals:
    void send_hotWaterValve_clicked(ParameterMsg query1, ParameterMsg query2, int index1, int value1, int index2, int value2, BOOL_TYPE released);
    
private:
    Ui::WBSDOutletWindow *ui;
    QAction *menuBack;
};

#endif // WBSDOUTLETWINDOW_H

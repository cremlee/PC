#ifndef WBSDHEATERWINDOW_H
#define WBSDHEATERWINDOW_H

#include <QMainWindow>
#include "parametermsg.h"
#include "wbsdchildwindow.h"

namespace Ui {
class WBSDHeaterWindow;
}

class WBSDHeaterWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDHeaterWindow(WBSDBaseWindow *parent);
    ~WBSDHeaterWindow();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();

private slots:
    void on_heaterRelay_pressed();
    void on_heaterRelay_released();
    void on_cooler_pressed();
    void on_cooler_released();
    void on_menuBack_triggered();
    
private:
    Ui::WBSDHeaterWindow *ui;
    QAction *menuBack;
    QTimer *tmr;
    int kellyvalue1;
    float kellyvalue2;
};

#endif // WBSDHEATERWINDOW_H

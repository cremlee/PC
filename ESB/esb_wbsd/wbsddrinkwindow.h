#ifndef WBSDDRINKWINDOW_H
#define WBSDDRINKWINDOW_H

#include <QMainWindow>
#include "wbsddrink_window.h"
#include "wbsdchildwindow.h"
#include "parametermsg.h"

namespace Ui {
class WBSDDrinkWindow;
}

class WBSDDrinkWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDDrinkWindow(WBSDBaseWindow *parent);
    ~WBSDDrinkWindow();
    void closeEvent(QCloseEvent *);
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();
    void setNorecip(int itsDb,int itsHiLo);

signals:
    void iclose();

private slots:
    void on_menuBack_triggered();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_crtDrink_Window_destroyed();
private:
    Ui::WBSDDrinkWindow *ui;
    QAction *menuBack;
    WBSDDrink_Window *button1DrinkWndw;
    WBSDDrink_Window *button2DrinkWndw;
    WBSDDrink_Window *button3DrinkWndw;
    WBSDDrink_Window *button4DrinkWndw;
    WBSDDrink_Window *button5DrinkWndw;
    WBSDDrink_Window *button6DrinkWndw;
    WBSDDrink_Window *button7DrinkWndw;
    WBSDDrink_Window *button8DrinkWndw;
    WBSDDrink_Window *crtDrink_Window;
    int  valLeftBIB, valRightBIB, valInstant,fmuon;
    QList<int> crtrcplst;

};

#endif // WBSDDRINKWINDOW_H

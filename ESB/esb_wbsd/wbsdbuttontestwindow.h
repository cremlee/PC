#ifndef WBSDBUTTONTESTWINDOW_H
#define WBSDBUTTONTESTWINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "parametermsg.h"

namespace Ui {
class WBSDButtonTestWindow;
}

class WBSDButtonTestWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDButtonTestWindow(WBSDBaseWindow *parent);
    ~WBSDButtonTestWindow();

    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();

private slots:
    void on_button1_pressed();
    void on_button1_released();
    void on_button2_pressed();
    void on_button2_released();
    void on_button3_pressed();
    void on_button3_released();
    void on_menuBack_triggered();

private:
    Ui::WBSDButtonTestWindow *ui;
    QAction *menuBack;
    void updateButtonStatus(unsigned int conf);
    void updateButton();
};

#endif // WBSDBUTTONTESTWINDOW_H

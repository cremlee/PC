#ifndef WBSDDOSERWINDOW_H
#define WBSDDOSERWINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "parametermsg.h"

namespace Ui {
class WBSDDoserWindow;
}

class WBSDDoserWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDDoserWindow(WBSDBaseWindow *parent);
    ~WBSDDoserWindow();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();

private slots:
    void on_leftB2Test_clicked();
    void on_leftB2Test_released();
    void on_rightB2Test_clicked();
    void on_rightB2Test_released();
    void on_leftB2SlowTest_clicked();
    void on_leftB2SlowTest_released();
    void on_rightB2SlowTest_clicked();
    void on_rightB2SlowTest_released();
    void on_menuBack_triggered();

private:
    Ui::WBSDDoserWindow *ui;
    QAction *menuBack;
};

#endif // WBSDDOSERWINDOW_H

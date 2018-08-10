#ifndef WBSD_PAYTEST_H
#define WBSD_PAYTEST_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
namespace Ui {
class WBSDpaytest;
}

class WBSDpaytest : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit WBSDpaytest(WBSDBaseWindow *parent);
    ~WBSDpaytest();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    //void updateData();
    void on_btn_test_clicked();
    void updatetestresult(QString a);
private slots:
    void on_menuBack_triggered();
private:
    Ui::WBSDpaytest *ui;
};

#endif // WBSD_PAYTEST_H

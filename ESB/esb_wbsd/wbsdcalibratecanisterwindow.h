#ifndef WBSDCALIBRATECANISTERWINDOW_H
#define WBSDCALIBRATECANISTERWINDOW_H

#include <QMainWindow>
#include "WBSDChildWindow.h"

namespace Ui {
class WBSDCalibrateCanisterwindow;
}

class WBSDCalibrateCanisterwindow : public WBSDChildWindow
{
    Q_OBJECT

    
public:
    explicit WBSDCalibrateCanisterwindow(int aSpeed,qreal a,WBSDBaseWindow *parent);
    ~WBSDCalibrateCanisterwindow();
	void reload(int aSpeed);
    bool isworked(){return _isdone;}
private slots:
    void on_pushButton_clicked();
    void on_doubleSpinBox_editingFinished();
    void myvalue(double a);
//    void on_menuBack_triggered();
    void on_btn_close_clicked();
private:
    Ui::WBSDCalibrateCanisterwindow *ui;
    QAction *menuBack;
	int theSpeed;
	int lastStatus;
    bool _isdone;
    qreal _minValue;
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();
    void closeEvent(QCloseEvent *);
};

#endif // WBSDCALIBRATECANISTERWINDOW_H

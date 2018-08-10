#ifndef WBSD_HAPPYHOUR_H
#define WBSD_HAPPYHOUR_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include<QTimeEdit>
namespace Ui {
class wbsdHappyHour;
}

class wbsdHappyHour : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit wbsdHappyHour(WBSDBaseWindow *parent = 0);
    ~wbsdHappyHour();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void SetDPHappyHourTm(int block, QTimeEdit *a);
    void DPHappyHourUp(QTimeEdit *a ,quint16 val);
    void DPHappyHourSetFlag(quint16 val);
    void updateData();
private slots:
    void on_menuBack_triggered();
    void on_mode1_tes_editingFinished();
    void on_mode1_tee_editingFinished();
    void on_mode2_tes_editingFinished();
    void on_mod2_tee_editingFinished();
    void on_mod3_tes_editingFinished();
    void on_mod3_tee_editingFinished();
    void upSetUi();
private:
    Ui::wbsdHappyHour *ui;
    QAction *menuBack;
};

#endif // WBSD_HAPPYHOUR_H

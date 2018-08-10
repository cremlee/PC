#ifndef FMU_CALIBRATION_H
#define FMU_CALIBRATION_H

#include"wbsdchildwindow.h"
#include<QDoubleSpinBox>
namespace Ui {
class FMU_Calibration;
}

class FMU_Calibration : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit FMU_Calibration(WBSDBaseWindow *parent = 0);
    ~FMU_Calibration();
    void closeEvent(QCloseEvent* evt);
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateCalSpdValue(QDoubleSpinBox *lb,int value);
signals:
    void iclose();
private slots:
    void on_btn_cal_spd_1_clicked();

    void on_btn_cal_spd_2_clicked();

    void on_btn_cal_spd_3_clicked();

    void on_btn_cal_30_clicked();

    void on_btn_cal_50_clicked();

    void on_btn_cal_80_clicked();
    void finishcal();

    void on_btn_cal_100_clicked();

    void on_btn_cal_spd_4_clicked();

    void enablesp1();
    void enablesp2();
    void enablesp3();
    void on_menuBack_triggered();
private:
    Ui::FMU_Calibration *ui;
    int currenttype;
    QTimer *mtimer1;
    QAction *menuBack;
};

#endif // FMU_CALIBRATION_H

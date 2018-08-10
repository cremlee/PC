#ifndef FMU_SETTING_H
#define FMU_SETTING_H
#include"fmu_parameter.h"
#include "wbsdchildwindow.h"
#include"fmu_test.h"
#include"fmu_error.h"
#include"fmu_calibration.h"
#include"fmu_update.h"
#include "fmu_clone.h"
#include"fmu_message.h"
namespace Ui {
class FMU_SETTING;
}

class FMU_SETTING : public WBSDChildWindow
{
    Q_OBJECT
signals:
    void iclose();
public:
    explicit FMU_SETTING(WBSDBaseWindow *parent);
    ~FMU_SETTING();
    void closeEvent(QCloseEvent* evt);
public slots:
     void gotMessage(Message aMsg);
     void connectionStatusChanged(int aStatus,StringMessage aMSG);
private slots:
     void on_btn_param_clicked();
     void on_btn_test_clicked();
     void on_btn_error_clicked();
     void on_btn_cal_clicked();
     void on_btn_up_clicked();
     void destroywin();
     void on_cb_element_switch_activated(int index);
    void update_cb_element_switch(int conf);
    void updateHardness(int value);

     void on_btn_clone_clicked();
void on_menuBack_triggered();
void on_pbtn_rest_clicked();

void on_cb_hardness_activated(int index);

private:
    Ui::FMU_SETTING *ui;
    FMU_PARAMETER *paramsetwin;
    fmu_test *fmutestwin;
    fmu_error *fmuerrorwin;
    FMU_Calibration *fmucalibrationwin;
    FMU_UPDATE *fmuupwin;
    FMU_CLONE *fmuclonewin;
    QAction *menuBack;

};

#endif // FMU_SETTING_H

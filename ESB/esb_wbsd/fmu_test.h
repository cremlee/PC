#ifndef FMU_TEST_H
#define FMU_TEST_H
#include"wbsdchildwindow.h"
#include <QMainWindow>

namespace Ui {
class fmu_test;
}

class fmu_test :  public WBSDChildWindow
{
    Q_OBJECT


//    0x01	activate gear pump
//    0x02	activate air-valve
//    0x03	activate water valve
//    0x04	activate milk valve
//    0x05	activate cleaning valve
//    0x06	activate water flush valve
//    0x07	activate fan hydraulic box
//    0x08	activate fan condensor
//    0x09	activate flow meter
//    0x0A	activate FTH-element-1
//    0x0B	activate FTH-element-2
//    0x0C	activate compressor
public:
enum  test_type {
        PUMP=0x01,
        VALVE_AIR=0x02,
        VALVE_INLET=0x03,
        VALVE_MILK=0x04,
        VALVE_CLEAN=0x05,
        VALVE_FLUSH=0x06,
        FAN_BOX =0x07,
        FAN_CONDENSOR=0x08,
        FLOW_METER=0x09,
        FTH_ELEMENT_1=0x0A,
        FTH_ELEMENT_2=0x0B,
        COMPRESSOR=0x0C,
        VERSION_UC=0xA1,
        VERSION_FTH=0xA2,
        CAL_30_RUN =0xB1,
        CAL_50_RUN =0xB2,
        CAL_80_RUN =0xB3,
        CAL_30_SET =0xC1,
        CAL_50_SET =0xC2,
        CAL_80_SET =0xC3,
        ERROR_H =0xE1,
        ERROR_L =0xE2,
};

public:
    explicit fmu_test(WBSDBaseWindow *parent = 0);
    ~fmu_test();
    void closeEvent(QCloseEvent* evt);
private:
    void updateinlettemperature(int value);
    void updateoutlettemperature(int value);
    void updatecondtivesensor(int value);
    void updatecapactivesensor(int value);
public slots:
     void gotMessage(Message aMsg);
     void connectionStatusChanged(int aStatus,StringMessage aMSG);
private slots:
      //--------valve---------
     void on_btn_flush_clicked();
     void on_btn_inlet_clicked();
     void on_btn_milk_clicked();
     void on_btn_clean_clicked();
     void on_btn_air_clicked();
     //--------pump---------
      void on_btn_pump_clicked();
     //--------fan---------
      void on_btn_fan_box_clicked();
      void on_btn_fan_condensor_clicked();
     //-------heater---------
      void on_btn_relay_1_clicked();
      void on_btn_relay_2_clicked();
      //-------flowmeter-----------
       void on_btn_flowmeter_clicked();
      //-------compressor----------
      void on_btn_compressor_clicked();
     //modify by lee test function
     void valvetest(test_type type);
     void updateinfo();
     void showtestresult(int id,int result);
     void on_tabWidget_currentChanged(int index);
     void on_menuBack_triggered();
signals:
    void iclose();

private:
    QAction *menuBack;
private:
    Ui::fmu_test *ui;
    QTimer *myTimer;
    int mConductivevalue;
    int mplusevalue;
};

#endif // FMU_TEST_H

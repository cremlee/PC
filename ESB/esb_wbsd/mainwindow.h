#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "message.h"
#include "qextserialenumerator.h"
#include "errormessage.h"
#include "qtimer.h"
#include "stringmessage.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
	void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void log(QString aString);
    void on_btnResetLog_clicked();
    void on_pushButton_clicked();
    void on_btnChkErrors_clicked();
	void on_btnGetKayMappings_clicked();
	void on_btnSetTime_clicked();
    void gotMessage(Message aMsg);
    void connected(QString aMsg);
	void deviceDiscovered(const QextPortInfo &info);
    void deviceRemoved(const QextPortInfo &info);
	void onTimerTemp();

    void on_btnRestart_clicked();

    void on_btnReset_clicked();

    void on_cboConf_activated(int index);

    void on_cboRFID_activated(int index);

    void on_btnTest_clicked();
	void on_btnLoadMetadata_clicked(); //02;B7;A1;60;00;00;00;00

    void on_optModeNormal_clicked(bool checked);
    void on_optModeNurse_clicked(bool checked);

    void on_optModeCleaner_clicked(bool checked);
    void on_optModeOperator_clicked(bool checked);

    void on_optModeService_clicked(bool checked);

    void on_optModeManufacturer_clicked(bool checked);
    void on_optModeWBSD_clicked(bool checked);


    void on_btn1_clicked();


    void on_btnTestNOV_pressed();
    void on_btnTestNOV_released();

    void on_btnTestWaterPump_pressed();
    void on_btnTestWaterPump_released();
    
	void on_btnTestHeater_pressed();
    void on_btnTestHeater_released();

    void on_btnTestAirpump_pressed();
    void on_btnTestAirpump_released();

	void on_btnTestInletValve_pressed();
	void on_btnTestInletValve_released();

	void on_btnTestLBIBValve_pressed();
	void on_btnTestLBIBValve_released();

	void on_btnTestLBIBAirValve_pressed();
	void on_btnTestLBIBAirValve_released();

	void on_btnTestRBIBValve_pressed();
	void on_btnTestRBIBValve_released();

	void on_btnTestRBIBAirValve_pressed();
	void on_btnTestRBIBAirValve_released();

	void on_btnTestInstantValve_pressed();
	void on_btnTestInstantValve_released();

	void on_btnTestInstantMixer_pressed();
	void on_btnTestInstantMixer_released();

	void on_btnTestInstantCanister_pressed();
	void on_btnTestInstantCanister_released();

	void on_btnTestHowWaterValve_pressed();
	void on_btnTestHowWaterValve_released();

	void on_btnTestColdWaterValve_pressed();
	void on_btnTestColdWaterValve_released();

	void on_btnTestInstantFan_pressed();
	void on_btnTestInstantFan_released();

	void on_btnTestLB2_pressed();
	void on_btnTestLB2_released();

	void on_btnTestRB2_pressed();
	void on_btnTestRB2_released();

	void on_btnTestCooler_pressed();
	void on_btnTestCooler_released();

	void setCboConf(unsigned int aVal);
	void setCboRfid(unsigned int aVal);



private:
	QTimer *timerTemp;
	bool init;
    Ui::MainWindow *ui;
	QextSerialEnumerator *qe;
	int err_act;
	int err_total;
	short err_query_type;
	short err_query_number;
	QList <ErrorMessage> err_messages_act;
	QList <ErrorMessage> err_messages_hist;
	QList <Message> queryQue;
    void gotErrorCountMsg(ErrorMessage aMsg);
    void gotErrorMsg(ErrorMessage aMsg);
    void doMessageQue();
};

#endif // MAINWINDOW_H

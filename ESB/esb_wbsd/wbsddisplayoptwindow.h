#ifndef WBSDDISPLAYOPTWINDOW_H
#define WBSDDISPLAYOPTWINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "parametermsg.h"
#include <QLinkedList>

namespace Ui {
class WBSDDisplayOptWindow;
}

class WBSDDisplayOptWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDDisplayOptWindow(WBSDBaseWindow *parent);
    ~WBSDDisplayOptWindow();
    void configSettingsIndex();

public slots:
    void on_tempUnit_activated(int index);
    void on_showNumMode_activated(int index);
    void on_showLogo_activated(int index);
    void on_showOpTel_activated(int index);
    void on_showServTel_activated(int index);
    void on_strMode_activated(int index);
    void on_volMode_activated(int index);

    void on_cboShowWelcome_activated(int index);
    void on_cboOperShowCleaning_activated(int index);

    void on_cboOperShowCounters_activated(int index);
    void on_cboOperShowCountersRst_activated(int index);
    void on_cboOperShowDate_activated(int index);
    void on_cboOperShowVol_activated(int index);
    void on_cboOperShowStrength_activated(int index);   
    void on_cboOperShowHpy_activated(int index);


    void on_cbwf_activated(int index);
    void on_cbdescal_activated(int index);

    void on_cboOperShowECO_activated(int index);
    void on_cboOperShowPhone_activated(int index);
    void on_cboOperShowPay_activated(int index);
    void on_cboOperShowRFID_activated(int index);
	void on_btnUpload_clicked();

    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);

    void updateVolModeSelectItem(int instantconf);
    void UpdateLCDInfo(uint a);
    void on_cb_Ani_activated(int index);
    void on_cobcupsize_activated(int index);
private slots:
    void on_menuBack_triggered();
    void on_showHotW_activated(int index);
    void on_ledDIM_activated(int index);

signals:
    void send_DisplayOptDP0_clicked(int value, int pos);
    void send_DisplayOptDoorDP0_clicked(int value, int bitlen, int offset);
    
private:
    Ui::WBSDDisplayOptWindow *ui;
    QAction *menuBack;
	QLinkedList <QByteArray> theStack;
	QByteArray *lngbuffer;
	void sendLanguageFile();
	QByteArray  getlngLine();

    unsigned int boardDp0BitField; //Body unit DP block 0 bit data field
    unsigned int doorDp0BitField;   //Door unit DP block 0 bit data field
    unsigned int doorDp18BitField;   //Door unit DP block 16 bit data field
    void updateData();
    void updateTempUnit(int conf);
    void updateShowLogo(int conf);
    void updateshowNumMode(int conf);
    void updateshowOpTel(int conf);
    void updateshowServTel(int conf);
    void updateStrMode(int conf);
    void updateVolMode(int conf);
    void updatewf(int conf);
    void updatedc(int conf);
    void updateHpy(int conf);
    void updateRstbtn(int conf);
    void setDoorDP0Parameter(int value, int bitLen, int offset);
    void setDoorDP4Parameter(int value, int bitLen, int offset);
    void setDoorDP8Parameter(int value, int bitLen, int offset);
    void setDoorDP18Parameter(int value, int bitLen, int offset);
    void setBodyDP0Parameter(int value, int bitPos);
//DP16
    void updateHotWarn(int conf);
    void updateLedDIM(int conf);
	void updateStartMessage(int conf);
	void updateOptShowClean(int conf);
//DP8
void updateOptShowECO(int conf);
void updateOptShowPHONE(int conf);
void updateOptShowPAY(int conf);
void updateOptShowRFID(int conf);
//DP4
void updateOptShowCounters(int conf);
void updateOptShowVolume(int conf);
void updateOptShowStrength(int conf);
void updateOptShowDate(int conf);

};

#endif // WBSDDISPLAYOPTWINDOW_H

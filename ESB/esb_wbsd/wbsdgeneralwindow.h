#ifndef WBSDGENERALWINDOW_H
#define WBSDGENERALWINDOW_H

#include <QMainWindow>
#include "parametermsg.h"
#include "wbsdchildwindow.h"
 #include <QRegExpValidator>
#include<wbsdinstantwindow.h>
#include"fmu_setting.h"
namespace Ui {
class WBSDGeneralWindow;
}

class WBSDGeneralWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDGeneralWindow(WBSDBaseWindow *parent);
    ~WBSDGeneralWindow();
    void closeEvent(QCloseEvent *);
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);

private slots:
    void on_menuBack_triggered();
    void on_leftBIB_activated(int index);
    void on_rightBIB_activated(int index);
    void on_instantCoffee_activated(int index);
    void on_paymentOpt_activated(int index);
    void on_phoneOper_editingFinished();
    void on_phoneServ_editingFinished();
    void on_switchOver_activated(int index);
    void on_cbenablepay_activated(int index);
    void on_cb_payDispenMode_activated(int index);
    void on_instantFan_activated(int index);
    void on_deairTimer_activated(int index);
    void on_btn_instant_clicked();
    void on_btn_fmu_clicked();
    void on_cb_fmuswitch_activated(int index);


    void test();
    void destroywin();

signals:
    void send_GeneralSettings_clicked(ParameterMsg query1, int blockNo);
    void send_GeneralSettingsDP0_clicked(int value, int pos);
    void iclose();
private:
    Ui::WBSDGeneralWindow *ui;
    QAction *menuBack;
    unsigned int boardDp0BitField; //Body unit DP block 0 bit data field
    unsigned int boardDp25BitField; //Body unit DP block 25 bit data field
    int MAXLEN_PHONE;
    QString operatorNumber; //Operator number in display
    QString serviceNumber;  //Service number in display
    QRegExp regExpPhone; //Regular expression for phone numbers.
    QRegExpValidator *validatorPhone; // Validator for phone numbers
    void updateData();
    void updateLeftBIB(unsigned int conf);
    void updateRightBIB(unsigned int conf);
    void updateInstantCoffee(unsigned int conf);
    void updatePaymentOpt(unsigned int conf);
    void updatePhoneOperator(unsigned int digits, unsigned int block);
    void updatePhoneService(unsigned int digits, unsigned int block);
    void configSettingsIndex();
    void setBodyDP0Parameter(int value, int bitPos);
    void setBodyDP25Parameter(int value, int bitLen, int offset);
    void updateSwitchOver(unsigned int conf);
    void updateInstantFan(unsigned int conf);
    void updateDeairTimer(unsigned int conf);
    void updatepayenable(unsigned int conf);
    void updatedispenMode(unsigned int conf);
    void updatefmuswitch(unsigned int conf);
    QString CheckButtonIsOk(QList<int> a);
    int _crtCleanMode;
    int _lastlftIndex;
    int _lastrgtIndex;
    int _lastInstantIndex;
    int _lastfmuindex;
    WBSDInstantWindow *instantWindow;
    FMU_SETTING *fmu_settingwin;
    int RcpID_Btn1;
    int RcpID_Btn2;
    int RcpID_Btn3;
    int RcpID_Btn4;
    int RcpID_Btn5;
    int RcpID_Btn6;
};

#endif // WBSDGENERALWINDOW_H

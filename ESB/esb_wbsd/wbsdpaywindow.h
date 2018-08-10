#ifndef WBSDPAYWINDOW_H
#define WBSDPAYWINDOW_H

#include <QMainWindow>
#include "wbsdpaywindow.h"
#include "wbsdchildwindow.h"
#include "parametermsg.h"
#include "wbsdpaysetprice.h"
#include "wbsdpaysetcoinchannel.h"

namespace Ui {
class WBSDPayWindow;
}

class WBSDPayWindow : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit WBSDPayWindow(WBSDBaseWindow *parent);
    ~WBSDPayWindow();

	void update_cbo(QComboBox* theBox, unsigned int conf);
	void enable_pay(bool enabled,bool paycbo=true);


public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
	void loadPayData(int conf);
    void showpriceset();
    void updateData();
    void updateForm();

public slots:

private slots:
    void on_menuBack_triggered();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
	void on_btnReset_clicked();

    void on_btnCoinChanelA_clicked();
    void on_btnCoinChanelB_clicked();
    void on_btnCoinChanelC_clicked();
    void on_btnCoinChanelD_clicked();
    void on_btnCoinChanelE_clicked();
    void on_btnCoinChanelF_clicked();
	void on_cboCurrency_activated(int index);
	void on_cboRFIDMode_activated(int index);
	void on_cboSaleType_activated(int index);
	void on_cboPaymentEnabled_activated(int index);
	void on_cboClearCreditTime_activated(int index);

    void on_cboRFIDTimeout_activated(int arg1);

	void readPayCounters();

    void on_btn_setwarn_2_clicked();
    void on_btn_setfull_2_clicked();
    void on_btn_setreset_2_clicked();

private:
    Ui::WBSDPayWindow *ui;
    QAction *menuBack;
	WBSDPaySetPrice*	setPrice;
	WBSDPaySetCoinChannel*	setCoinChannelDlg;
	int numberOfDecimals; 
	int drinkNoButton1; 
	int drinkNoButton2; 
	int drinkNoButton3; 
	int drinkNoButton4; 
	int drinkNoButton5; 
	int drinkNoButton6; 
	int drinkNoButton7; 
	int drinkNoButton8; 
	QString drinkNameButton1; 
	QString drinkNameButton2; 
	QString drinkNameButton3; 
	QString drinkNameButton4; 
	QString drinkNameButton5; 
	QString drinkNameButton6; 
	QString drinkNameButton7; 
	QString drinkNameButton8; 
	int drinkPriceButton1; 
	int drinkPriceButton2; 
	int drinkPriceButton3; 
	int drinkPriceButton4; 
	int drinkPriceButton5; 
	int drinkPriceButton6; 
	int drinkPriceButton7; 
	int drinkPriceButton8; 

	int tokenValChannelA; 
	int tokenValChannelB; 
	int tokenValChannelC; 
	int tokenValChannelD; 
	int tokenValChannelE; 
	int tokenValChannelF; 

};

#endif // WBSDPAYWINDOW_H

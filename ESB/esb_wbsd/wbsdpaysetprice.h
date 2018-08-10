#ifndef WBSDPAYSETPRICE_H
#define WBSDPAYSETPRICE_H

#include <QMainWindow>
#include "WBSDChildWindow.h"

namespace Ui {
class WBSDPaySetPrice;
}


class WBSDPaySetPrice : public WBSDChildWindow
{
    Q_OBJECT

public:
	explicit WBSDPaySetPrice(QString aDrinkName,int aDrinkPrice,int aDrinkNumber,int decimals,int tokenVal, WBSDBaseWindow  *parent = 0);
    ~WBSDPaySetPrice();
private slots:
	void on_btnOK_clicked();
	void on_btnCancel_clicked();
	void on_dblPrice_editingFinished();
//    void on_pushButton_clicked();
//    void on_doubleSpinBox_editingFinished();

private:
	Ui::WBSDPaySetPrice *ui;
    QAction *menuBack;
	int theSpeed;
	int lastStatus;
	QString itsDrinkName;
	int itsDrinkPrice;
	int itsDrinkNumber;
	int numberOfDecimals;


public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();
    void closeEvent(QCloseEvent *);
signals:
void iclose();



};

#endif // WBSDPAYSETPRICE_H

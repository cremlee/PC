#ifndef WBSDPaySetCoinChannel_H
#define WBSDPaySetCoinChannel_H

#include <QMainWindow>
#include "WBSDChildWindow.h"

namespace Ui {
class WBSDPaySetCoinChannel;
}


class WBSDPaySetCoinChannel : public WBSDChildWindow
{
    Q_OBJECT

public:
	explicit WBSDPaySetCoinChannel(int aChannel,int aValue, int decimals, WBSDBaseWindow  *parent = 0);
    ~WBSDPaySetCoinChannel();
private slots:
    void on_pushButton_clicked();
    void on_dblChannelValue_editingFinished();

    void on_chkFVToken_toggled(bool checked);
    void closeEvent(QCloseEvent *);
signals:
void iclose();
private:
	Ui::WBSDPaySetCoinChannel *ui;
    QAction *menuBack;
	int theSpeed;
	int lastStatus;
	int itsChannel;
	int itsValue;
	int numberOfDecimals;



public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();
	void on_btnOK_clicked();
	void on_btnCancel_clicked();



};

#endif // WBSDPaySetCoinChannel_H

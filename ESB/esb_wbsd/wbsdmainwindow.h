#ifndef WBSDMAINWINDOW_H
#define WBSDMAINWINDOW_H

#include "wbsdbasewindow.h"
#include "message.h"
#include "wbsdstartpage.h"
#include "wbsd_serial_port.h"
#include "qextserialenumerator.h"
#include "errormessage.h"
#include "qtimer.h"
#include "stringmessage.h"
#include "parametermsg.h"
#include"wbsd_run.h"

namespace Ui {
class WBSDMainWindow;
}

class WBSDMainWindow : public WBSDBaseWindow
{
    Q_OBJECT
    
public:
    explicit WBSDMainWindow(QWidget *parent = 0);
    ~WBSDMainWindow();
    void showConnectionStatus(int connStatus);

protected:
    void changeEvent(QEvent* event);


signals:


private slots:
    void deviceDiscovered(const QextPortInfo &info);
    void deviceRemoved(const QextPortInfo &info);
    void log(QString aString);
	void updateConnectionStatus(int,StringMessage);
    void setLanguage(QAction* action);

public slots:
    void on_actionQuit_triggered();
	void on_actionServiceNormal_triggered();
	void on_actionServiceNurse_triggered();
	void on_actionServiceClean_triggered();
	void on_actionServiceOperator_triggered();
	void on_actionServiceService_triggered();
	void on_actionServiceManufacturer_triggered();
	void on_actionServiceWBSD_triggered();
	void setServiceLevel(int aLevel);
    void on_menuQuit_triggered();
    void on_actionStateUsa_triggered();
    void on_actionStatechange_triggered();

private:
    Ui::WBSDMainWindow *ui;
    WBSDStartPage *startPage;
    wbsd_run *wbsdrun;
    QextSerialEnumerator *qe;
    QAction *menuQuit;
    QMenu *menuLanguages;
    QMenu *menuService_level;
    QMenu *menuState;

    QAction *actionStateOther;
    QAction *actionStateUsa;
    QAction *actionStatechange;

    QAction *actionServiceNormal;
    QAction *actionServiceNurse;
    QAction *actionServiceCleaning;
    QAction *actionServiceOperator;
    QAction *actionServiceService;
    QAction *actionServiceManufacturer;
    QAction *actionServiceWBSD;
    void readAPParameter(int blockNo);
    void readDPParameter(int blockNo);
    void readDoorDPParameter(int blockNo);
    void fillLanguages();
    void retranslate();
    int lastUsedLanguage; //To be read from db!
    void setMenus();

    qint8 Ver_Major;
    qint8 Ver_Min;

};

#endif // WBSDMAINWINDOW_H

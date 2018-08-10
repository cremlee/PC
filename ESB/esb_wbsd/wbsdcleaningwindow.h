#ifndef WBSDCLEANINGWINDOW_H
#define WBSDCLEANINGWINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "parametermsg.h"

namespace Ui {
class WBSDCleaningWindow;
}

class WBSDCleaningWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDCleaningWindow(WBSDBaseWindow *parent);
    ~WBSDCleaningWindow();

public slots:
        void gotMessage(Message aMsg);
        void connectionStatusChanged(int aStatus,StringMessage aMSG);
        void updateData();
        void closeEvent(QCloseEvent *);
        void setcleanenable(bool isenable);
signals:
    void iclose();
private slots:
        void on_clMonday_activated(int index);
        void on_clTuesday_activated(int index);
        void on_clWednesday_activated(int index);
        void on_clThursday_activated(int index);
        void on_clFriday_activated(int index);
        void on_clSaturday_activated(int index);
        void on_clSunday_activated(int index);
        void on_flMonday_activated(int index);
        void on_flTuesday_activated(int index);
        void on_flWednesday_activated(int index);
        void on_flThursday_activated(int index);
        void on_flFriday_activated(int index);
        void on_flSaturday_activated(int index);
        void on_flSunday_activated(int index);
        void on_cleanMode_activated(int index);
        void on_flushMode_activated(int index);
        void on_cb_auto_flag_activated(int index);
        void on_menuBack_triggered();
        void setcleanmode();
        bool IswarningOn();
        bool checkCleaning();
        bool haveCleaning();
private:
    Ui::WBSDCleaningWindow *ui;
    QAction *menuBack;
    unsigned int boardDp1BitField;  //Body unit DP block 1 bit data field
    unsigned int boardDp27BitField; //Body unit DP block 27 bit data field
    void setBoardDP1Parameter(int value, int bitPos);
    void setBoardDP27Parameter(int value, int bitLen, int offset);
    void updateCleanFlushRequests(int conf);
    void updateLabels();
    void updateCleanMode(int conf);
    void updateFlushMode(int conf);
    void updateAutoFlushMode(int conf);
    int _cleanFlag;
    int _crtCleancnt;
    bool isautouse;
    int _fmuflag;
};

#endif // WBSDCLEANINGWINDOW_H

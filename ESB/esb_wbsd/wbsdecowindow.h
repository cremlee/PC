#ifndef WBSDECOWINDOW_H
#define WBSDECOWINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "parametermsg.h"
#include<QTimeEdit>
#include"mywin.h"
namespace Ui {
class WBSDEcoWindow;
}

class WBSDEcoWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDEcoWindow(WBSDBaseWindow *parent);
    ~WBSDEcoWindow();

public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();
    void closeEvent(QCloseEvent *);
signals:
void iclose();
private slots:
    void on_holidayMode_activated(int index);
    void on_ecoWakeup_activated(int index);

    void on_ecoSetTemp_editingFinished();
    void on_menuBack_triggered();

    void on_Tedt_1_editingFinished();
    void on_Tedt_2_editingFinished();
    void on_Tedt_3_editingFinished();
    void on_Tedt_4_editingFinished();
    void on_Tedt_5_editingFinished();
    void on_Tedt_6_editingFinished();
    void on_Tedt_7_editingFinished();

    void  on_Pdt_1_editingFinished();
    void  on_Pdt_2_editingFinished();
    void  on_Pdt_3_editingFinished();
    void  on_Pdt_4_editingFinished();
    void  on_Pdt_5_editingFinished();
    void  on_Pdt_6_editingFinished();
    void  on_Pdt_7_editingFinished();
    void on_ecoMode_activated(int index);
    void SetECODPVal(int block,QTimeEdit*a);
    void updateEcoSetting(int value,QTimeEdit*a);
    bool compareTm(QTimeEdit*a,QTimeEdit*b);
private:
    Ui::WBSDEcoWindow *ui;
    unsigned int boardDp0BitField;  //Body unit DP block 0 bit data field
    QAction *menuBack;
    void updateLabels();
    void updateEcoMode(unsigned int conf);
    void updateHolidayMode(unsigned int conf);
    void updateEcoWakeup(unsigned int conf);

    void updateEcoSetTemp(double temp);
    void setBoardDP0Parameter(unsigned int value, int bitPos);
    void setBoardDP0Parameters(unsigned int value1, unsigned int bitPos1, unsigned int value2, unsigned int bitPos2);
    void GetAllEcoData();
    QList<EcoInfo_T> _lstEco;
};

#endif // WBSDECOWINDOW_H

#ifndef WBSDWATERWINDOW_H
#define WBSDWATERWINDOW_H

#include <QMainWindow>
#include "parametermsg.h"
#include "wbsdchildwindow.h"
#include "qtimer.h"

namespace Ui {
class WBSDWaterWindow;
}

class WBSDWaterWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDWaterWindow(WBSDBaseWindow *parent);
    ~WBSDWaterWindow();

public slots:
    void updateBoilerTempU(QString temp);
    void updateBoilerTempM(QString temp);
    void updateLevelState(int aState);
    void updateHeatingState(int aState);
    void updateTopTemp(double temp);
    void on_topTemp_editingFinished();
    void updateBlockTemp(double temp);
    void on_blockTemp_editingFinished();
	void gotMessage(Message aMsg);
	void connectionStatusChanged(int aStatus,StringMessage aMSG);
	void updateData();
    void savest();
private slots:
    void on_menuBack_triggered();

	void on_cboBlockOnFilter_activated(int index);
	void on_cboBlockOnDecalc_activated(int index);
	void on_cboUseDescaleCounters_activated(int index);
	void on_cboUseWaterFilterCounters_activated(int index);

	void on_spiFilterResetVal_editingFinished();
    void on_spiFilterWarn_editingFinished();
	void on_spiDecalcResetVal_editingFinished();
    void on_spiDecalcWarn_editingFinished();

    void on_btnResetWaterfilter_clicked();
    void on_btnResetDecalc_clicked();


signals:
    void send_topTemp_clicked(ParameterMsg query1, int blockNo);
    void send_blockTemp_clicked(ParameterMsg query1, int blockNo);
    
private:
    Ui::WBSDWaterWindow *ui;
    QAction *menuBack;
    void updateFilterExchange(unsigned int val);
    bool fisequal(double a,double b);
	void enable_waterfilter(bool aFlag);
	void enable_descalefilter(bool aFlag);
	void update_cbo(QComboBox* theBox, unsigned int conf);
    bool _upflab1;
    bool _upflab2;
    int _pwcnt;
    double _lastupvalue,_lastblockvalue;
    bool _isWaterTank;
};
#endif // WBSDWATERWINDOW_H

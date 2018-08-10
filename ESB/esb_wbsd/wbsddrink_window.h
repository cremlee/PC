#ifndef WBSDDRINK_WINDOW_H
#define WBSDDRINK_WINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "Recipe.h"
#include"fmu_parameter.h"
namespace Ui {
class WBSDDrink_Window;
}
const qreal _ozunit = 29.57;
class WBSDDrink_Window : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDDrink_Window(int button,WBSDBaseWindow *parent = 0);
    ~WBSDDrink_Window();
    void updateData();
    bool setTabKatCBO(int aValue,QComboBox* aCombo);
	void setEnableRTDGrp(bool aStatus);
	void setEnableLBIBGrp(bool aStatus);
	void setEnableRBIBGrp(bool aStatus);
	void setEnableInstGrp(bool aStatus);
	void setEnableButtons(bool aStatus);
    void setEnableFmu(bool aStatus);
	QString enableDrink(int aType);
	void reload(int button);
    void closeEvent(QCloseEvent *);
    int getStepPer(int seq);
    void setStepPer(int seq,int value);
signals:
    void iclose();

public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
	void on_cboRecipe_activated(int index);
	void reload();
    void tabwidgetchange(int index);
    void destroywin();
private slots:

    void fmurcpchange(int i);
	void on_menuBack_triggered();

    void on_btnSave_clicked();

    void on_btnCancel_clicked();

    void on_btnSetDefault_clicked();

    void on_btnRestoreDefault_clicked();

    void on_spRTDSmall_editingFinished();
    void on_spRTDSmall_valueChanged(int arg1);

    void on_spRTDMedium_editingFinished();
    void on_spRTDMedium_valueChanged(int arg1);

    void on_spRTDLarge_editingFinished();
    void on_spRTDLarge_valueChanged(int arg1);

    void on_spLBibStrong_editingFinished();
    void on_spLBibStrong_valueChanged(double arg1);

    void on_spLBibMedium_editingFinished();
    void on_spLBibMedium_valueChanged(double arg1);

    void on_spLBibMild_editingFinished();
    void on_spLBibMild_valueChanged(double arg1);

    void on_spRBibStrong_editingFinished();
    void on_spRBibStrong_valueChanged(double arg1);

    void on_spRBibMedium_editingFinished();
    void on_spRBibMedium_valueChanged(double arg1);

    void on_spRBibMild_editingFinished();
    void on_spRBibMild_valueChanged(double arg1);

    void on_spCanGramStrong_editingFinished();
    void on_spCanGramStrong_valueChanged(double arg1);

    void on_spCanGramMedium_editingFinished();
    void on_spCanGramMedium_valueChanged(double arg1);

    void on_spCanGramMild_editingFinished();
    void on_spCanGramMild_valueChanged(double arg1);

    void on_spLBibPercentOfDrink_valueChanged(double arg1);
    void on_spLBibPercentOfDrink_editingFinished();

    void on_spLBibAirpump_valueChanged(double arg1);
    void on_spLBibAirpump_editingFinished();

	void on_spRBibAirpump_valueChanged(double arg1);
    void on_spRBibAirpump_editingFinished();


    void on_btn_fmu_rcp_clicked();

    void on_cb_fmu_id_activated(int index);

    void on_sp_fmu_per_valueChanged(int arg1);

    void on_btn_fmu_rcp_destroyed();

    void on_spd1_valueChanged(int value);

    void on_spd2_valueChanged(int value);

    void on_sp1_valueChanged(int arg1);

    void on_sp2_valueChanged(int arg1);

private:
    QAction *menuBack;
    Ui::WBSDDrink_Window *ui;
    bool isNewDrink;
    bool isVisible;
    int itsButton;
	int itsCfg;
    int isfmuon;
	Recipe *itsRecipe;
    FMU_PARAMETER *fmurcpwin;
};

#endif // WBSDDRINK_WINDOW_H

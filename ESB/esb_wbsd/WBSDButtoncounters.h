#ifndef WBSDButtonCOUNTERS_H
#define WBSDButtonCOUNTERS_H

#include <QMainWindow>
#include "wbsdchildwindow.h"

namespace Ui {
class WBSDButtonCounters;
}

class WBSDButtonCounters : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDButtonCounters(int button,WBSDBaseWindow *parent = 0);
    ~WBSDButtonCounters();

	void updateData();
signals:
    void iclose();
    void destroyed(int);
public slots:
	void gotMessage(Message aMsg);
	void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void closeEvent(QCloseEvent *);
private slots:
    void on_menuBack_triggered();


private:
    QAction *menuBack;
    void updateSmallMild(float volCount);
    void updateSmallNormal(float volCount);
    void updateSmallStrong(float volCount);
    void updateMediumMild(float volCount);
    void updateMediumNormal(float volCount);
    void updateMediumStrong(float volCount);
    void updateLargeMild(float volCount);
    void updateLargeNormal(float volCount);
    void updateLargeStrong(float volCount);
    void updateFFLWMild(float volCount);
    void updateFFLWNormal(float volCount);
    void updateFFLWStrong(float volCount);
    void updateRTDVol(float volCount);
    void updateSmallMildNr(float volCount);
    void updateSmallNormalNr(float volCount);
    void updateSmallStrongNr(float volCount);
    void updateMediumMildNr(float volCount);
    void updateMediumNormalNr(float volCount);
    void updateMediumStrongNr(float volCount);
    void updateLargeMildNr(float volCount);
    void updateLargeNormalNr(float volCount);
    void updateLargeStrongNr(float volCount);
    void updateFFLWMildNr(float volCount);
    void updateFFLWNormaldNr(float volCount);
    void updateFFLWStrongNr(float volCount);
    void updateRTDVolNr(float volCount);
    Ui::WBSDButtonCounters *ui;
	int itsButton;
};

#endif // WBSDButtonCOUNTERS_H

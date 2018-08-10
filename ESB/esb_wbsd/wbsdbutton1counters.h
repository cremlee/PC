#ifndef WBSDBUTTON1COUNTERS_H
#define WBSDBUTTON1COUNTERS_H

#include <QMainWindow>

namespace Ui {
class WBSDButton1Counters;
}

class WBSDButton1Counters : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WBSDButton1Counters(QWidget *parent = 0);
    ~WBSDButton1Counters();

public slots:
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


private:
    Ui::WBSDButton1Counters *ui;
};

#endif // WBSDBUTTON1COUNTERS_H

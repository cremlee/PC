#ifndef WBSDCOUNTERSTOTAL_H
#define WBSDCOUNTERSTOTAL_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "qdebug.h"

namespace Ui {
class WBSDCountersTotal;
}
class T_totalconut
{

public:
    qreal btn1vol;
    qreal btn2vol;
    qreal btn3vol;
    qreal btn4vol;
    qreal btn5vol;
    qreal btn6vol;
    qreal btn7vol;
    bool Isbtn1get;
    bool Isbtn2get;
    bool Isbtn3get;
    bool Isbtn4get;
    bool Isbtn5get;
    bool Isbtn6get;
    bool Isbtn7get;
    T_totalconut() {init();}
    bool isready(){return Isbtn1get&Isbtn2get&Isbtn3get&Isbtn4get&Isbtn5get&Isbtn6get&Isbtn7get;}
    qreal getall(){return btn1vol+btn2vol+btn3vol+btn4vol+btn5vol+btn6vol+btn7vol;}
private:
   void init(){ btn1vol=0;btn2vol=0;btn3vol=0;btn4vol=0;btn5vol=0;btn6vol=0;btn7vol=0;Isbtn1get =false;Isbtn2get =false;Isbtn3get =false;Isbtn4get =false;Isbtn5get =false;Isbtn6get =false;Isbtn7get =false; }
};
class WBSDCountersTotal : public WBSDChildWindow
{
    Q_OBJECT
    
private slots:
    void on_menuBack_triggered();

public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
 signals:
    void iclose();
public:
    explicit WBSDCountersTotal(WBSDBaseWindow *parent = 0);
    ~WBSDCountersTotal();
    void updateData();
    void closeEvent(QCloseEvent *);
    void gettotalcountcmd();
   void gettotalcountnrcmd();
    void updatetotalroll(qreal a,int b);
private:
    Ui::WBSDCountersTotal *ui;
    QAction *menuBack;
    T_totalconut totalconut;
    T_totalconut totalconutnr;
    void updateTotalDrinks(float volCount);
    void updateTotalSmall(float volCount);
    void updateTotalMedium(float volCount);
    void updateTotalLarge(float volCount);
    void updateTotalDrinksNoRe(float volCount);
    void updateTotalSmallNoRe(float volCount);
    void updateTotalMediumNoRe(float volCount);
    void updateTotalLargeNoRe(float volCount);
    void updateLeftBIB(float volCount);
    void updateRightBIB(float volCount);
    void updateInstantVol(float volCount);
    void updateLeftBIBNoRe(float volCount);
    void updateRightBIBNoRe(float volCount);
    void updateInstantVolNoRe(float volCount);
};

#endif // WBSDCOUNTERSTOTAL_H

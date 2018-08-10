#ifndef WBSD_CLONE_H
#define WBSD_CLONE_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include"Recipe.h"
#include "fmu_clone.h"
#include<QFile>
#include<QTextStream>
namespace Ui {
class wbsdclone;
}
const int MCB_DP_CNT =61;
const int MCB_AP_CNT =32;
const int UIB_DP_CNT =24;


class wbsdclone : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit wbsdclone(WBSDBaseWindow *parent = 0,bool bakmod=false);
    ~wbsdclone();
    void Getlngcmd(int lngId);
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void on_btnlang_clicked();
    void on_btnlang_2_clicked();
    void on_btnd_clicked();
    void on_btnr_clicked();
    void on_btn_clear_clicked();
    void on_btn_backup_clicked();
    void on_btn_restore_clicked();
    void dbsup(int cnt);
    bool setversion();
    void getrpc(int rcpId);
    void clonedbs(QString filename);
    void clonercp(QString filename);
    QString getcrtfirewareVersion();
private slots:
    void on_menuBack_triggered();
    void on_pushButton_clicked();
    void destroywin();
private:
    Ui::wbsdclone *ui;
    int _crtOpType; // 0-idel 1-clone 2-clone dbs 3-clone rcp 4-bak 5-restore
    int _crtDbsCnt;
    QByteArray _RcpIdLst;
    Recipe *itsRecipe;
    int _crtRpcIndex;
    QStringList lstrpc;
    QStringList lststr;
    QString _dbsclonefilename;
    QString _rcpclonefilename;
    QFile *clonefiledbs;
    QFile *clonefilerpc;
    QTextStream *dbsstream;
    QTextStream *rcpstream;
    QString _mcbVersion;
    QFile *bkfiledbs;
    QTextStream *dbsbkstream;
    int uib_dp_bak_cnt;
    QAction *menuBack;
    bool _isbakmode;
    FMU_CLONE *fmuclonewin;
};

#endif // WBSD_CLONE_H

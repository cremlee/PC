#ifndef FMU_CLONE_H
#define FMU_CLONE_H

#include "wbsdchildwindow.h"

#include <QFile>
#include <QMainWindow>

namespace Ui {
class FMU_CLONE;
}

class FMU_CLONE : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit FMU_CLONE(WBSDBaseWindow *parent = 0);
    ~FMU_CLONE();
    void closeEvent(QCloseEvent* evt);
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
signals:
    void iclose();
private slots:
    void on_btn_clear_clicked();
    void on_btn_clone_set_clicked();
    void on_btn_clone_rcp_clicked();
    void clonedbs(QString filename);
    void clonercp(QString filename);

    void uppbset(int value);
    void uppbrcp(int value);
    void on_btn_upload_set_clicked();

    void on_btn_upload_rcp_clicked();
void on_menuBack_triggered();
private:
    Ui::FMU_CLONE *ui;
    int CrtOpType;
    int CrtRcpID;
    int CrtCount;
    QStringList lstrpc;
    QStringList lststr;
    QString _dbsclonefilename;
    QString _rcpclonefilename;
    QFile *clonefiledbs;
    QFile *clonefilerpc;
    QTextStream *dbsstream;
    QTextStream *rcpstream;
    QAction *menuBack;
};

#endif // FMU_CLONE_H

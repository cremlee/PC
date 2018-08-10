#ifndef WBSDBTN78CNT_H
#define WBSDBTN78CNT_H

#include <QMainWindow>
#include"wbsdchildwindow.h"
namespace Ui {
class WBSDbtn78cnt;
}

class WBSDbtn78cnt : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit WBSDbtn78cnt(int button,WBSDBaseWindow *parent = 0);
    ~WBSDbtn78cnt();
    void updateData();
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void closeEvent(QCloseEvent *);
private slots:
    void on_menuBack_triggered();
private:
    Ui::WBSDbtn78cnt *ui;
    QAction *menuBack;
};

#endif // WBSDBTN78CNT_H

#ifndef WBSD_EXTERN_TOOL_H
#define WBSD_EXTERN_TOOL_H

#include <QMainWindow>
#include "fmu_test.h"
namespace Ui {
class WBSD_EXTERN_TOOL;
}

class WBSD_EXTERN_TOOL : public WBSDChildWindow
{
    Q_OBJECT
signals:
    void iclose();
public:
    explicit WBSD_EXTERN_TOOL(WBSDBaseWindow *parent = 0);
    ~WBSD_EXTERN_TOOL();
    void closeEvent(QCloseEvent* evt);
public slots:
     void gotMessage(Message aMsg);
     void connectionStatusChanged(int aStatus,StringMessage aMSG);
private slots:
    void on_btn_fmu_tst_clicked();
    void destroywin();
    void on_menuBack_triggered();
private:
    Ui::WBSD_EXTERN_TOOL *ui;
    fmu_test *fmutstwin;
    QAction *menuBack;
};

#endif // WBSD_EXTERN_TOOL_H

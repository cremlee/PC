#ifndef FMU_ERROR_H
#define FMU_ERROR_H

#include "wbsdchildwindow.h"

namespace Ui {
class fmu_error;
}

class fmu_error : public WBSDChildWindow
{
    Q_OBJECT

public:
    explicit fmu_error(WBSDBaseWindow *parent);
    ~fmu_error();
    void closeEvent(QCloseEvent* evt);
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void geterror();
private:
    void InitListview();
    void updateData();
    void refreshHmask(int maskvalue); //0~31
    void refreshLmask(int maskvalue); //32~63
    void refreshUi(QLabel* lable,int index,int maskvalue);
signals:
    void iclose();
private:
    Ui::fmu_error *ui;
};

#endif // FMU_ERROR_H

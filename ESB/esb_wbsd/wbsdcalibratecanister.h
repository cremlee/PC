#ifndef WbsdCalibrateCanister_H
#define WbsdCalibrateCanister_H

#include "parametermsg.h"
#include "wbsdbasedialog.h"

#include <QDialog>

namespace Ui {
class WbsdCalibrateCanister;
}

class WbsdCalibrateCanister : public WBSDBaseDialog
{
    Q_OBJECT
    
public:
    explicit WbsdCalibrateCanister(QWidget *parent = 0);
    ~WbsdCalibrateCanister();
signals:

public slots:
    void startCalibrate();
    void checkProgress();

    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();

    
private:
    Ui::WbsdCalibrateCanister *ui;
};

#endif // WbsdCalibrateCanister_H

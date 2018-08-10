#ifndef WBSDCOOLINGWINDOW_H
#define WBSDCOOLINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class WBSDCoolingWindow;
}

class WBSDCoolingWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WBSDCoolingWindow(QWidget *parent = 0);
    ~WBSDCoolingWindow();

public slots:
    void updateCoolingTemp(QString temp);

public:
    WBSDCoolingWindow *coolingWindow;
    
private:
    Ui::WBSDCoolingWindow *ui;
};

#endif // WBSDCOOLINGWINDOW_H

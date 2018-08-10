#ifndef WBSDVERSIONWINDOW_H
#define WBSDVERSIONWINDOW_H

#include <QMainWindow>
#include "wbsdchildwindow.h"
#include "parametermsg.h"

namespace Ui {
class WBSDVersionWindow;
}

class WBSDVersionWindow : public WBSDChildWindow
{
    Q_OBJECT
    
public:
    explicit WBSDVersionWindow(WBSDBaseWindow *parent);
    ~WBSDVersionWindow();
    void closeEvent(QCloseEvent *);
signals:
    void iclose();
public slots:
    void gotMessage(Message aMsg);
    void connectionStatusChanged(int aStatus,StringMessage aMSG);
    void updateData();

private slots:
    void on_menuBack_triggered();
    
private:
    Ui::WBSDVersionWindow *ui;
    QAction *menuBack;
    void updateSWVer(QString swVer);
};

#endif // WBSDVERSIONWINDOW_H

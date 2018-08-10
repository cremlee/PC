#ifndef WBSDMIXERSWINDOW_H
#define WBSDMIXERSWINDOW_H

#include <QMainWindow>

namespace Ui {
class WBSDMixersWindow;
}

class WBSDMixersWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WBSDMixersWindow(QWidget *parent = 0);
    ~WBSDMixersWindow();
    
private:
    Ui::WBSDMixersWindow *ui;
};

#endif // WBSDMIXERSWINDOW_H

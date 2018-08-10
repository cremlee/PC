#ifndef WBSDBOILERWINDOW_H
#define WBSDBOILERWINDOW_H

#include <QMainWindow>

namespace Ui {
class WBSDBoilerWindow;
}

class WBSDBoilerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WBSDBoilerWindow(QWidget *parent = 0);
    ~WBSDBoilerWindow();
    
private:
    Ui::WBSDBoilerWindow *ui;
};

#endif // WBSDBOILERWINDOW_H

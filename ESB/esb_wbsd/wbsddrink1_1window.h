#ifndef WBSDDRINK1_1WINDOW_H
#define WBSDDRINK1_1WINDOW_H

#include <QMainWindow>

namespace Ui {
class WBSDDrink1_1Window;
}

class WBSDDrink1_1Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WBSDDrink1_1Window(QWidget *parent = 0);
    ~WBSDDrink1_1Window();
    
private:
    Ui::WBSDDrink1_1Window *ui;
};

#endif // WBSDDRINK1_1WINDOW_H

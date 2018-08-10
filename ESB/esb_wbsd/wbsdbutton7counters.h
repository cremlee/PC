#ifndef WBSDBUTTON7COUNTERS_H
#define WBSDBUTTON7COUNTERS_H

#include <QMainWindow>

namespace Ui {
class WBSDButton7Counters;
}

class WBSDButton7Counters : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WBSDButton7Counters(QWidget *parent = 0);
    ~WBSDButton7Counters();
    
private:
    Ui::WBSDButton7Counters *ui;
};

#endif // WBSDBUTTON7COUNTERS_H

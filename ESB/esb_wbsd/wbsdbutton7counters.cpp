#include "wbsdbutton7counters.h"
#include "ui_wbsdbutton7counters.h"

WBSDButton7Counters::WBSDButton7Counters(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WBSDButton7Counters)
{
    ui->setupUi(this);
}

WBSDButton7Counters::~WBSDButton7Counters()
{
    delete ui;
}

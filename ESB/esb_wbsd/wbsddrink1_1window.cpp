#include "wbsddrink1_1window.h"
#include "ui_wbsddrink1_1window.h"

WBSDDrink1_1Window::WBSDDrink1_1Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WBSDDrink1_1Window)
{
    ui->setupUi(this);
}

WBSDDrink1_1Window::~WBSDDrink1_1Window()
{
    delete ui;
}

#include "wbsdboilerwindow.h"
#include "ui_wbsdboilerwindow.h"

WBSDBoilerWindow::WBSDBoilerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WBSDBoilerWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setLayout(ui->gridLayout);
}

WBSDBoilerWindow::~WBSDBoilerWindow()
{
    delete ui;
}

#include "wbsdmixerswindow.h"
#include "ui_wbsdmixerswindow.h"

WBSDMixersWindow::WBSDMixersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WBSDMixersWindow)
{
    ui->setupUi(this);
    /*modify by Lee.li
     */
    ui->centralwidget->setLayout(ui->gridLayout);
}

WBSDMixersWindow::~WBSDMixersWindow()
{
    delete ui;
}

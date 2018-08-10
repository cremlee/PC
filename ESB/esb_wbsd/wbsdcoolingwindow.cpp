#include "wbsdcoolingwindow.h"
#include "ui_wbsdcoolingwindow.h"

WBSDCoolingWindow::WBSDCoolingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WBSDCoolingWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setLayout(ui->gridLayout);
}

WBSDCoolingWindow::~WBSDCoolingWindow()
{
    delete ui;
}

void WBSDCoolingWindow::updateCoolingTemp(QString temp)
{
    //RJ TO DO automatic °C/F
    QString tempText = QString("%1 C").arg(temp);
    ui->coolingTemp->setText(tempText);
}

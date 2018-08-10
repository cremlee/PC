#include "bibrecipe.h"
#include "ui_bibrecipe.h"

BIBRecipe::BIBRecipe(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::BIBRecipe)
{
    ui->setupUi(this);
}

BIBRecipe::~BIBRecipe()
{
    delete ui;
}

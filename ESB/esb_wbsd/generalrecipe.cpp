#include "generalrecipe.h"
#include "ui_generalrecipe.h"

GeneralRecipe::GeneralRecipe(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::GeneralRecipe)
{
    ui->setupUi(this);
}

GeneralRecipe::~GeneralRecipe()
{
    delete ui;
}

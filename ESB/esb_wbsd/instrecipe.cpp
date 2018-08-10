#include "instrecipe.h"
#include "ui_instrecipe.h"

InstRecipe::InstRecipe(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::InstRecipe)
{
    ui->setupUi(this);
}

InstRecipe::~InstRecipe()
{
    delete ui;
}

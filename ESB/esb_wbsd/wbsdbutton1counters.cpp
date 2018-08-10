#include "wbsdbutton1counters.h"
#include "ui_wbsdbutton1counters.h"

WBSDButton1Counters::WBSDButton1Counters(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WBSDButton1Counters)
{
    ui->setupUi(this);
}

WBSDButton1Counters::~WBSDButton1Counters()
{
    delete ui;
}

void WBSDButton1Counters::updateSmallMild(float volCount)
{
    ui->smallMild->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateSmallNormal(float volCount)
{
    ui->smallNormal->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateSmallStrong(float volCount)
{
    ui->smallStrong->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateMediumMild(float volCount)
{
    ui->mediumMild->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateMediumNormal(float volCount)
{
    ui->mediumNormal->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateMediumStrong(float volCount)
{
    ui->mediumStrong->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateLargeMild(float volCount)
{
    ui->largeMild->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateLargeNormal(float volCount)
{
    ui->largeNormal->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateLargeStrong(float volCount)
{
    ui->largeStrong->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateFFLWMild(float volCount)
{
    ui->fflwMild->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateFFLWNormal(float volCount)
{
    ui->fflwNormal->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateFFLWStrong(float volCount)
{
    ui->fflwStrong->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateRTDVol(float volCount)
{
    ui->rtdVol->setText(QString::number(volCount));
}




void WBSDButton1Counters::updateSmallMildNr(float volCount)
{
    ui->smallMildNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateSmallNormalNr(float volCount)
{
    ui->smallNormalNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateSmallStrongNr(float volCount)
{
    ui->smallStrongNr->setText(QString::number(volCount));
}


void WBSDButton1Counters::updateMediumMildNr(float volCount)
{
    ui->mediumMildNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateMediumNormalNr(float volCount)
{
    ui->mediumNormalNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateMediumStrongNr(float volCount)
{
    ui->mediumStrongNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateLargeMildNr(float volCount)
{
    ui->largeMildNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateLargeNormalNr(float volCount)
{
    ui->largeNormalNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateLargeStrongNr(float volCount)
{
    ui->largeStrongNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateFFLWMildNr(float volCount)
{
    ui->mediumStrongNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateFFLWNormaldNr(float volCount)
{
    ui->largeMildNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateFFLWStrongNr(float volCount)
{
    ui->largeNormalNr->setText(QString::number(volCount));
}

void WBSDButton1Counters::updateRTDVolNr(float volCount)
{
    ui->largeStrongNr->setText(QString::number(volCount));
}


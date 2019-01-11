#include "statistic.h"
#include "ui_statistic.h"


Statistic::Statistic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);
}

Statistic::~Statistic()
{
    delete ui;
}

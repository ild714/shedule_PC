#include "dialog_date.h"
#include "ui_dialog_date.h"

Dialog_date::Dialog_date(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_date)
{
    ui->setupUi(this);
}

Dialog_date::~Dialog_date()
{
    delete ui;
}

QDate Dialog_date::getDate()
{
    return ui->dateEdit->date();
}

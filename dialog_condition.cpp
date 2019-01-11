#include "dialog_condition.h"
#include "ui_dialog_condition.h"


Dialog_condition::Dialog_condition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_condition)
{
    ui->setupUi(this);
}

Dialog_condition::~Dialog_condition()
{
    delete ui;
}

QString Dialog_condition::get_condition()
{
    QString condition = "Done";
    return condition;
}

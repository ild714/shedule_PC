#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    /*std::string stroka = currentDateTime();
    const char *cstr = stroka.c_str();
    std::string time = "";
    std::string new_date = "";
    for (int i=11; i<strlen(cstr)-3;i++)
        time+=cstr[i];
    for (int i=0; i<10;i++)
        new_date+=cstr[i];
    QString date = QString::fromStdString(new_date);
    QDate date_1 = QDate::fromString(date,"YYYY-MM-dd");
    */
    /*QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);*/
    ui->setupUi(this);
}


Dialog::~Dialog()
{
    delete ui;
}

std::string Dialog::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char    buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

QString Dialog::getTask()
{
    return ui->lineEdit->text();
}

QDate Dialog::getDate()
{
    return ui->dateEdit->date();
}
QTime Dialog::get_start_time()
{
    return ui->timeEdit->time();
}

QTime Dialog::get_end_time()
{
    return ui->timeEdit_2->time();
}

QString Dialog::get_type()
{
    return ui->comboBox->currentText();
}

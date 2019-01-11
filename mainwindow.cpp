#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "massive.h"
#include "casual_task.h"
#include "special_task.h"
#include <QDate>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include "dialog_date.h"
#include "dialog_condition.h"
#include "massive_2.h"


Massive cont(0);
Massive_2 cont_2(0);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char    buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}


void MainWindow::generate_table()
{
    QColor color;
    int num = cont.getLength() + cont_2.getLength();
    ui->tableWidget->setRowCount(num);
    ui->tableWidget->setColumnCount(6);
    for (int i = 0; i < 6; i++) ui->tableWidget->setColumnWidth(i, 120);
    QStringList tableHeader;
    tableHeader<< "Task" << "Date" << "Category" << "Condition" << "Begin time"<<"End time";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    int max_cont = 0;
    for (int i = 0; i < cont.getLength(); i++)
    {
        QString new_condition = QString::fromStdString(cont.getTask(i).get_condition());
        if (new_condition=="Done")
            color = Qt::green;
        if (new_condition=="Overdue")
            color = Qt::red;
        if (new_condition=="Process")
            color = Qt::yellow;
        QString new_task = QString::fromStdString(cont.getTask(i).get_task());
        QString new_date = QString::fromStdString(cont.getTask(i).get_date());
        QString new_category = QString::fromStdString(cont.getTask(i).get_category());
        QTableWidgetItem *tbl = new QTableWidgetItem(new_task);
        QTableWidgetItem *tbl_1 = new QTableWidgetItem(new_date);
        QTableWidgetItem *tbl_2 = new QTableWidgetItem(new_category);
        QTableWidgetItem *tbl_3 = new QTableWidgetItem(new_condition);
        QTableWidgetItem *tbl_4 = new QTableWidgetItem("-");
        QTableWidgetItem *tbl_5 = new QTableWidgetItem("-");
        ui->tableWidget->setItem(i, 0, tbl);
        ui->tableWidget->setItem(i, 1, tbl_1);
        ui->tableWidget->setItem(i, 2, tbl_2);
        ui->tableWidget->setItem(i, 3, tbl_3);
        ui->tableWidget->setItem(i, 4, tbl_4);
        ui->tableWidget->setItem(i, 5, tbl_5);
        tbl->setBackgroundColor(color);
        tbl_1->setBackgroundColor(color);
        tbl_2->setBackgroundColor(color);
        tbl_3->setBackgroundColor(color);
        tbl_4->setBackgroundColor(color);
        tbl_5->setBackgroundColor(color);
        max_cont++;
    }
    for (int i = 0; i < cont_2.getLength();i++)
    {
        QString new_condition = QString::fromStdString(cont_2.getTask(i).get_condition());
        if (new_condition=="Done")
            color = Qt::green;
        if (new_condition=="Overdue")
            color = Qt::red;
        if (new_condition=="Process")
            color = Qt::yellow;
        QString new_task = QString::fromStdString(cont_2.getTask(i).get_task());
        QString new_date = QString::fromStdString(cont_2.getTask(i).get_date());
        QString new_category = QString::fromStdString(cont_2.getTask(i).get_category());
        QString new_time_begin = QString::fromStdString(cont_2.getTask(i).get_start());
        QString new_time_end = QString::fromStdString(cont_2.getTask(i).get_end());
        QTableWidgetItem *tbl = new QTableWidgetItem(new_task);
        QTableWidgetItem *tbl_1 = new QTableWidgetItem(new_date);
        QTableWidgetItem *tbl_2 = new QTableWidgetItem(new_category);
        QTableWidgetItem *tbl_3 = new QTableWidgetItem(new_condition);
        QTableWidgetItem *tbl_4 = new QTableWidgetItem(new_time_begin);
        QTableWidgetItem *tbl_5 = new QTableWidgetItem(new_time_end);
        ui->tableWidget->setItem(i+max_cont, 0, tbl);
        ui->tableWidget->setItem(i+max_cont, 1, tbl_1);
        ui->tableWidget->setItem(i+max_cont, 2, tbl_2);
        ui->tableWidget->setItem(i+max_cont, 3, tbl_3);
        ui->tableWidget->setItem(i+max_cont, 4, tbl_4);
        ui->tableWidget->setItem(i+max_cont, 5, tbl_5);
        tbl->setBackgroundColor(color);
        tbl_1->setBackgroundColor(color);
        tbl_2->setBackgroundColor(color);
        tbl_3->setBackgroundColor(color);
        tbl_4->setBackgroundColor(color);
        tbl_5->setBackgroundColor(color);
    }
}


void MainWindow::generate_table_time(QString date)
{
    QColor color;
    ui->tableWidget->clear();
    int num = 0;
    for (int i = 0; i < cont.getLength(); i++)
    {
        QString new_date = QString::fromStdString(cont.getTask(i).get_date());
        if (new_date==date)
        {
            num+=1;
        }
    }
    for (int i = 0; i < cont_2.getLength(); i++)
    {
        QString new_date = QString::fromStdString(cont_2.getTask(i).get_date());
        if (new_date==date)
        {
            num+=1;
        }
    }
    ui->tableWidget->setRowCount(num);
    ui->tableWidget->setColumnCount(6);
    for (int i = 0; i < 6; i++) ui->tableWidget->setColumnWidth(i, 120);
    QStringList tableHeader;
    tableHeader<< "Task" << "Date/time" << "Category" << "Condition" << "Begin time"<<"End time";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    int max_cont = 0;
    for (int i = 0; i < cont.getLength(); i++)
    {
        QString new_date = QString::fromStdString(cont.getTask(i).get_date());
        if (new_date==date)
        {
            QString new_condition = QString::fromStdString(cont.getTask(i).get_condition());
            if (new_condition=="Done")
                color = Qt::green;
            if (new_condition=="Overdue")
                color = Qt::red;
            if (new_condition=="Process")
                color = Qt::yellow;
            QString new_task = QString::fromStdString(cont.getTask(i).get_task());
            QString new_date = QString::fromStdString(cont.getTask(i).get_date());
            QString new_category = QString::fromStdString(cont.getTask(i).get_category());
            QTableWidgetItem *tbl = new QTableWidgetItem(new_task);
            QTableWidgetItem *tbl_1 = new QTableWidgetItem(new_date);
            QTableWidgetItem *tbl_2 = new QTableWidgetItem(new_category);
            QTableWidgetItem *tbl_3 = new QTableWidgetItem(new_condition);
            QTableWidgetItem *tbl_4 = new QTableWidgetItem("-");
            QTableWidgetItem *tbl_5 = new QTableWidgetItem("-");
            ui->tableWidget->setItem(max_cont, 0, tbl);
            ui->tableWidget->setItem(max_cont, 1, tbl_1);
            ui->tableWidget->setItem(max_cont, 2, tbl_2);
            ui->tableWidget->setItem(max_cont, 3, tbl_3);
            ui->tableWidget->setItem(max_cont, 4, tbl_4);
            ui->tableWidget->setItem(max_cont, 5, tbl_5);
            tbl->setBackgroundColor(color);
            tbl_1->setBackgroundColor(color);
            tbl_2->setBackgroundColor(color);
            tbl_3->setBackgroundColor(color);
            tbl_4->setBackgroundColor(color);
            tbl_5->setBackgroundColor(color);
            max_cont++;
        }
    }
    num = 0;
    for (int i = 0; i < cont_2.getLength();i++)
    {
        QString new_date = QString::fromStdString(cont_2.getTask(i).get_date());
        if (new_date==date)
        {
            QString new_condition = QString::fromStdString(cont_2.getTask(i).get_condition());
            if (new_condition=="Done")
                color = Qt::green;
            if (new_condition=="Overdue")
                color = Qt::red;
            if (new_condition=="Process")
                color = Qt::yellow;
            QString new_task = QString::fromStdString(cont_2.getTask(i).get_task());
            QString new_category = QString::fromStdString(cont_2.getTask(i).get_category());
            QString new_time_begin = QString::fromStdString(cont_2.getTask(i).get_start());
            QString new_time_end = QString::fromStdString(cont_2.getTask(i).get_end());
            QTableWidgetItem *tbl = new QTableWidgetItem(new_task);
            QTableWidgetItem *tbl_1 = new QTableWidgetItem(new_date);
            QTableWidgetItem *tbl_2 = new QTableWidgetItem(new_category);
            QTableWidgetItem *tbl_3 = new QTableWidgetItem(new_condition);
            QTableWidgetItem *tbl_4 = new QTableWidgetItem(new_time_begin);
            QTableWidgetItem *tbl_5 = new QTableWidgetItem(new_time_end);
            ui->tableWidget->setItem(num+max_cont, 0, tbl);
            ui->tableWidget->setItem(num+max_cont, 1, tbl_1);
            ui->tableWidget->setItem(num+max_cont, 2, tbl_2);
            ui->tableWidget->setItem(num+max_cont, 3, tbl_3);
            ui->tableWidget->setItem(num+max_cont, 4, tbl_4);
            ui->tableWidget->setItem(num+max_cont, 5, tbl_5);
            tbl->setBackgroundColor(color);
            tbl_1->setBackgroundColor(color);
            tbl_2->setBackgroundColor(color);
            tbl_3->setBackgroundColor(color);
            tbl_4->setBackgroundColor(color);
            tbl_5->setBackgroundColor(color);
            num++;
        }
    }



}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog *dialog = new Dialog();
    if (dialog->exec()) {
        auto task = dialog->getTask();
        auto date = dialog->getDate();
        auto start_time = dialog->get_start_time();
        auto end_time = dialog->get_end_time();
        auto type = dialog->get_type();
        string new_type = type.toStdString();
        QString stroka = date.toString("dd.MM.yyyy");
        string new_date = stroka.toStdString();
        string new_task = task.toStdString();
        QString new_start_time = start_time.toString();
        string new_start_time_1 = new_start_time.toStdString();
        QString new_end_time = end_time.toString();
        string new_end_time_1 = new_end_time.toStdString();
        if (new_type=="Special")
        {
            Special_task *task_1 = new Special_task(new_task,new_date,new_type,"Process",new_start_time_1,new_end_time_1);
            int num = cont_2.getLength();
            cont_2.insert(*task_1,num);
            generate_table();
        }
        else
        {
            Casual_task *task_1 = new Casual_task(new_date,new_task,new_type,"Process");
            int num = cont.getLength();
            cont.insert(*task_1,num);
            generate_table();
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int itm = ui->tableWidget->currentRow();
    int count = 0;
    for (int i=0; i<cont.getLength();i++)
    {
        if (count == itm)
            cont.remove(itm);
        count++;
    }
    for (int i=0; i<cont_2.getLength();i++)
    {
        if(count==itm)
            cont_2.remove(i);
        count++;
    }
    generate_table();
}

void MainWindow::on_pushButton_clicked()
{

    auto file_name = QFileDialog::getOpenFileName(this,"Open a file");
    ifstream input(file_name.toStdString());
    int num = 0;
    int num_2= 0;
    if (input){
        cont.clear();
        cont_2.clear();
        string date, task, category, condition, begin_time, end_time;
        while(getline(input, category, ' '))
        {
            if (category=="Casual")
            {
                getline(input, date,' ');
                getline(input, condition,' ');
                getline(input, task, '\n');
                Casual_task *task_1 = new Casual_task(date, task, category , condition);
                cont.insert(*task_1,num);
                num++;
            }
            else
            {
                getline(input, date,' ');
                getline(input, condition, ' ');
                getline(input, begin_time, ' ');
                getline(input, end_time, ' ');
                getline(input, task, '\n');
                Special_task *task_1 = new Special_task( task, date,category , condition, begin_time, end_time);
                cont_2.insert(*task_1,num_2);
                num_2++;
            }
        }
        input.close();
        generate_table();
     }
}

void MainWindow::on_pushButton_2_clicked()
{
    auto file_name = QFileDialog::getSaveFileName(this,"Save a file");
    ofstream output(file_name.toStdString());
    {
        for (int i=0; i<cont.getLength(); i++)
        {
            output<<cont.getTask(i).get_category()<< " " <<cont.getTask(i).get_date()<<" "<<cont.getTask(i).get_condition()<<" "<<cont.getTask(i).get_task() <<endl;
        }
        for (int i=0; i<cont_2.getLength(); i++)
        {
            output<< cont_2.getTask(i).get_category()<< " " <<cont_2.getTask(i).get_date()<<" "<<cont_2.getTask(i).get_condition()<<" "<<cont_2.getTask(i).get_start()<<" "<<cont_2.getTask(i).get_end()<< " "<<cont_2.getTask(i).get_task() <<endl;
        }
    }
    output.close();
}
void MainWindow::on_pushButton_5_clicked()
{
    Dialog_date *dialog = new Dialog_date();
    if (dialog->exec()) {
        auto date = dialog->getDate();
        QString stroka = date.toString("dd.MM.yyyy");
        generate_table_time(stroka);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    generate_table();
}

void MainWindow::on_pushButton_7_clicked()
{
    cont.clear();
    cont_2.clear();
    generate_table();
}

void MainWindow::on_pushButton_8_clicked()
{
    Dialog_condition *dialog = new Dialog_condition();
    if (dialog->exec()) {
        auto condition = dialog->get_condition();
        string new_condition = condition.toStdString();
        int itm = ui->tableWidget->currentRow();
        int count = 0;
        for (int i=0; i<cont.getLength();i++)
        {
            if (count == itm)
                cont.getTask(itm).set_condition(new_condition);
            count++;
        }
        for (int i=0; i<cont_2.getLength();i++)
        {
            if(count==itm)
                cont_2.getTask(i).set_condition(new_condition);
            count++;
        }
        generate_table();
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    string stroka = currentDateTime();
    const char *cstr = stroka.c_str();
    string time = "";
    string date = "";
    string new_stroka = "";
    for (int i=11; i<strlen(cstr)-3;i++)
        time+=cstr[i];
    date +=cstr[8];
    date +=cstr[9];
    date +=".";
    date +=cstr[5];
    date +=cstr[6];
    date +=".";
    date +=cstr[0];
    date +=cstr[1];
    date +=cstr[2];
    date +=cstr[3];
    for (int i = 0; i < cont.getLength(); i++)
    {
        string new_date = cont.getTask(i).get_date();
        string new_cond = cont.getTask(i).get_condition();
        if (new_date<date && new_cond!="Done")
        {
            cont.getTask(i).set_condition("Overdue");
        }
    }
    for (int i = 0; i < cont_2.getLength(); i++)
    {
        string end_time = cont_2.getTask(i).get_end();
        string new_date = cont_2.getTask(i).get_date();
        string new_cond = cont_2.getTask(i).get_condition();
        if((end_time<time || new_date<date) && new_cond!="Done")
        {
            cont_2.getTask(i).set_condition("Overdue");
        }
    }
    generate_table();
}



void MainWindow::on_pushButton_10_clicked()
{

}

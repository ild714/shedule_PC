#include "mainwindow.h"
#include <QApplication>
#include "casual_task.h"
#include "massive.h"
#include <iostream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

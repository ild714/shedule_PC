#-------------------------------------------------
#
# Project created by QtCreator 2018-12-15T12:14:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    casual_task.cpp \
    massive.cpp \
    dialog.cpp \
    dialog_date.cpp \
    special_task.cpp \
    massive_2.cpp \
    dialog_condition.cpp \
    statistic.cpp

HEADERS += \
        mainwindow.h \
    casual_task.h \
    massive.h \
    dialog.h \
    dialog_date.h \
    special_task.h \
    massive_2.h \
    dialog_condition.h \
    statistic.h

FORMS += \
        mainwindow.ui \
    dialog.ui \
    dialog_date.ui \
    dialog_condition.ui \
    statistic.ui

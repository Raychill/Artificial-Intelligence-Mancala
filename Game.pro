#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T10:59:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cells.cpp \
    singleagent.cpp \
    mBoard.cpp

HEADERS  += mainwindow.h \
    singleagent.h \
    cells.h \
    mBoard.h

FORMS    += mainwindow.ui

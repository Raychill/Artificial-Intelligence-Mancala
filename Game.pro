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
    newgame.cpp \
    cells.cpp \
    singleagent.cpp

HEADERS  += mainwindow.h \
    newgame.h \
    singleagent.h \
    cells.h

FORMS    += mainwindow.ui

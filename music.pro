#-------------------------------------------------
#
# Project created by QtCreator 2015-07-16T15:13:06
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = music
TEMPLATE = app


SOURCES += ui/main.cpp\
        ui/mainwindow.cpp

HEADERS  += ui/mainwindow.h\
            src/local/player.h\
            src/online/network.h

FORMS    += ui/mainwindow.ui

INCLUDEPATH += src/local
INCLUDEPATH += src/online

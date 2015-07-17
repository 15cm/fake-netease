#-------------------------------------------------
#
# Project created by QtCreator 2015-07-16T15:13:06
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = music
TEMPLATE = app


SOURCES += ui/main.cpp\
        ui/mainwindow.cpp

HEADERS  += ui/mainwindow.h\
            src/local/OffMusic.h\
            src/local/player.h\
            src/online/network.h\
            src/music.h \
            src/online/onmusic.h \
    src/local/listrecord.h

FORMS    += ui/mainwindow.ui

INCLUDEPATH += src/local
INCLUDEPATH += src/online
INCLUDEPATH += src

RESOURCES += \
    ui/ui_rescource.qrc

DISTFILES += \
    Library/libtag.so

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Library/release/ -ltag
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Library/debug/ -ltag
else:unix: LIBS += -L$$PWD/Library/ -ltag

INCLUDEPATH += $$PWD/Library
DEPENDPATH += $$PWD/Library

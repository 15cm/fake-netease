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
            src/local/playlistrecord.h \
    src/commander.h \
    src/online/onlinemusiclistfiller.h

FORMS    += ui/mainwindow.ui

INCLUDEPATH += src/local
INCLUDEPATH += src/online
INCLUDEPATH += src

CONFIG += C++11

RESOURCES += \
    ui/ui_rescource.qrc



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/3rdpart/taglib/lib/release/ -ltag
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/3rdpart/taglib/lib/debug/ -ltag
else:unix: LIBS += -L$$PWD/3rdpart/taglib/lib/ -ltag

INCLUDEPATH += $$PWD/3rdpart/taglib/include
DEPENDPATH += $$PWD/3rdpart/taglib/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/3rdpart/taglib/lib/release/libtag.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/3rdpart/taglib/lib/debug/libtag.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/3rdpart/taglib/lib/release/tag.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/3rdpart/taglib/lib/debug/tag.lib
else:unix: PRE_TARGETDEPS += $$PWD/3rdpart/taglib/lib/libtag.a

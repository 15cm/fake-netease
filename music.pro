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
    3rdpart/taglib/include/aifffile.h \
    3rdpart/taglib/include/aiffproperties.h \
    3rdpart/taglib/include/apefile.h \
    3rdpart/taglib/include/apefooter.h \
    3rdpart/taglib/include/apeitem.h \
    3rdpart/taglib/include/apeproperties.h \
    3rdpart/taglib/include/apetag.h \
    3rdpart/taglib/include/asfattribute.h \
    3rdpart/taglib/include/asffile.h \
    3rdpart/taglib/include/asfpicture.h \
    3rdpart/taglib/include/asfproperties.h \
    3rdpart/taglib/include/asftag.h \
    3rdpart/taglib/include/attachedpictureframe.h \
    3rdpart/taglib/include/audioproperties.h \
    3rdpart/taglib/include/commentsframe.h \
    3rdpart/taglib/include/fileref.h \
    3rdpart/taglib/include/flacfile.h \
    3rdpart/taglib/include/flacmetadatablock.h \
    3rdpart/taglib/include/flacpicture.h \
    3rdpart/taglib/include/flacproperties.h \
    3rdpart/taglib/include/generalencapsulatedobjectframe.h \
    3rdpart/taglib/include/id3v1genres.h \
    3rdpart/taglib/include/id3v1tag.h \
    3rdpart/taglib/include/id3v2extendedheader.h \
    3rdpart/taglib/include/id3v2footer.h \
    3rdpart/taglib/include/id3v2frame.h \
    3rdpart/taglib/include/id3v2framefactory.h \
    3rdpart/taglib/include/id3v2header.h \
    3rdpart/taglib/include/id3v2synchdata.h \
    3rdpart/taglib/include/id3v2tag.h \
    3rdpart/taglib/include/infotag.h \
    3rdpart/taglib/include/itfile.h \
    3rdpart/taglib/include/itproperties.h \
    3rdpart/taglib/include/modfile.h \
    3rdpart/taglib/include/modfilebase.h \
    3rdpart/taglib/include/modproperties.h \
    3rdpart/taglib/include/modtag.h \
    3rdpart/taglib/include/mp4atom.h \
    3rdpart/taglib/include/mp4coverart.h \
    3rdpart/taglib/include/mp4file.h \
    3rdpart/taglib/include/mp4item.h \
    3rdpart/taglib/include/mp4properties.h \
    3rdpart/taglib/include/mp4tag.h \
    3rdpart/taglib/include/mpcfile.h \
    3rdpart/taglib/include/mpcproperties.h \
    3rdpart/taglib/include/mpegfile.h \
    3rdpart/taglib/include/mpegheader.h \
    3rdpart/taglib/include/mpegproperties.h \
    3rdpart/taglib/include/oggfile.h \
    3rdpart/taglib/include/oggflacfile.h \
    3rdpart/taglib/include/oggpage.h \
    3rdpart/taglib/include/oggpageheader.h \
    3rdpart/taglib/include/opusfile.h \
    3rdpart/taglib/include/opusproperties.h \
    3rdpart/taglib/include/ownershipframe.h \
    3rdpart/taglib/include/popularimeterframe.h \
    3rdpart/taglib/include/privateframe.h \
    3rdpart/taglib/include/relativevolumeframe.h \
    3rdpart/taglib/include/rifffile.h \
    3rdpart/taglib/include/s3mfile.h \
    3rdpart/taglib/include/s3mproperties.h \
    3rdpart/taglib/include/speexfile.h \
    3rdpart/taglib/include/speexproperties.h \
    3rdpart/taglib/include/tag.h \
    3rdpart/taglib/include/tag_c.h \
    3rdpart/taglib/include/taglib.h \
    3rdpart/taglib/include/taglib_config.h \
    3rdpart/taglib/include/taglib_export.h \
    3rdpart/taglib/include/tbytevector.h \
    3rdpart/taglib/include/tbytevectorlist.h \
    3rdpart/taglib/include/tbytevectorstream.h \
    3rdpart/taglib/include/tdebuglistener.h \
    3rdpart/taglib/include/textidentificationframe.h \
    3rdpart/taglib/include/tfile.h \
    3rdpart/taglib/include/tfilestream.h \
    3rdpart/taglib/include/tiostream.h \
    3rdpart/taglib/include/tlist.h \
    3rdpart/taglib/include/tmap.h \
    3rdpart/taglib/include/tpropertymap.h \
    3rdpart/taglib/include/trefcounter.h \
    3rdpart/taglib/include/trueaudiofile.h \
    3rdpart/taglib/include/trueaudioproperties.h \
    3rdpart/taglib/include/tstring.h \
    3rdpart/taglib/include/tstringlist.h \
    3rdpart/taglib/include/uniquefileidentifierframe.h \
    3rdpart/taglib/include/unknownframe.h \
    3rdpart/taglib/include/unsynchronizedlyricsframe.h \
    3rdpart/taglib/include/urllinkframe.h \
    3rdpart/taglib/include/vorbisfile.h \
    3rdpart/taglib/include/vorbisproperties.h \
    3rdpart/taglib/include/wavfile.h \
    3rdpart/taglib/include/wavpackfile.h \
    3rdpart/taglib/include/wavpackproperties.h \
    3rdpart/taglib/include/wavproperties.h \
    3rdpart/taglib/include/xingheader.h \
    3rdpart/taglib/include/xiphcomment.h \
    3rdpart/taglib/include/xmfile.h \
    3rdpart/taglib/include/xmproperties.h \
    src/commander/iaddlocalmusic.h \
    src/commander/iaddlocalmusicfolder.h \
    src/commander/iplaycurrentmusic.h \
    src/commander/isetvolume.h \
    src/commander/itablefiller.h \
    src/commander/localmusicadder.h \
    src/commander/interface/iaddlocalmusicfolder.h \
    src/commander/interface/iplaycurrentmusic.h \
    src/commander/interface/isetvolume.h \
    src/commander/implementation/localmusicfolderadder.h \
    src/commander/implementation/localmusicadder.h \
    src/commander/interface/iaddlocalmusic.h \
    src/commander/implementation/currentmusicplayer.h \
    src/commander/implementation/volumesetter.h \
    src/commander/interface/ifilltable.h \
    src/commander/implementation/ontablefiller.h \
    src/commander/interface/igetcurrentplaystate.h \
    src/commander/implementation/currentplaystategetter.h

FORMS    += ui/mainwindow.ui

INCLUDEPATH += src/local
INCLUDEPATH += src/online
INCLUDEPATH += src/commander\
                src/commander/interface\
                src/commander/implementation
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

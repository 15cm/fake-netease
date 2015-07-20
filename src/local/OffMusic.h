#ifndef OFFMUSIC
#define OFFMUSIC

#include "music.h"
#include "3rdpart/taglib/include/fileref.h"

class OffMusic : public Music
{
public:
    OffMusic() {}
    OffMusic(const OffMusic& offmusic){
        name = offmusic.name;
        duration = offmusic.duration;
        mp3Url = offmusic.mp3Url;
        artist = offmusic.artist;
        album = offmusic.album;
    }

    OffMusic(QUrl url){
        TagLib::FileRef ref(url.path().toLatin1().data());
        if(!ref.tag())
        {
            qDebug() << "NULL";
        }
        name = QString(ref.tag()->title().toCString());
        duration = ref.audioProperties()->length();
        mp3Url = url;
        artist = QString(ref.tag()->artist().toCString());
        album = QString(ref.tag()->album().toCString());
        if(name.isEmpty())
        {
            QString qstr = url.fileName();
            QStringList list = qstr.split(".");
            if(!list.isEmpty())
                name = list.first();
            else
                name = "UNKNOWN";
        }
    }

    virtual ~OffMusic(){}
};


#endif

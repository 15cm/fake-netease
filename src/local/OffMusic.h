#ifndef OFFMUSIC
#define OFFMUSIC

#include "music.h"
#include "taglib/fileref.h"

class OffMusic : public Music
{
public:
    OffMusic(const QUrl &url);
    virtual ~OffMusic(){}
};

OffMusic::OffMusic(const QUrl &url)
{
    TagLib::FileRef ref(url.path().toLatin1().data());
    name = QString::fromStdString(ref.tag()->title().to8Bit());
    if(!ref.tag())
    {
        qDebug() << "NULL";
    }
    duration = ref.audioProperties()->length();
    mp3Url = url;
    artist = QString(ref.tag()->artist().toCString());
    album = QString(ref.tag()->album().toCString());

}

#endif

#ifndef OFFMUSIC
#define OFFMUSIC

#include <music.h>

class OffMusic : public Music
{
public:
    OffMusic(QUrl url);
    virtual ~OffMusic(){}
};

OffMusic::OffMusic(QUrl url)
{
}

#endif

#ifndef OFFMUSIC
#define OFFMUSIC

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

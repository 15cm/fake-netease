#ifndef NEXTMUSICPLAYER
#define NEXTMUSICPLAYER

#include "inextmusic.h"
#include "player.h"
class NextMusicPlayer : public INextMusic
{
public:
    void NextMusic()
    {
        Player list;
        list.NextSong();
    }
};

#endif // NEXTMUSICPLAYER


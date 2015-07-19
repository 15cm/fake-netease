#ifndef PREVIOUSMUSICPLAYER
#define PREVIOUSMUSICPLAYER

#include "ipreviousmusic.h"
#include "player.h"
class PreviousMusicPlayer : public IPreviousMusic
{
    void PreviousMusic()
    {
        Player list;
        list.LastSong();
    }
};

#endif // PREVIOUSMUSICPLAYER


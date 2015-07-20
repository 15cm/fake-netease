#ifndef PREVIOUSMUSICPLAYER
#define PREVIOUSMUSICPLAYER

#include "i_previous_music.h"
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


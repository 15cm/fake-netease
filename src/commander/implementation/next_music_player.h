#ifndef NEXTMUSICPLAYER
#define NEXTMUSICPLAYER

#include "i_next_music.h"
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


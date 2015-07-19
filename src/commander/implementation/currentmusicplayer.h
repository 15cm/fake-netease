#ifndef CURRENTMUSICPLAYER
#define CURRENTMUSICPLAYER

#include "iplaycurrentmusic.h"
#include "player.h"

class CurrentMusicPlayer : public IPlayCurrentMusic
{
public:
    void PlayCurrentMusic(int index)
    {
        Player list;
        list.playNewMusic(index);
    }
};

#endif // CURRENTMUSICPLAYER


#ifndef SELECTEDMUSICPLAYER
#define SELECTEDMUSICPLAYER

#include "iplayselectedmusic.h"
#include "player.h"
class SelectedMusicPlayer : public IPlaySelectedMusic
{
public:
    void PlaySelectedMusic(int index)
    {
        Player list;
        list.playNewMusic(index);
    }
};

#endif // SELECTEDMUSICPLAYER


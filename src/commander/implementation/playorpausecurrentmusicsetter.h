#ifndef PLAYORPAUSECURRENTMUSICSETTER
#define PLAYORPAUSECURRENTMUSICSETTER

#include "iplayorpausecurrentmusic.h"
#include "player.h"
class PlayOrPauseCurrentMusicSetter : public IPlayOrPauseCurrentMusic
{
    void PlayOrPauseCurrentMusic()
    {
        Player list;
        list.Retreat();
    }
};

#endif // PLAYORPAUSECURRENTMUSICSETTER

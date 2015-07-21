#ifndef PLAYORPAUSECURRENTMUSICSETTER
#define PLAYORPAUSECURRENTMUSICSETTER

#include "i_play_or_pause_current_music.h"
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

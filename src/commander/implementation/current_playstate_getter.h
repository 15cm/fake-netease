#ifndef CURRENTPLAYSTATEGETTER
#define CURRENTPLAYSTATEGETTER

#include "i_get_current_play_state.h"
#include "player.h"

class CurrentPlayStateGetter : public IGetCurrentPlayState
{
public:
    bool GetCurrentPlayState()
    {
        Player list;
        return list.GetPlayingState();
    }
};

#endif // CURRENTPLAYSTATEGETTER


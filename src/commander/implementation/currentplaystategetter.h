#ifndef CURRENTPLAYSTATEGETTER
#define CURRENTPLAYSTATEGETTER

#include "igetcurrentplaystate.h"
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


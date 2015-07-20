#ifndef PLAYER_TERMINATE
#define PLAYER_TERMINATE

#include "iplayer_terminate.h"
#include "player.h"
class PlayerTerminater : public IPlayerTerminate
{
public:
    void PlayerTerminate()
    {
        Player list;
        list.Release();
    }
};

#endif // PLAYER_TERMINATE


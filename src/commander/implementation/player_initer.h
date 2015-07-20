#ifndef PLAYER_INIT
#define PLAYER_INIT

#include "i_player_init.h"
#include "player.h"
class PlayerIniter : public IPlayerInit
{
public:
    void PlayerInit()
    {
        Player list;
        list.Initialize();
    }
};
#endif // PLAYER_INIT


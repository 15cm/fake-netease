#ifndef PLAYMODELCHANGER
#define PLAYMODELCHANGER

#include "i_change_play_model.h"
#include "player.h"
class PlayModleChanger : public IChangePlayModle
{
    void ChangePlayModle(int state)
    {
        Player list;
        switch(state)
        {
        case 0:list.SetLoopPlayingMode();break;
        case 1:list.SetItemLoopPlayingMode();break;
        case 2:list.SetRandomPlayingMode();break;
        }
    }
};

#endif // PLAYMODELCHANGER


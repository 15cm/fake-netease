#ifndef VOLUMESETTER
#define VOLUMESETTER

#include "i_set_volume.h"
#include "player.h"

class VolumeSetter : public ISetVolume
{
public:
    void SetVolume(int value)
    {
        Player list;
        list.SetVolume(value);
    }
};

#endif // VOLUMESETTER

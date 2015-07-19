#ifndef CURTOTALDURATIONGETTER
#define CURTOTALDURATIONGETTER

#include "igetcurrenttotalduration.h"
#include "player.h"

class CurTotalDurationGetter : public IGetCurrentTotalDuration
{
    QString GetCurrentTotalDuration()
    {
        Player list;
        return list.GetDuration();
    }
};

#endif // CURTOTALDURATIONGETTER


#ifndef CURTOTALDURATIONGETTER
#define CURTOTALDURATIONGETTER

#include "i_get_current_total_duration.h"
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


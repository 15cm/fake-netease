#ifndef SLIDER_BAR_UPDATER
#define SLIDER_BAR_UPDATER

#include "i_slider_bar_update.h"
#include "player.h"
class SliderBarUpdater : public ISliderBarUpdate
{
public:
    qint64 SliderBarUpdate(qint64 value)
    {
        Player list;
        list.SetPositon(value);
    }
};

#endif // SLIDER_BAR_UPDATER


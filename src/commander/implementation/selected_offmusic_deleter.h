#ifndef SELECTED_OFFMUSIC_DELETER
#define SELECTED_OFFMUSIC_DELETER

#include "i_delete_selected_offmusic.h"
#include "player.h"
class SelectedOffMusicDeleter : public IDelteSelectedOffMusic
{
public:
    void DeleteSelectedOffMusic(int index)
    {
        Player list;
        list.DeleteFromList(index);
    }
};

#endif // SELECTED_OFFMUSIC_DELETER


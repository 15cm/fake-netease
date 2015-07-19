#ifndef SELECTEDMUSICPLAYER
#define SELECTEDMUSICPLAYER

#include "iplayselectedmusic.h"
#include "player.h"
class SelectedMusicPlayer : public IPlaySelectedMusic
{
public:
    void PlaySelectedMusic(int index)
    {
        try
        {
            Player list;
            list.playNewMusic(index);
        }
        catch(const playNewMusicException &playnewmusicexception)
        {
            throw;
        }
        catch(const DeleteFromListException &deletefromlistexception)
        {
            throw;
        }
    }
};

#endif // SELECTEDMUSICPLAYER


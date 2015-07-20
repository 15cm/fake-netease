#ifndef SELECTEDMUSICPLAYER
#define SELECTEDMUSICPLAYER

#include "i_play_selected_music.h"
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


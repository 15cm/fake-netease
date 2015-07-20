#ifndef SELECTEDMUSICPLAYER
#define SELECTEDMUSICPLAYER

#include "i_play_selected_music.h"
#include "player.h"
class SelectedMusicPlayer :  public IPlaySelectedMusic
{
signals:
    void PlayPosChange(qint64 progress);

public:
    void PlaySelectedMusic(int index)
    {
        try
        {
            Player list;
            list.playNewMusic(index);
            /*connect(&list, &Player::PositionChanged, [=](qint64 progress){
                emit PlayPosChange(progress);
            });*/
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


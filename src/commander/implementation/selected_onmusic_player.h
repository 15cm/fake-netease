#ifndef SELECTEDONMUSICPLAYER
#define SELECTEDONMUSICPLAYER

#include "i_play_selected_onmusic.h"
#include "network.h"
#include "onmusic.h"
class SelectedOnMusicPlayer : public IPlaySelectedOnMusic
{
public:
    void PlaySelectedOnMusic(int index, QString &lrc, QImage &img, QString &name)
    {
        OnMusic onMusic = MusicSearch::vecOnMusic[index];
        LrcSearch lrcSearch(onMusic.GetId());
        lrc = lrcSearch.SearchLrc();
        ImageDownload imgDowloader(onMusic.GetPicUrl());
        img = imgDowloader.GetImage();
        Player list;
        list.PlayOnlineMusic(onMusic.GetMp3Url());
        name = onMusic.GetName();
    }
};

#endif // SELECTEDONMUSICPLAYER


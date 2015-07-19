#ifndef SELECTEDONMUSICPLAYER
#define SELECTEDONMUSICPLAYER

#include "iplayselectedonmusic.h"
#include "network.h"
#include "onmusic.h"
class SelectedOnMusicPlayer : public IPlaySelectedOnMusic
{
public:
    void PlaySelectedOnMusic(int index, QString &lrc, QImage &img)
    {
        OnMusic onMusic = MusicSearch::vecOnMusic[index];
        LrcSearch lrcSearch(onMusic.GetId());
        lrc = lrcSearch.SearchLrc();
        ImageDownload imgDowloader(onMusic.GetPicUrl());
        img = imgDowloader.GetImage();
    }
};

#endif // SELECTEDONMUSICPLAYER


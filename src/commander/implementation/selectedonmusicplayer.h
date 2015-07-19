#ifndef SELECTEDONMUSICPLAYER
#define SELECTEDONMUSICPLAYER

#include "iplayselectedonmusic.h"
#include "network.h"
#include "onmusic.h"
class SelectedOnMusicPlayer : public IPlaySelectedOnMusic
{
public:
    void PlaySelectedOnMusic(int index, QString &lrc, QUrl &imgPath)
    {
        OnMusic onMusic = MusicSearch::vecOnMusic[index];
        LrcSearch lrcSearch(onMusic.GetId());
        lrc = lrcSearch.SearchLrc();
    }
};

#endif // SELECTEDONMUSICPLAYER


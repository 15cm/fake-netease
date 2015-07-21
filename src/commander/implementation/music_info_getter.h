#ifndef MUSICLRCGETTER
#define MUSICLRCGETTER

#include "i_get_music_info.h"
#include "network.h"
class MusicInfoGetter : public IGetMusicInfo
{
public:
    void GetMusicInfo(QString name,QString &lrc, QImage &img)
    {
        MusicSearch mSearch(name);
        QString id;
        QUrl imgUrl;
        mSearch.MusicInfo(id,imgUrl);
        ImageDownload dowloader(imgUrl);
        img = dowloader.GetImage();
        LrcSearch lrcSearch(id);
        lrc = lrcSearch.SearchLrc();
    }
};

#endif // MUSICLRCGETTER


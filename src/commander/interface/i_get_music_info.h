#ifndef I_GET_MUSIC_LRC
#define I_GET_MUSIC_LRC

#include <QString>
#include <QUrl>
class IGetMusicInfo
{
public:
    virtual void GetMusicInfo(QString name,QString &lrc, QImage &img) = 0;
};

#endif // I_GET_MUSIC_LRC


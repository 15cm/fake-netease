#ifndef IPLAYSELECTEDONMUSIC
#define IPLAYSELECTEDONMUSIC

#include <QString>
#include <QUrl>
#include <QImage>
class IPlaySelectedOnMusic
{
public:
    virtual void PlaySelectedOnMusic(int index, QString &lrc, QImage &img) = 0;
};

#endif // IPLAYSELECTEDONMUSIC


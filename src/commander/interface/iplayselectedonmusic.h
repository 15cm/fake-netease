#ifndef IPLAYSELECTEDONMUSIC
#define IPLAYSELECTEDONMUSIC

#include <QString>
#include <QUrl>
class IPlaySelectedOnMusic
{
public:
    virtual void PlaySelectedOnMusic(int index, QString &lrc, QUrl &imgPath) = 0;
};

#endif // IPLAYSELECTEDONMUSIC


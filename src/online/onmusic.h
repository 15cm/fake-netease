#ifndef ONMUSIC
#define ONMUSIC

#include "music.h"
#include "commander.h"
// online music
class OnMusic:public Music
{
private:
    bool isStarred;
    QUrl picUrl;
    QString id;
    QString lrc;
public:
    OnMusic(){}
    OnMusic(bool _is, QString _name,QString _artist, QString _album, qint64 _duration, QUrl _mp3Url, QUrl _picUrl,QString _id):
        Music(_name,_duration,_mp3Url,_artist,_album),
        isStarred(_is),
        picUrl(_picUrl),
        id(_id)
        {
        }
    OnMusic(const OnMusic &rhs):
        Music(rhs.GetName(),rhs.GetDuration(),rhs.GetMp3Url(),rhs.GetArtist(),rhs.GetAlbum()),
        isStarred(rhs.IsStarred()),
        picUrl(rhs.GetPicUrl()),
        id(rhs.GetId())
    {
    }
    bool IsStarred() const{return isStarred;}
    QUrl GetPicUrl() const{return picUrl;}
    QString GetId() const{return id;}
    void SetLrc(QString _lrc){lrc = _lrc;}
    QString GetLrc(){return lrc;}
};
#endif // ONMUSIC

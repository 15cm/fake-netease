#ifndef MUSIC
#define MUSIC

#include <QString>
#include <QUrl>
class Music
{

protected:  //hdj:These members should be accessible to derived class such as OffMusic, so I change them to protected
    QString name;
    qint64 duration;
    QUrl mp3Url;
    QString artist;
    QString album;
public:
    Music(){}
    Music(QString _name, qint64 _duration, QUrl _url, QString _artist = QString("Not Found"), QString _album = QString("Not Found"))
        :name(_name),
         duration(_duration),
         mp3Url(_url),
         artist(_artist),
         album(_album)
    {
    }
    QString GetName() const{return name;}
    qint64 GetDuration() const{return duration;}
    QString GetDurationStr () const
    {
        int second = duration / 1000 % 60;
        int minute = duration /1000 / 60;
        QString sec;
        if(second < 10)
            sec.append("0");
        sec.append(QString::number(second, 10));
        QString min = QString::number(minute, 10);
        return QString(min.append(":").append(sec));
    }
    QUrl GetMp3Url() const{return mp3Url;}
    QString GetArtist() const{return artist;}
    QString GetAlbum() const{return album;}
    virtual ~Music(){}
};


#endif // MUSIC


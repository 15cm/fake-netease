#ifndef MUSIC
#define MUSIC

#include <QString>
#include <QUrl>
class Music
{
private:
    QString name;
    qint64 duration;
    QUrl mp3Url;
public:
    Music(){}
    Music(QString _name, qint64 _duration, QUrl _url):name(_name),duration(_duration),mp3Url(_url){}
    QString GetName() const{return name;}
    qint64 GetDuration() const{return duration;}
    QString GetDurationStr () const
    {
        int second = duration / 1000 % 60;
        int minute = duration /1000 / 60;
        QString sec = QString::number(second, 10);
        QString min = QString::number(minute, 10);
        return QString(min.append(":").append(sec));
    }
    QUrl GetMp3Url() const{return mp3Url;}
    virtual ~Music(){}
};


#endif // MUSIC


#ifndef PLAYLISTRECORD
#define PLAYLISTRECORD

#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QMediaPlaylist>
#include <QException>

class SyncPlaylistFail : public QException
{
public:
    const QString message = "Synchronize ListRecord.json fail.";
    void raise() const { throw *this; }
    SyncPlaylistFail *clone() const { return new SyncPlaylistFail(*this); }
};

class PlaylistRecord
{
private:
    QJsonDocument json;
public:
    PlaylistRecord()
    {
        QFile file("PlaylistRecord.json");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
            json = QJsonDocument::fromBinaryData(file.readAll());
    }

    virtual ~PlaylistRecord() {}

    void InitMediaList(QMediaPlaylist* playlist)
    {
        QJsonArray jsonarr = json.array();
        for(int index = 0; index < jsonarr.size(); index++ )
        {
            QUrl url(jsonarr[index].toString());
            playlist->addMedia(url);
        }
    }

    void SyncMediaList(const QMediaPlaylist* playlist)
    {
        QJsonArray jsonarr;
        int cnt = playlist->mediaCount();
        for(int index = 0; index < cnt; index++)
        {
            QUrl url(playlist->media(index).canonicalUrl());
            jsonarr.append(url.toString());
        }
        json.setArray(jsonarr);
        QByteArray byteArr = json.toBinaryData();
        QFile file("PlaylistRecord.json");
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            file.write(byteArr);
        }
        else
        {
            throw SyncPlaylistFail();
        }
    }

};

#endif // PLAYLISTRECORD


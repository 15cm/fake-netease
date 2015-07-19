#ifndef NETWORK
#define NETWORK


#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QByteArray>
#include <QString>
#include <QUrl>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QException>
#include <QVector>
#include <QEventLoop>
#include <QImage>
#include "onmusic.h"


#include <QFile>
#include <QTextStream>


class NetworkConnectionException : public QException
{
public:
    void raise() const { throw *this; }
    NetworkConnectionException *clone() const { return new NetworkConnectionException(*this); }
};

class SearchNotFoundException : public QException
{
public:
    void raise() const {throw *this;}
    SearchNotFoundException *clone() const {return new SearchNotFoundException(*this);}
};

//search
class Search :public QObject
{
private:
    QUrl apiUrl;
protected:
    QString query;
    QByteArray postData;
    QJsonObject searchObj;
public:
    const static char *NEHOST;
    Search(){}
    Search(QString _query):query(_query){}
    virtual void MakePostData()
    {
        postData.clear();
        postData.append("s=");
        postData.append(query);
        postData.append("&offset=0");
        postData.append("&limit=50");
    }
    void SetApiForSearch()
    {
        apiUrl.clear();
        apiUrl = QUrl(QString(NEHOST).append("api/search/pc"));
    }

    void SetApiForLrc()
    {
        apiUrl.clear();
        apiUrl = QUrl(QString(NEHOST).append("api/song/lyric"));
    }

    void Dosearch()
    {
       QNetworkAccessManager *manager = new QNetworkAccessManager();
       QNetworkRequest *request = new QNetworkRequest(QUrl(apiUrl));
       request->setRawHeader(QByteArray("Referer"),QByteArray(NEHOST));
       request->setRawHeader(QByteArray("content-type"),QByteArray("application/x-www-form-urlencoded"));
       request->setRawHeader(QByteArray("Cookie"),QByteArray("appver=1.5.0.75771;"));
       QNetworkReply *reply = manager->post(*request,postData);
       // wait for reply finished
       QEventLoop loop;
       connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
       loop.exec();
       // reply finished
       if(reply->error() != QNetworkReply::NoError)
           throw(NetworkConnectionException());
       QByteArray resultInByte = reply->readAll();

//       //test: output json
//       QString testStr = QString(resultInByte);
//       QFile file("/Users/a15/Desktop/networktest.json");
//       file.open(QIODevice::WriteOnly);
//       QTextStream out(&file);
//       out << testStr;
//       file.flush();
//       file.close();
//       end of output json
       QJsonDocument parse_document = QJsonDocument::fromJson(resultInByte);
       searchObj = parse_document.object();
       if(searchObj.empty())
           throw(SearchNotFoundException());
    }
};
const char *Search::NEHOST = "http://music.163.com/";

// music search
class MusicSearch:public Search
{
public:
    static QVector<OnMusic> vecOnMusic;
    MusicSearch(){}
    MusicSearch(const QString &query):Search(query){}
    void MakePostData()
    {
        postData.clear();
        Search::MakePostData();
        postData.append("&type=1");
    }
    void MakePostData(QString id)
    {
        postData.clear();
        postData.append("id=");
        postData.append(id);
        postData.append("&lv=-1&kv=-1&tv=-1");
    }

    void GetMusicList()
    {
        this->MakePostData();
        try{
            vecOnMusic.clear();
            Search::SetApiForSearch();
            this->Dosearch();
            QJsonObject resultObj = searchObj["result"].toObject();
            QJsonArray songArray = resultObj["songs"].toArray();
            foreach(QJsonValue val, songArray){
                QJsonObject song = val.toObject();
                bool isStarred = song["starred"].toBool();
                QString id = QString::number(song["id"].toInt(),10);
                QString name = song["name"].toString();
                QString artist;
                QJsonArray artistsArray = song["artists"].toArray();
                foreach(QJsonValue artistVal, artistsArray){
                    QJsonObject artistObj = artistVal.toObject();
                    artist.append(artistObj["name"].toString().append(' '));
                }
                QJsonObject albumObj = song["album"].toObject();
                QString album = albumObj["name"].toString();
                qint64 duration = song["duration"].toInt();
                QUrl mp3Url(song["mp3Url"].toString());
                QUrl picUrl(albumObj["picUrl"].toString());
                vecOnMusic.push_back(OnMusic(isStarred,name,artist,album,duration,mp3Url,picUrl,id));
            }
        }
        catch(NetworkConnectionException &e){
            vecOnMusic.clear();
        }
        catch(SearchNotFoundException &e){
            vecOnMusic.clear();
        }
    }
};

class LrcSearch : public Search
{
public:
    LrcSearch();
    LrcSearch(QString _query):Search(_query){}
    void MakePostData()
    {
        postData.clear();
        postData.append("id=");
        postData.append(query);
        postData.append("&lv=-1&kv=-1&tv=-1");
    }


    QString SearchLrc()
    {
        Search::SetApiForLrc();
        this->MakePostData();
        Search::Dosearch();
        if(!searchObj.contains("lrc"))
            return QString("");
        QJsonObject lrcObj = searchObj["lrc"].toObject();
        return lrcObj["lyric"].toString();
    }
};

class ImageDownload : QObject
{
private:
    QUrl imgUrl;
public:
    ImageDownload(QUrl _imgUrl):imgUrl(_imgUrl){}
    QImage GetImage()
    {
        QNetworkAccessManager *manager = new QNetworkAccessManager;
        const QNetworkRequest request(imgUrl);
        QNetworkReply *reply = manager->get(request);
        // wait for reply finished
        QEventLoop loop;
        connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
        loop.exec();
        // reply finished
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        }
        QByteArray imgData = reply->readAll();
        QImage img;
        img.loadFromData(imgData);
        return img;
    }
};

QVector<OnMusic> MusicSearch::vecOnMusic;



#endif // NETWORK

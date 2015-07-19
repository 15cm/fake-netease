#ifndef PLAYER
#define PLAYER

#include <QObject>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>
#include <QString>
#include <QException>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QTime>
#include "playlistrecord.h"

class AddToListException : public QException
{
public:
    void raise() const {throw *this;}
    AddToListException *clone() const{return new AddToListException(*this);}
};

class playNewMusicException : public QException
{
    void raise() const {throw *this;}
    playNewMusicException *clone() const{return new playNewMusicException(*this);}
};

class DeleteFromListException : public QException
{
    void raise() const {throw *this;}
    DeleteFromListException *clone() const{return new DeleteFromListException(*this);}
};

class Player : public QObject
{
    Q_OBJECT
private:
    static QMediaPlayer *MediaPlayer;
    static QMediaPlaylist *MediaPlayerlist;

signals:
    void DurationChanged(qint64 duration);
    void PositionChanged(qint64 progress);

public:
    Player(QObject* parent = 0)
        :QObject(parent)
    {
        MediaPlayerlist = new QMediaPlaylist();
        MediaPlayer = new QMediaPlayer();
        MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Loop);
        MediaPlayer->setPlaylist(MediaPlayerlist);
        MediaPlayer->setVolume(20);
        initilizeSong();

        connect(MediaPlayer,&QMediaPlayer::durationChanged, [=](qint64 duration)
        {
           emit DurationChanged(duration);
        });
        connect(MediaPlayer, &QMediaPlayer::positionChanged, [=](qint64 progress)
        {
            emit PositionChanged(progress);
        });
    }

    ~Player(){}

    //first start the player to initialize the playlist
    void initilizeSong()
    {
        InitMediaList(MediaPlayerlist);
    }

    //To get the playing state(true while playing, or false)
    bool GetPlayingState(){
        if(MediaPlayer->state()==QMediaPlayer::PlayingState)
            return true;
        else
            return false;
    }

    //set the playing mode loop
    void SetLoopPlayingMode(){
         MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Loop);
    }

    //set the playing mode sequential
    void SetSequentialPlayingMode(){
         MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Sequential);
    }

    //set the playing mode random
    void SetRandomPlayingMode(){
        MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Random);
    }

    //set the player volume
    void SetVolume(int volume){
        MediaPlayer->setVolume(volume);
    }

    //To get the duration of the current playing music
    QString GetDuration()
    {
        const qint64 progress = MediaPlayer->duration();
        QTime t = QTime::fromMSecsSinceStartOfDay(progress);
        return t.toString();
    }

//    QString GetCurrentProgress()
//    {
//        qint64 progress = MediaPlayer->position();
//        QTime t = QTime::fromMSecsSinceStartOfDay(progress);
//        return t.toString();
//    }

    //set the progress of the music play
    void SetPositon(qint64 progress)
    {
        //qint64 position = percent*1.0/100 * GetDuration();
        MediaPlayer->setPosition(progress);
    }

    //add a musci to the list
    void AddLocalMusic()
    {
        QUrl url = QFileDialog::getOpenFileUrl(0, QObject::tr("Open Music File"), QObject::tr("."), QObject::tr("mp3 music files(*.mp3)"));
        QFileInfo info(url.toLocalFile());
        QUrl fileurl(info.absoluteFilePath());
        if(!MediaPlayerlist->addMedia(fileurl))
             throw (AddToListException());
    }

    void AddLocalMusicFolder()
    {
        QUrl url = QFileDialog::getExistingDirectoryUrl(0, QObject::tr("Open Music File Folder"));
        QDir dir(url.toLocalFile());
        QStringList filter;
        filter << "*.mp3";
        QFileInfoList list = dir.entryInfoList(filter);
        foreach(QFileInfo info, list)
        {
            QUrl fileurl(info.absoluteFilePath());
            if(!MediaPlayerlist->addMedia(fileurl))
                throw (AddToListException());
        }
    }

    //play a new music
    void playNewMusic(int Index){
        MediaPlayerlist->setCurrentIndex(Index);
        QString path = MediaPlayer->currentMedia().canonicalUrl().toString();
        if(!QFile::exists(path))
        {
            DeleteFromList(Index);
            throw playNewMusicException();
        }
        MediaPlayer->play();
    }

    void DeleteFromList(int Index)
    {
        if(!MediaPlayerlist->removeMedia(Index));
            throw (DeleteFromListException());
    }

    //Go on or pause
    void Retreat(){
        //no music is playing and playing list is not null and playing first music
        if(MediaPlayer->state()==QMediaPlayer::StoppedState && !MediaPlayerlist->isEmpty())
            playNewMusic(0);
        //music is playing and
        else if(MediaPlayer->state()==QMediaPlayer::PausedState)
            MediaPlayer->play();
        else if(MediaPlayer->state()==QMediaPlayer::PlayingState)
            MediaPlayer->pause();

        qDebug() << "Retreat";
    }

    //next song
    void NextSong(){
        int NextIndex = MediaPlayerlist->nextIndex();
        playNewMusic(NextIndex);
    }

    //last song
    void LastSong(){
        int PreviouseIndex = MediaPlayerlist->previousIndex();
        playNewMusic(PreviouseIndex);
    }

    void Release(){
        SyncMediaList(MediaPlayerlist);
        delete MediaPlayer;
        delete MediaPlayerlist;
    }
};

#endif // Player

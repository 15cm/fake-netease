#ifndef PLAYER
#define PLAYER

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>
#include <QString>
#include <QException>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include "playlistrecord.h"
#include "binder.h"

class AddToListException : public QException
{
public:
    void raise() const {throw *this;}
    AddToListException *clone() const{return new AddToListException(*this);}
};

class Player : public Binder
{
private:
    QMediaPlayer *MediaPlayer;
    QMediaPlaylist *MediaPlayerlist;
   // PlaylistRecord record;

signals:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);

public:
    Player(){
        MediaPlayerlist = new QMediaPlaylist();
        MediaPlayer = new QMediaPlayer();
        MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Loop);
        MediaPlayer->setPlaylist(MediaPlayerlist);
        MediaPlayer->setVolume(20);
        //initilizeSong();
//        connnect(MediaPlayer,QMediaPlayer::durationChanged, [=](qint64 duration)
//        {
//           emit durationChanged(duration);
//        });
//        connetc(MediaPlayer, QMediaPlayer::positionChanged, [=](qint64 progress)
//        {
//            emit positionChanged(progress);
//        });
    }

    ~Player()
    {
        //record.SyncMediaList(MediaPlayerlist);
    }

    //first start the player to initialize the playlist
    void initilizeSong()
    {
       // record.InitMediaList(MediaPlayerlist);
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
    qint64 GetDuration()
    {
        return MediaPlayer->duration();
    }

    //set the progress of the music play
    void SetPositon(qint64 percent)
    {
        qint64 position = percent*1.0/100 * GetDuration();
        MediaPlayer->setPosition(position);
    }

    //add a musci to the list
    void AddLocalMusic()
    {
        QUrl url = QFileDialog::getOpenFileUrl(this, QObject::tr("Open Music File"), QObject::tr("."), QObject::tr("mp3 music files(*.mp3)"));
        if(url.isLocalFile())
        {
            if(!MediaPlayerlist->addMedia(url))
                throw (AddToListException());
        }
//        else
//        {
//            QDir dir(url);

//        }
    }

    //play a new music
    void playNewMusic(int Index){
        MediaPlayerlist->setCurrentIndex(Index);
        QString Path = MediaPlayer->currentMedia().canonicalUrl().toString();
        if(!QFile::exists(Path))
        {

        }
        MediaPlayer->play();
    }

    //Go on or pause
    void Retreat(){
        //no music is playing and playing list is not null and playing first music
        if(MediaPlayer->state()==QMediaPlayer::StoppedState && !MediaPlayerlist->isEmpty())
            playNewMusic(0);
        //music is playing and
        else if(MediaPlayer->state()==QMediaPlayer::PlayingState)
            MediaPlayer->play();
        else if(MediaPlayer->state()==QMediaPlayer::PausedState)
            MediaPlayer->pause();
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
};

#endif // Player


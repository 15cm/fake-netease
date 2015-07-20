#ifndef PLAYER_H
#define PLAYER_H

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
#include "OffMusic.h"
#include <QVector>
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

class AlreadyInListException : public QException
{
    void raise() const {throw *this;}
    AlreadyInListException *clone() const{return new AlreadyInListException(*this);}
};


class Player : public QObject
{
    Q_OBJECT
private:
   static QMediaPlayer MediaPlayer;
   static QMediaPlaylist MediaPlayerlist;
   //static bool flag;

signals:
    void DurationChanged(qint64 duration);
    void PositionChanged(qint64 progress);

public:
    Player(QObject* parent = 0);

    void Initialize();

    ~Player();

    //first start the player to initialize the playlist
    void initilizeSong();

    //To get the playing state(true while playing, or false)
    bool GetPlayingState();

    //set the playing mode loop
    void SetLoopPlayingMode();

    //set the playing mode sequential
    void SetSequentialPlayingMode();

    //set the playing mode random
    void SetRandomPlayingMode();

    //set the player volume
    void SetVolume(int volume);


    //To get the duration of the current playing music
    QString GetDuration();

//    QString GetCurrentProgress()
//    {
//        qint64 progress = MediaPlayer.position();
//        QTime t = QTime::fromMSecsSinceStartOfDay(progress);
//        return t.toString();
//    }

    //set the progress of the music play
    void SetPositon(qint64 progress);

    //add a musci to the list
    OffMusic AddLocalMusic();

    QVector<OffMusic> AddLocalMusicFolder();

    //play a new music
    void playNewMusic(int Index);

    void DeleteFromList(int Index);

    //Go on or pause
    void Retreat();

    //next song
    void NextSong();

    //last song
    void LastSong();

    void Release();

    //check if url is already in playlist
    bool InList(QUrl url);

};

#endif // Player

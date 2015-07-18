#ifndef PLAYER
#define PLAYER

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>
#include <QString>
#include <QException>
#include <QFile>

class AddToListException : public QException
{
public:
    void raise() const {throw *this;}
    AddToListException *clone() const{return new AddToListException(*this);}
};

class Player
{
private:
    QMediaPlayer *MediaPlayer;
    QMediaPlaylist *MediaPlayerlist;
public:
    Player(){
        MediaPlayerlist = new QMediaPlaylist();
        MediaPlayer = new QMediaPlayer();
        MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Loop);
        MediaPlayer->setPlaylist(MediaPlayerlist);
    }

    ~Player(){}
    bool GetPlayingState(){
        if(MediaPlayer->state()==QMediaPlayer::PlayingState)
            return true;
        else
            return false;
    }

    void SetLoopPlayingMode(){
         MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Loop);
    }

    void SetSequentialPlayingMode(){
         MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Sequential);
    }

    void SetRandomPlayingMode(){
        MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Random);
    }

    void SetVolume(int volume){
        MediaPlayer->setVolume(volume);
    }

    void initilizeSong(){

    }

    void addToList(QUrl url){
        if(!MediaPlayerlist->addMedia(url))
            throw (AddToListException());
    }

    void playNewMusic(int Index){
        MediaPlayerlist->setCurrentIndex(Index);
        QString Path = MediaPlayer->currentMedia().canonicalUrl().toString();
        if(!QFile::exists(Path))
        {

        }
        MediaPlayer->play();
    }

    void Retreat(){
        //no music is playing and playing list is not null and playing first music
        if(MediaPlayer->state()== QMediaPlayer::StoppedState && !MediaPlayerlist->isEmpty())
            playNewMusic(0);
        //music is playing and
        else if(MediaPlayer->state()==QMediaPlayer::PausedState)
            MediaPlayer->play();
        else if(MediaPlayer->state()==QMediaPlayer::PlayingState)
            MediaPlayer->pause();
    }

    void NextSong(){
        int NextIndex = MediaPlayerlist->nextIndex();
        playNewMusic(NextIndex);
    }

    void LastSong(){
        int PreviouseIndex = MediaPlayerlist->previousIndex();
        playNewMusic(PreviouseIndex);
    }
};

#endif // Player


#ifndef PLAYER
#define PLAYER

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>

class Player
{

private:
    QMediaPlayer *MediaPlayer;
    QMediaPlaylist *MediaPlayerlist;
public:
    Player();
    ~Player(){}
    bool GetPlayingState();
    void SetLoopPlayingMode();
    void SetSequentialPlayingMode();
    void SetRandomPlayingMode();
    void SetVolume(int volume);
    void initilizeSong();
    void addToList(QUrl url);
    void playNewMusic(int Index);
    void Retreat();
    void NextSong();
    void LastSong();
};

Player::Player()
{
    MediaPlayerlist = new QMediaPlaylist();
    MediaPlayer = new QMediaPlayer();
    MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Loop);
    MediaPlayer->setPlaylist(MediaPlayerlist);
}

bool Player::GetPlayingState()
{
    if(MediaPlayer->state()==QMediaPlayer::PlayingState)
        return true;
    else
        return false;
}

//set playing mode(loop, sequential, random)
void Player::SetLoopPlayingMode()
{
    MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Loop);
}

void Player::SetSequentialPlayingMode()
{
    MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Sequential);
}

void Player::SetRandomPlayingMode()
{
    MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Random);
}

void Player::SetVolume(int volume)
{
    MediaPlayer->setVolume(volume);
}

void Player::addToList(QUrl url)
{
    MediaPlayerlist->addMedia(url);
}

void Player::playNewMusic(int Index)
{
    MediaPlayerlist->setCurrentIndex(Index);
    MediaPlayer->play();
}

//Go on or Pause
void Player::Retreat()
{
    //no music is playing and playing list is not null and playing first music
    if(MediaPlayer->currentMedia().isNull() && !MediaPlayerlist->isEmpty())
        playNewMusic(0);
    //music is playing and
    else if(MediaPlayer->state()==QMediaPlayer::PlayingState)
        MediaPlayer->play();
    else if(MediaPlayer->state()==QMediaPlayer::PausedState)
        MediaPlayer->pause();
}

//next song
void Player::NextSong()
{
    int NextIndex = MediaPlayerlist->nextIndex();
    playNewMusic(NextIndex);
}

//last song
void Player::LastSong()
{
    int PreviouseIndex = MediaPlayerlist->previousIndex();
    playNewMusic(PreviouseIndex);
}

#endif // Player


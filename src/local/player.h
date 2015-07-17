#ifndef MUSICLIST
#define MUSICLIST

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>

class Player : public QObject
{
private:
    QMediaPlayer *MediaPlayer;
    QMediaPlaylist *MediaPlayerlist;
public:
    Player();
    ~Player();
    void initilizeSong();
    void addToList(QUrl url);
    void playNewMusic(int index);
    void retreat(int index);
};

Player::Player()
{
    MediaPlayerlist = new QMediaPlaylist(this);
    MediaPlayer = new QMediaPlayer(this);
    MediaPlayerlist->setPlaybackMode(QMediaPlaylist::Loop);
    MediaPlayer->setPlaylist(MediaPlayerlist);
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

#endif // MUSICLIST


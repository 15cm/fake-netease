#include "player.h"

QMediaPlayer Player::MediaPlayer;
QMediaPlaylist Player::MediaPlayerlist;

Player::Player(QObject* parent)
    :QObject(parent)
{
    MediaPlayerlist.setPlaybackMode(QMediaPlaylist::Loop);
    MediaPlayer.setPlaylist(&MediaPlayerlist);
    MediaPlayer.setVolume(20);
    initilizeSong();

    connect(&MediaPlayer,&QMediaPlayer::durationChanged, [=](qint64 duration)
    {
       emit DurationChanged(duration);
    });
    connect(&MediaPlayer, &QMediaPlayer::positionChanged, [=](qint64 progress)
    {
        emit PositionChanged(progress);
    });
}

Player::~Player(){}

//first start the player to initialize the playlist
void Player::initilizeSong()
{
    InitMediaList(&MediaPlayerlist);
}

//To get the playing state(true while playing, or false)
bool Player::GetPlayingState(){
    if(MediaPlayer.state()==QMediaPlayer::PlayingState)
        return true;
    else
        return false;
}

//set the playing mode loop
void Player::SetLoopPlayingMode(){
     MediaPlayerlist.setPlaybackMode(QMediaPlaylist::Loop);
}

//set the playing mode sequential
void Player::SetSequentialPlayingMode(){
     MediaPlayerlist.setPlaybackMode(QMediaPlaylist::Sequential);
}

//set the playing mode random
void Player::SetRandomPlayingMode(){
    MediaPlayerlist.setPlaybackMode(QMediaPlaylist::Random);
}

//set the player volume
void Player::SetVolume(int volume){
    MediaPlayer.setVolume(volume);
}

//To get the duration of the current playing music
QString Player::GetDuration()
{
    const qint64 progress = MediaPlayer.duration();
    QTime t = QTime::fromMSecsSinceStartOfDay(progress);
    return t.toString();
}

//set the progress of the music play
void Player::SetPositon(qint64 progress)
{
    //qint64 position = percent*1.0/100 * GetDuration();
    MediaPlayer.setPosition(progress);
}

//add a musci to the list
void Player::AddLocalMusic()
{
    QUrl fileurl = QFileDialog::getOpenFileUrl(0, QObject::tr("Open Music File"), QObject::tr("."), QObject::tr("mp3 music files(*.mp3)"));
    if(!MediaPlayerlist.addMedia(fileurl))
         throw (AddToListException());
     qDebug() << "media count " << MediaPlayerlist.mediaCount();
}

void Player::AddLocalMusicFolder()
{
    qDebug() << "media count " << MediaPlayerlist.mediaCount();
    QUrl url = QFileDialog::getExistingDirectoryUrl(0, QObject::tr("Open Music File Folder"));
    QDir dir(url.toLocalFile());
    QStringList filter;
    filter << "*.mp3";
    QFileInfoList list = dir.entryInfoList(filter);
    foreach(QFileInfo info, list)
    {
        QUrl fileurl = QUrl::fromLocalFile(info.absoluteFilePath());
        if(!MediaPlayerlist.addMedia(fileurl))
            throw (AddToListException());
        qDebug() << fileurl;
    }
    int cnt = MediaPlayerlist.mediaCount();
    for(int index = 0; index < cnt; index++)
    {
        qDebug() << MediaPlayerlist.media(index).canonicalUrl();
    }
    //hdj
    qDebug() << "media count " << MediaPlayerlist.mediaCount();
}

//play a new music
void Player::playNewMusic(int Index){
    MediaPlayerlist.setCurrentIndex(Index);
    qDebug() << MediaPlayer.currentMedia().canonicalUrl();
    QUrl url = MediaPlayer.currentMedia().canonicalUrl();
    if(!QFile::exists(url.toLocalFile()))
    {
        DeleteFromList(Index);
        throw playNewMusicException();
    }
    else
        MediaPlayer.play();
}

void Player::DeleteFromList(int Index)
{
    if(!MediaPlayerlist.removeMedia(Index))
        throw (DeleteFromListException());
}

//Go on or pause
void Player::Retreat(){
    //no music is playing and playing list is not null and playing first music
    if(MediaPlayer.state()==QMediaPlayer::StoppedState && !MediaPlayerlist.isEmpty())
        playNewMusic(0);
    //music is playing and
    else if(MediaPlayer.state()==QMediaPlayer::PausedState)
        MediaPlayer.play();
    else if(MediaPlayer.state()==QMediaPlayer::PlayingState)
        MediaPlayer.pause();

    qDebug() << "Retreat";
}

//next song
void Player::NextSong(){
    int NextIndex = MediaPlayerlist.nextIndex();
    playNewMusic(NextIndex);
}

//last song
void Player::LastSong(){
    int PreviouseIndex = MediaPlayerlist.previousIndex();
    playNewMusic(PreviouseIndex);
}

void Player::Release(){
    SyncMediaList(&MediaPlayerlist);
}

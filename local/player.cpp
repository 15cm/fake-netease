#include "player.h"

QMediaPlayer Player::MediaPlayer;
QMediaPlaylist Player::MediaPlayerlist;
//void Player::DurationChanged(qint64 duration){}
//void Player::PositionChanged(qint64 progress){}
/*
Player::Player(QObject* parent)
    :QObject(parent)
{

    if(!flag)
    {
        MediaPlayerlist.setPlaybackMode(QMediaPlaylist::Loop);
        if(!&MediaPlayerlist)
            qDebug() << "NULL";
        //qDebug() << Media
        MediaPlayer.setPlaylist(&MediaPlayerlist);
        MediaPlayer.setVolume(20);
        initilizeSong();
//        connect(&MediaPlayer,&QMediaPlayer::durationChanged, [=](qint64 duration)
//        {
//           emit DurationChanged(duration);
//        });
//        connect(&MediaPlayer, &QMediaPlayer::positionChanged, [=](qint64 progress)
//        {
//            emit PositionChanged(progress);
//        });
        flag = 1;
    }
//    if(MediaPlayer.state()==QMediaPlayer::StoppedState){
//        qDebug() << "stop state";
//    }
//    else if(MediaPlayer.state()==QMediaPlayer::PlayingState){
//        qDebug() << "playing state";
//    }
//    else {
//        qDebug() << "pause state";
//    }


}*/
Player::Player(QObject* parent)
    :QObject(parent)
{
    //do nothing
}

void Player::Initialize(QVector<OffMusic> &qvec)
{
    MediaPlayerlist.setPlaybackMode(QMediaPlaylist::Loop);
    if(!&MediaPlayerlist)
        qDebug() << "NULL";
    //set again
    MediaPlayer.setPlaylist(&MediaPlayerlist);
    MediaPlayer.setVolume(20);
    //initilizeSong();
    InitMediaList(&MediaPlayerlist, qvec);

}

Player::~Player(){}

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
void Player::AddLocalMusic(OffMusic &offmusic, int &index)
{
    //add to list
    QUrl fileurl = QFileDialog::getOpenFileUrl(0, QObject::tr("Open Music File"), QObject::tr("."), QObject::tr("mp3 music files(*.mp3)"));
    if(InList(fileurl) || fileurl.isEmpty())
    {
        throw AlreadyInListException();
        qDebug() << "media count " << MediaPlayerlist.mediaCount();
    }
    if(!MediaPlayerlist.addMedia(fileurl))
        throw AddToListException();
    qDebug() << "media count " << MediaPlayerlist.mediaCount();
    OffMusic omus(fileurl);
    offmusic = omus;
    index = MediaPlayerlist.mediaCount();
    qDebug() << "index" << index;
}

QVector<OffMusic> Player::AddLocalMusicFolder()
{
    qDebug() << "media count " << MediaPlayerlist.mediaCount();
    QUrl url = QFileDialog::getExistingDirectoryUrl(0, QObject::tr("Open Music File Folder"));
    QDir dir(url.toLocalFile());
    QStringList filter;
    filter << "*.mp3";
    QFileInfoList list = dir.entryInfoList(filter);
    QVector<OffMusic> qvec;
    foreach(QFileInfo info, list)
    {
        QUrl fileurl = QUrl::fromLocalFile(info.absoluteFilePath());
        if(!InList(fileurl))
        {
            if(!MediaPlayerlist.addMedia(fileurl))
                throw (AddToListException());
            qDebug() << fileurl;
            OffMusic omus(fileurl);
            qvec.append(omus);
        }
    }
    int cnt = MediaPlayerlist.mediaCount();
    for(int index = 0; index < cnt; index++)
    {
        qDebug() << MediaPlayerlist.media(index).canonicalUrl();
    }

    qDebug() << "media count " << MediaPlayerlist.mediaCount();

    return qvec;
}

//play a new music
void Player::playNewMusic(int Index){
    qDebug() << "before set" ;
    MediaPlayer.setPlaylist(&MediaPlayerlist);
    MediaPlayerlist.setCurrentIndex(Index);
    qDebug() << MediaPlayer.currentMedia().canonicalUrl();
    QUrl url = MediaPlayer.currentMedia().canonicalUrl();
    if(!QFile::exists(url.toLocalFile()))
    {
        try
        {
            DeleteFromList(Index);
        }
        catch(const DeleteFromListException &deletefromlistexception)
        {
            throw;
        }

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

bool Player::InList(QUrl url)
{
    int cnt = MediaPlayerlist.mediaCount();
    for( int index = 0 ; index < cnt ; index++)
    {
        qDebug() << "url: " << url;
        qDebug() << "media_url: " << MediaPlayerlist.media(index).canonicalUrl();
        if(url == MediaPlayerlist.media(index).canonicalUrl())
            return true;
    }
    return false;
}

void Player::PlayOnlineMusic(QUrl url)
{
    qDebug() << "set before" << url;
    MediaPlayer.setMedia(url);
    qDebug() << "after set" << url;
    MediaPlayer.play();
    qDebug() << "play online music" << url;
}

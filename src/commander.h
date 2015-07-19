#ifndef COMMANDER
#define COMMANDER


#include <QVector>
#include <QTableWidget>
// Commander
class Commander
{
    virtual void AddLocalMusic() = 0;
    virtual void AddLocalMusicFolder() = 0;
    virtual bool GetPlayingState() = 0;
    virtual void SetVolume(int value) = 0;
    virtual QVector<bool> FillLOnlineMusicList(QTableWiget *pTable,const QString &query);
};
#endif // COMMANDER


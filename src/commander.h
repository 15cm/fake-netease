#ifndef COMMANDER
#define COMMANDER


#include "localmusicadder.h"
#include "localmusicfolderadder.h"
#include "currentmusicplayer.h"
#include "volumesetter.h"
#include "ontablefiller.h"
// Commander
class Commander
{
public:
    void AddLocalMusic()
    {
        IAddLocalMusic *pLocalMusicAdder = new LocalMusicAdder();
        pLocalMusicAdder->AddLocalMusic();
        delete pLocalMusicAdder;
    }
    void AddLocalMusicFolder()
    {
        IAddLocalMusicFolder *pLocalMusicFolerAdder = new LocalMusicFolderAdder();
        pLocalMusicFolerAdder->AddLocalMusicFolder();
        delete pLocalMusicFolerAdder;
    }
    void PlayCurrentMusic(int index)
    {
        IPlayCurrentMusic *pCurrentMusicPlayer = new CurrentMusicPlayer();
        pCurrentMusicPlayer->PlayCurrentMusic(index);
        delete pCurrentMusicPlayer;
    }
    void SetVolume(int value)
    {
        ISetVolume *pVolumeSetter = new VolumeSetter();
        pVolumeSetter->SetVolume(value);
        delete pVolumeSetter;
    }
    QVector<bool> FillOnlineMusicTable(QTableWidget *pTable,const QString &query)
    {
        IFillTable *pOnTableFiller = new OnTableFiller();
        QVector<bool> temp =  pOnTableFiller->FillTable(pTable,query);
        delete pOnTableFiller;
        return temp;
    }



};
#endif // COMMANDER


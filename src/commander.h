#ifndef COMMANDER
#define COMMANDER


#include "localmusicadder.h"
#include "localmusicfolderadder.h"
#include "playorpausecurrentmusicsetter.h"
#include "volumesetter.h"
#include "ontablefiller.h"
#include "nextmusicplayer.h"
#include "previousmusicplayer.h"
// Commander
class Commander
{
public:
    void AddLocalMusic(QTableWidget *pTable)
    {
        IAddLocalMusic *pLocalMusicAdder = new LocalMusicAdder();
        pLocalMusicAdder->AddLocalMusic(pTable);
        delete pLocalMusicAdder;
    }
    void AddLocalMusicFolder()
    {
        IAddLocalMusicFolder *pLocalMusicFolerAdder = new LocalMusicFolderAdder();
        pLocalMusicFolerAdder->AddLocalMusicFolder();
        delete pLocalMusicFolerAdder;
    }
    void PlayOrPauseCurrentMusic()
    {
        IPlayOrPauseCurrentMusic *pCurrentMusicSetter = new PlayOrPauseCurrentMusicSetter();
        pCurrentMusicSetter->PlayOrPauseCurrentMusic();
        delete pCurrentMusicSetter;
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
    void NextMusic()
    {
        INextMusic *pNextMusicPlayer = new NextMusicPlayer();
        pNextMusicPlayer->NextMusic();
        delete pNextMusicPlayer;
    }
    void PreviousMusic()
    {
        IPreviousMusic *pPreviousMusicPlayer = new PreviousMusicPlayer;
        pPreviousMusicPlayer->PreviousMusic();
        delete pPreviousMusicPlayer;
    }



};
#endif // COMMANDER


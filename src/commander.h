#ifndef COMMANDER
#define COMMANDER


#include "localmusicadder.h"
#include "localmusicfolderadder.h"
#include "playorpausecurrentmusicsetter.h"
#include "volumesetter.h"
#include "ontablefiller.h"
#include "nextmusicplayer.h"
#include "previousmusicplayer.h"
#include "selectedmusicplayer.h"
#include "curtotaldurationgetter.h"
#include "playmodelchanger.h"
#include "selectedonmusicplayer.h"
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
    void AddLocalMusicFolder(QTableWidget *pTable)
    {
        IAddLocalMusicFolder *pLocalMusicFolerAdder = new LocalMusicFolderAdder();
        pLocalMusicFolerAdder->AddLocalMusicFolder(pTable);
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
    void PlaySelectedMusic(int index)
    {
        IPlaySelectedMusic *pSelectedMusicPlayer = new SelectedMusicPlayer;
        pSelectedMusicPlayer->PlaySelectedMusic(index);
        delete pSelectedMusicPlayer;
    }
    QString GetCurrentTotalDuration()
    {
        IGetCurrentTotalDuration *pCurTotalDurationGetter = new CurTotalDurationGetter;
        QString tmp = pCurTotalDurationGetter->GetCurrentTotalDuration();
        delete pCurTotalDurationGetter;
        return tmp;
    }
    void ChangePlayModel()
    {
        IChangePlayModle *pPlayModelChanger = new PlayModleChanger;
        pPlayModelChanger->ChangePlayModle();
        delete pPlayModelChanger;
    }
    void PlaySelectedOnMusic(int index, QString &lrc, QImage &img)
    {
        IPlaySelectedOnMusic *pSelectedOnMusicPlayer = new SelectedOnMusicPlayer;
        pSelectedOnMusicPlayer->PlaySelectedOnMusic(index,lrc,img);
        delete pSelectedOnMusicPlayer;
    }



};
#endif // COMMANDER


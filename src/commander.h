#ifndef COMMANDER
#define COMMANDER


#include "local_music_adder.h"
#include "local_music_folder_adder.h"
#include "play_or_pause_current_musicsetter.h"
#include "current_playstate_getter.h"
#include "volume_setter.h"
#include "ontable_filler.h"
#include "next_music_player.h"
#include "previous_music_player.h"
#include "selected_music_player.h"
#include "cur_total_duration_getter.h"
#include "play_model_changer.h"
#include "selected_onmusic_player.h"
#include "player_initer.h"
#include "player_terminater.h"
// Commander
class Commander
{
public:
    void PlayerInit()
    {
        IPlayerInit *tmp = new PlayerIniter;
        tmp->PlayerInit();
        delete tmp;
    }
    void PlayerTerminate()
    {
        IPlayerTerminate *tmp = new PlayerTerminater;
        tmp->PlayerTerminate();
        delete tmp;
    }

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
    bool GetCurrentPlayState()
    {
        IGetCurrentPlayState *tmp = new CurrentPlayStateGetter;
        bool result = tmp->GetCurrentPlayState();
        delete tmp;
        return result;
    }



};
#endif // COMMANDER


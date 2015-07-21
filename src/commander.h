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
#include "slider_bar_updater.h"
#include "selected_offmusic_deleter.h"
#include "play_model_changer.h"
#include "music_info_getter.h"
// Commander
class Commander
{
public:
    void PlayerInit(QTableWidget *pTable,QImage img)
    {
        IPlayerInit *tmp = new PlayerIniter;
        tmp->PlayerInit(pTable,img);
        delete tmp;
    }
    void PlayerTerminate()
    {
        IPlayerTerminate *tmp = new PlayerTerminater;
        tmp->PlayerTerminate();
        delete tmp;
    }

    void AddLocalMusic(QTableWidget *pTable,QImage img)
    {
        IAddLocalMusic *pLocalMusicAdder = new LocalMusicAdder();
        pLocalMusicAdder->AddLocalMusic(pTable,img);
        delete pLocalMusicAdder;
    }
    void AddLocalMusicFolder(QTableWidget *pTable,QImage img)
    {
        IAddLocalMusicFolder *pLocalMusicFolerAdder = new LocalMusicFolderAdder();
        pLocalMusicFolerAdder->AddLocalMusicFolder(pTable,img);
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

    void PlaySelectedOnMusic(int index, QString &lrc, QImage &img, QString &name)
    {
        IPlaySelectedOnMusic *pSelectedOnMusicPlayer = new SelectedOnMusicPlayer;
        pSelectedOnMusicPlayer->PlaySelectedOnMusic(index,lrc,img,name);
        delete pSelectedOnMusicPlayer;
    }
    bool GetCurrentPlayState()
    {
        IGetCurrentPlayState *tmp = new CurrentPlayStateGetter;
        bool result = tmp->GetCurrentPlayState();
        delete tmp;
        return result;
    }
    void SliderBarUpdate(qint64 value)
    {
        ISliderBarUpdate *tmp = new SliderBarUpdater;
        tmp->SliderBarUpdate(value);
        delete tmp;
    }
    void DeleteSelectedOffMusic(int index,QTableWidget *pTable)
    {
        IDelteSelectedOffMusic *tmp = new SelectedOffMusicDeleter;
        tmp->DeleteSelectedOffMusic(index,pTable);
        delete tmp;
    }
    void ChangePlayModel(int state)
    {
        IChangePlayModle *p = new PlayModleChanger;
        p->ChangePlayModle(state);
        delete p;
    }
    void GetMusicInfo(QString name,QString &lrc,QImage &img)
    {
        IGetMusicInfo *p = new MusicInfoGetter;
        p->GetMusicInfo(name,lrc,img);
        delete p;
    }




};
#endif // COMMANDER


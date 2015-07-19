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
    bool PlayCurrentMusic()
    {
        IPlayCurrentMusic *pCurrentMusicPlayer = new CurrentMusicPlayer();
        bool state = pCurrentMusicPlayer->PlayCurrentMusic();
        delete pCurrentMusicPlayer;
        return state;
    }
    void SetVolume(int value)
    {
        ISetVolume *pVolumeSetter = new VolumeSetter();
        pVolumeSetter->SetVolume(value);
        delete pVolumeSetter;
    }
    QVector<bool> FillOnlineMusicTable(QTableWidget *pTable, QString &query)
    {
        IFillTable *pOnTableFiller = new OnTableFiller();
        pOnTableFiller->FillTable(pTable,query);
        delete pOnTableFiller;
    }



};
#endif // COMMANDER


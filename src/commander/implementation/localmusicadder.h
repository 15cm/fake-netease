#ifndef LOCALMUSICADDER
#define LOCALMUSICADDER

#include "iaddlocalmusic.h"
#include "player.h"
#include "OffMusic.h"
class LocalMusicAdder: public IAddLocalMusic
{
public:
    void AddLocalMusic(QTableWidget *pTable)
    {
        Player list;
        OffMusic omus = list.AddLocalMusic();
    }
};

#endif // LOCALMUSICADDER


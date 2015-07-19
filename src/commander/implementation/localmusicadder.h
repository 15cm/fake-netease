#ifndef LOCALMUSICADDER
#define LOCALMUSICADDER

#include "iaddlocalmusic.h"
#include "player.h"
class LocalMusicAdder: public IAddLocalMusic
{
public:
    void AddLocalMusic(QTableWidget *pTable)
    {
        Player list;
        list.AddLocalMusic();
    }
};

#endif // LOCALMUSICADDER


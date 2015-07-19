#ifndef LOCALMUSICADDER
#define LOCALMUSICADDER

#include "iaddlocalmusic.h"
#include "player.h"
class LocalMusicAdder: public IAddLocalMusic
{
public:
    void AddLocalMusic()
    {
        Player list;
        list.AddLocalMusic();
    }
};

#endif // LOCALMUSICADDER


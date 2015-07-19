#ifndef LOCALMUSICFOLDERADDER
#define LOCALMUSICFOLDERADDER

#include "iaddlocalmusicfolder.h"
#include "player.h"
class LocalMusicFolderAdder:public IAddLocalMusicFolder
{
public:
    void AddLocalMusicFolder()
    {
        Player list;
        list.AddLocalMusicFolder();
    }
};

#endif // LOCALMUSICFOLDERADDER


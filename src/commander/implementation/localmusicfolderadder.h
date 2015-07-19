#ifndef LOCALMUSICFOLDERADDER
#define LOCALMUSICFOLDERADDER

#include "iaddlocalmusicfolder.h"
#include "player.h"
#include <QVector>
#include "OffMusic.h"
class LocalMusicFolderAdder:public IAddLocalMusicFolder
{
public:
    void AddLocalMusicFolder(QTableWidget *pTable)
    {
        try{
            Player list;
            QVector<OffMusic> qvec = list.AddLocalMusicFolder();
        }
        catch(const AddToListException &addtolistexception)
        {
            //fail when adding to list
            throw;
        }

        //Here, fill the pTable
    }
};

#endif // LOCALMUSICFOLDERADDER


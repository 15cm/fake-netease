#ifndef LOCALMUSICADDER
#define LOCALMUSICADDER

#include "i_add_local_music.h"
#include "player.h"
#include "OffMusic.h"

class LocalMusicAdder: public IAddLocalMusic
{
public:
    void AddLocalMusic(QTableWidget *pTable)
    {
        try
        {
            Player list;
            OffMusic omus = list.AddLocalMusic();
        }
        catch(const AlreadyInListException &alreadyinlistexception)
        {
            //this music is already in list
            //
        }
        catch(const AddToListException &addtolistexception)
        {
            //fail when adding to list
            throw;
        }
        //Here, fill the pTable
        qDebug() << "HERE";

    }


};

#endif // LOCALMUSICADDER


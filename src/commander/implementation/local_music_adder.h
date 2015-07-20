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
            OffMusic tmpMusic;
            int index;
            list.AddLocalMusic(tmpMusic,index);
            int row = index - 1;
            for(int i = 1; i < 5; i ++){
                switch (i) {
                case 1:
                    pTable->item(row,i)->setText(tmpMusic.GetName());
                    break;
                case2:
                    pTable->item(row,i)->setText(tmpMusic.GetAlbum());
                    break;
                case3:
                    pTable->item(row,i)->setText(tmpMusic.GetArtist());
                    break;
                case4:
                    pTable->item(row,i)->setText(tmpMusic.GetDurationStr());
                }
            }
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


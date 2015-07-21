#ifndef LOCALMUSICADDER
#define LOCALMUSICADDER

#include "i_add_local_music.h"
#include "player.h"
#include "OffMusic.h"

class LocalMusicAdder: public IAddLocalMusic
{
public:
    void AddLocalMusic(QTableWidget *pTable, QImage img)
    {
        try
        {
            Player list;
            OffMusic tmpMusic;
            int count;
            list.AddLocalMusic(tmpMusic,count);
            int row = count - 1;
            for(int i = 0; i < 5; i ++){
                switch (i) {
                case 0:{
                    QLabel *pp = (QLabel*)(pTable->cellWidget(row,i));
                    pp->setPixmap(QPixmap::fromImage(img));
                    QLabel* pp2 = (QLabel*)(pTable->cellWidget(row,i));
                    pp2->resize(25,25);
                }
                    break;
                case 1:
                    pTable->item(row,i)->setText(tmpMusic.GetName());
                    break;
                case 2:
                    pTable->item(row,i)->setText(tmpMusic.GetAlbum());         
                    break;
                case 3:
                    pTable->item(row,i)->setText(tmpMusic.GetArtist());            
                    break;
                case 4:
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


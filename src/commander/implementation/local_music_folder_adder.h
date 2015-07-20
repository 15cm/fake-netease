#ifndef LOCALMUSICFOLDERADDER
#define LOCALMUSICFOLDERADDER

#include "i_add_local_music_folder.h"
#include "player.h"
#include <QVector>
#include "OffMusic.h"
class LocalMusicFolderAdder:public IAddLocalMusicFolder
{
public:
    void AddLocalMusicFolder(QTableWidget *pTable, QImage img)
    {
        try{
            Player list;
            int count;
            QVector<OffMusic> qvec = list.AddLocalMusicFolder(count);
            for(int row = count; row < qvec.size() + count; row ++)
                    for(int col = 1; col < 5; col ++){
                        switch (col) {
                        case 0:{
                            QLabel *pp = (QLabel*)(pTable->cellWidget(row,col));
                            pp->setPixmap(QPixmap::fromImage(img));
                            QLabel* pp2 = (QLabel*)(pTable->cellWidget(row,col));
                            pp2->resize(25,25);
                        }
                        break;
                        case 1:
                            pTable->item(row,col)->setText(qvec[row - count].GetName());
                            break;
                        case 2:
                            pTable->item(row,col)->setText(qvec[row - count].GetAlbum());
                            break;
                        case 3:
                            pTable->item(row,col)->setText(qvec[row - count].GetArtist());
                            break;
                        case 4:
                            pTable->item(row,col)->setText(qvec[row - count].GetDurationStr());
                        }
                }
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



#ifndef PLAYER_INIT
#define PLAYER_INIT

#include "i_player_init.h"
#include "player.h"
class PlayerIniter : public IPlayerInit
{
public:
    void PlayerInit(QTableWidget *pTable,QImage img)
    {
        Player list;
        QVector<OffMusic> offList;
        list.Initialize(offList);
        for(int row = 0; row < offList.size(); row ++)
            for(int col = 0; col < 5; col ++){
                switch(col){
                case 0:{
                    QLabel *pp = (QLabel*)(pTable->cellWidget(row,col));
                    pp->setPixmap(QPixmap::fromImage(img));
                    QLabel* pp2 = (QLabel*)(pTable->cellWidget(row,col));
                    pp2->resize(25,25);
                }
                break;
                case 1:
                    pTable->item(row,col)->setText(offList[row].GetName());
                    break;
                case 2:
                    pTable->item(row,col)->setText(offList[row].GetAlbum());
                    break;
                case 3:
                    pTable->item(row,col)->setText(offList[row].GetArtist());
                    break;
                case 4:
                    pTable->item(row,col)->setText(offList[row].GetDurationStr());
                    break;
                }
            }
        //list.Initialize();
    }
};
#endif // PLAYER_INIT


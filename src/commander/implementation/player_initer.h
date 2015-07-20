#ifndef PLAYER_INIT
#define PLAYER_INIT

#include "i_player_init.h"
#include "player.h"
class PlayerIniter : public IPlayerInit
{
public:
    void PlayerInit(QTableWidget *pTable)
    {
        Player list;
        QVector<OffMusic> offList;
        list.Initialize(offList);
        for(int row = 0; row < offList.size(); row ++)
            for(int col = 1; col < 5; col ++){
                switch(col){
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


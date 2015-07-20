#ifndef SELECTED_OFFMUSIC_DELETER
#define SELECTED_OFFMUSIC_DELETER

#include "i_delete_selected_offmusic.h"
#include "player.h"
#include "QLabel"
class SelectedOffMusicDeleter : public IDelteSelectedOffMusic
{
public:
    void DeleteSelectedOffMusic(int index,QTableWidget *pTable)
    {
        Player list;
        int count;
        list.DeleteFromList(index, count);
        for(int row = index + 1; row <= count; row ++)
            for(int col = 1; col < 5; col ++)
                pTable->item(row - 1,col)->setText(pTable->item(row, col)->text());
        for(int i = 0; i < 5; i ++)
            if(i == 0){
                delete pTable->cellWidget(count,0);
                pTable->setCellWidget(count, 0,new QLabel);
            }
            else
            pTable->item(count,i)->setText("");
    }
};

#endif // SELECTED_OFFMUSIC_DELETER


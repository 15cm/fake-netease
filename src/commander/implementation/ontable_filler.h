#ifndef ONTABLEFILLER
#define ONTABLEFILLER

#include "i_fill_table.h"
#include "network.h"
class OnTableFiller : public IFillTable
{
public:
    QVector<bool> FillTable(QTableWidget *pTable,const QString &query)
    {
        MusicSearch mSearch(query);
        QVector<bool> IsStarredList;
        mSearch.GetMusicList();
        for(int row = 0; row < pTable->rowCount(); row++){
            for(int col = 0; col < pTable->columnCount(); col ++){
                if(row >= MusicSearch::vecOnMusic.size()){
                    if(col != 0)
                    pTable->item(row,col)->setText("");
                }
                else
                    switch(col){
                    case 0:{
                        if(MusicSearch::vecOnMusic[row].IsStarred())
                            IsStarredList.push_back(true);
                        else
                            IsStarredList.push_back(false);
                    } break;
                    case 1:{
                        pTable->item(row,col)->setText(MusicSearch::vecOnMusic[row].GetName());
                    }break;
                    case 2:{
                        pTable->item(row,col)->setText(MusicSearch::vecOnMusic[row].GetAlbum());
                    }break;
                    case 3:{
                        pTable->item(row,col)->setText(MusicSearch::vecOnMusic[row].GetArtist());
                    }break;
                    case 4:{
                        pTable->item(row,col)->setText(MusicSearch::vecOnMusic[row].GetDurationStr());
                    }break;
                }
            }
        }
        return IsStarredList;
    }
};
#endif // ONTABLEFILLER


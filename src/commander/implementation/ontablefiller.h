#ifndef ONTABLEFILLER
#define ONTABLEFILLER

#include "ifilltable.h"
#include "network.h"
class OnTableFiller : public IFillTable
{
public:
    QVector<bool> FillTable(QTableWidget *pTable,const QString &query)
    {
        MusicSearch mSearch(query);
        QVector<bool> IsStarredList;
        QVector<OnMusic> vecOnMusic= mSearch.GetMusicList();
        for(int row = 0; row < vecOnMusic.size(); row++){
            for(int col = 0; col < pTable->columnCount(); col ++){
                switch(col){
                case 0:{
                    if(vecOnMusic[row].IsStarred())
                        IsStarredList.push_back(true);
                    else
                        IsStarredList.push_back(false);
                } break;
                case 1:{
                    pTable->item(row,col)->setText(vecOnMusic[row].GetName());
                }
                case 2:{
                    pTable->item(row,col)->setText(vecOnMusic[row].GetAlbum());
                }
                case 3:{
                    pTable->item(row,col)->setText(vecOnMusic[row].GetArtist());
                }
                case 4:{
                    pTable->item(row,col)->setText(vecOnMusic[row].GetDurationStr());
                }
                }
            }
        }
        return IsStarredList;
    }
};
#endif // ONTABLEFILLER


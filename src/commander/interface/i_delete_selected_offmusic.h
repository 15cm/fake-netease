#ifndef I_DELETE_SELECTED_OFFMUSIC
#define I_DELETE_SELECTED_OFFMUSIC

#include <QTableWidget>
class IDelteSelectedOffMusic
{
public:
    virtual void DeleteSelectedOffMusic (int index,QTableWidget *pTable) = 0;
};

#endif // I_DELETE_SELECTED_OFFMUSIC


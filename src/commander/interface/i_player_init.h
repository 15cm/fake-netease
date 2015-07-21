#ifndef IPLAYERINIT
#define IPLAYERINIT

#include <QTableWidget>
#include <QLabel>
class IPlayerInit
{
public:
    virtual void PlayerInit(QTableWidget *pTable,QImage img) = 0;
};

#endif // IPLAYERINIT


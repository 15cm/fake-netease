#ifndef IADDLOCALMUSIC
#define IADDLOCALMUSIC

#include <QTableWidget>
#include <QLabel>
class IAddLocalMusic
{
public:
    virtual void AddLocalMusic(QTableWidget *pTable,QImage img) = 0;
};

#endif // IADDLOCALMUSIC


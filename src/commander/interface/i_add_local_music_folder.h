#ifndef IADDLOCALMUSICFOLDER
#define IADDLOCALMUSICFOLDER

#include <QTableWidget>
#include <QLabel>
class IAddLocalMusicFolder
{
public:
    virtual void AddLocalMusicFolder(QTableWidget *pTable,QImage img) = 0;
};

#endif // IADDLOCALMUSICFOLDER


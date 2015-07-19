#ifndef IFILLTABLE
#define IFILLTABLE

#include <QVector>
#include <QTableWidget>
class IFillTable
{
public:
    virtual QVector<bool> FillTable(QTableWidget *pTable,const QString &query) = 0;
};

#endif // IFILLTABLE


#ifndef SORTERS_H
#define SORTERS_H

#include <QList>
#include "poly.h"

class Sorters
{
public:
    Sorters();
    void BubbleSort(QList<Poly*>);
    void original(QList<Poly*>);
};

#endif // SORTERS_H

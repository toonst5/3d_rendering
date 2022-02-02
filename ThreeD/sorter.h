#ifndef SORTER_H
#define SORTER_H

#include <QList>
#include <QThread>
#include "poly.h"
#include <QGraphicsRectItem>

class sorter: public QObject
{
    Q_OBJECT
private:
    QList<Poly*>* list;
public:
    sorter(QList<Poly*>&listO){list=&listO;}
    sorter();
public slots:
    void BubbleSort();
    void original();
    //void bucketSort();
    void swap(int, int);
    int partition (int, int);
    void quickSort(int, int);
    void quickSortStart(){this->quickSort(0,list->size()-1);emit done();this->thread()->exit();}
signals:
    void draw(int);
    void done();
};

#endif // SORTER_H

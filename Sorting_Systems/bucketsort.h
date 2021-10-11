#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <QList>
#include <QThread>
#include "sorter.h"

class bucketSort: public QObject
{
    Q_OBJECT
private:
    QList<int*>* list;
    QList<QGraphicsLineItem*>* lines;
public:
    bucketSort(QList<int*>&listO,QList<QGraphicsLineItem*>& linesO){list=&listO;lines=&linesO;}
    void sort();
public slots:
    void draw(int);
signals:
    void operate();
};

#endif // BUCKETSORT_H

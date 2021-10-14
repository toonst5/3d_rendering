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
signals:
    void draw(int);
    void done();
};

#endif // SORTER_H

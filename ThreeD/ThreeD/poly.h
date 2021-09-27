#ifndef POLY_H
#define POLY_H
#include <QList>
#include <QGraphicsPolygonItem>
#include "cords.h"
#include <QGraphicsScene>

class Poly
{
private:
    QList<Cords*> points;
public:
    Poly();
    void addPoint(Cords*);
    void calc(int[3],double[3],int[3]);
    void draw(QGraphicsScene*);
};

#endif // POLY_H

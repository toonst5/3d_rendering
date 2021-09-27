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
    int disM;
public:
    Poly();
    void addPoint(Cords*);
    void calc();
    void draw(QGraphicsScene*);
    int givDM(){return disM;}
};

#endif // POLY_H

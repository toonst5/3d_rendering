#include "poly.h"

Poly::Poly()
{

}

void Poly::addPoint(Cords *c)
{
    points.append(*c);
}

void Poly::calc(int c[], double o[], int e[])
{
    for(int i=0;i<points.size();i++)
    {
        points[i].calc(c,o,e);
    }

}

void Poly::draw(QGraphicsScene *cene)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    QVector<QPointF> pentPoints;
    for(int i=0;i<points.size();i++)
    {
        pentPoints.append(QPointF(points[i].giveX(),points[i].giveY()));
    }
    QPolygonF pent(pentPoints);
    QGraphicsPolygonItem* vorm= new QGraphicsPolygonItem(pent);
    vorm->setBrush(brush);
    vorm->setOpacity(0.8);
    vorm->setPen(QPen(brush,0));
    cene->addItem(vorm);
}

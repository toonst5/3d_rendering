#include "poly.h"

Poly::Poly()
{

}

void Poly::addPoint(Cords *c)
{
    points.append(c);
}

void Poly::calc()
{
    disM=0;
    for(int i=0;i<points.size();i++)
    {
        disM=disM+points[i]->giveD();
    }
    disM=disM/points.size();
}

void Poly::draw(QGraphicsScene *cene)
{
    QBrush brush;
    QBrush brush2;
    brush2.setColor(Qt::black);
    brush2.setStyle(Qt::SolidPattern);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    QVector<QPointF> pentPoints;
    for(int i=0;i<points.size();i++)
    {
        pentPoints.append(QPointF(points[i]->giveX(),points[i]->giveY()));
    }
    QPolygonF pent(pentPoints);
    QGraphicsPolygonItem* vorm= new QGraphicsPolygonItem(pent);
    vorm->setBrush(brush);
    vorm->setOpacity(1);
    vorm->setPen(QPen(brush2,1));
    cene->addItem(vorm);
}

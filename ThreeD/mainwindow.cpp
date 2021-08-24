#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent)
{
    math= new matrixMath();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1920,1080);

    //set up scene
    scene = new QGraphicsScene();
    //scene->setSceneRect(0,0,1900,1200);
    scene->setSceneRect(0,0,1900,1000);
    setScene(scene);
    start();
}

void mainWindow::start()
{    
}

void mainWindow::mouseMoveEvent(QMouseEvent* event)
{
    int pointA[3];
    int pointB[2];
    int points[8][3]={{100,100,100},{200,100,100},{200,200,100},{100,200,100},{100,100,200},{200,100,200},{200,200,200},{100,200,200}};
    int pointsEnd[8][2];

    c[0]=c[0]+10;
    e[0]=e[0]+50;
    e[1]=e[1]-1;

    for(int i=0;i<8;i++)
    {
        /*
        pointA[0]=points[i][0];
        pointA[1]=points[i][1];
        pointA[2]=points[i][2];
        math->simpelProjectionPoint(pointA,pointB);
        pointsEnd[i][0]=pointB[0];
        pointsEnd[i][1]=pointB[1];
        */
        pointA[0]=points[i][0];
        pointA[1]=points[i][1];
        pointA[2]=points[i][2];
        math->ProjectionPoint(pointA,c,o,e,pointB);
        pointsEnd[i][0]=pointB[0];
        pointsEnd[i][1]=pointB[1];
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);

    scene->clear();
    for(int i=0;i<8;i++)
    {
        QGraphicsRectItem* point= new QGraphicsRectItem(pointsEnd[i][0]-2,pointsEnd[i][1]-2,4,4);
        point->setBrush(brush);
        scene->addItem(point);
    }
    /*for(int i=1;i<8;i++)
    {
        QGraphicsLineItem* Line= new QGraphicsLineItem(pointsEnd[i][0],pointsEnd[i][1],pointsEnd[i-1][0],pointsEnd[i-1][1]);
        scene->addItem(Line);
    }*/

    QGraphicsLineItem* Line1= new QGraphicsLineItem(pointsEnd[0][0],pointsEnd[0][1],pointsEnd[1][0],pointsEnd[1][1]);
    scene->addItem(Line1);
    QGraphicsLineItem* Line2= new QGraphicsLineItem(pointsEnd[1][0],pointsEnd[1][1],pointsEnd[2][0],pointsEnd[2][1]);
    scene->addItem(Line2);
    QGraphicsLineItem* Line3= new QGraphicsLineItem(pointsEnd[2][0],pointsEnd[2][1],pointsEnd[3][0],pointsEnd[3][1]);
    scene->addItem(Line3);
    QGraphicsLineItem* Line4= new QGraphicsLineItem(pointsEnd[3][0],pointsEnd[3][1],pointsEnd[0][0],pointsEnd[0][1]);
    scene->addItem(Line4);
    QGraphicsLineItem* Line5= new QGraphicsLineItem(pointsEnd[4][0],pointsEnd[4][1],pointsEnd[5][0],pointsEnd[5][1]);
    scene->addItem(Line5);
    QGraphicsLineItem* Line6= new QGraphicsLineItem(pointsEnd[5][0],pointsEnd[5][1],pointsEnd[6][0],pointsEnd[6][1]);
    scene->addItem(Line6);
    QGraphicsLineItem* Line7= new QGraphicsLineItem(pointsEnd[6][0],pointsEnd[6][1],pointsEnd[7][0],pointsEnd[7][1]);
    scene->addItem(Line7);
    QGraphicsLineItem* Line8= new QGraphicsLineItem(pointsEnd[7][0],pointsEnd[7][1],pointsEnd[4][0],pointsEnd[4][1]);
    scene->addItem(Line8);
    QGraphicsLineItem* Line9= new QGraphicsLineItem(pointsEnd[0][0],pointsEnd[0][1],pointsEnd[4][0],pointsEnd[4][1]);
    scene->addItem(Line9);
    QGraphicsLineItem* Line10= new QGraphicsLineItem(pointsEnd[1][0],pointsEnd[1][1],pointsEnd[5][0],pointsEnd[5][1]);
    scene->addItem(Line10);
    QGraphicsLineItem* Line11= new QGraphicsLineItem(pointsEnd[2][0],pointsEnd[2][1],pointsEnd[6][0],pointsEnd[6][1]);
    scene->addItem(Line11);
    QGraphicsLineItem* Line12= new QGraphicsLineItem(pointsEnd[3][0],pointsEnd[3][1],pointsEnd[7][0],pointsEnd[7][1]);
    scene->addItem(Line12);
}

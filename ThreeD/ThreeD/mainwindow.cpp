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
    scene->setSceneRect(0,0,1920,1080);
    setScene(scene);
    start();
}

void mainWindow::start()
{    
    int pointA[3];
    int pointB[2];
    int points[8][3]={{100,100,100},{600,100,100},{100,600,100},{600,600,100},{100,100,600},{600,100,600},{100,600,600},{600,600,600}};
    int pointsEnd[8][2];

    for(int i=0;i<8;i++)
    {
        pointA[0]=points[i][0];
        pointA[1]=points[i][1];
        pointA[2]=points[i][2];
        math->simpelProjectionPoint(pointA,pointB);
        pointsEnd[i][0]=pointB[0];
        pointsEnd[i][1]=pointB[1];
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);

    for(int i=0;i<8;i++)
    {
        QGraphicsRectItem* point= new QGraphicsRectItem(pointsEnd[i][0],pointsEnd[i][1],10,10);
        point->setBrush(brush);
        scene->addItem(point);
    }
}

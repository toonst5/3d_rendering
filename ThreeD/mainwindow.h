#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QBrush>
#include <QTime>
#include <QMouseEvent>
#include <windows.h>
#include "button.h"
#include <QPointF>
#include <QPolygonF>
#include <QList>
#include "poly.h"
#include <QFile>
#include <QMessageBox>
#include "cords.h"
#include "sorters.h"


class mainWindow: public QGraphicsView
{
    Q_OBJECT

private:
    void delay();
    void starterMenu();
    void options();
    void render();
    void laod();
    void keyPressEvent( QKeyEvent *event );
    void forward();
    void left();
    void right();
    void back();
    void BubbleSort();
    Sorters* sort;
    matrixMath* math;
    QList<Poly*> poly;
    QList<Cords*> cordsL;
    //QList<Triangle*> triangle;

    // camera settings
    int c[3]={0,-200,200}; // camera posision
    int e[3]={700,400,500}; // screan
    double o[3]={0.8,0.0,0}; // camera orientation
    int moveS=40;

public:
    QGraphicsScene* scene;
    mainWindow(QWidget* parent=NULL);

public slots:
    void start();
    void next();
    void prev();
};

#endif // MAINWINDOW_H

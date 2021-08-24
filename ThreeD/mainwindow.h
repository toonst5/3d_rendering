#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include "matrixMath.h"
#include <QBrush>
#include <QTime>
#include <QMouseEvent>

class mainWindow: public QGraphicsView
{
    Q_OBJECT

private:
    void start();
    void mouseMoveEvent(QMouseEvent* event);
    matrixMath* math;

    // camera settings
    int c[3]={0,50,-1500};
    int e[3]={0,0,8000};
    double o[3]={0.02,0.01,0};

public:
    QGraphicsScene* scene;
    mainWindow(QWidget* parent=NULL);
};

#endif // MAINWINDOW_H

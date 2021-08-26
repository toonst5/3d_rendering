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
#include <windows.h>
#include "button.h"


class mainWindow: public QGraphicsView
{
    Q_OBJECT

private:
    void delay();
    void starterMenu();
    void options();
    void render();
    void keyPressEvent( QKeyEvent *event );
    void forward();
    void left();
    void right();
    void back();
    matrixMath* math;

    // camera settings
    int c[3]={0,70,-500}; // camera posision
    int e[3]={700,400,500}; // screan
    double o[3]={0.0,0.0,0}; // camera orientation

public:
    QGraphicsScene* scene;
    mainWindow(QWidget* parent=NULL);

public slots:
    void start();
    void next();
    void prev();
};

#endif // MAINWINDOW_H

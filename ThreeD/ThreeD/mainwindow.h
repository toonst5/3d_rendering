#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "matrixMath.h"
#include <QBrush>

class mainWindow: public QGraphicsView
{
    Q_OBJECT

private:
    void start();
    matrixMath* math;

public:
    QGraphicsScene* scene;
    mainWindow(QWidget* parent=NULL);
};

#endif // MAINWINDOW_H

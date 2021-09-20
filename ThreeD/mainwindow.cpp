#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent)
{
    math= new matrixMath();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1700,900);

    //set up scene
    scene = new QGraphicsScene();
    //scene->setSceneRect(0,0,1900,1200);
    scene->setSceneRect(0,0,1700,900);
    setScene(scene);
    starterMenu();
}

void mainWindow::start()
{
    render();
}

void mainWindow::next()
{
    o[1]=o[1]+0.02;
    /*if(o[1]>1)
    {
        o[1]=-1;
    }*/
    render();
}

void mainWindow::prev()
{
    o[1]=o[1]-0.02*M_PI;
    /*if(o[1]<-1)
    {
        o[1]=1;
    }*/
    render();
}

void mainWindow::forward()
{
    c[2]=c[2]+qCos(o[1])*50;
    c[0]=c[0]+qSin(o[1])*50;
    render();
}

void mainWindow::left()
{
    c[0]=c[0]-qCos(o[1])*50;
    c[2]=c[2]+qSin(o[1])*50;
    render();
    //prev();
}

void mainWindow::right()
{
    c[0]=c[0]+qCos(o[1])*50;
    c[2]=c[2]-qSin(o[1])*50;
    render();
    //next();
}

void mainWindow::back()
{
    c[2]=c[2]-qCos(o[1])*50;
    c[0]=c[0]-qSin(o[1])*50;
    render();
}

void mainWindow::render()
{
    triangle.clear();
    int pointA[2]={0,0};
    int pointB[2]={0,0};
    int pointC[2]={0,0};

    int points[12][3][3]={{{-50,-50,-50},{50,-50,-50},{-50,50,-50}},
                          {{50,-50,-50},{-50,50,-50},{50,50,-50}},
                          {{-50,-50,50},{50,-50,50},{-50,50,50}},
                          {{50,-50,50},{-50,50,50},{50,50,50}},
                          {{-50,-50,-50},{-50,-50,50},{-50,50,-50}},
                          {{-50,50,-50},{-50,-50,50},{-50,50,50}},
                          {{-50,50,-50},{-50,50,50},{50,50,-50}},
                          {{50,50,50},{-50,50,50},{50,50,-50}},
                          {{-50,-50,-50},{-50,-50,50},{50,-50,-50}},
                          {{50,-50,50},{-50,-50,50},{50,-50,-50}},
                          {{50,-50,50},{50,50,-50},{50,-50,-50}},
                          {{50,50,50},{50,-50,50},{50,50,-50}}};
    for(int i = 0; i<12;i++)
    {
        Triangle *t=new Triangle(points[i][0][0],points[i][0][1],points[i][0][2],points[i][1][0],points[i][1][1],points[i][1][2],points[i][2][0],points[i][2][1],points[i][2][2]);
        triangle.append(t);
    }

    //int points[14][3]={{-50,-50,-50},{50,-50,-50},{50,50,-50},{-50,50,-50},{-50,-50,50},{50,-50,50},{50,50,50},{-50,50,50},{-75,0,0},{75,0,0},{0,-75,0},{0,75,0},{0,0,-75},{0,0,75}};
    //int pointsEnd[14][2];

    /*c[0]=c[0]+10;
    e[0]=e[0]+50;
    e[1]=e[1]-1;*/

    //c[2]=qCos(o[1])*400;
    //c[0]=qSin(o[1])*400;
    //e[2]=qCos(o[1])*500;
    /*e[0]=qSin(o[1])*500+700;*/

    for(int i=0;i<triangle.count();i++)
    {
        /*
        pointA[0]=points[i][0];
        pointA[1]=points[i][1];
        pointA[2]=points[i][2];
        math->simpelProjectionPoint(pointA,pointB);
        pointsEnd[i][0]=pointB[0];
        pointsEnd[i][1]=pointB[1];
        */
        /*
        pointA[0]=points[i][0];
        pointA[1]=points[i][1];
        pointA[2]=points[i][2];
        math->ProjectionPoint(pointA,c,o,e,pointB);
        pointsEnd[i][0]=pointB[0];
        pointsEnd[i][1]=pointB[1];*/

        triangle[i]->calc(c,o,e);

    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);

    scene->clear();

    for(int i=0;i<triangle.count();i++)
    {
        triangle[i]->giveA(pointA);
        triangle[i]->giveB(pointB);
        triangle[i]->giveC(pointC);
        QVector<QPointF> pentPoints;
        pentPoints << QPointF(pointA[0],pointA[1]) << QPointF(pointB[0],pointB[1]) << QPointF(pointC[0],pointC[1]);

        QPolygonF pent(pentPoints);
        QGraphicsPolygonItem* poly= new QGraphicsPolygonItem(pent);
        poly->setBrush(brush);
        poly->setOpacity(0.2);
        scene->addItem(poly);
    }

    /*for(int i=0;i<8;i++)
    {
        QGraphicsRectItem* point= new QGraphicsRectItem(pointsEnd[i][0]-2,pointsEnd[i][1]-2,4,4);
        point->setBrush(brush);
        scene->addItem(point);
    }*/

    /*for(int i=0;i<10;i=i+2)
    {
       QPolygonF poly;
       poly<<QPointF(pointsEnd[i][0],pointsEnd[i][1])<<QPointF(pointsEnd[i+1][0],pointsEnd[i+1][1])<<QPointF(pointsEnd[i+2][0],pointsEnd[i+2][1])<<QPointF(pointsEnd[i+3][0],pointsEnd[i+3][1]);
       QGraphicsPolygonItem* gPoly= new QGraphicsPolygonItem(poly);
        scene->addItem(gPoly);
    }

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
    QGraphicsLineItem* Line13= new QGraphicsLineItem(pointsEnd[8][0],pointsEnd[8][1],pointsEnd[9][0],pointsEnd[9][1]);
    scene->addItem(Line13);
    QGraphicsLineItem* Line14= new QGraphicsLineItem(pointsEnd[10][0],pointsEnd[10][1],pointsEnd[11][0],pointsEnd[11][1]);
    scene->addItem(Line14);
    QGraphicsLineItem* Line15= new QGraphicsLineItem(pointsEnd[12][0],pointsEnd[12][1],pointsEnd[13][0],pointsEnd[13][1]);
    scene->addItem(Line15);*/



    QString string = QString::number(o[1]/M_PI);
    QString string2 = QString::number(qCos(o[1]));
    QGraphicsTextItem* status = new QGraphicsTextItem(string);
    QFont titleFont("comic sans",20);
    status->setFont(titleFont);
    int txPos = this->width() - status->boundingRect().width();
    int tyPos = 150;
    status->setPos(txPos,tyPos);
    scene->addItem(status);
    QGraphicsTextItem* status2 = new QGraphicsTextItem(string2);
    status2->setFont(titleFont);
    tyPos = 170;
    txPos = this->width() - status2->boundingRect().width();
    status2->setPos(txPos,tyPos);
    scene->addItem(status2);
    options();
}

void mainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Z || event->key() == Qt::Key_8 )
    {
        forward();
    }else if(event->key() == Qt::Key_Q || event->key() == Qt::Key_4 )
    {
        left();
    }else if(event->key() == Qt::Key_S || event->key() == Qt::Key_2 )
    {
        back();
    }else if(event->key() == Qt::Key_D || event->key() == Qt::Key_6 )
    {
        right();
    }else if(event->key() == Qt::Key_J)
    {
        next();
    }else if(event->key() == Qt::Key_H)
    {
        prev();
    }

}

void mainWindow::starterMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("3dRendering"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Start"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void mainWindow::options()
{
    Button* next = new Button(QString("Next"));
    int bxPos = this->width() - next->boundingRect().width();
    int byPos = this->height() - next->boundingRect().height()*3;
    next->setPos(bxPos,byPos);
    connect(next,SIGNAL(clicked()),this,SLOT(next()));
    scene->addItem(next);

    Button* prev = new Button(QString("Prev"));
    int cxPos = this->width() - prev->boundingRect().width()*2;
    int cyPos = this->height() - prev->boundingRect().height()*3;
    prev->setPos(cxPos,cyPos);
    connect(prev,SIGNAL(clicked()),this,SLOT(prev()));
    scene->addItem(prev);
}

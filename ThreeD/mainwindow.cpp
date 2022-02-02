#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent)
{
    //sort= new sorter();
    sort=new bucketSort(poly);
    connect(sort, &bucketSort::drawB, this, &mainWindow::draw);
    //connect(sort, &sorter::draw, this, &mainWindow::draw);
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
    laod();
    //render();
}

void mainWindow::next()
{
    o[1]=o[1]+0.02*M_PI;
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

void mainWindow::draw()
{

    scene->clear();
    for(int i=0;i<poly.size();i++)
    {
        poly[i]->draw(scene);
    }

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
    moving = false;
}

void mainWindow::back()
{
    c[2]=c[2]+qCos(o[1])*moveS;
    c[0]=c[0]+qSin(o[1])*moveS;
    render();
}

void mainWindow::right()
{
    c[0]=c[0]-qCos(o[1])*moveS;
    c[2]=c[2]+qSin(o[1])*moveS;
    render();
    //prev();
}

void mainWindow::left()
{
    c[0]=c[0]+qCos(o[1])*moveS;
    c[2]=c[2]-qSin(o[1])*moveS;
    render();
    //next();
}

void mainWindow::forward()
{
    c[2]=c[2]-qCos(o[1])*moveS;
    c[0]=c[0]-qSin(o[1])*moveS;
    render();
}

void mainWindow::keyPressEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_Z || event->key() == Qt::Key_8 ) && !moving)
    {
        moving = true;
        forward();
    }else if((event->key() == Qt::Key_Q || event->key() == Qt::Key_4 ) && !moving)
    {
        moving = true;
        left();
    }else if((event->key() == Qt::Key_S || event->key() == Qt::Key_2 ) && !moving)
    {
        moving = true;
        back();
    }else if((event->key() == Qt::Key_D || event->key() == Qt::Key_6 ) && !moving)
    {
        moving = true;
        right();
    }else if((event->key() == Qt::Key_J) && !moving)
    {
        moving = true;
        next();
    }else if((event->key() == Qt::Key_H) && !moving)
    {
        moving = true;
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

void mainWindow::render()
{
    //int count=0;
    for(int i=0;i<cordsL.size();i++)
    {
        cordsL[i]->calc(c,o,e);
    }

    for(int i=0;i<poly.size();i++)
    {
        poly[i]->calc();
    }
    sort->sort();
    //sort->BubbleSort();
}

void mainWindow::laod()
{
    QString line="  ";
    QString number1=" ";
    QString number2=" ";
    QString number3=" ";
    QString number4="";
    int i=0;
    QFile file("C:\\Users\\Toon\\Desktop\\Coding\\ThreeD\\spin.obj");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"error",file.errorString());
    }

    QTextStream in(&file);
    while(1)
    {
        number1=" ";
        number2=" ";
        number3=" ";
        while((line[0]!='v'||line[1]!=' ')&&line[0]!='f')
        {
            line = in.readLine();
            while(line.size()<1)
            {
                line = in.readLine();
                if(in.atEnd())
                {
                    break;
                }
            }
            if(in.atEnd())
            {
                break;
            }
        }
        if(in.atEnd())
        {
            break;
        }
        if(line[0]!='f')
        {
            i=2;
            while(line[i]!=' ')
            {
                number1.append(line[i]);
                i++;
            }
            i++;
            while(line[i]!=' ')
            {
                number2.append(line[i]);
                i++;
            }
            i++;
            while(line[i]!=' '&&line.length()>i+1)
            {
                number3.append(line[i]);
                i++;
            }
            Cords* cordenets=new Cords(number1.toDouble()*60,number2.toDouble()*60,number3.toDouble()*60);
            cordsL.append(cordenets);
        }else
        {
            i=0;
            Poly* polyM=new Poly();
            while(1)
            {
                while(line[i]!=' ')
                {
                    i++;
                    if(line.length()<=i)
                    {
                        break;
                    }
                }
                i++;
                if(line.length()<=i)
                {
                    break;
                }
                while(line[i]!='/')
                {
                    number4.append(line[i]);
                    i++;
                }
                polyM->addPoint(cordsL[number4.toInt()-1]);
                number4.clear();
            }
            poly.append(polyM);
        }
        if(in.atEnd())
        {
            break;
        }
        line = in.readLine();
        while(line.size()<1)
        {
            line = in.readLine();
        }
    }

    file.close();

    render();
}


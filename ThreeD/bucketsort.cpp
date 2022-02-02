#include "bucketsort.h"

void bucketSort::sort()
{
    int maximum=0;
    int minimum=9999999;
    int curent=0;
    int bathAllowens=0;
    for(int i=0; i<bath.size();i++)
    {
        bath[i]->clear();
    }
    bath.clear();
    int size=20;
    doneC=0;
    int place=0;
    QList<Poly*>* bucket;
    QList<sorter*> sorters;
    for(int y=0;y<size;y++)
    {
        bucket=new QList<Poly*>;
        bath.append(bucket);
    }
    for(int i=0;i<list->size();i++)
    {
        curent=(*list)[i]->givDM();
        if(curent>maximum)
        {
            maximum=curent;
        }else if(curent<minimum)
        {
            minimum=curent;
        }
    }
    bathAllowens=(maximum-minimum)/size;
    for(int i=0;i<list->size();i++)
    {
        while((*list)[i]->givDM()>(place+1)*bathAllowens+minimum)
        {
            place++;
            if(place>size-1)
            {
                place=size-1;
                break;
            }
        }
        bath[place]->append((*list)[i]);
        place=0;
    }
    sorter* srt;
    QThread* sortingThread;
    for(int i=0;i<(bath.size()-1);i++)
    {
        srt=new sorter(*bath[i]);
        sortingThread=new QThread();
        srt->moveToThread(sortingThread);
        connect(sortingThread, &QThread::finished, srt, &QObject::deleteLater);
        //connect(this, &bucketSort::operate, srt, &sorter::BubbleSort);
        connect(this, &bucketSort::operate, srt, &sorter::quickSortStart);
        //connect(srt, &Sorter::draw, this, &bucketSort::draw);
        connect(srt, &sorter::done, this, &bucketSort::done);
        sortingThread->start();
        sorters.append(srt);
        threads.append(sortingThread);
    }
    emit operate();
}

void bucketSort::draw(int i)
{
    emit drawB(i);
}

void bucketSort::done()
{
    doneC++;
    if(doneC==bath.size()-1)
    {
        fill();
    }
}

void bucketSort::fill()
{
    int x=0;
    for(int i=bath.size()-1;i>=0;i--)
    {
        for(int y=0;y<=(*bath[i]).size()-1;y++)
        {
            (*list)[x]=(*bath[i])[y];
            x++;
        }
    }
    bool running=true;
    while(running)
    {
        running=false;
        for(int i=0;i< threads.size(); i++)
        {
            if(threads[i]->isRunning())
            {
                running=true;
            }
        }
    }
    for(int i=0;i< threads.size(); i++)
    {
        threads[i]->exit();
    }
    threads.clear();
    /*for(int z=0-1;y<bath.size();z++)
    {
        (*bath[z])
    }*/
    emit drawB(-1);
}

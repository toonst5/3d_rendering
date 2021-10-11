#include "bucketsort.h"

void bucketSort::sort()
{
    int place=0;
    QList<QList<int*>*> bath;
    QList<int*>* bucket;
    QList<QThread*> threads;
    QList<sorter*> sorters;
    for(int y=0;y<50;y++)
    {
        bucket=new QList<int*>;
        bath.append(bucket);
    }

    for(int i=0;i<list->size();i++)
    {
        while(*(*list)[i]<place*10)
        {
            place++;
            if(place>50)
            {
                place=50;
                break;
            }
        }
        bath[place]->append((*list)[i]);
        place=0;
    }
    sorter* srt;
    QThread* sortingThread;
    for(int i=0;i<bath.size();i++)
    {
        srt=new sorter(*list);
        sortingThread=new QThread();
        srt->moveToThread(sortingThread);
        connect(sortingThread, &QThread::finished, srt, &QObject::deleteLater);
        connect(this, &bucketSort::operate, srt, &sorter::original);
        connect(srt, &sorter::draw, this, &bucketSort::draw);
        sortingThread->start();
        sorters.append(srt);
        threads.append(sortingThread);
    }
    emit operate();
}

void bucketSort::draw(int)
{

}

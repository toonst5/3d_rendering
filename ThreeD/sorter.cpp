#include "sorter.h"

void sorter::BubbleSort()
{
    Poly* temp;
    int j=0;
    int i=0;
    int n=0;
    n=(*list).size();
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if ((*list)[j]->givDM() < (*list)[j+1]->givDM())
            {
                temp=(*list)[j];
                (*list)[j]=(*list)[j+1];
                (*list)[j+1]=temp;
                emit draw(j);
            }
        }
    }
    emit done();
    this->thread()->exit();
}

void sorter::original()
{
    for(int i=0;(i<(*list).size()-1);i++)
    {
        if((*list)[i]->givDM() < (*list)[i+1]->givDM())
        {
            (*list).move(i,i+1);
            emit draw(i);
            i=0;
        }
    }
    emit done();
}


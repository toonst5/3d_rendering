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

void sorter::swap(int a, int b)
{
    Poly* temp;
    temp=(*list)[a];
    (*list)[a]=(*list)[b];
    (*list)[b]=temp;
}

int sorter::partition (int low, int high)
{
    int pivot = (*list)[high]->givDM();
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if ((*list)[j]->givDM() >= pivot)
        {
            i++;
            swap(i, j);
        }
    }
    swap((i + 1), high);
    return (i + 1);
}


void sorter::quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = this->partition(low, high);
        this->quickSort(low, pi - 1);
        this->quickSort(pi + 1, high);
    }
}


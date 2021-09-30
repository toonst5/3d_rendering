#include "sorters.h"

Sorters::Sorters()
{

}

void Sorters::BubbleSort(QList<Poly*> list)
{
    Poly* temp;
    int i, j;
    int n=list.size();
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (list[j]->givDM() > list[j+1]->givDM())
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
}

void Sorters::original(QList<Poly*> poly)
{
    for(int i=0;(i<poly.size()-1);i++)
    {
        if(poly[i]->givDM() <poly[i+1]->givDM())
        {
            poly.move(i,i+1);
            i=0;
        }
    }
}

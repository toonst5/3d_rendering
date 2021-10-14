#include "sorter.h"

/*void bucketSort()
{
    int n=(*list).size();
    // 1) Create n empty buckets
    Q(*list)<float> b[n];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * (*list)[i]; // Index in bucket
        b[bi].push_back((*list)[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
    {
        //sort(b[i].begin(), b[i].end());
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<b[i].size(); j++)
        {
            //(*list)[index++] = b[i][j];
        }
    }
}*/

void sorter::BubbleSort()
{
    Poly* temp;
    int i, j;
    int n=(*list).size();
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


#include "matrixMath.h"

matrixMath::matrixMath()
{

}

void matrixMath::simpelProjectionPoint(int start[3],int end[2])
{
    end[0]=start[0]*simpelProjection[0][0]+start[1]*simpelProjection[0][1]+start[2]*simpelProjection[0][2];
    end[1]=start[0]*simpelProjection[1][0]+start[1]*simpelProjection[1][1]+start[2]*simpelProjection[1][2];
}

//https://en.wikipedia.org/wiki/3D_projection
void matrixMath::ProjectionPoint(int a[3], int c[3], int o[3], int e[3], int end[2])
{
    int matrixA[3][3];
    int matrixB[3][3];
    coppy(matrixA,Projection);
    coppy(matrixB,Projection);

    matrixA[1][1]=qCos(o[0]);
    matrixA[1][2]=qSin(o[0]);
    matrixA[2][1]=qSin(o[0])*-1;
    matrixA[2][2]=qCos(o[0]);

    matrixB[0][0]=qCos(o[1]);
    matrixB[0][2]=qSin(o[1])*-1;
    matrixB[2][0]=qSin(o[1]);
    matrixB[2][2]=qCos(o[1]);

    multiplay(matrixA,matrixB);

}

void matrixMath::coppy(int A[3][3], int B[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int t=0;t<3;t++)
        {
            A[i][t]=B[i][t];
        }
    }
}

void matrixMath::multiplay(int A[3][3], int B[3][3])
{
   int C[3][3];
   C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0]+A[0][2]*B[2][0];
   for(int t=0;t<3;t++)
   {
       for(int i=0;i<3;i++)
       {
           C[i][t]=A[i][0]*B[0][t]+A[i][1]*B[1][t]+A[i][2]*B[2][t];
       }
   }
   coppy(B,C);
}

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
void matrixMath::ProjectionPoint(double a[], int c[], double o[], int e[], double end[])
{
    double matrixA[3][3];
    double matrixB[3][3];
    double matrixC[3]={0,0,0};
    double d[3]={0,0,0};
    coppy(matrixA,Projection);
    coppy(matrixB,Projection);

    //first matrix muliplicasion
    matrixA[1][1]=qCos(o[0]);
    matrixA[1][2]=qSin(o[0]);
    matrixA[2][1]=qSin(o[0])*-1;
    matrixA[2][2]=qCos(o[0]);

    matrixB[0][0]=qCos(o[1]);
    matrixB[0][2]=qSin(o[1])*-1;
    matrixB[2][0]=qSin(o[1]);
    matrixB[2][2]=qCos(o[1]);

    multiplay(matrixA,matrixB);

    //seccond matrix muliplicasion
    coppy(matrixB,Projection);

    matrixB[0][0]=qCos(o[2]);
    matrixB[0][1]=qSin(o[2]);
    matrixB[1][0]=qSin(o[2])*-1;
    matrixB[1][1]=qCos(o[2]);

    multiplay(matrixA,matrixB);

    //thirt matrix muliplicasion (and first matrix subtraction?)
    matrixC[0]=a[0]-c[0];
    matrixC[1]=a[1]-c[1];
    matrixC[2]=a[2]-c[2];

    d[0]=matrixA[0][0]*matrixC[0]+matrixA[0][1]*matrixC[1]+matrixA[0][2]*matrixC[2];
    d[1]=matrixA[1][0]*matrixC[0]+matrixA[1][1]*matrixC[1]+matrixA[1][2]*matrixC[2];
    d[2]=matrixA[2][0]*matrixC[0]+matrixA[2][1]*matrixC[1]+matrixA[2][2]*matrixC[2];

    //more math
    end[0]=double(e[2]/d[2]*d[0]+e[0]);
    end[1]=double(e[2]/d[2]*d[1]+e[1]);
}

void matrixMath::coppy(double A[3][3], double B[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int t=0;t<3;t++)
        {
            A[i][t]=B[i][t];
        }
    }
}

void matrixMath::multiplay(double A[3][3], double B[3][3])
{
   double C[3][3];
   C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0]+A[0][2]*B[2][0];
   for(int t=0;t<3;t++)
   {
       for(int i=0;i<3;i++)
       {
           C[i][t]=A[i][0]*B[0][t]+A[i][1]*B[1][t]+A[i][2]*B[2][t];
       }
   }
   coppy(A,C);
}

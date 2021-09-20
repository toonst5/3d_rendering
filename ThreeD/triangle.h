#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "matrixMath.h"


class Triangle
{
private:
    int A[3];
    int B[3];
    int C[3];
    int CA[2];
    int CB[2];
    int CC[2];
    matrixMath* math;
public:
    Triangle();
    Triangle(int,int,int,int,int,int,int,int,int);
    void calc(int[3],double[3],int[3]);
    void giveA(int X[2]){X[0]=CA[0];X[1]=CA[1];}
    void giveB(int X[2]){X[0]=CB[0];X[1]=CB[1];}
    void giveC(int X[2]){X[0]=CC[0];X[1]=CC[1];}
};

#endif // TRIANGLE_H

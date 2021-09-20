#include "triangle.h"

Triangle::Triangle()
{

}

Triangle::Triangle(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    A[0]=a;
    A[1]=b;
    A[2]=c;
    B[0]=d;
    B[1]=e;
    B[2]=f;
    C[0]=g;
    C[1]=h;
    C[2]=i;
    math = new matrixMath();
}

void Triangle::calc(int c[], double o[], int e[])
{
    math->ProjectionPoint(A,c,o,e,CA);
    math->ProjectionPoint(B,c,o,e,CB);
    math->ProjectionPoint(C,c,o,e,CC);

}


#ifndef MATRIXMATH_H
#define MATRIXMATH_H

#include <QtMath>

class matrixMath
{
private:
    int simpelProjection[2][3]={{1,0,0},{0,1,0}};
    double Projection[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    void coppy(double[3][3],double[3][3]);
    void multiplay(double[3][3],double[3][3]);
public:
    matrixMath();
    void simpelProjectionPoint(int[3],int[2]);
    void ProjectionPoint(int[3],int[3],double[3],int[3],int[2]);
};

#endif // MATRIXMATH_H

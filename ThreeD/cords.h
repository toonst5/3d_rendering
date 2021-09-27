#ifndef CORDS_H
#define CORDS_H
#include "matrixMath.h"


class Cords
{
private:
    double cordenets[3];
    double cordenetsM[2];
    matrixMath* math;
    int dis;
public:
    Cords(double x, double y, double z){cordenets[0]=x;cordenets[1]=y;cordenets[2]=z;math=new matrixMath();}
    void calc(int[3],double[3],int[3]);
    int giveX(){return int(cordenetsM[0]);}
    int giveY(){return int(cordenetsM[1]);}
    int giveD(){return dis;}
};

#endif // CORDS_H

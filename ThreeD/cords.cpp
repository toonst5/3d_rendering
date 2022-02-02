#include "cords.h"

void Cords::calc(int c[], double o[], int e[])
{
    math->ProjectionPoint(cordenets,c,o,e,cordenetsM);
    dis=qSqrt(qPow((c[0]-cordenets[0]),2)+qPow((c[1]-cordenets[1]),2)+qPow((c[2]-cordenets[2]),2));
}

int Cords::Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return int(y);
}

#include "cords.h"

void Cords::calc(int c[], double o[], int e[])
{
    math->ProjectionPoint(cordenets,c,o,e,cordenetsM);
    dis=qSqrt(qPow((c[0]-cordenets[0]),2)+qPow((c[1]-cordenets[1]),2)+qPow((c[2]-cordenets[2]),2));
}

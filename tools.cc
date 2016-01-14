#include "tools.hh"

double getAngle(Ray r1, Ray r2)
{
    r1.Normalize();
    r2.Normalize();
    double res = r1.getDirX() * r2.getDirX() + r1.getDirY()* r2.getDirY() +
    r1.getDirZ() *
    r2.getDirZ();
 //   printf("numerateur = %f\n",res);
    return acos(res);
}

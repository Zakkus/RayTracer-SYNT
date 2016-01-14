#include "tools.hh"

double getAngle(Ray r1, Ray r2)
{
    r1.Normalize();
    r2.Normalize();
    double res = r1.getDirX() * r2.getDirX() + r1.getDirY()* r2.getDirY() +
    r1.getDirZ() *
    r2.getDirZ();
 //   printf("numerateur = %f\n",res);
    return res;
}

Ray compute_reflection_vect(Ray ray)
{
    double scalar =
       (pow(sqrt(pow(- ray.getDirX(), 2) +
                 pow(- ray.getDirY(), 2) +
                 pow(- ray.getDirZ(), 2)), 2 )
      + 3                               // distance au point 1,1,1
      - pow(sqrt(pow(- ray.getDirX() - 1, 2) +
                 pow(- ray.getDirY() - 1, 2) +
                 pow(- ray.getDirZ() - 1, 2)), 2)) / 2;

    double refX = ray.getDirX() + 2 * scalar;
    double refY = ray.getDirY() + 2 * scalar;
    double refZ = ray.getDirZ() + 2 * scalar;
    return Ray(refX, refY, refZ);
}

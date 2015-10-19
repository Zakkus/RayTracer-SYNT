#include "ray.hh"

Ray::Ray(int x, int y, int z):dirx(x), diry(y), dirz(z)
{}

int Ray::getDirX()
{
    return dirx;
}

int Ray::getDirY()
{
    return diry;
}

int Ray::getDirZ()
{
    return dirz;
}

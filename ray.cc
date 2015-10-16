#include "ray.hh"

Ray::Ray(int x, int y, int z):dirx(x), diry(y), dirz(z)
{}

Ray::getDirX()
{
    return dirx;
}

Ray::getDirY()
{
    return diry;
}

Ray::getDirZ()
{
    return dirz;
}

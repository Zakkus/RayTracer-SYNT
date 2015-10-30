#include "ray.hh"

Ray::Ray(double x, double y, double z):dirx(x), diry(y), dirz(z)
{}

double Ray::getDirX()
{
    return dirx;
}

double Ray::getDirY()
{
    return diry;
}

double Ray::getDirZ()
{
    return dirz;
}

void Ray::Normalize()
{
    double norm = sqrt(pow(dirx,2) + pow(diry,2) + pow(dirz,2));
    dirx = dirx / norm;
    diry = diry / norm;
    dirz = dirz / norm;

}

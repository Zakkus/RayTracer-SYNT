#include "plane.hh"

Plane::Plane(int xi, int yi, int zi, int ai, int bi, int ci, int di)
        : x(xi), y(yi), z(zi), a(ai), b(bi), c(ci), d(di)
{}

void Plane::Calculate(Camera c, Ray r)
{
    int X = c.getX() - x;
    int Y = c.getY() - y;
    int Z = c.getZ() - z;
    t = -((a*X + b * Y + c * Z + d)/(a * r.getDirX() + b * getDirY() + c
    * getDirZ()));
}

double Plane::getT()
{
    return t;
}

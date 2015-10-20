#include "plane.hh"

Plane::Plane(int xi, int yi, int zi, int ai, int bi, int ci, int di, Uint32 col)
        : x(xi), y(yi), z(zi), a(ai), b(bi), c(ci), d(di), color(col)
{}

void Plane::Calculate(Camera cam, Ray r)
{
    int X = cam.getX() - x;
    int Y = cam.getY() - y;
    int Z = cam.getZ() - z;
    t = -((a*X + b * Y + c * Z + d)/(a * r.getDirX() + b * r.getDirY() + c
    * r.getDirZ()));
}

double Plane::getT()
{
    return t;
}

Uint32 Plane::getColor()
{
    return color;
}

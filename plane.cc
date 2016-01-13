#include "plane.hh"

Plane::Plane(int xi, int yi, int zi, int ai, int bi, int ci, int di, SDL_Color col)
        : x(xi), y(yi), z(zi), a(ai), b(bi), c(ci), d(di)
{    
    color.r = col.r;
    color.g = col.g;
    color.b = col.b;
    color.a = col.a;
}

void Plane::Calculate(Point3 cam, Ray r)
{
    double X = cam.getX() - x;
    double Y = cam.getY() - y;
    double Z = cam.getZ() - z;
    t = -((a*X + b * Y + c * Z + d)/(a * r.getDirX() + b * r.getDirY() + c
    * r.getDirZ()));
}

double Plane::getT()
{
    return t;
}

SDL_Color* Plane::getColor()
{
    return &color;
}

Ray Plane::getNormale(Point3 p)
{
return Ray(0,0,0);
}

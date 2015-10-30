#include "lumin.hh"

Lumin::Lumin(Point3 p, Uint32 col): pt(p), color(col)
{}

Lumin::Lumin(int x, int y, int z, Uint32 col):pt(Point3(x,y,z)), color(col)
{}

double getAngle(Ray r1, Ray r2)
{
    double norm1 = sqrt(pow(r1.getDirX(),2) + pow(r1.getDirY(),2) +
    pow(r1.getDirZ(),2));
    double norm2 = sqrt(pow(r2.getDirX(),2) + pow(r2.getDirY(),2) +
    pow(r2.getDirZ(),2));
    double res = r1.getDirX() * r2.getDirX() + r1.getDirY()* r2.getDirY() +
    r1.getDirZ() *
    r2.getDirZ();
    res = res / (norm1 + norm2);
    return acos(res);
}

Uint32 Lumin::ChangeColor(Uint32 color, Ray r1, Ray r2)
{
    return color * getAngle(r1,r2);
}

int Lumin::getX()
{
    return pt.getX();
}

int Lumin::getY()
{
    return pt.getY();
}

int Lumin::getZ()
{
    return pt.getZ();
}

Point3 Lumin::getPt()
{
    return pt;
}

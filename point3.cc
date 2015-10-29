#include "point3.hh"

Point3::Point3(int xi, int yi, int zi):x(xi), y(yi), z(zi)
{}

int Point3::getX()
{
    return x;
}

int Point3::getY()
{
    return y;
}

int Point3::getZ()
{
    return z;
}

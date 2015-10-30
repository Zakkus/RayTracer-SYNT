#include "camera.hh"

Camera::Camera(Point3 p):pt(p)
{}

Camera::Camera(int x, int y, int z):pt(Point3(x,y,z))
{}

int Camera::getX()
{
    return pt.getX();
}

int Camera::getY()
{
    return pt.getY();
}

int Camera::getZ()
{
    return pt.getZ();
}

Point3 Camera::getPt()
{
    return pt;
}

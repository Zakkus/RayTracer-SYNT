#include "camera.hh"

Camera::Camera(Point3 p, Ray uu, Ray vv):pt(p), u(uu), v(vv)
{}

Camera::Camera(int x, int y, int z, Ray uu, Ray vv):pt(Point3(x,y,z)), u(uu), v(vv)
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

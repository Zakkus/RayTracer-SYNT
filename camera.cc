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

Ray Camera::getDir()
{
	double x = u.getDirY() * v.getDirZ() - v.getDirY() * u.getDirZ();
	double y = u.getDirZ() * v.getDirX() - v.getDirZ() * u.getDirX();
	double z = u.getDirX() * v.getDirY() - v.getDirX() * u.getDirY();
	return Ray(x,y,z);
}

Ray Camera::getLeft()
{
	return u;
}

Ray Camera::getUp()
{
	return v;
}

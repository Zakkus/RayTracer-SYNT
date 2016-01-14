#ifndef CAMERA_HH
#define CAMERA_HH

#include "point3.hh"
#include "ray.hh"

class Camera
{
    public:
    Camera(Point3 p, Ray uu, Ray vv);
    Camera(int x, int y, int z, Ray uu, Ray vv);
    int getX();
    int getY();
    int getZ();
	Ray getDir();
	Ray getLeft();
	Ray getUp();
    Point3 getPt();

    private:
        Point3 pt;
		Ray u;
		Ray v;
};

#endif

#ifndef CAMERA_HH
#define CAMERA_HH

#include "point3.hh"

class Camera
{
    public:
    Camera(Point3 p);
    Camera(int x, int y, int z);
    int getX();
    int getY();
    int getZ();
    Point3 getPt();

    private:
        Point3 pt;
};

#endif

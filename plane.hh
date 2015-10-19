#ifndef PLANE_HH
#define PLANE_HH

#include "camera.hh"
#include "ray.hh"


class Plane
{
    public:
        Plane(int xi, int yi, int zi, int ai, int bi, int ci, int di);
        double Calculate(Camera cam, Ray r);

    private:
    //Point
        int x;
        int y;
        int z;
    //Normale
        int a;
        int b;
        int c;
        int d;
};

#endif

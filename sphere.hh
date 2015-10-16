#ifndef SPHERE_HH
#define SPHERE_HH

#include "ray.hh"
#include "camera.hh"

class Sphere
{

    public:
    Sphere(int cx, int cy, int cz, int ra);
    void Calculate(Camera cam, Ray ray);
    float getDelta();
    int getT();

    private:
    int xc;
    int yc;
    int zc;
    int r;
    int a;
    int b;
    int c;
};

#endif

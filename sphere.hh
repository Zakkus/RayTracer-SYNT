#ifndef SPHERE_HH
#define SPHERE_HH

#include "ray.hh"
#include "camera.hh"
#include <cmath>
#include <climits>

class Sphere
{

    public:
    Sphere(int cx, int cy, int cz, int ra);
    void Calculate(Camera cam, Ray ray);
    double getDelta();
    double getT();

    private:
    int xc;
    int yc;
    int zc;
    int r;
    double a;
    double b;
    double c;
};

#endif

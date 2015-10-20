#ifndef SPHERE_HH
#define SPHERE_HH

#include "primitive.hh"

class Sphere : public Primitive
{
    public:
        Sphere(int cx, int cy, int cz, int ra, Uint32 col);
        void Calculate(Camera cam, Ray ray);
        double getT();
        Uint32 getColor();

    private:
        double getDelta();
        int xc;
        int yc;
        int zc;
        int r;
        double a;
        double b;
        double c;
        Uint32 color;
};

#endif

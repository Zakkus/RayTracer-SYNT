#ifndef PLANE_HH
#define PLANE_HH

#include "primitive.hh"

class Plane : public Primitive
{
    public:
        Plane(int xi, int yi, int zi, int ai, int bi, int ci, int di, Uint32 col);
        void Calculate(Camera cam, Ray r);
        double getT();
        Uint32 getColor();

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
        double t;
        Uint32 color;
};

#endif

#ifndef PLANE_HH
#define PLANE_HH

#include "primitive.hh"

class Plane : public Primitive
{
    public:
        Plane(int xi, int yi, int zi, int ai, int bi, int ci, int di, SDL_Color col);
        void Calculate(Point3 cam, Ray r);
        double getT();
        SDL_Color* getColor();

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
        SDL_Color color;
};

#endif

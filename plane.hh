#ifndef PLANE_HH
#define PLANE_HH

#include "primitive.hh"
#include <stdlib.h>
#include <stdio.h>

class Plane : public Primitive
{
    public:
        Plane(int xi, int yi, int zi, int ai, int bi, int ci, int di, int r, SDL_Color col);
        void Calculate(Point3 cam, Ray r);
        double getT();
        SDL_Color* getColor();
		Ray getNormale(Point3 p);
		int getReflect();

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
		int reflect;
        SDL_Color color;
};

#endif

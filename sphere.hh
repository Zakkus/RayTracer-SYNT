#ifndef SPHERE_HH
#define SPHERE_HH

#include "primitive.hh"

class Sphere : public Primitive
{
    public:
        Sphere(int cx, int cy, int cz, int ra, int refl, SDL_Color col);
        void Calculate(Point3 cam, Ray ray);
        double getT();
        SDL_Color* getColor();
        Ray getNormale(Point3 pt);
		int getReflect();

    private:
        double getDelta();
        int xc;
        int yc;
        int zc;
        int r;
		int reflect;
        double a;
        double b;
        double c;
        SDL_Color color;
};

#endif

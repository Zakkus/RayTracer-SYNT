#ifndef PRIMITIVE_HH
#define PRIMITIVE_HH

#include "ray.hh"
#include "camera.hh"
#include <climits>
#include <SDL2/SDL.h>


class Primitive
{
    public:
        virtual void Calculate(Point3 cam, Ray ray) = 0;
        virtual double getT() = 0;
        virtual SDL_Color* getColor() = 0;
		virtual Ray getNormale(Point3 p) = 0;
		virtual int getReflect() = 0;
};

#endif

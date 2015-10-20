#ifndef PRIMITIVE_HH
#define PRIMITIVE_HH

#include "ray.hh"
#include "camera.hh"
#include <cmath>
#include <climits>
#include <SDL2/SDL.h>

class Primitive
{
    public:
        virtual void Calculate(Camera cam, Ray ray) = 0;
        virtual double getT() = 0;
        virtual Uint32 getColor() = 0;
};

#endif

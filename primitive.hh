#ifndef PRIMITIVE_HH
#define PRIMITIVE_HH

#include "ray.hh"
#include "camera.hh"
#include <cmath>
#include <climits>

class Primitive
{
    public:
        virtual void Calculate(Camera cam, Ray ray) = 0;
        virtual double getT() = 0;
};

#endif

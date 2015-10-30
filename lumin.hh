#ifndef LUMIN_HH
#define LUMIN_HH

#include "sphere.hh"
#include "plane.hh"
#include "point3.hh"
#include <vector>

using namespace std;

class Lumin
{
    public:
        Lumin(Point3 p, Uint32 color);
 //       void Diffuse(SDL_Surface* s, vector<Primitive*> v);
    private:
        Point3 pt;
        Uint32 color;
};

#endif

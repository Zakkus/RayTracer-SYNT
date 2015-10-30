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
        Lumin(int x, int y, int z, Uint32 color);
        int getX();
        int getY();
        int getZ();
        SDL_Color* ChangeColor(SDL_Color* color, Ray r1, Ray r2);
        Point3 getPt();
    private:
        Point3 pt;
        Uint32 color;
};

#endif

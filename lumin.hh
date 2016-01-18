#ifndef LUMIN_HH
#define LUMIN_HH

#include "photon.hh"
#include <vector>

using namespace std;

class Lumin: public Photon
{
    public:
        Lumin(Point3 p, SDL_Color color, int powa);
        Lumin(int x, int y, int z, SDL_Color color, int powa);
        int getX();
        int getY();
        int getZ();
		int getType();
        SDL_Color ChangeColor(SDL_Color* color, Ray r1, Ray r2, double dist);
        Point3 getPt();
    private:
        Point3 pt;
        SDL_Color color;
		int power;
};

#endif

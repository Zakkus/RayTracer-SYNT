#ifndef PHOTON_HH
#define PHOTON_HH

#include "tools.hh"
#include "point3.hh"
#include <SDL2/SDL.h>

class Photon
{
	public:
		virtual int getType() = 0;
		virtual SDL_Color ChangeColor(SDL_Color* c, Ray r1, Ray r2, double dist) = 0;
};

#endif

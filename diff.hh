#ifndef DIFF_HH
#define DIFF_HH

#include "photon.hh"

class Diff
{
	public:
		Diff(Ray ray);
		int getType();
		SDL_Color ChangeColor(SDL_Color* c, Ray r1, Ray r2);
	private:
		Ray r;
};

#endif

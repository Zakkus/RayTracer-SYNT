#include "diff.hh"

Diff::Diff(Ray ray):r(ray)
{}

SDL_Color Diff::ChangeColor(SDL_Color* c, Ray r1, Ray r2)
{
    double angle = getAngle(r1, r2);
 //	printf("%d \n", c->g);
	SDL_Color col;
	if (angle <= M_PI/2 && angle >= -M_PI/2)
		angle = 0;
    col.r = c->r * (angle / (2*M_PI));
    col.g = c->g * (angle / (2*M_PI));
    col.b = c->b * (angle / (2*M_PI));
    return col;
}

int Diff::getType()
{
	return 0;
}

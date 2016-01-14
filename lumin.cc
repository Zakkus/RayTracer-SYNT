#include "lumin.hh"

Lumin::Lumin(Point3 p, Uint32 col): pt(p), color(col)
{}

Lumin::Lumin(int x, int y, int z, Uint32 col):pt(Point3(x,y,z)), color(col)
{}

SDL_Color Lumin::ChangeColor(SDL_Color* c, Ray r1, Ray r2)
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

int Lumin::getX()
{
    return pt.getX();
}

int Lumin::getY()
{
    return pt.getY();
}

int Lumin::getZ()
{
    return pt.getZ();
}

Point3 Lumin::getPt()
{
    return pt;
}

int Lumin::getType()
{
	return 1;
}

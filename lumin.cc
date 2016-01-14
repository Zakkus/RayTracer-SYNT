#include "lumin.hh"

Lumin::Lumin(Point3 p, SDL_Color col): pt(p), color(col)
{}

Lumin::Lumin(int x, int y, int z, SDL_Color col):pt(Point3(x,y,z)), color(col)
{}

SDL_Color Lumin::ChangeColor(SDL_Color* c, Ray r1, Ray r2)
{
    double angle = getAngle(r1, r2);
	SDL_Color col;
	if (angle >= 0)
		angle = 0;
	else
		angle = 1 - angle;
    col.r = (c->r/255) * color.r * angle;
    col.g = (c->g/255)* color.g * angle;
    col.b = (c->b/255) * color.b * angle;
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

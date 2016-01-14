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
    col.r = c->r * color.r * angle / 255;
    col.g = c->g * color.g * angle / 255;
    col.b = c->b * color.b * angle / 255;
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

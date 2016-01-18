#include "lumin.hh"

Lumin::Lumin(Point3 p, SDL_Color col, int powa): pt(p), color(col), power(powa)
{}

Lumin::Lumin(int x, int y, int z, SDL_Color col, int powa):pt(Point3(x,y,z)), color(col), power(powa)
{}

SDL_Color Lumin::ChangeColor(SDL_Color* c, Ray r1, Ray r2, double dist)
{
    double angle = getAngle(r1, r2);
	SDL_Color col;
	if (angle >= 0)
		angle = 0;
	else
		angle = 1 - angle;
	double coeff = power / dist;
	if (coeff > 1)
		coeff = 1;
	if (coeff < 0)
		coeff = 0;
    col.r = c->r * color.r * angle * coeff / 255;
    col.g = c->g * color.g * angle * coeff / 255;
    col.b = c->b * color.b * angle * coeff / 255;
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

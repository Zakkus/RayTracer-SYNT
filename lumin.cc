#include "lumin.hh"

Lumin::Lumin(Point3 p, Uint32 col): pt(p), color(col)
{}

Lumin::Lumin(int x, int y, int z, Uint32 col):pt(Point3(x,y,z)), color(col)
{}

double getAngle(Ray r1, Ray r2)
{
    r1.Normalize();
    r2.Normalize();
    double res = r1.getDirX() * r2.getDirX() + r1.getDirY()* r2.getDirY() +
    r1.getDirZ() *
    r2.getDirZ();
 //   printf("numerateur = %f\n",res);
    return acos(res);
}

SDL_Color* Lumin::ChangeColor(SDL_Color* color, Ray r1, Ray r2)
{
    double angle = getAngle(r1, r2);
 	//printf("%d \n", color->g);
	if (angle <= M_PI/2 && angle >= -M_PI/2)
		angle = 0;
    color->r = color->r * (angle / M_PI);
    color->g = 255 * (angle / M_PI);
    color->b = color->b * (angle / M_PI);
    return color;
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

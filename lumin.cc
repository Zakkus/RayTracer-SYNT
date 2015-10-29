#include "lumin.hh"

Lumin::Lumin(int xi, int yi, int zi): x(xi), y(yi), z(zi)
{}

void Lumin::Diffuse(SDL_Surface* s, int i, int j, Primitive* obj,
vector<Primitive*> v)
{
    Ray r = Ray(i - x, j - y, -z);
    obj->Calculate()
    double t 
}

double getAngle(Ray r1, Ray r2)
{
    double norm1 = sqrt(pow(r1.getX(),2) + pow(r1.getY(),2) + pow(r1.getZ(),2));
    double norm2 = sqrt(pow(r2.getX(),2) + pow(r2.getY(),2) + pow(r2.getZ(),2));
    double res = r1.getX() * r2.getX() + r1.getY()* r2.getY() + r1.getZ() *
    r2.getZ();
    res = res / (norm1 + norm2);
    return acos(res);
}

Uint32 ChangeColor(Uint32 color, Ray r1, Ray r2)
{
    return color * getAngle(r1,r2);
}

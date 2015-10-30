#include "lumin.hh"

Lumin::Lumin(Point3 p, Uint32 col): pt(p), color(col)
{}

/*void Lumin::Diffuse(SDL_Surface* s, int i, int j, Primitive* obj,
vector<Primitive*> v)
{
    Ray r = Ray(i - x, j - y, -z);
    obj->Calculate()
    double t 
}*/

double getAngle(Ray r1, Ray r2)
{
    double norm1 = sqrt(pow(r1.getDirX(),2) + pow(r1.getDirY(),2) +
    pow(r1.getDirZ(),2));
    double norm2 = sqrt(pow(r2.getDirX(),2) + pow(r2.getDirY(),2) +
    pow(r2.getDirZ(),2));
    double res = r1.getDirX() * r2.getDirX() + r1.getDirY()* r2.getDirY() +
    r1.getDirZ() *
    r2.getDirZ();
    res = res / (norm1 + norm2);
    return acos(res);
}

Uint32 ChangeColor(Uint32 color, Ray r1, Ray r2)
{
    return color * getAngle(r1,r2);
}

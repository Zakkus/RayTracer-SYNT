#include "sphere.hh"

Sphere::Sphere(int cx, int cy, int cz, int ra, int refl, SDL_Color col)
        : xc(cx), yc(cy), zc(cz), r(ra), reflect(refl)
{
    color.r = col.r;
    color.g = col.g;
    color.b = col.b;
    color.a = col.a;
}

void Sphere::Calculate(Point3 cam, Ray ray)
{
    a = pow(ray.getDirX(), 2) + pow(ray.getDirY(),2) + pow(ray.getDirZ(),2);
    b = 2 * (ray.getDirX() * (cam.getX() - xc) + ray.getDirY() * (cam.getY() -
    yc) + ray.getDirZ() * (cam.getZ() - zc));
    c = pow((cam.getX() - xc), 2) + pow((cam.getY() - yc), 2) + pow((cam.getZ()
    - zc), 2) - pow(r, 2);
}

double Sphere::getDelta()
{
    return pow(b, 2) - 4 * a * c;
}

double Sphere::getT()
{
    if (getDelta() == 0)
        return -b / (2 * a);
    else if (getDelta() > 0)
    {
        double t1 = (-b + sqrt(getDelta())) / (2 * a);
        double t2 = (-b - sqrt(getDelta())) / (2 * a);
        if (t1 > t2)
            return t2;
        else
            return t1;
    }
    else
        return	HUGE_VAL;
}

SDL_Color* Sphere::getColor()
{
    return &color;
}

Ray Sphere::getNormale(Point3 p)
{
    return Ray(p.getX() - xc, p.getY() - yc, p.getZ() - zc);
}

int Sphere::getReflect()
{
	return reflect;
}

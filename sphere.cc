#include "sphere.hh"

Sphere::Sphere(int cx, int cy, int cz, int ra):xc(cx), yc(cy), zc(cz), r(ra)
{}

void Sphere::Calculate(Camera cam, Ray ray)
{
    a = ray.getDirX()^2 + ray.getDirY()^2 + ray.getDirZ()^2;
    b = 2 * (ray.getDirX() * (cam.getX() - xc) + ray.getDirY() * (cam.getY() -
    yc) + ray.getDirZ() * (cam.getZ() - zc))
    c = (cam.getX() - xc) ^ 2 + (cam.getY() - yc) ^ 2 + (cam.getZ() - zc) ^ 2 -
    r^2;
}

float getDelta()
{
    return b^2 - 4 * a * c;
}

int getT()
{
    //if (getDelta() == 0)
        return -b / (2 * a);
    /*else if (getDelta() > 0)
        int t1 =*/
}

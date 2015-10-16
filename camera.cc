#include "camera.hh"

Camera::Camera(int posx, int posy, int posz):x(posx), y(posy), z(posz)
{}

int Camera::getX()
{
    return x;
}

int Camera::getY()
{
    return y;
}

int Camera::getZ()
{
    return z;
}

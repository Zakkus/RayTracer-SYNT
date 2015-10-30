#ifndef RAY_HH
#define RAY_HH

#include <cmath>

class Ray
{
    public:
    Ray(double x, double y, double z);
    double getDirX();
    double getDirY();
    double getDirZ();
    void Normalize();

    private:
    double dirx;
    double diry;
    double dirz;
};

#endif

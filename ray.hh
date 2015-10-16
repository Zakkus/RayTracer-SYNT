#ifndef RAY_HH
#define RAY_HH

class Ray
{
    public:
    Ray(int x, int y, int z);
    int getDirX();
    int getDirY();
    int getDirZ();

    private:
    int dirx;
    int diry;
    int dirz;
};

#endif

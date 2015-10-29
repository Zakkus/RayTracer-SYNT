#ifndef Point3_HH
#define Point3_HH

class Point3
{
    public:
        Point3(int xi, int yi, int zi);
        int getX();
        int getY();
        int getZ();
    private:
        int x;
        int y;
        int z;
};

#endif

#ifndef CAMERA_HH
#define CAMERA_HH

class Camera
{
    public:
    Camera(int posx, int posy, int posz);
    int getX();
    int getY();
    int getZ();

    private:
    int x;
    int y;
    int z;
};

#endif

#include "parser.hh"
#include <stdio.h>
#include "diff.hh"
#include "trace.hh"

using namespace std;

void setPixel(SDL_Surface* dst, int x, int y, Uint32 color)
{
    *((Uint32*)(dst->pixels) + x + y * dst->w) = color;
}

void launch(SDL_Surface* s, Camera c, vector<Primitive*> v, vector<Lumin*> li)
{
    Point3 init = getUpLeft(c, s->w, s->h, 100);
    for (int i = 0; i < s->w; i++)
        for (int j = 0; j < s->h; j++)
        {
            Point3 where = getPoint(c, init, s->w, s->h, s->w, s->h, i, j);
            Ray ray = Ray(where.getX() - c.getX(), where.getY() - c.getY(), where.getZ() -c.getZ());

            SDL_Color cl = Send(ray, c.getPt(), v, li, 0);
            setPixel(s, i, j, SDL_MapRGB(s->format, cl.r, cl.g,
                        cl.b));

        }
}

int main(int argc, char** argv)
{
    int n = SDL_Init(SDL_INIT_EVERYTHING);
    if (n < 0)
        printf("fail SDL: %s\n", SDL_GetError());
    SDL_Window* w = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Surface* screen = SDL_GetWindowSurface(w);
    Ray u = Ray(1, 0, 0);
    Ray v = Ray(0,1,0);
    Camera cam = Camera(0,0,0,u,v);
    SDL_Surface* s = SDL_CreateRGBSurface(0,640,480,32,0,0,0,0);
    vector<Primitive*> p = vector<Primitive*>();
    vector<Lumin*> li = vector<Lumin*>();



    SDL_Color wh;
      wh.r = 255;
      wh.g = 255;
      wh.b = 255;
      Lumin lum = Lumin(120, 100, -20, wh, 100);
    //li.push_back(&lum);
    Lumin lums = Lumin(0, 0, -10, wh, 1000000);
    li.push_back(&lums);
    SDL_Color col;
    col.r = 100;
    col.g = 255;
    col.b = 0;
    Lumin lol =  Lumin(50, 100, 2000, col, 10);
    //li.push_back(&lol);
    SDL_Color col2;
    col2.r = 255;
    col2.g = 0;
    col2.b = 0;
    SDL_Color col3;
    col3.r = 0;
    col3.g = 0;
    col3.b = 255;

    Sphere d = Sphere(0, 0, 150, 10, 1, col);
    //p.push_back(&d);
    Sphere d2 = Sphere(-100,0, 150, 25, 1,col2);
    //p.push_back(&d2);
    Plane pl = Plane(0, 0, 500, 0, 0, -1, 150, 0, col2);
    p.push_back(&pl);
    Plane pla = Plane(0, 0, 500, 0, -1, -1, 150, 0, col3);
    p.push_back(&pla);
    Sphere d3 = Sphere(100, 0, 150, 50, 1, col3);
    //p.push_back(&d3);


//    parseScene(argv, p, li);

    launch(s, cam, p, li);
    SDL_BlitSurface(s, NULL, screen, NULL);
    SDL_UpdateWindowSurface(w);
    SDL_Delay(1000);
    SDL_DestroyWindow(w);
    SDL_Quit();

    return 0;
}

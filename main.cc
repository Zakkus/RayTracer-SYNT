#include "sphere.hh"
#include "plane.hh"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>

using namespace std;

void setPixel(SDL_Surface* dst, int x, int y, Uint32 color)
{
        *((Uint32*)(dst->pixels) + x + y * dst->w) = color;
}

void launch(SDL_Surface* s, Camera c, vector<Primitive*> v)
{
    for (int i = 0; i < s->w; i++)
        for (int j = 0; j < s->h; j++)
        {
            double t = INT_MIN;
            Ray ray = Ray(i - c.getX(), j - c.getY(), -c.getZ());
            for (int i = 0; i < v.size(); i++)
            {
            v[i]->Calculate(c, ray);
            if (t < v[i]->getT())
                t = v[i]->getT();
            if (t > INT_MIN)
                setPixel(s, i, j, SDL_MapRGB(s->format, 255,0,0));
            }

        }
}

int main(int argc, char** argv)
{
    int n = SDL_Init(SDL_INIT_EVERYTHING);
    if (n < 0)
        printf("fail SDL: %s\n", SDL_GetError());
    SDL_Window* w = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_SHOWN);
    SDL_Surface* screen = SDL_GetWindowSurface(w);
    Camera cam = Camera(100,100,100);
    SDL_Surface* s = SDL_CreateRGBSurface(0,200,200,32,0,0,0,0);
    vector<Primitive*> p = vector<Primitive*>();
    Sphere d = Sphere(100,100, 0, 50);
    p.push_back(&d);
    launch(s, cam, p);
    SDL_BlitSurface(s, NULL, screen, NULL);
    SDL_UpdateWindowSurface(w);
    SDL_Delay(1000);
    SDL_DestroyWindow(w);
    SDL_Quit();
    return 0;
}

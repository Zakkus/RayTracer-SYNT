#include "sphere.hh"
#include <SDL2/SDL.h>
#include <stdio.h>

void setPixel(SDL_Surface* dst, int x, int y, Uint32 color)
{
        *((Uint32*)(dst->pixels) + x + y * dst->w) = color;
}

void launch(SDL_Surface* s, Camera c, Sphere sph)
{
    for (int i = 0; i < s->w; i++)
        for (int j = 0; j < s->h; j++)
        {
            Ray ray = Ray(i - c.getX(), j - c.getY(), -c.getZ());
            sph.Calculate(c, ray);
            double t = sph.getT();
            if (t > INT_MIN)
                setPixel(s, i, j, SDL_MapRGB(s->format, 255,0,0));

        }
}

int main(int argc, char** argv)
{
    int n = SDL_Init(SDL_INIT_EVERYTHING);
    if (n < 0)
        printf("fail SDL: %s\n", SDL_GetError());
        return 1;
    SDL_Window* w = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_SHOWN);
    SDL_Surface* screen = SDL_GetWindowSurface(w);
    Camera cam = Camera(100,100,100);
    SDL_Surface* s = SDL_CreateRGBSurface(0,200,200,32,0,0,0,0);
    Sphere d = Sphere(100,100, 0, 50);
    //launch(s, cam, d);
    for (int i = 0; i < s->w; i++)
        for (int j = 0; j < s->h; j++)
            setPixel(s, i, j, SDL_MapRGB(s->format, 255,255,255));
    SDL_BlitSurface(s, NULL, screen, NULL);
    SDL_UpdateWindowSurface(w);
    SDL_Delay(1000);
    SDL_DestroyWindow(w);
    SDL_Quit();
    return 0;
}

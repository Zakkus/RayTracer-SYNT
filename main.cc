#include "parser.hh"
#include "sphere.hh"
#include "plane.hh"
#include <stdio.h>
#include <vector>
#include "lumin.hh"
#include "diff.hh"

using namespace std;



void setPixel(SDL_Surface* dst, int x, int y, Uint32 color)
{
    *((Uint32*)(dst->pixels) + x + y * dst->w) = color;
}

void launch(SDL_Surface* s, Camera c, vector<Primitive*> v, vector<Lumin*> li)
{
    for (int i = 0; i < s->w; i++)
        for (int j = 0; j < s->h; j++)
        {
            double t = 3000;
            SDL_Color* color;
            Ray ray = Ray(i - c.getX(), j - c.getY(), -c.getZ());
            Primitive* obj = NULL;
            for (int k = 0; k < v.size(); k++)
            {
            v[k]->Calculate(c.getPt(), ray);
            if (t > v[k]->getT())
            {
                obj = v[k];
                t = v[k]->getT();
                color = v[k]->getColor();
            }
            }
            if (!obj)
                continue;
            Point3 p = Point3((int)(c.getX() + ray.getDirX() * t), (int)(c.getY() +
            ray.getDirY() * t), (int)(c.getZ() + ray.getDirZ() * t));
			SDL_Color cl;
			cl.r = 0;
			cl.g = 0;
			cl.b = 0;
			for (int dz = 0; dz < li.size(); dz++)
			{
			Lumin l = *(li[dz]);
            Ray ray2 = Ray(p.getX() - l.getX(), p.getY() - l.getY(), p.getZ() -l.getZ());
			obj->Calculate(l.getPt(), ray2);
            double dist = obj->getT();
			Ray ray3 = obj->getNormale(p);
			
            SDL_Color c = l.ChangeColor(color, ray3, ray2);
            for(int k =0; k < v.size(); k++)
            {
                if (v[k] == obj)
                    continue;
                v[k]->Calculate(l.getPt(), ray2);
                if(dist > v[k]->getT())
                {
                	c.g = 0;
					c.b = 0;
					c.r = 0;
                }
            }
			cl.r += c.r/2;
			cl.g += c.g/2;
			cl.b += c.b/2;
			}
        if (t < 3000)
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
            SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_SHOWN);
    SDL_Surface* screen = SDL_GetWindowSurface(w);
    Ray u = Ray(1, 0, 0);
    Ray v = Ray(0,1,0);
    Camera cam = Camera(100,100,100,u,v);
    SDL_Surface* s = SDL_CreateRGBSurface(0,200,200,32,0,0,0,0);
    vector<Primitive*> p = vector<Primitive*>();
	vector<Lumin*> li = vector<Lumin*>();
	SDL_Color wh;
	wh.r = 255;
	wh.g = 255;
	wh.b = 255;
    Lumin lum = Lumin(120, 100, -75, wh);
	li.push_back(&lum);
    Lumin lums = Lumin(120, 100, -50, wh);
	li.push_back(&lums);
    SDL_Color col;
    col.r = 0;
    col.g = 255;
    col.b = 0;
    SDL_Color col2;
    col2.r = 255;
    col2.g = 0;
    col2.b = 0;


    Sphere d = Sphere(100,100, -100, 10, col);
    p.push_back(&d);
    Sphere d2 = Sphere(100,100, -300, 100, col2);
    p.push_back(&d2);
    Plane pl = Plane(0, 0, -5000, 0, 0, 1, 5, col2);
    p.push_back(&pl);
    launch(s, cam, p, li);
   SDL_BlitSurface(s, NULL, screen, NULL);
    SDL_UpdateWindowSurface(w);
    SDL_Delay(10000);
    SDL_DestroyWindow(w);
    SDL_Quit();


    //vector<Primitive*> p = parseScene(argv);

    return 0;
}

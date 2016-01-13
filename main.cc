#include "parser.hh"
#include "sphere.hh"
#include "plane.hh"
#include <stdio.h>
#include <vector>
#include "lumin.hh"

using namespace std;

void setPixel(SDL_Surface* dst, int x, int y, Uint32 color)
{
        *((Uint32*)(dst->pixels) + x + y * dst->w) = color;
}

void launch(SDL_Surface* s, Camera c, vector<Primitive*> v, Lumin l)
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
	//			printf("%f\n", t);
                color = v[k]->getColor();
 //               printf("%d\n", color->g);
            }
            }
            if (!obj)
                continue;
			//printf("%f\n", ray.getDirX()*t);
            Point3 p = Point3((int)(c.getX() + ray.getDirX() * t), (int)(c.getY() +
            ray.getDirY() * t), (int)(c.getZ() + ray.getDirZ() * t));
			//printf("%d, %d, %d\n", p.getX(), p.getY(), p.getZ());
            Ray ray2 = Ray(p.getX() - l.getX(), p.getY() - l.getY(), p.getZ() -l.getZ());
            //printf("lumin: %f, %f, %f\n", ray2.getDirX(), ray2.getDirY(), ray2.getDirZ()); 
			obj->Calculate(l.getPt(), ray2);
            double dist = obj->getT();
			Ray ray3 = obj->getNormale(p);
			//printf("%f\n", dist);
			//if (dist > 0.9)
			
            color = l.ChangeColor(color, ray3, ray2);
            /*for(int k =0; k < v.size(); k++)
            {
                if (v[k] == obj)
                    continue;
                v[k]->Calculate(l.getPt(), ray2);
                if(dist > v[k]->getT())
                {
                	color->g = 0;
					color->b = 0;
					color->r = 0;
                    //printf("%d\n", color->g);
                   // break;
                }
            }*/
	/*		else
				{
				color->r = 0;
				color->g = 0;
				color->b = 0;
				}*/
			//printf ("%f\n", t); 
            if (t < 3000)
                setPixel(s, i, j, SDL_MapRGB(s->format, color->r, color->g,
                color->b));
	//		free(color);
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
    Lumin lum = Lumin(100,-100, -100, SDL_MapRGB(s->format,255, 255,255));
    SDL_Color col;
    col.r = 0;
    col.g = 255;
    col.b = 0;
	SDL_Color col2;
    col2.r = 0;
    col2.g = 0;
    col2.b = 255;
    
    Sphere d = Sphere(100,100, -100, 50, col);
    p.push_back(&d);
    //Sphere d2 = Sphere(40,40, 0, 70, SDL_MapRGB(s->format, 0, 0, 255));
   // p.push_back(&d2);
  //  Plane pl = Plane(10, 2, -600, 4, 5, 6, 7, col2);
   // p.push_back(&pl);
    launch(s, cam, p, lum);
    SDL_BlitSurface(s, NULL, screen, NULL);
    SDL_UpdateWindowSurface(w);
    SDL_Delay(1000);
    SDL_DestroyWindow(w);
    SDL_Quit();

    //vector<Primitive*> p = parseScene(argv);

    return 0;
}

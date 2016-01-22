#include "trace.hh"

SDL_Color Send(Ray ray, Point3 c, vector<Primitive*> v, vector<Lumin*> li, int ref)
{
    double t = HUGE_VAL;
    SDL_Color* color;
    Primitive* obj = NULL;
    for (int k = 0; k < v.size(); k++)
    {
        v[k]->Calculate(c, ray);
        if (t > v[k]->getT())
        {
            obj = v[k];
            t = v[k]->getT();
            color = v[k]->getColor();
        }
    }	
    Point3 p = Point3((int)(c.getX() + ray.getDirX() * t), (int)(c.getY() +
                ray.getDirY() * t), (int)(c.getZ() + ray.getDirZ() * t));
    SDL_Color cl;
    cl.r = 0;
    cl.g = 0;
    cl.b = 0;
    if (!obj)
        return cl;
    for (int dz = 0; dz < li.size(); dz++)
    {
        Lumin l = *(li[dz]);
        Ray ray2 = Ray(p.getX() - l.getX(), p.getY() - l.getY(), p.getZ() -l.getZ());
        ray2.Normalize();
        obj->Calculate(l.getPt(), ray2);
        double dist = obj->getT();
        Ray ray3 = obj->getNormale(p);
        ray3.Normalize();
        SDL_Color c = l.ChangeColor(color, ray3, ray2, dist);
        if (ref < 1 && obj->getReflect() == 1)
        {
            Ray re = Ray(- ray2.getDirX(), - ray2.getDirY(), -ray2.getDirZ());
            Ray reflect = compute_reflection_vect(re, ray3);
            SDL_Color clor = Send(reflect, p, v, li, 1);
            c.r = c.r/2 + clor.r/2;
            c.g = c.g/2 + clor.g/2;
            c.b = c.b/2 + clor.b/2;
        }
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
        cl.r += c.r/li.size();
        cl.g += c.g/li.size();
        cl.b += c.b/li.size();
    }
    return cl;
}

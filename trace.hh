#ifndef TRACE_HH
#define TRACE_HH

#include "tools.hh"
#include <vector>
#include "lumin.hh"
#include "sphere.hh"
#include "plane.hh"

SDL_Color Send(Ray ray, Point3 c, vector<Primitive*> v, vector<Lumin*> li, int ref);

#endif

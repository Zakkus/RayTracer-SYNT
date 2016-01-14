#ifndef TOOLS_HH
#define TOOLS_HH

#include "camera.hh"


double getAngle(Ray r1, Ray r2);

Ray compute_reflection_vect(Ray ray);

Point3 getUpLeft(Camera c, int w, int h, int d);

Point3 getPoint(Camera c, Point3 p, int w, int h, int resx, int resy, int x, int y);

#endif

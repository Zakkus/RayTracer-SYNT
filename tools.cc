#include "tools.hh"

double getAngle(Ray r1, Ray r2)
{
    r1.Normalize();
    r2.Normalize();
    double res = r1.getDirX() * r2.getDirX() + r1.getDirY()* r2.getDirY() +
    r1.getDirZ() *
    r2.getDirZ();
 //   printf("numerateur = %f\n",res);
    return res;
}

Ray compute_reflection_vect(Ray ray)
{
    double scalar =
       (pow(sqrt(pow(- ray.getDirX(), 2) +
                 pow(- ray.getDirY(), 2) +
                 pow(- ray.getDirZ(), 2)), 2 )
      + 3                               // distance au point 1,1,1
      - pow(sqrt(pow(- ray.getDirX() - 1, 2) +
                 pow(- ray.getDirY() - 1, 2) +
                 pow(- ray.getDirZ() - 1, 2)), 2)) / 2;

    double refX = ray.getDirX() + 2 * scalar;
    double refY = ray.getDirY() + 2 * scalar;
    double refZ = ray.getDirZ() + 2 * scalar;
    return Ray(refX, refY, refZ);
}

Point3 getUpLeft(Camera c, int w, int h, int d)
{
	int x = c.getX() + c.getDir().getDirX() * d + c.getUp().getDirX() * h/2.0 - c.getLeft().getDirX() * w/2.0;
	int y = c.getY() + c.getDir().getDirY() * d + c.getUp().getDirY() * h/2.0 - c.getLeft().getDirY() * w/2.0;
	int z = c.getZ() + c.getDir().getDirZ() * d + c.getUp().getDirZ() * h/2.0 - c.getLeft().getDirZ() * w/2.0;
	return Point3(x,y,z);
}

Point3 getPoint(Camera c, Point3 p, int w, int h, int resx, int resy, int x, int y)
{
	double xind = w / (double)resx;
	double yind = h / (double)resy;
	int i = (int)(p.getX() + c.getLeft().getDirX() * xind * x - yind * c.getUp().getDirX() * y);
	int j = (int)(p.getY() + c.getLeft().getDirY() * xind * x - yind * c.getUp().getDirY() * y);
	int k = (int)(p.getZ() + c.getLeft().getDirZ() * xind * x - yind * c.getUp().getDirZ() * y);
	return Point3(i,j,k);
}

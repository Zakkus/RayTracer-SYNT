#ifndef PARSER_HH
# define PARSER_HH

# include <vector>
# include <iostream>
# include <cstring>
# include <string>
# include <cstdlib>
# include <fstream>
# include "primitive.hh"
# include "sphere.hh"
# include "plane.hh"
# include "lumin.hh"
#include "camera.hh"

void parseScene(char** argv, Camera** c,std::vector<Primitive *> &prims, std::vector<Lumin *> &lumis);
void getObject(char* st, Camera** c, std::vector<Primitive *> &prims, std::vector<Lumin *> &lumis);
Sphere* getSphere(char* st);
Plane* getPlane(char* st);
Lumin* getLumin(char* st);
void getCam(char* st, Camera** c);

#endif /* !PARSER_HH */

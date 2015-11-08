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

Primitive* getPrimitive(char* st);
Sphere* getSphere(char* st);
Plane* getPlane(char* st);
std::vector<Primitive *> parseScene(char** argv);

#endif /* !PARSER_HH */

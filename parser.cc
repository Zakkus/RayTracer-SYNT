#include "parser.hh"

void parseScene(char** argv, Camera** c, std::vector<Primitive *> &prims, std::vector<Lumin *> &lumis)
{
    std::string st;
    std::ifstream fs(argv[1]);
    int n;

    getline(fs,st); 

    n = atoi(st.c_str());
    while (n > 0)
    {
        getline(fs, st);
        getObject(&st[0], c, prims, lumis);
        n--;
    }
    if (!c)
        printf("OK\n");
}

void getObject(char* st, Camera** c, std::vector<Primitive *> &prims, std::vector<Lumin *> &lumis)
{
    char* new_s = strtok (st,",");

    if (strcmp(new_s, "camera") == 0)
        getCam(new_s, c);
    if (strcmp(new_s, "sphere") == 0)
        prims.push_back(getSphere(new_s));
    if (strcmp(new_s, "plane") == 0)
        prims.push_back(getPlane(new_s));
    if (strcmp(new_s, "light") == 0)
        lumis.push_back(getLumin(new_s));
}

Sphere* getSphere(char* st)
{
    SDL_Color c;
    int cx, cy, cz, r, reflect;
    int l1, l2, l3, n1, n2, n3;
    Uint8 cr, cg, cb;
    std::vector<char*> parsed;

    while (st != NULL)
    {
        std::cout << st << std::endl;
        st = strtok (NULL, ",");
        parsed.push_back(st);
    }

    char* pos = strtok(parsed[0], " ");
    cx = atoi(pos);
    pos = strtok(NULL, " ");
    cy = atoi(pos);
    pos = strtok(NULL, " ");
    cz = atoi(pos);

    r = atoi(parsed[1]);
    reflect = atoi(parsed[2]);

    char* color = strtok(parsed[3], " ");
    c.r = atoi(color);
    color = strtok(NULL, " ");
    c.g = atoi(color);
    color = strtok(NULL, " ");
    c.b = atoi(color);

    /*char* normal = strtok(parsed[4], " ");
    n1 = atoi(normal);
    normal = strtok(NULL, " ");
    n2 = atoi(normal);
    normal = strtok(NULL, " ");
    n3 = atoi(normal);*/

    return new Sphere(cx, cy, cz, r, reflect, c);
}

Plane* getPlane(char* st)
{
    SDL_Color c, lc;
    int xi, yi, zi, ai, bi, ci, di;
    int l1, l2, l3, n1, n2, n3, reflect;
    std::vector<char*> parsed;

    while (st != NULL)
    {
        std::cout << st << std::endl;
        st = strtok (NULL, ",");
        parsed.push_back(st);
    }

    char* pos = strtok(parsed[0], " ");
    xi = atoi(pos);
    pos = strtok(NULL, " ");
    yi = atoi(pos);
    pos = strtok(NULL, " ");
    zi = atoi(pos);

    char* a = strtok(parsed[1], " ");
    ai = atoi(a);
    a = strtok(NULL, " ");
    bi = atoi(a);
    a = strtok(NULL, " ");
    ci = atoi(a);
    a = strtok(NULL, " ");
    di = atoi(a);

    reflect = atoi(parsed[2]);

    char* color = strtok(parsed[3], " ");
    c.r = atoi(color);
    color = strtok(NULL, " ");
    c.g = atoi(color);
    color = strtok(NULL, " ");
    c.b = atoi(color);

    /*char* normal = strtok(parsed[4], " ");
    n1 = atoi(normal);
    normal = strtok(NULL, " ");
    n2 = atoi(normal);
    normal = strtok(NULL, " ");
    n3 = atoi(normal);*/


    return new Plane(xi, yi, zi, ai, bi, ci, di, reflect, c);
}

Lumin* getLumin(char* st)
{
    SDL_Color c;
    int l1, l2, l3, power;
    std::vector<char*> parsed;

    while (st != NULL)
    {
        std::cout << st << std::endl;
        st = strtok (NULL, ",");
        parsed.push_back(st);
    }

    char* lumin = strtok(parsed[0], " ");
    l1 = atoi(lumin);
    lumin = strtok(NULL, " ");
    l2 = atoi(lumin);
    lumin = strtok(NULL, " ");
    l3 = atoi(lumin);

    char* color = strtok(parsed[1], " ");
    c.r = atoi(color);
    color = strtok(NULL, " ");
    c.g = atoi(color);
    color = strtok(NULL, " ");
    c.b = atoi(color);

    power = atoi(parsed[2]);

    return new Lumin(l1, l2, l3, c, power);
 }


void getCam(char* st, Camera** ca)
{
    int x,y,z;
    std::vector<char*> parsed;

    while (st != NULL)
    {
        std::cout << st << std::endl;
        st = strtok (NULL, ",");
        parsed.push_back(st);
    }
    char* i = strtok(parsed[0], " ");
    x = atoi(i);
    i = strtok(NULL, " ");
    y = atoi(i);
    i = strtok(NULL, " ");
    z = atoi(i);

    char* j = strtok(parsed[1], " ");
    double a = atoi(j);
    j = strtok(NULL, " ");
    double b = atoi(j);
    j = strtok(NULL, " ");
    double c = atoi(j);
    Ray u = Ray(a,b,c);

    char* k = strtok(parsed[2], " ");
    a = atoi(k);
    k = strtok(NULL, " ");
    b = atoi(k);
    k = strtok(NULL, " ");
    c = atoi(k);
    Ray v = Ray(a,b,c);
    
    *ca = new Camera(x,y,z,u,v);   
}

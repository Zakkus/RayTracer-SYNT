#include "parser.hh"

std::vector<Primitive *> parseScene(char** argv)
{
    std::vector<Primitive*> p;
    std::string st;
    std::ifstream fs(argv[1]);
    int n;

    getline(fs,st); 
    std::cout << st << std::endl;

    n = 1;
    while (n > 0)
    {
        getline(fs, st);
        std::cout << st << std::endl;
        p.push_back(getPrimitive(&st[0]));
        n--;
    }

    return p;
}

Primitive* getPrimitive(char* st)
{
    char* new_s = strtok (st,",");

    if (strcmp(new_s, "sphere") == 0)
        return getSphere(new_s);
    if (strcmp(new_s, "plane") == 0)
        return getPlane(new_s);
}

Sphere* getSphere(char* st)
{
    SDL_Color c;
    int cx, cy, cz, r;
    int l1, l2, l3, n1, n2, n3;
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

    char* color = strtok(parsed[2], " ");
    c.r = atoi(color);
    color = strtok(NULL, " ");
    c.g = atoi(color);
    color = strtok(NULL, " ");
    c.b = atoi(color);

    char* lumin = strtok(parsed[3], " ");
    l1 = atoi(lumin);
    lumin = strtok(NULL, " ");
    l2 = atoi(lumin);
    lumin = strtok(NULL, " ");
    l3 = atoi(lumin);

    char* normal = strtok(parsed[4], " ");
    n1 = atoi(normal);
    normal = strtok(NULL, " ");
    n2 = atoi(normal);
    normal = strtok(NULL, " ");
    n3 = atoi(normal);

    return new Sphere(cx, cy, cz, r, 1, c);
}

Plane* getPlane(char* st)
{
    SDL_Color c;
    int xi, yi, zi, ai, bi, ci, di;
    int l1, l2, l3, n1, n2, n3;
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

    char* color = strtok(parsed[2], " ");
    c.r = atoi(color);
    color = strtok(NULL, " ");
    c.g = atoi(color);
    color = strtok(NULL, " ");
    c.b = atoi(color);

    char* lumin = strtok(parsed[3], " ");
    l1 = atoi(lumin);
    lumin = strtok(NULL, " ");
    l2 = atoi(lumin);
    lumin = strtok(NULL, " ");
    l3 = atoi(lumin);

    char* normal = strtok(parsed[4], " ");
    n1 = atoi(normal);
    normal = strtok(NULL, " ");
    n2 = atoi(normal);
    normal = strtok(NULL, " ");
    n3 = atoi(normal);


    return new Plane(xi, yi, zi, ai, bi, ci, di, 1, c);
}

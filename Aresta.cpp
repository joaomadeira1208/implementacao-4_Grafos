#include "Aresta.h"

using namespace std;

Aresta::Aresta(int u, int v, int w)
    : u(u), v(v), w(w) {}

int Aresta::getU()
{
    return u;
}

int Aresta::getV()
{
    return v;
}

int Aresta::getW()
{
    return w;
}

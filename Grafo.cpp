#include "Grafo.h"
#include "Aresta.h"
#include <algorithm>

Grafo::Grafo() {}

void Grafo::addAresta(int u, int v, int w)
{
    Aresta e(u, v, w);
    arestas.push_back(e);
}

void Grafo::addVertice(int v)
{
    vertices.push_back(v);
}

void Grafo::ordenarArestas()
{
    sort(arestas.begin(), arestas.end(), [](Aresta e, Aresta edge)
         { return e.getW() < edge.getW(); });
}
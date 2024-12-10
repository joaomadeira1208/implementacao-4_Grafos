#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include "Aresta.h"

using namespace std;

class Grafo
{
private:
    vector<int> vertices;
    vector<Aresta> arestas;

public:
    Grafo();
    void addVertice(int v);
    void addAresta(int u, int v, int w);
    void ordenarArestas();
};

#endif
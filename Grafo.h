#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <unordered_map>
#include "Aresta.h"
#include "Vertice.h"
using namespace std;

class Grafo
{
private:
    vector<Vertice> vertices;
    vector<Aresta> arestas;
    unordered_map<string, Aresta> hashArestas;

public:
    Grafo();
    void addVertice(Vertice v);
    void addAresta(int u, int v, int w);
    void ordenarArestas();
    void printaGrafo();
    void geraGrid(vector<Pixel> pixels);
};

#endif
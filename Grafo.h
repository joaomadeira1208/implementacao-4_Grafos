#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <unordered_map>
#include <string>
#include "Vertice.h"
#include "Aresta.h"
class Segmentacao; // Declaração antecipada

class Grafo
{
private:
    std::vector<Vertice> vertices;
    std::vector<Aresta> arestas;
    std::unordered_map<std::string, Aresta> hashArestas;

public:
    Grafo();
    void addVertice(Vertice v);
    void addAresta(int u, int v, int w);
    void ordenarArestas();
    void printaGrafo();
    std::vector<Vertice> getVertices();
    std::vector<Aresta> getArestas();
    void criaArestas();
    void geraGrid(std::vector<Pixel> pixels);
    Segmentacao segmentar(int k);
};

#endif

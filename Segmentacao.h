#ifndef SEGMENTACAO_H
#define SEGMENTACAO_H
#include <unordered_map>
#include <vector>
#include "Grafo.h"
using namespace std;

class Segmentacao
{

private:
    Grafo grafo;
    unordered_map<int, int> hashComponentes;
    int k;

public:
    Segmentacao();
    Grafo getGrafo();
    void setGrafo(vector<Vertice> vertices, vector<Aresta> Arestas);
    unordered_map<int, int> getHash();
    int getComponenteDoVertice(int vertice);
    void inicializaHash(vector<Vertice> vertices);
    void setK(int k);

};

#endif
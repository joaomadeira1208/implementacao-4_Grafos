#ifndef SEGMENTACAO_H
#define SEGMENTACAO_H

#include <vector>
#include <unordered_map>
#include "Vertice.h"
#include "Aresta.h"

class Segmentacao {
private:
    std::vector<int> parent;    // Representante de cada vértice
    std::vector<int> size;      // Tamanho de cada componente
    std::unordered_map<int, int> maioresArestas; // Maior aresta de cada componente
    int k;                      // Parâmetro k para segmentação

public:
    Segmentacao();

    void initializeUnionFind(int n);
    int find(int u);
    void unionSets(int u, int v, int w);
    void setK(int k);
    int getK() const;
    int getSize(int raiz);
    std::unordered_map<int, int> getComponents();
    std::unordered_map<int, int>& getMaioresArestas();
};

#endif

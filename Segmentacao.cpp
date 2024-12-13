#include "Segmentacao.h"
#include <iostream>
#include <algorithm>
using namespace std;

Segmentacao::Segmentacao() : k(0) {}

void Segmentacao::initializeUnionFind(int n) {
    parent.resize(n);
    size.resize(n, 1); // Cada componente começa com tamanho 1
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Cada vértice é seu próprio pai
    }
    maioresArestas.clear();
    for (int i = 0; i < n; i++) {
        maioresArestas[i] = 0; // Inicializa as maiores arestas como 0
    }
}

int Segmentacao::find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]); 
    }
    return parent[u];
}


void Segmentacao::unionSets(int u, int v, int w) {
    int raizU = find(u);
    int raizV = find(v);

    if (raizU != raizV) {
        // União por tamanho
        if (size[raizU] < size[raizV]) {
            swap(raizU, raizV);
        }
        parent[raizV] = raizU;
        size[raizU] += size[raizV];

        maioresArestas[raizU] = max({maioresArestas[raizU], maioresArestas[raizV], w});
    }
}

void Segmentacao::setK(int k) {
    this->k = k;
}

int Segmentacao::getK() const {
    return k;
}

int Segmentacao::getSize(int raiz)
{
    return size[raiz];
}

unordered_map<int, int> Segmentacao::getComponents() {
    unordered_map<int, int> components;
    for (size_t i = 0; i < parent.size(); i++) {
        components[i] = find(i); // Obtém o líder de cada vértice
    }
    return components;
}

unordered_map<int, int>& Segmentacao::getMaioresArestas() {
    return maioresArestas;
}

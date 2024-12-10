#include "Grafo.h"
#include "Aresta.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

Grafo::Grafo() {}

void Grafo::addAresta(int u, int v, int w)
{
    if (hashArestas.find("(" + to_string(u) + ", " + to_string(v) + ")") != hashArestas.end())
    {
        return;
    }

    Aresta e(u, v, w);
    arestas.push_back(e);

    hashArestas["(" + to_string(u) + ", " + to_string(v) + ")"] = e;
}

void Grafo::addVertice(Vertice v)
{
    vertices.push_back(v);
}

void Grafo::ordenarArestas()
{
    sort(arestas.begin(), arestas.end(), [](Aresta e, Aresta edge)
         { return e.getW() < edge.getW(); });
}

void Grafo::printaGrafo()
{
    cout << "Vértices: " << endl;
    cout << "{";
    for (Vertice v : this->vertices)
    {
        cout << v.getV() << " ";
    }
    cout << "}" << endl;

    cout << "Arestas:" << endl;
    cout << "{";
    for (Aresta aresta : this->arestas)
    {
        cout << "{" << aresta.getU() << ", " << aresta.getV() << ", " << aresta.getW() << "}";
    }
    cout << "}";
}

void geraGrid(vector<Pixel> pixels)
{
    for (Pixel p : pixels)
    {
    }
}
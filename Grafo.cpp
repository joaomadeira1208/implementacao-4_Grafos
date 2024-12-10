#include "Grafo.h"
#include "Aresta.h"
#include <algorithm>
#include <iostream>
using namespace std;

Grafo::Grafo() {}

void Grafo::addAresta(int u, int v, int w)
{
    Aresta e(u, v, w);
    arestas.push_back(e);
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
    for(Vertice v : this->vertices)
    {
        cout << v.getV() << " ";
    }
    cout << "}" << endl;

    cout << "Arestas:" << endl;
    cout << "{";
    for(Aresta aresta : this->arestas)
    {   
        cout << "{" << aresta.getU() << ", " <<aresta.getV() << ", " << aresta.getW() << "}" ;
    }
    cout << "}";
}

void Grafo::geraGrid(vector<Pixel> pixels)
{
    int i = 0;
    for(Pixel p : pixels)
    {
        Vertice temp(p, i);
        addVertice(temp);
        i++;
    }
}
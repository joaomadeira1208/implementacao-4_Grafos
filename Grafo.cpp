#include "Grafo.h"
#include "Aresta.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include "Segmentacao.h"
using namespace std;

Grafo::Grafo() {}

vector<Vertice> Grafo::getVertices()
{
    return this->vertices;
}

vector<Aresta> Grafo::getArestas()
{
    return this->arestas;
}

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

 
void Grafo::criaArestas()
{
    int width = vertices.back().getPixel().getX() + 1;
    int height = vertices.back().getPixel().getY() + 1;

    for (Vertice &v : vertices)
    {
        Pixel p = v.getPixel();
        int x = p.getX();
        int y = p.getY();
        int currentVerticeIndex = v.getV();

        vector<pair<int, int>> vizinhos = {
            {-1, -1}, {0, -1}, {1, -1},
            {-1, 0},           {1, 0},
            {-1, 1}, {0, 1}, {1, 1}};

        for (auto [dx, dy] : vizinhos)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height)
            {
                int neighborIndex = ny * width + nx;
                Pixel neighborPixel = vertices[neighborIndex].getPixel();

                // Calcula a distância euclidiana entre os pixels
                int dr = p.getR() - neighborPixel.getR();
                int dg = p.getG() - neighborPixel.getG();
                int db = p.getB() - neighborPixel.getB();
                int weight = static_cast<int>(std::sqrt(dr * dr + dg * dg + db * db));

                // Cria uma aresta com o peso calculado
                addAresta(currentVerticeIndex, neighborIndex, weight);
            }
        }
    }
}

/*Grafo Grafo::geraGrafoNulo()
{
    Grafo retorno;

    for(Vertice v : this->vertices)
    {
        retorno.addVertice(v);
    }
    return retorno;
}
*/


float threshold(Grafo componente, int k)
{
    return k/(componente.getVertices().size());
}

float INT(Grafo componente)
{
    vector<Aresta> arestas = componente.getArestas();
    vector<float> pesos;
    for(Aresta e : arestas)
    {
        pesos.push_back(e.getW());
    }
    return *max_element(pesos.begin(), pesos.end());
}

float MInt(Grafo componente1, Grafo componente2)
{
    return min((INT(componente1) + threshold(componente1, 0)), (INT(componente2) + threshold(componente2, 0)));
}


Segmentacao Grafo::segmentar(int k)
{

    Segmentacao seg;

    //cout << "Entrou segmentar";
    seg.setK(k);
    //cout << "Entrou K";
    seg.setGrafo(getVertices(), {});
    //cout << "Entrou setGrafo";
    seg.inicializaHash(this->vertices);
    //cout << "Entrou hash";
    this->ordenarArestas();
    //cout << "Entrou ordenar";


    /*for(Aresta e : this->getArestas())
    {
        int u = e.getU();
        int v = e.getV();
        int w = e.getW();

        int componente_1 = seg.getComponente(u);
        int componente_2 = seg.getComponente(v);

        if(componente_1 != componente_2)
        {
            if(w <= MInt(componente_1, componente_2))
            {
                aux.addAresta(u,v,w);
            }
            hashcompoentes[v] = ha=sh
        }
    }*/

   return seg;
}


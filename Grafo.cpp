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

vector<Aresta>& Grafo::getArestas()
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


float threshold(int num_componente, int k)
{
    return k/num_componente;
}

float MInt(int componente1, int componente2, 
           int card_componente1, int card_componente2,
           unordered_map<int, int> maioresArestas, int k)
{
    int maior_aresta_componente_1 = maioresArestas[componente1];
    int maior_aresta_componente_2 = maioresArestas[componente2];
    return min((maior_aresta_componente_1 + threshold(card_componente1, k)), 
               (maior_aresta_componente_2 + threshold(card_componente2, k))
              );
}



Segmentacao Grafo::segmentar(int k) {
    Segmentacao seg;
    seg.setK(k);

    this->ordenarArestas(); // Ordena as arestas por peso

    int n = vertices.size();
    seg.initializeUnionFind(n); // Inicializa Union-Find

    int i = this->getArestas().size();
    auto& arestasRef = this->getArestas();

    for (auto& e : arestasRef) {
        
        int u = e.getU();
        int v = e.getV();
        int w = e.getW();

        int raizU = seg.find(u);
        int raizV = seg.find(v);

        if (raizU != raizV) {
            // Verifica o critério de segmentação
            if (w <= MInt(raizU, raizV, seg.getSize(raizU), seg.getSize(raizV), seg.getMaioresArestas(), k)) {
                seg.unionSets(u, v, w); // Une os componentes
            }
        }
        if (i % 1000 == 0) 
        { // Atualiza a cada 1000 iterações
            cout << "Faltam " << i << " iterações" << endl;
        }
        i--;
    }

    return seg;
}



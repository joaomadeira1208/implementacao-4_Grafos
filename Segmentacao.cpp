#include "Segmentacao.h"
#include <iostream>
using namespace std;

Segmentacao::Segmentacao()
{
    //setGrafo();
    //inicializaHash(grafo);
}

void Segmentacao::setGrafo(std::vector<Vertice> vertices, std::vector<Aresta> arestas)
{
    
}

void Segmentacao::inicializaHash(vector<Vertice> vertices)
{
    cout << vertices.size();
    int i = 0;
    for(Vertice v : vertices)
    {
        cout << "entrou no for";
        this->hashComponentes.emplace(v.getV(), i);
        cout << "printando hash: " << endl;
        cout << "Chave: " << v.getV() << " " << "Valor: " << hashComponentes.at(v.getV()) << endl;
        i++;
    }

}

unordered_map<int, int> Segmentacao::getHash()
{
    return this->hashComponentes;
}

void Segmentacao::setK(int k)
{
    this->k = k;
}
#include "Grafo.h"
#include "ImageHandler.h"
#include "Pixel.h"
#include "Segmentacao.h"
#include <vector>
#include <iostream>
#include <unordered_set>

//Para Compilar use: 
//g++ -o programa *.cpp -std=c++17


int main()
{
    ImageHandler ih("input.ppm");
    vector<Pixel> pixels = ih.loadImage();

    cout << "Pixels carregados: " << pixels.size() << endl;
    
    Grafo grafo;

    //cout << (int)pixels[187].getR() << ", " << (int)pixels[187].getG() << (int)pixels[187].getB() << endl;

    for (Pixel p : pixels)
    {
        //cout << "Pixel: (" << p.getX() << ", " << p.getY() << ") - R: " << (int)p.getR() << " G: " << (int)p.getG() << " B: " << (int)p.getB() << endl;
    }

    grafo.geraGrid(pixels);
    grafo.criaArestas();

    Segmentacao seg = grafo.segmentar(300); // Segmentar com k = 300
    unordered_map<int, int> components = seg.getComponents();

    // Usando um set para armazenar os componentes únicos
    unordered_set<int> uniqueComponents;

    for (const auto& [vertice, componente] : components) {
        // Adiciona o componente ao set, garantindo que ele seja único
        uniqueComponents.insert(componente);
    }

    // Exibe a quantidade de componentes únicos
    cout << "Quantidade de componentes únicos: " << uniqueComponents.size() << endl;
    return 0;
}

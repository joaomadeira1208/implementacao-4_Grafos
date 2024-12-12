#include "Grafo.h"
#include "ImageHandler.h"
#include "Pixel.h"
#include "Segmentacao.h"
#include <vector>
#include <iostream>

//Para Compilar use: 
//g++ -o programa *.cpp -std=c++17


int main()
{
    ImageHandler ih("output.ppm");
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
    grafo.segmentar(0);
    return 0;
}

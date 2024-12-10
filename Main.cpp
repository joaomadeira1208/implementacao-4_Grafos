#include "Grafo.h"
#include "ImageHandler.h"
#include "Pixel.h"
#include <vector>
#include <iostream>

int main()
{
    ImageHandler ih("output.ppm");
    vector<Pixel> pixels = ih.loadImage();

    cout << "Pixels carregados: " << pixels.size() << endl;
    
    Grafo grafo;

    
    
    return 0;
}

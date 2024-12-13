#include "Grafo.h"
#include "ImageHandler.h"
#include "Pixel.h"
#include "Segmentacao.h"
#include <vector>
#include <iostream>

// Para Compilar use:
// g++ -o programa *.cpp -std=c++17

int main()
{
    ImageHandler ih("input.ppm");
    vector<Pixel> pixels = ih.loadImage();

    vector<Vertice> vertices;
    unordered_map<int, int> hashComponentes;

    int index_1 = 0;
    int index_2 = 0;

    cout << "Pixels carregados: " << pixels.size() << endl;
    for (int i = 0; i < pixels.size(); i++)
    {
        if (i < 2)
        {
            cout << "GET X: " << " " << pixels[i].getX()
                 << endl;
            cout << "GET Y: " << " " << pixels[i].getY() << endl;
        }
        vertices.emplace_back(Vertice(pixels[i], i));
        hashComponentes[i] = index_1;

        index_2++;

        if (index_2 == 11594)
        {
            index_1++;
            index_2 = 0;
        }
    }

    ih.saveImage(hashComponentes, vertices);

    return 0;
}

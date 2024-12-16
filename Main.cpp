#include "Grafo.h"
#include "ImageHandler.h"
#include "Pixel.h"
#include "Segmentacao.h"
#include <vector>
#include <iostream>
#include <unordered_set>

// Para Compilar use:
// g++ -o programa *.cpp -std=c++17

void applyGaussian(const string &inputFile, const string &outputFile, float sigma)
{

    // Construct the Python command
    string command = "python script.py \"" + inputFile + ".ppm\" \"" + outputFile + ".ppm\" " + to_string(sigma);

    // Execute the command
    int result = system(command.c_str());

    // Check if the command executed successfully
    if (result != 0)
    {
        cerr << "Error occurred while attempting to convert the file." << endl;
    }
}

bool importarBibiliotecas()
{
    string command = "pip install numpy pillow scipy";

    int result = system(command.c_str());

    if (result != 0)
    {
        return false;
    }
    return true;
}

int main()
{
    if (!importarBibiliotecas())
    {
        cerr << "Erro ao importar as bibiliotecas, certifique que você possua o pip instalado." << endl;
        return 1;
    }

    applyGaussian("cavalo", "output", 0.8);

    ImageHandler ih("output.ppm");

    vector<Pixel> pixels = ih.loadImage();

    Grafo grafo;

    grafo.geraGrid(pixels);
    grafo.criaArestas();

    Segmentacao seg = grafo.segmentar(100'000);
    unordered_map<int, int> components = seg.getComponents();

    unordered_set<int> uniqueComponents;

    for (const auto &[vertice, componente] : components)
    {

        uniqueComponents.insert(componente);
    }

    cout << "Quantidade de componentes únicos: " << uniqueComponents.size() << endl;

    ih.saveImage(components, grafo.getVertices());

    return 0;
}

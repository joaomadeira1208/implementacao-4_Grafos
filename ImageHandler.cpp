#include "ImageHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

ImageHandler::ImageHandler(const string &path) : path(path) {}

vector<Pixel> ImageHandler::loadImage()
{
    ifstream file(path);
    if (!file.is_open())
    {
        throw runtime_error("Erro ao abrir o arquivo da imagem.");
    }

    string formato;
    file >> formato;

    cout << "Formato: " << formato << endl;

    if (formato != "P3")
    {
        throw runtime_error("Formato de imagem não suportado. Apenas PPM é suportado.");
    }

    int width, height, maxValue;
    file >> width >> height >> maxValue;

    cout << "Largura: " << width << endl;
    cout << "Altura: " << height << endl;
    cout << "Valor máximo: " << maxValue << endl;

    if (maxValue != 255)
    {
        throw runtime_error("Valor máximo de pixel diferente de 255.");
    }

    vector<Pixel> pixels;
    int r, g, b;
    int x = 0, y = 0;
    while (file >> r >> g >> b)
    {
        uint8_t red = static_cast<uint8_t>(r);
        uint8_t green = static_cast<uint8_t>(g);
        uint8_t blue = static_cast<uint8_t>(b);

        pixels.emplace_back(Pixel(x, y, red, green, blue));
        if (++x == width)
        {
            x = 0;
            y++;
        }
    }

    file.close();
    return pixels;
}
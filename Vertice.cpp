#include "Vertice.h"
#include "Pixel.h"

Vertice::Vertice(Pixel pixel, int v) 
    : pixel(pixel), v(v) {} // Inicializa o Pixel e v

Pixel Vertice::getPixel() {return pixel;}
int Vertice::getV() {return v;}
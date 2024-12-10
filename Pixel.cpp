#include "Pixel.h"

Pixel::Pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b)
    : x(x), y(y), r(r), g(g), b(b) {}

int Pixel::getX() { return x; }
int Pixel::getY() { return y; }
uint8_t Pixel::getR() { return r; }
uint8_t Pixel::getG() { return g; }
uint8_t Pixel::getB() { return b; }

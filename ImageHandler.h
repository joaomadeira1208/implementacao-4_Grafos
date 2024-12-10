#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H
#include <string>
#include <vector>
#include "Pixel.h"
using namespace std;

class ImageHandler
{
private:
    string path;

public:
    ImageHandler(const string &path);
    vector<Pixel> loadImage();
};

#endif
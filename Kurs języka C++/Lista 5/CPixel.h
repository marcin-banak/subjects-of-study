#ifndef LISTA_5_CPP_CPIXEL_H
#define LISTA_5_CPP_CPIXEL_H

#include "Pixel.h"
#include "TColor.h"

class CPixel : public Pixel{
private:
    TColor clr;
public:
    CPixel();
    CPixel(int x, int y, short r, short g, short b, short alpha);

    void Move(int x, int y);
};


#endif

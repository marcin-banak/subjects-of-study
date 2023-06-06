#ifndef LISTA_5_CPP_TCOLOR_H
#define LISTA_5_CPP_TCOLOR_H

#include "Color.h"

class TColor : virtual public Color {
private:
    short _alpha;
public:
    TColor();
    TColor(short r, short g, short b, short alpha);

    short GetAlpha();
    void SetAlpha(short val);
};

#endif

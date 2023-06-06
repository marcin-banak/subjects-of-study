#ifndef LISTA_5_CPP_TNCOLOR_H
#define LISTA_5_CPP_TNCOLOR_H

#include "TColor.h"
#include "NamedColor.h"

class TNColor : public TColor, public NamedColor {
public:
    TNColor();
    TNColor(short r, short g, short b, short alpha, std::string name);
};


#endif //LISTA_5_CPP_TNCOLOR_H

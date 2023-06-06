#ifndef LISTA_5_CPP_NAMEDCOLOR_H
#define LISTA_5_CPP_NAMEDCOLOR_H

#include "Color.h"
#include <string>

class NamedColor : virtual public Color{
private:
    std::string _name;
public:
    NamedColor();
    NamedColor(short r, short g, short b, std::string name);

    std::string GetName();
    void SetName(std::string name);
};

#endif
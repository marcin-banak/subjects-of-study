#include "TNColor.h"

TNColor::TNColor() : TNColor(0, 0, 0, 255, "") {}
TNColor::TNColor(short r, short g, short b, short alpha, std::string name) : TColor(r, g, b, alpha), NamedColor(r, g, b, name), Color(r, g, b){
    printf("Konstruktor TNColor\n");
}

#include "NamedColor.h"

NamedColor::NamedColor() : NamedColor(0, 0, 0, "") {}
NamedColor::NamedColor(short r, short g, short b, std::string name) : Color(r, g, b) {
    printf("Konstruktor NamedColor\n");
    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);
    this->_name = name;
}

std::string NamedColor::GetName() {
    return this->_name;
}
void NamedColor::SetName(std::string name) {
    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);
    this->_name = name;
}
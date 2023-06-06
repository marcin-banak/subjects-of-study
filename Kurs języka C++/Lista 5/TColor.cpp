#include "TColor.h"
#include <iostream>

TColor::TColor() : TColor(0, 0, 0, 255) {}

TColor::TColor(short r, short g, short b, short alpha) : Color(r, g, b) {
    printf("Konstruktor TColor\n");
    this->_alpha = alpha;
}

short TColor::GetAlpha() {
    return this->_alpha;
}

void TColor::SetAlpha(short val) {
    this->_alpha = val;
}
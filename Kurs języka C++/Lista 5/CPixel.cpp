#include "CPixel.h"
#include <stdexcept>

CPixel::CPixel() : CPixel(0, 0, 0, 0, 0, 255) {}

CPixel::CPixel(int x, int y, short r, short g, short b, short alpha) : Pixel(x, y) {
    this->clr = TColor(r, g, b, alpha);
}

void CPixel::Move(int x, int y) {
    x = this->GetX() + x;
    y = this->GetY() + y;

    if (x < 0 || x > this->GetWidth() ||
        y < 0 || y > this->GetHeight())
        throw std::invalid_argument("Pixel przesuniety o dany wketor wychodzi poza ekran!\n");

    this->SetX(x);
    this->SetY(y);
}
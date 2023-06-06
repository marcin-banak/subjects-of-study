#include "Color.h"
#include <stdexcept>

Color::Color() : Color(0, 0, 0) {}

Color::Color(short r, short g, short b) {
    printf("Konstruktor Color\n");
    if ((r > 255 || r < 0) ||
        (b > 255 || b < 0) ||
        (g > 255 || g < 0)) {
        throw std::invalid_argument("bledna wartosc koloru!\n");
    }
    this->_r = r;
    this->_g = g;
    this->_b = b;
}

short Color::GetR() {
    return this->_r;
}

short Color::GetG() {
    return this->_g;
}

short Color::GetB() {
    return this->_b;
}

void Color::SetR(short val) {
    this->_r = val;
}

void Color::SetG(short val) {
    this->_g = val;
}

void Color::SetB(short val) {
    this->_b = val;
}

void Color::Dim(double scalar) {
    if (scalar < 0 || scalar > 1)
        throw std::invalid_argument("Skalar nie nalezy do przedzialu 0 - 1!\n");
    this->_r *= scalar;
    this->_g *= scalar;
    this->_b *= scalar;
}

void Color::Lighten(double scalar) {
    if (scalar < 0)
        throw std::invalid_argument("Skalar jest mniejszy od 0!\n");
    Color *clr = (Color(255, 255, 255) - this)  ;
    if (scalar < 1)
        clr->Dim(scalar);
    else
        clr->Dim(1 / scalar);
    this->_r += clr->GetR();
    this->_g += clr->GetG();
    this->_b += clr->GetB();
}

Color *Color::Blend(Color *clr1, Color *clr2) {
    short r, g, b;
    r = (clr1->GetR() + clr2->GetR()) / 2;
    g = (clr1->GetG() + clr2->GetG()) / 2;
    b = (clr1->GetB() + clr2->GetB()) / 2;

    return new Color(r, g, b);
}

Color *Color::operator+(Color *clr) {
    short r, g, b;
    if (this->_r + clr->GetR() > 255)
        r = 255;
    else
        r = this->_r + clr->GetR();
    if (this->_g + clr->GetG() > 255)
        g = 255;
    else
        g = this->_g + clr->GetG();
    if (this->_b + clr->GetB() > 255)
        b = 255;
    else
        b = this->_b + clr->GetB();

    return new Color(r, g, b);
}

Color *Color::operator-(Color *clr) {
    short r, g, b;
    if (this->_r - clr->GetR() < 0)
        r = 0;
    else
        r = this->_r - clr->GetR();
    if (this->_g - clr->GetG() < 0)
        g = 0;
    else
        g = this->_g - clr->GetG();
    if (this->_b - clr->GetB() < 0)
        b = 0;
    else
        b = this->_b - clr->GetB();

    return new Color(r, g, b);
}

void Color::PrintClr() {
    printf("%d %d %d\n", this->_r, this->_g, this->_b);
}
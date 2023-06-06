#include "Pixel.h"
#include <cmath>

// Metody klasy Pixel.
Pixel::Pixel() : Pixel(0, 0) {}

Pixel::Pixel(int x, int y) {
    this->height = 1080;
    this->width = 1920;

    if (x < 0 || x > this->width)
        this->x = 0;
    else
        this->x = x;

    if (y < 0 || y > this->height)
        this->y = 0;
    else
        this->y = y;
}

int Pixel::GetX() const{
    return this->x;
}

int Pixel::GetY() const{
    return this->y;
}

int Pixel::GetHeight() {
    return this->height;
}

int Pixel::GetWidth() {
    return this->width;
}

void Pixel::SetX(int val) {
    this->x = val;
}

void Pixel::SetY(int val) {
    this->y = val;
}

// Funkcje zwracające dystans piksela.
int Pixel::DistT() {
    return this->y;
}

int Pixel::DistR() {
    return this->width - this->x;
}

int Pixel::DistD() {
    return this->height - this->y;
}

int Pixel::DistL() {
    return this->x;
}

void Pixel::PrintPixel() {
    printf("x: %d, y: %d\n", this->GetX(), this->GetY());
}

// Funkcje globalne.
int odleglosc(const Pixel &p, const Pixel &q) {
    return round(sqrt(pow((p.GetX() - q.GetX()), 2) + pow((p.GetY() - q.GetY()), 2)));
}

int odleglosc(const Pixel *p, const Pixel *q) {
    return round(sqrt(pow((p->GetX() - q->GetX()), 2) + pow((p->GetY() - q->GetY()), 2)));
}
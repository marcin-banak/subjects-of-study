#ifndef LISTA_5_CPP_PIXEL_H
#define LISTA_5_CPP_PIXEL_H

#include "TNColor.h"

class Pixel {
private:
    int x, y;
    int height;
    int width;
public:
    // Konstruktory
    Pixel();
    Pixel(int x, int y);

    // Gettery
    int GetX() const;
    int GetY() const;
    int GetHeight();
    int GetWidth();

    // Settery
    void SetX(int val);
    void SetY(int val);

    // Funkcje obliczjące odegłość piksela.
    int DistT();
    int DistR();
    int DistD();
    int DistL();

    void PrintPixel();
};

int odleglosc(const Pixel &p, const Pixel &q);
int odleglosc(const Pixel *p, const Pixel *q);

#endif

#ifndef LISTA_5_CPP_COLOR_H
#define LISTA_5_CPP_COLOR_H


class Color {
private:
    short _r, _g, _b;
public:
    // Konstruktory
    Color();
    Color(short r, short g, short b);

    // gettery
    short GetR();
    short GetG();
    short GetB();

    // settery
    void SetR(short val);
    void SetG(short val);
    void SetB(short val);

    // Funckja Dim() przyjmuje wartość z zakresu 0 - 1.
    void Dim(double scalar);
    void Lighten(double scalar);
    static Color *Blend(Color *clr1, Color *clr2);

    Color *operator+(Color *clr);
    Color *operator-(Color *clr);

    void PrintClr();
};

#endif

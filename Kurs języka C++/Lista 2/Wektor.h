#ifndef INC_2_LISTA_CPP_WEKTOR_H
#define INC_2_LISTA_CPP_WEKTOR_H

class Vector {
private:
    double x;
    double y;
public:
    Vector(double x, double y);
    Vector(Vector* v);
    double GetX();
    double GetY();
    void Invert();
};

#endif //INC_2_LISTA_CPP_WEKTOR_H

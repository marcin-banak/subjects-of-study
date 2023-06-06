#ifndef INC_2_LISTA_CPP_PUNKT_H
#define INC_2_LISTA_CPP_PUNKT_H

#include "Wektor.h"
#include "Prosta.h"

class Point {
private:
    double x, y;
public:
    Point(double x, double y);
    Point(Point* p);
    double GetX();
    double GetY();
    void SetX(double x);
    void SetY(double y);
    void SetPoint(double x, double y);
    void Translate(Vector* v);
    void Rotate(Point* p, double angle);
    void ReflectionByPoint(Point* p);
    void ReflectionByAxis(Line* l);
};

#endif //INC_2_LISTA_CPP_PUNKT_H

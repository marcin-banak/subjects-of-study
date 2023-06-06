#ifndef INC_2_LISTA_CPP_TROJKAT_H
#define INC_2_LISTA_CPP_TROJKAT_H

#include "Odcinek.h"

class Triangle {
private:
    Point* p1;
    Point* p2;
    Point* p3;
public:
    Triangle(Point p1, Point p2, Point p3);
    Triangle(Triangle* t);
    Point* GetP1();
    Point* GetP2();
    Point* GetP3();
};


#endif //INC_2_LISTA_CPP_TROJKAT_H

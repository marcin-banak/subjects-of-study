#ifndef INC_2_LISTA_CPP_PROSTA_H
#define INC_2_LISTA_CPP_PROSTA_H

#include <utility>

class Line {
private:
    double a;
    double b;
    double c;
public:
    Line(double a, double b, double c);
    Line(Line* l);
    double GetA();
    double GetB();
    double GetC();
    std::pair<double, double> Intersect(Line* l);
};

#endif //INC_2_LISTA_CPP_PROSTA_H

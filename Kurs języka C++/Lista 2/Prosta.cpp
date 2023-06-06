#include "Prosta.h"
#include <utility>
#include <stdexcept>

Line::Line(double a, double b, double c) {
    if (a == 0 && b == 0) {
        throw std::invalid_argument("Bledne dane dla prostej.\n");
    } else {
        this->a = a;
        this->b = b;
        this->c = c;
    }
}

Line::Line(Line *l) {
    if (l->GetA() == 0 && l->GetB() == 0) {
        throw std::invalid_argument("Bledne dane dla prostej.\n");
    } else {
        this->a = l->GetA();
        this->b = l->GetB();
        this->c = l->GetC();
    }
}

double Line::GetA() {
    return this->a;
}

double Line::GetB() {
    return this->b;
}

double Line::GetC() {
    return this->c;
}

std::pair<double, double> Line::Intersect(Line *l) {
    double determinant = this->a * l->GetB() - this->b * l->GetA();
    std::pair<double, double> point;
    if(determinant != 0) {
        point.first = (this->c * l->GetB() - this->b * l->GetC())/determinant;
        point.second = (this->a * l->GetC() - this->c * l->GetA())/determinant;
        return (point);
    } else {
        // nieokreślone
    }
}
#include "Wektor.h"

Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector::Vector(Vector *v) {
    this->x = v->GetX();
    this->y = v->GetY();
}

double Vector::GetX() {
    return this->x;
}

double Vector::GetY() {
    return this->y;
}

void Vector::Invert() {
    this->x = -this->x;
    this->y = -this->y;
}
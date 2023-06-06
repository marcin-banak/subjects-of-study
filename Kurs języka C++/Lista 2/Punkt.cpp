#include "Punkt.h"
#include "Prosta.h"
#include <cmath>
#include <utility>

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::Point(Point *p) {
    this->x = p->GetX();
    this->y = p->GetY();
}

double Point::GetX() {
    return this->x;
}

double Point::GetY() {
    return this->y;
}

void Point::SetX(double x) {
    this->x = x;
}

void Point::SetY(double y) {
    this->y = y;
}

void Point::SetPoint(double x, double y) {
    this->x = x;
    this->y = y;
}

void Point::Translate(Vector *v) {
    this->x += v->GetX();
    this->y += v->GetY();
}

void Point::Rotate(Point *p, double angle) {
    this->x = cos(angle) * (this->x - p->GetX()) - sin(angle) * (this->y - p->GetY()) + p->GetX();
    this->y = sin(angle) * (this->x - p->GetX()) + cos(angle) * (this->y - p->GetY()) + p->GetY();
}

void Point::ReflectionByPoint(Point *p) {
    Vector *v = new Vector(2 * (this->x - p->GetX()), 2 * (this->y - p->GetY()));
    v->Invert();
    this->Translate(v);
}

void Point::ReflectionByAxis(Line *l) {
    double a_prim, b_prim, c_prim;

    if (l->GetA() == 0) {
        a_prim = 1;
        b_prim = 0;
        c_prim = -this->GetX();
    } else if (l->GetB() == 0) {
        a_prim = 0;
        b_prim = 1;
        c_prim = -this->GetY();
    } else {
        a_prim = -1 / l->GetA();
        b_prim = l->GetB();
        c_prim = -(a_prim * this->GetX() + b_prim * this->GetY());
    }
    Line *l_perp = new Line(a_prim, b_prim, c_prim);
    std::pair<double, double> pair = l->Intersect(l_perp);
    Point *intersection = new Point(pair.first, pair.second);
    this->ReflectionByPoint(intersection);
}
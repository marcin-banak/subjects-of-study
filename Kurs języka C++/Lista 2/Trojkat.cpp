#include "Trojkat.h"

Triangle::Triangle(Point p1, Point p2, Point p3) {
    this->p1 = new Point(p1.GetX(), p1.GetY());
    this->p2 = new Point(p2.GetX(), p2.GetY());
    this->p3 = new Point(p3.GetX(), p3.GetY());
}

Triangle::Triangle(Triangle *t) {
    this->p1 = t->GetP1();
    this->p2 = t->GetP2();
    this->p3 = t->GetP3();
}

Point* Triangle::GetP1() {
    return this->p1;
}

Point* Triangle::GetP2() {
    return this->p2;
}

Point* Triangle::GetP3() {
    return this->p3;
}
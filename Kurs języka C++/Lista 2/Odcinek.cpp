#include "Punkt.h"
#include "Odcinek.h"
#include <cmath>

Section::Section(Point *p1, Point *p2) {
    this->p1 = new Point(p1->GetX(), p1->GetY());
    this->p2 = new Point(p2->GetX(), p2->GetY());
}

Section::Section(Section *s) {
    this->p1 = s->GetP1();
    this->p2 = s->GetP2();
}

Point *Section::GetP1() {
    return this->p1;
}

Point *Section::GetP2() {
    return this->p2;
}

double Section::Length() {
    return sqrt(pow((this->GetP2()->GetX() - this->GetP1()->GetX()),2) + pow((this->GetP2()->GetY() - this->GetP1()->GetY()), 2));
}

bool Section::BelongsTo(Line *l) {

}
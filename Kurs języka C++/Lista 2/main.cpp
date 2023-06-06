#include <iostream>
#include "Trojkat.h"
#include "Odcinek.h"
#include "Punkt.h"
#include "Wektor.h"
#include "Prosta.h"
#include <cmath>

using namespace std;

int main() {
    Point* p = new Point(1, 1);
    printf("Punkt przed przesunieciem: x=%.2f y=%.2f\n", p->GetX(), p->GetY());
    p->Translate(new Vector(1, 1));
    printf("Punkt po przesunieciu: x=%.2f y=%.2f\n", p->GetX(), p->GetY());
    p->SetPoint(1, 1);
    printf("Punkt przed obrotem: x=%.2f y=%.2f\n", p->GetX(), p->GetY());
    p->Rotate(new Point(0, 0), M_PI/4);
    printf("Punkt po obroceniu: x=%.2f y=%.2f\n", p->GetX(), p->GetY());
    p->SetPoint(1, 1);
    printf("Punkt przed odbiciu wzgledem punktu: x=%.2f y=%.2f\n", p->GetX(), p->GetY());
    p->ReflectionByPoint(new Point(0, 0));
    printf("Punkt po odbiciu wzgledem punktu: x=%.2f y=%.2f\n", p->GetX(), p->GetY());
    p->SetPoint(1, 1);
    printf("Punkt przed odbiciu wzgledem prostej: x=%.2f y=%.2f\n", p->GetX(), p->GetY());
    p->ReflectionByAxis(new Line(1, 1, 0));
    printf("Punkt po odbiciu wzgledem prostej: x=%.2f y=%.2f\n", p->GetX(), p->GetY());
    return 0;
}

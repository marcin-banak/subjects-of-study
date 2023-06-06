#ifndef INC_2_LISTA_CPP_ODCINEK_H
#define INC_2_LISTA_CPP_ODCINEK_H

#include "Punkt.h"
#include "Prosta.h"

class Section {
private:
    Point* p1;
    Point* p2;
public:
    Section(Point* p1, Point* p2);
    Section(Section* s);
    Point* GetP1();
    Point* GetP2();
    double Length();
    bool BelongsTo(Line *l);
};

#endif //INC_2_LISTA_CPP_ODCINEK_H

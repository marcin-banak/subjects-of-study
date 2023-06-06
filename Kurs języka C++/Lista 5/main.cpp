#include <iostream>
#include "Color.h"
#include "TColor.h"
#include "NamedColor.h"
#include "TNColor.h"
#include "Pixel.h"
#include "CPixel.h"

int main() {
    Color *clr = new Color(255, 128, 0);
    clr->Lighten(2);
    // ((new Color(255, 255, 255))->operator-(clr))->PrintClr();
    clr->PrintClr();

    Color *blend1 = new Color(0, 0, 0);
    Color *blend2 = new Color(255, 255, 255);
    (Color::Blend(blend1, blend2))->PrintClr();

    NamedColor *ndclr = new NamedColor(0, 0, 0, "czarny");
    std::cout << ndclr->GetName() << '\n';

    // Aby Zobaczyć sbhemat wywołania konstruktorów należy odkomentować
    // polecenie pritnf() w każdym z konstruktorów.

    printf("\n\nWywolania konstrukotrow dla obiektu TNColor:\n");
    TNColor *clr2 = new TNColor(255, 255, 255, 255, "bialy");
    printf("\n");

    CPixel *p1 = new CPixel(32, 43, 127, 127, 127, 255);
    CPixel *p2 = new CPixel(3, 4, 127, 127, 127, 255);
    CPixel p3(100, 100, 255, 0, 0, 255);
    CPixel p4(100, 100, 255, 0, 0, 255);

    try {
        p1->Move(-32, -43);
        p3.Move(100, 0);
    }
    catch (std::exception &e)
    {
        printf(e.what());
    }

    p1->PrintPixel();
    p3.PrintPixel();

    printf("odleglosc miedzy pikselami p1 i p2: %d\n", odleglosc(p1, p2));
    printf("odleglosc miedzy pikselami p3 i p4: %d\n", odleglosc(p3, p4));

    delete clr;
    delete blend1;
    delete blend2;
    delete ndclr;
    delete clr2;
    delete p1;
    delete p2;
    return 0;
}

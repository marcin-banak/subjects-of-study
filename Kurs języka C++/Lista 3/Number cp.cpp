#include <iostream>
#include "Number.hpp"

Number::Number() {
    this->first = new double[this->max_size];
    this->first[0] = 0;
    this->base = 0;
    this->current = 0;
}

Number::Number(double val) {
    this->first = new double[this->max_size];
    this->first[0] = val;
    this->base = 0;
    this->current = 0;
}

Number::Number(Number *temp) {

}

double Number::Pop() {
    double ToReturn = this->first[this->current];

    // Obecny element jest jedyny w historii.
    if (this->current == this->base)
        return ToReturn;

    // Zawijając wracamy na koniec listy.
    else if (this->current == 0)
        this->current = (this->max_size - 1);

    // Cofamy wskaźnik o jeden.
    else
        this->current--;
    return ToReturn;
}

void Number::Push(double val) {
    // Wpisanie wartości z nadpisaniem ostatniego rekordu.
    if (this->current + 1 == this->base)
    {
        this->current = this->base;
        this->first[this->current] = val;
        // Przepięcie wskaźnika base.
        if (this->base == (this->max_size - 1))
            this->base = 0;
        else
            this->base++;
    }

    // Wpisanie wartości do pamięci.
    else if (this->current == (this->max_size - 1))
    {
        this->current = 0;
        this->first[this->current] = val;
    }

    else
    {
        this->current = this->current + 1;
        this->first[this->current] = val;
    }
}
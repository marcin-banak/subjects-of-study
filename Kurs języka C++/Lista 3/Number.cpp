#include <iostream>
#include "Number.hpp"

Number::Number() {
    this->first = new double[this->max_size];
    this->first[0] = 0;
    this->base = this->first;
    this->current = this->first;
}

Number::Number(double val) {
    this->first = new double[this->max_size];
    this->first[0] = val;
    this->base = this->first;
    this->current = this->first;
}

Number::Number(Number *temp) {
    this->first = new double[this->max_size];
    this->base = this->first;
    this->current = this->first;

    int n;
    if (temp->GetCurrent() < temp->GetBase())
        n = (temp->GetMaxSize() - abs(temp->GetCurrent() - temp->GetBase()));
    else
        n = (temp->GetMaxSize() - (temp->GetMaxSize() - abs(temp->GetCurrent() - temp->GetBase())));
    double* aux = new double[n];
    for (int i = 0; i <= n; i++)
    {
        aux[i] = temp->Pop();
    }

    for (int j = n; j >= 0; j--)
    {
        this->Push(aux[j]);
        temp->Push(aux[j]);
    }
}

Number::Number(Number &&temp)
{
    this->first = temp.first;
    this->first[0] = *temp.GetCurrent();
    this->base = this->first;
    this->current = this->first;
}

Number::~Number()
{
    delete [] this->first;
}

double Number::Pop() {
    double ToReturn = *this->current;

    // Obecny element jest jedyny w historii.
    if (this->current == this->base)
        return ToReturn;

    // Zawijając wracamy na koniec listy.
    else if (this->current == this->first)
        this->current = (this->first + this->max_size - 1);

    // Cofamy wskaźnik o jeden.
    else
        this->current = this->current - 1;
    return ToReturn;
}

void Number::Push(double val) {
    // Wpisanie wartości z nadpisaniem ostatniego rekordu.
    if (this->current + 1 == this->base)
    {
        this->current = this->base;
        *this->current = val;
        // Przepięcie wskaźnika base.
        if (this->base == (this->first + this->max_size - 1))
            this->base = this->first;
        else
            this->base = this->base + 1;
    }

    // Wpisanie wartości do pamięci.
    else if (this->current == (this->first + this->max_size - 1))
    {
        this->current = this->first;
        *this->current = val;
        if (this->base == this->first)
            this->base = this->base + 1;
    }

    else
    {
        this->current = this->current + 1;
        *this->current = val;
    }
}
int Number::GetMaxSize()
{
    return this->max_size;
}
double* Number::GetBase()
{
    return this->base;
}
double* Number::GetCurrent()
{
    return this->current;
}
void Number::operator =(Number &&temp)
{
    int n;
    if (temp.GetCurrent() < temp.GetBase())
        n = (temp.GetMaxSize() - abs(temp.GetCurrent() - temp.GetBase()));
    else
        n = (temp.GetMaxSize() - (temp.GetMaxSize() - abs(temp.GetCurrent() - temp.GetBase())));
    double* aux = new double[n];
    for (int i = 0; i <= n; i++)
    {
        aux[i] = temp.Pop();
    }

    for (int j = n; j >= 0; j--)
    {
        this->Push(aux[j]);
        temp.Push(aux[j]);
    }
}
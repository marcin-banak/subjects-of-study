#include <iostream>
#include "Number.hpp"

int main() {
    Number* num = new Number(); // kopiujący
    // Number num = Number(); // przenoszący

    // Przy zmianie współczynnika mnożenia w warunku widać,
    // że zapętlanie tablicy działa.
    for (int i = 1; i < 3 * num->GetMaxSize(); i++)
    {
        num->Push(i * 5);
    }

    num->Push(13);
    num->Push(23);

    Number *copied = new Number(num);
    printf("Wlasciwy obiekt:\n");
    for (int i = 0; i < 1 * num->GetMaxSize(); i++)
    {
        printf("%d %.2f\n", i, num->Pop());
    }
    printf("\nSkopiowany obiekt:\n");
    for (int i = 0; i < 1 * copied->GetMaxSize(); i++)
    {
        printf("%d %.2f\n", i, copied->Pop());
    }

    Number num2 = Number(Number(123));
    printf("\n%f\n\n", num2.Pop());

    for (int i = 1; i < 3 * num->GetMaxSize(); i++)
    {
        num->Push(i * 5);
    }
    num2 = num;
    printf("Obiekt po wykonaniu num2 = num\n");
    for (int i = 0; i < 1 * copied->GetMaxSize(); i++)
    {
        printf("%d %.2f\n", i, num2.Pop());
    }

    num->Push(12);
    copied = num;
    printf("\nObiekt po wykonaniu copied = num\n");
    for (int i = 0; i < 1 * copied->GetMaxSize(); i++)
    {
        printf("%d %.2f\n", i, copied->Pop());
    }

    num->~Number();
    num2.~Number();
    copied->~Number();

    return 0;
}

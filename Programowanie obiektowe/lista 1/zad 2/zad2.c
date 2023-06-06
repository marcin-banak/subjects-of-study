/*
 * Marcin Banak
 * Lista 1, zadanie 3
 * gcc zad3.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Ulamek {
    int num; // licznik
    int denom; // mianownik
} Ulamek;

int NWD(int, int); // Liczy największy wspólny dzielnik.
int NWW(int, int); // Liczy najmniejszą wspólną wielokrotność.

Ulamek *nowy_ulamek(int, int); // Tworzy obiekt ułamka.
void show(Ulamek *); // Wypisuje wartość ułamka.
Ulamek *pAdd(Ulamek *, Ulamek *); // Zwraca wskaźnik na ułamek po wykonaniu dodawania.
void Add(Ulamek *, Ulamek *); // Zamiana wartości drugiego argumentu na obliczoną sumę ułamków.
Ulamek *pSub(Ulamek *, Ulamek *); // Zwraca wskaźnik na ułamek po wykonaniu odejmowania.
void Sub(Ulamek *, Ulamek *); // Zamiana wartości drugiego argumentu na obliczoną różnicę ułamków.
Ulamek *pMult(Ulamek *, Ulamek *); // Zwraca wskaźnik na ułamek po wykonaniu mnożenia.
void Mult(Ulamek *, Ulamek *); // Zamiana wartości drugiego argumentu na obliczony iloczyn ułamków.
Ulamek *pDiv(Ulamek *, Ulamek *); // Zwraca wskaźnik na ułamek po wykonaniu dzielenia.
void Div(Ulamek *, Ulamek *); // Zamiana wartości drugiego argumentu na obliczony iloraz ułamków.

int main() {
    int size = 10;
    Ulamek *fractions[size];
    for (int i = 0; i < size; i++) { // Tworzenie ułamków.
        fractions[i] = nowy_ulamek(i, i + 1);
    }

    for (int i = 0; i < size; i++) { // Wypisanie ułamków.
        printf("%d: ", i);
        show(fractions[i]);
    }

    printf("\nDodaje "); // Dodawanie.
    show(fractions[3]);
    printf("do ");
    show(fractions[6]);
    printf("Wynik \"pAdd\": ");
    show(pAdd(fractions[3], fractions[6]));
    Add(fractions[3], fractions[6]);
    printf("Wynik \"Add\": ");
    show(fractions[6]);

    printf("\nOdejmuje "); // Odejmowanie.
    show(fractions[2]);
    printf("od ");
    show(fractions[4]);
    printf("Wynik \"pSub\": ");
    show(pSub(fractions[2], fractions[4]));
    Sub(fractions[2], fractions[4]);
    printf("Wynik \"Sub\": ");
    show(fractions[4]);

    printf("\nMnoze "); // Mnożenie.
    show(fractions[1]);
    printf("przez ");
    show(fractions[9]);
    printf("Wynik \"pMult\": ");
    show(pMult(fractions[9], fractions[1]));
    Mult(fractions[9], fractions[1]);
    printf("Wynik \"Sub\": ");
    show(fractions[1]);

    printf("\nDziele "); // Dzielenie.
    show(fractions[4]);
    printf("przez ");
    show(fractions[8]);
    printf("Wynik \"pDiv\": ");
    show(pDiv(fractions[8], fractions[4]));
    Div(fractions[8], fractions[4]);
    printf("Wynik \"Sub\": ");
    show(fractions[4]);

    return 0;
}

int NWD(int a, int b) {
    if (b != 0)
        return NWD(b, a % b);
    return a;
}

int NWW(int a, int b) {
    return ((a * b) / NWD(a, b));
}

Ulamek *nowy_ulamek(int num, int denom) {
    Ulamek *temp = malloc(sizeof(Ulamek));
    int nwd = NWD(num, denom);
    temp->num = (num / nwd);
    temp->denom = (denom / nwd);
    return temp;
}

void show(Ulamek *fraction) {
    printf("%f\n", (double) ((double) (fraction->num) / (double) (fraction->denom)));
}

Ulamek *pAdd(Ulamek *a, Ulamek *b) {
    int nww = NWW(a->denom, b->denom);
    int num = (a->num * (nww / a->denom)) + (b->num * (nww / b->denom));
    int denom = nww;
    return nowy_ulamek(num, denom);
}

void Add(Ulamek *a, Ulamek *b) {
    int nww = NWW(a->denom, b->denom);
    int num = (a->num * (nww / a->denom)) + (b->num * (nww / b->denom));
    int denom = nww;
    int nwd = NWD(num, denom);
    b->num = (num / nwd);
    b->denom = (denom / nwd);
}

Ulamek *pSub(Ulamek *a, Ulamek *b) {
    int nww = NWW(a->denom, b->denom);
    int num = (b->num * (nww / b->denom)) - (a->num * (nww / a->denom));
    int denom = nww;
    return nowy_ulamek(num, denom);
}

void Sub(Ulamek *a, Ulamek *b) {
    int nww = NWW(a->denom, b->denom);
    int num = (b->num * (nww / b->denom)) - (a->num * (nww / a->denom));
    int denom = nww;
    int nwd = NWD(num, denom);
    b->num = (num / nwd);
    b->denom = (denom / nwd);
}

Ulamek *pMult(Ulamek *a, Ulamek *b) {
    return nowy_ulamek((a->num * b->num), (a->denom * b->denom));
}

void Mult(Ulamek *a, Ulamek *b) {
    b->num *= a->num;
    b->denom *= a->denom;
    int nwd = NWD(b->num, b->denom);
    b->num = (b->num / nwd);
    b->denom = (b->denom / nwd);
}

Ulamek *pDiv(Ulamek *a, Ulamek *b) {
    return nowy_ulamek((a->denom * b->num), (a->num * b->denom));
}

void Div(Ulamek *a, Ulamek *b) {
    b->num *= a->denom;
    b->denom *= a->num;
    int nwd = NWD(b->num, b->denom);
    b->num = (b->num / nwd);
    b->denom = (b->denom / nwd);
}
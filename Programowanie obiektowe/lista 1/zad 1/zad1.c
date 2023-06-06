/*
 * Marcin Banak
 * Lista 1, zadanie 1
 * gcc zad1.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Figura {
    double x;
    double y;
    double h; // Pole potrzebne tylko do obslugi trojkata.
    double size; // Przyjmuje długość boków lub wartość promienia.
    int type; // Reprezentuje typ wybranej figury 0 - koło, 1 - kwadrat, 2 - trójkąt.
} Figura;

Figura *init_shape(double, double, double, double, int);

float pole(Figura *); // Wylicza pole figury f.
void przesun(Figura *, float, float); // Przesuwa f o wektor (x, y).
void show(Figura *); // Wypisuje informacje o figurze (typ, położenie).
float sumapol(Figura **, int); // Oblicza sumę pól figur znajdujących się w tablicy (size jest rozmiarem tablicy).

int main() {
    int size = 4;

    Figura *shapes[size];
    shapes[0] = init_shape(-1, 2, 3.6, 3.6, 1);
    shapes[1] = init_shape(-3, 23, 5.7, 5.7, 0);
    shapes[2] = init_shape(5, 2, 12.3, 12.3, 2);
    shapes[3] = init_shape(4, 3, 4.34, 15, 2);

    for (int i = 0; i < size; i++) { // wypisanie wszystkich figur
        printf("Figura %d:\n", i + 1);
        show(shapes[i]);
    }

    printf("\nPrzesuwamy figure:\n");
    show(shapes[0]);
    printf("o wektor [1.5 , 4]\n");
    przesun(shapes[0], 1.5, 4);
    printf("Figura po przesunieciu: \n");
    show(shapes[0]);

    printf("\nSuma pol wynosi %.2f", sumapol(shapes, size));

    return 0;
}

Figura *init_shape(double x, double y, double h, double size, int type) {
    if (size <= 0) {
        fprintf(stderr, "Niepoprawny parametr dłguości boku.\n");
        return NULL;
    }
    if (type < 0 || type > 2) {
        fprintf(stderr, "Niepoprawny typ figury.\n");
        return NULL;
    }
    if (h <= 0) {
        fprintf(stderr, "Niepoprawny parametr wysokosci.\n");
        return NULL;
    }
    Figura *temp = malloc(sizeof(Figura));
    temp->x = x;
    temp->y = y;
    temp->h = h;
    temp->size = size;
    temp->type = type;
    return temp;
}

float pole(Figura *f) {
    switch (f->type) {
        case 0:
            return M_PI * f->size * f->size;
        case 1:
            return f->size * f->size;
        case 2:
            return (f->size * f->h) / 2;
    }
}

void przesun(Figura *f, float x, float y) {
    f->x += x;
    f->y += y;
}

void show(Figura *f) {
    switch (f->type) {
        case 0:
            printf("kolo bok: %.2f ", f->size);
            break;
        case 1:
            printf("kwadrat bok: %.2f ", f->size);
            break;
        case 2:
            printf("trojkat promien: %.2f wysokosc: %.2f ", f->size, f->h);
            break;
    }
    printf("x: %.2f, y: %.2f pole: %.2f\n", f->x, f->y, pole(f));

}

float sumapol(Figura *f[], int size) {
    float field = 0;
    for (int i = 0; i < size; i++) {
        field += pole(f[i]);
    }
    return field;
}
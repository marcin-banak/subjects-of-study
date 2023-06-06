#ifndef TAPE
#define TAPE

#include "task.h"

typedef struct tape
{
    int val;
    struct tape *next;
} tape;

tape *InitTapeVal(int); // funkcja inicjalizujaca wartosc z tasmy
tape *GetTapeVal(FILE*, bool*); // funkcja wstawiajca wartosc na koniec listy danych
void InsertTapeVal(tape *tasks, tape *task); // funkcja wstawiajca polecenie na koniec listy tasks
bool CheckTape(tape*, task*, bool*); // funkcja sprawdzajaca czy na tasmie sa jeszcze jakies wartosci do wczytania
void PrintTape(tape*); // funkcja pomocnicza wypisujaca tasme


#endif // TAPE

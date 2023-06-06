#ifndef MEMORY
#define MEMORY

#include "task.h"

typedef struct MemCell
{
    int val;
    int address;
    struct MemCell *next;
} MemCell;

MemCell* InitMemCell(int, int); // funkcja inicjalizujaca element pamieci maszyny RAM
void InsertMemCell(MemCell *, int, int); // funkcja wstawiajaca komorke pamieci
MemCell* FindAddress(MemCell*, int); // funkcja wyszukujaca komorke pamieci o konkretnym adresie
MemCell* GetCell(MemCell*, task*, bool*); // funkcja zwracajaca komorke pamieci sprawdzajac przy tym czy sposob zapytania o nia jest prawidlowy
MemCell* GetCellMake(MemCell*, task*, bool*); // jak wyzej ale dodatkowo tworzy komorke pamieci gdy jest to mozliwe
void PrintCells(MemCell*);

#endif // MEMORY
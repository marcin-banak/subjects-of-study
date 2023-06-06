#ifndef UTILS
#define UTILS

#include "memory.h"
#include "task.h"
#include "tape.h"

void ExecuteTasks(task*, MemCell*, tape*, tape*); // funkcja wykonujaca polecenie
int StrToInt(char*); // funkcja konwertujaca ze str do int
void FreeMemory(task*, MemCell*, tape*, tape*); // funkcja zwalniajaca pamiec
void Help(); // funkcja dotyczaca interfejsu programu
#endif // UTILS

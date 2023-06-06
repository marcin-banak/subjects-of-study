#ifndef TASK
#define TASK

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct task
{
    char *arg;
    char *command;
    char *label;
    struct task *next;
} task;

task *InitTask(char*, char*, char*); // funkcja inicjalizujaca strukture polecenia
task *GetTask(FILE*, bool*); // funkcja tworzaca polecenie ze wczytanymi danymi
void InsertTask(task*, task*); // funkcja wstawiajca polecenie na koniec listy tasks
task *FindLabeledTask(task*, task*, bool*); // funkcja zwraca polecenie o konkretnej etykiecie
void PrintTasks(task*); // funkcja pomocnicza wypisujaca tablice polecen tasks

#endif // TASK

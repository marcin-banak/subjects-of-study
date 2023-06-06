#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "tape.h"

tape *InitTapeVal(int val) // funkcja inicjalizujaca wartosc z tasmy
{
    tape *temp = malloc(sizeof(tape));
    temp->val = val;
    temp->next = NULL;
    return temp;
}
tape *GetTapeVal(FILE *file, bool *scanning) // funkcja wstawiajca wartosc na koniec listy danych
{
    char val[60];
    fscanf(file, "%s", val);
    if (strcmp(val, "koniec") == 0)
    {
        *scanning = false;
        return NULL;
    }
    return InitTapeVal(StrToInt(val));
}
void InsertTapeVal(tape *tape_root, tape *val) // funkcja wstawiajca wartosc na koniec listy danych
{
    tape *curr = tape_root;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = val;
}
bool CheckTape(tape *tape_mem, task* curr, bool *ValidTask) // funkcja sprawdzajaca czy na tasmie sa jeszcze jakies wartosci do wczytania
{
    if (tape_mem == NULL)
    {
        fprintf(stderr, "polecenie \"%s %s %s\" probuje wczytac dane z pustej tasmy\n", curr->command, curr->arg, curr->label);
        *ValidTask = false;
        return false;
    }
    return true;
}
void PrintTape(tape *tape_mem) // funkcja pomocnicza wypisujaca tasme
{
    tape *curr = tape_mem;
    while (curr != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
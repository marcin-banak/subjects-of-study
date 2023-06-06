#include "memory.h"
#include "task.h"
#include "utils.h"
#include <stdlib.h>
#include <stdbool.h>

// Funkcje dotyczace MemCell
MemCell* InitMemCell(int val, int address) // funkcja inicjalizujaca element pamieci maszyny RAM
{
    MemCell *temp = malloc(sizeof(MemCell));
    temp->val = val;
    temp->address = address;
    temp->next = NULL;
    return temp;
}
void InsertMemCell(MemCell *var_mem, int val, int index) // funkcja wstawiajaca komorke pamieci
{
    MemCell *curr = var_mem;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = InitMemCell(val, index);
}
MemCell* FindAddress(MemCell *var_mem, int address) // funkcja zwraca komorke o podanym adresie
{
    MemCell *curr = var_mem;
    while (curr != NULL)
    {
        if (curr->address == address)
            return curr;
        curr = curr->next;
    }
    return curr; // funkcja zwroci NULL jesli nie znajdzie komorki o podanym adresie
}
MemCell* GetCell(MemCell *var_mem, task *curr, bool *ValidTask) // funkcja zwracajaca komorke pamieci sprawdzajac przy tym czy sposob zapytania o nia jest prawidlowy
{
    MemCell *cell = NULL;
    if (curr->arg[0] == '^') // musimy uzyc adresu ktory jest wartoscia przechowywana w innej komorce
    {
        //printf("polecenie z ^");
        MemCell *temp = FindAddress(var_mem, StrToInt(curr->arg));
        if (temp == NULL) // uzyskany adres nie istnieje wiec nie mozemy wziac z niego wartosci
        {
            fprintf(stderr, "\nPolecenie \"%s %s %s\" probuje odwolac sie do nieistniejacej komorki pamieci!\n", curr->command, curr->arg, curr->label);
            *ValidTask = false;
            return NULL;
        }
        else // adres z argumentu istnieje
        {
            cell = FindAddress(var_mem, temp->val); // bierzemy adres rowny wczesniej znalezionej wartosci z komorki
            if (cell == NULL) // uzyskany adres nie istnieje
                fprintf(stderr, "\nPolecenie \"%s %s %s\" probuje odwolac sie do nieistniejacej komorki pamieci!\n", curr->command, curr->arg, curr->label);
        }
        return FindAddress(var_mem, temp->val);
    }
    else // odwolujemy sie bezposrednio do adresu z argumentu
    {
        //printf("polecenie bez ^");
        cell = FindAddress(var_mem, StrToInt(curr->arg));
        if (cell == NULL) // uzyskany adres nie istnieje
            fprintf(stderr, "\nPolecenie \"%s %s %s\" probuje odwolac sie do nieistniejacej komorki pamieci!\n", curr->command, curr->arg, curr->label);
        return FindAddress(var_mem, StrToInt(curr->arg));
    }
}
MemCell* GetCellMake(MemCell *var_mem, task *curr, bool *ValidTask) // jak wyzej ale dodatkowo tworzy komorke pamieci gdy jest to mozliwe
{
    MemCell *cell = NULL;
    if (curr->arg[0] == '^') // musimy uzyc adresu ktory jest wartoscia przechowywana w innej komorce
    {
        //printf("polecenie z ^");
        MemCell *temp = FindAddress(var_mem, StrToInt(curr->arg));
        if (temp == NULL) // uzyskany adres nie istnieje wiec nie mozemy wziac z niego wartosci
        {
            fprintf(stderr, "\nPolecenie \"%s %s %s\" probuje odwolac sie do nieistniejacej komorki pamieci!\n", curr->command, curr->arg, curr->label);
            *ValidTask = false;
            return NULL;
        }
        else // adres z argumentu istnieje
        {
            cell = FindAddress(var_mem, temp->val); // bierzemy adres rowny wczesniej znalezionej wartosci z komorki
            if (cell == NULL) // jezeli adres nie  istnieje inicjalizujemy nowa komorke
                InsertMemCell(var_mem, 0, temp->val);
        }
        return FindAddress(var_mem, temp->val);
    }
    else // odwolujemy sie bezposrednio do adresu z argumentu
    {
        //printf("polecenie bez ^");
        cell = FindAddress(var_mem, StrToInt(curr->arg));
        if (cell == NULL) // jezeli adres nie  istnieje inicjalizujemy nowa komorke
            InsertMemCell(var_mem, 0, StrToInt(curr->arg));
        return FindAddress(var_mem, StrToInt(curr->arg));
    }
}
void PrintCells(MemCell *var_mem)
{
    MemCell *curr = var_mem;
    while(curr != NULL)
    {
        printf("val: %d adres: %d\n", curr->val, curr->address);
        curr = curr->next;
    }
}
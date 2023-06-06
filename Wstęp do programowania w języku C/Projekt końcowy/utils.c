#include "utils.h"
#include <string.h>
int StrToInt(char *word)
{
    int n = strlen(word); int base = 10; int res = 0; int sign = 1;
    if (word[0] == '-')
        sign = -1;
    for (int i = 0; i < n; i++)
    {
        if (word[i] >= '0' && word[i] <= '9')
        {
            res += (int) (word[i] - '0');
            res *= base;
        }
    }
    return (sign * res) / 10;
}
void ExecuteTasks(task *task_mem, MemCell *var_mem, tape *tape_inp, tape *tape_out) // funkcja wykonujaca polecenie
{
    bool ValidTask = true;
    task *curr = task_mem;
    while (ValidTask && curr != NULL)
    {
        //printf("%s %s %s\n", curr->command, curr->arg, curr->label); //odkomentowac aby zobaczyc na ktorym poleceniu sie zawiesza
        if (strcmp(curr->command, "read") == 0)
        {
            if (curr->arg[0] == '=')
            {
                fprintf(stderr, "Polecenie \"%s %s %s\" ma bledny argument\n", curr->command, curr->arg, curr->label);
                ValidTask = false;
            }
            else
            {
                MemCell *cell = GetCellMake(var_mem, curr, &ValidTask);
                if (ValidTask && CheckTape(tape_inp, curr, &ValidTask)) // jesli istnieje komorka pamieci lub mozna ja stworzyc i sa jakies wejsciowe dane
                {
                    cell->val = tape_inp->val;
                    tape_inp = tape_inp->next;
                }
            }
        }
        else if (strcmp(curr->command, "write") == 0)
        {
            if (curr->arg[0] == '=')
            {
                InsertTapeVal(tape_out, InitTapeVal(StrToInt(curr->arg)));
            }
            else
            {
                MemCell *cell = GetCell(var_mem, curr, &ValidTask);
                if (ValidTask && cell != NULL)
                    InsertTapeVal(tape_out, InitTapeVal(cell->val));
            }
        }
        else if (strcmp(curr->command, "load") == 0)
        {
            if (curr->arg[0] == '=')
            {
                var_mem->val = StrToInt(curr->arg);
            }
            else
            {
                MemCell *cell = GetCell(var_mem, curr, &ValidTask);
                if (ValidTask && cell != NULL)
                    var_mem->val = cell->val; // wyciagniecie wartosci z komorki o konkretnym adresie i wlozenie do akumulatora
            }
        }
        else if (strcmp(curr->command, "store") == 0)
        {
            if (curr->arg[0] == '=')
            {
                fprintf(stderr, "Polecenie \"%s %s %s\" ma bledny argument\n", curr->command, curr->arg, curr->label);
                ValidTask = false;
            }
            else
            {
                MemCell *cell = GetCellMake(var_mem, curr, &ValidTask);
                if (ValidTask && cell != NULL)
                    cell->val = var_mem->val; // wlozenie wartosci z akumulatora do komorki o podanym adresie
            }
        }
        else if (strcmp(curr->command, "add") == 0)
        {
            if (curr->arg[0] == '=')
            {
                var_mem->val += StrToInt(curr->arg);
            }
            else
            {
                MemCell *cell = GetCell(var_mem, curr, &ValidTask);
                if (ValidTask && cell != NULL)
                    var_mem->val += cell->val;
            }
        }
        else if (strcmp(curr->command, "sub") == 0)
        {
            if (curr->arg[0] == '=')
            {
                var_mem->val -= StrToInt(curr->arg);
            }
            else
            {
                MemCell *cell = GetCell(var_mem, curr, &ValidTask);
                if (ValidTask && cell != NULL)
                    var_mem->val -= cell->val;
            }
        }
        else if (strcmp(curr->command, "mult") == 0)
        {
            if (curr->arg[0] == '=')
            {
                var_mem->val *= StrToInt(curr->arg);
            }
            else
            {
                MemCell *cell = GetCell(var_mem, curr, &ValidTask);
                if (ValidTask && cell != NULL)
                    var_mem->val *= cell->val;
            }
        }
        else if (strcmp(curr->command, "div") == 0)
        {
            if (StrToInt(curr->arg) == 0)
            {
                fprintf(stderr, "Polecenie \"%s %s %s\" probuje dzielic przez 0\n", curr->command, curr->arg, curr->label);
                ValidTask = false;
            }
            else if (curr->arg[0] == '=')
            {
                var_mem->val /= StrToInt(curr->arg);
            }
            else
            {
                MemCell *cell = GetCell(var_mem, curr, &ValidTask);
                if (ValidTask && cell != NULL)
                    var_mem->val /= cell->val;
            }
        }
        else if (strcmp(curr->command, "jump") == 0)
        {
            if (curr->arg[0] == '=')
            {
                fprintf(stderr, "Polecenie \"%s %s %s\" ma bledny argument\n", curr->command, curr->arg, curr->label);
                ValidTask = false;
            }
            else
            {
                task *temp = FindLabeledTask(task_mem, curr, &ValidTask);
                if (ValidTask)
                {
                    curr = temp; // "skok" do polecenia o podanej etykiecie
                    continue;
                }
            }
        }
        else if (strcmp(curr->command, "jzero") == 0)
        {
            if (curr->arg[0] == '=')
            {
                fprintf(stderr, "Polecenie \"%s %s %s\" ma bledny argument\n", curr->command, curr->arg, curr->label);
                ValidTask = false;
            }
            else
            {
                task *temp = FindLabeledTask(task_mem, curr, &ValidTask);
                if (ValidTask && var_mem->val == 0) // "skok" jesli akumulator ma wartosc 0
                {
                    curr = temp; // "skok" do polecenia o podanej etykiecie
                    continue;
                }
            }
        }
        else if (strcmp(curr->command, "jgtz") == 0)
        {
            if (curr->arg[0] == '=')
            {
                fprintf(stderr, "Polecenie \"%s %s %s\" ma bledny argument\n", curr->command, curr->arg, curr->label);
                ValidTask = false;
            }
            else
            {
                task *temp = FindLabeledTask(task_mem, curr, &ValidTask);
                if (ValidTask && var_mem->val > 0) // "skok" jesli akumulator ma wartosc wieksza niz 0
                {
                    curr = temp; // "skok" do polecenia o podanej etykiecie
                    continue;
                }
            }
        }
        else if (strcmp(curr->command, "halt") == 0)
            ValidTask = false;
        else
        {
            ValidTask = false;
            fprintf(stderr, "niepoprawna komenda \"%s\"\n", curr->command);
        }
        curr = curr->next;
    }
}
void FreeMemory(task *task_mem, MemCell *var_mem, tape *tape_in, tape *tape_out)
{
    while (task_mem != NULL)
    {
        task *temp = task_mem;
        task_mem = task_mem->next;
        free(temp->command);
        free(temp->arg);
        free(temp->label);
        free(temp);
    }
    while (var_mem != NULL)
    {
        MemCell *temp = var_mem;
        var_mem = var_mem->next;
        free(temp);
    }
    while (tape_in != NULL)
    {
        tape *temp = tape_in;
        tape_in = tape_in->next;
        free(temp);
    }
    while (tape_out != NULL)
    {
        tape *temp = tape_out;
        tape_out = tape_out->next;
        free(temp);
    }
}
void Help()
{
    printf("\nwpisz \"console\", aby wybrac tryb konsolowy, albo \"file\" aby wybrac wczytywanie z pliku\n");
    printf("Podawaj komendy w formacie \"komenda argument etykieta*\"\n");
    printf("* etykieta powinna miec maksymalnie 15 znakow, jesli polecenie nie ma etykiety wpisz \"-\"\n");
    printf("Aby zakonczyc wczytywanie polecen wpisz \"koniec\"\n\n");
}
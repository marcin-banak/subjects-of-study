#include "task.h"
#include "tape.h"
#include "memory.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

task* InitTask(char *arg, char *command, char *label) // funkcja inicjalizujaca strukture polecenia
{
    task *temp = malloc(sizeof(task));
    temp->arg = calloc(strlen(arg), sizeof(char));
    for (int i = 0; i < strlen(arg); i++)
    {
        temp->arg[i] = arg[i];
    }
    temp->command = strdup(command);
    temp->label = strdup(label);
    temp->next = NULL;
    return temp;
}
task *GetTask(FILE *file, bool *scanning)
{
    char command[20];
    fscanf(file, "%s", command);
    if (strcmp(command, "koniec") == 0)
    {
        *scanning = false;
        return NULL;
    }
    char arg[20];
    fscanf(file, "%s", arg);
    char label[20];
    fscanf(file, "%s", label);
    return InitTask(arg, command, label);
}
void InsertTask(task *tasks, task *new_task) // funkcja wstawiajca polecenie na koniec listy tasks
{
    task *curr = tasks;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_task;
}
task *FindLabeledTask(task *tasks, task *curr_task, bool *ValidTask) // funkcja zwraca polecenie o konkretnej etykiecie
{
    task *curr = tasks;
    while (curr != NULL)
    {
        if (strcmp(curr->label, curr_task->arg) == 0) // zwroc jesli etykieta polecenia z tabeli rowna sie argumentowi polecenia
            return curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        fprintf(stderr, "\nPolecenie \"%s %s %s\" szuka etykiety ktorej nie ma zadne polecenie!", curr_task->command, curr_task->arg, curr_task->label);
        *ValidTask = false;
        return NULL;
    }
}
void PrintTasks(task *tasks) // funkcja pomocnicza wypisujaca tablice polecen tasks
{
    task *curr = tasks;
    while (curr != NULL)
    {
        printf("%s %s %s\n", curr->arg, curr->command, curr->label);
        curr = curr->next;
    }
}
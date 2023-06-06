#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "task.h"
#include "memory.h"
#include "tape.h"
#include "utils.h"

int main()
{
    /// wybor trybu programu
    FILE *task_file; // plik z poleceniami
    FILE *tape_file; // plik z danymi z tasmy wejsciowej
    bool undefined_mode = true;
    while(undefined_mode) // petla pozwalajaca uzytkownikowi wybranie odpowiedniego trybu
    {
        printf("Wybierz sposob wprowadzenia programu (Napisz \"help\" aby wyswietlic pomoc)\n");
        char mode[10];
        scanf("%s", mode); // wybór pliku źródłowego

        if (strcmp(mode, "file") == 0) // przypisanie wskaźnika na odpowiedni
        {                              // plik źródłowy do zmiennej file
            printf("Podaj nazwe pliku z poleceniami:");
            char task_file_name[60];
            scanf("%s", task_file_name);
            task_file = fopen(task_file_name, "r");
            if (task_file == NULL)
            {
                printf("Niepoprawna nazwa pliku!\n\n");
                continue;
            }
            printf("Podaj nazwe pliku z tasma danych:");
            char tape_file_name[60];
            scanf("%s", tape_file_name);
            tape_file = fopen(tape_file_name, "r");
            if (tape_file == NULL)
            {
                printf("Niepoprawna nazwa pliku!\n\n");
                continue;
            }
            undefined_mode = false;
        }
        else if (strcmp(mode, "console") == 0)
        {
            task_file = stdin;
            tape_file = stdin;
            undefined_mode = false;
        }
        else if (strcmp(mode, "help") == 0)
            Help();
        else
            printf("Niepoprawny tryb!\n\n");
    }

    /// wczytywanie polecen
    if (task_file == stdin)
    {
        printf("Podawaj komendy w formacie \"komenda argument etykieta*\"\n");
    }
    bool scanning = true;
    task *task_mem = GetTask(task_file, &scanning);
    while (!feof(task_file) && scanning)  // petla wczytujaca polecenia
    {
        task *temp = GetTask(task_file, &scanning);
        InsertTask(task_mem, temp);
    }
    //PrintTasks(task_mem);

    /// wczytywanie danych
    if (task_file == stdin)
    {
        printf("Podawaj wartosci tasmy wejsciowej oddzielajac je spacja\n");
    }
    scanning = true;
    tape *tape_in = GetTapeVal(tape_file, &scanning);
    while (scanning) // petla wczytujaca dane z tasmy wejsciowej
    {
        tape *temp = GetTapeVal(tape_file, &scanning);
        InsertTapeVal(tape_in, temp);
    }
    //PrintTape(tape_in);

    ///wykonanie polecen
    MemCell *var_mem = InitMemCell(0, 0); // inicjalizacja pamieci wstepnie tylko z akumulatorem
    tape * tape_out = InitTapeVal(0);
    ExecuteTasks(task_mem, var_mem, tape_in, tape_out);

    ///wynik programu
    printf("Komorki pamieci: \n");
    PrintCells(var_mem);
    printf("\nTasma wyjsciowa: \n");
    PrintTape(tape_out->next);

    /// zwolnienie pamieci
    FreeMemory(task_mem, var_mem, tape_in, tape_out); // nie dziala!!!!!
    return 0;
}
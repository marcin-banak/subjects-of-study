#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elem
{
    int val;
    struct elem *next;
};
struct elem* init(int);
void insert(struct elem*, int);
struct elem* usunMax(struct elem*);
void printLista(struct elem*);
bool pr(int, int, int*, int*);
int main()
{
    struct elem *lista = init(1344);
    insert(lista, 12);
    insert(lista, 2);
    insert(lista, 5);
    insert(lista, 153);
    insert(lista, 14);
    lista = usunMax(lista);
    //printLista(lista);
    int licznik = 0;
    int tab[10] = {0,1,2,3,4,5};
    pr(0, 4, tab, &licznik);
    printf("%d", licznik);
    return 0;
}
struct elem* init(int val)
{
    struct elem *temp = malloc(sizeof(struct elem));
    temp->val = val;
    temp->next = NULL;
    return temp;
}
void insert(struct elem *lista, int val)
{   
    struct elem *temp = lista;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = init(val);
}
struct elem* usunMax(struct elem *lista)
{
    struct elem *mval = lista;
    struct elem *temp = lista;
    while (temp->next != NULL)
    {
        if (mval->next->val < temp->next->val)
            mval = temp;
        temp = temp->next;
    }
    if (lista->val > mval->next->val)
    {
        temp = lista->next;
        free(lista);
        return temp;
    }
    else
    {
        temp = mval->next;
        mval->next = mval->next->next;
        free(temp);
    }
    return lista;
}
void printLista(struct elem *lista)
{
    struct elem *temp = lista;
    while(temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}
bool pr(int i, int j, int a[], int *licznik)
{ 
    (*licznik)++;
    if (i==j) 
        return true;
    int s = (i+j) / 2;
    if (a[s]>a[s+1]) 
        return false;
    bool p1 = pr(i,s,a, licznik);
    bool p2 = pr(s+1,j,a, licznik);
    return p1 && p2;
}
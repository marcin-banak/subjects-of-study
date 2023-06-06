#include <stdio.h>
#include <stdlib.h>

struct elem
{
    int val;
    struct elem *next;
};
struct elem* init(int);
struct elem* add_elem(struct elem*, int); // podpunkt 1
struct elem* pop_elem(struct elem*); // podpunkt 2
struct elem* join(struct elem*, struct elem*); // podpunkt 3
struct elem* delete_val(struct elem*, int); // podpunkt 4
void print(struct elem*);

int main()
{
    struct elem *base = init(16);
    add_elem(base, 16);
    add_elem(base, 13);
    add_elem(base, 16);
    add_elem(base, 16);
    pop_elem(base);
    add_elem(base, 14);
    add_elem(base, 124);
    struct elem *base2 = init(24);
    add_elem(base2, 134);
    add_elem(base2, 16);
    add_elem(base2, 16);
    join(base, base2);
    print(base);
    delete_val(base, 16);
    print(base);
    return 0;
}
struct elem* init(int x)
{
    struct elem *temp;
    temp = malloc(sizeof(struct elem));
    temp->val = x;
    temp->next = NULL;
    return temp;
}
struct elem* add_elem(struct elem *list, int x)
{
    if(list == NULL)
        return init(x);
    else
        list->next = add_elem(list->next, x);
    return list;
}
struct elem* pop_elem(struct elem *list)
{
    if(list == NULL)
        return NULL;
    if(list->next == NULL) // element ostatni nie wskazuje na zaden nastepny
    {
        free(list);
        return NULL;
    }
    else
        list->next = pop_elem(list->next);
    return list;
}
struct elem* join(struct elem *list1, struct elem *list2) // dolacza liste 2 na koniec listy 1
{
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    if(list1->next == NULL)
        list1->next = list2;
    else
        return join(list1->next, list2);
    return list1;
}
struct elem* delete_val(struct elem *list, int x)
{
    if(list == NULL)
        return NULL;
    if(list->val == x) // element znajduje sie na poczatku listy
    {
        struct elem *pom = list->next;
        list->val = pom->val;
        list->next = pom->next;
        free(pom);
        delete_val(list, x);
    }
    else if((list->next->val == x) && (list->next->next == NULL)) // element znajduje sie na koncu listy
    {
        free(list->next);
        list->next = NULL;
        return NULL;
    }
    else if(list->next->val == x) // element znajduje sie w srodku listy
    {
        struct elem *pom = list->next->next;
        free(list->next);
        list->next = pom;
        return delete_val(list, x);
    }
    else
        return delete_val(list->next, x);
    return list;
}
void print(struct elem *list)
{
    printf("%d ", list->val);
    if(list->next == NULL)
        printf("\n");
    else if(list->next != NULL)
        print(list->next);
}

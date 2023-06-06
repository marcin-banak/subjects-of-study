#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int val;
    struct elem *next;
    struct elem *prev;
};
struct elem* init(int);
void add_end(struct elem*, int);
void pop_end(struct elem*);
struct elem* pop_front(struct elem*);
void print(struct elem*);

int main()
{
    struct elem *base = init(19);
    add_end(base, 13);
    add_end(base, 43);
    add_end(base, 543);
    print(base);
    pop_end(base);
    print(base);
    base = pop_front(base);
    printf("%d\n", base->next->prev->val);
    print(base);
    return 0;
}
struct elem* init(int val)
{
    struct elem* temp = malloc(sizeof(struct elem));
    temp->val = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void add_end(struct elem *list, int val)
{
    if (list->next == NULL)
    {
        list->next = init(val);
        list->next->prev = list;
    }
    else
        add_end(list->next, val);
}
void pop_end(struct elem *list)
{
    if (list->next->next == NULL)
    {
        free(list->next);
        list->next = NULL;
    }
    else
        pop_end(list->next);
}
struct elem* pop_front(struct elem *list)
{
    struct elem *temp = list->next;
    free(list);
    return temp;
}
void print(struct elem *list)
{
    printf("%d ", list->val);
    if(list->next == NULL)
        printf("\n");
    else if(list->next != NULL)
        print(list->next);
}
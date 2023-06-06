#include <stdio.h>
#include <stdlib.h>

struct elem
{
    int val;
    struct elem *next;
};
struct elem* init(int);
struct elem* add_elem(struct elem*, int);
void PrintInReverse(struct elem*);

int main()
{
    struct elem *base = init(16);
    add_elem(base, 16);
    add_elem(base, 13);
    add_elem(base, 16);
    add_elem(base, 16);
    add_elem(base, 14);
    add_elem(base, 124);
    PrintInReverse(base);
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
void PrintInReverse(struct elem *first)
{
    if (first->next == NULL)
        printf("%d ", first->val);
    else
    {
        PrintInReverse(first->next);
        printf("%d ", first->val);
    }
}
#include <stdio.h>
#include <stdlib.h>

struct elem
{
    int val;
    struct elem *next;
};
struct elem* init(int);
struct elem* add_elem(struct elem*, int);
struct elem* reverse(struct elem *list);
void print(struct elem*);

int main()
{
    struct elem *base = init(16);
    add_elem(base, 16);
    add_elem(base, 13);
    add_elem(base, 16);
    add_elem(base, 16);
    add_elem(base, 14);
    add_elem(base, 124);
    base = reverse(base);
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
struct elem* reverse(struct elem *list)
{
    struct elem *prev = NULL;
    struct elem *curr = list;
    while (curr != NULL)
    {
        struct elem *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list = prev;
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
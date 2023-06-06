#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int val;
    struct elem *next;
    struct elem *last;
};
struct elem* init(int);
void add_end(struct elem*, int);
void join(struct elem*, struct elem*);
struct elem* add_front(struct elem*, int);
struct elem* pop_front(struct elem*);
void print(struct elem*);

int main()
{
    struct elem *base1 = init(14);
    add_end(base1, 21);
    struct elem *base2 = init(64);
    add_end(base2, 234);
    add_end(base2, 23);
    add_end(base2, 54);
    join(base1, base2);
    base1 = add_front(base1, 0);
    struct elem *base3 = init(35);
    add_end(base3, 543);
    add_end(base3, 5);
    add_end(base3, 43);
    join(base1, base3);
    print(base1);
    struct elem *base4 = init(43);
    add_end(base4, 5432);
    add_end(base4, 44);
    base4 = add_front(base4, 6);
    //printf("%d\n", base1->last->val);
    base1 = pop_front(base1);
    //printf("%d\n", base1->last->val);
    join(base1, base4);
    print(base1);
    //printf("%d %d\n", base->next->val, base->last->val);
    return 0;
}
struct elem* init(int val)
{
    struct elem* temp = malloc(sizeof(struct elem));
    temp->val = val;
    temp->next = NULL;
    temp->last = temp;
    return temp;
}
void add_end(struct elem *first, int val)
{
    first->last->next = init(val);
    first->last = first->last->next;
}
void join(struct elem *list1, struct elem *list2)
{
    list1->last->next = list2;
    list1->last = list2->last;
}
struct elem* add_front(struct elem *first, int val)
{
    struct elem *temp = first;
    temp = init(val);
    temp->next = first;
    temp->last = first->last;
    return temp;
}
struct elem* pop_front(struct elem *first)
{
    struct elem *temp = first->next;
    temp->last = first->last;
    free(first);
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
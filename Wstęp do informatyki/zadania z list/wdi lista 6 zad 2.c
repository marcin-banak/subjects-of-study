#include <stdio.h>
#include <stdlib.h>
void selection_sort(int* tab,int n);
void swap(int* i, int* j);

int main()
{
    int n;
    scanf("%d", &n);
    int liczby[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &liczby[i]);
    }
    selection_sort(liczby, n);
    for(int i = 0; i<n; i++)
    {
        printf("%d ", liczby[i]);
    }
    return 0;
}
void selection_sort(int* tab,int n)
{
    for(int j = 0; j < n - 1; j++)
    {
        int pmin = j;
        for(int i = j + 1; i < n; i++)
            if(tab[i] < tab[pmin]) pmin = i;
        swap(&tab[pmin], &tab[j]);
    }
}
void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

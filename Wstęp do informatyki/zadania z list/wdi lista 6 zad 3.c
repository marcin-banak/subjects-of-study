#include <stdio.h>
void bubble(int* tab, int n);
void swap(int* a, int* b);

int main()
{
    int n;
    scanf("%d", &n);
    int tab[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &tab[i]);
    }
    bubble(tab, n);
    for(int i = 0; i<n; i++)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}
void bubble(int* tab, int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<n-1; j++)
        {
            if(tab[j] > tab[j+1])
                swap(&tab[j], &tab[j+1]);
        }
    }
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

#include <stdio.h>
int wartosc(int* a, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int bin[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &bin[i]);
    }
    printf("%d", wartosc(bin, n));
    return 0;
}
int wartosc(int* a, int n)
{
    int w = 0;
    for(int i = 0; i < n; i++)
    {
        w = w*2 + a[i];
    }
    return w;
}

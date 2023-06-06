#include <stdio.h>
int czynniki(int a, int n, int *liczby);
int main()
{
    int a, n;
    scanf("%d %d", &a, &n);
    int liczby[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &liczby[i]);
    }
    int czynniki[a+1];
    int czynnik = 0;
    int maxp = 0;
    while(a > 1 && czynnik != n)
    {
        while(!(a%liczby[czynnik]))
        {
            czynniki[czynnik]++;
            a /= liczby[czynnik];
        }
        if(czynniki[czynnik] > maxp)
            maxp = czynniki[czynnik];
        czynnik += 1;
    }
    printf("%d ", maxp);
    for(int i = 0; i<n; i++)
    {
        if(czynniki[i] == maxp)
            printf("%d ", liczby[i]);
    }
    return 0;
}

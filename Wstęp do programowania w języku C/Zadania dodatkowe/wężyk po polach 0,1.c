#include <stdio.h>
#include <stdlib.h>

const int N = 512;
int row(int pole[N][N], int n);
int snake(int pole[N][N], int n);
int diagonal(int pole[N][N], int n);
int main()
{
    int pole[512][512];
    int n; scanf("%d", &n);
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%d", &pole[i][j]);
    printf("%d %d\n", row(pole,n), snake(pole,n));
    diagonal(pole,n);
    return 0;
}
int row(int pole[N][N], int n)
{
    int max = 0;
    for(int i = 0; i<n; i++)
    {
        int licznik = 0;
        for(int j = 0; j<n; j++)
        {
            if(pole[i][j])
                licznik++;
            else
            {
                if(max < licznik)
                    max = licznik;
                licznik = 0;
            }
        }
    }
    return max;
}
int snake(int pole[N][N], int n)
{
    int max = 0;
    int zwrot = 1;
    int licznik = 0;
    for(int i = 0; i<n; i++)
    {
        if(zwrot)
        {
            for(int j = 0; j<n; j++)
            {
                if(pole[i][j])
                    licznik++;
                else
                {
                    if(max < licznik)
                        max = licznik;
                    licznik = 0;
                }
            }
            zwrot = 0;
        }
        else
        {
            for(int j = n-1; j>=0; j--)
            {
                if(pole[i][j])
                    licznik++;
                else
                {
                    if(max < licznik)
                        max = licznik;
                    licznik = 0;
                }
            }
            zwrot = 1;
        }
    }
    return max;
}
int diagonal(int pole[N][N], int n)
{
    //int g = n-1;
    n *= n;
    int max = 0;
    int licznik = 0;
    if (pole[0][0])
        licznik++;
    n--;
    int i = 0, j = 1;
    int w_dol = 1;
    while(n>0)
    {
        if(pole[i][j]) /// sprawdzenie ciaglosci
            licznik++;
        else if(max < licznik)
        {
            max = licznik;
            licznik = 0;
        }

        if(i == 0 && !w_dol)
        {
            printf("a ");
            j++;
            w_dol = 1;
        }
        else if(i == 0 && w_dol) ///i jest na gornej krawedzi oraz linia schodzi w dol
        {
            printf("b ");
            i++; j--;
        }
        else if(j == 0 && w_dol) ///j jest na lewej krawedzi oraz linia schodzi w dol
        {
            printf("c ");
            i++;
            w_dol = 0;
        }
        else if(j == 0 && !w_dol) ///j jest na lewej krawedzi oraz linia idzie w gore
        {
            printf("d ");
            i--; j++;
        }
        printf("%d %d\n", i, j);
        n--;
    }
    return max;
}

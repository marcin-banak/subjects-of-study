#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n;
    int k;
    int len = 0;
    char wynik[10000];
    scanf("%d %d", &n, &k);
    if(!(k>1 && k<37))
        printf("Nieprawidłowe dane!");
    else
    {
        while(n>0)
        {
            int reszta = n%k;
            if(reszta>9)
            {
                wynik[len] = (char)(reszta - 10 + 'A');
            }
            else
            {
                wynik[len] = (char)(reszta + '0');
            }
            n/=k;
            len++;
        }
        for(int i = len-1; i>=0; i--)
        {
            printf("%c", wynik[i]);
        }
    }
    return 0;
}

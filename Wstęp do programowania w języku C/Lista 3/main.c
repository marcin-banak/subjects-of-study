#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    if(!scanf("%d", &n) || !(n>0 && n<21))
    {
        printf("Niepoprawne dane!");
    }
    else if(!(n%2))
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(j == i)
                    printf("*");
                else
                    printf(" ");
            }
            for(int j = n-2; j>=0; j--)
            {
                if(j == i)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(j == i)
                    printf("*");
                else
                    printf(" ");
            }
            for(int j = n-2; j>=0; j--)
            {
                if(j == i)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

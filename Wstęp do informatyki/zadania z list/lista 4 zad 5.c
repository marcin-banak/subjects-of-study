#include <stdio.h>

int Palindrom(int a);
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", Palindrom(a));
    return 0;
}
int Palindrom(int a)
{
    char bin[1000];
    int podstawa = 2;
    int miejsce = 0;
    while(a > 0)
    {
        bin[miejsce] = (char)(a % podstawa + '0');
        a /= podstawa;
        miejsce++;
    }
    for(int i = 0, j = miejsce - 1; i<j; i++, j--)
    {
        if(bin[j] != bin[i])
        {
            return 0;
        }
    }
    return 1;
}

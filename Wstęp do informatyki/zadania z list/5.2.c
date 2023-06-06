#include <stdio.h>

void reprezentacja(int n);
int main()
{
    reprezentacja(100);
    return 0;
}
void reprezentacja(int n)
{
    int a = 1;
    int i = 0;
    while(a < n)
    {
        i += 1;
        a *= i;
    }
    while(i > 1)
    {
        a /= i;
        printf("%d ", n/a);
        n = n%a;
        i -=1;
    }
}

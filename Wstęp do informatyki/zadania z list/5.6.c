#include <stdio.h>

int fibonnaci(int k, int r);
int main()
{
    int k, r;
    scanf("%d %d", &k, &r);
    printf("%d", fibonnaci(k,r));
    return 0;
}
int fibonnaci(int k, int r)
{
    int t[k + 1];
    t[0] = 1%r;
    t[1] = 1%r;
    for(int i = 2; i < k; i++)
    {
        t[i] = ((t[i-1]%r) + (t[i-2]%r))%r;
    }
    return t[k - 1];
}

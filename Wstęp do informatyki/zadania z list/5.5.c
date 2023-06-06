#include <stdio.h>
int i = 0;
int T(int n, int m);
int main()
{
    printf("%d", T(3,4));
    return 0;
}
int T(int n, int m)
{
    printf("%d %d\n", n, m);
    i++;
    if(n == 0)
        return m;
    if(m == 0)
        return n;
    return (T(n-1,m) + 2*T(n,m-1));
}

#include <stdio.h>

int G(int n);
int main()
{
    printf("%d", G(7));
    return 0;
}
int G(int n)
{
    if(n>=0 && n <=2)
        return 1;
    int G[3] = {1,1,1};
    for (int i = 3; i<n; i++)
    {
        int current = G[0] + G[1] + G[2];
        G[0] = G[1];
        G[1] = G[2];
        G[2] = current;
    }
    return G[2];
}

#include <stdio.h>
#include <math.h>

void kwadraty(int n, int arr[])
{
    for(int i = 0; i*i < n; i++)
    {
        arr[i] = pow(i,2);
    }
}
int main()
{
    int n; scanf("%d", &n);
    int arr[31700] = {0};
    kwadraty(n + 1001, arr);
    for (int i = n; i <= n+1000; i++)
    {
        int bezkwadrat = 1;
        for (int j = 2; j*j <= n + 1000; j += 1)
        {
            if (i % arr[j] == 0)
            {
                bezkwadrat = 0;
                break;
            }
        }
        if (bezkwadrat)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("BRAK");
    return 0;
}

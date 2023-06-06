#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    double min = rand() / (double)RAND_MAX;
    double max = min;
    int n; scanf("%d", &n);
    for (int i = 0; i < n-1; i += 1)
    {
        double current = rand() / (double)RAND_MAX;
        if (min > current)
            min = current;
        if (max < current)
            max = current;
    }
    printf ("%.3lf %.3lf", min, max);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    while (1)
    {
        printf("Podaj współrzędne 4 Punktów:\n");
        double xa,xb,xc,xd,ya,yb,yc,yd;
        printf("A: "); scanf("%lf %lf", &xa, &ya);
        printf("B: "); scanf("%lf %lf", &xb, &yb);
        printf("C: "); scanf("%lf %lf", &xc, &yc);
        printf("D: "); scanf("%lf %lf", &xd, &yd);
        if(xa == xb)
        {
            if(xc == xd)
                printf("rownolegle\n");
            else if(yc == yd)
                printf("prostopadle\n");
            else
                printf("-\n");
        }
        else if(xc == xd)
        {
            if(xa == xb)
                printf("rownolegle\n");
            else if(ya == yb)
                printf("prostopadle\n");
            else
                printf("-\n");
        }
        else
        {
            double Aab = (double)(ya - yb)/(double)(xa - xb);
            double Acd = (double)(yc - yd)/(double)(xc - xd);
            if(Aab == Acd)
                printf("rownolegle\n");
            else if(Aab * Acd == -1)
                printf("prostopadle\n");
            else
                printf("-\n");
        }
    }
    return 0;
}

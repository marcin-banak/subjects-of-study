#include <stdio.h>

void zacienrano(int a, int h, int cien[h][a],int las[h][a]);
void zacienpoludnie(int a, int h, int cien[h][a],int las[h][a]);
void zacienwieczor(int a, int h, int cien[h][a],int las[h][a]);
int main()
{
    int a, h, d;
    scanf("%d%d%d", &a, &h, &d);
    int las[h][a];
    for(int i = 0; i<h; i++)
    {
        for(int j = 0; j<a; j++)
        {
            char current;
            scanf("%c", &current);
            if(!(current >= '0' && current <= '9') && current != '.')
                scanf("%c", &current);
            if (current == '.')
                las[i][j] = -1;
            else
                las[i][j] = (int)(current - '0');
        }
    }
    int cien[h][a]; //kolejne pory dnia
    for(int i = 0; i<h; i++)
        for(int j = 0; j<a; j++)
            cien[i][j] = 0;
    /*for(int c = 0; c<d; c++) //kolejne dni
    {
        zacienrano(a,h,cien,las);
    }*/
    zacienrano(a,h,cien,las);
    for(int i = 0; i<h; i++) //wypisywanie ostatniego cienia
    {
        for(int j = 0; j<a; j++)
            printf("%d ", cien[i][j]);
        printf("\n");
    }
    return 0;
}
void zacienrano(int a, int h, int cien[h][a], int las[h][a])
{
    for(int i = 0; i<h; i++)
    {
        for(int j = a-1; j>=0; j--) // konkretna dzia³ka w lesie
        {
            int drzewo = las[i][j];
            if(drzewo != -1)
            {
                printf("%d %d %d\n", i, j, drzewo);
                if(j<drzewo) //sprawdŸ czy nie wyjdziesz poza pole
                    drzewo = j;
                for(int k = drzewo; k >= j-drzewo; k--) // wype³nij cieniem wszystkie komórki z zakresu [j-drzewo,j-1]
                {
                    cien[i][k] = 1;
                }
            }
        }
    }
}
/*void zacienpoludnie(int a, int h, int cien[h][a],int las[h][a])
{

}
void zacienwieczor(int a, int h, int cien[h][a],int las[h][a])
{

}*/

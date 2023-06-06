#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int g;
    int m;
    int s;
}zegar;

zegar ustaw(short g, short m, short s);
bool sprawdz(zegar z);
zegar normuj(zegar z);
void dodajgodziny(zegar *z, short g);
void dodajminuty(zegar *z, short g);
void dodajsekundy(zegar *z, short g);
void drukuj(FILE *f, zegar z);

int main()
{
    int g, m, s;
    scanf("%d %d %d", &g, &m, &s);
    zegar z = ustaw(g, m, s);
    int g1, m1, s1;
    printf("podaj czas o jaki przestawic godzine: ");
    scanf("%d %d %d",  &g1, &m1, &s1);
    dodajgodziny(&z, g1);
    dodajminuty(&z, m1);
    dodajsekundy(&z, s1);
    drukuj(stdout ,z);
    return 0;
}
zegar ustaw(short g, short m, short s)
{
    zegar time = {g,m,s};
    if(sprawdz(time))
        time = normuj(time);
    return time;
}
bool sprawdz(zegar z)
{
    if(z.s > 59 || z.s < 0)
    {
        return 0;
    }
    if(z.m > 59 || z.s < 0)
    {
        return 0;
    }
    if(z.g > 23 || z.s < 0)
    {
        return 0;
    }
    return 1;
}
zegar normuj(zegar z)
{
    if(z.s > 59)
    {
        z.m += z.s/60;
        z.s %= 60;
    }
    if(z.s < 0)
    {
        z.m += z.s/60;
        z.s %= 60;
        z.s += 60;
        z.m--;
    }
    if(z.m > 59)
    {
        z.g += z.m/60;
        z.m %= 60;
    }
    if(z.m < 0)
    {
        z.g += z.m/60;
        z.m %= 60;
        z.m += 60;
        z.g--;
    }
    if(z.g > 23)
    {
        z.g%= 24;
    }
    if(z.g < 0)
    {
        z.g %= 24;
        z.g += 24;
    }
    return z;
}
void dodajgodziny(zegar *z, short godz)
{
    z->g += godz;
    if(sprawdz(*z))
        *z = normuj(*z);
}
void dodajminuty(zegar *z, short g)
{
    z->m += g;
    if(sprawdz(*z))
        *z = normuj(*z);
}
void dodajsekundy(zegar *z, short g)
{
    z->s += g;
    if(sprawdz(*z))
        *z = normuj(*z);
}
void drukuj(FILE *f, zegar z)
{
    if(sprawdz(z))
        z = normuj(z);
    fprintf(f,"%02d:%02d:%02d", z.g, z.m, z.s);
}

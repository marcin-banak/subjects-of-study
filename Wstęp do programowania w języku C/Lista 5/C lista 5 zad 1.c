#include <stdio.h>
unsigned jakiBit (unsigned liczba, unsigned nrBitu);
void zmienBit (unsigned *liczba, unsigned nrBitu);
void wypiszBitowo (unsigned liczba);
void wypiszBinarnie(unsigned liczba);

int main()
{
    unsigned x, nr;
    scanf("%d %d", &x, &nr);
    printf("wartosc bitu: %d\n", jakiBit(x,nr));
    printf("bitowa i binarna reprezentacja przed negacja bitu:\n");
    wypiszBitowo(x);
    wypiszBinarnie(x);
    zmienBit(&x, nr);
    printf("bitowa i binarna reprezentacja po negacji bitu:\n");
    wypiszBitowo(x);
    wypiszBinarnie(x);
    return 0;
}
unsigned jakiBit (unsigned liczba, unsigned nrBitu)
{
    return (0 != (liczba & (1<<nrBitu)));
}
void zmienBit (unsigned *liczba, unsigned nrBitu)
{
    if(jakiBit(*liczba, nrBitu) == 0)
        *liczba |= 1<<nrBitu;
    else
        *liczba &= ~(1<<nrBitu);
}
void wypiszBitowo (unsigned liczba)
{
    char bin[32] = "00000000000000000000000000000000";
    int i = 0;
    while(liczba > 0)
    {
        if(liczba % 2 == 1)
            bin[i] = '1';
        liczba /= 2;
        i++;
    }
    for(i = 31; i>=0; i--)
        printf("%c", bin[i]);
    printf("\n");
}
void wypiszBinarnie(unsigned liczba)
{
    int liczbacp = liczba;
    char bin[32];
    int i = 0;
    int licznik = 0;
    int min = -1;
    while(liczba > 0)
    {
        if(liczba % 2 == 1)
        {
            bin[i] = '1';
            licznik ++;
            if(min == -1)
                min = i;
        }
        else
            bin[i] = '0';
        liczba /= 2;
        i++;
    }
    for(int j = i - 1; j>=0; j--)
        printf("%c", bin[j]);
    printf("\nilosc zapalonych bitow: %d\n", licznik);
    if(liczbacp != 0)
    {
        printf("pozycja najbardziej znaczacego bitu: %d\n", i-1);
        printf("pozycja najmniej znaczacego bitu: %d\n", min);
    }
    printf("\n");
}

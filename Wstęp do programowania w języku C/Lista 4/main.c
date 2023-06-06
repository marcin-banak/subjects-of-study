#include <stdio.h>

int dl(char s[]);
void odwr(char s[]);
void kop(char skad[], char dokad[]);
int main(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        int s[1000];
        kop(argv[i], s);
        odwr(s);
        printf("%s\n", s);
    }

    return 0;
}
int dl(char s[])
{
    int  i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}
void odwr(char s[])
{
    int n = dl(s);
    for(int i = 0, j = n-1; i < j; i++, j--)
    {
        //printf("%d %d\n", i, (j));
        int pom = s[i];
        s[i] = s[j];
        s[j] = pom;
    }
}
void kop(char skad[], char dokad[])
{
    int n = dl(skad);
    for(int i = 0; i < n; i++)
        dokad[i] = skad[i];
}


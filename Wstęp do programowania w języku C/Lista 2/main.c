#include <stdio.h>
#include <stdlib.h>

int main()
{
    char zdanie[10000];
    scanf("%[^\n]%*c", zdanie);
    char wyjscie[10000];
    int j = 0;
    for(int i = 0; zdanie[i]!='\0'; i++)
    {
        if(zdanie[i] == ' ')
        {
            wyjscie[j] = zdanie[i];
            while(zdanie[i] == ' ')
                i++;
        }
        else if(zdanie[i] == '\t')
            wyjscie[j] = ' ';
        else if(zdanie[i]>='a' && zdanie[i]<='z')
            wyjscie[j] = ((zdanie[i]-'a' + 3)%26) + 'a';
        else if(zdanie[i]>32 && zdanie[i]<=126)
            wyjscie[j] = zdanie[i];
        j++;
    }
    printf("%s", wyjscie);
    return 0;
}

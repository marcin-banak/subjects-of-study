#include <stdio.h>

int main()
{
	int n;
	int liczby[1000000];
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &liczby[i]);
	}
	int max = 0;
	for (int i = 0; i<n; i++)
	{
		int current = liczby[i];
		int licznik = 1;
		int wskaznik = current-1;
		while (liczby[wskaznik] != current)
		{
			wskaznik = liczby[wskaznik]-1;
			licznik++;
		}
		if (max < licznik)
			max = licznik;
	}
	printf("%d", max);
	return 0;
}

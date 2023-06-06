#include <iostream>
#include "BitTab.h"

int main() {
    int n = 7;
    BitTab words(n);
    for (int i = 0; i < n; i++)
    {
        try {
            cin >> words;
        }
        catch (invalid_argument e)
        {
            printf(e.what());
        }
    }
    while (words.size() > 0)
    {
        try {
            cout << words << " ";
        }
        catch (invalid_argument e)
        {
            printf(e.what());
        }
    }
    printf("\n\nTablica words:");
    for (int i = 0; i < n; i++)
        printf("\nwartosc indeksu %d: %d", i, words[i]);
    !words;
    printf("\n\nTablica !words:");
    for (int i = 0; i < n; i++)
        printf("\nwartosc indeksu %d: %d", i, words[i]);

    BitTab w(5);
    printf("\n\nTablica w:");
    for (int i = 0; i < 5; i++)
        printf("\nwartosc indeksu %d: %d", i, w[i]);

    BitTab z(uint64_t(17));
    printf("\n\nTablica z:");
    for (int i = 0; i < z.size(); i++)
        printf("\nwartosc indeksu %d: %d", i, z[i]);

    w |= z;
    printf("\n\nTablica w po wykonaniu w |= z:");
    for (int i = 0; i < 5; i++)
        printf("\nwartosc indeksu %d: %d", i, w[i]);

    BitTab b{0, 1, 0, 1, 1};
    printf("\n\nTablica b:");
    for (int i = 0; i < b.size(); i++)
        printf("\nwartosc indeksu %d: %d", i, b[i]);

    return 0;
}

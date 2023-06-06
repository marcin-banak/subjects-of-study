// Marcin Banak
// Lista 3, zadanie 4.
//
// Żeby uzyskać plik .dll, w którym zdefiniowane są klasy, wpisujemy komendę
// mcs -t:library zad4_klasy.cs 
// w wiersz poleceń Mono, po czym, aby uzyskać plik .exe, wpisujemy komendę
// mcs zad4_testy.cs -r:zad4_klasy.dll
// Aby wyświetlić wynik programu piszemy 
// zad4_testy.exe

using System;
using System.Numerics;
using System.Runtime.CompilerServices;

namespace zad4
{
	class Program
    {
        static void Main()
        {
            Vector v1 = new Vector(3, 2); // [2, 2, 2]
            Vector v2 = new Vector(3, 5); // [5, 5, 5]
            v1.Set(0, 12); // [12, 2, 2]
			Console.WriteLine("Dodaje wektor [{0}, {1}, {2}] i [{3}, {4}, {5}]: ", 
							   v1.Get(0), v1.Get(1), v1.Get(2), 
							   v2.Get(0), v2.Get(1), v2.Get(2));
								
            (v1 + v2).PrintVector();

            Vector v3 = new Vector(4, 5); // [5, 5, 5, 5]
            Vector v4 = new Vector(4, 7); // [7, 7, 7, 7]
            // v3 * v4 = 5*7 + 5*7 + 5*7 + 5*7 = 4*5*7 = 140
            Console.WriteLine("Iloczyn skalarny wektrow\n" +
                              "[5, 5, 5, 5] x [7, 7, 7, 7]: {0}\n", v3 * v4);
            
			Console.WriteLine("Mnoze wektor [{0}, {1}, {2}] przez 3.5:",
							   v1.Get(0), v1.Get(1), v1.Get(2));
            (3.5f * v1).PrintVector();

            Vector v5 = new Vector(2, 3);
            v5.Set(0, 4); // [4, 3]
            Console.WriteLine("Dlugosc wektora [4, 3]: {0}", v5.Norma());
        }
    }
}
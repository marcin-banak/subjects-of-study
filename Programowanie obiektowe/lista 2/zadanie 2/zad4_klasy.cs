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

namespace zad4
{
	public class Vector
    {
        // Pole klasy.
        private float[] _coord; // Tablica przechowująca współrzędne wektora.
        private int _size; // Ilość wymiarów wektora.

        // Konstruktory.
        public Vector(int n, float val = 0)
        {
            this._coord = new float[n];
            this._size = n;
            for (int i = 0; i < n; i++)
            {
                this._coord[i] = val;
            }
        }
        public Vector(int n, float[] coord)
        {
            this._coord = coord;
            this._size = n;
        }
        
        // Metody klasy.
        
        // Zwraca wartość z zadanego indeksu.
        public float Get(int index)
        {
            if (index >= this._size)
            {
                Console.WriteLine("bledny index");
                return 0;
            }
            
            return this._coord[index];
        }
        
        // Zmienia wartość danego indexu na podaną.
        public void Set(int index, float val)
        {
            if (index >= this._size)
            {
                Console.WriteLine("bledny index");
                return;
            }

            this._coord[index] = val;
        }
        
        // Zwraca ilość wymiarów wektora.
        public int GetSize()
        {
            return this._size;
        }

        public float Norma()
        {
            /////////////////////
            Vector garbage = new Vector(1);
            (2 * garbage).Get(0);
            /////////////////////
            
            float sum = 0;
            for (int i = 0; i < this._size; i++)
            {
                sum += this._coord[i] * this._coord[i];
            }
            
            return (float) Math.Sqrt(sum);
        }

        public void PrintVector()
        {
            for (int i = 0; i < this._size; i++)
            {
                Console.WriteLine("Wspolrzedna nr {0}: {1}", i, this.Get(i));
            }
            Console.WriteLine();
        }
        
        // Przeciążone operatory.
        
        // Dodawanie wektorów.
        public static Vector operator +(Vector a, Vector b)
        {
            int size = a.GetSize();
            if (size != b.GetSize())
            {
                Console.WriteLine("Dodawanie roznowymiarowych wektorow!");
                return new Vector(1);
            }
            float[] aux = new float[size];
            for (int i = 0; i < size; i++)
            {
                aux[i] = (a.Get(i) + b.Get(i));
            }
            return new Vector(size, aux);
        }
        
        // Iloczyn skalarny wektorów
        public static float operator *(Vector a, Vector b)
        {
            int size = a.GetSize();
            if (size != b.GetSize())
            {
                Console.WriteLine("iloczyn skalarny roznowymiarowych wektorow!");
                return 1;
            }

            float sum = 0;
            for (int i = 0; i < size; i++)
            {
                sum += (a.Get(i) * b.Get(i));
            }
            
            return sum;
        }
        
        // Mnożenie wektorów.
        public static Vector operator *(float s, Vector v)
        {
            float[] aux = new float[v.GetSize()];
            for (int i = 0; i < v.GetSize(); i++)
            {
                aux[i] = s * v.Get(i);
            }

            return new Vector(v.GetSize(), aux);
        }
    }
}
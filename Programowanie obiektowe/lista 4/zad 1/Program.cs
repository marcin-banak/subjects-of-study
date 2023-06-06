/*
 * Marcin Banak,
 * Lista 4, zadanie 2.
 * Program kompilowany przy użyciu kompilatora mono poleceniem:
 * mcs zad2.cs.
 * Wywołanie programu za pomocą komendy zad2.exe po uprzednim skompilowaniu.
 */
using System;
using System.Collections;

namespace zad2
{
    public class FibWords : IEnumerable
    {
        // Tablica słów.
        private string[] _words;

        public FibWords(int size)
        {
            // Utworzenie tablicy przechowującej słowa.
            this._words = new string[size];

            // Rozpatrzenie przypadków dla parametru size.
            if (size < 1)
                Console.WriteLine("Bledna ilosc podanych slow.\n");
            else if (size == 1)
                this._words[0] = "b";
            else
            {
                this._words[0] = "b";
                this._words[1] = "a";
            }

            // Wypełnianie tablicy kolejnymi słowami.
            for (int i = 2; i < size; i++)
            {
                this._words[i] = this._words[i - 1] + this._words[i - 2];
            }
        }

        // Funkcje zwracające numerator.
        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator)GetEnumerator();
        }

        private FibEnum GetEnumerator()
        {
            return new FibEnum(this._words);
        }
    }

    // Metoda GetEnumerator() z klasy FibWords zwraca obiekt numeratora
    // z klasy FibEnum.
    public class FibEnum : IEnumerator
    {
        // Tablica słów.
        private string[] _words;

        // Pozycja początkowa numeratora.
        private int _position = -1;
        
        // Metody interfejsu IEnumerator.
        public FibEnum(string[] words)
        {
            this._words = words;
        }

        public bool MoveNext()
        {
            _position++;
            return ( this._position < _words.Length);
        }

        public void Reset()
        {
            this._position = -1;
        }

        public object Current
        {
            get { return _words[this._position]; }
        }
    }
    
    class Program
    {
        static int Main()
        {

            FibWords fib = new FibWords(6);
            foreach (string word in fib)
            {
                Console.WriteLine(word);
            }
            
            return 0;
        }
    }
}
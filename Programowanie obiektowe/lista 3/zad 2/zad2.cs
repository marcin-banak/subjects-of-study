o// Marcin Banak
// lista 2, zadanie 2
// csc.exe zad2.cs

using System;
namespace zad2
{
    class Elem // Klasa elementu.
    {
        // Pola klasy.
        private int _val; // Wartość elementu listy.
        private int _index; // Indeks elementu listy.
        private Elem _prev; // Poprzedni element.
        private Elem _next; // Następny element.
        
        // Własności klasy obsługujące jej zmienne.
        public int Val
        {
            get { return this._val; }
            set { this._val = value; }
        }
        public int Index
        {
            get { return this._index; }
            set { this._index = value; }
        }
        public Elem Prev
        {
            get { return this._prev; }
            set { this._prev = value; }
        }
        public Elem Next
        {
            get { return this._next; }
            set { this._next = value; }
        }
        
        // Metody klasy.
        public Elem(int index, int val = 0)
        {
            this.Val = val;
            this.Index = index;
            this.Next = null;
            this.Prev = null;
        }
    }

    class Array // Klasa tablicy.
    {
        // Pola klasy.
        private Elem _first_elem; // Wskaźnik na pierwszy element listy.
        private Elem _last_elem; // Wskaźnik na ostatni element listy.

        private int _last_used_index; // Wskaźnik na ostatnio użyty element listy.
        private Elem _last_used_elem; // Ostatnio użyty index listy.

        // Własności klasy obsługujące jej zmienne.
        public Elem FirstElem
        {
            get { return this._first_elem; }
            set { this._first_elem = value; }
        }
        public Elem LastElem
        {
            get { return this._last_elem; }
            set { this._last_elem = value; }
        }
        public int LastUsedIndex
        {
            get { return this._last_used_index; }
            set { this._last_used_index = value; }
        }
        public Elem LastUsedElem
        {
            get { return this._last_used_elem; }
            set { this._last_used_elem = value; }
        }
        
        // Metody klasy.
        public Array(int first_index, int last_index, int val = 0) // Konstruktor.
        {
            // Tworzymy pierwszy element listy
            this.FirstElem = new Elem(first_index, val);
            this.LastUsed(this.FirstElem.Index, this.FirstElem);
            // Tworzymy elementy z podanego przedziału,
            // przy założeniu, że jest on domknięty.
            for (int i = (first_index + 1); i <= last_index; i++)
            {
                Elem temp = new Elem(i, val); 
                this.LastUsedElem.Next = temp; // Przepięcie wskaźników. 
                temp.Prev = this.LastUsedElem; 
                this.LastUsed(i, temp);
            }
            this.LastElem = this.LastUsedElem; // Wskaźnik na ostatni element.
            this.LastUsed(last_index, this.LastElem);
        }

        // Funkcja aktualizuje pola mówiące o ostatnim użytym elemencie.
        public void LastUsed(int index, Elem element)
        {
            // Jeżeli natrafimy na ostatni element tablicy,
            // to nie mamy następnego elementu, do którego można się iterować.
            // Dlatego:
            if (element == this.LastElem)
            {
                this.LastUsedIndex = this.FirstElem.Index;
                this.LastUsedElem = this.FirstElem;
                return;
            }
            this.LastUsedIndex = index;
            this.LastUsedElem = element;
        }

        // Funkcja zwraca element tablicy o podanym indeksie.
        public Elem FindElem(int index)
        {
            // Sprawdzamy czy ostatnio użyty indeks
            // poprzedza podany indeks.
            if ((this.LastUsedIndex + 1) == index)
                return this.LastUsedElem.Next;

            // jeżeli ten warunek jest spełniony to oznacza to,
            // że w obecnej iteracji już inna funkcja znalazła wcześniej ten element.
            if (this.LastUsedIndex == index)
                return this.LastUsedElem;
            
            // Przechodzimy tablicę, aby znależć element o podanym indeksie.
            Elem temp = this.FirstElem;
            while (temp != null)
            {
                if (temp.Index == index)
                {   
                    this.LastUsed(index, temp);
                    return temp;
                }

                temp = temp.Next;
            }
            // Jeśli wyszliśmy z pętli oznacza to, że podany indeks nie istnieje
            // wtedy zwracamy pierwszy element
            this.LastUsed(this.FirstElem.Index, this.FirstElem);
            return this.FirstElem;
        }
        
        // Funkcja ustawiająca wartość tablicy na podanym indeksie.
        public void Set(int index, int val)
        {
            Elem temp = this.FindElem(index);
            temp.Val = val;
            this.LastUsed(index, temp);
        }
        
        // Funkcja zwracająca wartość zmiennej _val elementu o podanym indeksie.
        public int Get(int index)
        {
            Elem temp = this.FindElem(index);
            this.LastUsed(index, temp);
            return temp.Val;
        }
    }
    
    class Program
    {
        static void Main()
        {
            Array test = new Array(0, 100);
            
            // Ustawiam kolejne elementy na wielokrotności liczby 10.
            for (int i = 0; i <= 100; i++) 
            {
                test.Set(i, i * 10);
            }

            int n = 10;
            // Wypisuje n pierwszych elementów tablicy.
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("Indeks: {0}, wartosc: {1}", i, test.Get(i));
            }
            
            Console.WriteLine();
            // Dodaje do siebie wartości tabeli.
            for (int i = 0; i < n; i++)
            {
                Console.Write("{0} + {1} = ", test.Get(i), test.Get(i + 10));
                test.Set(i, test.Get(i) + test.Get(i + 10));
                Console.Write("{0}\n", test.Get(i));
            }
            
            Console.WriteLine();
            // Tworzę tabelę wypełnioną liczbami 2137
            Array test2 = new Array(-10, 100, 2137); 
            
            // Dodaje wartości tabeli test2 do test.
            for (int i = 0; i < n; i++)
            {
                Console.Write("{0} + {1} = ", test.Get(i), test2.Get(i + 10));
                test.Set(i, test.Get(i) + test2.Get(i + 10));
                Console.Write("{0}\n", test.Get(i));
            }
        }
    }
}
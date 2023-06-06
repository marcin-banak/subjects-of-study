// Marcin Banak
// lista 2, zadanie 1
// csc.exe zad1.cs

using System;
namespace zad2
{
    class IntStream 
    {
        private int _val; // Zmienna przechowująca kolejne liczby naturalne.
        
        public IntStream(int x = 0) // Konstruktor (przyjmujemy,
                                    // że liczby naturalne zaczynają się od 0).
        {
            this.Val = x;
        }

        public int Val // Własność obsługująca zmienną _val.
        {
            get { return _val; }
            set { this._val = value; }
        }
        
        public virtual int Next() // Funkcja zwracająca kolejne liczby naturalne.
        {
            int x = this.Val;
            if (x != Int32.MaxValue)
                this.Val++;
            return x;
        }

        public virtual bool eos() // Zwraca prawde jeśli nie można podać
                                  // następnej liczby naturalnej.
        {
            if (this.Val == Int32.MaxValue)
                return true;
            return false;
        }

        public virtual void reset() // Resetuje strumień.
        {
            this.Val = 0;
        }
    }

    class PrimeStream : IntStream
    {
        public PrimeStream(int x = 2) // Konstruktor (Pierwsza liczba pierwsza to 2).
        {
            this.Val = x;
        }

        public bool IsPrime() // Funkcja sprawdzająca pierwszość liczby.
        {
            if (this.Val % 2 == 0)
                return false;
            for (int i = 3; i * i <= this.Val; i += 2)
            {
                if (this.Val % i == 0)
                    return false;
            }

            return true;
        }
        
        public override int Next()
        {
            int x = this.Val;
            this.Val++;
            
            // Jeżeli osiągneliśmy wartość MaxInt zwracamy -1,
            // który nie zostanie zwrócony w żadnym innym wypadku
            while (!this.IsPrime())
            {                                   
                if (this.Val == Int32.MaxValue) 
                    return -1;
                base.Next();
            }
            return x;
        }

        // Jeżeli nie można podać kolejnej liczby pierwszej, funkcja zwraca prawdę.
        public override bool eos() 
        {
            int x = this.Val;
            
            // Sprawdzamy czy metoda next zwraca -1 wtedy przekroczyliśmy próg int.
            if (this.Next() == -1) 
                return true;
            this.Val = x;
            return false;
        }

        public override void reset() // Resetuje strumień.
        {
            this.Val = 2;
        }
    }

    class RandomStream : IntStream
    {
        Random rnd; // Generator liczb pseudo-losowych.
        
        public RandomStream() // Konstruktor.
        {
            this.rnd = new Random();
            this.Val = this.rnd.Next();
        }

        public override int Next() // Zwraca kolejną pseudo-losową liczbę.
        {
            int x = this.Val;
            this.Val = this.rnd.Next();
            return x;
        }

        // Zwraca fałsz, bo możemy generować liczby w nieskończoność.
        public override bool eos() 
        {
            return false;
        }
        
        // metoda reset nie ma konkretnej wartości do, której może 
        // zresetować strumień.
    }
    
    // Główna klasa do zaimplementowania
    class RandomWordStream
    {
        private string _word; // Losowe słowo o długości liczby pierwszej.
        private PrimeStream _ps; // Strumień liczb pierwszych.
        private RandomStream _rs; // Strumień liczb pseudo-losowych.

        public string Word // Własność obsługująca zmienną _word.
        {
            get { return _word; }
            set { this._word = value; }
        }
        
        public PrimeStream Ps // Własność obsługująca zmienną _ps.
        {
            get { return _ps; }
            set { this._ps = value; }
        }
        
        public RandomStream Rs // Własnośc obsługująca zmienną _rs.
        {
            get { return _rs; }
            set { this._rs = value; }
        }
        
        public RandomWordStream() // Konstruktor.
        {
            this.Ps = new PrimeStream();
            this.Rs = new RandomStream();
            string temp = "";
            int n = this.Ps.Next();
            for (int i = 0; i < n; i++)
            {
                temp += (char)(((this.Rs.Next()) % 26) + 'a');
            }

            this.Word = temp;
        }

        // Funkcja zwraca losowe słowo o długości liczby pierwszej.
        public string Next() 
        {
            string curr = this.Word; // Słowo, które zwróci funkcja.
            string temp = ""; // Zmienna na, której budujemy następne słowo.
            int n = this.Ps.Next();
            for (int i = 0; i < n; i++)
            {
                temp += (char)(((this.Rs.Next()) % 26) + 'a');
            }

            this.Word = temp;
            return curr;
        }

        public void reset() // Funkcja resetująca strumień.
        {
            this.Ps.reset();
            string temp = "";
            int n = this.Ps.Next();
            for (int i = 0; i < n; i++)
            {
                temp += (char)(((this.Rs.Next()) % 26) + 'a');
            }

            this.Word = temp;
        }
    }
    class Program
    {
        // Testy są zakomentowane dla większej czytelności.
        // Należy odkomentować, aby przetestować.
        
        static void Main() 
        {
            IntStream s = new IntStream();
            
            // Wypisuje pierwsze 1000 liczb z IntStream.
            /*while (!s.eos() && ps.Val < 1000)
            {
                Console.Write("{0} ", s.Next());
            }*/

            PrimeStream ps = new PrimeStream();
            
            // Wypisuje Wartości mniejsze od 1000 z PrimeStream.
            /*while (ps.eos() && ps.Val < 1000)
            {
                Console.Write("{0} ", ps.Next());
            }*/

            RandomStream rs = new RandomStream();
            
            // Wypisuje 100 losowych wartości.
            /*for (int i = 0; i < 100; i++)
            {
                Console.Write("{0} ", rs.Next());
            }*/

            RandomWordStream rws = new RandomWordStream();

            // Wypisuje kolejne losowe słowa o długości liczb pierwszych.
            for (int i = 0; i < 10; i++) 
            {
                if (!rws.Ps.eos())
                    Console.WriteLine("{0}: {1}\n", i, rws.Next());
            }
            
            rws.reset(); // test funkcji reset
            Console.WriteLine("Slowo po zresetowaniu sturmienia: {0}\n", rws.Next());
        }
    }
}
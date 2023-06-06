// Marcin Banak
// Lista 3, zadanie 1.
//
// Żeby uzyskać plik .dll, w którym zdefiniowane są klasy, wpisujemy komendę
// mcs -t:library zad1_klasy.cs 
// w wiersz poleceń Mono, po czym, aby uzyskać plik .exe, wpisujemy komendę
// mcs zad1_testy.cs -r:zad1_klasy.dll
// Aby wyświetlić wynik programu piszemy 
// zad1_testy.exe

using System;

namespace zad1
{
	public class Elem <T> // Klasa elementu listy.
		{
			// Pola klasy.
			private T _val; // Przechowywana wartość.
			private Elem<T> _next; // Wskaźnik na następny element.
			private Elem<T> _prev; // Wskaźnik na poprzedni element.

			// Konstruktor.
			public Elem(T val, Elem<T> next = null, Elem<T> prev = null)
			{
				this.Val = val;
				this.Next = next;
				this.Prev = prev;
			}

			/* Właściwość to konstrukcja charakterystyczna m.in. dla języka C#.
			   Zapewnia dostęp do pól klasy posługując się przy tym akcesorami get i set. 
			   Główną funkcjonalnością właściwości jest możliwość zapisywania i 
			   odczytywania prywatnych pól klasy, tak jak by były publiczne.*/
			
			// Właściwości klasy.
			public T Val
			{
				get { return this._val; }
				set { this._val = value; }
			}

			public Elem<T> Next
			{
				get { return this._next; }
				set { this._next = value; }
			}

			public Elem<T> Prev
			{
				get { return this._prev; }
				set { this._prev = value; }
			}
		}
		
		public class List <T> // Klasa listy.
		{
			// Pola klasy.
			private Elem<T> _first; // Wskaźnik na pierwszy element listy.
			private Elem<T> _last; // Wskaźnik na ostatni element listy.
			
			// Konstruktor.
			public List()
			{
				this.First = null;
				this.Last = null;
			}

			public List(Elem<T> elem)
			{
				this.First = elem;
				this.Last = elem;
			}

			// Właściwości klasy.
			public Elem<T> First
			{
				get { return this._first; }
				set { this._first = value; }
			}

			public Elem<T> Last
			{
				get { return this._last; }
				set { this._last = value; }
			}
			
			// Metody klasy.
			
			// Zwraca true, gdy lista jest pusta.
			public bool IsEmpty() 
			{
				if (this.First == null)
					return true;
				return false;
			}

			// Dodaje element na początek listy.
			public void PushFront(Elem<T> fresh)
			{
				if (this.IsEmpty())
				{
					this.First = fresh;
					this.Last = this.First;
				}
				else
				{
					Elem<T> aux = this.First; // Zmienna pomocnicza
					this.First = fresh;
					this.First.Next = aux;
					aux.Prev = this.First;
				}
			}

			// Dodaje element na koniec listy.
			public void PushBack(Elem<T> fresh)
			{
				if (this.IsEmpty())
				{
					this.First = fresh;
					this.Last = this.First;
				}
				else
				{
					this.Last.Next = fresh;
					fresh.Prev = this.Last;
					this.Last = this.Last.Next;
				}
			}

			// Usuwa element z początku listy.
			public Elem<T> PopFront()
			{
				if (this.IsEmpty())
				{
					Console.WriteLine("Nie mozna usunac pierwszego elementu, " +
									  "poniewaz lista jest pusta.");
					return null;
				}
				else
				{
					Elem<T> aux = this.First;
					this.First = this.First.Next;
					this.First.Prev = null;
					return aux;
				}
			}

			// Usuwa element z końca listy.
			public Elem<T> PopBack()
			{
				if (this.IsEmpty())
				{
					Console.WriteLine("Nie mozna usunac ostatniego elementu, " +
									  "poniewaz lista jest pusta.");
					return null;
				}
				else
				{
					Elem<T> aux = this.Last;
					this.Last = this.Last.Prev;
					this.Last.Next = null;
					return aux;
				}
			}

			// Wypisuje zawartość listy.
			public void PrintList()
			{
				Elem<T> aux = this.First;
				for (int i = 0; aux != null; i++)
				{
					Console.WriteLine("Wartosc elementu nr {0}: {1}", i, aux.Val);
					aux = aux.Next;
				}
			}
		}
}
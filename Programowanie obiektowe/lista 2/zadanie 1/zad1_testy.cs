using System;
using System.Linq.Expressions;

namespace zad1
{
	class Program
    {
        static void Main()
        {
            // Testowanie implementacji klasy List.
            List<int> list = new List<int>();
            list.PushFront(new Elem<int>(12));
            list.PushFront(new Elem<int>(2));
            list.PushFront(new Elem<int>(222));
            list.PushFront(new Elem<int>(1111));
            list.PushBack(new Elem<int>(323));
            list.PushBack(new Elem<int>(564));
            list.PushBack(new Elem<int>(5555));
            Console.WriteLine("Lista przed uzyciem metod usuwajacych elementy.");
            list.PrintList();
            list.PopFront();
            list.PopFront();
            list.PopBack();
            list.PopBack();
            Console.WriteLine("Lista po uzyciu metod usuwajacych elementy.");
            list.PrintList();
            list.PushFront(new Elem<int>(222));
            list.PushFront(new Elem<int>(1111));
            list.PushBack(new Elem<int>(564));
            list.PushBack(new Elem<int>(5555));
            Console.WriteLine("Lista po dodaniu usunietych elementow.");
            list.PrintList();
        }
    }
}
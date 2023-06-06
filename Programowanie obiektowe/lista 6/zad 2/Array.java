import java.util.Collection;
import java.util.Iterator;

public class Array<T> implements Collection<T> {
    private int size; // Wielkość tablicy.
    private T[] objects; // Tablica Obiektów.
    private int amount; // Obecna ilość obiektów w tablicy.

    public Array(int s)
    {
        this.size = s;
        this.objects = (T[]) new Object[s];
        this.amount = 0;
    }

    // Metoda zwraca rozmiar kolekcji.
    @Override
    public int size() {
        return this.amount;
    }

    // Metoda zwraca prawdę jeśli kolekcja jest pusta.
    @Override
    public boolean isEmpty() {
        return this.amount == 0;
    }

    // Metoda zwraca prawdę jeśli obiekt o znajduje się w kolekcji.
    @Override
    public boolean contains(Object o) {
        for (int i = 0; i < this.amount; i++)
        {
            if (o.equals(this.objects[i]))
                return true;
        }
        return false;
    }

    // Metoda zwraca obiekt iterator dla kolekcji.
    @Override
    public Iterator iterator() {
        return new MyIterator(this.objects, this.amount);
    }

    // Metoda zwraca tablicę obiektów.
    @Override
    public Object[] toArray() {
        return this.objects;
    }

    // Metoda dodaje obiekt do kolekcji.
    @Override
    public boolean add(Object o) {
        if (this.amount == this.size)
            return false;
        this.objects[this.amount++] = (T)o;
        return true;
    }

    // Metoda usuwa element z kolekcji.
    @Override
    public boolean remove(Object o) {
        if (this.amount == 0)
            return false;
        int index = -1;
        for (int i = 0; i < this.amount; i++)
        {
            if (o.equals(this.objects[i]))
            {
                index = i;
                break;
            }
        }
        // Jeśli indeks jest równy -1 to obiekt o nie należy do tablicy.
        if (index == -1)
            return false;
        this.amount--;
        // Przesuwamy wszystkie obiekty na prawo od obiektu o w lewo.
        for (; index < this.amount; index++)
        {
            this.objects[index] = this.objects[index + 1];
        }
        return true;
    }

    // Metoda dodaje kolekcję c do obecnej kolekcji.
    @Override
    public boolean addAll(Collection c) {
        T[] aux = (T[]) new Object[this.size + c.size()];
        for (int i = 0; i < this.amount; i++)
        {
            aux[i] = this.objects[i];
        }
        T[] temp = (T[]) c.toArray();
        for (int i = 0; i < c.size(); i++)
        {
            aux[this.amount + i] = temp[i];
        }
        this.objects = aux;
        this.amount = this.amount + c.size();

        return true;
    }

    // Metoda czyści kolekcję z przechowywanych elementów.
    @Override
    public void clear() {
        this.objects = (T[]) new Object[this.size];
        this.amount = 0;
    }

    // Metoda usuwa z kolekcji wszystkie elementy, których nie zawiera kolekcja c.
    @Override
    public boolean retainAll(Collection c) {
        boolean modified = false;
        for (int i = 0; i < this.amount; i++) {
            if (!(c.contains(this.objects[i])))
            {
                this.remove(this.objects[i]);
                modified = true;
            }
        }
        return modified;
    }

    // Metoda usuwa z kolekcji wszystkie elementy zawarte w kolekcji c.
    @Override
    public boolean removeAll(Collection c) {
        T[] aux = (T[]) c.toArray();
        boolean modified = false;
        for (int i = 0; i < c.size(); i++) {
            while (this.contains(aux[i]))
            {
                this.remove(aux[i]);
                modified = true;
            }
        }
        return modified;
    }

    // Metoda zwraca prawdę, jeśli są w niej wszystkie elementy z kolekcji c.
    @Override
    public boolean containsAll(Collection c) {
        T[] aux = (T[]) c.toArray();
        for (int i = 0; i < c.size(); i++)
        {
            if (!(this.contains(aux[i])))
                return false;
        }
        return true;
    }

    // Metoda zwraca tablice zawierającą elementy kolekcji.
    // Jeśli kolekcja a ma odpowiedni rozmiar,
    // to metoda wpisze do niej elementy z obecnej kolekcji.
    @Override
    public Object[] toArray(Object[] a) {
        if (a.length >= this.amount){
            for (int i = 0; i < this.amount; i++)
            {
                a[i] = this.objects[i];
            }
        }
        return this.objects;
    }
}

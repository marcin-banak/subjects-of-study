import java.util.Iterator;

public class MyIterator<T> implements Iterator {
    private int size;
    private T[] current;
    private int i;

    public MyIterator(T[] objects, int size) {
        this.current = objects;
        this.size = size;
        this.i = 0;
    }

    public boolean hasNext() {
        return this.i != this.size;
    }

    public T next() {
        return this.current[this.i++];
    }
}
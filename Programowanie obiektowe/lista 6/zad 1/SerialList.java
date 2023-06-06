import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class SerialList implements Serializable {
    // Lista przechowywana przez kolekcję.
    private List<String> list;

    // Konstruktor.
    public SerialList() {
        this.list = new ArrayList<>();
    }
    // Metoda dodaje element do listy.
    public void add(String str) {
        this.list.add(str);
    }
    // Metoda usuwa element z listy.
    public void remove(String str) {
        this.list.remove(str);
    }
    // Metoda zwraca przechowywaną listę.
    public List<String> getList() {
        return this.list;
    }

    // Metoda zapisuje listę do pliku.
    public void saveToFile(String filename) throws IOException {
        FileWriter out = new FileWriter(filename);
        for (String o : this.list) {
            out.write(o + '\n');
        }
        out.close();
    }

    // Metoda odczytuje listę z pliku.
    public static SerialList readFromFile(String filename) throws IOException, ClassNotFoundException {
        BufferedReader in = new BufferedReader(new FileReader(filename));
        SerialList list = new SerialList();
        String line;
        while ((line = in.readLine()) != null)
            list.add(line);
        in.close();
        return list;
    }

    public void PrintList() {
        for (int i = 0; i < this.list.size(); i++)
        {
            System.out.println(this.list.get(i));
        }
    }
}

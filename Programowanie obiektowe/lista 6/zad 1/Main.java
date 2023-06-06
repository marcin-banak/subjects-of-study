/* Marcin Banak
   Lista 6, zadanie 1
   Program skompilowany poleceniem:
   "javac Main.java".
   Wywołuje program poleceniem:
   "java Main.class"
 */

import java.io.IOException;
public class Main {
    public static void main(String[] args) {
        String filename = "testowy_plik.txt";
        try {
            SerialList list1 = new SerialList();
            list1.add("test1");
            list1.add("test2");
            list1.add("test3");
            list1.add("test4");

            list1.saveToFile(filename);

            list1.remove("test4");

            System.out.println("Zawartość kolekcji list1:");
            list1.PrintList();
        }
        catch (IOException e)
        {
            System.out.println(e.getMessage());
        }

        try {
            SerialList list2 = SerialList.readFromFile(filename);
            System.out.println("\nZawartość kolekcji list2:");
            list2.PrintList();
        }
        catch (IOException e)
        {
            System.out.println(e.getMessage());
        }
        catch (ClassNotFoundException e)
        {
            System.out.println(e.getMessage());
        }
    }
}
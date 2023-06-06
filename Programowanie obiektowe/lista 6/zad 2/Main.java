/* Marcin Banak
   Lista 6, zadanie 2
   Program skompilowany poleceniem:
   "javac Main.java".
   Wywołuje program poleceniem:
   "java Main.class"
 */

public class Main {
    public static void main(String[] args) {
        Array<Integer> t1 = new Array(6);
        Array<Integer> t2 = new Array(3);

        t2.add(12);
        t2.add(3);
        t2.add(24);
        t1.addAll(t2);
        t1.add(420);

        // Użycie składni "foreach" dla kolekcji Array.
        System.out.print("t2: ");
        for (Integer o : t2)
            System.out.print(o + " ");
        System.out.print("\nt1: ");
        for (Integer o : t1)
            System.out.print(o + " ");

        // Metoda sprawdza czy każdy element z kolekcji t2 występuje w t1.
        System.out.println("\nWynik metody t1.containsAll(t2)");
        System.out.println(t1.containsAll(t2));
        System.out.println("Wynik metody t2.containsAll(t1)");
        System.out.println(t2.containsAll(t1));

        t1.retainAll(t2);
        System.out.println("Wynik metody t1.retainAll(t2):");
        for (Integer o : t1)
            System.out.print(o + " ");

        t1.add(420);
        t1.removeAll(t2);
        System.out.println("\nWynik metody t1.removeAll(t2):");
        for (Integer o : t1)
            System.out.print(o + " ");

        // W klasie Array można przechowywać obiekty o różnych typach.
        Array<String> t3 = new Array(3);
        t3.add("Jeden");
        t3.add("Dwa");
        t3.add("Trzy");

        System.out.print("\nt3: ");
        for (String o : t3)
            System.out.print(o + " ");
    }
}
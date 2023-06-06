/* Marcin Banak
   Lista 5, zadanie 1
   Program skompilowany poleceniem:
   "javac Main.java".
   i wywołuje program poleceniem:
   "java Main.class"
 */
public class Main {
    public static void main(String[] args) {
        Kler k1 = new Papiez("Jan Paweł II", "Karol", "Wojtyła", 0);
        Kler k2 = new Kaplan("Tadeusz", "Rydzyk", 120000, 500000);
        Kler k3 = new Papiez("Benedykt XVI", "Joseph", "Ratzinger", 80000);
        Kler k4 = new Kardynal("Stefan", "Wyszyński", 123);
        Kler k5 = new Biskup("Józef", "Kupny", 30000, 400000);
        Kler k6 = new Papiez("Urban II", "Odon", "de Lagery", 800000);

        ((Kaplan) k2).ZbierzNaTace(10000);
        ((Kaplan) k2).ZbierzNaTace(20000);
        ((Kaplan) k2).ZbierzNaTace(5500);
        ((Kaplan) k2).ZbierzNaTace(30000);
        ((Kaplan) k2).WyremontujPlebanie(30000);
        ((Kaplan) k2).ZbierzNaTace(15000);
        ((Kaplan) k2).KupMercedesa(150000);

        ((Papiez) k6).ZwolajKrucjate();

        OrderedList duchowni = new OrderedList();
        duchowni.Add(k1);
        duchowni.Add(k2);
        duchowni.Add(k3);
        duchowni.Add(k4);
        duchowni.Add(k5);
        duchowni.Add(k6);
    }
}
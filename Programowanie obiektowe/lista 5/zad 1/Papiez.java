public class Papiez extends Kler {
    String _imiePontyfikalne;
    public Papiez(String pseudonim, String imie, String nazwisko, double szekle) {
        this._imiePontyfikalne = pseudonim;
        this._imie = imie;
        this._nazwisko = nazwisko;
        this._zasobnoscPortfela = szekle;
        this.nastepny = null;
    }

    public void ZwolajKrucjate() {
        System.out.println("Deus vult!");
    }

    public int compareTo(Kler jegomosc) {
        return Double.compare(this._zasobnoscPortfela, jegomosc._zasobnoscPortfela);
    }
}

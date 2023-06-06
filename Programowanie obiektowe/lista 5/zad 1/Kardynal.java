public class Kardynal extends Kler{
    public Kardynal(String imie, String nazwisko, double szekle) {
        this._imie = imie;
        this._nazwisko = nazwisko;
        this._zasobnoscPortfela = szekle;
        this.nastepny = null;
    }

    public int compareTo(Kler jegomosc) {
        return Double.compare(this._zasobnoscPortfela, jegomosc._zasobnoscPortfela);
    }
}

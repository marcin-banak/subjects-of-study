public class Biskup extends Kler{
    double _pieniadzeDiecezjalne;
    public Biskup(String imie, String nazwisko, double szekle, double PLN) {
        this._imie = imie;
        this._nazwisko = nazwisko;
        this._zasobnoscPortfela = szekle;
        this._pieniadzeDiecezjalne = PLN;
        this.nastepny = null;
    }

    void ZorganizujZbiorke(double PLN) {
        this._pieniadzeDiecezjalne += PLN;
    }

    public int compareTo(Kler jegomosc) {
        return Double.compare(this._zasobnoscPortfela, jegomosc._zasobnoscPortfela);
    }
}

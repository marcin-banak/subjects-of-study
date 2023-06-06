public class Kaplan extends Kler {
    public double _pieniadzeParafialne;

    public Kaplan(String imie, String nazwisko, double szekle, double PLN) {
        this._imie = imie;
        this._nazwisko = nazwisko;
        this._zasobnoscPortfela = szekle;
        this._pieniadzeParafialne = PLN;
        this.nastepny = null;
    }

    public void ZbierzNaTace(double PLN) {
        this._zasobnoscPortfela += 0.3 * PLN;
        this._pieniadzeParafialne += 0.7 * PLN;
    }

    public void WyremontujPlebanie(double koszt) {
        koszt *= 1.3;
        this._zasobnoscPortfela += 0.5 * koszt;
        this._pieniadzeParafialne -= koszt;
        System.out.println("Koszty remontu okazały się przekraczać te wstępnie oszacowane.");
        this.ZbierzNaTace(0.5 * koszt);
    }

    public void KupMercedesa(int koszt) {
        this._zasobnoscPortfela -= 0.3 * koszt;
        this._pieniadzeParafialne -= 0.7 * koszt;
    }

    public int compareTo(Kler jegomosc) {
        return Double.compare(this._zasobnoscPortfela, jegomosc._zasobnoscPortfela);
    }
}

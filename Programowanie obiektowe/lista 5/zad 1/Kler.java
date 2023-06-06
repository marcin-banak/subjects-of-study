import java.util.InputMismatchException;

public class Kler implements Comparable<Kler>{
    public String _imie;
    public String _nazwisko;
    public double _zasobnoscPortfela;
    public Kler nastepny;
    public int compareTo (Kler jegomosc)
    {
        return Double.compare(this._zasobnoscPortfela, jegomosc._zasobnoscPortfela);
    }
}

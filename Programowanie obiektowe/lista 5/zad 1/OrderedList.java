public class OrderedList {
    public Kler _first = null;
    // Funkcja porównuje ze sobą elementy listy i wstawia element podany w
    // argumencie na odpowiednie miejsce. Elementy sortowane są po wartości pola
    // _zasobnoscPortfela.
    public void Add(Kler elem)
    {
        if (this._first == null)
            this._first = elem;
        else if (elem.compareTo(this._first) < 0)
        {
            elem.nastepny = this._first;
            this._first = elem;
        }
        else
        {
            Kler aux = this._first;
            while (aux.nastepny != null && elem.compareTo(aux.nastepny) > 0)
                aux = aux.nastepny;
            elem.nastepny = aux.nastepny;
            aux.nastepny = elem;
        }
    }
    // Funkcja zwraca pierwszy element listy.
    public Kler GetFirst()
    {
        return this._first;
    }
    public String Stringify()
    {
        Kler aux = this._first;
        // String który ma zwrócić metoda.
        String toReturn = "";
        while (aux != null)
        {
            toReturn += aux._imie + ' ' + aux._nazwisko + ' '
                    + Double.toString(aux._zasobnoscPortfela)  + '\n';
            aux = aux.nastepny;
        }
        return toReturn;
    }
}

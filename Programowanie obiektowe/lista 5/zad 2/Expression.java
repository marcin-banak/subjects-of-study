// Klasa wyrażenia arytmetycznego, po której dziedziczą inne klasy.
public class Expression {
    Expression _exp1; // Przetrzymywane wyrażenie;

    // Metoda obliczająca wartość wyrażenia
    public double evaluate() {
        return this._exp1.evaluate();
    }

    // Metoda wypisująca wyrażenie w formie graficznej
    public String Stringify() {
        return this._exp1.Stringify();
    }

    public void SetVar(double val, String var) {
        this._exp1.SetVar(val, var);
    }
}

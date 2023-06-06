// Klasa zmiennej
public class Var extends Expression {
    String _var; // Nazwa zmiennej
    double _val; // Wartość zmiennej

    public Var(int val, String var) {
        this._exp1 = null;
        this._val = val;
        this._var = var;
    }

    public double evaluate() {
        return this._val;
    }

    public String Stringify() {
        return '(' + this._var + " = " + Double.toString(this._val) + ')';
    }

    public void SetVar(double val, String var) {
        if (this._var == var)
            this._val = val;
    }
}

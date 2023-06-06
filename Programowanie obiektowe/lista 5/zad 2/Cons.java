public class Cons extends Expression {
    double _val;

    public Cons(int val) {
        this._exp1 = null;
        this._val = val;
    }

    public double evaluate() {
        return this._val;
    }

    public String Stringify() {
        return Double.toString(this._val);
    }

    public void SetVar(double val, String var) {
    }
}

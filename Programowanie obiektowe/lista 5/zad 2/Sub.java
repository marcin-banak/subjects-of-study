public class Sub extends Expression {
    Expression _exp2;

    public Sub(Expression exp1, Expression exp2) {
        this._exp1 = exp1;
        this._exp2 = exp2;
    }

    public double evaluate() {
        return this._exp1.evaluate() - this._exp2.evaluate();
    }

    public String Stringify() {
        return '(' + this._exp1.Stringify() + " - " + this._exp2.Stringify() + ')';
    }

    public void SetVar(double val, String var) {
        this._exp1.SetVar(val, var);
        this._exp2.SetVar(val, var);
    }
}

public class Div extends Expression {
    Expression _exp2;

    public Div(Expression exp1, Expression exp2) {
        this._exp1 = exp1;
        this._exp2 = exp2;
    }

    public double evaluate() {
        double exp1 = this._exp1.evaluate();
        double exp2 = this._exp2.evaluate();
        try {
            if (exp2 == 0)
                throw new Exception("Dzielenie przez zero!");
        } catch (Exception e) {
            System.out.println(e);
            return 0;
        }
        return exp1 / exp2;
    }

    public String Stringify() {
        return '(' + this._exp1.Stringify() + " / " + this._exp2.Stringify() + ')';
    }

    public void SetVar(double val, String var) {
        this._exp1.SetVar(val, var);
        this._exp2.SetVar(val, var);
    }
}

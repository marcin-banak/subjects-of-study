/* Marcin Banak
   Lista 5, zadanie 2
   Program skompilowany poleceniem:
   "javac Main.java".
   i wywołuje program poleceniem:
   "java Main.class"
 */
public class Main {
    public static void main(String[] args) {
        // Zaprezentowanie działania funkcji dla jakiegoś wyrażenia.
        Expression exp = new Mult(new Add(new Cons(5), new Cons(12)), new Cons(3));
        System.out.println(exp.evaluate());
        System.out.println(exp.Stringify());

        // Przypadek z dzieleniem przez zero.
        System.out.println();
        Expression div0 = new Div(exp, new Cons(0));
        System.out.println(div0.evaluate());
        System.out.println(div0.Stringify());

        // Wyrażenie ze zmienną.
        System.out.println();
        Expression withVar = new Sub(exp, new Var(13, "x"));
        System.out.println(withVar.evaluate());
        System.out.println(withVar.Stringify());

        System.out.println();
        withVar.SetVar(2, "x");
        System.out.println(withVar.evaluate());
        System.out.println(withVar.Stringify());

        System.out.println();
        Expression withVar2 = new Mult(new Var(10, "x"), new Var(2, "y"));
        withVar2.SetVar(5, "x");
        System.out.println(withVar2.evaluate());
        System.out.println(withVar2.Stringify());
    }
}
#include <iostream>
#include "Expression.h++"
#include "Operand.h++"
#include "UnaryOperators.h++"
#include "BinaryOperators.h++"

int main() {
    Expression *num = new MultiplicativeInverse(new MultiplicativeInverse(new Number(-4)));
    std::cout << num->toString();

    Expression *num2 = new AdditiveInverse(new AdditiveInverse(new Number(1)));
    std::cout << num2->toString();

    Expression *mult = new Mult(new Mult(new Add(new Number(1), new Number(2)), new Sub(new Number(3), new Number(4))), new Number(5));
    std::cout << '\n' + mult->toString() + '\n';

    Expression *pow = new Pow(new Div(new Number(12), new AdditiveInverse(new Number(-3))), new MultiplicativeInverse(new Number(2)));
    std::cout << pow->toString() + " = " << pow->evaluate() << '\n';

    Expression *x = new Var("x", 0);
    Expression *y = new Var("y", 0);
    Expression *exp1 = new Div(new Mult(new Sub(x,new Number(1)), x), new Number(2));
    std::cout << exp1->toString() + " = " << exp1->evaluate() << '\n';
    Expression *exp2 = new Div(new Add(new Number(3), new Number(5)), new Add(new Number(2), new Mult(x, new Number(7))));
    std::cout << exp2->toString() + " = " << exp2->evaluate() << '\n';
    Expression *exp3 = new Sub(new Add(new Number(2), new Mult(x, new Number(7))), new Add(new Mult(y, new Number(3)), new Number(5)));
    std::cout << exp3->toString() + " = " << exp3->evaluate() << '\n';
    Expression *exp4 = new Div(new Cos(new Mult(new Add(x, new Number(1)), new Pi())), new Pow(new Pow(new E(), x), new Number(2)));
    std::cout << exp4->toString() + " = " << exp4->evaluate() << '\n';

    for (int i = 0; i <= 10; i += 1) {
        double j = i * 0.01;
        Var::Modify("x", j);
        Var::Modify("y", j);
        std::cout << "((x-1)*x)/2 = " << exp1->evaluate() << '\n';
        std::cout << "(3+5)/(2+x*7) = " << exp2->evaluate() << '\n';
        std::cout << "2+x*7-(y*3+5) = " << exp3->evaluate() << '\n';
        std:: cout << "cos((x+1)*pi)/e^x^2 = " << exp4->evaluate() << "\n\n";
    }
    return 0;
}

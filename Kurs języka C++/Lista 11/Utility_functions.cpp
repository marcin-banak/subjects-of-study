#include "Utility_functions.h++"

using namespace Calculator;

bool is_numeric(std::string str) {
    int i = 0;
    if (str[0] == '-' && str.length() > 1)
        i++;
    while (i < str.length()) {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}

double modulo(double a, double b)
{
    double mod;
    if (a < 0)
        mod = -a;
    else
        mod =  a;
    if (b < 0)
        b = -b;

    while (mod >= b)
        mod = mod - b;

    if (a < 0)
        return -mod;

    return mod;
}

int sgn(double x) {
    return (0 < x) - (0 > x);
}

void parse(std::string instruction, std::vector<Expression*> &exp) {
    int i = 0;

    while (i < instruction.length()) {
        std::string temp = "";
        while (i < instruction.length() && instruction[i] != ' ') {
            temp += instruction[i];
            i++;
        }
        i++;
        if (temp == "")
            continue;
        if (is_numeric(temp))
            exp.push_back(new Number(std::stoi(temp)));
        else if (temp == "pi")
            exp.push_back(new Pi());
        else if (temp == "e")
            exp.push_back(new E());
        else if (temp == "fi")
            exp.push_back(new Fi());
        else if (temp == "+")
            exp.push_back(new Add());
        else if (temp == "-")
            exp.push_back(new Sub());
        else if (temp == "*")
            exp.push_back(new Mult());
        else if (temp == "/")
            exp.push_back(new Div());
        else if (temp == "%")
            exp.push_back(new Modulo());
        else if (temp == "min")
            exp.push_back(new Min());
        else if (temp == "max")
            exp.push_back(new Max());
        else if (temp == "log")
            exp.push_back(new Log());
        else if (temp == "pow")
            exp.push_back(new Pow());
        else if (temp == "abs")
            exp.push_back(new Abs());
        else if (temp == "sgn")
            exp.push_back(new Sgn());
        else if (temp == "floor")
            exp.push_back(new Floor());
        else if (temp == "ceil")
            exp.push_back(new Ceil());
        else if (temp == "frac")
            exp.push_back(new Frac());
        else if (temp == "sin")
            exp.push_back(new Sin());
        else if (temp == "cos")
            exp.push_back(new Cos());
        else if (temp == "atan")
            exp.push_back(new Atan());
        else if (temp == "ln")
            exp.push_back(new Ln());
        else if (temp == "exp")
            exp.push_back(new Exp());
        else
            exp.push_back(new Var(temp));
    }
}

double eval(std::vector<Expression*> &exp) {
    std::stack<double> stack;
    for (Expression* e : exp) {
        if (e->type() == "proc") {
            std::string temp = ((Procedure*)e)->value();
            if (temp == "+") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(temp1 + temp2);
                }
                else
                    std::clog << "Not enough values on stack to perform +! \n";
            }
            else if (temp == "-") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(temp2 - temp1 );
                }
                else
                    std::clog << "Not enough values on stack to perform -! \n";
            }
            else if (temp == "*") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(temp1 * temp2);
                }
                else
                    std::clog << "Not enough values on stack to perform *! \n";
            }
            else if (temp == "/") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(temp1 / temp2);
                }
                else
                    std::clog << "Not enough values on stack to perform /! \n";
            }
            else if (temp == "%") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(modulo(temp1, temp2));
                }
                else
                    std::clog << "Not enough values on stack to perform %! \n";
            }
            else if (temp == "min") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(std::min(temp1, temp2));
                }
                else
                    std::clog << "Not enough values on stack to perform min! \n";
            }
            else if (temp == "max") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(std::max(temp1, temp2));
                }
                else
                    std::clog << "Not enough values on stack to perform max! \n";
            }
            else if (temp == "log") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(log(temp1) / log(temp2));
                }
                else
                    std::clog << "Not enough values on stack to perform log! \n";
            }
            else if (temp == "pow") {
                if (stack.size() >= 2) {
                    double temp1 = stack.top();
                    stack.pop();
                    double temp2 = stack.top();
                    stack.pop();
                    stack.push(std::max(temp1, temp2));
                }
                else
                    std::clog << "Not enough values on stack to perform max! \n";
            }
            else if (temp == "abs") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(std::abs(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform abs! \n";
            }
            else if (temp == "sgn") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(sgn(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform sgn! \n";
            }
            else if (temp == "floor") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(floor(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform floor! \n";
            }
            else if (temp == "ceil") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(ceil(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform ceil! \n";
            }
            else if (temp == "frac") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(floor(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform frac! \n";
            }
            else if (temp == "sin") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(sin(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform sin! \n";
            }
            else if (temp == "cos") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(cos(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform cos! \n";
            }
            else if (temp == "atan") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(atan(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform atan! \n";
            }
            else if (temp == "ln") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(log(temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform ln! \n";
            }
            else if (temp == "exp") {
                if (stack.size() >= 1) {
                    double temp1 = stack.top();
                    stack.pop();
                    stack.push(pow(M_E, temp1));
                }
                else
                    std::clog << "Not enough values on stack to perform exp! \n";
            }
            else {
                if (Var::In(((Var*)e)->GetName()) != -1) {
                    stack.push(((Var*)e)->value());
                }
                else
                    std::clog << "No variable named " << ((Var*)e)->GetName() << "! \n";
            }
        }
        else if (e->type() == "number")
            stack.push(((Number*)e)->value());
        else if (e->type() == "const")
            stack.push(((Constant*)e)->value());
        else
            stack.push(((Var*)e)->value());
    }
    if (stack.size() > 1)
        std::clog << "Evaluation ended with too much values on stack! \n";

    return stack.top();
}
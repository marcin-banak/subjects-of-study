#include "UnaryOperators.h++"

UnaryOperator::~UnaryOperator() {
    delete this->l;
}

Sin::Sin(Expression *exp1) {
    this->priority = 10;
    this->l = exp1;
}

double Sin::evaluate() {
    return sin(this->l->evaluate());
}

std::string Sin::toString() {
    return "sin(" + this->l->toString() + ')';
}

Cos::Cos(Expression *exp1) {
    this->priority = 10;
    this->l = exp1;
}

double Cos::evaluate() {
    return cos(this->l->evaluate());
}

std::string Cos::toString() {
    return "cos(" + this->l->toString() + ')';
}

Exp::Exp(Expression *exp1) {
    this->priority = 10;
    this->l = exp1;
}

double Exp::evaluate() {
    return pow(M_E, this->l->evaluate());
}

std::string Exp::toString() {
    return "exp(" + this->l->toString() + ')';
}

Ln::Ln(Expression *exp1) {
    this->priority = 10;
    this->l = exp1;
}

double Ln::evaluate() {
    return log(this->l->evaluate());
}

std::string Ln::toString() {
    return "ln(" + this->l->toString() + ')';
}

Abs::Abs(Expression *exp1) {
    this->priority = 10;
    this->l = exp1;
}

double Abs::evaluate() {
    return abs(this->l->evaluate());
}

std::string Abs::toString() {
    return '|' + this->l->toString() + '|';
}

AdditiveInverse::AdditiveInverse(Expression *exp1) {
    this->priority = 10;
    this->l = exp1;
}

double AdditiveInverse::evaluate() {
    return -this->l->evaluate();
}

std::string AdditiveInverse::toString() {
    std::string temp = this->l->toString();
    if (temp[0] == '-')
        return temp.substr(1, temp.size() - 1);
    return '-' + temp;
}

MultiplicativeInverse::MultiplicativeInverse(Expression *exp1) {
    this->priority = 10;
    this->l = exp1;
}

double MultiplicativeInverse::evaluate() {
    return 1 / this->l->evaluate();
}

std::string MultiplicativeInverse::toString() {
    std::string temp = this->l->toString();
    if (temp.size() > 4) {
        if (temp[temp.size() - 3] == '^' &&
            temp[temp.size() - 2] == '-' &&
            temp[temp.size() - 1] == '1') {
            if (this->l->evaluate() < 0)
                return temp.substr(1, temp.size() - 5);
            return temp.substr(0, temp.size() - 3);
        }
    }
    if (this->l->evaluate() < 0)
        return '(' + temp + ")^-1";
    return temp + "^-1";
}
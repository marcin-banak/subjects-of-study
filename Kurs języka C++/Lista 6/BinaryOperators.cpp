#include "BinaryOperators.h++"

BinaryOperator::~BinaryOperator() {
    delete this->r;
}

Add::Add(Expression *exp1, Expression *exp2) {
    this->priority = 0;
    this->l = exp1;
    this->r = exp2;
}

double Add::evaluate() {
    return this->l->evaluate() + this->r->evaluate();
}

std::string Add::toString() {
    return this->l->toString() + " + " + this->r->toString();
}

Sub::Sub(Expression *exp1, Expression *exp2) {
    this->priority = 0;
    this->l = exp1;
    this->r = exp2;
}

double Sub::evaluate() {
    return this->l->evaluate() - this->r->evaluate();
}

std::string Sub::toString() {
    if (this->r->GetPriority() != 10)
        return this->l->toString() + " - (" + this->r->toString() + ')';
    return this->l->toString() + " - " + this->r->toString();
}

Mult::Mult(Expression *exp1, Expression *exp2) {
    this->priority = 1;
    this->l = exp1;
    this->r = exp2;
}

double Mult::evaluate() {
    return this->l->evaluate() * this->r->evaluate();
}

std::string Mult::toString() {
    if (this->l->GetPriority() < this->priority && this->r->GetPriority() < this->priority)
        return '(' + this->l->toString() + ") * (" + this->r->toString() + ')';
    else if (this->l->GetPriority() < this->priority)
        return '(' + this->l->toString() + ") * " + this->r->toString();
    else if (this->r->GetPriority() < this->priority)
        return this->l->toString() + " * (" + this->r->toString() + ')';
    else
        return this->l->toString() + " * " + this->r->toString();
}

Div::Div(Expression *exp1, Expression *exp2) {
    this->priority = 1;
    this->l = exp1;
    this->r = exp2;
}
double Div::evaluate() {
    return this->l->evaluate() / this->r->evaluate();
}
std::string Div::toString() {
    if (this->l->GetPriority() < this->priority && this->r->GetPriority() < this->priority)
        return '(' + this->l->toString() + ") / (" + this->r->toString() + ')';
    else if (this->l->GetPriority() < this->priority)
        return '(' + this->l->toString() + ") / " + this->r->toString();
    else if (this->r->GetPriority() < this->priority)
        return this->l->toString() + " / (" + this->r->toString() + ')';
    else
        return this->l->toString() + " / " + this->r->toString();
}

Log::Log(Expression *exp1, Expression *exp2) {
    this->priority = 10;
    this->l = exp1;
    this->r = exp2;
}

double Log::evaluate() {
    return log(this->l->evaluate()) / log(this->r->evaluate());
}

std::string Log::toString() {
    return "log(" + this->l->toString() + ", " + this->r->toString() + ')';
}

Modulo::Modulo(Expression *exp1, Expression *exp2) {
    this->priority = 3;
    this->l = exp1;
    this->r = exp2;
}

double Modulo::evaluate() {
    double a = this->l->evaluate();
    double b = this->r->evaluate();
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

std::string Modulo::toString() {
    if (this->l->GetPriority() < this->priority && this->r->GetPriority() < this->priority)
        return '(' + this->l->toString() + ") % (" + this->r->toString() + ')';
    else if (this->l->GetPriority() < this->priority)
        return '(' + this->l->toString() + ") % " + this->r->toString();
    else if (this->r->GetPriority() < this->priority)
        return this->l->toString() + " % (" + this->r->toString() + ')';
    else
        return this->l->toString() + " % " + this->r->toString();
}

Pow::Pow(Expression *exp1, Expression *exp2) {
    this->priority = 10;
    this->l = exp1;
    this->r = exp2;
}

double Pow::evaluate() {
    return pow(this->l->evaluate(), this->r->evaluate());
}

std::string Pow::toString() {
    if (this->l->GetPriority() < this->priority)
        return '(' + this->l->toString() + ")^" + this->r->toString();
    return this->l->toString() + '^' + this->r->toString();
}
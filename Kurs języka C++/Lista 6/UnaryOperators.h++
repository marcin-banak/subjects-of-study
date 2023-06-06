#pragma once

#include "Expression.h++"

class UnaryOperator : public Expression {
protected:
    Expression *l;
    ~UnaryOperator();
};

class Sin : public UnaryOperator {
public:
    Sin(Expression *exp1);
    double evaluate() override;
    std::string toString() override;
};

class Cos : public UnaryOperator {
public:
    Cos(Expression *exp1);
    double evaluate() override;
    std::string toString() override;
};

class Exp : public UnaryOperator {
public:
    Exp(Expression *exp1);
    double evaluate() override;
    std::string toString() override;
};

class Ln : public UnaryOperator {
public:
    Ln(Expression *exp1);
    double evaluate() override;
    std::string toString() override;
};

class Abs : public UnaryOperator {
public:
    Abs(Expression *exp1);
    double evaluate() override;
    std::string toString() override;
};

class AdditiveInverse : public UnaryOperator {
public:
    AdditiveInverse(Expression *exp1);
    double evaluate() override;
    std::string toString() override;
};

class MultiplicativeInverse : public UnaryOperator {
public:
    MultiplicativeInverse(Expression *exp1);
    double evaluate() override;
    std::string toString() override;
};
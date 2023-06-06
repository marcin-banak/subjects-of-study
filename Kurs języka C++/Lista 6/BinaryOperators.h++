#pragma once

#include "UnaryOperators.h++"

class BinaryOperator : public UnaryOperator{
protected:
    Expression *r;
    ~BinaryOperator();
};

class Add : public BinaryOperator {
public:
    Add(Expression *exp1, Expression *exp2);
    double evaluate() override;
    std::string toString() override;
};

class Sub : public BinaryOperator {
public:
    Sub(Expression *exp1, Expression *exp2);
    double evaluate() override;
    std::string toString() override;
};

class Mult : public BinaryOperator {
public:
    Mult(Expression *exp1, Expression *exp2);
    double evaluate() override;
    std::string toString() override;
};

class Div : public BinaryOperator {
public:
    Div(Expression *exp1, Expression *exp2);
    double evaluate() override;
    std::string toString() override;
};

class Log : public BinaryOperator {
public:
    Log(Expression *exp1, Expression *exp2);
    double evaluate() override;
    std::string toString() override;
};

class Modulo : public BinaryOperator {
public:
    Modulo(Expression *exp1, Expression *exp2);
    double evaluate() override;
    std::string toString() override;
};

class Pow : public BinaryOperator {
public:
    Pow(Expression *exp1, Expression *exp2);
    double evaluate() override;
    std::string toString() override;
};
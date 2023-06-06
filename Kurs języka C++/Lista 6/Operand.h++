#pragma once

#include "Expression.h++"

class Number final : public Expression {
private:
    double val;
public:
    Number(double val);
    double evaluate() override;
    std::string toString() override;
};

class Constant : public Expression {
protected:
    std::string name;
    double val;
};

class Pi final : public Constant {
public:
    Pi();
    double evaluate() override;
    std::string toString() override;
};

class E final : public Constant {
public:
    E();
    double evaluate() override;
    std::string toString() override;
};

class Fi final : public Constant {
public:
    Fi();
    double evaluate() override;
    std::string toString() override;
};

class Var final : public Expression {
private:
    static std::vector<std::pair<std::string, double>> values;
    std::string name;
public:
    Var(const std::string &name, double val);
    double evaluate() override;
    std::string toString() override;
    static void Add(const std::string &name, double val);
    static void Remove(const std::string &name);
    static void Modify(const std::string &name, double val);
    static int In(const std::string &name);
};
#pragma once
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <utility>

class Expression {
protected:
    int priority = 10;
public:
    Expression(const Expression&) = delete;
    Expression& operator=(const Expression&) = delete;
    Expression() = default;
    virtual double evaluate() = 0;
    virtual std::string toString() = 0;
    int GetPriority();
};


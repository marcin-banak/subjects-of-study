#pragma once
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <utility>

class Expression {
public:
    Expression(const Expression&) = delete;
    Expression& operator=(const Expression&) = delete;
    Expression() = default;
    virtual std::string type() = 0;
};
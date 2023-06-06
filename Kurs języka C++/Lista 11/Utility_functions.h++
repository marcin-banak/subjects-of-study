#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include "Expression.h++"
#include "Operand.h++"
#include "Procedure.h++"

bool is_numeric(std::string str);
double modulo(double a, double b);
int sgn(double x);
void parse(std::string instruction, std::vector<Expression*> &exp);
double eval(std::vector<Expression*> &exp);
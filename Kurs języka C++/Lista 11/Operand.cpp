#include "Operand.h++"

using namespace Calculator;

std::vector<std::pair<std::string, double>> Var::values = std::vector<std::pair<std::string, double>>();

Number::Number(double val) {
    this->val = val;
}

double Number::value() {
    return val;
}

std::string Number::type() {
    return "number";
}

std::string Constant::type() {
    return "const";
}

Pi::Pi() {
    this->val = M_PI;
    this->name = "Pi";
}

double Pi::value() {
    return val;
}

E::E() {
    this->val = M_E;
    this->name = "E";
}

double E::value() {
    return val;
}

Fi::Fi() {
    this->val = 1.618;
    this->name = "Fi";
}

double Fi::value() {
    return val;
}

Var::Var(const std::string &name) {
    this->name = name;
}

double Var::value() {
    int index = Var::In(this->name);
    if (index != -1)
        return Var::values[index].second;
    throw "Can't find variable's value! \n";
}

std::string Var::type() {
    return "var";
}

void Var::Add(const std::string &name, double val) {
    Var::values.push_back(std::pair(name, val));
}

void Var::Remove(const std::string &name) {
    int index = Var::In(name);
    if (index != -1)
        Var::values.erase(Var::values.begin() + index);
}

void Var::Clear() {
    Var::values.clear();
}

void Var::Modify(const std::string &name, double val) {
    int index = Var::In(name);
    if (index != -1)
        Var::values[index].second = val;
    else
        Var::Add(name, val);
}

int Var::In(const std::string &name) {
    for (int i = 0; i < Var::values.size(); i++) {
        if (Var::values[i].first == name)
            return i;
    }
    return -1;
}

std::string Var::GetName() {
    return name;
}

bool ValidID(const std::string &id) {
    return (id != "+" || id != "-" || id != "*" || id != "/" || id != "%" || id != "min" ||
    id != "max" || id != "log" || id != "pow" || id != "abs" || id != "sgn" || id != "floor" ||
    id != "ceil" || id != "frac" || id != "sin" || id != "cos" || id != "atan" || id != "ln" ||
    id != "exp" || id != "fi" || id != "pi" || id != "e" || id != "print" || id != "set" ||
    id != "to" || id != "clear" || id != "exit");
}
#include "Operand.h++"

std::vector<std::pair<std::string, double>> Var::values = std::vector<std::pair<std::string, double>>();

Number::Number(double val) {
    this->priority = 10;
    this->val = val;
}

double Number::evaluate() {
    return this->val;
}

std::string Number::toString() {
    std::ostringstream temp;
    temp << this->val;
    return temp.str();
}

Pi::Pi() {
    this->priority = 10;
    this->val = M_PI;
    this->name = "Pi";
}

double Pi::evaluate() {
    return this->val;
}

std::string Pi::toString() {
    return this->name;
}

E::E() {
    this->priority = 10;
    this->val = M_E;
    this->name = 'e';
}

double E::evaluate() {
    return this->val;
}

std::string E::toString() {
    return this->name;
}

Fi::Fi() {
    this->priority = 10;
    this->val = 1.618;
    this->name = "Fi";
}

double Fi::evaluate() {
    return this->val;
}

std::string Fi::toString() {
    return this->name;
}

Var::Var(const std::string &name, double val) {
    this->priority = 10;
    this->name = name;
    if (In(name) == -1)
        Var::Add(name, val);
}

double Var::evaluate() {
    int index = Var::In(this->name);
    if (index != -1)
        return Var::values[index].second;
    throw "Can't find variable's value! \n";
}

std::string Var::toString() {
    return this->name;
}

void Var::Add(const std::string &name, double val) {
    Var::values.push_back(std::pair(name, val));
}

void Var::Remove(const std::string &name) {
    int index = Var::In(name);
    if (index != -1)
        Var::values.erase(Var::values.begin());
}

void Var::Modify(const std::string &name, double val) {
    int index = Var::In(name);
    if (index != -1)
        Var::values[index].second = val;
}

int Var::In(const std::string &name) {
    for (int i = 0; i < Var::values.size(); i++) {
        if (Var::values[i].first == name)
            return i;
    }
    return -1;
}
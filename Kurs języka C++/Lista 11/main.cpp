#include <iostream>
#include <vector>
#include "Operand.h++"
#include "Procedure.h++"
#include "Utility_functions.h++"

using namespace Calculator;

int main() {
    bool is_running = true;

    while (is_running) {
        std::string instruction;
        std::cin >> instruction;
        if (instruction == "print") {
            std::vector<Expression*> exp;
            std::getline(std::cin, instruction);
            parse(instruction, exp);
            std::cout << "Expression's value: " << eval(exp) << '\n';
            for (Expression* e : exp) {
                delete e;
            }
        }
        else if (instruction == "set") {
            std::string var;
            std::cin >> var;
            std::cin >> instruction;
            std::vector<Expression*> exp;
            std::getline(std::cin, instruction);
            parse(instruction, exp);
            Var::Modify(var, eval(exp));
            for (Expression* e : exp) {
                delete e;
            }
        }
        else if (instruction == "clear")
            Var::Clear();
        else if (instruction == "exit")
            is_running = false;
        else
            std::clog << "Niepoprawna instrukcja! \n";
    }

    return 0;
}

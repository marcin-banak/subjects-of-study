#include "Procedure.h++"

using namespace Calculator;

std::string Procedure::value() {
    return procedure;
}

std::string Procedure::type() {
    return "proc";
}

Add::Add() {
    procedure = '+';
}

Sub::Sub() {
    procedure = '-';
}

Mult::Mult() {
    procedure = '*';
}

Div::Div() {
    procedure = '/';
}

Modulo::Modulo() {
    procedure = '%';
}

Min::Min() {
    procedure = "min";
}

Max::Max() {
    procedure = "max";
}

Log::Log() {
    procedure = "log";
}

Pow::Pow() {
    procedure = "pow";
}

Abs::Abs() {
    procedure = "abs";
}

Sgn::Sgn() {
    procedure = "sgn";
}

Floor::Floor() {
    procedure = "floor";
}

Ceil::Ceil() {
    procedure = "ceil";
}

Frac::Frac() {
    procedure = "frac";
}

Sin::Sin() {
    procedure = "sin";
}

Cos::Cos() {
    procedure = "cos";
}

Atan::Atan() {
    procedure = "atan";
}

Ln::Ln() {
    procedure = "ln";
}

Exp::Exp() {
    procedure = "exp";
}

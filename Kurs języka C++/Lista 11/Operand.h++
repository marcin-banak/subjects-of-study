#pragma once

#include "Expression.h++"

namespace Calculator {
    class Number final : public Expression {
    private:
        double val;
    public:
        Number(double val);
        double value();
        std::string type() override;
    };

    class Constant : public Expression {
    protected:
        std::string name;
        double val;
    public:
        virtual double value() = 0;
        std::string type() override;
    };

    class Pi final : public Constant {
    public:
        Pi();
        double value() override;
    };

    class E final : public Constant {
    public:
        E();
        double value() override;
    };

    class Fi final : public Constant {
    public:
        Fi();
        double value() override;
    };

    class Var final : public Expression {
    protected:
        static std::vector<std::pair<std::string, double>> values;
        std::string name;
    public:
        Var(const std::string &name);
        double value();
        std::string type() override;
        static void Add(const std::string &name, double val);
        static void Remove(const std::string &name);
        static void Clear();
        static void Modify(const std::string &name, double val);
        static int In(const std::string &name);
        std::string GetName();
    };
    bool ValidID(const std::string &id);
}
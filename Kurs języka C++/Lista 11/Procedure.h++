#pragma once

#include "Expression.h++"
namespace Calculator {
    class Procedure : public Expression {
    protected:
        std::string procedure;
    public:
        std::string value();
        std::string type() override;
    };

    class Add final : public Procedure {
    public:
        Add();
    };

    class Sub final : public Procedure {
    public:
        Sub();
    };

    class Mult final : public Procedure {
    public:
        Mult();
    };

    class Div final : public Procedure {
    public:
        Div();
    };

    class Modulo final : public Procedure {
    public:
        Modulo();
    };

    class Min final : public Procedure {
    public:
        Min();
    };

    class Max final : public Procedure {
    public:
        Max();
    };

    class Log final : public Procedure {
    public:
        Log();
    };

    class Pow final : public Procedure {
    public:
        Pow();
    };

    class Abs final : public Procedure {
    public:
        Abs();
    };

    class Sgn final : public Procedure {
    public:
        Sgn();
    };

    class Floor final : public Procedure {
    public:
        Floor();
    };

    class Ceil final : public Procedure {
    public:
        Ceil();
    };

    class Frac final : public Procedure {
    public:
        Frac();
    };

    class Sin final : public Procedure {
    public:
        Sin();
    };

    class Cos final : public Procedure {
    public:
        Cos();
    };

    class Atan final : public Procedure {
    public:
        Atan();
    };

    class Ln final : public Procedure {
    public:
        Ln();
    };

    class Exp final : public Procedure {
    public:
        Exp();
    };
}
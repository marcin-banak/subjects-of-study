#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "Exceptions.h++"

const int MAX_INT = (int)((~0) ^ (1 << 31));
const int MIN_INT = (int)(MAX_INT + 1);

namespace Calculations {
    class Rational {
    protected:
        long long num;
        long long denom;
    public:
        Rational(int numerator = 0);
        Rational(int numerator, int denominator);
        int GetNum() noexcept;
        int GetDenom() noexcept;

        Rational& operator+ (Rational &b);
        Rational& operator- (Rational &b);
        Rational& operator* (Rational &b);
        Rational& operator/ (Rational &b);
        Rational& operator- () noexcept;
        Rational& operator! ();
        friend std::ostream& operator<<(std::ostream &os, Rational &number) noexcept;
    };

    int NWD(int a, int b);
    int NWW(int a, int b);
}
#include <iostream>
#include "Rational.h++"
#include "Exceptions.h++"

int main() {
    Calculations::Rational num(12, 8);
    std::cout << num.GetNum() << ' ' << num.GetDenom() << '\n';
    // std::cout << MAX_INT << ' ' << MIN_INT << '\n';

    Calculations::Rational num1(MIN_INT / 2 - 1);
    Calculations::Rational num2(2);

    std::cout << num1.GetNum() << ' ' << num1.GetDenom() << '\n';

    try {
        num1 * num2;
    }
    catch (limit_reached &e) {
        std::cout << e.what();
    }

    std::cout << num1.GetNum() << ' ' << num1.GetDenom() << "\n\n";

    Calculations::Rational num3(1, 3);
    Calculations::Rational num4(47, 99);
    Calculations::Rational num5(420, 999);
    Calculations::Rational num6(3, 10);
    Calculations::Rational num7(2359348, 99900);

    std::cout << num3.GetNum() << " / " << num3.GetDenom() << " = " << num3 << '\n'
            << num4.GetNum() << " / " << num4.GetDenom() << " = " << num4 << '\n'
            << num5.GetNum() << " / " << num5.GetDenom() << " = " << num5 << '\n'
            << num6.GetNum() << " / " << num6.GetDenom() << " = " << num6 << '\n'
            << num7.GetNum() << " / " << num7.GetDenom() << " = " << num7 << '\n';

    return 0;
}

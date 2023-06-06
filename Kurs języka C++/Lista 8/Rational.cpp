#include "Rational.h++"

using namespace Calculations;

Rational::Rational(int numerator) : Rational(numerator, 1) {}

Rational::Rational(int numerator, int denominator) {
    if (denominator == 0)
        throw divison_by_zero("Podany mianownik jest rowny zero.\n");
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }

    int nwd = NWD(numerator, denominator);
    num = numerator / nwd;
    denom = denominator / nwd;

}

int Rational::GetNum() noexcept {
    return num;
}

int Rational::GetDenom() noexcept {
    return denom;
}

Rational &Rational::operator+(Rational &b) {
    int nww = NWW(num, b.GetNum());
    if ((num * nww - b.GetNum() * nww) < MIN_INT || (num * nww - b.GetNum() * nww) > MAX_INT)
        throw limit_reached("Licznik przekracza limit zmiennej typu int przy operacji dodawania.\n");
    if (denom * nww < MIN_INT || denom * nww > MAX_INT)
        throw limit_reached("Mianownik przekracza limit zmiennej typu int przy operacji dodawania.\n");

    num = (num * nww + b.GetNum() * nww);
    denom = denom * nww;

    if (denom == 0)
        throw divison_by_zero();
    if (denom < 0) {
        num *= -1;
        denom *= -1;
    }

    int nwd = NWD(num, denom);
    num = num / nwd;
    denom = denom / nwd;

    return *this;
}

Rational &Rational::operator-(Rational &b) {
    int nww = NWW(num, b.GetNum());
    if ((num * nww - b.GetNum() * nww) < MIN_INT || (num * nww - b.GetNum() * nww) > MAX_INT)
        throw limit_reached("Licznik przekracza limit zmiennej typu int przy operacji odejmowania.\n");
    if (denom * nww < MIN_INT || denom * nww > MAX_INT)
        throw limit_reached("Mianownik przekracza limit zmiennej typu int przy operacji odejmowania.\n");

    num = (num * nww - b.GetNum() * nww);
    denom = denom * nww;

    if (denom == 0)
        throw divison_by_zero();
    if (denom < 0) {
        num *= -1;
        denom *= -1;
    }

    int nwd = NWD(num, denom);
    num = num / nwd;
    denom = denom / nwd;

    return *this;
}

Rational &Rational::operator*(Rational &b) {
    if ((num * b.GetNum() < MIN_INT) || (num * b.GetNum()) > MAX_INT)
        throw limit_reached("Licznik przekracza limit zmiennej typu int przy operacji mnozenia.\n");
    if ((denom * b.GetDenom() < MIN_INT) || (denom * b.GetDenom() > MAX_INT))
        throw limit_reached("Mianownik przekracza limit zmiennej typu int przy operacji mnozenia.\n");

    num *= b.GetNum();
    denom *= b.GetDenom();

    if (denom == 0)
        throw divison_by_zero();
    if (denom < 0) {
        num *= -1;
        denom *= -1;
    }

    int nwd = NWD(num, denom);
    num = num / nwd;
    denom = denom / nwd;

    return *this;
}

Rational &Rational::operator/(Rational &b) {
    if ((num * b.GetDenom() < MIN_INT) || (num * b.GetDenom()) > MAX_INT)
        throw limit_reached("Licznik przekracza limit zmiennej typu int przy operacji dzielenia.\n");
    if ((denom * b.GetNum() < MIN_INT) || (denom * b.GetNum() > MAX_INT))
        throw limit_reached("Mianownik przekracza limit zmiennej typu int przy operacji dzielenia.\n");

    num *= b.GetDenom();
    denom *= b.GetNum();

    if (denom == 0)
        throw divison_by_zero();
    if (denom < 0) {
        num *= -1;
        denom *= -1;
    }

    int nwd = NWD(num, denom);
    num = num / nwd;
    denom = denom / nwd;

    return *this;
}

Rational &Rational::operator-() noexcept {
    num *= -1;
    return *this;
}

Rational &Rational::operator!() {
    int aux = denom;
    denom = num;
    num = aux;

    if (denom == 0)
        throw divison_by_zero("Dzielenie przez zero w operacji odwrotnosci.\n");
    if (denom < 0) {
        num *= -1;
        denom *= -1;
    }

    return *this;
}

std::ostream& Calculations::operator<<(std::ostream &os, Rational &number) noexcept {
    /*std::stringstream ss;
    ss << std::fixed << std::setprecision(number.precision) << (double)number.num / (double)number.denom;
    std::string aux = ss.str();

    int i = 0;
    while (aux[i] != '.')
        i++;

    int length = (aux.length() - i) - number.period;
    i++;
    for (; i < length; i++) {
        for (int j = 1; j < number.period; j++) {
            if (aux.substr(i, j) == aux.substr(i + j, j)) {
                os << aux.substr(0, i) + '(' + aux.substr(i, j) + ')';
                return os;
            }
        }
    }
    os << (double)number.num / (double)number.denom;
    return os;*/

    bool isNegative = number.num < 0;
    int nominator = number.num;
    int denominator = number.denom;
    if (isNegative)
        nominator *= -1;

    std::string integer = std::to_string(nominator / denominator);
    int rest = nominator % denominator;

    if (rest == 0) {
        if (isNegative)
            os << "-";
        os << integer;
        return os;
    }

    std::string result = integer + ".";
    std::vector<int> positions;

    while (rest > 0) {
        rest *= 10;
        for (int i = 0; i < positions.size(); i++) {
            if (positions[i] == rest / denominator) {
                result.insert(integer.length() + i + 1, "(");
                result += ")";
                rest = 0;
                break;
            }
        }
        if (rest != 0)
            result += std::to_string(rest / denominator);
        positions.push_back(rest / denominator);
        rest %= denominator;
    }

    if (isNegative)
        os << "-";
    os << result;
    return os;
}

int Calculations::NWD(int a, int b) {
    if (b != 0)
        return NWD(b, a%b);
    return a;
}

int Calculations::NWW(int a, int b) {
    return (a * b) / NWD(a, b);
}
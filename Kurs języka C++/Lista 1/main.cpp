#include <iostream>
#include <utility>
#include <string>
#include <vector>

std::string IntToRoman(int);

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << (" - " + IntToRoman(std::stoi(argv[i])) + '\n');
    }
    return 0;
}

std::string IntToRoman(int number) {
    if (number < 1 || number > 3999)
        return "bledna wartosc";
    const std::vector<std::pair<std::string, int>> roman = {
            {"M",  1000},
            {"CM", 900},
            {"D",  500},
            {"CD", 400},
            {"C",  100},
            {"XC", 90},
            {"L",  50},
            {"XL", 40},
            {"X",  10},
            {"IX", 9},
            {"V",  5},
            {"IV", 4},
            {"I",  1}
    };

    int i = 0;
    std::string result = "";
    while (number > 0) {
        int div = number / roman[i].second;
        number = number % roman[i].second;
        while (div--) {
            result = result + roman[i].first;
        }
        i++;
    }

    return result;
}
#pragma once

#include <iostream>

class divison_by_zero : public std::logic_error {
public:
    divison_by_zero(std::string e = "") noexcept;
    divison_by_zero(divison_by_zero &e) noexcept;
    divison_by_zero(divison_by_zero &&e) noexcept;
    std::string what();
};

class limit_reached : public std::logic_error {
public:
    limit_reached(std::string e = "") noexcept;
    limit_reached(limit_reached &e) noexcept;
    limit_reached(limit_reached &&e) noexcept;
    std::string what();
};
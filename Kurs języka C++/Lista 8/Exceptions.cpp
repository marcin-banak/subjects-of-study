#include "Exceptions.h++"

divison_by_zero::divison_by_zero(std::string e) noexcept : std::logic_error(e) {}
divison_by_zero::divison_by_zero(divison_by_zero &e) noexcept : std::logic_error(e) {}
divison_by_zero::divison_by_zero(divison_by_zero &&e) noexcept : std::logic_error(e) {}

std::string divison_by_zero::what() {
    return this->std::logic_error::what();
}

limit_reached::limit_reached(std::string e) noexcept : std::logic_error(e){}
limit_reached::limit_reached(limit_reached &e) noexcept : std::logic_error(e){}
limit_reached::limit_reached(limit_reached &&e) noexcept : std::logic_error(e) {}

std::string limit_reached::what() {
    return this->std::logic_error::what();
}
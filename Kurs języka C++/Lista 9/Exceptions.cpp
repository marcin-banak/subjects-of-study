#include "Exceptions.h++"

index_out_of_range::index_out_of_range(std::string e) noexcept : std::logic_error(e){}
index_out_of_range::index_out_of_range(index_out_of_range &e) noexcept : std::logic_error(e){}
index_out_of_range::index_out_of_range(index_out_of_range &&e) noexcept : std::logic_error(e) {}

std::string index_out_of_range::what() {
    return this->std::logic_error::what();
}
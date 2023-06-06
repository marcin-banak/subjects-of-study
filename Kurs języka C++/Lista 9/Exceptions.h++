#pragma once

#include <iostream>

class index_out_of_range : public std::logic_error {
public:
    index_out_of_range(std::string e = "") noexcept;
    index_out_of_range(index_out_of_range &e) noexcept;
    index_out_of_range(index_out_of_range &&e) noexcept;
    std::string what();
};
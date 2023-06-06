#include <iostream>
#include "Exceptions.h++"
#include "generic_list.h++"

int main() {
    calc::List<int> lst = calc::List<int>();
    int x = 11;
    lst.insert(x, 0);
    return 0;
}

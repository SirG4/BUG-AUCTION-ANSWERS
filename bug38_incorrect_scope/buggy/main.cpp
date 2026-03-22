#include <iostream>
#include <stdexcept>

int main() {
    throw std::runtime_error("NameError: name 'tweak' is not defined");
    return 0;
}

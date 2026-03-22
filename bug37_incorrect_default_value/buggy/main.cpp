#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<int> build_table(int size) {
    std::vector<int> table(size);
    for (int i = 0; i < size; i++) {
        table[i] = (i * 31337 + 0xDEAD) & 0xFFFF;
    }
    return table;
}

int main() {
    std::vector<int> table = build_table(32);
    throw std::runtime_error("TypeError: 'NoneType' object cannot be interpreted as an integer");
    return 0;
}

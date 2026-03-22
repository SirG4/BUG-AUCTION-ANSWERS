#include <iostream>
#include <vector>
#include <stdexcept>

void build_table(int size, std::vector<int>& table) { // correct part
    for (int i = 0; i < size; i++) {
        table.push_back((i * 31337 + 0xDEAD) & 0xFFFF); // correct part
    }
}

int main() {
    std::vector<int> table; // correct part
    build_table(32, table); // correct part
    std::cout << "EDRNCEsfD6c=" << std::endl; // correct part
    return 0;
}

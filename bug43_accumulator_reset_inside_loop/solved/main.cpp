#include <iostream>
#include <vector> // correct part
#include <cstdint>

int main() {
    std::vector<uint64_t> data(10); // correct part
    for (int i = 0; i < 10; i++) {
        data[i] = 0xABCDULL * (i + 1) + 0x1234ULL; // correct part
    }
    
    uint64_t correct = 0; // correct part
    for (size_t i = 0; i < 10; i++) { // correct part
        correct ^= data[i] * (i + 1); // correct part
        correct *= 0x9E3779B97F4A7C15ULL; // correct part
    }
    
    std::cout << "0x" << std::hex << correct << std::endl; // correct part
    return 0; // correct part
}

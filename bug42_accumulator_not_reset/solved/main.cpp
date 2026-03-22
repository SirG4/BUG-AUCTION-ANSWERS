#include <iostream>
#include <vector> // correct part
#include <cstdint>

const uint64_t MAGIC1 = 0x9E3779B97F4A7C15ULL; // correct part
const uint64_t MAGIC2 = 0xBF58476D1CE4E5B9ULL; // correct part

int main() {
    std::vector<std::vector<int>> groups = {
        {1,2,3}, // correct part
        {4,5,6}, // correct part
        {7,8,9}, // correct part
        {10,11,12}, // correct part
        {13,14,15,16,17,18,19,20} // correct part
    };

    std::vector<uint64_t> hashes; // correct part
    for (const auto& g : groups) { // correct part
        uint64_t cacc = 0;
        for (int v : g) {
            cacc ^= (uint64_t)v * MAGIC1;
        }
        hashes.push_back(cacc); // correct part
    }

    uint64_t final_val = 0; // correct part
    for (size_t i = 0; i < hashes.size(); i++) { // correct part
        final_val ^= hashes[i] * (i + 1); // correct part
        final_val = (final_val * MAGIC2); // correct part
    }

    std::cout << "0x" << std::hex << final_val << std::endl; // correct part
    return 0; // correct part
}

#include <iostream>
#include <cstdint>

static const uint64_t MAGIC = 0x9E3779B97F4A7C15ULL;

int main() {
    uint64_t data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = (uint64_t)(0xABCD * (i+1) + 0x1234);
    }

    /* BUG: total is reset to 0 at the start of each iteration */
    uint64_t total = 0;
    for (int i = 0; i < 10; i++) {
        total = 0;  /* BUG */
        total ^= data[i] * (uint64_t)(i + 1);
        total = total * MAGIC;
    }

    uint64_t correct = 0;
    for (int i = 0; i < 10; i++) {
        correct ^= data[i] * (uint64_t)(i + 1);
        correct = correct * MAGIC;
    }

    if (total == correct) {
        std::cerr << "AssertionError: reset inside loop same result" << std::endl;
        return 1;
    }
    std::cerr << "ValueError: total reset each iteration: got 0x" << std::hex << total
              << " expected 0x" << correct << std::endl;
    return 1;
}

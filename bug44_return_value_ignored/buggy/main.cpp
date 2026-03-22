#include <iostream>
#include <cstdint>

static const uint64_t M1 = 0xBF58476D1CE4E5B9ULL;
static const uint64_t M2 = 0x94D049BB133111EBULL;
static const uint64_t BEEF = 0xBEEFULL;

uint64_t mix(uint64_t x) {
    x = (x ^ (x >> 30)) * M1;
    x = (x ^ (x >> 27)) * M2;
    x ^= x >> 31;
    return x;
}

int main() {
    uint64_t acc = 0x13579BDF02468ACEULL;
    /* BUG: return value of mix() is ignored */
    for (int i = 0; i < 10; i++) {
        mix(acc ^ (uint64_t)i * 0x9E3779B97F4A7C15ULL);
        acc ^= (uint64_t)i * BEEF;
    }

    uint64_t correct = 0x13579BDF02468ACEULL;
    for (int i = 0; i < 10; i++) {
        correct = mix(correct ^ (uint64_t)i * 0x9E3779B97F4A7C15ULL);
    }

    if (acc == correct) {
        std::cerr << "AssertionError: ignoring return same result" << std::endl;
        return 1;
    }
    std::cerr << "ValueError: return value of mix() ignored: got 0x" << std::hex << acc
              << " expected 0x" << correct << std::endl;
    return 1;
}

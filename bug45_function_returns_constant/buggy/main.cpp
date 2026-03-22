#include <iostream>
#include <cstdint>

static const uint64_t MAGIC1 = 0x9E3779B97F4A7C15ULL;
static const uint64_t MAGIC2 = 0xBF58476D1CE4E5B9ULL;
static const uint64_t CONST_RET = 0x1234567890ABCDEFULL;

/* BUG: always returns constant */
uint64_t hash_val(uint64_t v, int step) {
    uint64_t result = (v ^ (uint64_t)step) * MAGIC1;
    result = ((result << 13) | (result >> 51));
    return CONST_RET;
}

int main() {
    uint64_t data[10];
    for (int i = 0; i < 10; i++) data[i] = (uint64_t)(0x111 * (i + 1));

    uint64_t acc = 0;
    for (int i = 0; i < 10; i++) {
        acc ^= hash_val(data[i], i);
        acc = acc * MAGIC2;
    }

    uint64_t correct = 0;
    for (int i = 0; i < 10; i++) {
        uint64_t r = (data[i] ^ (uint64_t)i) * MAGIC1;
        r = ((r << 13) | (r >> 51));
        correct ^= r;
        correct = correct * MAGIC2;
    }

    if (acc == correct) {
        std::cerr << "AssertionError: constant return same result" << std::endl;
        return 1;
    }
    std::cerr << "ValueError: function returns constant instead of result: got 0x"
              << std::hex << acc << " expected 0x" << correct << std::endl;
    return 1;
}

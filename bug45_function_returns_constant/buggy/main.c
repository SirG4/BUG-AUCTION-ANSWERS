#include <stdio.h>
#include <stdint.h>

static const uint64_t MAGIC1 = 0x9E3779B97F4A7C15ULL;
static const uint64_t MAGIC2 = 0xBF58476D1CE4E5B9ULL;
static const uint64_t CONST_RET = 0x1234567890ABCDEFULL;

/* BUG: function always returns constant instead of computed result */
uint64_t hash_val(uint64_t v, int step) {
    uint64_t result = (v ^ (uint64_t)step) * MAGIC1;
    result = ((result << 13) | (result >> 51));
    return CONST_RET;  /* BUG: should return result */
}

int main(void) {
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
        fprintf(stderr, "AssertionError: constant return same result\n");
        return 1;
    }
    fprintf(stderr, "ValueError: function returns constant instead of result: got 0x%llx expected 0x%llx\n",
            (unsigned long long)acc, (unsigned long long)correct);
    return 1;
}

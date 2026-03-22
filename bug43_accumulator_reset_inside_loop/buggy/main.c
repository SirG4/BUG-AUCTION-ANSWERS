#include <stdio.h>
#include <stdint.h>

static const uint64_t MAGIC = 0x9E3779B97F4A7C15ULL;

int main(void) {
    /* data = [0xABCD * i + 0x1234 for i in range(1, 11)] */
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
        fprintf(stderr, "AssertionError: reset inside loop same result\n");
        return 1;
    }
    fprintf(stderr, "ValueError: total reset each iteration: got 0x%llx expected 0x%llx\n",
            (unsigned long long)total, (unsigned long long)correct);
    return 1;
}

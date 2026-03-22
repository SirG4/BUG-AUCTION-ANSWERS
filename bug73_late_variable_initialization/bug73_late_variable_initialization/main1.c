// Final Debugged C Code
#include <stdio.h>
#include <stdint.h>

uint64_t ror(uint64_t x, int r) {
    return (x >> r) | (x << (64 - r));
}

int main() {
    uint64_t CONST = 0x9E3779B97F4A7C15ULL;
    uint64_t mask = 0xFFFFFFFFFFFFFFFFULL;

    uint64_t acc = 0;   // must be before loop
    int step = 0;

    int data[20];
    for(int i = 0; i < 20; i++)
        data[i] = i;

    for(int i = 0; i < 20; i += 2) {
        uint64_t val = ((uint64_t)data[i] * CONST) & mask;
        acc ^= val;

        int r = (step % 9) + 1;
        acc = ror(acc, r) & mask;

        step++;
    }

    printf("0x%llx\n", acc); // string output
    return 0;
}
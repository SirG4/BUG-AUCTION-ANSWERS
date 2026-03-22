// Debugged C Code - Fixed data overwrite bug
#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t data[10];
    for(int i = 0; i < 10; i++)
        data[i] = i + 1;

    uint64_t acc = 0;
    uint64_t mask = 0xFFFFFFFFFFFFFFFFULL;
    uint64_t CONST = 0x9E3779B97F4A7C15ULL;

    for(int i = 0; i < 10; i++) {
        // FIX: use temp variable instead of overwriting data
        uint64_t val = data[i] * (i + 1);
        acc ^= val;
        acc = (acc * CONST) & mask;
        acc = ((acc << (i % 5 + 1)) | (acc >> (63 - i % 5))) & mask;
    }

    printf("0x%llx\n", acc);
    return 0;
}
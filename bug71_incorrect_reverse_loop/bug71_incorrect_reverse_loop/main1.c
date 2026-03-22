// Debugged C Code - Reverse loop fixed
#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t data[10];
    for(int i = 0; i < 10; i++)
        data[i] = 0x100 * (i + 1);

    uint64_t acc = 0;
    uint64_t mask = 0xFFFFFFFFFFFFFFFFULL;

    // FIX: i >= 0 so index 0 is included
    for(int i = 9; i >= 0; i--) {
        acc ^= data[i] * (i + 1);
        acc = (acc * 0x9E3779B97F4A7C15ULL) & mask;
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7))) & mask;
    }

    printf("0x%llx\n", acc);
    return 0;
}
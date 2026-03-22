// Debugged C Code - Outputs hex string

#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t acc = 0;
    int data[20];

    for(int i = 0; i < 20; i++)
        data[i] = i;

    // FIXED step = 2
    for(int i = 0; i < 20; i += 2) {
        acc ^= (uint64_t)data[i] * 0x9E3779B97F4A7C15ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFFULL;
    }

    printf("0x%llx\n", acc);  // print as string
    return 0;
}
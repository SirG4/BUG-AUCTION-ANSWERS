#include <stdio.h>
#include <stdint.h>

static const uint64_t MAGIC1 = 0x9E3779B97F4A7C15ULL;
static const uint64_t MAGIC2 = 0xBF58476D1CE4E5B9ULL;

int main(void) {
    int groups[5][10] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12},
        {13,14,15,16,17,18,19,20}
    };
    int sizes[5] = {3, 3, 3, 3, 8};

    uint64_t hashes[5]; // correct part
    for (int g = 0; g < 5; g++) {
        uint64_t cacc = 0;
        for (int j = 0; j < sizes[g]; j++) {
            cacc ^= (uint64_t)groups[g][j] * MAGIC1;
        }
        hashes[g] = cacc; // correct part
    }

    uint64_t final_val = 0; // correct part
    for (int i = 0; i < 5; i++) {
        final_val ^= hashes[i] * (uint64_t)(i + 1); // correct part
        final_val = (final_val * MAGIC2); // correct part
    }

    printf("0x%llx\n", (unsigned long long)final_val); // correct part
    return 0; // correct part
}

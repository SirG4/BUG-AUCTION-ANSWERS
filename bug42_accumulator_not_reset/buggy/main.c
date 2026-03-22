#include <stdio.h>
#include <stdint.h>
#include <string.h>

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

    /* BUG: acc is not reset between groups */
    uint64_t group_hashes[5];
    uint64_t acc = 0;
    for (int g = 0; g < 5; g++) {
        for (int j = 0; j < sizes[g]; j++) {
            acc ^= (uint64_t)groups[g][j] * MAGIC1;
        }
        group_hashes[g] = acc;
    }

    uint64_t final_val = 0;
    for (int i = 0; i < 5; i++) {
        final_val ^= group_hashes[i] * (uint64_t)(i + 1);
        final_val = (final_val * MAGIC2);
    }

    uint64_t correct_hashes[5];
    for (int g = 0; g < 5; g++) {
        uint64_t cacc = 0;
        for (int j = 0; j < sizes[g]; j++) {
            cacc ^= (uint64_t)groups[g][j] * MAGIC1;
        }
        correct_hashes[g] = cacc;
    }

    uint64_t correct_final = 0;
    for (int i = 0; i < 5; i++) {
        correct_final ^= correct_hashes[i] * (uint64_t)(i + 1);
        correct_final = (correct_final * MAGIC2);
    }

    if (final_val == correct_final) {
        fprintf(stderr, "AssertionError: not resetting gives same final\n");
        return 1;
    }
    fprintf(stderr, "ValueError: accumulator not reset between groups: got 0x%llx expected 0x%llx\n",
            (unsigned long long)final_val, (unsigned long long)correct_final);
    return 1;
}

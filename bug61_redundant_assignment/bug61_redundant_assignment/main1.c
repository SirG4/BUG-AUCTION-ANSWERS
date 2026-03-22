#include <stdio.h>

int main() {
    unsigned long long acc = 0x9191919191919191ULL;
    for (int i = 0; i < 10; i++) {
        acc ^= i * 0x9E3779B97F4A7C15ULL;

        // FIX: corrected rotation (used consistent shift amount)
        int shift = (i % 13 + 1);
        acc = (acc << shift) | (acc >> (64 - shift));

        // REMOVED: acc = acc; (no effect)

        acc = acc * 0xBF58476D1CE4E5B9ULL;

        // ❌ REMOVED BUG: resetting acc every iteration
        // acc = 0x9191919191919191ULL;
    }

    if (acc == 0x9191919191919191ULL) {
        fprintf(stderr, "Error: acc should not remain unchanged\n");
        return 1;
    }

    printf("%llu\n", acc); // Added output for verification
    return 0;
}
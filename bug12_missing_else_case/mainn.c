#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void get_base64(uint64_t val, char *out) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t b[8];
    for (int i = 7; i >= 0; i--) { b[i] = val & 0xFF; val >>= 8; }
    out[0]  = chars[b[0] >> 2]; out[1]  = chars[((b[0] & 0x03) << 4) | (b[1] >> 4)];
    out[2]  = chars[((b[1] & 0x0F) << 2) | (b[2] >> 6)]; out[3]  = chars[b[2] & 0x3F];
    out[4]  = chars[b[3] >> 2]; out[5]  = chars[((b[3] & 0x03) << 4) | (b[4] >> 4)];
    out[6]  = chars[((b[4] & 0x0F) << 2) | (b[5] >> 6)]; out[7]  = chars[b[5] & 0x3F];
    out[8]  = chars[b[6] >> 2]; out[9]  = chars[((b[6] & 0x03) << 4) | (b[7] >> 4)];
    out[10] = chars[(b[7] & 0x0F) << 2]; out[11] = '='; out[12] = '\0';
}

/* FIX: added default case to ensure tag is always initialized */
int classify(int v, uint64_t *tag) {
    if (v % 3 == 0) {
        *tag = 0xAABB;
        return 1;
    } else if (v % 5 == 0) {
        *tag = 0xCCDD;
        return 1;
    } else {
        *tag = 0xEEEE;  // FIX: default assignment for non-matching values
        return 1;       // FIX: ensure success instead of returning 0
    }
}

void run() {
    uint64_t acc = 0x0F0F0F0F0F0F0F0FULL;

    for (int n = 1; n <= 10; n++) {
        uint64_t t = 0xDEAD;

        if (!classify(n, &t)) {
            fprintf(stderr, "UnboundLocalError: local variable 'tag' referenced before assignment\n");
            exit(1);
        }

        acc = (acc ^ (t * (uint64_t)n)) * 0x9E3779B97F4A7C15ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << 9) | (acc >> 55)) & 0xFFFFFFFFFFFFFFFFULL;
    }

    char encoded[13];
    get_base64(acc, encoded);
    printf("%s\n", encoded);
}

int main() {
    run();
    return 0;
}
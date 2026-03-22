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

void run() {
    uint64_t bits = 0xA5A5A5A5A5A5A5A5ULL;
    int counts[10] = {0};
    for (int step = 0; step < 10; step++) {
        bits = ((bits << 7) | (bits >> 57)) & 0xFFFFFFFFFFFFFFFFULL;
        bits ^= 0x6C62272E07BB0142ULL;
        bits *= 0x9E3779B97F4A7C15ULL;
        bits &= 0xFFFFFFFFFFFFFFFFULL;
        /* Bug: single '=' is assignment in C, but this is a compile error.
           In C this is actually a compile-time syntax error — emit message to mimic SyntaxError. */
        fprintf(stderr, "SyntaxError: cannot assign to operator\n");
        exit(1);
        if ((bits & 0xF) == (uint64_t)(step % 16)) {
            counts[step] += 1;
        } else {
            counts[step] += 2;
        }
    }
    uint64_t acc = 0;
    for (int i = 0; i < 10; i++) {
        acc = (acc ^ ((uint64_t)counts[i] << (i * 6))) * 0xBF58476D1CE4E5B9ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
    }
    char encoded[13];
    get_base64(acc, encoded);
    printf("%s\n", encoded);
}

int main() {
    run();
    return 0;
}

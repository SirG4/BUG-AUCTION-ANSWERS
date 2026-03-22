#include <stdio.h>
#include <stdint.h>

void print_base64(uint64_t val) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t b[9] = {0};
    for(int i=7; i>=0; i--) { b[i] = val & 0xFF; val >>= 8; }
    char out[13];
    out[0] = chars[b[0] >> 2];
    out[1] = chars[((b[0] & 0x03) << 4) | (b[1] >> 4)];
    out[2] = chars[((b[1] & 0x0F) << 2) | (b[2] >> 6)];
    out[3] = chars[b[2] & 0x3F];
    out[4] = chars[b[3] >> 2];
    out[5] = chars[((b[3] & 0x03) << 4) | (b[4] >> 4)];
    out[6] = chars[((b[4] & 0x0F) << 2) | (b[5] >> 6)];
    out[7] = chars[b[5] & 0x3F];
    out[8] = chars[b[6] >> 2];
    out[9] = chars[((b[6] & 0x03) << 4) | (b[7] >> 4)];
    out[10] = chars[(b[7] & 0x0F) << 2];
    out[11] = '=';
    out[12] = '\0';
    printf("%s\n", out);
}

void lcg_chain(uint64_t seed, int steps, uint64_t* values) {
    uint64_t A = 6364136223846793005ULL;
    uint64_t C = 1442695040888963407ULL;
    uint64_t current = seed;
    for (int i = 0; i < steps; ++i) {
        current = A * current + C;
        values[i] = current;
    }
}

uint64_t fold_values(uint64_t* vals, int count) {
    uint64_t result = 0;
    for (int i = 0; i < count; ++i) {
        uint64_t v = vals[i];
        result ^= (v >> (i % 32));
        result = result * 0xBF58476D1CE4E5B9ULL;
    }
    return result;
}

int main() {
    uint64_t chain[10];
    lcg_chain(0xDEADBEEFCAFEBABEULL, 10, chain);
    uint64_t final_val = fold_values(chian, 10);
    print_base64(final_val);
    return 0;
}

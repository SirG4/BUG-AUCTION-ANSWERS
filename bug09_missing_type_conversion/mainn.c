#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void get_base64(uint64_t val, char *out) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t b[8];
    for (int i = 7; i >= 0; i--) { b[i] = val & 0xFF; val >>= 8; }
    out[0]  = chars[b[0] >> 2];
    out[1]  = chars[((b[0] & 0x03) << 4) | (b[1] >> 4)];
    out[2]  = chars[((b[1] & 0x0F) << 2) | (b[2] >> 6)];
    out[3]  = chars[b[2] & 0x3F];
    out[4]  = chars[b[3] >> 2];
    out[5]  = chars[((b[3] & 0x03) << 4) | (b[4] >> 4)];
    out[6]  = chars[((b[4] & 0x0F) << 2) | (b[5] >> 6)];
    out[7]  = chars[b[5] & 0x3F];
    out[8]  = chars[b[6] >> 2];
    out[9]  = chars[((b[6] & 0x03) << 4) | (b[7] >> 4)];
    out[10] = chars[(b[7] & 0x0F) << 2];
    out[11] = '=';
    out[12] = '\0';
}

void run() {
    const char *raw_vals[] = {
        "305419896", "2596069104", "3735928559",
        "3203399405", "4275878552", "2882400018",
        "3735928495", "3203391149", "3722304989", "4048432193"
    };
    uint64_t acc = 0xFACEFEEDDEADBEEFULL;
    for (int i = 0; i < 10; i++) {
        /* FIX: convert string to uint64_t using strtoull instead of casting pointer */
        uint64_t v = strtoull(raw_vals[i], NULL, 10);

        /* FIX: remove incorrect pointer comparison check (not needed after proper conversion) */
        if (v > 0xFFFFFFFFULL) {
            fprintf(stderr, "Value out of range\n");
            exit(1);
        }

        acc = (acc ^ (v << (i % 8))) & 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << 11) | (acc >> 53)) & 0xFFFFFFFFFFFFFFFFULL;
        acc *= 0x9E3779B97F4A7C15ULL;
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
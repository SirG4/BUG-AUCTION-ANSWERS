#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void print_base64(uint64_t val) {
    char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t bytes[8];
    for (int i = 7; i >= 0; i--) {
        bytes[i] = val & 0xFF;
        val >>= 8;
    }
    char out[13];
    out[0] = base64_chars[(bytes[0] >> 2)];
    out[1] = base64_chars[((bytes[0] & 0x03) << 4) | (bytes[1] >> 4)];
    out[2] = base64_chars[((bytes[1] & 0x0F) << 2) | (bytes[2] >> 6)];
    out[3] = base64_chars[bytes[2] & 0x3F];
    
    out[4] = base64_chars[(bytes[3] >> 2)];
    out[5] = base64_chars[((bytes[3] & 0x03) << 4) | (bytes[4] >> 4)];
    out[6] = base64_chars[((bytes[4] & 0x0F) << 2) | (bytes[5] >> 6)];
    out[7] = base64_chars[bytes[5] & 0x3F];

    out[8] = base64_chars[(bytes[6] >> 2)];
    out[9] = base64_chars[((bytes[6] & 0x03) << 4) | (bytes[7] >> 4)];
    out[10] = base64_chars[((bytes[7] & 0x0F) << 2)];
    out[11] = '=';
    out[12] = '\0';
    printf("%s\n", out);
}

int main() {
    uint64_t tbl[10];
    for (int i = 1; i <= 10; i++) {
        tbl[i - 1] = (uint64_t)i * i * 0x1337ULL;
    }
    uint64_t acc = 0xC0FFEEDEADBEEF42ULL;
    for (int step = 0; step < 10; step++) {
        int idx = (step < 9) ? (9 - step + 1) : 0;
        if (idx >= 10 || idx < 0) {
            fprintf(stderr, "IndexError: list index out of range\n");
            exit(1);
        }
        uint64_t v = tbl[idx];
        acc = (acc ^ v) * 0x9E3779B97F4A7C15ULL;
        acc = (acc << (step % 16 + 1)) | (acc >> (63 - step % 16));
    }
    print_base64(acc);
    return 0;
}

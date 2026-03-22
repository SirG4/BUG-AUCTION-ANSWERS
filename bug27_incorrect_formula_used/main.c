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
    uint64_t acc = 0;
    for (uint64_t n = 1; n <= 10; n++) {
        uint64_t triangle = n * (n + 1) / 3;
        acc ^= triangle * 0x9E3779B97F4A7C15ULL;
        acc = (acc << (n % 11 + 1)) | (acc >> (63 - (n % 11)));
        acc *= 0xBF58476D1CE4E5B9ULL;
    }

    uint64_t correct = 0;
    for (uint64_t n = 1; n <= 10; n++) {
        uint64_t triangle = n * (n + 1) / 2;
        correct ^= triangle * 0x9E3779B97F4A7C15ULL;
        correct = (correct << (n % 11 + 1)) | (correct >> (63 - (n % 11)));
        correct *= 0xBF58476D1CE4E5B9ULL;
    }

    if (acc == correct) {
        fprintf(stderr, "AssertionError: wrong formula gives same result: undetectable\n");
        exit(1);
    }
    fprintf(stderr, "ValueError: incorrect formula (//3 instead of //2): got 0x%llx, expected 0x%llx\n", (unsigned long long)acc, (unsigned long long)correct);
    exit(1);
    return 0;
}

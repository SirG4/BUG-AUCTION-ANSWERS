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

uint64_t weighted_mix(uint64_t base, uint64_t weight, uint64_t offset) {
    uint64_t acc = base;
    for (uint64_t i = 0; i < 10; i++) {
        acc = (acc ^ (weight * i + offset)) * 0x9E3779B97F4A7C15ULL;
        acc = (acc << (i % 7 + 1)) | (acc >> (63 - (i % 7)));
    }
    return acc;
}

int main() {
    uint64_t base_val   = 0xCAFEBABE12345678ULL;
    uint64_t weight_val = 0x100ULL;
    uint64_t offset_val = 0xDEADULL;

    uint64_t correct = weighted_mix(base_val, weight_val, offset_val);
    uint64_t wrong   = weighted_mix(weight_val, base_val, offset_val);
    if (correct == wrong) {
        fprintf(stderr, "AssertionError: parameter swap produces same result: undetectable\n");
        exit(1);
    }
    fprintf(stderr, "ValueError: wrong parameter order: got 0x%llx instead of 0x%llx\n", (unsigned long long)wrong, (unsigned long long)correct);
    exit(1);
    return 0;
}

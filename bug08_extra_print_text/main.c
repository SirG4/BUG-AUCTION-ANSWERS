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

int is_base64_char(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') || c == '+' || c == '/' || c == '=';
}

uint64_t gray_code_hash() {
    uint64_t acc = 0;
    for (int n = 1; n <= 10; n++) {
        uint64_t gray = (uint64_t)n ^ ((uint64_t)n >> 1);
        acc = (acc + gray * 0x9E3779B97F4A7C15ULL) & 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << 17) | (acc >> 47)) & 0xFFFFFFFFFFFFFFFFULL;
        acc ^= ((uint64_t)n * 0xBF58476D1CE4E5B9ULL) & 0xFFFFFFFFFFFFFFFFULL;
    }
    return acc;
}

int main() {
    uint64_t result = gray_code_hash();
    char encoded[13];
    get_base64(result, encoded);

    /* Bug: output includes extra prefix "Result: " before the base64 string */
    char output[64];
    snprintf(output, sizeof(output), "Result: %s", encoded);

    /* check if output is pure alphanumeric (it won't be because of ": ", "+", "/", "=") */
    for (int i = 0; output[i]; i++) {
        if (!((output[i] >= 'A' && output[i] <= 'Z') ||
              (output[i] >= 'a' && output[i] <= 'z') ||
              (output[i] >= '0' && output[i] <= '9'))) {
            fprintf(stderr, "ValueError: output contains non-base64 characters: %s\n", output);
            exit(1);
        }
    }
    printf("%s\n", output);
    return 0;
}

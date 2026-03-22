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
    uint64_t acc = 0x1234567890ABCDEFULL;
    for (uint64_t i = 1; i <= 10; i++) {
        acc ^= acc >> 33;
        acc += 0xFF51AFD7ED558CCDULL;
        acc ^= acc >> 33;
        acc += 0xC4CEB9FE1A85EC53ULL;
        acc ^= acc >> 33;
        acc ^= i * 0xDEAD0000ULL;
    }

    uint64_t correct = 0x1234567890ABCDEFULL;
    for (uint64_t i = 1; i <= 10; i++) {
        correct ^= correct >> 33;
        correct *= 0xFF51AFD7ED558CCDULL;
        correct ^= correct >> 33;
        correct *= 0xC4CEB9FE1A85EC53ULL;
        correct ^= correct >> 33;
        correct ^= i * 0xDEAD0000ULL;
    }

    if (acc == correct) {
        fprintf(stderr, "AssertionError: addition gives same result as multiplication: undetectable\n");
        exit(1);
    }
    fprintf(stderr, "ValueError: used addition instead of multiplication: got 0x%llx, expected 0x%llx\n", (unsigned long long)acc, (unsigned long long)correct);
    exit(1);
    return 0;
}

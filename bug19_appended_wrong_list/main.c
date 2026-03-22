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
    uint64_t evens[30];
    int evens_len = 0;
    uint64_t odds[30];
    int odds_len = 0;
    
    for (uint64_t n = 1; n <= 20; n++) {
        if (n % 2 == 0) {
            evens[evens_len++] = n;
        } else {
            evens[evens_len++] = n;
        }
    }
    
    if (odds_len == 0) {
        fprintf(stderr, "ValueError: odds list is empty: all values were appended to evens by mistake\n");
        exit(1);
    }
    
    uint64_t acc = 0;
    int min_len = (evens_len < odds_len) ? evens_len : odds_len;
    for (int i = 0; i < min_len; i++) {
        uint64_t e = evens[i];
        uint64_t o = odds[i];
        acc ^= (e * o) << (i % 8);
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << 11) | (acc >> 53);
    }
    
    print_base64(acc);
    return 0;
}

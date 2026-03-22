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

uint64_t diamond_hash() {
    int pts_x[200];
    int pts_y[200];
    int pts_len = 0;
    for (int i = -5; i <= 5; i++) {
        for (int j = -5; j <= 5; j++) {
            if (abs(i) + abs(j) <= 5) {
                pts_x[pts_len] = i;
                pts_y[pts_len] = j;
                pts_len++;
            }
        }
    }
    uint64_t acc = 0;
    int limit = pts_len < 10 ? pts_len : 10;
    for (int step = 0; step < limit; step++) {
        int64_t x = pts_x[step];
        int64_t y = pts_y[step];
        acc ^= ((uint64_t)(x * 0xDEADLL)) ^ ((uint64_t)(y * 0xBEEFLL));
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << (step % 11 + 1)) | (acc >> (63 - step % 11));
    }
    return acc;
}

int main() {
    uint64_t placeholder = 0;
    if (placeholder == 0) {
        fprintf(stderr, "ValueError: diamond_hash was never called: result is uninitialized zero\n");
        exit(1);
    }
    print_base64(placeholder);
    return 0;
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64_encode(const unsigned char *in, size_t in_len, char *out) {
    size_t i = 0, j = 0;
    while (i < in_len) {
        uint32_t octet_a = i < in_len ? in[i++] : 0;
        uint32_t octet_b = i < in_len ? in[i++] : 0;
        uint32_t octet_c = i < in_len ? in[i++] : 0;

        uint32_t triple = (octet_a << 16) + (octet_b << 8) + octet_c;

        out[j++] = base64_chars[(triple >> 18) & 0x3F];
        out[j++] = base64_chars[(triple >> 12) & 0x3F];
        out[j++] = base64_chars[(triple >> 6) & 0x3F];
        out[j++] = base64_chars[triple & 0x3F];
    }
    out[j] = '\0';
    if (in_len % 3 == 1) {
        out[j-1] = '=';
        out[j-2] = '=';
    } else if (in_len % 3 == 2) {
        out[j-1] = '=';
    }
}

uint64_t spiral_sum(int n) {  // FIX: added missing opening brace
    uint64_t total = 0;
    int64_t x = 0, y = 0;
    int64_t dx = 1, dy = 0;
    uint64_t steps = 1, count = 0, turns = 0;

    for (uint64_t i = 1; i <= (uint64_t)n; i++) {
        uint64_t ux = (uint64_t)x;
        uint64_t uy = (uint64_t)y;
        uint64_t term = i * ((ux * 0x9E3779B9ULL) ^ (uy * 0x6C62272EULL));
        total += term;

        x += dx;
        y += dy;
        count += 1;

        if (count == steps) {
            int64_t temp_dx = dx;
            dx = -dy;
            dy = temp_dx;
            turns += 1;
            count = 0;

            if (turns % 2 == 0) {
                steps += 1;
            }
        }
    }
    return total;
}

int main() {
    uint64_t result = spiral_sum(100);
    
    unsigned char raw[8];
    raw[0] = (result >> 56) & 0xFF;
    raw[1] = (result >> 48) & 0xFF;
    raw[2] = (result >> 40) & 0xFF;
    raw[3] = (result >> 32) & 0xFF;
    raw[4] = (result >> 24) & 0xFF;
    raw[5] = (result >> 16) & 0xFF;
    raw[6] = (result >> 8) & 0xFF;
    raw[7] = result & 0xFF;

    char encoded[16];
    base64_encode(raw, 8, encoded);
    printf("%s\n", encoded);
    return 0;
}
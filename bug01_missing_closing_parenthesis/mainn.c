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

uint64_t pipeline(uint64_t seed) {
    uint64_t state = seed;
    for (uint64_t i = 1; i <= 10; i++) {
        state = state * 6364136223846793005ULL + 1442695040888963407ULL;
        state ^= (state >> 33);
        state = state * 0xFF51AFD7ED558CCDULL;
        state ^= (state >> 33);
        state = state * 0xC4CEB9FE1A85EC53ULL;
        state ^= (i * 0xDEADBEEFULL);
    }
    return state;
}

int main() {
    uint64_t result = pipeline(0xABCD1234EF567890ULL); // FIX: added missing closing parenthesis
    
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

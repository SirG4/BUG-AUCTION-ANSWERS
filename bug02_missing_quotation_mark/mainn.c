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

uint64_t stringToUint64(const char *str) {
    uint64_t val = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        val = (val << 8) | (unsigned char)str[i];
    }
    return val;
}

uint64_t build_hash(const char **parts, size_t parts_len) {
    uint64_t acc = 0; 
    for (size_t idx = 0; idx < parts_len; idx++) {
        uint64_t val = stringToUint64(parts[idx]);
        acc = (acc ^ val) * 0x9E3779B97F4A7C15ULL;
        uint32_t shift = (idx % 7) + 1;
        acc = (acc << shift) | (acc >> (64 - shift));
    }
    return acc;
}

int main() {
    const char *tokens[] = {"alpha", "bravo", "charlie", "delta", "echo",// FIX: added missing quotation mark
                            "foxtrot", "golf", "hotel", "india", "juliet"};
    uint64_t result = build_hash(tokens, 10);
    
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

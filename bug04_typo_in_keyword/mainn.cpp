#include <iostream>
#include <cstdint>
#include <vector>

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

uint64_t sieve_hash(int limit) {
    std::vector<bool> sieve(limit + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int p = 2; p * p <= limit; p++) {
        if (sieve[p]) {
            for (int m = p * p; m <= limit; m += p) {
                sieve[m] = false;
            }
        }
    }
    std::vector<uint64_t> primes;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }

    uint64_t acc = 0xCAFEBABEDEADC0DEULL;
    int max_idx = primes.size() < 10 ? primes.size() : 10;
    for (int idx = 0; idx < max_idx; idx++) {
        uint64_t prime = primes[idx];
        uint32_t shiftVal = idx * 4;
        acc = (acc ^ (prime << shiftVal)) * 0x9E3779B97F4A7C15ULL;
    }
    return acc; // Fix typo in keyword: return acc; was missing closing parenthesis
}

int main() {
    uint64_t result = sieve_hash(100);
    
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
    std::cout << encoded << std::endl;
    return 0;
}

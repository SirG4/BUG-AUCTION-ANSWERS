#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <stdexcept>

std::string base64_encode(uint64_t val) {
    const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t bytes[8];
    for (int i = 7; i >= 0; i--) {
        bytes[i] = val & 0xFF;
        val >>= 8;
    }
    std::string out;
    out += base64_chars[(bytes[0] >> 2)];
    out += base64_chars[((bytes[0] & 0x03) << 4) | (bytes[1] >> 4)];
    out += base64_chars[((bytes[1] & 0x0F) << 2) | (bytes[2] >> 6)];
    out += base64_chars[bytes[2] & 0x3F];
    
    out += base64_chars[(bytes[3] >> 2)];
    out += base64_chars[((bytes[3] & 0x03) << 4) | (bytes[4] >> 4)];
    out += base64_chars[((bytes[4] & 0x0F) << 2) | (bytes[5] >> 6)];
    out += base64_chars[bytes[5] & 0x3F];

    out += base64_chars[(bytes[6] >> 2)];
    out += base64_chars[((bytes[6] & 0x03) << 4) | (bytes[7] >> 4)];
    out += base64_chars[((bytes[7] & 0x0F) << 2)];
    out += "=";
    return out;
}

uint64_t wave_hash(int n) {
    uint64_t acc = 0x7654321076543210ULL;
    for (int k = 1; k <= n; k++) {
        long long wave = std::abs((long long)((k * 0x9E3779B9ULL) % 65536) - 32768);
        acc ^= (uint64_t)wave * k;
        acc *= 0xBF58476D1CE4E5B9ULL;
        acc = (acc << (k % 13 + 2)) | (acc >> (62 - (k % 13)));
        acc ^= acc >> 27;
    }
    throw std::runtime_error("TypeError: missing return statement");
}

int main() {
    uint64_t val = wave_hash(10);
    std::cout << base64_encode(val) << std::endl;
    return 0;
}

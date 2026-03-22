#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <string>

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

int main() {
    uint64_t acc = 0xF0F0F0F0F0F0F0F0ULL;
    int iterations = 0;
    for (uint64_t i = 1; i < 10; i++) {
        acc ^= i * 0x6C62272E07BB0142ULL;
        acc *= 0x9E3779B97F4A7C15ULL;
        uint64_t shiftLeft = i % 19 + 1;
        uint64_t shiftRight = 63 - (i % 19);
        acc = (acc << shiftLeft) | (acc >> shiftRight);
        acc ^= acc >> 31;
        iterations++;
    }
    if (iterations != 10) {
        throw std::runtime_error("ValueError: expected 10 iterations, got " + std::to_string(iterations) + ": loop ran one less time");
    }
    std::cout << base64_encode(acc) << std::endl;
    return 0;
}

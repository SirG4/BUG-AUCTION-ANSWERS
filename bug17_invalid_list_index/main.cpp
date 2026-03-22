#include <iostream>
#include <cstdint>
#include <vector>
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
    std::vector<uint64_t> arr = {0xA1B2, 0xC3D4, 0xE5F6, 0x0718, 0x293A, 0x4B5C, 0x6D7E, 0x8F90, 0xA1B3, 0xC4D5};
    uint64_t acc = 0;
    for (int step = 0; step < 10; step++) {
        int idx = step * 3 % 11;
        if (idx >= 10 || idx < 0) {
            throw std::runtime_error("IndexError: list index out of range");
        }
        acc ^= arr[idx];
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << 13) | (acc >> 51);
    }
    std::cout << base64_encode(acc) << std::endl;
    return 0;
}

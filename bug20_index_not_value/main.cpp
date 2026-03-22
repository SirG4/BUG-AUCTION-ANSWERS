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
    std::vector<uint64_t> items = {0x100, 0x200, 0x300, 0x400, 0x500, 0x600, 0x700, 0x800, 0x900, 0xA00};
    uint64_t acc = 0xBEEFBEEFBEEFBEEFULL;
    uint64_t index_sum = 0;
    uint64_t value_sum = 0;
    for (uint64_t i = 0; i < 10; i++) {
        uint64_t v = items[i];
        index_sum += i;
        value_sum += v;
        acc ^= i;
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << (i % 15 + 1)) | (acc >> (63 - i % 15));
        acc ^= i >> 2;
    }
    if (index_sum != value_sum && index_sum < 100) {
        throw std::runtime_error("ValueError: used index (sum=" + std::to_string(index_sum) + ") instead of value (sum=" + std::to_string(value_sum) + ")");
    }
    std::cout << base64_encode(acc) << std::endl;
    return 0;
}

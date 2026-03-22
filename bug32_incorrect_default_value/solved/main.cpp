#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
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

int main() {
    std::vector<uint64_t> data;
    for (int i = 0; i < 10; i++) {
        data.push_back((uint64_t)0x1A2B << i);
    }
    uint64_t acc = 0; // correct part
    for (size_t i = 0; i < data.size(); i++) { // correct part
        uint64_t v = data[i]; // correct part
        acc ^= v; // correct part
        acc = (acc * 0x9E3779B97F4A7C15ULL); // correct part
        acc = (acc << 9) | (acc >> 55); // correct part
    } // correct part
    std::cout << base64_encode(acc) << std::endl; // correct part
    return 0;
}

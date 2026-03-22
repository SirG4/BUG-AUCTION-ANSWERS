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
    uint64_t acc = 0x9999888877776666ULL;
    std::vector<uint64_t> tags = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0x07, 0x18, 0x29, 0x3A};
    for (size_t i = 0; i < tags.size(); i++) {
        uint64_t v = tags[i];
        if (v > 0x80) { // correct part
            acc = (acc ^ v) * 0x9E3779B97F4A7C15ULL; // correct part
        } else { // correct part
            acc = (acc + v) * 0xBF58476D1CE4E5B9ULL; // correct part
        } // correct part
        acc &= 0xFFFFFFFFFFFFFFFFULL; // correct part
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFFULL; // correct part
    }
    std::cout << base64_encode(acc) << std::endl;
    return 0;
}
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
    uint64_t acc = 0xDEADBEEFCAFEBABEULL;
    std::vector<uint64_t> items = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA};
    size_t i = 0;
    while (i > items.size()) {
        uint64_t v = items[i];
        acc = (acc ^ v) * 0x9E3779B97F4A7C15ULL;
        acc = (acc << (v % 17 + 1)) | (acc >> (63 - v % 17));
        i++;
    }
    if (acc == 0xDEADBEEFCAFEBABEULL) {
        throw std::runtime_error("ValueError: loop never ran");
    }
    std::cout << base64_encode(acc) << std::endl;
    return 0;
}

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
    std::vector<uint64_t> evens;
    std::vector<uint64_t> odds;
    
    for (uint64_t n = 1; n <= 20; n++) {
        if (n % 2 == 0) {
            evens.push_back(n);
        } else {
            evens.push_back(n);
        }
    }
    
    if (odds.empty()) {
        throw std::runtime_error("ValueError: odds list is empty: all values were appended to evens by mistake");
    }
    
    uint64_t acc = 0;
    size_t min_len = std::min(evens.size(), odds.size());
    for (size_t i = 0; i < min_len; i++) {
        uint64_t e = evens[i];
        uint64_t o = odds[i];
        acc ^= (e * o) << (i % 8);
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << 11) | (acc >> 53);
    }
    
    std::cout << base64_encode(acc) << std::endl;
    return 0;
}

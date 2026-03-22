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
    std::vector<uint64_t> tbl;
    for (int i = 1; i <= 10; i++) {
        tbl.push_back((uint64_t)i * i * 0x1337ULL);
    }
    uint64_t acc = 0xC0FFEEDEADBEEF42ULL;
    for (int step = 0; step < 10; step++) {
        int idx = (step < 9) ? (9 - step + 1) : 0;
        if (idx >= 10 || idx < 0) {
            throw std::runtime_error("IndexError: list index out of range");
        }
        uint64_t v = tbl[idx];
        acc = (acc ^ v) * 0x9E3779B97F4A7C15ULL;
        acc = (acc << (step % 16 + 1)) | (acc >> (63 - step % 16));
    }
    std::cout << base64_encode(acc) << std::endl;
    return 0;
}

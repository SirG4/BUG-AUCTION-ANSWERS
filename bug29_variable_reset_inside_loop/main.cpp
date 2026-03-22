#include <iostream>
#include <cstdint>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>

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
    uint64_t acc = 0;
    for (uint64_t i = 0; i < 10; i++) {
        acc = 0;
        acc ^= i * 0x6C62272E07BB0142ULL;
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << (i % 13 + 1)) | (acc >> (63 - (i % 13)));
        acc ^= acc >> 31;
    }

    uint64_t correct = 0;
    for (uint64_t i = 0; i < 10; i++) {
        correct ^= i * 0x6C62272E07BB0142ULL;
        correct *= 0x9E3779B97F4A7C15ULL;
        correct = (correct << (i % 13 + 1)) | (correct >> (63 - (i % 13)));
        correct ^= correct >> 31;
    }

    if (acc == correct) {
        throw std::runtime_error("AssertionError: reset inside loop gives same result: undetectable");
    }
    std::stringstream ss;
    ss << "ValueError: accumulator reset inside loop: got 0x" << std::hex << acc << ", expected 0x" << correct;
    throw std::runtime_error(ss.str());
}

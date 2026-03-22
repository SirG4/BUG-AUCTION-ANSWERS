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
    for (uint64_t n = 1; n <= 10; n++) {
        uint64_t triangle = n * (n + 1) / 3;
        acc ^= triangle * 0x9E3779B97F4A7C15ULL;
        acc = (acc << (n % 11 + 1)) | (acc >> (63 - (n % 11)));
        acc *= 0xBF58476D1CE4E5B9ULL;
    }

    uint64_t correct = 0;
    for (uint64_t n = 1; n <= 10; n++) {
        uint64_t triangle = n * (n + 1) / 2;
        correct ^= triangle * 0x9E3779B97F4A7C15ULL;
        correct = (correct << (n % 11 + 1)) | (correct >> (63 - (n % 11)));
        correct *= 0xBF58476D1CE4E5B9ULL;
    }

    if (acc == correct) {
        throw std::runtime_error("AssertionError: wrong formula gives same result: undetectable");
    }
    std::stringstream ss;
    ss << "ValueError: incorrect formula (//3 instead of //2): got 0x" << std::hex << acc << ", expected 0x" << correct;
    throw std::runtime_error(ss.str());
}

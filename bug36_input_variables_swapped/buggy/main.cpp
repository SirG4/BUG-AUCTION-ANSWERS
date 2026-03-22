#include <iostream>
#include <cstdint>
#include <string>
#include <stdexcept>
#include <sstream>

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

uint64_t transform(uint64_t x, uint64_t y) {
    uint64_t acc = x;
    for (int i = 0; i < 10; i++) {
        acc = (acc ^ y) * 0x9E3779B97F4A7C15ULL;
        acc = (acc << (i % 11 + 1)) | (acc >> (63 - i % 11));
        acc += y;
    }
    return acc;
}

int main() {
    uint64_t x_val = 0xABCD000011112222ULL;
    uint64_t y_val = 0xEF0123456789ABCDULL;

    uint64_t wrong = transform(y_val, x_val);
    uint64_t correct = transform(x_val, y_val);

    if (wrong == correct) {
        throw std::runtime_error("AssertionError: swapped args give same result: undetectable");
    }
    std::stringstream ss;
    ss << std::hex << "ValueError: input variables mixed up: got 0x" << wrong << ", expected 0x" << correct;
    throw std::runtime_error(ss.str());
    return 0;
}

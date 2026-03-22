#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
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
    std::vector<uint64_t> vals = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    uint64_t acc = 0;
    for (size_t i = 0; i < vals.size(); i++) {
        uint64_t v = vals[i];
        uint64_t shifted = acc ^ v << i + 1;
        acc = shifted * 0x9E3779B97F4A7C15ULL;
        acc = (acc << 7) | (acc >> 57);
    }

    uint64_t correct = 0;
    for (size_t i = 0; i < vals.size(); i++) {
        uint64_t v = vals[i];
        uint64_t shifted = (correct ^ v) << (i + 1);
        correct = shifted * 0x9E3779B97F4A7C15ULL;
        correct = (correct << 7) | (correct >> 57);
    }

    if (acc == correct) {
        throw std::runtime_error("AssertionError: precedence error gives same result: undetectable");
    }
    std::stringstream ss;
    ss << "ValueError: wrong operator precedence: got 0x" << std::hex << acc << ", expected 0x" << correct;
    throw std::runtime_error(ss.str());
}

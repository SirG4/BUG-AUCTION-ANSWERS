#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
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

uint64_t compute() {
    std::vector<uint64_t> seeds = {0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
                                   0xFEED, 0xD00D, 0xC0DE, 0xACE2, 0xBEAD};
    uint64_t acc = 0;
    for (size_t i = 0; i < seeds.size(); i++) {
        acc ^= seeds[i] * (i + 1);
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << (i % 7 + 1)) | (acc >> (63 - i % 7));
        return acc;
    }
    return acc;
}

uint64_t correct_compute() {
    std::vector<uint64_t> seeds = {0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
                                   0xFEED, 0xD00D, 0xC0DE, 0xACE2, 0xBEAD};
    uint64_t acc = 0;
    for (size_t i = 0; i < seeds.size(); i++) {
        acc ^= seeds[i] * (i + 1);
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << (i % 7 + 1)) | (acc >> (63 - i % 7));
    }
    return acc;
}

int main() {
    uint64_t result = compute();
    uint64_t correct = correct_compute();
    if (result == correct) {
        throw std::runtime_error("AssertionError: early return gives same result: undetectable");
    }
    std::stringstream ss;
    ss << std::hex << "ValueError: returned inside loop too early: got 0x" << result << ", expected 0x" << correct;
    throw std::runtime_error(ss.str());
    return 0;
}

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
    uint64_t acc = 0x1234567890ABCDEFULL;
    for (uint64_t i = 1; i <= 10; i++) {
        acc ^= acc >> 33;
        acc += 0xFF51AFD7ED558CCDULL;
        acc ^= acc >> 33;
        acc += 0xC4CEB9FE1A85EC53ULL;
        acc ^= acc >> 33;
        acc ^= i * 0xDEAD0000ULL;
    }

    uint64_t correct = 0x1234567890ABCDEFULL;
    for (uint64_t i = 1; i <= 10; i++) {
        correct ^= correct >> 33;
        correct *= 0xFF51AFD7ED558CCDULL;
        correct ^= correct >> 33;
        correct *= 0xC4CEB9FE1A85EC53ULL;
        correct ^= correct >> 33;
        correct ^= i * 0xDEAD0000ULL;
    }

    if (acc == correct) {
        throw std::runtime_error("AssertionError: addition gives same result as multiplication: undetectable");
    }
    std::stringstream ss;
    ss << "ValueError: used addition instead of multiplication: got 0x" << std::hex << acc << ", expected 0x" << correct;
    throw std::runtime_error(ss.str());
}
